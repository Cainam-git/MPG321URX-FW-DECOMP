/* dp_mst_pack_enum_path_reply  (FUN_a00d76ac)
 *
 * Pack the path resources reply into the byte stream of an MST reply.
 * Name basis: derived - port and two 16-bit payload numbers in six bytes; called from dp_mst_send_reply
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d76ac @ 0xa00d76ac-0xa00d76f4 (18 words), flags -mcpu=v8 -Os -g. Leaf.
 * Every byte re-loads the halfword (lduh), no volatile needed (each store may alias).
 * Source form: the 0xf1 mask goes into a u16 temp first ('unsigned short low = src[0] & 0xf1; out[1] = low;');
 * the direct forms (Ghidra's '(byte)*p & 0xf1', a u8 temp, an expression) let gcc narrow the load to
 * ldub [p+1] with mask -15; a uint temp gives different code.
 */
/* Split the three 16-bit words of `src` into six bytes of `out`: out[0] = bits 8..14 of word 0,
 * out[1] = word 0 & 0xf1, out[2..3] = word 1 (high byte first), out[4..5] = word 2 (high byte first).
 * Called from dp_mst_send_reply. */
void dp_mst_pack_enum_path_reply(unsigned short *src, unsigned char *out)
{
  out[0] = (src[0] >> 8) & 0x7f;
  { unsigned short low = src[0] & 0xf1; out[1] = low; }
  out[2] = src[1] >> 8;
  out[3] = src[1];
  out[4] = src[2] >> 8;
  out[5] = src[2];
}
