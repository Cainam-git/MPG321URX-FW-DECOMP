/* DRV_HDMI_EQScan_FSM_Search_EQTable (leon2s 0xa0078dc8-0xa0078fe8, 544 bytes), flags -mcpu=v8 -Os -g.
 * Under bit 1 of _DAT_a8078634 prints the entry message with 'A' + port, the function name and byte +0x30 (st)
 * of the 0x898-byte record DAT_a807a9f0[port]. st - 1 <= 4: word 0 of ARR_a807ccc4[port] = 10, return 0.
 * done[0..2] (bytes +0x31..+0x33) all 1: word 0 = 0x10, byte +0x896 = 0, return 1. idx[0..2] (bytes +0..+2) all
 * <= 0x17: for each ch 0..2 with done[ch] != 1 prints ch and idx[ch] (bit 1), FUN_a0074ef4(port, ch, idx[ch]),
 * idx[ch]++; then st = 0, DRV_HDMI_PHY_Clr_EQ_Err(port), word 0 = 0xb, return 0. Otherwise word 0 = 0, prints
 * the "Back to EQSCAN_PHY_INIT" message (bit 1) and returns 1.
 * Source form: unsigned char parameter (every use extends it again, so the record offset port * 0x898 is
 *   recomputed in each block), record fields addressed as DAT_a807a9f0[port] in each statement;
 *   _DAT_a8078634 is declared unsigned long (as in DRV_HDMI_EQScan_FSM_PHY_PLL: the alias set orders its last
 *   load after the ARR_a807ccc4 index computation).
 */
struct eq_rec {
    unsigned char idx[3];
    unsigned char _03[0x30 - 3];
    unsigned char st;
    unsigned char done[3];
    unsigned char _34[0x896 - 0x34];
    unsigned char b896;
    unsigned char _897;
};
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct eq_rec DAT_a807a9f0[];
extern struct Rec12 ARR_a807ccc4[];
extern unsigned long _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern void FUN_a0074ef4(unsigned int, unsigned int, unsigned char);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);
static const char fn_[] = "DRV_HDMI_EQScan_FSM_Search_EQTable";

int DRV_HDMI_EQScan_FSM_Search_EQTable(unsigned char port)
{
    struct eq_rec *r;
    unsigned char ch;

    if (_DAT_a8078634 & 2)
        FUN_a0073044("[EQ]: \x1b[1mPort%c %s: (%u-th)\x1b[m", (char)(port + 0x41), fn_,
                     DAT_a807a9f0[port].st);
    if ((unsigned char)(DAT_a807a9f0[port].st - 1) <= 4) {
        ARR_a807ccc4[port].w0 = 10;
        return 0;
    }
    if (DAT_a807a9f0[port].done[0] == 1 && DAT_a807a9f0[port].done[1] == 1 && DAT_a807a9f0[port].done[2] == 1) {
        ARR_a807ccc4[port].w0 = 0x10;
        DAT_a807a9f0[port].b896 = 0;
        return 1;
    }
    if (DAT_a807a9f0[port].idx[0] <= 0x17 && DAT_a807a9f0[port].idx[1] <= 0x17 && DAT_a807a9f0[port].idx[2] <= 0x17) {
        for (ch = 0; ch < 3; ch++) {
            if (DAT_a807a9f0[port].done[ch] != 1) {
                if (_DAT_a8078634 & 2)
                    FUN_a0073044("[EQ]: # Port%c (CH%u) eqtable index = %u\n", (char)(port + 0x41), ch,
                                 DAT_a807a9f0[port].idx[ch]);
                FUN_a0074ef4(port, ch, DAT_a807a9f0[port].idx[ch]);
                DAT_a807a9f0[port].idx[ch]++;
            }
        }
        DAT_a807a9f0[port].st = 0;
        DRV_HDMI_PHY_Clr_EQ_Err(port);
        ARR_a807ccc4[port].w0 = 0xb;
        return 0;
    }
    ARR_a807ccc4[port].w0 = 0;
    if (_DAT_a8078634 & 2)
        FUN_a0073044("[EQ]: Port%c Back to EQSCAN_PHY_INIT", (char)(port + 0x41));
    return 1;
}
