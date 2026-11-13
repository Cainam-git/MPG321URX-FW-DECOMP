/* dp_mst_unpack_port_byte  (FUN_a00d6b4c)
 *
 * Unpack the port number byte from a received MST message.
 * Name basis: descriptive - low 7 bits of the first body byte copied, bit 7 of the destination kept; body
 *   offset from the header length nibble; called from dp_mst_parse_request
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d6b4c @ 0xa00d6b4c (-mcpu=v8 -Os -g)
 * One-byte member of the dp_mst_unpack_port_pair / dp_mst_unpack_port_pair_copy family.
 * Source form: Ghidra's types kept; the masked byte goes through a temporary.
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


/* Copy the low 7 bits of the first body byte of the chunk at `src` into `out`, keeping bit 7 of `out`.
 * The body starts after the header: with n = (src[0] >> 4) - 1 the body byte is src[(n / 2 rounded up) + 3].
 * Called from dp_mst_parse_request. */
void dp_mst_unpack_port_byte(byte *out,byte *src)

{
  uint nibbles;
  unsigned char body_index;
  
  nibbles = (*src >> 4) - 1;
  body_index = (int)nibbles / 2;
  if ((nibbles & 1) != 0) {
    body_index = body_index + 1;
  }
  { uint t_ = src[(body_index & 0xff) + 3] & 0x7f; *out = *out & 0x80 | t_; }
  return;
}
