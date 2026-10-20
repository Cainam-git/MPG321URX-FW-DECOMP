/* leon2m FUN_a011b3b8 @ 0xa011b3b8  MATCH (-mcpu=v8 -O2 -g)
 * Stores the byte param_1 into the 256-byte table DAT_a802c9a0 at index param_2 & 0xff.
 *
 * Required form: the global is declared as an array and indexed with a plain subscript, which makes the global
 * address the base register and the index the offset (stb %o0, [%g1 + %o1]); the pointer form (&DAT)[idx] swaps
 * the two registers.
 */
extern unsigned char DAT_a802c9a0[256]; /* 0xa802c9a0 */

void FUN_a011b3b8(unsigned char param_1, unsigned int param_2)
{
    DAT_a802c9a0[param_2 & 0xff] = param_1;
}
