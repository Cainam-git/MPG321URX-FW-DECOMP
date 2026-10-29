/* leon2m FUN_a00b72cc @ 0xa00b72cc-0xa00b7474 (106 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00b7474.
 * Calls FUN_a0146b50(0xd7, 0) and FUN_a0146b6c(2, 0); then for i = 0..2: with b = byte 0xa802d298 (DAT_a802d290 + 8),
 * FUN_a00a31a4(0, 0x28, i * 2 + 6, 1, FUN_a00a3844(word table 0x197d08, i * 29 + b), 0), wrapped in
 * FUN_a0146b6c(0, 0) / FUN_a0146b6c(2, 0) when b == 0x13, or when b == 0xd and i is 0 or 2; then, with
 * row = i * 2 + 6, FUN_a0146a80(0x2b, row, 1, 0x792, 0), FUN_a0146b20(0, 0x2b, row, 1, 0x3f, 0),
 * FUN_a0146a80(0x32, row, 1, 0x792, 0), FUN_a0146b20(0, 0x32, row, 1, 0x40, 0). Ends with FUN_a0146b6c(0, 0).
 * Source form: the two wrapped cases are separate if arms with identical bodies (merged by the compiler);
 * one '||' over both tests gives a different block layout. Compiler aids: none.
 */
struct R290 { unsigned char pad[8]; unsigned char b08; };
extern struct R290 DAT_a802d290;
extern unsigned int DAT_00197d08[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

void FUN_a00b72cc(void)
{
    unsigned char i;
    unsigned int row;

    FUN_a0146b50(0xd7, 0);
    FUN_a0146b6c(2, 0);
    for (i = 0; i <= 2; i++) {
        if (DAT_a802d290.b08 == 0x13) {
            FUN_a0146b6c(0, 0);
            FUN_a00a31a4(0, 0x28, i * 2 + 6, 1, FUN_a00a3844(DAT_00197d08, i * 29 + DAT_a802d290.b08), 0);
            FUN_a0146b6c(2, 0);
        } else if ((i == 0 || i == 2) && DAT_a802d290.b08 == 0xd) {
            FUN_a0146b6c(0, 0);
            FUN_a00a31a4(0, 0x28, i * 2 + 6, 1, FUN_a00a3844(DAT_00197d08, i * 29 + DAT_a802d290.b08), 0);
            FUN_a0146b6c(2, 0);
        } else
            FUN_a00a31a4(0, 0x28, i * 2 + 6, 1, FUN_a00a3844(DAT_00197d08, i * 29 + DAT_a802d290.b08), 0);
        row = i * 2 + 6;
        FUN_a0146a80(0x2b, row, 1, 0x792, 0);
        FUN_a0146b20(0, 0x2b, row, 1, 0x3f, 0);
        FUN_a0146a80(0x32, row, 1, 0x792, 0);
        FUN_a0146b20(0, 0x32, row, 1, 0x40, 0);
    }
    FUN_a0146b6c(0, 0);
}
