/* FUN_a009a41c (leon2s 0xa009a41c-0xa009a580, 356 bytes), flags -mcpu=v8 -Os -g.
 * When FUN_a00a7468(0x14, 0, 0x1f0c) returns 0, for ports i = 0, 1 with ARR_a8079110[i] != 0: j =
 * FUN_a00961e8(i); when byte +6 of the 0x18-byte record ARR_a807cc64[j] is 0, the state word DAT_a807d648[i]
 * is cleared unless it is 1; when FUN_a008d800() <= 0x82 and ARR_a80790d0[i] is 1, the state is set to 3,
 * ARR_a80790d0[i], DAT_a80790d8[i] and byte +2 of the 0xb0-byte record ARR_a807d680[i] are cleared. Then the
 * state function DAT_a00b4230[state](i) is called again while it returns a non-zero byte. Finally the period
 * word of the timer descriptor DAT_a8079100 is set to DAT_a8078630 and it is passed to
 * CONV2HDMITX_UpdateInterface_4 (sibling call).
 */
struct sel_rec {
    unsigned char b[6];
    unsigned char b6;
    unsigned char _7[0x18 - 7];
};
struct TimerDesc { unsigned int periodic; unsigned int period; void (*fn)(void); };
extern struct sel_rec ARR_a807cc64[];
extern unsigned int DAT_a807d648[];
extern unsigned char ARR_a8079110[];
extern unsigned char ARR_a80790d0[];
extern unsigned char DAT_a80790d8[];
extern unsigned char ARR_a807d680[][0xb0];
extern unsigned char (*const DAT_a00b4230[])(unsigned char);
extern struct TimerDesc DAT_a8079100;
extern unsigned char DAT_a8078630;
extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);
extern unsigned char FUN_a00961e8(unsigned char);
extern unsigned char FUN_a008d800(void);
extern void CONV2HDMITX_UpdateInterface_4(struct TimerDesc *);

void FUN_a009a41c(void)
{
    unsigned char i;
    unsigned char j;

    if (FUN_a00a7468(0x14, 0, 0x1f0c) == 0) {
        for (i = 0; i < 2; i++) {
            if (ARR_a8079110[i] == 0)
                continue;
            j = FUN_a00961e8(i);
            if (ARR_a807cc64[j].b6 == 0 && DAT_a807d648[i] != 1)
                DAT_a807d648[i] = 0;
            if (FUN_a008d800() <= 0x82 && ARR_a80790d0[i] == 1) {
                DAT_a807d648[i] = 3;
                ARR_a80790d0[i] = 0;
                DAT_a80790d8[i] = 0;
                ARR_a807d680[i][2] = 0;
            }
            while (DAT_a00b4230[DAT_a807d648[i]](i))
                ;
        }
    }
    DAT_a8079100.period = DAT_a8078630;
    CONV2HDMITX_UpdateInterface_4(&DAT_a8079100);
}
