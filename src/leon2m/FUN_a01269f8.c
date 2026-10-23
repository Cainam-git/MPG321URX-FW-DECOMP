/* leon2m FUN_a01269f8 @ 0xa01269f8 (-mcpu=v8 -O3 -g)
 * When FUN_a01248c8() returns nonzero, reads two bytes of register 0x10 of I2C device 0x60 into 0xA802D888 through
 * FUN_a0147ae8(0x60, 2, 0x10, 5, 0, 0xA802D888, 2). Returns the bytes at 0xA802D888 and 0xA802D889 as a big-endian
 * halfword. Same code as FUN_a0126878 with other constants.
 */
extern unsigned char FUN_a01248c8(void);   /* GPIO group 9 bit 3 is high */
extern unsigned short FUN_a0147ae8();      /* I2C register read */
extern unsigned char DAT_a802d888[2];      /* last value read from device 0x60 register 0x10 */

unsigned short FUN_a01269f8(void)
{
    if (FUN_a01248c8())
        FUN_a0147ae8(0x60, 2, 0x10, 5, 0, DAT_a802d888, 2);
    return (DAT_a802d888[0] << 8) | DAT_a802d888[1];
}
