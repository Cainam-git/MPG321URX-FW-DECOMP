/* leon2m FUN_a00adc98 @ 0xa00adc98  MATCH (-mcpu=v8 -O2 -g)
 * This function is structurally identical to the already-matched `FUN_a00ae288`, except the final field update uses `(value + 1) % 3` instead of `(value + 2) % 3`. The target assembly confirms this: `add %o4, 1, %o0` before the modulo-by-3 multiply sequence. Everything else — the initial `m = (field * 2 + 4) & 0xff`, the `if (m == 10)` branch with its two calls versus the else branch with one call, the common third call, then the modulo and the `FUN_a00ad86c` call with the result and `1`, and the final `DAT_a802b08e |= 2` — matches the known-good pattern exactly.
 */
struct St {
    unsigned char pad[0x17c];
    unsigned char b17c;
};
extern struct St DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a00ad86c(unsigned char, unsigned char);
extern void FUN_a00b32e4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int);

void FUN_a00adc98(void)
{
    unsigned char m;
    
    m = (DAT_a802d290.b17c * 2 + 4) & 0xff;
    FUN_a00b3ed0(0, 0, 0, 0);
    
    if (m == 10) {
        FUN_a00b32e4(0, 0, 0x792, 3, 10, 2, 0);
        FUN_a00b32e4(1, 0, 0x3092, 3, 0xc, 1, 0x11);
    } else {
        FUN_a00b32e4(0, 0, 0x792, 3, m, 3, 0);
    }
    
    FUN_a00b32e4(0, 0, 0x792, 0x12, m, 3, 0);
    
    DAT_a802d290.b17c = (DAT_a802d290.b17c + 1) % 3;
    FUN_a00ad86c(DAT_a802d290.b17c, 1);
    DAT_a802b08e = DAT_a802b08e | 2;
}
