/* dp_mst_queue_short_message  (FUN_a00d97bc)
 *
 * Copy a header, lower its low nibble by one, drop its first address nibble and queue it.
 * Name basis: descriptive - low nibble of byte 0 lowered by one and address nibbles moved down; queued with
 *   dp_mst_queue_chunk queue 3
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d97bc @ 0xa00d97bc-0xa00d985c (40 words), flags -mcpu=v8 -Os -g.
 * The nop between the delay slot of the final call and the ret is emitted by the compiler.
 * Source form: one union for the bits 24..27 bit-field and the byte view; remaining is a signed char (an int
 * lets CSE share the two 'low_nibble - 1').
 */
extern void lib_memcpy(void *, const void *, int);
extern void dp_mst_queue_chunk(union Msg *, int, int);
/* The unpacked header: byte 0 = count (high nibble) and low nibble, then one nibble per byte from byte 1. */
union chunk_header { struct { unsigned int count : 4, low_nibble : 4, rest : 24; } h; unsigned char b[0x18]; };

/*
 * Copy the unpacked header `src` (0x13 bytes), lower its low nibble by one and drop the first of its address
 * nibbles, then put it into the forward ring (dp_mst_queue_chunk, queue 3).
 *
 * The nibbles at bytes 2.. of src are moved down to bytes 1..; with low_nibble the old low nibble, low_nibble - 1
 * entries are moved and a zero follows them. Called by dp_mst_receive_task for a message that is passed on;
 * dp_mst_append_chunk_to_message is called right after it.
 */
void dp_mst_queue_short_message(unsigned char *src)
{
  union chunk_header m;
  signed char remaining;
  unsigned char low_nibble;
  unsigned char i;

  lib_memcpy(&m, src, 0x13);
  low_nibble = src[0] & 0xf;
  m.h.low_nibble = low_nibble - 1;
  remaining = low_nibble - 1;
  for (i = 0; i < remaining; i++)
    m.b[i + 1] = src[i + 2];
  m.b[i + 1] = 0;
  dp_mst_queue_chunk(&m, 3, 1);
}
