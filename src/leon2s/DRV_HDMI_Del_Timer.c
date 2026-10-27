/* DRV_HDMI_Del_Timer (leon2s 0xa009c284-0xa009c310, 140 bytes), flags -mcpu=v8 -Os -g.
 * When bit 2 of DAT_a8078634 is set, calls FUN_a0073044(s_a006a630, s_a00b4450, type) (the format string
 * "[MODEDET] %s Start, type = %d" and the function name "DRV_HDMI_Del_Timer"). Then by type: 1 passes the
 * descriptor DAT_a80790f4 to FUN_a00b222c; 0x14 passes DAT_a8079100; 0x15 does both (0xa80790f4 first).
 * Other types do nothing. Counterpart of DRV_HDMI_Start_Timer (same switch). The range ends with the
 * unreachable ret/restore pair of the -g epilogue after the final tail call.
 */
struct TimerDesc { unsigned int periodic; unsigned int period; void (*fn)(void); };
extern struct TimerDesc DAT_a80790f4, DAT_a8079100;
extern unsigned char DAT_a8078630, DAT_a8078631;
extern unsigned int DAT_a8078634;
extern char s_a006a630[], s_a00b4450[];
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00b222c(struct TimerDesc *);

void DRV_HDMI_Del_Timer(unsigned int type)
{
    if (DAT_a8078634 & 4)
        FUN_a0073044(s_a006a630, s_a00b4450, type);
    switch (type) {
    case 1:
        FUN_a00b222c(&DAT_a80790f4);
        break;
    case 0x15:
        FUN_a00b222c(&DAT_a80790f4);
        /* fall through */
    case 0x14:
        FUN_a00b222c(&DAT_a8079100);
        break;
    }
}
