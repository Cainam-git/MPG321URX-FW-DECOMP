/* DRV_HDMI_Start_Timer (leon2s 0xa009c310-0xa009c3bc, 172 bytes), flags -mcpu=v8 -Os -g.
 * When bit 2 of DAT_a8078634 is set, calls FUN_a0073044(s_a006a630, s_a00b4468, type) (a format
 * string starting "[MODEDET]" with a %s and a %d field, and the function name "DRV_HDMI_Start_Timer"). Then by type: 1 sets word 1 of the
 * 3-word descriptor DAT_a80790f4 to the byte DAT_a8078631 and passes it to CONV2HDMITX_UpdateInterface_4; 0x14
 * does the same with DAT_a8079100 and DAT_a8078630; 0x15 does both (0xa80790f4 first). Other types do nothing.
 */
struct TimerDesc { unsigned int periodic; unsigned int period; void (*fn)(void); };
extern struct TimerDesc DAT_a80790f4, DAT_a8079100;
extern unsigned char DAT_a8078630, DAT_a8078631;
extern unsigned int DAT_a8078634;
extern char s_a006a630[], s_a00b4468[];
extern int FUN_a0073044(const char *, ...);
extern void CONV2HDMITX_UpdateInterface_4(struct TimerDesc *);

void DRV_HDMI_Start_Timer(unsigned int type)
{
    if (DAT_a8078634 & 4)
        FUN_a0073044(s_a006a630, s_a00b4468, type);
    switch (type) {
    case 1:
        DAT_a80790f4.period = DAT_a8078631;
        CONV2HDMITX_UpdateInterface_4(&DAT_a80790f4);
        break;
    case 0x15:
        DAT_a80790f4.period = DAT_a8078631;
        CONV2HDMITX_UpdateInterface_4(&DAT_a80790f4);
        /* fall through */
    case 0x14:
        DAT_a8079100.period = DAT_a8078630;
        CONV2HDMITX_UpdateInterface_4(&DAT_a8079100);
        break;
    }
}
