/*
 * This file is only needed on SVR4.  It is not a full implementation of
 * <stdint.h>; just enough for this code to roll.
 */

#ifndef _H_INCLUDE_STDINT
#define _H_INCLUDE_STDINT

#ifdef __svr4__

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed long int32_t;

#endif /* __svr4 */

#endif /* _H_INCLUDE_STDINT */
