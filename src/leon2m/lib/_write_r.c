/* _write_r  (FUN_a015e134)
 *
 * Write to a file descriptor (reentrant wrapper).
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015e134 @ 0xa015e134, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept; write is declared without a parameter list.
 */
typedef unsigned int uint;
extern unsigned int libc_errno;
extern int write();

/*
 * Reentrant form of write: clear libc_errno (0xA802E40C), call write(fd, buffer, length) and return its
 * result. When the result is -1 and write has set libc_errno, the value is also stored at *errno_ptr.
 */
uint _write_r(int *errno_ptr,int fd,uint buffer,uint length)

{
  uint result;
  
  libc_errno = 0;
  result = write(fd,buffer,length);
  if ((result == 0xffffffff) && (libc_errno != 0)) {
    *errno_ptr = libc_errno;
  }
  return result;
}
