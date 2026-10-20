/* 8051_bank1 FUN_CODE_3c4d @ 0x3c4d  register-block byte loop with five register pointers (LARGE model).
 * Caller: FUN_CODE_8512 (0x84F8). Returns a bit (carry): the AND of the results of FUN_CODE_611a and FUN_CODE_6db5.
 * LARGE parameter / local block at XDATA 0xA4B7: ch 0xA4B7, ctl (kept in R5, slot 0xA4B8 unused), n 0xA4B9..BA,
 * buf (generic pointer, passed in its slot 0xA4BB..BD), i 0xA4BE..BF, p0..p4 (generic pointers) 0xA4C0..CE;
 * the bit local ok is BITS 0x20.1.
 * Returns 0 when n is 0. ch selects the register block: p0..p4 = R+5, R+4, R+0, R+2, R+1 with R = 0xF039 (ch 0),
 * 0xF041 (1), 0xF089 (2), 0xF091 (3), 0xF09B (4), 0xF0B8 (5); any other ch leaves them 0.
 * Then 0xF00A = 0x55, ET0 = 0, *p1 = 0xFF, and by n:
 *   1: *p2 = 0xA77A | 0x02, *p0 = ctl | 1, FUN_CODE_611a(ch, buf).
 *   2: *p2 = 0xA77A | 0xC2, *p0 = ctl | 1, FUN_CODE_611a(ch, buf), FUN_CODE_611a(ch, buf + 1).
 *   3 and more: *p2 = 0xA77A | 0x42, *p0 = ctl | 1; for i = 0 .. n - 1: at i == n - 2 wait (two NOPs per
 *     pass) until *p4 bit 3 is set, set *p2 bit 7 and wait until it reads back clear; FUN_CODE_611a(ch, buf + i).
 * Finally FUN_CODE_6db5(ch), ET0 = 1. Pointer accesses go through the Keil library ?C?CLDPTR (0x06A4) and
 * ?C?CSTPTR (0x06EA). Keil shares the last FUN_CODE_611a call of n == 1 and n == 2. No aids.
 */
#include <reg51.h>
#include <intrins.h>
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char xdata DAT_EXTMEM_a77a;
bit FUN_CODE_611a(unsigned char ch, unsigned char *p);
bit FUN_CODE_6db5(unsigned char ch);

bit FUN_CODE_3c4d(unsigned char ch, unsigned char ctl, unsigned int n, unsigned char *buf)
{
    unsigned int i;
    unsigned char *p0, *p1, *p2, *p3, *p4;
    bit ok;

    i = 0;
    ok = 1;
    p0 = 0;
    p1 = 0;
    p2 = 0;
    p3 = 0;
    p4 = 0;
    if (n < 1) return 0;
    switch (ch) {
    case 0:
        p0 = (unsigned char xdata *)0xf03e;
        p1 = (unsigned char xdata *)0xf03d;
        p2 = (unsigned char xdata *)0xf039;
        p3 = (unsigned char xdata *)0xf03b;
        p4 = (unsigned char xdata *)0xf03a;
        break;
    case 1:
        p0 = (unsigned char xdata *)0xf046;
        p1 = (unsigned char xdata *)0xf045;
        p2 = (unsigned char xdata *)0xf041;
        p3 = (unsigned char xdata *)0xf043;
        p4 = (unsigned char xdata *)0xf042;
        break;
    case 2:
        p0 = (unsigned char xdata *)0xf08e;
        p1 = (unsigned char xdata *)0xf08d;
        p2 = (unsigned char xdata *)0xf089;
        p3 = (unsigned char xdata *)0xf08b;
        p4 = (unsigned char xdata *)0xf08a;
        break;
    case 3:
        p0 = (unsigned char xdata *)0xf096;
        p1 = (unsigned char xdata *)0xf095;
        p2 = (unsigned char xdata *)0xf091;
        p3 = (unsigned char xdata *)0xf093;
        p4 = (unsigned char xdata *)0xf092;
        break;
    case 4:
        p0 = (unsigned char xdata *)0xf0a0;
        p1 = (unsigned char xdata *)0xf09f;
        p2 = (unsigned char xdata *)0xf09b;
        p3 = (unsigned char xdata *)0xf09d;
        p4 = (unsigned char xdata *)0xf09c;
        break;
    case 5:
        p0 = (unsigned char xdata *)0xf0bd;
        p1 = (unsigned char xdata *)0xf0bc;
        p2 = (unsigned char xdata *)0xf0b8;
        p3 = (unsigned char xdata *)0xf0ba;
        p4 = (unsigned char xdata *)0xf0b9;
        break;
    }
    DAT_EXTMEM_f00a = 0x55;
    ET0 = 0;
    *p1 = 0xff;
    switch (n) {
    case 0:
        break;
    case 1:
        *p2 = DAT_EXTMEM_a77a | 0x02;
        *p0 = ctl | 0x01;
        ok &= FUN_CODE_611a(ch, buf);
        break;
    case 2:
        *p2 = DAT_EXTMEM_a77a | 0xc2;
        *p0 = ctl | 0x01;
        ok &= FUN_CODE_611a(ch, buf);
        ok &= FUN_CODE_611a(ch, buf + 1);
        break;
    default:
        *p2 = DAT_EXTMEM_a77a | 0x42;
        *p0 = ctl | 0x01;
        for (i = 0; i < n; i++) {
            if (i == n - 2) {
                while (!(*p4 & 0x08)) {
                    _nop_();
                    _nop_();
                }
                *p2 |= 0x80;
                while (*p2 & 0x80) ;
            }
            ok &= FUN_CODE_611a(ch, buf + i);
        }
        break;
    }
    ok &= FUN_CODE_6db5(ch);
    ET0 = 1;
    return ok;
}
