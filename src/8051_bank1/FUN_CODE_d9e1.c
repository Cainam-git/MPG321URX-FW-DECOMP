/* 8051_bank1 FUN_CODE_d9e1 @ 0xD9E1..0xD9FF (30 bytes).
 * Returns the 16-bit value stored low byte first at XDATA 0x9A00 + i: the low byte is read from 0x9A00 + i and the
 * high byte from the next address, both through a generic pointer (Keil ?C?CLDPTR), and combined as hi << 8 | lo.
 * No caller in the image. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_9a00[];
unsigned int FUN_CODE_d9e1(unsigned char i)
{
    unsigned char *p;
    unsigned char lo, hi;
    p = DAT_EXTMEM_9a00;
    p += i;
    lo = *p;
    p++;
    hi = *p;
    return ((unsigned int)hi << 8) | lo;
}
