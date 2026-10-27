/* leon2m FUN_a00b789c @ 0xa00b789c-0xa00b7944 (42 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00af44c.
 * Calls FUN_a0146b50(0x111, 0) and FUN_a0146b6c(0, 0); then for i = 0 and 1: FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1,
 * FUN_a00a3844(word table 0x19336c, i * 29 + byte 0xa802d298), 0). Ends with a tail call FUN_a00a813c(1, bit 15 of
 * the word 0xa802d338 (DAT_a802d290 + 0xa8), 1). The loop has the same form as the one in FUN_a00ab3d8.
 */
struct R290 { unsigned char pad[8]; unsigned char b08; unsigned char pad09[0x9f]; unsigned int wa8; };
extern struct R290 DAT_a802d290;
extern unsigned int DAT_0019336c[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a00b789c(void)
{
    unsigned char i;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    for (i = 0; i <= 1; i++)
        FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_0019336c, i * 29 + DAT_a802d290.b08), 0);
    FUN_a00a813c(1, (DAT_a802d290.wa8 >> 15) & 1, 1);
}
