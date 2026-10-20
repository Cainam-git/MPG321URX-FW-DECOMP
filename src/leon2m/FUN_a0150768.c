/* leon2m FUN_a0150768 @ 0xa0150768-0xa0150a98 (204 words incl. the unreachable ret/restore pair
 * FUN_a0150a90), flags -mcpu=v8 -O3 -g.
 * Code facts: p (u8), q (u8). For each bit b = 0x01, 0x02, ... 0x80 in turn: if bit b is set in
 * byte DAT_a802cc86 or in byte DAT_a802cc87, call FUN_a00fe880(q, b, t) with t = 10 when p == 1
 * and t = 0 otherwise (two unrolled copies of the 8 tests; the p != 1 copy is the fall-through).
 * cc86 is re-read before each test (calls in between); not volatile. void.
 * Fix vs the autoc draft (81.86): no volatile on the RAM byte cc86 (the draft had it); u8 q with
 * the plain bit tests; FUN_a00fe880(u8, u32, u32) prototype. Aids: none.
 */
extern unsigned char DAT_a802cc86;
extern unsigned char DAT_a802cc87;
extern void FUN_a00fe880(unsigned char, unsigned int, unsigned int);

void FUN_a0150768(unsigned char p, unsigned char q)
{
    if (p == 1) {
        if ((DAT_a802cc86 & 0x1) || (DAT_a802cc87 & 0x1))
            FUN_a00fe880(q, 0x1, 10);
        if ((DAT_a802cc86 & 0x2) || (DAT_a802cc87 & 0x2))
            FUN_a00fe880(q, 0x2, 10);
        if ((DAT_a802cc86 & 0x4) || (DAT_a802cc87 & 0x4))
            FUN_a00fe880(q, 0x4, 10);
        if ((DAT_a802cc86 & 0x8) || (DAT_a802cc87 & 0x8))
            FUN_a00fe880(q, 0x8, 10);
        if ((DAT_a802cc86 & 0x10) || (DAT_a802cc87 & 0x10))
            FUN_a00fe880(q, 0x10, 10);
        if ((DAT_a802cc86 & 0x20) || (DAT_a802cc87 & 0x20))
            FUN_a00fe880(q, 0x20, 10);
        if ((DAT_a802cc86 & 0x40) || (DAT_a802cc87 & 0x40))
            FUN_a00fe880(q, 0x40, 10);
        if ((DAT_a802cc86 & 0x80) || (DAT_a802cc87 & 0x80))
            FUN_a00fe880(q, 0x80, 10);
    } else {
        if ((DAT_a802cc86 & 0x1) || (DAT_a802cc87 & 0x1))
            FUN_a00fe880(q, 0x1, 0);
        if ((DAT_a802cc86 & 0x2) || (DAT_a802cc87 & 0x2))
            FUN_a00fe880(q, 0x2, 0);
        if ((DAT_a802cc86 & 0x4) || (DAT_a802cc87 & 0x4))
            FUN_a00fe880(q, 0x4, 0);
        if ((DAT_a802cc86 & 0x8) || (DAT_a802cc87 & 0x8))
            FUN_a00fe880(q, 0x8, 0);
        if ((DAT_a802cc86 & 0x10) || (DAT_a802cc87 & 0x10))
            FUN_a00fe880(q, 0x10, 0);
        if ((DAT_a802cc86 & 0x20) || (DAT_a802cc87 & 0x20))
            FUN_a00fe880(q, 0x20, 0);
        if ((DAT_a802cc86 & 0x40) || (DAT_a802cc87 & 0x40))
            FUN_a00fe880(q, 0x40, 0);
        if ((DAT_a802cc86 & 0x80) || (DAT_a802cc87 & 0x80))
            FUN_a00fe880(q, 0x80, 0);
    }
}
