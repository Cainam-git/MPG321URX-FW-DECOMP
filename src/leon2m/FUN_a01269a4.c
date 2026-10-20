/* leon2m FUN_a01269a4 @ 0xa01269a4  MATCH (-mcpu=v8 -O3 -g, twin)
 * Twin of FUN_a0126878: same code, constants swapped; byte-exact.
 */
extern unsigned char FUN_a01248c8(void);   /* GPIO group 9 bit 3 is high */
extern unsigned short FUN_a0147ae8();      /* I2C register read */
extern unsigned char DAT_a802d888[2];      /* last value read from device 0x60 register 0xd0 */

unsigned short FUN_a01269a4(void)
{
    if (FUN_a01248c8())
        FUN_a0147ae8(0x60, 2, 0xd0, 5, 0, DAT_a802d888, 2);
    return (DAT_a802d888[0] << 8) | DAT_a802d888[1];
}
