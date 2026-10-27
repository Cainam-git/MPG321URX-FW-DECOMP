/* FUN_a010b5dc (leon2m 0xa010b5dc-0xa010b610, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns word k of the register block selected by c from the pointer table DAT_0019aed8 (c above 2 selects entry
 * 0). Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a010b530 and FUN_a010b610. Source form: the table holds volatile word pointers; the clamp is 'if (c > 2) c =
 * 0;'.
 */
extern volatile unsigned int *const DAT_0019aed8[];

unsigned int FUN_a010b5dc(unsigned char c, unsigned int k)
{
    if (c > 2)
        c = 0;
    return DAT_0019aed8[c][k];
}
