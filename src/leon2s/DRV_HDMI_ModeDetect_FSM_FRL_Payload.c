/* DRV_HDMI_ModeDetect_FSM_FRL_Payload (leon2s 0xa0096f60-0xa009723c, 732 bytes), flags -mcpu=v8 -Os -g.
 * int (port). Prints "Port%c DRV_HDMI_ModeDetect_FSM_FRL_Payload" with 'A' + port. Returns 0 after printing
 * s_a0069898 when FUN_a00a7408(0x11, r18 + 0x24 words) of the port record DAT_a807db00[port] is non-zero. When
 * DAT_a807d648[port] != 9, DAT_a807d650[port].st = 0 and "check stand by%d" is printed with 3. err = r18[0xd] &
 * 0x7fff is printed with r20[0xa] & 0xffff ("RS err=..., pkt=..."), DAT_a807909c[port] = FUN_a00967ec(port) and
 * r18[0xd] |= 0xffff. err > 0x3fff: DAT_a8079090[port] is incremented; above 0x13 it is cleared, the "Trigger FRL
 * Packets abnormal handling flow" line is printed when bit 2 of _DAT_a8078634 is set, DAT_a807d648[port] = 3,
 * st = 0, DAT_a807cc64[port].b1 = 0 and byte 2 of record ARR_a807d680 + port * 0xb0 is cleared; otherwise
 * st = 2. A DAT_a807909c[port] of 0 or above 0x7a4 sets st = 2. Otherwise, for d = DAT_a807909c[port] -
 * DAT_a8079094[port] (signed) within -29..29: FRL_PLL(port, DAT_a807909c[port]), r20[0x20] |= 7,
 * FUN_a00a73ac(8, r0 + 1), FUN_a00b1794(1), FUN_a00a73d4(8, r0 + 1), record bytes 0x3b and 0x3c cleared and
 * st = 3; then record byte 1 > 4, DAT_a807909c[port] <= 0x64 and (r18[5] & 0x7f) == 0x33 set
 * DAT_a8079040[port] = 1 and st = 0. Outside the range "FRL Preload_unstable" is printed when bit 2 of
 * _DAT_a8078634 is set. Finally DAT_a8079094[port] = DAT_a807909c[port]; returns 0.
 * Source form: FRL_PLL takes the value as its second parameter (it is already in %o1 at the call); the range test
 * is two nested ifs with the print in both else arms; the record pointer q is taken again in the in-range block.
 * volatile only on the hardware register pointers of the port record.
 */
struct port_rec {
    volatile unsigned int *r0;
    unsigned int _04[5];
    volatile unsigned int *r18;
    unsigned int _1c;
    volatile unsigned int *r20;
    unsigned char _24[0x34 - 0x24];
};
struct eq_state {
    unsigned int st;
    unsigned char cnt;
    unsigned char _5[0x18 - 5];
};
struct sel_rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char _2[0x18 - 2];
};
extern struct port_rec DAT_a807db00[];
extern unsigned int DAT_a807d648[];
extern struct eq_state DAT_a807d650[];
extern unsigned char ARR_a807d680[];
extern struct sel_rec DAT_a807cc64[];
extern unsigned int DAT_a807909c[];
extern unsigned int DAT_a8079094[];
extern unsigned char DAT_a8079090[];
extern unsigned char DAT_a8079040[];
extern unsigned int _DAT_a8078634;
extern const char s_a0069898[];
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned int FUN_a00a7408(unsigned int, volatile unsigned int *);
extern unsigned int FUN_a00967ec(unsigned char);
extern void FRL_PLL(unsigned int, unsigned int);
extern void FUN_a00a73ac(unsigned int, volatile unsigned int *);
extern void FUN_a00a73d4(unsigned int, volatile unsigned int *);
extern void FUN_a00b1794(unsigned short);

int DRV_HDMI_ModeDetect_FSM_FRL_Payload(unsigned int param_1)
{
    unsigned char port;
    unsigned char *rec;
    unsigned char *q;
    unsigned int err;
    int d;

    FUN_a0073044("Port%c DRV_HDMI_ModeDetect_FSM_FRL_Payload\n", (char)(param_1 + 'A'));
    port = param_1;
    if (FUN_a00a7408(0x11, DAT_a807db00[port].r18 + 0x24) != 0) {
        FUN_a00734c4(s_a0069898);
        return 0;
    }
    if (DAT_a807d648[port] != 9) {
        DAT_a807d650[port].st = 0;
        FUN_a0073044("check stand by%d\r\n", 3);
    }
    err = DAT_a807db00[port].r18[0xd] & 0x7fff;
    FUN_a0073044("RS err=0x%04X, pkt=0x%04X\n", err, DAT_a807db00[port].r20[0xa] & 0xffff);
    DAT_a807909c[port] = FUN_a00967ec(port);
    DAT_a807db00[port].r18[0xd] |= 0xffff;
    if (err > 0x3fff) {
        if (++DAT_a8079090[port] > 0x13) {
            DAT_a8079090[port] = 0;
            if (_DAT_a8078634 & 4)
                FUN_a00734c4("[MODEDET]: Trigger FRL Packets abnormal handling flow\n");
            rec = ARR_a807d680 + port * 0xb0;
            DAT_a807d648[port] = 3;
            DAT_a807d650[port].st = 0;
            DAT_a807cc64[port].b1 = 0;
            rec[2] = 0;
        } else
            DAT_a807d650[port].st = 2;
    } else if (DAT_a807909c[port] == 0 || DAT_a807909c[port] > 0x7a4) {
        DAT_a807d650[port].st = 2;
    } else {
        d = DAT_a807909c[port] - DAT_a8079094[port];
        if (d >= -29) {
            if (d <= 29) {
                FRL_PLL(port, DAT_a807909c[port]);
                DAT_a807db00[port].r20[0x20] |= 7;
                FUN_a00a73ac(8, DAT_a807db00[port].r0 + 1);
                FUN_a00b1794(1);
                FUN_a00a73d4(8, DAT_a807db00[port].r0 + 1);
                q = ARR_a807d680 + port * 0xb0;
                q[0x3b] = 0;
                DAT_a807d650[port].st = 3;
                q[0x3c] = 0;
                if (q[1] > 4 && DAT_a807909c[port] <= 0x64 && (DAT_a807db00[port].r18[5] & 0x7f) == 0x33) {
                    DAT_a8079040[port] = 1;
                    DAT_a807d650[port].st = 0;
                }
            } else {
                if (_DAT_a8078634 & 4)
                    FUN_a00734c4("[MODEDET]: FRL Preload_unstable\n");
            }
        } else {
            if (_DAT_a8078634 & 4)
                FUN_a00734c4("[MODEDET]: FRL Preload_unstable\n");
        }
    }
    DAT_a8079094[port] = DAT_a807909c[port];
    return 0;
}
