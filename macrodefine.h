#ifdef _STRING_H_
#	define strop(A,OP,B) (strcmp(A,B) OP 0)
#else
#	define _STRING_H_
#	include <string.h>
#	define strop(A,OP,B) (strcmp(A,B) OP 0)		
#endif

#ifdef _STDLIB_H_
#	define ANEW(T,N) (T*)malloc(sizeof(T)*N)
#else
#	define _STDLIB_H_
#	include <stdlib.h>
#	define ANEW(T,N) (T*)malloc(sizeof(T)*N)		
#endif

#ifndef _STDIO_H_
#	define _STDIO_H_
#	include <stdio.h>
#endif

#ifndef _TIME_H
#	define _TIME_H
#	include <time.h>
#endif
