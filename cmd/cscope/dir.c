/*===========================================================================
 Copyright (c) 1998-2000, The Santa Cruz Operation 
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 *Redistributions of source code must retain the above copyright notice,
 this list of conditions and the following disclaimer.

 *Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 *Neither name of The Santa Cruz Operation nor the names of its contributors
 may be used to endorse or promote products derived from this software
 without specific prior written permission. 

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 DAMAGE. 
 =========================================================================*/


/*	cscope - interactive C symbol cross-reference
 *
 *	directory searching functions
 */

#include <dirent.h>
#include <sys/types.h>	/* needed by stat.h */
#include <sys/stat.h>	/* stat */
#include "global.h"
#include "vp.h"		/* vpdirs and vpndirs */

static char const rcsid[] = "$Id$";

#define	DIRSEPS	" ,:"	/* directory list separators */
#define	DIRINC	10	/* directory list size increment */
#define HASHMOD	2003	/* must be a prime number */
#define	SRCINC	HASHMOD	/* source file list size increment */
			/* largest known database had 22049 files */

char	currentdir[PATHLEN + 1];/* current directory */
char	**incdirs;		/* #include directories */
char	**srcdirs;		/* source directories */
char	**srcfiles;		/* source files */
int	nincdirs;		/* number of #include directories */
int	mincdirs = DIRINC;	/* maximum number of #include directories */
int	nsrcdirs;		/* number of source directories */
int	msrcdirs;		/* maximum number of source directories */
int	nsrcfiles;		/* number of source files */
int	msrcfiles = SRCINC;	/* maximum number of source files */

static	char	**incnames;	/* #include directory names without view pathing */
static	int	nvpsrcdirs;	/* number of view path source directories */

static	struct	listitem {	/* source file names without view pathing */
	char	*text;
	struct	listitem *next;
} *srcnames[HASHMOD];

BOOL	issrcfile();
void	addsrcdir(), addincdir();

/* make the view source directory list */

void
makevpsrcdirs()
{
	int	i;

	/* return if this function has already been called */
	if (nsrcdirs > 0) {
		return;
	}
	/* get the current directory name */
	if (getcwd(currentdir, PATHLEN) == NULL) {
		(void) fprintf(stderr, "cscope: warning: cannot get current directory name\n");
		(void) strcpy(currentdir, "<unknown>");
	}
	/* see if there is a view path and this directory is in it */
	vpinit(currentdir);
	if (vpndirs > 1) {
		nsrcdirs = vpndirs;
	}
	else {
		nsrcdirs = 1;
	}
	/* create the source directory list */
	msrcdirs = nsrcdirs + DIRINC;
	srcdirs = (char **) mymalloc(msrcdirs * sizeof(char *));
	*srcdirs = ".";	/* first source dir is always current dir */
	for (i = 1; i < vpndirs; ++i) {
		srcdirs[i] = vpdirs[i];
	}
	/* save the number of original source directories in the view path */
	nvpsrcdirs = nsrcdirs;
}

/* add a source directory to the list for each view path source directory */

void
sourcedir(dirlist)
char	*dirlist;
{
	char	path[PATHLEN + 1];
	register char	*dir;
	register int	i;

	makevpsrcdirs();		/* make the view source directory list */
	dirlist = stralloc(dirlist);	/* don't change environment variable text */
	
	/* parse the directory list */
	dir = strtok(dirlist, DIRSEPS);
	while (dir != NULL) {
		addsrcdir(dir);

		/* if it isn't a full path name and there is a 
		   multi-directory view path */
		if (*dirlist != '/' && vpndirs > 1) {
			
			/* compute its path from higher view path source dirs */
			for (i = 1; i < nvpsrcdirs; ++i) {
				(void) sprintf(path, "%s/%s", srcdirs[i], dir);
				addsrcdir(path);
			}
		}
		dir = strtok((char *) NULL, DIRSEPS);
	}
}

/* add a source directory to the list */

void
addsrcdir(dir)
char	*dir;
{
	struct	stat	statstruct;

	/* make sure it is a directory */
	if (stat(compath(dir), &statstruct) == 0 && 
	    (statstruct.st_mode & S_IFDIR)) {

		/* note: there already is a source directory list */
		if (nsrcdirs == msrcdirs) {
			msrcdirs += DIRINC;
			srcdirs = (char **) myrealloc((char *) srcdirs, msrcdirs * sizeof(char *));
		}
		srcdirs[nsrcdirs++] = stralloc(dir);
	}
}

/* add a #include directory to the list for each view path source directory */

void
includedir(dirlist)
char	*dirlist;
{
	char	path[PATHLEN + 1];
	register char	*dir;
	register int	i;

	makevpsrcdirs();		/* make the view source directory list */
	dirlist = stralloc(dirlist);	/* don't change environment variable text */
	
	/* parse the directory list */
	dir = strtok(dirlist, DIRSEPS);
	while (dir != NULL) {
		addincdir(dir, dir);

		/* if it isn't a full path name and there is a 
		   multi-directory view path */
		if (*dirlist != '/' && vpndirs > 1) {
			
			/* compute its path from higher view path source dirs */
			for (i = 1; i < nvpsrcdirs; ++i) {
				(void) sprintf(path, "%s/%s", srcdirs[i], dir);
				addincdir(dir, path);
			}
		}
		dir = strtok((char *) NULL, DIRSEPS);
	}
}

/* add a #include directory to the list */

void
addincdir(name, path)
char	*name;
char	*path;
{
	struct	stat	statstruct;

	/* make sure it is a directory */
	if (stat(compath(path), &statstruct) == 0 && 
	    (statstruct.st_mode & S_IFDIR)) {
		if (incdirs == NULL) {
			incdirs = (char **) mymalloc(mincdirs * sizeof(char *));
			incnames = (char **) mymalloc(mincdirs * sizeof(char *));
		}
		else if (nincdirs == mincdirs) {
			mincdirs += DIRINC;
			incdirs = (char **) myrealloc((char *) incdirs, 
				mincdirs * sizeof(char *));
			incnames = (char **) myrealloc((char *) incnames, 
				mincdirs * sizeof(char *));
		}
		incdirs[nincdirs] = stralloc(path);
		incnames[nincdirs++] = stralloc(name);
	}
}

/* make the source file list */

void
makefilelist()
{
	static	BOOL	firstbuild = YES;	/* first time through */
	DIR	*dirfile;		/* directory file descriptor */
	struct	dirent	*entry;		/* directory entry pointer */
	FILE	*names;			/* name file pointer */
	char	dir[PATHLEN + 1];
	char	path[PATHLEN + 1];
	register char	*file;
	register char	*s;
	register int	i;

	makevpsrcdirs();	/* make the view source directory list */

	/* if -i was NOT given and there are source file arguments */
	if (namefile == NULL && fileargc > 0) {
		
		/* put them in a list that can be expanded */
		for (i = 0; i < fileargc; ++i) {
			file = fileargv[i];
			if (infilelist(file) == NO) {
				if ((s = inviewpath(file)) != NULL) {
					addsrcfile(file, s);
				}
				else {
					(void) fprintf(stderr, "cscope: cannot find file %s\n",
					    file);
					errorsfound = YES;
				}
			}
		}
		return;
	}
	/* see if a file name file exists */
	if (namefile == NULL && vpaccess(NAMEFILE, READ) == 0) {
		namefile = NAMEFILE;
	}
	/* if there is a file of source file names */
	if (namefile != NULL) {
		if ((names = vpfopen(namefile, "r")) == NULL) {
			cannotopen(namefile);
			myexit(1);
		}
		/* get the names in the file */
		while (fscanf(names, "%s", path) == 1) {
			if (*path == '-') {	/* if an option */
				i = path[1];
				switch (i) {
				case 'q':	/* quick search */
					invertedindex = YES;
					break;
				case 'T':	/* truncate symbols to 8 characters */
					trun_syms = YES;
					break;
				case 'I':	/* #include file directory */
				case 'p':	/* file path components to display */
					s = path + 2;		/* for "-Ipath" */
					if (*s == '\0') {	/* if "-I path" */
						(void) fscanf(names, "%s", path);
						s = path;
					}
					switch (i) {
					case 'I':	/* #include file directory */
						if (firstbuild == YES) {
							shellpath(dir, sizeof(dir), s);	/* expand $ and ~ */
							includedir(dir);
						}
						break;
					case 'p':	/* file path components to display */
						if (*s < '0' || *s > '9') {
							(void) fprintf(stderr, "cscope: -p option in file %s: missing or invalid numeric value\n", 
								namefile);
						}
						dispcomponents = atoi(s);
						break;
					}
					break;
				default:
					(void) fprintf(stderr, "cscope: only -I, -p, and -T options can be in file %s\n", 
						namefile);
				}
			}
			else if ((s = inviewpath(path)) != NULL) {
				addsrcfile(path, s);
			}
			else {
				(void) fprintf(stderr, "cscope: cannot find file %s\n",
				    path);
				errorsfound = YES;
			}
		}
		(void) fclose(names);
		firstbuild = NO;
		return;
	}
	/* make a list of all the source files in the directories */
	for (i = 0; i < nsrcdirs; ++i) {

		/* open the directory */
		/* note: failure is allowed because SOURCEDIRS may not exist */
		if ((dirfile = opendir(srcdirs[i])) != NULL) {

			/* read each entry in the directory */
			while ((entry = readdir(dirfile)) != NULL) {
				
				/* if it is a source file not already found */
				file = entry->d_name;
				if (entry->d_ino != 0 && issrcfile(file) &&
				    infilelist(file) == NO) {

					/* add it to the list */
					(void) sprintf(path, "%s/%s", srcdirs[i], file);
					addsrcfile(file, path);
				}
			}
			closedir(dirfile);
		}
	}
}

/* see if this is a source file */

BOOL
issrcfile(file)
char	*file;
{
	struct	stat	statstruct;
	char	*s;

	/* if there is a file suffix */
	if ((s = strrchr(file, '.')) != NULL && *++s != '\0') {
		
		/* if an SCCS or versioned file */
		if (file[1] == '.' && file + 2 != s) { /* 1 character prefix */
			switch (*file) {
			case 's':
			case 'S':
				return(NO);
			}
		}
		if (s[1] == '\0') {	/* 1 character suffix */
			switch (*s) {
			case 'c':
			case 'h':
			case 'l':
			case 'y':
			case 'C':
			case 'G':
			case 'H':
			case 'L':
				return(YES);
			}
		}
		else if (s[2] == '\0') {	/* 2 character suffix */
			if (*s == 'b' && s[1] == 'p' ||	/* breakpoint listing */
			    *s == 'q' &&
				(s[1] == 'c' || s[1] == 'h') || /* Ingres */
			    *s == 's' && s[1] == 'd') {	/* SDL */
			
				/* some directories have 2 character
				   suffixes so make sure it is a file */
				if (stat(file, &statstruct) == 0 && 
				    (statstruct.st_mode & S_IFREG)) {
					return(YES);
				}
			}
		}
	}
	return(NO);
}

/* add an include file to the source file list */

void
incfile(file, type)
char	*file;
char	type;
{
	char	name[PATHLEN + 1];
	char	path[PATHLEN + 1];
	char	*s;
	int	i;
	
	/* see if the file is already in the source file list */
	if (infilelist(file) == YES) {
		return;
	}
	/* look in current directory if it was #include "file" */
	if (type == '"' && (s = inviewpath(file)) != NULL) {
		addsrcfile(file, s);
	}
	else {
		/* search for the file in the #include directory list */
		for (i = 0; i < nincdirs; ++i) {
			
			/* don't include the file from two directories */
			(void) sprintf(name, "%s/%s", incnames[i], file);
			if (infilelist(name) == YES) {
				break;
			}
			/* make sure it exists and is readable */
			(void) sprintf(path, "%s/%s", incdirs[i], file);
			if (access(compath(path), READ) == 0) {
				addsrcfile(name, path);
				break;
			}
		}
	}
}

/* see if the file is already in the list */

BOOL
infilelist(file)
char	*file;
{
	register struct	listitem *p;
	
	for (p = srcnames[hash(compath(file)) % HASHMOD]; p != NULL; p = p->next) {
		if (strequal(file, p->text)) {
			return(YES);
		}
	}
	return(NO);
}

/* search for the file in the view path */

char *
inviewpath(file)
char	*file;
{
	static	char	path[PATHLEN + 1];
	int	i;

	/* look for the file */
	if (access(compath(file), READ) == 0) {
		return(file);
	}
	/* if it isn't a full path name and there is a multi-directory view path */
	if (*file != '/' && vpndirs > 1) {

		/* compute its path from higher view path source dirs */
		for (i = 1; i < nvpsrcdirs; ++i) {
			(void) sprintf(path, "%s/%s", srcdirs[i], file);
			if (access(compath(path), READ) == 0) {
				return(path);
			}
		}
	}
	return(NULL);
}

/* add a source file to the list */

void
addsrcfile(name, path)
char	*name;
char	*path;
{
	struct	listitem *p;
	int	i;
	
	/* make sure there is room for the file */
	if (nsrcfiles == msrcfiles) {
		msrcfiles += SRCINC;
		srcfiles = (char **) myrealloc((char *) srcfiles, msrcfiles * sizeof(char *));
	}
	/* add the file to the list */
	srcfiles[nsrcfiles++] = stralloc(compath(path));
	p = (struct listitem *) mymalloc(sizeof(struct listitem));
	p->text = stralloc(compath(name));
	i = hash(p->text) % HASHMOD;
	p->next = srcnames[i];
	srcnames[i] = p;
}

/* free the memory allocated for the source file list */

void
freefilelist()
{
	register struct	listitem *p, *nextp;
	register int	i;
	
	while (nsrcfiles > 0) {
		free(srcfiles[--nsrcfiles]);
	}
	for (i = 0; i < HASHMOD; ++i) {
		for (p = srcnames[i]; p != NULL; p = nextp) {
			nextp = p->next;
			free((char *) p);
		}
		srcnames[i] = NULL;
	}
}
