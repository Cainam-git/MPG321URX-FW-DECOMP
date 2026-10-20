/* leon2m FUN_a0100a40 @ 0xa0100a40-0xa0100e6c (267 words).
 * Writes block registers 0x19/0x1a (FUN_a00f1ad4, FUN_a00f1b5c) of block blk chosen by word 0xa8027a78 and byte
 * 0xa8027a75. Word == 2: 0x19 = 0, 0x1a = 0. Word >= 3: 0x19 = ((word << 3) | 0x80) & 0xf8, 0x1a = 0x19.
 * Word 0 or 1: a jump table over byte 0..42 (values above 42 take the default). The case groups write
 * 0x19 = 0x88 / 0xf8 / 0xb0 / 0 and then 0x1a = 0x19 or 0x39, or clear bit 0 of 0x1a, and set or clear bit 5 of
 * 0x1a; cases 28-39 choose between two of these forms by blk == 0; case 41 also writes the 15 halfwords at 0x19a5bc
 * to block registers 0x1b, 0x1d, 0x1f, 0x21, 0x23 (FUN_a00f1d48) in three groups separated by writes of 8/2,
 * 0xa/4 and 0xc/9 to 0x1a. Finally, for blk == 4, copies byte 0xa8027a75 to byte 0xa8027a7c.
 * Called from FUN_a01012a8. Source form: the table is read through a local pointer t in case 41.
 */
extern unsigned int DAT_a8027a78;
extern unsigned char DAT_a8027a75, DAT_a8027a7c;
extern const unsigned short DAT_0019a5bc[15];
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern void FUN_a00f1d48(unsigned char blk, unsigned char reg, unsigned short val);

void FUN_a0100a40(unsigned char blk)
{
    if (DAT_a8027a78 == 2) {
        FUN_a00f1ad4(blk, 0x19, 0);
        FUN_a00f1ad4(blk, 0x1a, 0);
    } else if (DAT_a8027a78 <= 1) {
        switch (DAT_a8027a75) {
        case 0: case 26:
            FUN_a00f1ad4(blk, 0x19, 0x88);
            FUN_a00f1ad4(blk, 0x1a, 0x19);
            FUN_a00f1b5c(blk, 0x1a, 0x20, 0);
            break;
        case 1: case 27:
            FUN_a00f1ad4(blk, 0x19, 0xf8);
            FUN_a00f1ad4(blk, 0x1a, 0x19);
            FUN_a00f1b5c(blk, 0x1a, 0x20, 0);
            break;
        case 2: case 6: case 8: case 12: case 14: case 18: case 20: case 24:
            FUN_a00f1ad4(blk, 0x19, 0xb0);
            FUN_a00f1ad4(blk, 0x1a, 0x19);
            FUN_a00f1b5c(blk, 0x1a, 0x20, 0);
            break;
        case 4: case 10: case 16: case 22:
            FUN_a00f1ad4(blk, 0x19, 0xb0);
            FUN_a00f1ad4(blk, 0x1a, 0x39);
            break;
        case 5: case 11: case 17: case 23:
            FUN_a00f1ad4(blk, 0x19, 0);
            FUN_a00f1b5c(blk, 0x1a, 1, 0);
            FUN_a00f1b5c(blk, 0x1a, 0x20, 1);
            break;
        case 28: case 32: case 34: case 38:
            if (blk != 0)
                FUN_a00f1ad4(blk, 0x19, 0xb0);
            else
                FUN_a00f1ad4(blk, 0x19, 0x88);
            FUN_a00f1ad4(blk, 0x1a, 0x19);
            FUN_a00f1b5c(blk, 0x1a, 0x20, 0);
            break;
        case 29: case 33: case 35: case 39:
            if (blk == 0) {
                FUN_a00f1ad4(blk, 0x19, 0xf8);
                FUN_a00f1ad4(blk, 0x1a, 0x19);
            } else {
                FUN_a00f1ad4(blk, 0x19, 0);
                FUN_a00f1b5c(blk, 0x1a, 1, 0);
            }
            FUN_a00f1b5c(blk, 0x1a, 0x20, 0);
            break;
        case 30: case 36:
            if (blk == 0)
                FUN_a00f1ad4(blk, 0x19, 0x88);
            else
                FUN_a00f1ad4(blk, 0x19, 0xb0);
            FUN_a00f1ad4(blk, 0x1a, 0x19);
            FUN_a00f1b5c(blk, 0x1a, 0x20, 1);
            break;
        case 31: case 37:
            if (blk == 0) {
                FUN_a00f1ad4(blk, 0x19, 0xf8);
                FUN_a00f1ad4(blk, 0x1a, 0x19);
            } else {
                FUN_a00f1ad4(blk, 0x19, 0);
                FUN_a00f1b5c(blk, 0x1a, 1, 0);
            }
            FUN_a00f1b5c(blk, 0x1a, 0x20, 1);
            break;
        case 41: {
            const unsigned short *t = DAT_0019a5bc;
            FUN_a00f1ad4(blk, 0x19, 0);
            FUN_a00f1ad4(blk, 0x1a, 0);
            FUN_a00f1d48(blk, 0x1b, t[0]);
            FUN_a00f1d48(blk, 0x1d, t[1]);
            FUN_a00f1d48(blk, 0x1f, t[2]);
            FUN_a00f1d48(blk, 0x21, t[3]);
            FUN_a00f1d48(blk, 0x23, t[4]);
            FUN_a00f1ad4(blk, 0x1a, 8);
            FUN_a00f1ad4(blk, 0x1a, 2);
            FUN_a00f1d48(blk, 0x1b, t[5]);
            FUN_a00f1d48(blk, 0x1d, t[6]);
            FUN_a00f1d48(blk, 0x1f, t[7]);
            FUN_a00f1d48(blk, 0x21, t[8]);
            FUN_a00f1d48(blk, 0x23, t[9]);
            FUN_a00f1ad4(blk, 0x1a, 0xa);
            FUN_a00f1ad4(blk, 0x1a, 4);
            FUN_a00f1d48(blk, 0x1b, t[10]);
            FUN_a00f1d48(blk, 0x1d, t[11]);
            FUN_a00f1d48(blk, 0x1f, t[12]);
            FUN_a00f1d48(blk, 0x21, t[13]);
            FUN_a00f1d48(blk, 0x23, t[14]);
            FUN_a00f1ad4(blk, 0x1a, 0xc);
            FUN_a00f1ad4(blk, 0x1a, 9);
            FUN_a00f1ad4(blk, 0x1a, 0x19);
            FUN_a00f1b5c(blk, 0x1a, 0x20, 0);
            break;
        }
        case 42:
            FUN_a00f1ad4(blk, 0x19, 0);
            FUN_a00f1ad4(blk, 0x1a, 0xfe);
            FUN_a00f1b5c(blk, 0x1a, 0x20, 0);
            break;
        default:
            FUN_a00f1ad4(blk, 0x19, 0);
            FUN_a00f1b5c(blk, 0x1a, 1, 0);
            FUN_a00f1b5c(blk, 0x1a, 0x20, 0);
            break;
        }
    } else {
        FUN_a00f1ad4(blk, 0x19, ((DAT_a8027a78 << 3) | 0x80) & 0xf8);
        FUN_a00f1ad4(blk, 0x1a, 0x19);
    }
    if (blk == 4)
        DAT_a8027a7c = DAT_a8027a75;
}
