/* FUN_a00932a8 (leon2m 0xa00932a8-0xa0093334, 140 bytes), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a00a93bc(b) and FUN_a00a813c(1, b, 0) with b the byte DAT_a8025c56, FUN_a00a9650(DAT_a802afec - 0x48,
 * 0) and FUN_a00a813c(1, byte 0x182 of DAT_a802d290, 1); stores 0xe to DAT_a802afec, calls FUN_a00a900c(0, 1),
 * clears bit 11 of the word at DAT_a802d290 + 0xa8, calls FUN_a00acc40() and sets bit 1 of the byte DAT_a802b08e.
 */
struct G290 { unsigned char p0[0xa8]; unsigned int wa8; unsigned char pac[0x182 - 0xac]; unsigned char b182; };
extern struct G290 DAT_a802d290;
extern unsigned char DAT_a8025c56, DAT_a802b08e;
extern unsigned int DAT_a802afec;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(unsigned char mode, unsigned char sel, unsigned char on);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00acc40(void);

void FUN_a00932a8(void)
{
    FUN_a00a93bc(DAT_a8025c56);
    FUN_a00a813c(1, DAT_a8025c56, 0);
    FUN_a00a9650(DAT_a802afec - 0x48, 0);
    FUN_a00a813c(1, DAT_a802d290.b182, 1);
    DAT_a802afec = 0xe;
    FUN_a00a900c(0, 1);
    DAT_a802d290.wa8 &= ~0x800u;
    FUN_a00acc40();
    DAT_a802b08e |= 2;
}
