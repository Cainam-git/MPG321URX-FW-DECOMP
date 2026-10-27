/* FUN_a010b450 (leon2m 0xa010b450-0xa010b4fc, 172 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores v to word k of register block c of the pointer tables DAT_0019aef0 and DAT_0019aee4; for c above 2 stores
 * it to word k of blocks 0..2 of both tables (both tables hold volatile word pointers). Nothing in the image refers
 * to it: no call, branch, sethi/or constant or address word. It lies between FUN_a010b444 and FUN_a010b4fc. Source
 * form: a separate if (c > N) loop/else statement per table, unsigned int loop counter.
 */
extern volatile unsigned int *const DAT_0019aef0[];
extern volatile unsigned int *const DAT_0019aee4[];

void FUN_a010b450(unsigned char c, unsigned int k, unsigned int v)
{
    unsigned int i;

    if (c > 2) {
        for (i = 0; i <= 2; i++)
            DAT_0019aef0[i][k] = v;
    } else
        DAT_0019aef0[c][k] = v;
    if (c > 2) {
        for (i = 0; i <= 2; i++)
            DAT_0019aee4[i][k] = v;
    } else
        DAT_0019aee4[c][k] = v;
}
