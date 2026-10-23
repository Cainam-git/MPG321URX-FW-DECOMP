/* 8051_bank1 module FUN_CODE_482e: FUN_CODE_482e, FUN_CODE_4cb9, FUN_CODE_62c6, FUN_CODE_6465 (one compile, byte-exact
 * with OPTIMIZE(8,SPEED) LARGE, also with REGFILE(R.ORC) added). All four take a channel ch 0..5 that selects a register block with
 * base R = 0xF039 (ch 0), 0xF041 (1), 0xF089 (2), 0xF091 (3), 0xF09B (4), 0xF0B8 (5); any other ch leaves the
 * pointers 0. Register pointers are generic pointers to volatile bytes (62c6 reads R+3 again for every test),
 * accessed through the Keil library ?C?CLDPTR (0x06A4) and ?C?CSTPTR (0x06EA). All four return a bit (carry).
 * Keil common-entry blocks (OPTIMIZE(8) "reuse of common entry code"): the calls 'FUN_CODE_62c6(ch, buf[i])' in
 * the loops of 482e and 4cb9 share the block 0x62B5..0x62C6 (FUN_CODE_62b5) in front of 62c6 (R7 = ch, R5 = buf[i] with i in
 * R4:R5); the calls 'FUN_CODE_6465(ch, buf[i])' share the block 0x644F..0x6465 (FUN_CODE_644f) in front of 6465 (buf and i read
 * from their adjacent LARGE slots through DPTR). Callers pass A = ch and DPTR = the slot of buf.
 *
 * FUN_CODE_482e(ch, ctl, n, buf), caller FUN_CODE_83f3 (0x84CC); LARGE slots 0xA4B7..0xA4CB (n 0xA4B9, buf
 * 0xA4BB, i 0xA4BE, p0..p3 0xA4C0..), bit local ok = BITS 0x20.1. 0xF00A = 0x55; returns 0 when n is 0;
 * p0..p3 = R+7, R+5, R+4, R+0; ET0 = 0; *p0 = 1, *p2 = 0xFF, *p3 = 0xA77A | 0x02, *p1 = ctl; for i = 0 .. n - 2:
 * 0xF00A = 0x55 and FUN_CODE_62c6(ch, buf[i]); then FUN_CODE_bae2(ch) and FUN_CODE_6465(ch, buf[n - 1]).
 * Returns the AND of all call results. ET0 is left 0.
 * FUN_CODE_4cb9(ch, ctl, w, n, buf), caller FUN_CODE_50c9 (0x5264); LARGE slots 0xA4BD..0xA4D0 (n and buf passed in their slots
 * 0xA4C1 / 0xA4C3). Returns 0 when n is 0; p0..p2 = R+5, R+4, R+0; 0xF00A = 0x55; ET0 = 0; *p1 = 0xFF,
 * *p2 = 0xA77A | 0x02, *p0 = ctl; FUN_CODE_62c6(ch, low byte of w); the same loop and two calls as 482e;
 * ET0 = 1. Returns the AND of all call results.
 * FUN_CODE_62c6(ch, v): ps, pd, pc = R+3, R+5, R+4; up to 1000 passes: return 0 when R+3 bit 3 or bit 4 is set;
 * when bit 6 is set: *pd = v, *pc = 0x40, return 1. Returns 0 after 1000 passes. The two early exits are
 * 'break' (Keil jumps to the shared CLR C / RET).
 * FUN_CODE_6465(ch, v): pd, pc, ps = R+5, R+0, R+1; ET0 = 0; *pd = v; *pc |= 0x20; ET0 = 1; up to 12000 passes:
 * return 1 when R+1 bit 0 is set. Returns 0 after 12000 passes.
 * No aids.
 */
#include <reg51.h>
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char xdata DAT_EXTMEM_a77a;
bit FUN_CODE_bae2(unsigned char ch);
bit FUN_CODE_62c6(unsigned char ch, unsigned char v);
bit FUN_CODE_6465(unsigned char ch, unsigned char v);

bit FUN_CODE_482e(unsigned char ch, unsigned char ctl, unsigned int n, unsigned char *buf)
{
    unsigned int i;
    unsigned char volatile *p0, *p1, *p2, *p3;
    bit ok;

    i = 0;
    ok = 1;
    p0 = 0;
    p1 = 0;
    p2 = 0;
    p3 = 0;
    DAT_EXTMEM_f00a = 0x55;
    if (n < 1) return 0;
    switch (ch) {
    case 0:
        p0 = (unsigned char xdata *)0xf040;
        p1 = (unsigned char xdata *)0xf03e;
        p2 = (unsigned char xdata *)0xf03d;
        p3 = (unsigned char xdata *)0xf039;
        break;
    case 1:
        p0 = (unsigned char xdata *)0xf048;
        p1 = (unsigned char xdata *)0xf046;
        p2 = (unsigned char xdata *)0xf045;
        p3 = (unsigned char xdata *)0xf041;
        break;
    case 2:
        p0 = (unsigned char xdata *)0xf090;
        p1 = (unsigned char xdata *)0xf08e;
        p2 = (unsigned char xdata *)0xf08d;
        p3 = (unsigned char xdata *)0xf089;
        break;
    case 3:
        p0 = (unsigned char xdata *)0xf098;
        p1 = (unsigned char xdata *)0xf096;
        p2 = (unsigned char xdata *)0xf095;
        p3 = (unsigned char xdata *)0xf091;
        break;
    case 4:
        p0 = (unsigned char xdata *)0xf0a2;
        p1 = (unsigned char xdata *)0xf0a0;
        p2 = (unsigned char xdata *)0xf09f;
        p3 = (unsigned char xdata *)0xf09b;
        break;
    case 5:
        p0 = (unsigned char xdata *)0xf0bf;
        p1 = (unsigned char xdata *)0xf0bd;
        p2 = (unsigned char xdata *)0xf0bc;
        p3 = (unsigned char xdata *)0xf0b8;
        break;
    }
    ET0 = 0;
    *p0 = 0x01;
    *p2 = 0xff;
    *p3 = DAT_EXTMEM_a77a | 0x02;
    *p1 = ctl;
    for (i = 0; i < n - 1; i++) {
        DAT_EXTMEM_f00a = 0x55;
        ok &= FUN_CODE_62c6(ch, buf[i]);
    }
    ok &= FUN_CODE_bae2(ch);
    ok &= FUN_CODE_6465(ch, buf[i]);
    return ok;
}

bit FUN_CODE_4cb9(unsigned char ch, unsigned char ctl, unsigned int w, unsigned int n, unsigned char *buf)
{
    unsigned int i;
    unsigned char volatile *p0, *p1, *p2;
    bit ok;

    i = 0;
    ok = 1;
    p0 = 0;
    p1 = 0;
    p2 = 0;
    if (n < 1) return 0;
    switch (ch) {
    case 0:
        p0 = (unsigned char xdata *)0xf03e;
        p1 = (unsigned char xdata *)0xf03d;
        p2 = (unsigned char xdata *)0xf039;
        break;
    case 1:
        p0 = (unsigned char xdata *)0xf046;
        p1 = (unsigned char xdata *)0xf045;
        p2 = (unsigned char xdata *)0xf041;
        break;
    case 2:
        p0 = (unsigned char xdata *)0xf08e;
        p1 = (unsigned char xdata *)0xf08d;
        p2 = (unsigned char xdata *)0xf089;
        break;
    case 3:
        p0 = (unsigned char xdata *)0xf096;
        p1 = (unsigned char xdata *)0xf095;
        p2 = (unsigned char xdata *)0xf091;
        break;
    case 4:
        p0 = (unsigned char xdata *)0xf0a0;
        p1 = (unsigned char xdata *)0xf09f;
        p2 = (unsigned char xdata *)0xf09b;
        break;
    case 5:
        p0 = (unsigned char xdata *)0xf0bd;
        p1 = (unsigned char xdata *)0xf0bc;
        p2 = (unsigned char xdata *)0xf0b8;
        break;
    }
    DAT_EXTMEM_f00a = 0x55;
    ET0 = 0;
    *p1 = 0xff;
    *p2 = DAT_EXTMEM_a77a | 0x02;
    *p0 = ctl;
    ok &= FUN_CODE_62c6(ch, w);
    for (i = 0; i < n - 1; i++) {
        DAT_EXTMEM_f00a = 0x55;
        ok &= FUN_CODE_62c6(ch, buf[i]);
    }
    ok &= FUN_CODE_bae2(ch);
    ok &= FUN_CODE_6465(ch, buf[i]);
    ET0 = 1;
    return ok;
}

bit FUN_CODE_62c6(unsigned char ch, unsigned char v)
{
    unsigned int t;
    unsigned char volatile *ps, *pd, *pc;

    t = 1000;
    ps = 0;
    pd = 0;
    pc = 0;
    switch (ch) {
    case 0:
        ps = (unsigned char xdata *)0xf03c;
        pd = (unsigned char xdata *)0xf03e;
        pc = (unsigned char xdata *)0xf03d;
        break;
    case 1:
        ps = (unsigned char xdata *)0xf044;
        pd = (unsigned char xdata *)0xf046;
        pc = (unsigned char xdata *)0xf045;
        break;
    case 2:
        ps = (unsigned char xdata *)0xf08c;
        pd = (unsigned char xdata *)0xf08e;
        pc = (unsigned char xdata *)0xf08d;
        break;
    case 3:
        ps = (unsigned char xdata *)0xf094;
        pd = (unsigned char xdata *)0xf096;
        pc = (unsigned char xdata *)0xf095;
        break;
    case 4:
        ps = (unsigned char xdata *)0xf09e;
        pd = (unsigned char xdata *)0xf0a0;
        pc = (unsigned char xdata *)0xf09f;
        break;
    case 5:
        ps = (unsigned char xdata *)0xf0bb;
        pd = (unsigned char xdata *)0xf0bd;
        pc = (unsigned char xdata *)0xf0bc;
        break;
    }
    while (t) {
        t--;
        if (*ps & 0x08) break;
        if (*ps & 0x10) break;
        if (*ps & 0x40) {
            *pd = v;
            *pc = 0x40;
            return 1;
        }
    }
    return 0;
}

bit FUN_CODE_6465(unsigned char ch, unsigned char v)
{
    unsigned int t;
    unsigned char volatile *pd, *pc, *ps;

    t = 12000;
    pd = 0;
    pc = 0;
    ps = 0;
    switch (ch) {
    case 0:
        pd = (unsigned char xdata *)0xf03e;
        pc = (unsigned char xdata *)0xf039;
        ps = (unsigned char xdata *)0xf03a;
        break;
    case 1:
        pd = (unsigned char xdata *)0xf046;
        pc = (unsigned char xdata *)0xf041;
        ps = (unsigned char xdata *)0xf042;
        break;
    case 2:
        pd = (unsigned char xdata *)0xf08e;
        pc = (unsigned char xdata *)0xf089;
        ps = (unsigned char xdata *)0xf08a;
        break;
    case 3:
        pd = (unsigned char xdata *)0xf096;
        pc = (unsigned char xdata *)0xf091;
        ps = (unsigned char xdata *)0xf092;
        break;
    case 4:
        pd = (unsigned char xdata *)0xf0a0;
        pc = (unsigned char xdata *)0xf09b;
        ps = (unsigned char xdata *)0xf09c;
        break;
    case 5:
        pd = (unsigned char xdata *)0xf0bd;
        pc = (unsigned char xdata *)0xf0b8;
        ps = (unsigned char xdata *)0xf0b9;
        break;
    }
    ET0 = 0;
    *pd = v;
    *pc |= 0x20;
    ET0 = 1;
    while (t) {
        t--;
        if (*ps & 0x01) return 1;
    }
    return 0;
}
