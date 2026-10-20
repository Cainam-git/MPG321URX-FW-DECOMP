/* leon2m FUN_a010e0f4 @ 0xa010e0f4-0xa010e448 (213 words).
 * ch selects a record (ch == 1: 0xA802D804, else 0xA802D704); stores the low byte of sel at its byte +0x27. For
 * ch == 0 the hardware register pairs are 0xd0032120/0xd0032124 and 0xd00321dc/0xd00321e0 with the control word
 * 0xd0032004; for any other ch they are 0xd0032128/0xd003212c, 0xd00321e4/0xd00321e8 and 0xd0032008. Every register
 * write goes to the 0xd0032xxx register and to the same offset at 0xd003axxx. By (unsigned char)sel (jump table):
 * 1 stores a and b in record words +0x28/+0x2c and the first pair, and sets bit 5 of the control word; 2 clears
 * them and bit 5; 3 stores a and b in +0x30/+0x34 and the second pair, and sets bit 6; 4 clears them and bit 6;
 * 0 clears all four words, both pairs and bits 5-6. The control word is read once and written back to both blocks
 * (unchanged for other sel values). sel is an unsigned int parameter (the byte store uses the unmasked register).
 * No direct callers were found.
 */
#define R(a) (*(volatile unsigned int *)(a))

struct ChRec {
    unsigned char pad[0x27];
    unsigned char sel;
    unsigned int w28, w2c, w30, w34;
};
extern struct ChRec DAT_a802d704, DAT_a802d804;

void FUN_a010e0f4(unsigned char ch, unsigned int sel, unsigned int a, unsigned int b)
{
    struct ChRec *p;
    unsigned int v;

    p = &DAT_a802d704;
    if (ch == 1) p = &DAT_a802d804;
    p->sel = sel;
    if (ch == 0) {
        v = R(0xd0032004);
        switch ((unsigned char)sel) {
        case 0:
            p->w28 = 0;
            p->w2c = 0;
            p->w30 = 0;
            p->w34 = 0;
            R(0xd0032120) = 0;
            R(0xd003a120) = 0;
            R(0xd00321dc) = 0;
            R(0xd003a1dc) = 0;
            R(0xd0032124) = 0;
            R(0xd003a124) = 0;
            R(0xd00321e0) = 0;
            R(0xd003a1e0) = 0;
            v &= ~0x60;
            break;
        case 1:
            p->w28 = a;
            p->w2c = b;
            R(0xd0032120) = a;
            R(0xd003a120) = a;
            R(0xd0032124) = b;
            R(0xd003a124) = b;
            v |= 0x20;
            break;
        case 2:
            p->w28 = 0;
            p->w2c = 0;
            R(0xd0032120) = 0;
            R(0xd003a120) = 0;
            R(0xd0032124) = 0;
            R(0xd003a124) = 0;
            v &= ~0x20;
            break;
        case 3:
            p->w30 = a;
            p->w34 = b;
            R(0xd00321dc) = a;
            R(0xd003a1dc) = a;
            R(0xd00321e0) = b;
            R(0xd003a1e0) = b;
            v |= 0x40;
            break;
        case 4:
            p->w30 = 0;
            p->w34 = 0;
            R(0xd00321dc) = 0;
            R(0xd003a1dc) = 0;
            R(0xd00321e0) = 0;
            R(0xd003a1e0) = 0;
            v &= ~0x40;
            break;
        }
        R(0xd0032004) = v;
        R(0xd003a004) = v;
    } else {
        v = R(0xd0032008);
        switch ((unsigned char)sel) {
        case 0:
            p->w28 = 0;
            p->w2c = 0;
            p->w30 = 0;
            p->w34 = 0;
            R(0xd0032128) = 0;
            R(0xd003a128) = 0;
            R(0xd00321e4) = 0;
            R(0xd003a1e4) = 0;
            R(0xd003212c) = 0;
            R(0xd003a12c) = 0;
            R(0xd00321e8) = 0;
            R(0xd003a1e8) = 0;
            v &= ~0x60;
            break;
        case 1:
            p->w28 = a;
            p->w2c = b;
            R(0xd0032128) = a;
            R(0xd003a128) = a;
            R(0xd003212c) = b;
            R(0xd003a12c) = b;
            v |= 0x20;
            break;
        case 2:
            p->w28 = 0;
            p->w2c = 0;
            R(0xd0032128) = 0;
            R(0xd003a128) = 0;
            R(0xd003212c) = 0;
            R(0xd003a12c) = 0;
            v &= ~0x20;
            break;
        case 3:
            p->w30 = a;
            p->w34 = b;
            R(0xd00321e4) = a;
            R(0xd003a1e4) = a;
            R(0xd00321e8) = b;
            R(0xd003a1e8) = b;
            v |= 0x40;
            break;
        case 4:
            p->w30 = 0;
            p->w34 = 0;
            R(0xd00321e4) = 0;
            R(0xd003a1e4) = 0;
            R(0xd00321e8) = 0;
            R(0xd003a1e8) = 0;
            v &= ~0x40;
            break;
        }
        R(0xd0032008) = v;
        R(0xd003a008) = v;
    }
}
