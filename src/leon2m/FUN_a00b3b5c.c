/* leon2m FUN_a00b3b5c @ 0xa00b3b5c-0xa00b3ba0 (17 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/17 mismatches.
 * Code facts: FUN_a00a9f30(4, bit 9 of the word DAT_a802d290) (ld, srl 9, and 1); then the sibcall
 * FUN_a00aa01c(4, 1) when on == 1, else FUN_a00aa01c(4, 0) (two arms, each sets %i0 = 4 and %i1).
 * on is a u8 param (and 0xff after the first call). Fixes vs the autoc draft (52.94): the second
 * call is written as two calls in an if/else (the '== 1' value form gives one shared call); void
 * prototypes with 2 args (the draft passed 6). Aids: none.
 */
extern unsigned int DAT_a802d290;
extern void FUN_a00a9f30(unsigned char, unsigned char);
extern void FUN_a00aa01c(unsigned char, int);

void FUN_a00b3b5c(unsigned char on)
{
    FUN_a00a9f30(4, DAT_a802d290 >> 9 & 1);
    if (on == 1)
        FUN_a00aa01c(4, 1);
    else
        FUN_a00aa01c(4, 0);
}
