/* leon2s FUN_a00d76ac @ 0xa00d76ac-0xa00d76f4 (18 words), flags -mcpu=v8 -Os -g. Leaf.
 * Unpacks three big-endian u16 words src[0..2] into dst bytes: dst[0] = (src[0] >> 8) & 0x7f,
 * dst[1] = src[0] & 0xf1, dst[2] = src[1] >> 8, dst[3] = src[1], dst[4] = src[2] >> 8, dst[5] = src[2];
 * every byte re-loads the halfword (lduh), no volatile needed (each store may alias).
 * Source form: the 0xf1 mask goes into a u16 temp first ('unsigned short v = src[0] & 0xf1; dst[1] = v;');
 * the direct forms (Ghidra's '(byte)*p & 0xf1', a u8 temp, an expression) let gcc narrow the load to
 * ldub [p+1] with mask -15; a uint temp gives different code.
 */
void FUN_a00d76ac(unsigned short *src, unsigned char *dst)
{
  dst[0] = (src[0] >> 8) & 0x7f;
  { unsigned short v = src[0] & 0xf1; dst[1] = v; }
  dst[2] = src[1] >> 8;
  dst[3] = src[1];
  dst[4] = src[2] >> 8;
  dst[5] = src[2];
}
