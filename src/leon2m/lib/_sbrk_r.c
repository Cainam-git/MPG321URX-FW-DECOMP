/* _sbrk_r  (FUN_a015df0c)
 *
 * Grow the heap by a number of bytes (reentrant wrapper).
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015df0c @ 0xa015df0c, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept; the result is written as CONCAT44(param_2, result) and truncated to
 * the int return.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern unsigned int libc_errno;
extern int sbrk(int increment);

/*
 * Reentrant form of sbrk: clear libc_errno (0xA802E40C), call sbrk(increment) and return its result. When the
 * result is -1 and sbrk has set libc_errno, the value is also stored at *errno_ptr.
 */
int _sbrk_r(int *errno_ptr,int increment)

{
  int result;
  
  libc_errno = 0;
  result = sbrk(increment);
  if ((result == -1) && (libc_errno != 0)) {
    *errno_ptr = libc_errno;
  }
  return CONCAT44(increment,result);
}
