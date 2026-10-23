/* FUN_a011c4cc (leon2m 0xa011c4cc-0xa011c6c8, 508 bytes), flags -mcpu=v8 -O3 -g. Caller: FUN_a01461dc.
 * Picks five register addresses by sel (0: 0xcf00bfcc, 0xcf011780, 0xcf011784, 0xcf011788, 0xcf01178c; other:
 * 0xcf00c3cc, 0xcf011794, 0xcf011798, 0xcf01179c, 0xcf0117a0) and clears bit 7 of register DAT_a8027aa8[sel] + 0
 * with the inlined FUN_a01191fc. Writes x->cmd & 0xf0 to the second address, the word x->addr to the third, its
 * bits 8-31 to the fourth and its high halfword to the first; then x->n bytes of x->data to the fifth address.
 * With rle != 0 a byte 0x00 or 0xff is followed by a count byte and is written that many times (count 0 = 256).
 * Every register write is followed by a 160-nop delay loop.
 * Source form: the RB() register macro accesses 'volatile unsigned long'; with 'volatile unsigned int' (the type of
 * the selected pointers) the registers of the inlined bit clear differ.
 */
#define RB(a) (*(volatile unsigned long *)(0xcf000000 | ((a) << 2)))
extern unsigned short DAT_a8027aa8[2];

struct Blk {
    unsigned short n;
    unsigned short pad;
    unsigned int cmd;
    union { unsigned int w; unsigned short h[2]; } addr;
    unsigned char *data;
};

void FUN_a01191fc(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = RB(DAT_a8027aa8[blk] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    RB(DAT_a8027aa8[blk] + reg) = (unsigned char)v;
}

void FUN_a011c4cc(int rle, struct Blk *x, unsigned char sel)
{
    volatile unsigned int *data;
    volatile unsigned int *cmd;
    volatile unsigned int *a0;
    volatile unsigned int *a1;
    volatile unsigned int *strobe;
    unsigned short n, i;
    unsigned char c, cnt;
    int k;

    if (sel == 0) {
        strobe = (volatile unsigned int *)0xcf00bfcc;
        cmd = (volatile unsigned int *)0xcf011780;
        a0 = (volatile unsigned int *)0xcf011784;
        a1 = (volatile unsigned int *)0xcf011788;
        data = (volatile unsigned int *)0xcf01178c;
    } else {
        strobe = (volatile unsigned int *)0xcf00c3cc;
        cmd = (volatile unsigned int *)0xcf011794;
        a0 = (volatile unsigned int *)0xcf011798;
        a1 = (volatile unsigned int *)0xcf01179c;
        data = (volatile unsigned int *)0xcf0117a0;
    }
    FUN_a01191fc(sel, 0, 0x80, 0);
    *cmd = x->cmd & 0xf0;
    n = x->n;
    for (k = 0; k < 0xa0; k++)
        __asm__("nop");
    *a0 = x->addr.w;
    *a1 = x->addr.w >> 8;
    *strobe = x->addr.h[0];
    for (k = 0; k < 0xa0; k++)
        __asm__("nop");
    if (rle == 0) {
        for (i = 0; i < n; i++) {
            *data = x->data[i];
            for (k = 0; k < 0xa0; k++)
                __asm__("nop");
        }
    } else {
        for (i = 0; i < n; i++) {
            c = x->data[i];
            if (c == 0 || c == 0xff) {
                cnt = x->data[++i];
                do {
                    *data = c;
                    for (k = 0; k < 0xa0; k++)
                        __asm__("nop");
                } while (--cnt);
            } else {
                *data = c;
                for (k = 0; k < 0xa0; k++)
                    __asm__("nop");
            }
        }
    }
}
