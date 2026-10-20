/* leon2m FUN_a00b7980 @ 0xa00b7980-0xa00b79cc (19 words; the fw nop at 0xa00b79cc is padding), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf; if bit 20 of word 0xa802d290+0xac is set and byte +0x1f == 0: tail FUN_a00a9f30(6, 1);
 * else tail FUN_a00a9f30(6, 0) (both leaf sibcalls 'mov %o7, %g1; call; mov %g1, %o7').
 * Fix vs the autoc draft (75.00): one record DAT_a802d290 via a struct pointer (fw sethi|or into %o4, both reads
 * off it; the draft named mid-record _DAT_a802d33c / DAT_a802d2af), void callee. Aids: none.
 */
struct G290 { unsigned char pad[0x1f]; unsigned char b1f; unsigned char pad2[0x8c]; unsigned int wac; };
extern struct G290 DAT_a802d290;
extern void FUN_a00a9f30(int, int);

void FUN_a00b7980(void)
{
    struct G290 *p = &DAT_a802d290;

    if ((p->wac & 0x100000) != 0 && p->b1f == 0) {
        FUN_a00a9f30(6, 1);
        return;
    }
    FUN_a00a9f30(6, 0);
}
