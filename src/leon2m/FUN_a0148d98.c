/* FUN_a0148d98: bit 31 of the RAM word DAT_a802e3d0 becomes 0 when bit 27 of DAT_a802e1a0 is set, else bit 0
 * of on. Then bit 23 (0x800000) of word +0x70 of the first 0x78-byte record at DAT_a802df30 is cleared when
 * bit 31 of DAT_a802e3d0 is set (read back) and set otherwise. Callers include FUN_a0086ae8, FUN_a0097138,
 * FUN_a00c9788. Exact form: bit 31 of DAT_a802e3d0 is a 1-bit bit-field (first field, big-endian).
 */
struct E3d0 { unsigned int b31 : 1, rest : 31; };
struct Chan { unsigned int w0; unsigned char pad[0x6c]; unsigned int w70; unsigned char pad2[0x4]; };
extern unsigned int DAT_a802e1a0;
extern struct E3d0 DAT_a802e3d0;
extern struct Chan DAT_a802df30[4];

void FUN_a0148d98(int on)
{
    if (DAT_a802e1a0 & 0x8000000)
        DAT_a802e3d0.b31 = 0;
    else
        DAT_a802e3d0.b31 = on;
    if (DAT_a802e3d0.b31)
        DAT_a802df30[0].w70 &= ~0x800000;
    else
        DAT_a802df30[0].w70 |= 0x800000;
}
