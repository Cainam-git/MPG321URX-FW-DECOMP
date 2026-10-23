/* FLT_no_retrain (leon2s 0xa009c9b4-0xa009cb34, 384 bytes), flags -mcpu=v8 -Os -g.
 * For ports i = 0, 1 with ARR_a8079110[i] != 0: when FUN_a00a7468(0x14, 0, 0x1f0c) returns 0 and
 * FUN_a00a7408(0x11, word +0x18 of the 0x34-byte record ARR_a807db00[i] + 0x90) is not 0 while the state word of
 * the 0x18-byte record DAT_a807d650[i] is above 1, byte +0x35 of the 0xb0-byte record ARR_a807d680[i] is set
 * to 1 (printing "FLT_no_retrain\n" with FUN_a00734c4 when it was 0) and the port is skipped; otherwise that
 * byte is cleared when a second FUN_a00a7408 call returns 0. Then MODEDET_handler(i) runs and the state
 * function DAT_a00b4258[state](i) is called again while it returns a non-zero byte. Finally the period word of
 * the descriptor DAT_a80790f4 is set to DAT_a8078631 and it is passed to CONV2HDMITX_UpdateInterface_4.
 */
struct eq_state {
    unsigned int st;
    unsigned char cnt;
    unsigned char _5[0x18 - 5];
};
struct Port34 { unsigned char pad[0x18]; unsigned int w18; unsigned char rest[0x34 - 0x1c]; };
struct TimerDesc { unsigned int periodic; unsigned int period; void (*fn)(void); };
extern struct eq_state DAT_a807d650[];
extern struct Port34 ARR_a807db00[];
extern unsigned char ARR_a8079110[];
extern unsigned char ARR_a807d680[][0xb0];
extern unsigned char (*const DAT_a00b4258[])(unsigned char);
extern struct TimerDesc DAT_a80790f4;
extern unsigned char DAT_a8078631;
extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);
extern unsigned int FUN_a00a7408(unsigned int, unsigned int);
extern unsigned int FUN_a00734c4(const char *);
extern void MODEDET_handler(unsigned char);
extern void CONV2HDMITX_UpdateInterface_4(struct TimerDesc *);

void FLT_no_retrain(void)
{
    unsigned char i;

    for (i = 0; i < 2; i++) {
        if (ARR_a8079110[i] == 0)
            continue;
        if (FUN_a00a7468(0x14, 0, 0x1f0c) == 0) {
            if (FUN_a00a7408(0x11, ARR_a807db00[i].w18 + 0x90) && DAT_a807d650[i].st > 1) {
                if (ARR_a807d680[i][0x35] == 0) {
                    ARR_a807d680[i][0x35] = 1;
                    FUN_a00734c4("FLT_no_retrain\n");
                }
                continue;
            }
            if (FUN_a00a7408(0x11, ARR_a807db00[i].w18 + 0x90) == 0)
                ARR_a807d680[i][0x35] = 0;
        }
        MODEDET_handler(i);
        while (DAT_a00b4258[DAT_a807d650[i].st](i))
            ;
    }
    DAT_a80790f4.period = DAT_a8078631;
    CONV2HDMITX_UpdateInterface_4(&DAT_a80790f4);
}
