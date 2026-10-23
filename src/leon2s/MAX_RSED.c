/* MAX_RSED (leon2s 0xa0099c18-0xa0099ffc, 996 bytes), flags -mcpu=v8 -Os -g.
 * Port = (u8)param_1. Record DAT_a807d680[port] (0xb0 bytes): u16 hist[10] at 0x96, byte 0xaa = column index,
 * 0xab = sub-counter, 0xac = sub-counter modulus, 0xad = wrap flag, 0xae / 0xaf = flags (cleared by
 * FUN_a0099610). Word +0x20 of the 0x34-byte record DAT_a807db00[port] points to four register words.
 * With sub-counter 0 and bit 14 of DAT_a8078634, prints "Jex: RSED CNT debug, index = %d". When bit 15 of the
 * first register word is clear (FUN_a00a7408(0xf, ...)), prints "Jex: RSED non valid, ERR". Otherwise
 * sum = sum of bits 14..0 of the four words, & 0x7fff; sum 0x7ffc with flag 0xae clear calls
 * FUN_a00a73ac(6, word +0x18 of the record + 0x80 bytes), sets the flag and prints "MAX_RSED". With
 * sub-counter 0, the sum goes to hist[column], the history is printed ("%04X "), and the entry is compared:
 * with the wrap flag set, against hist[(column + 1) % 10] (smaller: prints the "RSED error clear" message and
 * tail-calls FUN_a0099610(port); difference > 4 with flag 0xaf clear: prints " Jex: RSED err>4 in 1s,
 * Total=0x%04X ", calls FUN_a00a73ac(6, ...), sets 0xaf); without it, against hist[0] (smaller: same clear
 * path; entry > 4 with 0xaf clear: FUN_a00a73ac, sets 0xaf, prints); then prints "\n". Finally the column
 * advances when the sub-counter is 0 (10 wraps to 0 and sets the wrap flag) and the sub-counter becomes
 * (c + 1) % modulus. Prints depend on bit 14 of DAT_a8078634.
 * Source forms: the register-word pointer is volatile, as are all register-block pointers of the
 * DAT_a807db00 records (see FUN_a00735e8); the sum is an unsigned short; one variable holds the entry and
 * then the difference.
 */
struct Rec {
    unsigned char _00[0x96];
    unsigned short hist[10];
    unsigned char idx, sub, mod, wrap, fe, ff;
};
struct Rec34 {
    unsigned char _00[0x18];
    unsigned int p18;
    unsigned char _1c[4];
    volatile unsigned int *p20;
    unsigned char _24[0x34 - 0x24];
};

extern struct Rec DAT_a807d680[];
extern struct Rec34 DAT_a807db00[];
extern unsigned int DAT_a8078634;
extern const char s_a006a0f0[], s_a006a118[], s_a006a128[], s_a006a150[], s_a006a188[], s_a006a0e8[];
extern const char s_a0069ee8[];

extern unsigned int FUN_a00a7408(unsigned int, volatile unsigned int *);
extern void FUN_a00a73ac(unsigned int, int);
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern void FUN_a0099610(unsigned char);

void MAX_RSED(unsigned int param_1)
{
    unsigned char port = param_1;
    volatile unsigned int *w;
    unsigned short sum;
    unsigned int cur, nxt;
    unsigned short val;
    unsigned char k;

    if (DAT_a807d680[port].sub == 0 && (DAT_a8078634 & 0x4000))
        FUN_a0073044(s_a006a0f0, DAT_a807d680[port].idx);
    if (FUN_a00a7408(0xf, DAT_a807db00[port].p20) != 0) {
        w = DAT_a807db00[port].p20;
        sum = ((w[0] & 0x7fff) + (w[1] & 0x7fff) + (w[2] & 0x7fff) + (w[3] & 0x7fff)) & 0x7fff;
        if (sum == 0x7ffc && DAT_a807d680[port].fe == 0) {
            FUN_a00a73ac(6, DAT_a807db00[port].p18 + 0x80);
            DAT_a807d680[port].fe = 1;
            FUN_a00734c4(s_a006a118);
        }
        if (DAT_a807d680[port].sub == 0) {
            DAT_a807d680[port].hist[DAT_a807d680[port].idx] = sum;
            for (k = 0; k < 10; k++) {
                if (DAT_a8078634 & 0x4000)
                    FUN_a0073044(s_a006a0e8, DAT_a807d680[port].hist[k]);
            }
            if (DAT_a807d680[port].wrap != 0) {
                cur = DAT_a807d680[port].hist[DAT_a807d680[port].idx];
                nxt = DAT_a807d680[port].hist[(DAT_a807d680[port].idx + 1) % 10];
                if (cur < nxt) {
                    if (DAT_a8078634 & 0x4000)
                        FUN_a00734c4(s_a006a150);
                    FUN_a0099610(port);
                    return;
                }
                cur -= nxt;
                if ((int)cur > 4 && DAT_a807d680[port].ff == 0) {
                    if (DAT_a8078634 & 0x4000)
                        FUN_a0073044(s_a006a128, cur);
                    FUN_a00a73ac(6, DAT_a807db00[port].p18 + 0x80);
                    DAT_a807d680[port].ff = 1;
                }
            } else {
                val = DAT_a807d680[port].hist[DAT_a807d680[port].idx];
                if (val < DAT_a807d680[port].hist[0]) {
                    if (DAT_a8078634 & 0x4000)
                        FUN_a00734c4(s_a006a150);
                    FUN_a0099610(port);
                    return;
                }
                if (val > 4 && DAT_a807d680[port].ff == 0) {
                    FUN_a00a73ac(6, DAT_a807db00[port].p18 + 0x80);
                    DAT_a807d680[port].ff = 1;
                    if (DAT_a8078634 & 0x4000)
                        FUN_a0073044(s_a006a128, val);
                }
            }
            if (DAT_a8078634 & 0x4000)
                FUN_a00734c4(s_a0069ee8);
        }
    } else {
        if (DAT_a8078634 & 0x4000)
            FUN_a00734c4(s_a006a188);
    }

    if (DAT_a807d680[port].sub == 0) {
        if (++DAT_a807d680[port].idx == 10) {
            DAT_a807d680[port].wrap = 1;
            DAT_a807d680[port].idx = 0;
        }
    }
    DAT_a807d680[port].sub = (DAT_a807d680[port].sub + 1) % DAT_a807d680[port].mod;
}
