/* FUN_a010b4fc (leon2m 0xa010b4fc-0xa010b530, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns word k of the register block selected by c from the pointer table DAT_0019aef0 (c above 2 selects entry
 * 0). Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a010b450 and FUN_a010b530. Source form: the table holds volatile word pointers, like DAT_0019aed8; the clamp
 * is 'if (c > 2) c = 0;'.
 */
extern volatile unsigned int *const DAT_0019aef0[];
unsigned int FUN_a010b4fc(unsigned char c, unsigned int k)
{
    if (c > 2)
        c = 0;
    return DAT_0019aef0[c][k];
}
