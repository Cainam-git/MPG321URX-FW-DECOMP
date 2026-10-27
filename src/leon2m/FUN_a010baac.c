/* FUN_a010baac (leon2m 0xa010baac-0xa010baf4, 72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores v to word k of the register block DAT_0019aed8[c] (sel 0) or DAT_0019aecc[c] (sel non-zero); both tables
 * hold volatile word pointers. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a010b96c and FUN_a010baf4.
 */
extern volatile unsigned int *const DAT_0019aed8[];
extern volatile unsigned int *const DAT_0019aecc[];

void FUN_a010baac(unsigned char c, unsigned char sel, unsigned int k, unsigned int v)
{
    if (sel == 0)
        DAT_0019aed8[c][k] = v;
    else
        DAT_0019aecc[c][k] = v;
}
