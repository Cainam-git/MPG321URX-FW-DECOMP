/* __sseek  (FUN_a015e008)
 *
 * Move the file position of a stream.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015e008 @ 0xa015e008 (-mcpu=v8 -O2 -g, the section default)
 * Source form: _lseek_r is declared without a prototype; the descriptor is passed as the sign-extended halfword,
 * and the result is compared with -1 (not tested for < 0).
 */

/* The fields of a C library stream used by __sread and __sseek. */
struct stdio_stream {
    unsigned char pad0[0xc];
    unsigned short flags;                       /* +0xC */
    short fd;                                   /* +0xE: file descriptor passed to _read_r / _lseek_r */
    unsigned char pad10[0x50 - 0x10];
    int offset;                                 /* +0x50: file position */
};

#define STREAM_FLAG_OFFSET_VALID 0x1000         /* flags bit 12: set here when offset is stored */
#define SEEK_FAILED              (-1)

extern unsigned int _impure_ptr;                /* the C library's current reentrancy structure */
extern int _lseek_r();

/*
 * Move the position of the stream's file descriptor (through _lseek_r, with the current reentrancy structure);
 * `offset` and `whence` are passed on unchanged.
 *
 * On success the new position is stored in the stream and STREAM_FLAG_OFFSET_VALID is set; on -1 the flag is
 * cleared. Returns the result of _lseek_r. In this firmware _lseek fails every seek (errno 29, result -1), so
 * the failure branch is the one taken.
 */
int __sseek(struct stdio_stream *stream, int offset, int whence)
{
  int result;

  result = _lseek_r(_impure_ptr, (int)stream->fd, offset, whence);
  if (result == SEEK_FAILED) {
    stream->flags = stream->flags & ~STREAM_FLAG_OFFSET_VALID;
  }
  else {
    stream->flags = stream->flags | STREAM_FLAG_OFFSET_VALID;
    stream->offset = result;
  }
  return result;
}
