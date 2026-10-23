/* 8051_bank2 module FUN_CODE_d275: FUN_CODE_d275 @ 0xd275..0xd2fb and FUN_CODE_c6ea @ 0xc6ea..0xc7c5, with the Keil
 * common-entry block FUN_CODE_d261 @ 0xd261..0xd275 in front of FUN_CODE_d275. One Keil C51 module,
 * OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC). The block is the shared set-up of two FUN_CODE_d275 calls in
 * FUN_CODE_c6ea: OR the previous call's result into st (R3), load addr (XDATA 0x08EF) into R4..R7 and shift it
 * right by R0 (?C?ULSHR; R0 = 16 and 8 are loaded before the LCALL), then fall into FUN_CODE_d275.
 *
 * FUN_CODE_d275(b): bit-banged I2C byte send.
 * Shifts b out MSB first on P1.6 (SDA), clocking P1.7 (SCL) with half-bit delays (FUN_CODE_e462). Then releases SDA,
 * raises SCL and waits up to 255 polls for the slave to release SCL (clock stretching). Returns 0 when the slave pulled
 * SDA low (ACK); when SDA is high it polls SDA up to 7 more half-bits and returns 1 (NACK) only if it stayed high.
 * Ends with SCL low, SDA high. Locals live in IDATA. Used for every byte of FUN_CODE_bfcf (service-bus write).
 *
 * FUN_CODE_c6ea(addr, v) (callers: FUN_CODE_d10a at 0xd155 with v = 0xAA and at 0xd1b0 with v = 0): LARGE
 * parameters addr (unsigned long, XDATA 0x08EF..0x08F2) and v (XDATA 0x08F3). After FUN_CODE_e423 it sends with
 * FUN_CODE_d275 the bytes 0x6E, 0x00, 0x3C, bits 23..16, 15..8 and 7..0 of addr, then 0xF0, 0x0F, 0x6E, 0x91, 0x13,
 * 0xEC, OR-ing every result into st. Then 512 data bytes: index 0..0x1FE send 0xFF, index 0x1FF sends v (these
 * results are not OR-ed). The last byte is the XOR of every byte sent before it, also OR-ed into st; then
 * FUN_CODE_e525 and return st. Keil folds the constant part of the checksum: 0x6E ^ 0x00 ^ 0x3C = 0x52 (XRL A,#52H)
 * and the six bytes 0xF0..0xEC XOR to 0xFF (CPL A); every 0xFF data byte flips the sum (CPL A).
 * Source forms the bytes depend on: the checksum is one expression after the header bytes; the 16-bit index counts
 * up to 0x200 (Keil tests i != 0x200 at the loop end). st, the checksum and i stay in R3, R6 and R4:R5 across the
 * FUN_CODE_d275 calls through the register file.
 */
#include <intrins.h>
sfr P1 = 0x90;
sbit SDA = P1 ^ 6;
sbit SCL = P1 ^ 7;
extern unsigned char xdata DAT_EXTMEM_09d2;
void FUN_CODE_e462(void);
void FUN_CODE_e423(void);
void FUN_CODE_e525(void);
unsigned char FUN_CODE_d275(unsigned char b)
{
    unsigned char idata n;
    unsigned char idata ack;
    unsigned char idata v;
    v = b;
    for (n = 0; n < 8; n++) {
        FUN_CODE_e462();
        SCL = 0;
        FUN_CODE_e462();
        if (v & 0x80) SDA = 1; else SDA = 0;
        FUN_CODE_e462();
        SCL = 1;
        v <<= 1;
    }
    FUN_CODE_e462();
    SCL = 0;
    FUN_CODE_e462();
    SDA = 1;
    FUN_CODE_e462();
    SCL = 1;
    FUN_CODE_e462();
    v = 0xff;
    while (!SCL && --v);
    if (!SDA) ack = 0;
    else {
        n = 7;
        while (SDA && n) {
            FUN_CODE_e462();
            n--;
        }
        if (n == 0) ack = 1; else ack = 0;
    }
    SCL = 0;
    SDA = 1;
    FUN_CODE_e462();
    FUN_CODE_e462();
    return ack;
}

unsigned char FUN_CODE_c6ea(unsigned long addr, unsigned char v)
{
    unsigned char st, chk;
    unsigned int i;
    FUN_CODE_e423();
    st = FUN_CODE_d275(0x6e);
    st |= FUN_CODE_d275(0);
    st |= FUN_CODE_d275(0x3c);
    st |= FUN_CODE_d275((unsigned char)(addr >> 16));
    st |= FUN_CODE_d275((unsigned char)(addr >> 8));
    st |= FUN_CODE_d275((unsigned char)addr);
    st |= FUN_CODE_d275(0xf0);
    st |= FUN_CODE_d275(0x0f);
    st |= FUN_CODE_d275(0x6e);
    st |= FUN_CODE_d275(0x91);
    st |= FUN_CODE_d275(0x13);
    st |= FUN_CODE_d275(0xec);
    chk = 0x6e ^ 0x00 ^ 0x3c ^ (unsigned char)(addr >> 16) ^ (unsigned char)(addr >> 8) ^ (unsigned char)addr
        ^ 0xf0 ^ 0x0f ^ 0x6e ^ 0x91 ^ 0x13 ^ 0xec;
    for (i = 0; i < 0x200; i++) {
        if (i == 0x1ff) {
            FUN_CODE_d275(v);
            chk ^= v;
        } else {
            FUN_CODE_d275(0xff);
            chk ^= 0xff;
        }
    }
    st |= FUN_CODE_d275(chk);
    FUN_CODE_e525();
    return st;
}
