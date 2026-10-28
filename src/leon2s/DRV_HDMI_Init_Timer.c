/* DRV_HDMI_Init_Timer (leon2s 0xa009c188-0xa009c284, 252 bytes), flags -mcpu=v8 -Os -g.
 * When bit 2 of DAT_a8078634 is set, calls FUN_a0073044(s_a006a630, s_a00b4438, type) (format string starting
 * "[MODEDET]" with a %s and a %d field, and the function name "DRV_HDMI_Init_Timer"). Then by type fills the
 * 3-word descriptors and passes them to CONV2HDMITX_UpdateInterface_3: type 1: DAT_a80790f4 = {0, DAT_a8079038,
 * FLT_no_retrain}; 0x14: DAT_a8079100 = {0, DAT_a8079038, FUN_a009a41c}; 0x15: both (0xa80790f4 first). Other
 * types do nothing.
 * Source form: cases in ascending order, 0x15 repeats both descriptor blocks; each block stores the flag word,
 * the function pointer and then the period.
 */
struct TimerDesc { unsigned int periodic; unsigned int period; void (*fn)(void); };
extern struct TimerDesc DAT_a80790f4, DAT_a8079100;
extern unsigned char DAT_a8079038;
extern unsigned int DAT_a8078634;
extern char s_a006a630[], s_a00b4438[];
extern int FUN_a0073044(const char *, ...);
extern void CONV2HDMITX_UpdateInterface_3(struct TimerDesc *);
extern void FLT_no_retrain(void);
extern void FUN_a009a41c(void);

void DRV_HDMI_Init_Timer(unsigned int type)
{
    if (DAT_a8078634 & 4)
        FUN_a0073044(s_a006a630, s_a00b4438, type);
    switch (type) {
    case 1:
        DAT_a80790f4.periodic = 0;
        DAT_a80790f4.fn = FLT_no_retrain;
        DAT_a80790f4.period = DAT_a8079038;
        CONV2HDMITX_UpdateInterface_3(&DAT_a80790f4);
        break;
    case 0x14:
        DAT_a8079100.periodic = 0;
        DAT_a8079100.fn = FUN_a009a41c;
        DAT_a8079100.period = DAT_a8079038;
        CONV2HDMITX_UpdateInterface_3(&DAT_a8079100);
        break;
    case 0x15:
        DAT_a80790f4.periodic = 0;
        DAT_a80790f4.fn = FLT_no_retrain;
        DAT_a80790f4.period = DAT_a8079038;
        CONV2HDMITX_UpdateInterface_3(&DAT_a80790f4);
        DAT_a8079100.periodic = 0;
        DAT_a8079100.fn = FUN_a009a41c;
        DAT_a8079100.period = DAT_a8079038;
        CONV2HDMITX_UpdateInterface_3(&DAT_a8079100);
        break;
    }
}
