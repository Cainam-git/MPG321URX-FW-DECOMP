/* leon2m FUN_a00935e8 @ 0xa00935e8 (-mcpu=v8 -O3 -g)
 * Bit 12 of word 0xA802D338 (0xA802D290 + 0xa8) = bit 0 of byte 0xA8025C56; FUN_a00a93bc((word 0xA802AFEC - 0x53) & 0xff);
 * with b = that bit (read again before each use): FUN_a00a9650(b + 1, 0), FUN_a00a813c(1, b + 1, 0) and
 * FUN_a00a813c(1, b + 1, 1); word 0xA802AFEC = 0x11; FUN_a00a900c(3, 1) (tail call).
 * Source form: the record is a structure with bit 12 of +0xa8 as a 1-bit bit-field (its base stays in a register).
 */
struct R290 { unsigned char pad[0xa8]; unsigned int hi : 19, b12 : 1, lo : 12; };
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c56;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);

void FUN_a00935e8(void)
{
    DAT_a802d290.b12 = DAT_a8025c56;
    FUN_a00a93bc(_DAT_a802afec - 0x53);
    FUN_a00a9650(DAT_a802d290.b12 + 1, 0);
    FUN_a00a813c(1, DAT_a802d290.b12 + 1, 0);
    FUN_a00a813c(1, DAT_a802d290.b12 + 1, 1);
    _DAT_a802afec = 0x11;
    FUN_a00a900c(3, 1);
}
