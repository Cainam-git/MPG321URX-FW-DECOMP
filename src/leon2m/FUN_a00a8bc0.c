/* leon2m FUN_a00a8bc0 @ 0xa00a8bc0 (-mcpu=v8 -O2 -g)
 * The function computes `(param_1 & 0xff) * 2 + 4`, masks to a byte, and branches on whether it equals 10. The if-path makes two calls with hardcoded constants; the else path makes one call using the computed value. Both paths converge on a final call. The main uncertainty is whether the compiler will hoist common argument setup before the branch as the target does, but the structure (call order, branch shape, and constant values) should now match.
 */
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int);
extern void FUN_a00b32e4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

void FUN_a00a8bc0(unsigned int param_1)
{
    unsigned int t;
    
    t = (param_1 & 0xff) * 2 + 4;
    FUN_a00b3ed0(0, 0, 0, 0);
    t = t & 0xff;
    
    if (t == 10) {
        FUN_a00b32e4(0, 0, 0x792, 3, 10, 2, 0);
        FUN_a00b32e4(1, 0, 0x3092, 3, 0xc, 1, 0x11);
    } else {
        FUN_a00b32e4(0, 0, 0x792, 3, t, 3, 0);
    }
    
    FUN_a00b32e4(0, 0, 0x792, 0x12, t, 3, 0);
}
