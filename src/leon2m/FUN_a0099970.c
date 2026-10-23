/* leon2m FUN_a0099970 @ 0xa0099970 (-mcpu=v8 -O3 -g)
 * FUN_a00a93bc((word 0xA802AFEC - 68) & 0xff); with b = byte 0xA802D2DA (0xA802D290 + 0x4a, read again before each use):
 * FUN_a00a9650((b + 2) & 0xff, 0), FUN_a00a813c(1, (b + 2) & 0xff, 0) and FUN_a00a813c(1, (b + 2) & 0xff, 1);
 * word 0xA802AFEC = 13; FUN_a00a900c(2, 1) (tail call).
 * Source form: the byte is a member of the record structure at 0xA802D290 (its base stays in a register).
 */
struct R290 { unsigned char pad[0x4a]; unsigned char b4a; };
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0099970(void)
{
    FUN_a00a93bc(_DAT_a802afec - 68);
    FUN_a00a9650(DAT_a802d290.b4a + 2, 0);
    FUN_a00a813c(1, DAT_a802d290.b4a + 2, 0);
    FUN_a00a813c(1, DAT_a802d290.b4a + 2, 1);
    _DAT_a802afec = 13;
    FUN_a00a900c(2, 1);
}
