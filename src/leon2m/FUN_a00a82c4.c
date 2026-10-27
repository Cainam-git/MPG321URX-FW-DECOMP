/* FUN_a00a82c4 (leon2m 0xa00a82c4-0xa00a835c, 152 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Calls FUN_a0146b50(0x111, 0) and FUN_a0146b6c(0, 0), then for i = 0..3 calls FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1,
 * FUN_a00a3844(DAT_0018f984, i * 29 + b + 29), 0) with b = byte 8 of DAT_a802d290. Called by FUN_a0094438,
 * FUN_a00956a0, FUN_a0095704, FUN_a0095984, FUN_a0095a20. Source form: the same loop is inlined in FUN_a00af44c
 * (same flags, -msoft-float).
 */
struct R290 { unsigned char p000[8]; unsigned char b008; };
extern struct R290 DAT_a802d290;
extern unsigned int DAT_0018f984[];
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, int, unsigned int, int, unsigned int, int);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(unsigned char c, unsigned char v);

void FUN_a00a82c4(void)
{
    unsigned char i;

    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    for (i = 0; i <= 3; i++)
        FUN_a00a31a4(0, 0x2a, i * 2 + 6, 1, FUN_a00a3844(DAT_0018f984, i * 29 + DAT_a802d290.b008 + 29), 0);
}
