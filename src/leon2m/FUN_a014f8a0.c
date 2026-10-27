/* FUN_a014f8a0 (leon2m 0xa014f8a0-0xa014f92c, 140 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * For each bit i (0..7) set in m, stores v to the byte DAT_a802a4a8 + i (eight separate byte globals). Called by
 * FUN_a014bac4 (8 calls). It lies between FUN_a014f894 and FUN_a014f92c.
 */
extern unsigned char DAT_a802a4a8, DAT_a802a4a9, DAT_a802a4aa, DAT_a802a4ab;
extern unsigned char DAT_a802a4ac, DAT_a802a4ad, DAT_a802a4ae, DAT_a802a4af;

void FUN_a014f8a0(unsigned char m, unsigned char v)
{
    if (m & 1)
        DAT_a802a4a8 = v;
    if (m & 2)
        DAT_a802a4a9 = v;
    if (m & 4)
        DAT_a802a4aa = v;
    if (m & 8)
        DAT_a802a4ab = v;
    if (m & 0x10)
        DAT_a802a4ac = v;
    if (m & 0x20)
        DAT_a802a4ad = v;
    if (m & 0x40)
        DAT_a802a4ae = v;
    if (m & 0x80)
        DAT_a802a4af = v;
}
