/* leon2m FUN_a009906c @ 0xa009906c (-mcpu=v8 -O3 -g)
 * v = bit 15 of word 0xA802D338 (0xA802D290 + 0xa8): byte 0xA8025C56 = v; FUN_a00a813c(1, v, 0);
 * FUN_a00a900c((word 0xA802AFEC - 42) & 0xff, 2); then with v read again: word 0xA802AFEC = v + 0xb4,
 * FUN_a00a9650(v, 1) and byte 0xA802B08E |= 2.
 * Source form: the record is a structure with bit 15 of +0xa8 as a 1-bit bit-field.
 */
struct R290 { unsigned char pad[0xa8]; unsigned int hi : 16, b15 : 1, lo : 15; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a009906c(void)
{
    DAT_a8025c56 = DAT_a802d290.b15;
    FUN_a00a813c(1, DAT_a802d290.b15, 0);
    FUN_a00a900c(_DAT_a802afec - 42, 2);
    _DAT_a802afec = DAT_a802d290.b15 + 0xb4;
    FUN_a00a9650(DAT_a802d290.b15, 1);
    DAT_a802b08e |= 2;
}
