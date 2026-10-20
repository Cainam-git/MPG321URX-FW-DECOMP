/* leon2m FUN_a00920f4 @ 0xa00920f4-0xa0092188 (37 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a00a8ee8((word 0xa802afec - 24) & 0xff); loop: v = ((low halfword of 0xa802afec) - 19) % 6
 * (signed int, magic 0x2aaaaaab), word = v + 24, until FUN_a00aa520(v & 0xff) returns 1 (u8 test);
 * FUN_a00a900c((word - 24) & 0xff, 1); tail call FUN_a00af44c(0x18, (word - 24) & 0xff).
 * Fix vs the autoc draft (79.49): the fw 'lduh [%i1 + 0x3ee]' on the SAME sethi as 'ld [%i1 + 0x3ec]' is
 * '(unsigned short)_DAT_a802afec': combine narrows the SImode load of the word to a HImode load at +2 and
 * keeps the lo_sum on the word's HIGH. A separate extern _DAT_a802afee gets its own sethi; a union/struct
 * member or a pointer cast gives 'or %lo' + [reg+2]. The draft also read the halfword before the loop's
 * first store in the wrong order (uVar1 used before set). Aids: none.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8ee8(unsigned char);
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00af44c(int, unsigned char);

void FUN_a00920f4(void)
{
    int v;

    FUN_a00a8ee8(_DAT_a802afec - 24);
    do {
        v = ((unsigned short)_DAT_a802afec - 19) % 6;
        _DAT_a802afec = v + 24;
    } while (FUN_a00aa520(v) != 1);
    FUN_a00a900c(_DAT_a802afec - 24, 1);
    FUN_a00af44c(0x18, _DAT_a802afec - 24);
}
