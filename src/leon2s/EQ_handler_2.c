/*
 * EQ_handler_2 (leon2s 0xa0075ffc-0xa0076180, 388 bytes), flags -mcpu=v8 -Os -g.
 * void (port). For ch 0..2, under bit 1 of _DAT_a8078634, prints "[EQ]: Port%c <CH%d> RVGA=..., RCT=..., CCT=..."
 * with the port letter, ch, DAT_a00b3ac8[rvga[ch]], the rct byte and the cct halfword of entry ch at +0x884 of the
 * 0x898-byte record ARR_a807a9f0[port] (rvga[] at +0x890). Then three loops without bodies: j < 3 (byte 8 of the
 * 12-byte record ARR_a807ccc4[port] set) or 1; i < 10 or 14 with the same j loop inside (byte 8 re-read for
 * every test).
 * Source form: the first loop is written with labels ('goto test; loop: ...; ch++; test: if (ch < 3) goto
 * loop;'), which keeps the firmware's jump to the test at entry; p = (unsigned char)port is set after ch = 0; the
 * three values are read in print-argument order (rvga, rct, cct).
 */
struct EqCur { unsigned char rct; unsigned char _1; unsigned short cct; };
struct EqRec {
    unsigned char _0[0x884];
    struct EqCur cur[3];
    unsigned char rvga[3];
    unsigned char _893[5];
};
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
extern struct EqRec ARR_a807a9f0[];
extern struct Rec12 ARR_a807ccc4[];
extern const unsigned char DAT_a00b3ac8[];
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);

void EQ_handler_2(unsigned int port)
{
    unsigned int p;
    unsigned char ch, i, j;
    unsigned char rvga, rct;
    unsigned short cct;

    ch = 0;
    p = (unsigned char)port;
    goto test;
loop:
    rvga = DAT_a00b3ac8[ARR_a807a9f0[p].rvga[ch]];
    rct = ARR_a807a9f0[p].cur[ch].rct;
    cct = ARR_a807a9f0[p].cur[ch].cct;
    if (_DAT_a8078634 & 2)
        FUN_a0073044("[EQ]: Port%c <CH%d> RVGA=0x%02x, RCT=0x%02x, CCT=0x%04x\n", (char)(port + 'A'), ch,
                     rvga, rct, cct);
    ch++;
test:
    if (ch < 3)
        goto loop;
    for (j = 0; j < (ARR_a807ccc4[port & 0xff].b8 ? 3u : 1u); j++)
        ;
    for (i = 0; i < (ARR_a807ccc4[port & 0xff].b8 ? 10u : 14u); i++)
        for (j = 0; j < (ARR_a807ccc4[port & 0xff].b8 ? 3u : 1u); j++)
            ;
}
