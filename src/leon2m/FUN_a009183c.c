/* leon2m FUN_a009183c @ 0xa009183c-0xa00918f4 (46 words), flags -mcpu=v8 -O3 -g.
 * Code facts: w = word 0xa802afec; FUN_a00a8ee8((w - 11) & 0xff); FUN_a00aa4c0((w - 11) & 0xff, 0);
 * loop: v = ((low halfword of w) - 10) % 3 (signed, magic 0x55555556), w = v + 11, until
 * FUN_a00aa520(v & 0xff) returns 1; FUN_a00a900c((w - 11) & 0xff, 1); FUN_a00aa4c0((w - 11) & 0xff, 1);
 * tail call FUN_a00af44c(11, (w - 11) & 0xff).
 * Fix vs the autoc draft (76.6): BEHAVIOUR - FUN_a00aa4c0(.., 1) runs BEFORE the FUN_a00af44c tail call
 * (draft had it last); the halfword is '(unsigned short)_DAT_a802afec' (see FUN_a00920f4). Aids: none.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00aa4c0(unsigned char, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00af44c(int, unsigned char);

void FUN_a009183c(void)
{
    int v;

    FUN_a00a8ee8(_DAT_a802afec - 11);
    FUN_a00aa4c0(_DAT_a802afec - 11, 0);
    do {
        v = ((unsigned short)_DAT_a802afec - 10) % 3;
        _DAT_a802afec = v + 11;
    } while (FUN_a00aa520(v) != 1);
    FUN_a00a900c(_DAT_a802afec - 11, 1);
    FUN_a00aa4c0(_DAT_a802afec - 11, 1);
    FUN_a00af44c(11, _DAT_a802afec - 11);
}
