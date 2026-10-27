/* FUN_a010db74 (leon2m 0xa010db74-0xa010dbc4, 80 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns word k of the register block DAT_0019aec4[c] (sel 0) or DAT_0019aebc[c] (sel non-zero), c above 1
 * counting as 0; both tables hold volatile word pointers. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a010db2c and FUN_a010dbc4.
 */
extern volatile unsigned int *const DAT_0019aec4[];
extern volatile unsigned int *const DAT_0019aebc[];

unsigned int FUN_a010db74(unsigned char c, unsigned char sel, unsigned int k)
{
    volatile unsigned int *t;

    if (c > 1)
        c = 0;
    if (sel == 0)
        t = DAT_0019aec4[c];
    else
        t = DAT_0019aebc[c];
    return t[k];
}
