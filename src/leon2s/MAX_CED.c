/* MAX_CED (leon2s 0xa009967c-0xa0099c18, 1436 bytes), flags -mcpu=v8 -Os -g.
 * Ports 0 and 1 only (value a = 2 / 3 for the calls below). Record DAT_a807d680[port] (0xb0 bytes): byte 0 = count n,
 * u16 h[4][10] at 0x3e, byte 0x8e = column index, 0x8f = sub-counter, 0x90 = sub-counter modulus,
 * 0x91 = wrap flag, bytes 0x92..0x95 = per-row flags (see FUN_a0099560 / FUN_a0099610).
 * For i < n: FUN_a00a7468(0xf / 0x1f, a, 0x2e64 / 0x2e68) != 0 keeps a flag (rows 0..3; for other rows the
 * flag of the previous row stays); with the flag set, the word from FUN_a00a7314(a, 0x2e64 / 0x2e68) gives
 * bits 14..0 (rows 0, 2) or bits 30..16 (rows 1, 3) as the row value, else the value is 0 and "Jex: CED non
 * valid, ERR" is printed. Second pass per row: value 0x7fff with row flag 0 calls FUN_a00a73ac(1, word 0xc of
 * DAT_a807db00[port] (0x34-byte records) + 0x60), sets the row flag and prints "MAX_CED[%d]". With sub-counter
 * 0 the value goes to h[i][column], the row is printed ("%04X "), and the entry is compared: with the wrap
 * flag set, h[i][column] < h[i][(column + 1) % 10] prints a message, calls FUN_a0099560(port) and returns;
 * a difference > 4 prints " Jex: ch%d CED error > 4 in 1s, Total=0x%04X " and calls FUN_a00a73ac as above;
 * without it, an entry > 4 does the same in the other order. Finally the column index advances (10 wraps to 0
 * and sets the wrap flag) when the sub-counter is 0, and the sub-counter becomes (c + 1) % modulus.
 * Prints depend on bit 13 of DAT_a8078634. Source forms: the port is an unsigned char local in the first part
 * and param_1 & 0xff in every later access; the column byte is read in each arm; one variable holds the entry
 * and then the difference; the 0/1 row value of FUN_a00a7314 is a bit-field view of its result.
 */
struct Rec {
    unsigned char n;
    unsigned char _01[0x3d];
    unsigned short h[4][10];
    unsigned char b8e, b8f, b90, b91;
    unsigned char a92[4];
    unsigned char _96[0xb0 - 0x96];
};
struct Rec34 {
    unsigned char _00[0xc];
    unsigned int p0c;
    unsigned char _10[0x34 - 0x10];
};
union Ced {
    unsigned int w;
    struct {
        unsigned int v1 : 1;
        unsigned int c1 : 15;
        unsigned int v0 : 1;
        unsigned int c0 : 15;
    } f;
};

extern struct Rec DAT_a807d680[];
extern struct Rec34 DAT_a807db00[];
extern unsigned int DAT_a8078634;
extern const char s_a006a038[], s_a006a060[], s_a006a080[], s_a006a090[], s_a006a0c0[], s_a006a0e8[];
extern const char s_a0069ee8[];

extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00a73ac(unsigned int, int);
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern void FUN_a0099560(unsigned int);

void MAX_CED(unsigned int param_1)
{
    unsigned short ced[4] = {0, 0, 0, 0};
    unsigned char ok = 0;
    unsigned char lanes;
    unsigned char i, k;
    unsigned char port = param_1;
    union Ced u;
    unsigned int cur, nxt;
    unsigned short val;

    if (port == 0)
        lanes = 2;
    else if (port == 1)
        lanes = 3;
    else
        return;

    if (DAT_a807d680[port].b8f == 0 && (DAT_a8078634 & 0x2000))
        FUN_a0073044(s_a006a038, DAT_a807d680[port].b8e);

    for (i = 0; i < DAT_a807d680[port].n; i++) {
        if (i == 0)
            ok = FUN_a00a7468(0xf, lanes, 0x2e64) != 0;
        else if (i == 1)
            ok = FUN_a00a7468(0x1f, lanes, 0x2e64) != 0;
        else if (i == 2)
            ok = FUN_a00a7468(0xf, lanes, 0x2e68) != 0;
        else if (i == 3)
            ok = FUN_a00a7468(0x1f, lanes, 0x2e68) != 0;
        if (ok) {
            if (i == 0) {
                u.w = FUN_a00a7314(lanes, 0x2e64);
                ced[0] = u.f.c0;
            } else if (i == 1) {
                u.w = FUN_a00a7314(lanes, 0x2e64);
                ced[1] = u.f.c1;
            } else if (i == 2) {
                u.w = FUN_a00a7314(lanes, 0x2e68);
                ced[2] = u.f.c0;
            } else if (i == 3) {
                u.w = FUN_a00a7314(lanes, 0x2e68);
                ced[3] = u.f.c1;
            }
        } else {
            ced[i] = 0;
            if (DAT_a8078634 & 0x2000)
                FUN_a00734c4(s_a006a060);
        }
    }

    for (i = 0; i < DAT_a807d680[param_1 & 0xff].n; i++) {
        if (ced[i] == 0x7fff && DAT_a807d680[param_1 & 0xff].a92[i] == 0) {
            FUN_a00a73ac(1, DAT_a807db00[param_1 & 0xff].p0c + 0x60);
            DAT_a807d680[param_1 & 0xff].a92[i] = 1;
            FUN_a0073044(s_a006a080, i);
        }
        if (DAT_a807d680[param_1 & 0xff].b8f == 0) {
            DAT_a807d680[param_1 & 0xff].h[i][DAT_a807d680[param_1 & 0xff].b8e] = ced[i];
            for (k = 0; k < 10; k++) {
                if (DAT_a8078634 & 0x2000)
                    FUN_a0073044(s_a006a0e8, DAT_a807d680[param_1 & 0xff].h[i][k]);
            }
            if (DAT_a807d680[param_1 & 0xff].b91 != 0) {
                cur = DAT_a807d680[param_1 & 0xff].h[i][DAT_a807d680[param_1 & 0xff].b8e];
                nxt = DAT_a807d680[param_1 & 0xff].h[i][(DAT_a807d680[param_1 & 0xff].b8e + 1) % 10];
                if (cur < nxt) {
                    if (DAT_a8078634 & 0x2000)
                        FUN_a00734c4(s_a006a090);
                    FUN_a0099560(param_1 & 0xff);
                    return;
                }
                cur -= nxt;
                if ((int)cur > 4) {
                    if (DAT_a8078634 & 0x2000)
                        FUN_a0073044(s_a006a0c0, i, cur);
                    FUN_a00a73ac(1, DAT_a807db00[param_1 & 0xff].p0c + 0x60);
                }
            } else {
                val = DAT_a807d680[param_1 & 0xff].h[i][DAT_a807d680[param_1 & 0xff].b8e];
                if (val > 4) {
                    FUN_a00a73ac(1, DAT_a807db00[param_1 & 0xff].p0c + 0x60);
                    if (DAT_a8078634 & 0x2000)
                        FUN_a0073044(s_a006a0c0, i, val);
                }
            }
            if (DAT_a8078634 & 0x2000)
                FUN_a00734c4(s_a0069ee8);
        }
    }

    if (DAT_a807d680[param_1 & 0xff].b8f == 0) {
        if (++DAT_a807d680[param_1 & 0xff].b8e == 10) {
            DAT_a807d680[param_1 & 0xff].b91 = 1;
            DAT_a807d680[param_1 & 0xff].b8e = 0;
        }
    }
    DAT_a807d680[param_1 & 0xff].b8f = (DAT_a807d680[param_1 & 0xff].b8f + 1) % DAT_a807d680[param_1 & 0xff].b90;
}
