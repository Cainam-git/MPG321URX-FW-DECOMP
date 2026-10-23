/* leon2m FUN_a0096c80 @ 0xa0096c80 (-mcpu=v8 -O3 -g)
 * v = bits 18-19 of word 0xA802D33C (0xA802D290 + 0xac): byte 0xA8025C56 = v; FUN_a00a813c(1, v, 0);
 * FUN_a00a900c((word 0xA802AFEC - 0x18) & 0xff, 2); then with v read again: word 0xA802AFEC = v + 0x77 and
 * FUN_a00a9650(v, 1) (tail call).
 * Source form: the record is a structure with bits 18-19 of +0xac as a 2-bit bit-field.
 */
struct R290 { unsigned char pad[0xac]; unsigned int hi : 12, f : 2, lo : 18; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0096c80(void)
{
    DAT_a8025c56 = DAT_a802d290.f;
    FUN_a00a813c(1, DAT_a802d290.f, 0);
    FUN_a00a900c(_DAT_a802afec - 0x18, 2);
    _DAT_a802afec = DAT_a802d290.f + 0x77;
    FUN_a00a9650(DAT_a802d290.f, 1);
}
