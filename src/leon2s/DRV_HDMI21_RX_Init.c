/* leon2s DRV_HDMI21_RX_Init @ 0xa00a1cdc-0xa00a1df0 (69 words), flags -mcpu=v8 -Os -g.
 * Code facts: one-time init guarded by byte DAT_a8079192 (set to 1 at the end). If bit 0 of _DAT_a8078634:
 * print s_a006b860 with 999. DRV_HDMI_IF_Init(); for i = 0, 1: DRV_HDMI_IF_Disconnect(i), FUN_a00a1b58(i);
 * for j = 0, 1: FUN_a00a1c74(j, 1); for i = 0, 1: FUN_a00a7488(FUN_a008f4d0(i), 0x2e70, 0xffffffff, 0xf00)
 * and FUN_a00a73ac(0xb / 9 / 10, cfg + 8 bytes) with cfg = word +0x18 of the 0x34-byte record
 * DAT_a807db00[i] (re-read for each call). void.
 * Fixes vs the autoc draft (76.81, did not compile): the third loop was missing (a7488 / 73ac run per port,
 * indexed by the loop counter); the print string is a symbol; 'i = 0' at the declaration (fw 'clr %l1' in
 * the first branch delay slot) and the middle loop has its own counter j (fw %l0). Aids: none.
 */
struct port_regs {
    unsigned int unk0[6];
    unsigned int *cfg;
    unsigned char _1c[0x34 - 0x1c];
};
extern struct port_regs DAT_a807db00[];
extern unsigned char DAT_a8079192;
extern unsigned int _DAT_a8078634;
extern char s_a006b860[];
extern void DRV_HDMI_IF_Init(void);
extern void DRV_HDMI_IF_Disconnect(unsigned char);
extern void FUN_a00a1b58(unsigned char);
extern void FUN_a00a1c74(unsigned char, unsigned char);
extern void FUN_a00a73ac(unsigned int, int);
extern void FUN_a00a7488(unsigned char, unsigned int, unsigned int, unsigned int);
extern unsigned int FUN_a008f4d0(unsigned char);
extern int FUN_a0073044(const char *, ...);

void DRV_HDMI21_RX_Init(void)
{
    unsigned char i = 0;
    unsigned char j;

    if (DAT_a8079192 == 0) {
        if (_DAT_a8078634 & 1)
            FUN_a0073044(s_a006b860, 999);
        DRV_HDMI_IF_Init();
        for (; i < 2; i++) {
            DRV_HDMI_IF_Disconnect(i);
            FUN_a00a1b58(i);
        }
        for (j = 0; j < 2; j++)
            FUN_a00a1c74(j, 1);
        for (i = 0; i < 2; i++) {
            FUN_a00a7488(FUN_a008f4d0(i), 0x2e70, 0xffffffff, 0xf00);
            FUN_a00a73ac(0xb, (int)DAT_a807db00[i].cfg + 8);
            FUN_a00a73ac(9, (int)DAT_a807db00[i].cfg + 8);
            FUN_a00a73ac(10, (int)DAT_a807db00[i].cfg + 8);
        }
        DAT_a8079192 = 1;
    }
}
