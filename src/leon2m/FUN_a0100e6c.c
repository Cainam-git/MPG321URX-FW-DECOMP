/* leon2m FUN_a0100e6c @ 0xa0100e6c-0xa0101028 (111 words).
 * Sets byte 0xa8027a75 by word 0xa8027a78: 2 -> 1; other than 1 and 2 -> byte 0xa8027a74. For 1, by c: 0x31, 0x41,
 * 0x51, 0x61, 0x71, 0x81 -> d; 0x21 -> w = FUN_a00f8dd4(port), h = FUN_a00f8df0(port); register 1 of block port
 * = 0x24 for 0x780 x 0x438 or 0x500 x 0x2d0, else 1 (FUN_a00f1ad4); 20 ms delay; the byte = 9 for those two
 * sizes, else 3; any other c -> 1 (the value of the word).
 * Source form: FUN_a00f8dd4 and FUN_a00f8df0 (12-bit results) are declared returning unsigned short (the build
 * truncates right after the calls); pairs of equality tests in one || and the other tests as separate arms.
 */
extern unsigned int DAT_a8027a78;
extern unsigned char DAT_a8027a74, DAT_a8027a75;
extern unsigned short FUN_a00f8dd4(unsigned char blk);
extern unsigned short FUN_a00f8df0(unsigned char blk);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern void func_0x4008d1a0(int ms);

void FUN_a0100e6c(unsigned int unused, unsigned char port, unsigned char c, unsigned char d)
{
    if (DAT_a8027a78 == 1) {
        if (c == 0x31 || c == 0x41)
            DAT_a8027a75 = d;
        else if (c == 0x51 || c == 0x61)
            DAT_a8027a75 = d;
        else if (c == 0x21) {
            unsigned short w = FUN_a00f8dd4(port);
            unsigned short h = FUN_a00f8df0(port);

            if ((w == 0x780 && h == 0x438) || (w == 0x500 && h == 0x2d0))
                FUN_a00f1ad4(port, 1, 0x24);
            else
                FUN_a00f1ad4(port, 1, 1);
            func_0x4008d1a0(20);
            if ((w == 0x780 && h == 0x438) || (w == 0x500 && h == 0x2d0))
                DAT_a8027a75 = 9;
            else
                DAT_a8027a75 = 3;
        } else if (c == 0x71)
            DAT_a8027a75 = d;
        else if (c == 0x81)
            DAT_a8027a75 = d;
        else
            DAT_a8027a75 = DAT_a8027a78;
    } else if (DAT_a8027a78 == 2)
        DAT_a8027a75 = 1;
    else
        DAT_a8027a75 = DAT_a8027a74;
}
