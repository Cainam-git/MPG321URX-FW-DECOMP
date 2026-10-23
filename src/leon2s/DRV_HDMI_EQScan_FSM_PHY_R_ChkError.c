/* leon2s DRV_HDMI_EQScan_FSM_PHY_R_ChkError @ 0xa0077f04-0xa00787f4 (2288 bytes), flags -mcpu=v8 -Os -g.
 * u8 port; returns 0 while counting, else 1. Uses the 0x898-byte port record ARR_a807a9f0[port] (pre[3] at +3,
 * rvga[3] at +9, per-channel state words at +0x10, rows [4][3] at +0x1c, flags at +0x2a and +0x2d, counter at
 * +0x30, word table [rvga][pre][ch] at +0x80) and the per-port byte pairs DAT_a807899c / DAT_a80789a8.
 * With the counter 0 it prints DAT_a0067428 (port letter, name) and calls DRV_HDMI_PHY_Clr_EQ_Err(port) when
 * DAT_a80761a0[port] > 1; the counter is incremented and the function returns 0 while it is below
 * DAT_a80761a0[port]. Then it prints DAT_a0067450 (port letter, name, counter), reads the per-channel SCDC
 * status and value (as DRV_HDMI_EQScan_FSM_PHY_ChkError) for the channels whose +0x2d flag is not 1, prints
 * them (s_a0067478) and stores value & 0x7fff in the table cell of the channel's rvga/pre indexes when pre is
 * within the limit (pre_ok; print s_a00674c0). A second pass steps pre per channel by the state word: values
 * below 0x10 record pre in row[state] and set pre to the state's start value (4/6, 5/7, 9/13, 10/14 by byte 8)
 * and advance the state while pre_ok; larger values count DAT_a807899c / DAT_a80789a8 (state 2 and 3 set pre
 * to 10/14 when the second count passes the first) and move pre down (states 1 and 3, ending at row 0 / row 2)
 * or up (states 0 and 2, ending at 5/7 with state 2); each channel prints s_a0067500. Finally word 0 of
 * ARR_a807ccc4[port] = 7.
 * Source form: the counter is the 4th argument of the "(Done %u-th)" print; the status uses '?:' so the array
 * address forms first; the limit test is the inlined helper pre_ok with an unsigned limit (its argument is read
 * before the byte-8 test); cases in ascending order; the state word is addressed through a pointer taken
 * between the two flag tests; store orders as in the firmware.
 */
struct Rec12 { unsigned int w0; unsigned char b4[4]; unsigned char b8; unsigned char pad[3]; };
struct EqPort {
    unsigned char _0[3];
    unsigned char pre[3];
    unsigned char _6[3];
    unsigned char rvga[3];
    unsigned char _c[4];
    unsigned int state[3];
    unsigned char row[4][3];
    unsigned char _28[2];
    unsigned char fa[3];
    unsigned char done[3];
    unsigned char cnt;
    unsigned char _31[0x4f];
    unsigned int tbl[3][14][3];
    unsigned char _rest[0x898 - 0x80 - 3 * 14 * 3 * 4];
};
extern struct EqPort ARR_a807a9f0[];
extern struct Rec12 ARR_a807ccc4[];
extern unsigned int _DAT_a8078634;
extern unsigned char DAT_a80761a0[];
extern unsigned char DAT_a807899c[][3];
extern unsigned char DAT_a80789a8[][3];
extern unsigned char DAT_a0067428[], DAT_a0067450[];
extern char s_a0067478[], s_a00674c0[], s_a0067500[];
extern int FUN_a0073044(const void *, ...);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);

/* 1 when v is within the PreAEQ limit: 9 when byte 8 of ARR_a807ccc4[port] is set, else 13. */
static inline int pre_ok(unsigned char port, unsigned char v)
{
    return v <= (ARR_a807ccc4[port].b8 ? 9u : 0xdu);
}

int DRV_HDMI_EQScan_FSM_PHY_R_ChkError(unsigned char port)
{
    unsigned int st[3] = {0};
    unsigned int ced[3] = {0};
    unsigned char ch;
    unsigned char pre;
    unsigned char rv;
    unsigned int val;
    unsigned int *sp;

    if (ARR_a807a9f0[port].cnt == 0) {
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(DAT_a0067428, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_R_ChkError");
    }
    if (ARR_a807a9f0[port].cnt == 0 && DAT_a80761a0[port] > 1)
        DRV_HDMI_PHY_Clr_EQ_Err(port);
    if (++ARR_a807a9f0[port].cnt < DAT_a80761a0[port])
        return 0;
    if ((_DAT_a8078634 & 2) != 0)
        FUN_a0073044(DAT_a0067450, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_R_ChkError",
                     ARR_a807a9f0[port].cnt);
    for (ch = 0; ch < 3; ch++) {
        if (ARR_a807a9f0[port].done[ch] == 1)
            continue;
        if (ch == 0) {
            st[ch] = FUN_a00a7468(0, port, 0x1ea0) == 0 ? FUN_a00a7314(port, 0x1e94) >> 24 : 0;
            ced[ch] = (FUN_a00a7314(port, 0x1ea0) & 0xff00) | ((FUN_a00a7314(port, 0x1ea0) >> 16) & 0xff);
        } else if (ch == 1) {
            st[ch] = FUN_a00a7468(1, port, 0x1ea0) == 0 ? FUN_a00a7314(port, 0x1e98) & 0xff : 0;
            ced[ch] = ((FUN_a00a7314(port, 0x1ea0) & 0xff000000) >> 16) | (FUN_a00a7314(port, 0x1ea4) & 0xff);
        } else {
            st[ch] = FUN_a00a7468(2, port, 0x1ea0) == 0 ? (FUN_a00a7314(port, 0x1e98) >> 8) & 0xff : 0;
            ced[ch] = (FUN_a00a7314(port, 0x1ea4) & 0xff00) | ((FUN_a00a7314(port, 0x1ea4) >> 16) & 0xff);
        }
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a0067478, (char)(port + 'A'), ch, ch, ced[ch] & 0x7fff,
                         FUN_a00a7314(port, 0x1ea0) & 0xff);
        if (pre_ok(port, ARR_a807a9f0[port].pre[ch])) {
            pre = ARR_a807a9f0[port].pre[ch];
            rv = ARR_a807a9f0[port].rvga[ch];
            val = ced[ch] & 0x7fff;
            ARR_a807a9f0[port].tbl[rv][pre][ch] = val;
            if ((_DAT_a8078634 & 2) != 0)
                FUN_a0073044(s_a00674c0, (char)(port + 'A'), ch, rv, pre, ch, val);
        }
    }
    for (ch = 0; ch < 3; ch++) {
        if (ARR_a807a9f0[port].done[ch] == 1)
            continue;
        sp = &ARR_a807a9f0[port].state[ch];
        if (ARR_a807a9f0[port].fa[ch] != 0)
            continue;
        if (!pre_ok(port, ARR_a807a9f0[port].pre[ch]))
            continue;
        if (ARR_a807a9f0[port].pre[ch] == 0) {
            DAT_a807899c[port][ch] = 0;
            DAT_a80789a8[port][ch] = 0;
        }
        if ((ced[ch] & 0x7fff) < 0x10) {
            ARR_a807a9f0[port].row[*sp][ch] = ARR_a807a9f0[port].pre[ch];
            switch (*sp) {
            case 0:
                ARR_a807a9f0[port].pre[ch] = ARR_a807ccc4[port].b8 ? 4 : 6;
                break;
            case 1:
                ARR_a807a9f0[port].pre[ch] = ARR_a807ccc4[port].b8 ? 5 : 7;
                break;
            case 2:
                ARR_a807a9f0[port].pre[ch] = ARR_a807ccc4[port].b8 ? 9 : 0xd;
                break;
            case 3:
                ARR_a807a9f0[port].pre[ch] = ARR_a807ccc4[port].b8 ? 10 : 0xe;
                break;
            }
            if (pre_ok(port, ARR_a807a9f0[port].pre[ch]))
                *sp = *sp + 1;
        } else {
            if (*sp - 2 < 2) {
                if (++DAT_a80789a8[port][ch] > DAT_a807899c[port][ch])
                    ARR_a807a9f0[port].pre[ch] = ARR_a807ccc4[port].b8 ? 10 : 0xe;
            } else {
                DAT_a807899c[port][ch]++;
            }
            if (pre_ok(port, ARR_a807a9f0[port].pre[ch])) {
                switch (*sp) {
                case 0:
                case 2:
                    if (++ARR_a807a9f0[port].pre[ch] == (ARR_a807ccc4[port].b8 ? 5 : 7))
                        *sp = 2;
                    break;
                case 1:
                    if (--ARR_a807a9f0[port].pre[ch] == ARR_a807a9f0[port].row[0][ch]) {
                        *sp = 2;
                        ARR_a807a9f0[port].pre[ch] = ARR_a807ccc4[port].b8 ? 5 : 7;
                        ARR_a807a9f0[port].row[1][ch] = ARR_a807a9f0[port].row[0][ch];
                    }
                    break;
                case 3:
                    if (--ARR_a807a9f0[port].pre[ch] == ARR_a807a9f0[port].row[2][ch]) {
                        ARR_a807a9f0[port].pre[ch] = ARR_a807ccc4[port].b8 ? 10 : 0xe;
                        ARR_a807a9f0[port].row[3][ch] = ARR_a807a9f0[port].row[2][ch];
                    }
                    break;
                }
            }
        }
        if ((_DAT_a8078634 & 2) != 0)
            FUN_a0073044(s_a0067500, (char)(port + 'A'), ch, ARR_a807a9f0[port].pre[ch]);
    }
    ARR_a807ccc4[port].w0 = 7;
    return 1;
}
