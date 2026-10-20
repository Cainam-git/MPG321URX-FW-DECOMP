/* leon2m FUN_a0121374 @ 0xa0121374 (-mcpu=v8 -O2 -g)
 * Returns bit param_1 of the word at 0xa802c9e4: (word >> param_1) & 1. The shift count has no `& 0x1f` mask;
 * SPARC srl uses only the low 5 bits of the count, and GCC emits sethi, ld, srl, retl, and.
 */
extern unsigned int _DAT_a802c9e4; /* 0xa802c9e4 */

unsigned int FUN_a0121374(unsigned int param_1)
{
    return (_DAT_a802c9e4 >> param_1) & 1;
}
