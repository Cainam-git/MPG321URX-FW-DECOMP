/* dp_mst_unpack_port_pair_copy  (FUN_a00d7274)
 *
 * Unpack the two-byte port setting from a received MST message.
 * Note: Identical copy of dp_mst_unpack_port_pair.
 * Name basis: descriptive - low 7 bits of body byte 0 and the high nibble of body byte 1, kept in place; body
 *   offset from the header length nibble; called from dp_mst_parse_request for request 0x1C
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d7274 @ 0xa00d7274 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's types kept; the masked high nibble goes through a temporary.
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




/* Unpack two body bytes of the received chunk `src` into the 2-byte setting `dst`: low 7 bits of body byte 0
 * into dst[0] (bit 7 kept), high nibble of body byte 1 into dst[1] (low nibble kept). The body starts at
 * src[body_start + 3], with body_start = ((src[0] >> 4) - 1) / 2 rounded up. Called from
 * dp_mst_parse_request for request 0x1c. */
void dp_mst_unpack_port_pair_copy(byte *dst,byte *src)

{
  uint nibbles;
  unsigned char body_start;
  
  nibbles = (*src >> 4) - 1;
  body_start = (int)nibbles / 2;
  if ((nibbles & 1) != 0) {
    body_start = body_start + 1;
  }
  *dst = *dst & 0x80 | src[(body_start & 0xff) + 3] & 0x7f;
  { uint hi = src[(body_start & 0xff) + 4] & 0xf0; dst[1] = dst[1] & 0xf | hi; }
  return;
}
