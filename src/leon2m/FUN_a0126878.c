/* leon2m FUN_a0126878 @ 0xa0126878  (hand; byte-exact at -mcpu=v8 -O3 -g)
 *
 * Reads a 16-bit value over the software I2C bus, but only while a GPIO input is high.
 *
 * - FUN_a01248c8() is a pin test: FUN_a002cd38(9, 0x08), i.e. bit 3 of GPIO input register 0xCF03C458 (group 9);
 *   it returns 1 when that pin is high.
 * - FUN_a0147ae8(dev, mode, reg, delay, bus, buf, len) is the I2C register read wrapper (-> FUN_a01256d0 ->
 *   FUN_a002bb28, the bit-banged master: start, device address with up to 10 ACK retries, register address,
 *   repeated start, read len bytes ACKing all but the last, stop). Here: device 0x60 (8-bit write address, 7-bit
 *   0x30), mode 2 = 16-bit register address, register 0x00B2, bit delay 5, bus 0 (the only bus FUN_a01256d0 serves),
 *   2 bytes into DAT_a802d888.
 * - Returns the two bytes as a big-endian 16-bit value. When the pin is low nothing is read and the value from the
 *   previous successful read is returned.
 *
 * Caller: FUN_a00dac38 (panel parameter row select) prints the result as the first %x of
 * "SYSAPI_GetPanelParamStruct %x,%x". Which board chip answers at I2C 0x60 is not named anywhere in this
 * firmware; the code only shows that it has 16-bit register addresses and register 0xB2 holds a 16-bit value.
 */
extern unsigned char FUN_a01248c8(void);   /* GPIO group 9 bit 3 is high */
extern unsigned short FUN_a0147ae8();      /* I2C register read */
extern unsigned char DAT_a802d888[2];      /* last value read from device 0x60 register 0xB2 */

unsigned short FUN_a0126878(void)
{
    if (FUN_a01248c8())
        FUN_a0147ae8(0x60, 2, 0xb2, 5, 0, DAT_a802d888, 2);
    return (DAT_a802d888[0] << 8) | DAT_a802d888[1];
}
