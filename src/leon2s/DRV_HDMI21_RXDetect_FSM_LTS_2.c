/* DRV_HDMI21_RXDetect_FSM_LTS_2 (leon2s, 0xa0098330-0xa00983ec, 47 words). Flags -mcpu=v8 -Os -g.
 * Code facts: u8 port. rec = 0xb0-byte record port of DAT_a807d680; if the state word DAT_a807d648[port] !=
 * rec word +0x30: if bit 0x800 of _DAT_a8078634, print s_a0069c10 '[HDMI21]: =%s, Port ID = %d=' with
 * s_a00b42b8 (the function name) and port; then rec +0x30 = state.
 * FUN_a00a73ac(0x16, word +0x18 of the 0x34-byte record port of DAT_a807db00 + 0xa0);
 * state = (FUN_a0098300(port) & 0xff) ? 7 : 3; returns 0.
 * The print takes 3 arguments (fmt, name string, port). Source form: records addressed through two separate
 * local pointers (one shared rec pointer or inline indexing reorders the smul/add). Aids: none.
 */
extern unsigned int _DAT_a8078634;
extern unsigned int DAT_a807d648[];
extern unsigned char DAT_a807d680[];
extern unsigned char DAT_a807db00[];
extern char s_a0069c10[], s_a00b42b8[];
extern int FUN_a0073044(const char *, ...);
extern int FUN_a0098300(unsigned int);
extern void FUN_a00a73ac(unsigned int, int);

unsigned int DRV_HDMI21_RXDetect_FSM_LTS_2(unsigned char param_1)
{
    unsigned int *rec;
    unsigned int *tx;

    rec = (unsigned int *)(DAT_a807d680 + param_1 * 0xb0);
    if (DAT_a807d648[param_1] != rec[0xc]) {
        if (_DAT_a8078634 & 0x800) {
            FUN_a0073044(s_a0069c10, s_a00b42b8, param_1);
        }
        rec[0xc] = DAT_a807d648[param_1];
    }

    tx = (unsigned int *)(DAT_a807db00 + param_1 * 0x34);
    FUN_a00a73ac(0x16, tx[6] + 0xa0);
    if (FUN_a0098300(param_1) & 0xff) {
        DAT_a807d648[param_1] = 7;
    } else {
        DAT_a807d648[param_1] = 3;
    }
    return 0;
}
