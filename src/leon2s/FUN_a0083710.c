/* FUN_a0083710 (leon2s 0xa0083710-0xa0083870, 352 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns a 3-bit status from the word DAT_a80789e4. sel 1..4 is first replaced by
 * ((DAT_a80761a8 >> (sel * 2 - 2)) & 3) + 1. Then a switch (jump table) on sel: cases 0..4 test three bits
 * (0: bits 0/1/2, 1: bits 3/4/5, 2: bits 6/7/8, 3: bits 13/14/15, 4: bits 16/17/18) and return 1, | 2 and | 4
 * for them; cases 5 and 6 test two bits (5: bits 9/10, 6: bits 11/12) for 1 and | 2; any other sel gives 0.
 */
extern unsigned char DAT_a80761a8;
extern unsigned int DAT_a80789e4;

unsigned char FUN_a0083710(int sel)
{
    unsigned char r = 0;

    if ((unsigned int)(sel - 1) <= 3)
        sel = ((DAT_a80761a8 >> (sel * 2 - 2)) & 3) + 1;
    switch (sel) {
    case 0:
        if (DAT_a80789e4 & 1)
            r = 1;
        if (DAT_a80789e4 & 2)
            r |= 2;
        if (DAT_a80789e4 & 4)
            r |= 4;
        break;
    case 1:
        if (DAT_a80789e4 & 8)
            r = 1;
        if (DAT_a80789e4 & 0x10)
            r |= 2;
        if (DAT_a80789e4 & 0x20)
            r |= 4;
        break;
    case 2:
        if (DAT_a80789e4 & 0x40)
            r = 1;
        if (DAT_a80789e4 & 0x80)
            r |= 2;
        if (DAT_a80789e4 & 0x100)
            r |= 4;
        break;
    case 3:
        if (DAT_a80789e4 & 0x2000)
            r = 1;
        if (DAT_a80789e4 & 0x4000)
            r |= 2;
        if (DAT_a80789e4 & 0x8000)
            r |= 4;
        break;
    case 4:
        if (DAT_a80789e4 & 0x10000)
            r = 1;
        if (DAT_a80789e4 & 0x20000)
            r |= 2;
        if (DAT_a80789e4 & 0x40000)
            r |= 4;
        break;
    case 5:
        if (DAT_a80789e4 & 0x200)
            r = 1;
        if (DAT_a80789e4 & 0x400)
            r |= 2;
        break;
    case 6:
        if (DAT_a80789e4 & 0x800)
            r = 1;
        if (DAT_a80789e4 & 0x1000)
            r |= 2;
        break;
    }
    return r;
}
