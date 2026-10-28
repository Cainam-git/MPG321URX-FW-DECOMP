/* 8051_bank1 FUN_CODE_52be @ 0x52be..0x54af (497 B)  OPTIMIZE(8,SPEED) LARGE.
 * Reads byte a of the 3-byte record XDATA 0xA62F[XDATA 0xA64D]: k = bits 0..4 (local XDATA 0xA474), f = bit 5;
 * r (local XDATA 0xA475) = 0. Switch on k (jump table at 0x52F4):
 *   0: r = FUN_CODE_c0a1(); when 0, r = FUN_CODE_cf38(); when 0, r = FUN_CODE_d7ac().
 *   1..6: bit 0x20.1 = f; r = FUN_CODE_d4b0(n) | FUN_CODE_b2b0(n) with n = 0, 0, 1, 0, 2, 3.
 *   7, 8: r = FUN_CODE_a6cf(0); when 0, r = FUN_CODE_da3a().  9, 10: the same with FUN_CODE_a6cf(1) / FUN_CODE_da57().
 *   11, 12: r = FUN_CODE_d6e7().  Other k: r = 0.
 * Then r = k when r is 1, else 0x0D. When r is 0x0D, for key = 7, 8, 9, 10 in turn: when FUN_CODE_d27f(key) is not
 * 0xFF and FUN_CODE_a6cf(0) or FUN_CODE_da3a() (keys 7, 8), FUN_CODE_a6cf(1) or FUN_CODE_da57() (keys 9, 10) returns 1,
 * r = key. Returns r. Caller: FUN_CODE_a57e.
 * Source forms:
 *  - m is declared with the initialiser 0xFF, which is never read. With it Keil keeps the record byte v in R6 and
 *    m = v & 0x1F in R7 as the firmware does; without it v is in R7 and m is copied.
 *  - The tests on keys 7..10 are written 'if (FUN_CODE_a6cf(n) == 0) { if (...) r = key; } else { r = key; }'. Keil
 *    merges the two stores of r and leaves a 'SJMP' to the next instruction (0x544A, 0x5467, 0x5484, 0x54A1).
 *  - Compiler aid: 'goto l2; l2:' and 'goto l4; l4:' at the end of cases 2 and 4 jump to the next statement and emit
 *    no code. Without them Keil merges the identical bodies of cases 1, 2 and 4 into one; the firmware keeps three
 *    copies.
 */
#include <reg51.h>
struct ent3 { unsigned char a, b, c; };
extern struct ent3 xdata DAT_EXTMEM_a62f[10];
extern unsigned char xdata DAT_EXTMEM_a64d;
extern bit BITS_20_1;
bit FUN_CODE_c0a1(void);
bit FUN_CODE_cf38(void);
bit FUN_CODE_d7ac(void);
bit FUN_CODE_b2b0(unsigned char pg);
bit FUN_CODE_d4b0(unsigned char n);
bit FUN_CODE_a6cf(unsigned char ch);
bit FUN_CODE_da3a(void);
bit FUN_CODE_da57(void);
bit FUN_CODE_d6e7(void);
unsigned char FUN_CODE_d27f(unsigned char key);

unsigned char FUN_CODE_52be(void)
{
    unsigned char v, m = 0xff, k, r;
    bit f;

    v = DAT_EXTMEM_a62f[DAT_EXTMEM_a64d].a;
    m = v & 0x1f;
    f = (v >> 5) & 1;
    k = m;
    r = 0;
    switch (m) {
    case 0:
        if ((r = FUN_CODE_c0a1()) != 0) break;
        if ((r = FUN_CODE_cf38()) != 0) break;
        r = FUN_CODE_d7ac();
        break;
    case 1:
        BITS_20_1 = f;
        r = FUN_CODE_d4b0(0) | FUN_CODE_b2b0(0);
        break;
    case 2:
        BITS_20_1 = f;
        r = FUN_CODE_d4b0(0) | FUN_CODE_b2b0(0);
        goto l2;
l2:
        break;
    case 3:
        BITS_20_1 = f;
        r = FUN_CODE_d4b0(1) | FUN_CODE_b2b0(1);
        break;
    case 4:
        BITS_20_1 = f;
        r = FUN_CODE_d4b0(0) | FUN_CODE_b2b0(0);
        goto l4;
l4:
        break;
    case 5:
        BITS_20_1 = f;
        r = FUN_CODE_d4b0(2) | FUN_CODE_b2b0(2);
        break;
    case 6:
        BITS_20_1 = f;
        r = FUN_CODE_d4b0(3) | FUN_CODE_b2b0(3);
        break;
    case 7:
        if ((r = FUN_CODE_a6cf(0)) != 0) break;
        r = FUN_CODE_da3a();
        break;
    case 8:
        if ((r = FUN_CODE_a6cf(0)) != 0) break;
        r = FUN_CODE_da3a();
        break;
    case 9:
        if ((r = FUN_CODE_a6cf(1)) != 0) break;
        r = FUN_CODE_da57();
        break;
    case 10:
        if ((r = FUN_CODE_a6cf(1)) != 0) break;
        r = FUN_CODE_da57();
        break;
    case 11:
    case 12:
        r = FUN_CODE_d6e7();
        break;
    default:
        r = 0;
        break;
    }
    if (r == 1) r = k;
    else r = 0x0d;
    if (r == 0x0d) {
        if (FUN_CODE_d27f(7) != 0xff) {
            if (FUN_CODE_a6cf(0) == 0) { if (FUN_CODE_da3a()) r = 7; } else { r = 7; }
        }
        if (FUN_CODE_d27f(8) != 0xff) {
            if (FUN_CODE_a6cf(0) == 0) { if (FUN_CODE_da3a()) r = 8; } else { r = 8; }
        }
        if (FUN_CODE_d27f(9) != 0xff) {
            if (FUN_CODE_a6cf(1) == 0) { if (FUN_CODE_da57()) r = 9; } else { r = 9; }
        }
        if (FUN_CODE_d27f(10) != 0xff) {
            if (FUN_CODE_a6cf(1) == 0) { if (FUN_CODE_da57()) r = 10; } else { r = 10; }
        }
    }
    return r;
}
