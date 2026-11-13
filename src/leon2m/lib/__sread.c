/* __sread  (FUN_a015df44)
 *
 * Read from the file behind a stream.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015df44 @ 0xa015df44 (-mcpu=v8 -O2 -g, the section default)
 * Source form: _read_r is declared without a prototype; the descriptor is passed as the sign-extended halfword.
 */

/* The fields of a C library stream used by __sread and __sseek. */
struct stdio_stream {
    unsigned char pad0[0xc];
    unsigned short flags;                       /* +0xC */
    short fd;                                   /* +0xE: file descriptor passed to _read_r / _lseek_r */
    unsigned char pad10[0x50 - 0x10];
    int offset;                                 /* +0x50: file position */
};

#define STREAM_FLAG_OFFSET_VALID 0x1000         /* flags bit 12: set by __sseek when it stores offset */

extern unsigned int _impure_ptr;                /* the C library's current reentrancy structure */
extern int _read_r();

/*
 * Read up to `count` bytes from the stream's file descriptor into `buf` (through _read_r, with the current
 * reentrancy structure).
 *
 * On success the number of bytes read is added to the stream's file position. On an error (a negative result)
 * the position is marked as not valid: STREAM_FLAG_OFFSET_VALID is cleared. Returns the result of _read_r.
 */
int __sread(struct stdio_stream *stream, char *buf, int count)
{
  int result;

  result = _read_r(_impure_ptr, (int)stream->fd, buf, count);
  if (result < 0) {
    stream->flags = stream->flags & ~STREAM_FLAG_OFFSET_VALID;
  }
  else {
    stream->offset = stream->offset + result;
  }
  return result;
}
