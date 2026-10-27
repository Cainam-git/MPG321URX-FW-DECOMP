/* leon2s FUN_a009d2f8 @ 0xa009d2f8-0xa009d5cc, -mcpu=v8 -Os -g.
 * int (port), returns 0. p = low byte of port. FUN_a00980a8(p). When byte +0x18 of the 0x190-byte record
 * DAT_a807d7e0[p] is 1: unless FUN_a009facc(p) returns 0x82, byte +9 of the 0x18-byte record DAT_a807d650[p]
 * counts down to 0; when FUN_a00a03c8(p) differs from byte +0x2d of the record, prints "HDMI 21 DSC Port%c
 * modechange" and sets byte +0xa of DAT_a807d650[p]; FUN_a00974ec(p). When byte +7 of the record differs from
 * DAT_a8079050[p]: a 1 -> 0 change sets word 0 of DAT_a807d650[p] to 7; DAT_a8079050[p] takes the new value.
 * FUN_a00a1150(port); H_ACTIVE_DIFF(port) == 1 clears word 0 of DAT_a807d650[port]. When byte +6 of the record
 * is 0 and FUN_a00a03c8(port) is set: the first time (DAT_a80790b8[port] == 0) the frame count f = word 0x98 of
 * the register block ARR_a807db00[port].r0 is stored in DAT_a80790e4[port] and f / 333 in DAT_a80790ec[port];
 * when |DAT_a80790e4 - count| exceeds DAT_a80790ec, both are refreshed from a new count, FUN_a009c87c(port),
 * word 0 of DAT_a807d650[port] = 0 and "dsc mode changed, frame cnt diff > %ld" is printed. FUN_a00a93e4(port).
 * Source forms: the second count read uses its own local; DAT_a80790ec is declared unsigned long (alias set);
 * the later callees are declared with unsigned int parameters (the firmware passes the masked port as is).
 */
struct port_rec { volatile unsigned int *r0; unsigned char _4[0x30]; };
struct mode_rec {
    unsigned char _00[6];
    unsigned char f06;
    unsigned char f07;
    unsigned char _08[0x10];
    unsigned char f18;
    unsigned char _19[0x2d - 0x19];
    unsigned char f2d;
    unsigned char _2e[0x190 - 0x2e];
};
struct st_rec { unsigned int st; unsigned char _4[5]; unsigned char f9; unsigned char fa; unsigned char _b[0x18 - 0xb]; };
extern struct port_rec ARR_a807db00[];
extern struct mode_rec DAT_a807d7e0[];
extern struct st_rec DAT_a807d650[];
extern unsigned char DAT_a8079050[];
extern unsigned char DAT_a80790b8[];
extern unsigned int DAT_a80790e4[];
extern unsigned long DAT_a80790ec[];
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00980a8(unsigned char);
extern int FUN_a009facc(unsigned char);
extern unsigned char FUN_a00a03c8(unsigned int);
extern void FUN_a00974ec(unsigned char);
extern void FUN_a00a1150(unsigned int);
extern unsigned char H_ACTIVE_DIFF(unsigned int);
extern void FUN_a009c87c(unsigned int);
extern void FUN_a00a93e4(unsigned int);

int FUN_a009d2f8(unsigned int port)
{
    unsigned char p = port;
    unsigned int f, g;
    int d, t;

    FUN_a00980a8(p);
    if (DAT_a807d7e0[p].f18 == 1) {
        if (FUN_a009facc(p) != 0x82) {
            if (DAT_a807d650[p].f9 != 0)
                DAT_a807d650[p].f9--;
        }
        if (FUN_a00a03c8(p) != DAT_a807d7e0[p].f2d) {
            FUN_a0073044("HDMI 21 DSC Port%c modechange\r\n", (char)(port + 'A'));
            DAT_a807d650[p].fa = 1;
        }
        FUN_a00974ec(p);
    }
    if (DAT_a807d7e0[port & 0xff].f07 != DAT_a8079050[port & 0xff]) {
        if (DAT_a8079050[port & 0xff] == 1 && DAT_a807d7e0[port & 0xff].f07 == 0)
            DAT_a807d650[port & 0xff].st = 7;
        DAT_a8079050[port & 0xff] = DAT_a807d7e0[port & 0xff].f07;
    }
    port &= 0xff;
    FUN_a00a1150(port);
    if (H_ACTIVE_DIFF(port) == 1)
        DAT_a807d650[port].st = 0;
    if (DAT_a807d7e0[port].f06 == 0 && FUN_a00a03c8(port)) {
        if (DAT_a80790b8[port] == 0) {
            f = ARR_a807db00[port].r0[0x98 / 4];
            DAT_a80790e4[port] = f;
            DAT_a80790ec[port] = f / 333;
            DAT_a80790b8[port] = 1;
        }
        d = DAT_a80790e4[port] - ARR_a807db00[port].r0[0x98 / 4];
        if ((unsigned int)__builtin_abs(d) > DAT_a80790ec[port]) {
            g = ARR_a807db00[port].r0[0x98 / 4];
            DAT_a80790ec[port] = g / 333;
            DAT_a80790e4[port] = g;
            FUN_a009c87c(port);
            DAT_a807d650[port].st = 0;
            FUN_a0073044("dsc mode changed, frame cnt diff > %ld\r\n", DAT_a80790ec[port]);
        }
    }
    FUN_a00a93e4(port);
    return 0;
}
