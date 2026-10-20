/* leon2s FUN_a00a4524 @ 0xa00a4524  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Finished from mechanical Ghidra C. HDMI TX FRL training, link-training-state
 * step for port param_1: when the port entry of 0xa807db6c differs from its copy in 0xa807873c
 * it logs the state change, copies it, writes 0 to register 0x31 and, if bit 5 of register
 * 0x10 is set, writes 0x20 to register 0x10. Then if FUN_a0091960(port) reports 1 the state
 * becomes 2. The log string is the real one from
 * the firmware.
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
