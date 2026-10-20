/* DRV_HDMI_DbgHDMITaskCtrl (leon2s 0xa00a3250-0xa00a32d0, 128 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a00734c4(s_a00b4cc0), then reads byte 3 (sel) and byte 7 (on) of the argument block. sel 0: FUN_a0073540(0) when on, else FUN_a00735c0(0).
 * sel 1: DRV_HDMI_Start_Timer(1) when on, else DRV_HDMI_Del_Timer(1). Returns 0. Both bytes are read into
 * locals before the tests (the firmware loads byte 7 once).
 */
extern char s_a00b4cc0[];
extern int FUN_a00734c4(const char *);
extern void FUN_a0073540(unsigned char);
extern void FUN_a00735c0(unsigned char);
extern void DRV_HDMI_Start_Timer(unsigned char);
extern void DRV_HDMI_Del_Timer(unsigned char);

int DRV_HDMI_DbgHDMITaskCtrl(unsigned char *arg)
{
    unsigned char sel, on;

    FUN_a00734c4(s_a00b4cc0);
    sel = arg[3];
    on = arg[7];
    if (sel == 0) {
        if (on != 0)
            FUN_a0073540(0);
        else
            FUN_a00735c0(0);
    } else if (sel == 1) {
        if (on != 0)
            DRV_HDMI_Start_Timer(1);
        else
            DRV_HDMI_Del_Timer(1);
    }
    return 0;
}
