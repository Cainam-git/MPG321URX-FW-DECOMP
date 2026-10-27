/* FUN_a0099f20 (leon2m 0xa0099f20-0xa009a018, 248 bytes), flags -mcpu=v8 -O3 -g.
 * Clears (DAT_a802afec = 0xbb) or sets (0xbc) bit 15 of the word at DAT_a802d290 + 0x1dc; calls
 * FUN_a00a93bc(DAT_a8025c56 + 0x45) and FUN_a00a813c(1, DAT_a8025c56, 0); stores 0x37 to DAT_a802afec; calls
 * FUN_a00a9650(bit 15, 0), FUN_a00a813c(1, bit 15, 1), FUN_a00a900c(DAT_a802afec - 52, 1), FUN_a00a9468(1, 2),
 * FUN_a00b34d4(0, 1) and FUN_a00dab20(); sets bit 1 of the byte DAT_a802b08e.
 */
struct G290 { unsigned char p0[0x1dc]; unsigned int w1dc; };
extern struct G290 DAT_a802d290;
extern unsigned int DAT_a802afec;
extern unsigned char DAT_a8025c56, DAT_a802b08e;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(unsigned char mode, unsigned char sel, unsigned char on);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9468(unsigned char sel, unsigned char mode);
extern void FUN_a00b34d4(unsigned char hi, unsigned char lo);
extern void FUN_a00dab20(void);

void FUN_a0099f20(void)
{
    if (DAT_a802afec == 0xbb)
        DAT_a802d290.w1dc &= ~0x8000u;
    else if (DAT_a802afec == 0xbc)
        DAT_a802d290.w1dc |= 0x8000;
    FUN_a00a93bc(DAT_a8025c56 + 0x45);
    FUN_a00a813c(1, DAT_a8025c56, 0);
    DAT_a802afec = 0x37;
    FUN_a00a9650((DAT_a802d290.w1dc >> 15) & 1, 0);
    FUN_a00a813c(1, (DAT_a802d290.w1dc >> 15) & 1, 1);
    FUN_a00a900c(DAT_a802afec - 52, 1);
    FUN_a00a9468(1, 2);
    FUN_a00b34d4(0, 1);
    FUN_a00dab20();
    DAT_a802b08e |= 2;
}
