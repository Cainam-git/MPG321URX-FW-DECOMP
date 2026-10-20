/* leon2m FUN_a00b3ba0 @ 0xa00b3ba0  (-mcpu=v8 -O3 -g -msoft-float)
 * Calls FUN_a0146b50(0x92, 0) and FUN_a0146b6c(0, 0), then for i = 0..4 FUN_a00a31a4(0, 0x14, i * 2 + 6, 1,
 * FUN_a00a3844(table 0x196B24, index), 0) with index i for i = 0..3 and i + DAT_a802d290 byte +8 (16-bit) for i = 4.
 * Finally calls FUN_a00a9f30(4, bit 9 of the word at DAT_a802d290).
 * Callers: FUN_a00b0034+0x214.
 * Data: DAT_a802d290 is used as {u32 +0; u8 +8}.
 * Source form: the row-4 test is an if/else inside the loop with one call in each arm.
 */
struct R290 { unsigned int w000; unsigned char pad[4]; unsigned char b08; };
extern struct R290 DAT_a802d290;
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);
extern void FUN_a00a9f30(unsigned char, unsigned char);

void FUN_a00b3ba0(void)
{
    unsigned char i;

    FUN_a0146b50(0x92, 0);
    FUN_a0146b6c(0, 0);
    for (i = 0; i <= 4; i++) {
        if (i == 4)
            FUN_a00a31a4(0, 0x14, i * 2 + 6, 1, FUN_a00a3844((unsigned int *)0x196b24, i + DAT_a802d290.b08), 0);
        else
            FUN_a00a31a4(0, 0x14, i * 2 + 6, 1, FUN_a00a3844((unsigned int *)0x196b24, i), 0);
    }
    FUN_a00a9f30(4, (DAT_a802d290.w000 >> 9) & 1);
}
