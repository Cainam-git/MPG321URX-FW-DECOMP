/* FUN_a010daf8 (leon2m 0xa010daf8-0xa010db2c, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns word k of the register block selected by c from the pointer table DAT_0019aec4 (c above 1 selects entry
 * 0). Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a010d914 and FUN_a010db2c. Source form: the table holds volatile word pointers; the clamp is 'if (c > 1) c =
 * 0;'.
 */
extern volatile unsigned int *const DAT_0019aec4[];

unsigned int FUN_a010daf8(unsigned char c, unsigned int k)
{
    if (c > 1)
        c = 0;
    return DAT_0019aec4[c][k];
}
