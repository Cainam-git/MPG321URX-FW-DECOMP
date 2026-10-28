/* leon2m FUN_a00bb560 @ 0xa00bb560..0xa00bb86c (780 bytes): reads bytes of one port into the buffer 0xA802D040 and
 * returns a frame class (2, 4, 8, 0x10). Same layout as FUN_a00baef8 (buffer 0xA802D0D0, timer 0xf) with timer 0x10,
 * count byte DAT_a802b09a and flag byte DAT_a802b099. Caller: FUN_a00bbabc.
 *   n = 0; FUN_a01487cc(port, 0x30 - count, &buf[count], &n) appends at most 0x30 - count bytes (n = bytes read).
 *   n == 0, timer 0x10 expired (FUN_a0086a3c(0x10) == 0) and flag == 1 -> flag = 0, return 0x10.
 *   count += n; count > 0x2f -> count = 0.
 *   First byte neither '5' nor 0 and timer expired -> flag = 1, FUN_a00869b0(0x10, 0x32).
 *   First byte != '5' or fewer than 6 bytes -> return 8. Timer expired -> flag = 1, FUN_a00869b0(0x10, 0xfa).
 *   Expected frame length k: byte1 '8' -> 7; 'b' -> 10 (and when bytes 4, 5 are ';', '4': bit 10 of the halfword
 *   0xA802CFF4 + 0x18 is set when byte 9 is '1', else cleared); '6' -> 5; other: 0.
 *   count <= (k & 0xf) -> 8; buf[k & 0xf] != '\r' -> 0x10; else flag = 0 and return 2 ('8'), 4 ('b'); bytes 2..4
 *   "00+" or "00-" -> count = 0, the 0x32 buffer bytes cleared, return 8; otherwise 0x10.
 * Source form: the two "00+" / "00-" tests are separate ifs with their own clear loops (the firmware re-reads
 * byte 2 for the second test).
 */
extern void FUN_a01487cc(unsigned char, unsigned short, unsigned char *, unsigned short *);
extern unsigned short FUN_a0086a3c(int);
extern void FUN_a00869b0(int, int);

struct Rcff4 { unsigned char pad[0x18]; unsigned short h18; };
extern struct Rcff4 DAT_a802cff4;
extern unsigned char DAT_a802b09a, DAT_a802b099;
extern unsigned char DAT_a802d040[];

unsigned char FUN_a00bb560(unsigned char port)
{
    unsigned short n = 0;
    unsigned int k = 0;
    unsigned char i;

    FUN_a01487cc(port, 0x30 - DAT_a802b09a, &DAT_a802d040[DAT_a802b09a], &n);
    if (n == 0 && FUN_a0086a3c(0x10) == 0 && DAT_a802b099 == 1) {
        DAT_a802b099 = 0;
        return 0x10;
    }
    DAT_a802b09a += n;
    if (DAT_a802b09a > 0x2f)
        DAT_a802b09a = 0;
    if (DAT_a802d040[0] != '5' && DAT_a802d040[0] != 0 && FUN_a0086a3c(0x10) == 0) {
        DAT_a802b099 = 1;
        FUN_a00869b0(0x10, 0x32);
    }
    if (DAT_a802d040[0] != '5' || DAT_a802b09a < 6)
        return 8;
    if (FUN_a0086a3c(0x10) == 0) {
        DAT_a802b099 = 1;
        FUN_a00869b0(0x10, 0xfa);
    }
    if (DAT_a802d040[1] == '8')
        k = 7;
    else if (DAT_a802d040[1] == 'b') {
        k = 10;
        if (DAT_a802d040[4] == ';' && DAT_a802d040[5] == '4') {
            if (DAT_a802d040[9] == '1')
                DAT_a802cff4.h18 |= 0x400;
            else
                DAT_a802cff4.h18 &= ~0x400;
        }
    } else if (DAT_a802d040[1] == '6')
        k = 5;
    if (DAT_a802b09a <= (k & 0xf))
        return 8;
    if (DAT_a802d040[k & 0xf] != '\r')
        return 0x10;
    DAT_a802b099 = 0;
    if (DAT_a802d040[1] == '8')
        return 2;
    if (DAT_a802d040[1] == 'b')
        return 4;
    if (DAT_a802d040[2] == '0' && DAT_a802d040[3] == '0' && DAT_a802d040[4] == '+') {
        DAT_a802b09a = 0;
        for (i = 0; i < 0x32; i++)
            DAT_a802d040[i] = 0;
        return 8;
    }
    if (DAT_a802d040[2] == '0' && DAT_a802d040[3] == '0' && DAT_a802d040[4] == '-') {
        DAT_a802b09a = 0;
        for (i = 0; i < 0x32; i++)
            DAT_a802d040[i] = 0;
        return 8;
    }
    return 0x10;
}
