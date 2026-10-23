/* leon2m FUN_a0096e14 @ 0xa0096e14 (-mcpu=v8 -O3 -g)
 * Bits 18-19 of word 0xA802D33C (0xA802D290 + 0xac) = bits 0-1 of byte 0xA8025C56; FUN_a00a93bc((word 0xA802AFEC - 0x77)
 * & 0xff); with v = those bits (read again before each use): FUN_a00a9650(v, 0) and FUN_a00a813c(1, v, 1);
 * word 0xA802AFEC = 0x1d; FUN_a00a900c(5, 1) (tail call). Store counterpart of FUN_a0096c80.
 * Source form: the record is a structure with bits 18-19 of +0xac as a 2-bit bit-field.
 */
struct R290 { unsigned char pad[0xac]; unsigned int hi : 12, f : 2, lo : 18; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0096e14(void)
{
    DAT_a802d290.f = DAT_a8025c56;
    FUN_a00a93bc(_DAT_a802afec - 0x77);
    FUN_a00a9650(DAT_a802d290.f, 0);
    FUN_a00a813c(1, DAT_a802d290.f, 1);
    _DAT_a802afec = 0x1d;
    FUN_a00a900c(5, 1);
}
