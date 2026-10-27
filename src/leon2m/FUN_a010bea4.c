/* FUN_a010bea4 (leon2m 0xa010bea4-0xa010bee4, 64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns word k of the register block DAT_0019aed8[c] (sel 0) or DAT_0019aecc[c] (sel non-zero); both tables hold
 * volatile word pointers. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It
 * lies between FUN_a010bdcc and FUN_a010bee4.
 */
extern volatile unsigned int *const DAT_0019aed8[];
extern volatile unsigned int *const DAT_0019aecc[];

unsigned int FUN_a010bea4(unsigned char c, unsigned char sel, unsigned int k)
{
    volatile unsigned int *t;

    if (sel == 0)
        t = DAT_0019aed8[c];
    else
        t = DAT_0019aecc[c];
    return t[k];
}
