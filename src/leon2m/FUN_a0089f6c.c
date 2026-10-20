/* leon2m FUN_a0089f6c @ 0xa0089f6c-0xa008a034 (50 words), flags -mcpu=v8 -O3 -g.
 * Code facts: builds a 10-byte message on the stack {0x6e, 0x88, 2, 0, 0xe6, 0, 0, 1, 0, f} where
 * f = bit 7 of the word DAT_a802d290 + 0xa8 (ld, btst 0x80); the byte DAT_a802af9e = 0x50, then
 * af9e ^= buf[i] for i = 0..9 (loop.c load_mems keeps af9e in a register and writes it back after
 * the loop); buf[10] = af9e; FUN_a01486a8(FUN_a014e478(d290[0x1e]), 0xb, buf). void, no params.
 * FUN_a01486a8 takes 3 arguments (it forwards %o2 to FUN_a0133b54); FUN_a014e478 takes d290[0x1e]; the base is
 * the symbol DAT_a802d290.
 * Source form: the f == 0 arm first, and a local buffer pointer p (fw keeps &buf in %l0 across the calls).
 * Compiler aid: u8 local bound n = 10 (code-free; tree fold turns 'i < 10' into 'cmp 9; bleu', the fw has
 * 'cmp 0xa; bcs'; same class as FUN_a00aaf48 'n = 7').
 */
struct Rec290 {
    unsigned char pad[0x1e];
    unsigned char b1e;
    unsigned char pad2[0xa8 - 0x1f];
    unsigned int w0a8;
};
extern struct Rec290 DAT_a802d290;
extern unsigned char DAT_a802af9e;
extern void FUN_a01486a8(unsigned char, unsigned short, unsigned char *);
extern int FUN_a014e478(unsigned int);

void FUN_a0089f6c(void)
{
    unsigned char buf[40];
    unsigned char i;
    unsigned char n;
    unsigned char *p;
    int f;

    buf[0] = 0x6e;
    buf[1] = 0x88;
    buf[2] = 2;
    buf[4] = 0xe6;
    f = (DAT_a802d290.w0a8 & 0x80) != 0;
    buf[3] = 0;
    buf[5] = 0;
    buf[6] = 0;
    buf[7] = 1;
    buf[8] = 0;
    if (!f)
        buf[9] = 0;
    else
        buf[9] = 1;
    DAT_a802af9e = 0x50;
    p = buf;
    n = 10;
    for (i = 0; i < n; i++)
        DAT_a802af9e = p[i] ^ DAT_a802af9e;
    p[i] = DAT_a802af9e;
    FUN_a01486a8(FUN_a014e478(DAT_a802d290.b1e), 0xb, p);
}
