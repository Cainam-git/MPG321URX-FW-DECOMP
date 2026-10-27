/* FUN_a010db2c (leon2m 0xa010db2c-0xa010db74, 72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores v to word k of the register block DAT_0019aec4[c] (sel 0) or DAT_0019aebc[c] (sel non-zero); both tables
 * hold volatile word pointers. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a010daf8 and FUN_a010db74.
 */
extern volatile unsigned int *const DAT_0019aec4[];
extern volatile unsigned int *const DAT_0019aebc[];

void FUN_a010db2c(unsigned char c, unsigned char sel, unsigned int k, unsigned int v)
{
    if (sel == 0)
        DAT_0019aec4[c][k] = v;
    else
        DAT_0019aebc[c][k] = v;
}
