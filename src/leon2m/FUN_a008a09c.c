/* leon2m FUN_a008a09c @ 0xa008a09c-0xa008a174 (54 words). -mcpu=v8 -O3 -g.
 * (written from the asm).
 * What it does (APP event pump FUN_a008a210 callee): picks one pending event code and hands it on:
 *   v = 0xc7 (none); the first of FUN_a0088654, FUN_a008866c, FUN_a0088688, FUN_a00886a4, FUN_a00886c0,
 *   FUN_a00886dc, FUN_a00886f8 that returns nonzero gives v = 0xc0, 0xc2, 0xc1, 0xc3, 0xc4, 0xc5, 0xc6
 *   (in that order; each callee is a leaf that tests and clears one flag bit, e.g. FUN_a0088654 = bit 0 of
 *   the byte DAT_a802af99); then FUN_a008a184(v) as a tail call.
 * Not rate-dependent (event flags).
 * Code fact: the fw 'and %i0,0xc7' before the call is the u8 argument extension of v; combine narrowed the
 * 0xff mask to 0xc7 because every value of v (0xc0..0xc7) has bits 3..5 clear. volatile: none. Aids: none.
 */
extern unsigned char FUN_a0088654(void), FUN_a008866c(void), FUN_a0088688(void), FUN_a00886a4(void);
extern unsigned char FUN_a00886c0(void), FUN_a00886dc(void), FUN_a00886f8(void);
extern void FUN_a008a184(unsigned char code);

void FUN_a008a09c(void)
{
    unsigned char v = 0xc7;

    if (FUN_a0088654())
        v = 0xc0;
    else if (FUN_a008866c())
        v = 0xc2;
    else if (FUN_a0088688())
        v = 0xc1;
    else if (FUN_a00886a4())
        v = 0xc3;
    else if (FUN_a00886c0())
        v = 0xc4;
    else if (FUN_a00886dc())
        v = 0xc5;
    else if (FUN_a00886f8())
        v = 0xc6;
    FUN_a008a184(v);
}
