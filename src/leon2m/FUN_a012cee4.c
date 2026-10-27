/* FUN_a012cee4 (leon2m 0xa012cee4-0xa012cf10, 44 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores the halfword v to bits 8..23 of the word at DAT_a802e1a0 + 0x34 (bits 0..7 and 24..31 kept). Called by
 * gap. It lies between FUN_a012ced8 and FUN_a012cf10.
 */
struct S34 { unsigned char p0[0x34]; unsigned int w34; };
extern struct S34 DAT_a802e1a0;
void FUN_a012cee4(unsigned short v)
{
    DAT_a802e1a0.w34 = (DAT_a802e1a0.w34 & 0xff0000ff) | (v << 8);
}
