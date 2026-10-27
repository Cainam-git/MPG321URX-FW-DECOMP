/* leon2s FUN_a00a1150 @ 0xa00a1150-0xa00a13a0, -mcpu=v8 -Os -g.
 * void (port). p = low byte of port. For the register words 0x70, 0x74, 0x78, 0x7c, 0x80, 0x90 of the block
 * ARR_a807db00[p].r0 and word 0xc4 of the block .r24 it reads the word v, calls FUN_a00a1098(p, bits of v,
 * table) with the bits (v >> 8) & 4, (v >> 16) & 2, (v >> 24) & 6 (word 0x70; written back | 0x06020400),
 * v & 3 (0x74, | 3), none (0x78), v & 8 (0x7c, | 8), (v >> 24) & 0x20 (0x80, | 0x20000000), none (0x90, 0xc4)
 * and the callback tables DAT_a80786f0/d0/b0, DAT_a8078690, DAT_a8079158, DAT_a8078670, DAT_a8078650,
 * DAT_a8079138, DAT_a8079118; byte +0x158 of the 0x190-byte record DAT_a807d7e0[p] is cleared before word 0x80.
 * Then, when byte +8 of the record is 1: clears it; when byte +1 is 1 and FUN_a0097ed0(p) returns 1: saves the
 * 0x58-byte block at +0x4c (FUN_a00b15d8), refreshes it with FUN_a009f738(p, block); a changed byte +0x30 of
 * the block sets byte +0x14 of DAT_a807d650[p] to 1, else a changed word +4 calls FUN_a009e9cc(p) and
 * FUN_a009c87c(p); finally block bytes +0x55 and +0x56 = 1 and, when +0x57 is 0, FUN_a009f738 again.
 * Source form: p is an unsigned char local; the last block indexes with (unsigned char)port (the firmware
 * masks the parameter again there).
 */
struct blk4c { unsigned int w0; unsigned int w4; unsigned char d8[0x28]; unsigned char b30; unsigned char d31[0x24]; unsigned char f55, f56, f57; };
struct mode_rec {
    unsigned char _00;
    unsigned char f01;
    unsigned char _02[6];
    unsigned char f08;
    unsigned char _09[0x4c - 0x09];
    struct blk4c cur;
    unsigned char _a4[0x158 - 0xa4];
    unsigned char f158;
    unsigned char _159[0x190 - 0x159];
};
struct st_rec { unsigned char _0[0x14]; unsigned char f14; unsigned char _15[3]; };
struct port_rec {
    volatile unsigned int *r0;
    unsigned char _04[0x20];
    volatile unsigned int *r24;
    unsigned char _28[0x34 - 0x28];
};
extern struct port_rec ARR_a807db00[];
extern struct mode_rec DAT_a807d7e0[];
extern struct st_rec DAT_a807d650[];
extern unsigned int *DAT_a80786f0[], *DAT_a80786d0[], *DAT_a80786b0[], *DAT_a8078690[], *DAT_a8079158[];
extern unsigned int *DAT_a8078670[], *DAT_a8078650[], *DAT_a8079138[], *DAT_a8079118[];
extern void FUN_a00a1098(unsigned int, unsigned char, unsigned int **);
extern unsigned int FUN_a0097ed0(unsigned int);
extern void *FUN_a00b15d8(void *, const void *, int);
extern unsigned char FUN_a009f738(unsigned char, struct blk4c *);
extern void FUN_a009e9cc(unsigned int);
extern void FUN_a009c87c(unsigned char);

void FUN_a00a1150(unsigned int port)
{
    unsigned char p = port & 0xff;
    unsigned int v;
    unsigned char r;
    struct blk4c old;

    v = ARR_a807db00[p].r0[0x70 / 4];
    FUN_a00a1098(p, (v >> 8) & 4, DAT_a80786f0);
    FUN_a00a1098(p, (v >> 16) & 2, DAT_a80786d0);
    FUN_a00a1098(p, (v >> 24) & 6, DAT_a80786b0);
    ARR_a807db00[p].r0[0x70 / 4] = v | 0x06020400;
    v = ARR_a807db00[p].r0[0x74 / 4];
    FUN_a00a1098(p, v & 3, DAT_a8078690);
    ARR_a807db00[p].r0[0x74 / 4] = v | 3;
    v = ARR_a807db00[p].r0[0x78 / 4];
    FUN_a00a1098(p, 0, DAT_a8079158);
    ARR_a807db00[p].r0[0x78 / 4] = v;
    v = ARR_a807db00[p].r0[0x7c / 4];
    FUN_a00a1098(p, v & 8, DAT_a8078670);
    ARR_a807db00[p].r0[0x7c / 4] = v | 8;
    DAT_a807d7e0[p].f158 = 0;
    v = ARR_a807db00[p].r0[0x80 / 4];
    FUN_a00a1098(p, (v >> 24) & 0x20, DAT_a8078650);
    ARR_a807db00[p].r0[0x80 / 4] = v | 0x20000000;
    v = ARR_a807db00[p].r0[0x90 / 4];
    FUN_a00a1098(p, 0, DAT_a8079138);
    ARR_a807db00[p].r0[0x90 / 4] = v;
    v = ARR_a807db00[p].r24[0xc4 / 4];
    FUN_a00a1098(p, 0, DAT_a8079118);
    ARR_a807db00[p].r24[0xc4 / 4] = v;
    if (DAT_a807d7e0[p].f08 == 1) {
        DAT_a807d7e0[p].f08 = 0;
        if (DAT_a807d7e0[p].f01 == 1) {
            r = FUN_a0097ed0(p);
            if (r == 1) {
                FUN_a00b15d8(&old, &DAT_a807d7e0[p].cur, sizeof(old));
                FUN_a009f738(p, &DAT_a807d7e0[p].cur);
                if (DAT_a807d7e0[p].cur.b30 != old.b30)
                    DAT_a807d650[p].f14 = 1;
                else if (DAT_a807d7e0[p].cur.w4 != old.w4) {
                    FUN_a009e9cc(p);
                    FUN_a009c87c(p);
                }
                DAT_a807d7e0[(unsigned char)port].cur.f55 = 1;
                DAT_a807d7e0[(unsigned char)port].cur.f56 = 1;
                if (DAT_a807d7e0[(unsigned char)port].cur.f57 == 0)
                    FUN_a009f738((unsigned char)port, &DAT_a807d7e0[(unsigned char)port].cur);
            }
        }
    }
}
