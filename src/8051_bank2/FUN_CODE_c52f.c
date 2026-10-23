/* 8051_bank2 module FUN_CODE_c52f: FUN_CODE_e423 @ 0xe423..0xe432, FUN_CODE_c52f @ 0xc52f..0xc60e and
 * FUN_CODE_bba9 @ 0xbba9..0xbcb3, with the Keil common-entry block FUN_CODE_e419 @ 0xe419..0xe423 in front of
 * FUN_CODE_e423. One Keil C51 module, OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC). The block is the identical entry of
 * FUN_CODE_c52f and FUN_CODE_bba9 before their first call (FUN_CODE_e423): store the generic pointer parameter buf
 * (R3:R2:R1) at the DPTR the caller loads (0x08FD resp. 0x0909) and keep the char parameter in R6 (MOV R6,AR7).
 *
 * FUN_CODE_e423: I2C START condition. The service bus is bit-banged on port 1: P1.7 = SCL, P1.6 = SDA. SCL high,
 * SDA low (start), SCL low, with a half-bit delay (FUN_CODE_e462) after each step.
 *
 * FUN_CODE_c52f(v, buf) (callers 0xa159 and FUN_CODE_ca42 at 0xcb05, both with buf = XDATA 0x0440): LARGE
 * parameters v (R6 after the block) and buf (XDATA 0x08FD..0x08FF); locals st (0x0900) and chk (0x0901). After
 * FUN_CODE_e423 it sends with FUN_CODE_d275 the bytes 0x6E, 0x00, 0x3C, v, 0xF0, 0x0F, 0x6E, 0x91, 0x13, 0xEC,
 * OR-ing every result into st, then buf[0..0x1FF] (512 bytes, ?C?CLDOPTR; these results are not OR-ed), then the
 * XOR of every byte sent before it, also OR-ed into st; FUN_CODE_e525; returns st. Keil folds the constants of the
 * checksum expression into one XRL A,#0ADH.
 *
 * FUN_CODE_bba9(dev, buf) (callers 0xded4, 0xe133, 0xe4c1, all with dev = 0x6E and buf = XDATA 0x0436): LARGE
 * parameter buf (0x0909..0x090B), local i (unsigned int, 0x090C). After FUN_CODE_e423 it sends dev | 1 up to 10
 * times (FUN_CODE_d275 returns 0 on ACK, FUN_CODE_e462 between tries); after 10 failures FUN_CODE_e525 and return 1.
 * Then FUN_CODE_e44b(1), buf[0] = FUN_CODE_db1c(0), buf[1] = FUN_CODE_db1c(0); buf[0] > 10: FUN_CODE_e525, return 1.
 * Then buf[0] more bytes into buf[2..]: the last one after six FUN_CODE_e462 delays with FUN_CODE_db1c(1), the others
 * with FUN_CODE_db1c(0); FUN_CODE_e525; return 0.
 * Source forms the bytes depend on: the loop limit and the last-index test cast buf[0] to unsigned int (Keil then
 * zero-extends into R6:R7 with MOV R6,#0 and subtracts 1 with ADD/ADDC #0FFH); each arm has its own
 * 'buf[i + 2] = FUN_CODE_db1c(k);' (Keil cross-jumps the shared tail).
 */
#include <intrins.h>
sfr P1 = 0x90;
sbit SDA = P1 ^ 6;
sbit SCL = P1 ^ 7;
extern unsigned char xdata DAT_EXTMEM_09d2;
void FUN_CODE_e462(void);
void FUN_CODE_e423(void)
{
    SCL = 1;
    FUN_CODE_e462();
    SDA = 0;
    FUN_CODE_e462();
    SCL = 0;
    FUN_CODE_e462();
}

void FUN_CODE_e525(void);
void FUN_CODE_e44b(unsigned char n);
unsigned char FUN_CODE_d275(unsigned char b);
unsigned char FUN_CODE_db1c(unsigned char last);

unsigned char FUN_CODE_c52f(unsigned char v, unsigned char *buf)
{
    unsigned char st, chk;
    unsigned int i;
    FUN_CODE_e423();
    st = FUN_CODE_d275(0x6e);
    st |= FUN_CODE_d275(0);
    st |= FUN_CODE_d275(0x3c);
    st |= FUN_CODE_d275(v);
    st |= FUN_CODE_d275(0xf0);
    st |= FUN_CODE_d275(0x0f);
    st |= FUN_CODE_d275(0x6e);
    st |= FUN_CODE_d275(0x91);
    st |= FUN_CODE_d275(0x13);
    st |= FUN_CODE_d275(0xec);
    chk = 0x6e ^ 0x00 ^ 0x3c ^ v ^ 0xf0 ^ 0x0f ^ 0x6e ^ 0x91 ^ 0x13 ^ 0xec;
    for (i = 0; i < 0x200; i++) {
        FUN_CODE_d275(buf[i]);
        chk ^= buf[i];
    }
    st |= FUN_CODE_d275(chk);
    FUN_CODE_e525();
    return st;
}

unsigned char FUN_CODE_bba9(unsigned char dev, unsigned char *buf)
{
    unsigned int i;
    FUN_CODE_e423();
    for (i = 0; i < 10; i++) {
        if (FUN_CODE_d275(dev | 1) == 0) break;
        FUN_CODE_e462();
    }
    if (i == 10) {
        FUN_CODE_e525();
        return 1;
    }
    FUN_CODE_e44b(1);
    buf[0] = FUN_CODE_db1c(0);
    buf[1] = FUN_CODE_db1c(0);
    if (buf[0] > 10) {
        FUN_CODE_e525();
        return 1;
    }
    for (i = 0; i < (unsigned int)buf[0]; i++) {
        if (i == (unsigned int)buf[0] - 1) {
            FUN_CODE_e462();
            FUN_CODE_e462();
            FUN_CODE_e462();
            FUN_CODE_e462();
            FUN_CODE_e462();
            FUN_CODE_e462();
            buf[i + 2] = FUN_CODE_db1c(1);
        } else buf[i + 2] = FUN_CODE_db1c(0);
    }
    FUN_CODE_e525();
    return 0;
}
