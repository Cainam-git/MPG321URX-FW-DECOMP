/* _lseek  (FUN_a015e7fc)
 *
 * Fail every seek: set errno to 29 (ESPIPE) and return -1.
 * Returns: -1
 * Name basis: proven - stores 0x1D through __errno; called by _lseek_r (libnosys stub)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015e7fc @ 0xa015e7fc (-mcpu=v8 -O2 -g)
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern undefined4 __errno(void);

/*
 * Store 0x1D in the word whose address __errno returns and return -1. fd (param_1) is not used.
 */
#define ERRNO_ESPIPE 0x1d                       /* 29: illegal seek */

int _lseek(undefined4 fd,undefined4 offset)

{
  undefined4 *error_number;
  
  error_number = (undefined4 *)__errno();
  *error_number = ERRNO_ESPIPE;
  return CONCAT44(offset,0xffffffff);
}