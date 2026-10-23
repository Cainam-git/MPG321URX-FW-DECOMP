/* leon2s FUN_a00a4524 @ 0xa00a4524 (-mcpu=v8 -Os -g)
 * k = p1. When word k of the array 0xA807DB6C differs from word k of the array 0xA807873C: prints
 * "ESC[1;33m[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_L" with p1 through FUN_a0073044, copies
 * the word into 0xA807873C, calls FUN_a0091cf4(k, 0x31, 0) and, when bit 5 of FUN_a0091d64(k, 0x10) is set,
 * FUN_a0091cf4(k, 0x10, 0x20). Then stores 2 in word k of 0xA807DB6C when the low byte of FUN_a0091960(k) is 1,
 * clears byte 0xA80791AA and returns 0.
 */
extern unsigned char DAT_a80791aa;
extern int FUN_a0073044(const char *, ...);
extern unsigned int FUN_a0091960(unsigned int);
extern void FUN_a0091cf4(unsigned int, unsigned int, unsigned int);
extern unsigned char FUN_a0091d64(unsigned int, unsigned int);
extern unsigned int ARR_a807873c[];
extern unsigned int ARR_a807db6c[];

unsigned int FUN_a00a4524(unsigned char param_1) {
    unsigned int uVar1;
    unsigned int idx;

    param_1 &= 0xff;
    idx = param_1;

    if (ARR_a807db6c[idx] != ARR_a807873c[idx]) {
        FUN_a0073044("\x1b[1;33m[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_L\n\n\x1b[0m", param_1);
        ARR_a807873c[idx] = ARR_a807db6c[idx];
        FUN_a0091cf4(param_1, 0x31, 0);
        uVar1 = FUN_a0091d64(param_1, 0x10);
        if (uVar1 & 0x20) {
            FUN_a0091cf4(param_1, 0x10, 0x20);
        }
    }

    uVar1 = FUN_a0091960(param_1);
    if ((uVar1 & 0xff) == 1) {
        ARR_a807db6c[param_1] = 2;
    }

    DAT_a80791aa = 0;
    return 0;
}
