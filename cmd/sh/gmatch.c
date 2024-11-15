/*
 * Derived from /usr/src/cmd/sh/expand.c, Unix 7th Edition:
 * 
 * uso:  Based on relevant judgments and by comparing the file described above
 *       to the 32V version (which may have been accidentally released into
 *       the public domain according to pre-1989 copyright law), I have erased
 *       the Caldera acknowledgment.
 */

#if __GNUC__ >= 3 && __GNUC_MINOR__ >= 4 || __GNUC__ >= 4
#define	USED	__attribute__ ((used))
#elif defined __GNUC__
#define	USED	__attribute__ ((unused))
#else
#define	USED
#endif
static const char sccsid[] USED = "@(#)gmatch.sl	1.5 (gritter) 5/29/05";

#include	<stdlib.h>
#include	<limits.h>

#if (defined(__sun))||(!defined(__svr4__))
#include	<wchar.h>
#include	"mbtowi.h"

#define	fetch(wc, s, n)	((mb_cur_max > 1 && *(s) & 0200 ? \
		((n) = mbtowi(&(wc), (s), mb_cur_max), \
		 (n) = ((n) > 0 ? (n) : (n) < 0 ? (wc = WEOF, 1) : 1)) :\
	((wc) = *(s) & 0377, (n) = 1)), (s) += (n), (wc))
#endif

int
gmatch(const char *s, const char *p)
{
	const char	*bs = s;
	int	mb_cur_max = MB_CUR_MAX;
	int	n;

#if (defined(__sun))||(!defined(__svr4__))
	wint_t	c, scc;

	if (fetch(scc, s, n) == WEOF)
		return (0);
	switch (fetch(c, p, n)) {
#else
	int c, scc;
	
	scc = *(s++);
	switch (c = *(p++)) {
#endif
	case '[':	{
		int	ok = 0, excl;
		unsigned long	lc = ULONG_MAX;
		const char	*bp;

		if (*p == '!') {
			p++;
			excl = 1;
		} else
			excl = 0;
#if (defined(__sun))||(!defined(__svr4__))
		fetch(c, p, n);
#else
		c = *(p++);
#endif
		bp = p;
		while (c != '\0') {
			if (c == ']' && p > bp)
				return (ok ^ excl ? gmatch(s, p) : 0);
			else if (c == '-' && p > bp && *p != ']') {
				if (*p == '\\')
					p++;
#if (defined(__sun))||(!defined(__svr4__))
				if (fetch(c, p, n) == '\0')
#else
				if (0 == (c = *(p++)))
#endif
					break;
				if (lc <= scc && scc <= c)
					ok = 1;
			} else {
				if (c == '\\') {
#if (defined(__sun))||(!defined(__svr4__))
					if (fetch(c, p, n) == '\0')
#else
					if (0==(c = *(p++)))
#endif
						break;
				}
				if (scc == (lc = c))
					ok = 1;
			}
#if (defined(__sun))||(!defined(__svr4__))
			fetch(c, p, n);
#else
			c = *(p++);
#endif
		}
		return (0);
	}

	case '\\':
#if (defined(__sun))||(!defined(__svr4__))
		fetch(c, p, n);
#else
		c = *(p++);
#endif
		if (c == '\0')
			return (0);
		/*FALLTHRU*/

	default:
		if (c != scc)
			return (0);
		/*FALLTHRU*/

	case '?':
		return (scc ? gmatch(s, p) : 0);

	case '*':
		if (*p == '\0')
			return (1);
		s = bs;
		while (*s) {
			if (gmatch(s, p))
				return (1);
#if (defined(__sun))||(!defined(__svr4__))
			fetch(scc, s, n);
#else
			scc = *(s++);
#endif
		}
		return (0);

	case '\0':
		return (scc == '\0');

#if (defined(__sun))||(!defined(__svr4__))
	case WEOF:
		return (0);
#endif

	}
}
