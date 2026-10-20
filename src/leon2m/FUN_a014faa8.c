/* FUN_a014faa8: for each of the eight bytes DAT_a802a4a8[0..7] that is not 0xff calls FUN_a011e4c8(0x10 + i,
 * byte) (writes the byte to register 0xcf016450 + 4 * i, see FUN_a011e4c8), then tail-calls
 * FUN_a011e4c8(0x18, DAT_a802cc85) (ch 0x18 selects no single register there, so the byte goes to all nine).
 * Callers: FUN_a0150120. Written as eight separate ifs (the firmware code is not a loop).
 */
extern unsigned char DAT_a802a4a8[8];
extern unsigned char DAT_a802cc85;
extern void FUN_a011e4c8(unsigned char ch, unsigned char v);

void FUN_a014faa8(void)
{
    if (DAT_a802a4a8[0] != 0xff)
        FUN_a011e4c8(0x10, DAT_a802a4a8[0]);
    if (DAT_a802a4a8[1] != 0xff)
        FUN_a011e4c8(0x11, DAT_a802a4a8[1]);
    if (DAT_a802a4a8[2] != 0xff)
        FUN_a011e4c8(0x12, DAT_a802a4a8[2]);
    if (DAT_a802a4a8[3] != 0xff)
        FUN_a011e4c8(0x13, DAT_a802a4a8[3]);
    if (DAT_a802a4a8[4] != 0xff)
        FUN_a011e4c8(0x14, DAT_a802a4a8[4]);
    if (DAT_a802a4a8[5] != 0xff)
        FUN_a011e4c8(0x15, DAT_a802a4a8[5]);
    if (DAT_a802a4a8[6] != 0xff)
        FUN_a011e4c8(0x16, DAT_a802a4a8[6]);
    if (DAT_a802a4a8[7] != 0xff)
        FUN_a011e4c8(0x17, DAT_a802a4a8[7]);
    FUN_a011e4c8(0x18, DAT_a802cc85);
}
