/* leon2m FUN_a00bf110 @ 0xa00bf110..0xa00bf2c8 (440 bytes)  UartSetI2CEnable: the Big chip's entry into the official
 * USB/UART firmware update (rescue) path. -mcpu=v8 -O3 -g -msoft-float (also -mcpu=v8 -O3 -g).
 *
 * What the code does (code facts):
 * 1. Builds an 11-byte reply frame at 0xA802D078: bytes 7, 8, 9 = the hundreds, tens and ones digit ('0' + n) of the
 *    byte 0xA802D299; bytes 0 and 2..6 = bytes 0, 2..6 of row 2 of the UART command table (FUN_a015463c(2, i),
 *    row 2 = "580040:"), byte 1 = 'b', byte 10 = '\r'.
 * 2. Clears the receive state of the UART port it was called for: port 2 -> 0xA802B09A and bytes 0, 0x19, 1, 7, 10 of
 *    0xA802D040; port 3 -> 0xA802B098 and the same bytes of 0xA802D098; any other port -> 0xA802B09C and 0xA802D0D0.
 * 3. FUN_a01487e8(port, 11, frame): sends the frame back on that port (FUN_a01487e8 forwards to FUN_a01337e8; the
 *    frame pointer goes in %o2).
 * 4. Prints "--->UartSetI2CEnable" (string at 0x1982C8, debug printf FUN_a00df170).
 * 5. FUN_a0148794(0, 0x10, 0, 0) (first argument 0 -> FUN_a0133f24(0x10, 0, 0)).
 * 6. FUN_a0107bac(0, FUN_a0125124(byte 0xA802E14A), 0, 0): GPIO/pin-mux set-up of group 0, pin = byte +2 of the
 *    22-byte entry 0xA802E14A of the table at 0x1A42A8, output disabled.
 * 7. FUN_a0133f84(1) = func_0x4008f3f4(2, 1, 0, 0, 1) and func_0x4008f3f4(0xf, 1, 0, 0, 1);
 *    FUN_a0133e7c(1, 0x6E) = func_0x4008f3f4(7, 1, 0x6E, 0, 1) (tail call).
 * No loops, no waits, no hardware register access in this function itself; it always returns.
 *
 * Caller: only FUN_a00bfcc4 (the UART command switch), case at 0xA00C0A74: `and %i0,0xff,%i0; call FUN_a00bf110;
 *   restore` = tail call with the port byte.
 * Rescue path: for MSI's tool to reach the monitor, the Big chip must be running far enough to poll the UART
 *   command switch FUN_a00bfcc4; this function then needs only the UART send path, the GPIO set-up and the
 *   func_0x4008f3f4 (RAM-copy, = FUN_a002f3f4) I2C slave set-up. It reads no panel/timing state.
 *
 * key: the three digits computed into their own unsigned char locals first (h = v / 100; t = r / 10.
 *   o = r - t * 10) and stored afterwards; writing the digit expressions straight into the stores gives the same
 *   instructions with other registers (78.2 %).
 */
extern unsigned char DAT_a802d299, DAT_a802e14a;
extern unsigned char DAT_a802d078[11];
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern void FUN_a01487e8(unsigned char, int, unsigned char *);
extern int FUN_a00df170();
extern void FUN_a0148794(int, int, int, int);
extern unsigned char FUN_a0125124(unsigned char);
extern void FUN_a0107bac(int, unsigned char, int, int);
extern void FUN_a0133f84(int);
extern void FUN_a0133e7c(int, int);
extern char s_001982c8[];

void FUN_a00bf110(unsigned char port)
{
    {
        unsigned char v = DAT_a802d299, h, r, t, o;
        h = v / 100;
        r = v - h * 100;
        t = r / 10;
        o = r - t * 10;
        DAT_a802d078[7] = h + '0';
        DAT_a802d078[8] = t + '0';
        DAT_a802d078[9] = o + '0';
    }
    DAT_a802d078[0] = FUN_a015463c(2, 0);
    DAT_a802d078[1] = 'b';
    DAT_a802d078[2] = FUN_a015463c(2, 2);
    DAT_a802d078[3] = FUN_a015463c(2, 3);
    DAT_a802d078[4] = FUN_a015463c(2, 4);
    DAT_a802d078[5] = FUN_a015463c(2, 5);
    DAT_a802d078[6] = FUN_a015463c(2, 6);
    DAT_a802d078[10] = '\r';
    if (port == 2) {
        DAT_a802b09a = 0;
        DAT_a802d040[0] = 0;
        DAT_a802d040[1] = 0;
        DAT_a802d040[7] = 0;
        DAT_a802d040[10] = 0;
        DAT_a802d040[0x19] = 0;
    } else if (port == 3) {
        DAT_a802b098 = 0;
        DAT_a802d098[0] = 0;
        DAT_a802d098[1] = 0;
        DAT_a802d098[7] = 0;
        DAT_a802d098[10] = 0;
        DAT_a802d098[0x19] = 0;
    } else {
        DAT_a802b09c = 0;
        DAT_a802d0d0[0] = 0;
        DAT_a802d0d0[1] = 0;
        DAT_a802d0d0[7] = 0;
        DAT_a802d0d0[10] = 0;
        DAT_a802d0d0[0x19] = 0;
    }
    FUN_a01487e8(port, 0xb, DAT_a802d078);
    FUN_a00df170(s_001982c8);
    FUN_a0148794(0, 0x10, 0, 0);
    FUN_a0107bac(0, FUN_a0125124(DAT_a802e14a), 0, 0);
    FUN_a0133f84(1);
    FUN_a0133e7c(1, 0x6e);
}
