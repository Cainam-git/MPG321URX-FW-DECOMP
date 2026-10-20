/* leon2m FUN_a00ab340 @ 0xa00ab340  OSD/menu table loop (hand;
 * BYTE-EXACT at -mcpu=v8 -O3 -g -msoft-float).
 *
 * FUN_a00a8c88(); FUN_a0146b50(0x111, 0); FUN_a0146b6c(0, 0); then for i = 0..4:
 * FUN_a00a31a4(0, 0x2A, i * 2 + 6, 1, FUN_a00a3844(table 0x18E9F8, (u16)(i * 29 + state byte 0xA802D298)), 0).
 * BYTE-EXACT keys: 0xA802D298 read as field +8 of the state block 0xA802D290; the index i * 29 (not 36).
 */
struct St { unsigned char pad[8]; unsigned char b08; };
extern struct St DAT_a802d290;
extern unsigned int DAT_0018e9f8[];
extern void FUN_a00a8c88(void);
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);

void FUN_a00ab340(void)
{
    unsigned char i;

    FUN_a00a8c88();
    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    i = 0;
    do {
        FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_0018e9f8, (unsigned short)(i * 29 + DAT_a802d290.b08)), 0);
        i++;
    } while (i <= 4);
}
