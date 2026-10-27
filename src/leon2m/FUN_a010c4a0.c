/* FUN_a010c4a0 (leon2m 0xa010c4a0-0xa010c54c, 172 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores v to word k of register block c of the pointer tables DAT_0019aec4 and DAT_0019aebc; for c above 1 stores
 * it to word k of blocks 0..1 of both tables (both tables hold volatile word pointers). Nothing in the image refers
 * to it: no call, branch, sethi/or constant or address word. It lies between FUN_a010c390 and FUN_a010c54c. Source
 * form: a separate if (c > N) loop/else statement per table, unsigned int loop counter.
 */
extern volatile unsigned int *const DAT_0019aec4[];
extern volatile unsigned int *const DAT_0019aebc[];

void FUN_a010c4a0(unsigned char c, unsigned int k, unsigned int v)
{
    unsigned int i;

    if (c > 1) {
        for (i = 0; i <= 1; i++)
            DAT_0019aec4[i][k] = v;
    } else
        DAT_0019aec4[c][k] = v;
    if (c > 1) {
        for (i = 0; i <= 1; i++)
            DAT_0019aebc[i][k] = v;
    } else
        DAT_0019aebc[c][k] = v;
}
