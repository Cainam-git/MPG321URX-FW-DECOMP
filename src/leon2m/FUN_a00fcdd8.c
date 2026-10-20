/* leon2m FUN_a00fcdd8 @ 0xa00fcdd8 (-mcpu=v8 -O3 -g)
 * Returns the four bytes at DAT_a802c978 as a little-endian 32-bit value: b[0] + (b[1] << 8) + (b[2] << 16) +
 * (b[3] << 24). Referenced from FUN_a0147760.
 */
extern unsigned char DAT_a802c978[4];

unsigned int FUN_a00fcdd8(void)
{
    return DAT_a802c978[0] + (DAT_a802c978[1] << 8) + (DAT_a802c978[2] << 16) + (DAT_a802c978[3] << 24);
}
