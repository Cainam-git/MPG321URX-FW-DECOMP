/* FUN_a014e320: for the port DAT_a802e3d0[0x18] three times: when FUN_a012f134(port) is non-zero and
 * FUN_a012e550((u16)(1 << (port & 0xf)), reg, b) succeeds for reg 2 / 0x10 / 0x80, the three returned bytes b[0..2]
 * are copied to DAT_a802e1f0[6..8] / [9..0xb] / [0x12..0x14]. Caller: FUN_a008454c.
 * The order of the byte copies in each block is the order that reproduces the firmware's load/store schedule.
 */
extern unsigned char DAT_a802e3d0[];
extern unsigned char DAT_a802e1f0[];
extern unsigned char FUN_a012f134(unsigned char port);
extern unsigned char FUN_a012e550(unsigned short mask, unsigned char reg, unsigned char *buf);

void FUN_a014e320(void)
{
    unsigned char b[3];

    if (FUN_a012f134(DAT_a802e3d0[0x18]) && FUN_a012e550(1 << (DAT_a802e3d0[0x18] & 0xf), 2, b)) {
        DAT_a802e1f0[6] = b[0];
        DAT_a802e1f0[7] = b[1];
        DAT_a802e1f0[8] = b[2];
    }
    if (FUN_a012f134(DAT_a802e3d0[0x18]) && FUN_a012e550(1 << (DAT_a802e3d0[0x18] & 0xf), 0x10, b)) {
        DAT_a802e1f0[9] = b[0];
        DAT_a802e1f0[0xa] = b[1];
        DAT_a802e1f0[0xb] = b[2];
    }
    if (FUN_a012f134(DAT_a802e3d0[0x18]) && FUN_a012e550(1 << (DAT_a802e3d0[0x18] & 0xf), 0x80, b)) {
        DAT_a802e1f0[0x12] = b[0];
        DAT_a802e1f0[0x13] = b[1];
        DAT_a802e1f0[0x14] = b[2];
    }
}
