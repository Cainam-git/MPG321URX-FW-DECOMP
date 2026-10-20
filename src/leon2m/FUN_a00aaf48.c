/* leon2m FUN_a00aaf48 @ 0xa00aaf48-0xa00ab080 (78 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a0146b50(0x111, 0); FUN_a0146b6c(0, 0); save byte DAT_a802b08f, set it to 0xe. Loop i = 0..6
 * (u8, 7 rounds): if FUN_a00aad30(i) returns 0 (low byte): FUN_a0146a80(0x2a, i*2+6, 10, 0x296, 0); then
 * FUN_a00a31a4(0, 0x2a, (u16)(i*2+6), 1, FUN_a00a3844(0x1910b0, (u16)(i*29 + byte DAT_a802d290[8])), 0) (the 5th
 * arg is a3844's return: mov %o0,%o4). After the loop v = byte DAT_a802d290[0x1a4]; x = v <= 6 ? v*2+6 : v*2-8
 * (u8); FUN_a0146b20(0, 0x28, x, 1, 0xf, 0); FUN_a0146b20(0, 0x29, x, 1, 0x10, 0); restore DAT_a802b08f. void.
 * Source form: the record base DAT_a802d290; arm order 'v <= 6' first. The loop bound is a u8 local 'n = 7': the
 * fw test is 'cmp 7; bcc' (GEU 7), which only survives when the constant reaches the compare at RTL level (a
 * literal 7 is folded to 'i <= 6' -> cmp 6).
 * Compiler aids: none (the local n generates no code).
 */
extern unsigned char DAT_a802b08f;
extern unsigned char DAT_a802d290[];
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);

void FUN_a00aaf48(void)
{
    unsigned char saved;
    unsigned char i;
    unsigned char v;
    unsigned char x;
    unsigned char n = 7;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    saved = DAT_a802b08f;
    DAT_a802b08f = 0xe;
    for (i = 0; i < n; i++) {
        if (FUN_a00aad30(i) == 0)
            FUN_a0146a80(0x2a, i * 2 + 6, 10, 0x296, 0);
        FUN_a00a31a4(0, 0x2a, (unsigned short)(i * 2 + 6), 1,
                     FUN_a00a3844((unsigned int *)0x1910b0, i * 29 + DAT_a802d290[8]), 0);
    }
    v = DAT_a802d290[0x1a4];
    if (v <= 6)
        x = v * 2 + 6;
    else
        x = v * 2 - 8;
    FUN_a0146b20(0, 0x28, x, 1, 0xf, 0);
    FUN_a0146b20(0, 0x29, x, 1, 0x10, 0);
    DAT_a802b08f = saved;
}
