#ifndef ASM_TYPES_H
#define ASM_TYPES_H
#include <stdarg.h>
typedef unsigned char byte;
typedef unsigned short ushort;
typedef void *object;
typedef void (*functype)(object, ...);
#endif