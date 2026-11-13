/* _fstat_r  (FUN_a015e408)
 *
 * Get the status of a file descriptor (reentrant wrapper).
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015e408 @ 0xa015e408 (-mcpu=v8 -O2 -g)
 * Source form: the return value is written CONCAT44(fd, result), as the decompiler printed it; Ghidra's type
 * names are kept.
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
extern unsigned int libc_errno;
extern undefined4 _fstat(undefined4 param_1,int param_2);

/*
 * Clear the global error number, call _fstat, and when it returns -1 with the error number set,
 * copy the error number to *error_out.
 * fd is the descriptor, stat_buf the buffer handed to _fstat.
 */
int _fstat_r(int *error_out,uint fd,int stat_buf)

{
  uint result;
  
  libc_errno = 0;
  result = _fstat(fd,stat_buf);
  if ((result == 0xffffffff) && (libc_errno != 0)) {
    *error_out = libc_errno;
  }
  return CONCAT44(fd,result);
}