/* __fp_lock  (FUN_a015b738)
 *
 * Lock one stream unless it is a string stream; always return 0.
 * Returns: 0
 * Name basis: proven - tests the 0x200 stream flag, then __st_pthread_mutex_lock on the stream's lock (newlib
 *   findfp.c)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015b738 @ 0xa015b738, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept.
 */
extern int __st_pthread_mutex_lock();

#define STREAM_FLAGS_OFFSET 0xc         /* halfword with the stream flags */
#define STREAM_FLAG_NO_LOCK 0x200       /* set: the stream has no lock */
#define STREAM_LOCK_OFFSET  0x58        /* the stream's lock object */

/*
 * Lock the stream at stream when bit 9 (0x200) of its flag halfword (+0xC) is clear, using the lock object at
 * +0x58. Always returns 0 (the second parameter is shifted out of the 64-bit value that the decompiler returns).
 *   unused  not used; it only appears in the return expression
 */
unsigned int __fp_lock(int stream,unsigned int unused)

{
  if ((*(unsigned short *)(stream + STREAM_FLAGS_OFFSET) & STREAM_FLAG_NO_LOCK) == 0) {
    __st_pthread_mutex_lock(stream + STREAM_LOCK_OFFSET);
  }
  return (unsigned long long)unused << 0x20;
}