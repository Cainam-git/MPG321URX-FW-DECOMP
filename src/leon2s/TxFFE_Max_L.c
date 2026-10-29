/* leon2s TxFFE_Max_L @ 0xa0098468-0xa009860c (-mcpu=v8 -Os -g)
 * port = arg & 0xff. Record rec = byte table 0xa807d680 + port * 0xb0, port record ARR_a807db00[port].
 * If rec[1] differs from bits 24..27 of word 0x90 of the port's register block (pointer at +0x18): prints
 * "[HDMI21]: LTP Time start" through FUN_a00734c4 when bit 11 of _DAT_a8078634 is set, stores FUN_a00b2064()
 * to DAT_a8079074[port], stores those bits to rec[1], calls FUN_a00a7488(port, 0x1f0c, 0xfffffff0, rec[1]),
 * stores bits 28..31 to rec[0x13] and clears rec[0x0f .. 0x0f + rec[0] - 1].
 * Then rec[0] = 0 for rec[1] == 0, 3 for rec[1] 1..2 and 4 otherwise; for rec[1] != 0 it calls
 * FUN_a00a73d4(8, wc + 0x60) and FUN_a00a73d4(9, wc + 0x60) with wc = word +0xc of the port record. When
 * bit 11 of _DAT_a8078634 is set, prints rec[1] and rec[0x13] with the format string through FUN_a0073044.
 * Source form: the first part is a static helper (inlined) that addresses the table through a constant
 * pointer (the firmware keeps the whole address in a register there) and reads rec[0] into an unsigned int
 * before the rec[0x13] store, then copies it to an unsigned short loop limit.
 */
struct Port34 {
    unsigned int w0;
    unsigned int w4;
    unsigned int w8;
    unsigned int wc;
    unsigned char pad10[8];
    volatile unsigned int *r18;
    unsigned char rest[0x34 - 0x1c];
};
extern struct Port34 ARR_a807db00[];
extern unsigned char ARR_a807d680[][0xb0];
extern unsigned int DAT_a8079074[];
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern unsigned int FUN_a00734c4(const char *);
extern unsigned int FUN_a00b2064(void);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00a73d4(unsigned int, unsigned int);

static void upd(unsigned char port)
{
    struct Port34 *t = ARR_a807db00;
    struct Port34 *p = t + port;
    unsigned char (*tab)[0xb0] = ((unsigned char (*)[0xb0])0xa807d680);
    unsigned char *rec = tab[port];
    unsigned char i;
    unsigned short n;
    unsigned int c;

    if (rec[1] != (p->r18[0x90 / 4] & 0x0f000000) >> 24) {
        if (_DAT_a8078634 & 0x800)
            FUN_a00734c4("[HDMI21]: LTP Time start\n");
        DAT_a8079074[port] = FUN_a00b2064();
        rec[1] = (p->r18[0x90 / 4] & 0x0f000000) >> 24;
        FUN_a00a7488(port, 0x1f0c, 0xfffffff0, rec[1]);
        c = tab[port][0];
        rec[0x13] = p->r18[0x90 / 4] >> 28;
        n = c;
        for (i = 0; i < n; i++)
            tab[port][0xf + i] = 0;
    }
}

void TxFFE_Max_L(unsigned int port)
{
    upd(port);
    if (ARR_a807d680[(unsigned char)port][1] == 0)
        ARR_a807d680[(unsigned char)port][0] = 0;
    else if ((unsigned char)(ARR_a807d680[(unsigned char)port][1] - 1) <= 1) {
        ARR_a807d680[(unsigned char)port][0] = 3;
        FUN_a00a73d4(8, ARR_a807db00[(unsigned char)port].wc + 0x60);
        FUN_a00a73d4(9, ARR_a807db00[(unsigned char)port].wc + 0x60);
    } else {
        ARR_a807d680[(unsigned char)port][0] = 4;
        FUN_a00a73d4(8, ARR_a807db00[(unsigned char)port].wc + 0x60);
        FUN_a00a73d4(9, ARR_a807db00[(unsigned char)port].wc + 0x60);
    }
    if (_DAT_a8078634 & 0x800)
        FUN_a0073044("[HDMI21]: Upadte FRL_Rate = %d, TxFFE_Max_L = %d\n", ARR_a807d680[(unsigned char)port][1], ARR_a807d680[(unsigned char)port][0x13]);
}
