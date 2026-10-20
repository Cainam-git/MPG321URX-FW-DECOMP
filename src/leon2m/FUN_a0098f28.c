/* leon2m FUN_a0098f28 @ 0xa0098f28-0xa009901c (61 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Calls FUN_a00a93bc(word 0xa802afec + 0x4f) and FUN_a00a813c(1, byte 0xa8025c56, 0). For 0xa802afec == 0xb1:
 * clears bit 6 of word 0xa802d338 (0xa802d290 + 0xa8), calls FUN_a00a9650(0, 0) and then FUN_a00a813c(1, bit 6, 1).
 * Otherwise sets bit 6, writes bit 0 of 0xa802afec into bit 5, calls FUN_a00a9650(bit 5 + 1, 0) and
 * FUN_a00a813c(1, bit 5 + 1, 1). Then FUN_a00d9978, FUN_a00d99a8, 0xa802afec = 0x2d, FUN_a00a900c(3, 1) and bit 1
 * (0x02) of byte 0xa802b08e is set. The bits are 1-bit bit-fields.
 */
struct R290 { unsigned char pad[0xa8]; unsigned int hi : 25, b6 : 1, b5 : 1, lo : 5; };
extern struct R290 DAT_a802d290;
extern unsigned int DAT_a802afec;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802b08e;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00d9978(void);
extern void FUN_a00d99a8(void);
extern void FUN_a00a900c(unsigned char, int);

void FUN_a0098f28(void)
{
    FUN_a00a93bc(DAT_a802afec + 0x4f);
    FUN_a00a813c(1, DAT_a8025c56, 0);
    if (DAT_a802afec == 0xb1) {
        DAT_a802d290.b6 = 0;
        FUN_a00a9650(0, 0);
        FUN_a00a813c(1, DAT_a802d290.b6, 1);
    } else {
        DAT_a802d290.b6 = 1;
        DAT_a802d290.b5 = DAT_a802afec;
        FUN_a00a9650(DAT_a802d290.b5 + 1, 0);
        FUN_a00a813c(1, DAT_a802d290.b5 + 1, 1);
    }
    FUN_a00d9978();
    FUN_a00d99a8();
    DAT_a802afec = 0x2d;
    FUN_a00a900c(3, 1);
    DAT_a802b08e |= 2;
}
