/* leon2s FUN_a00d2d1c @ 0xa00d2d1c-0xa00d2d8c (28 words incl. the unreachable ret/restore pair
 * FUN_a00d2d84), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp 0/28 mismatches.
 * Code facts: only when byte DAT_a8078c26 == 1: FUN_a00d2210(0, 0); FUN_a00d2288(0, 0);
 * FUN_a00d23bc(0, 0); FUN_a00d2300(0, 0); FUN_a00d2434(0, 0); DAT_a8078c26 = 0; tail call
 * func_0xa0f834c4(string 0x9f1c6408). void, no params.
 * Required forms: the tail arg is a SYMBOL (fw 'restore %i0, %lo(sym), %o0' on
 * the shared %hi; a plain constant gives sethi/or + plain restore) and the only arg; the (0, 0)
 * callees are (u8, u8) int as in FUN_a00d27fc. Aids: none.
 */
extern unsigned char DAT_a8078c26;
extern int FUN_a00d2210(unsigned char, unsigned char);
extern int FUN_a00d2288(unsigned char, unsigned char);
extern int FUN_a00d2300(unsigned char, unsigned char);
extern int FUN_a00d23bc(unsigned char, unsigned char);
extern int FUN_a00d2434(unsigned char, unsigned char);
extern const char s_9f1c6408[];
extern void func_0xa0f834c4(const char *);

void FUN_a00d2d1c(void)
{
    if (DAT_a8078c26 != 1)
        return;
    FUN_a00d2210(0, 0);
    FUN_a00d2288(0, 0);
    FUN_a00d23bc(0, 0);
    FUN_a00d2300(0, 0);
    FUN_a00d2434(0, 0);
    DAT_a8078c26 = 0;
    func_0xa0f834c4(s_9f1c6408);
}
