/* leon2s FUN_a00a5d8c @ 0xa00a5d8c-0xa00a60ac, -mcpu=v8 -Os -g.
 * (u8 port, struct Out *d), void. regs = word 2 of the 12-byte record DAT_a807dc04[port], a register-block
 * pointer (volatile: every field reads its register word again). Unpacks the words regs[0x10/4] ..
 * regs[0x48/4] field by field into d: 14-bit halves (high half >> 16 & 0x3fff, low half & 0x3fff) into the
 * halfwords, single bits and 2- or 3-bit fields into the bytes, byte 6 = word 0x14 >> 15, byte 0x12 =
 * word 0x18 >> 8, halfword 0x22 = word 0x2c >> 16 & 0xfff, byte 0x40 = bit 31 of word 0x48 and word 0x44 =
 * word 0x48 & 0x1ffffff. The record pointer is re-read after each byte store (char stores may alias it).
 */
struct Out {
    unsigned short h00;
    unsigned short h02;
    unsigned char b04;
    unsigned char b05;
    unsigned char b06;
    unsigned char b07;
    unsigned char b08;
    unsigned char b09;
    unsigned char b0a;
    unsigned char b0b;
    unsigned char b0c;
    unsigned char b0d;
    unsigned char b0e;
    unsigned char b0f;
    unsigned short h10;
    unsigned char b12;
    unsigned char b13;
    unsigned short h14;
    unsigned short h16;
    unsigned short h18;
    unsigned short h1a;
    unsigned short h1c;
    unsigned short h1e;
    unsigned short h20;
    unsigned short h22;
    unsigned short h24;
    unsigned short h26;
    unsigned short h28;
    unsigned short h2a;
    unsigned short h2c;
    unsigned short h2e;
    unsigned short h30;
    unsigned char b32;
    unsigned char b33;
    unsigned short h34;
    unsigned short h36;
    unsigned short h38;
    unsigned char b3a;
    unsigned char b3b;
    unsigned char b3c;
    unsigned char b3d;
    unsigned char b3e;
    unsigned char b3f;
    unsigned char b40;
    unsigned char _41[3];
    unsigned int w44;
};
struct rec12 { unsigned int w0; unsigned int w4; volatile unsigned int *regs; };
extern struct rec12 DAT_a807dc04[];

void FUN_a00a5d8c(unsigned char port, struct Out *d)
{
    d->h00 = (DAT_a807dc04[port].regs[0x10 / 4] >> 16) & 0x3fff;
    d->h02 = (DAT_a807dc04[port].regs[0x10 / 4]) & 0x3fff;
    d->b04 = (DAT_a807dc04[port].regs[0x14 / 4] >> 27) & 7;
    d->b05 = (DAT_a807dc04[port].regs[0x14 / 4] >> 23) & 7;
    d->b06 = DAT_a807dc04[port].regs[0x14 / 4] >> 15;
    d->b07 = (DAT_a807dc04[port].regs[0x14 / 4] >> 11) & 1;
    d->b08 = (DAT_a807dc04[port].regs[0x14 / 4] >> 10) & 1;
    d->b09 = (DAT_a807dc04[port].regs[0x14 / 4] >> 8) & 1;
    d->b0a = (DAT_a807dc04[port].regs[0x14 / 4] >> 7) & 1;
    d->b0b = (DAT_a807dc04[port].regs[0x14 / 4] >> 6) & 1;
    d->b0c = (DAT_a807dc04[port].regs[0x14 / 4] >> 5) & 1;
    d->b0d = (DAT_a807dc04[port].regs[0x14 / 4] >> 4) & 1;
    d->b0e = (DAT_a807dc04[port].regs[0x14 / 4] >> 3) & 1;
    d->b0f = DAT_a807dc04[port].regs[0x14 / 4] & 3;
    d->h10 = (DAT_a807dc04[port].regs[0x18 / 4] >> 16) & 0x3fff;
    d->b12 = (DAT_a807dc04[port].regs[0x18 / 4] >> 8);
    d->b13 = (DAT_a807dc04[port].regs[0x18 / 4] >> 4) & 3;
    d->h14 = (DAT_a807dc04[port].regs[0x1c / 4] >> 16) & 0x3fff;
    d->h16 = (DAT_a807dc04[port].regs[0x1c / 4]) & 0x3fff;
    d->h18 = (DAT_a807dc04[port].regs[0x20 / 4] >> 16) & 0x3fff;
    d->h1a = (DAT_a807dc04[port].regs[0x20 / 4]) & 0x3fff;
    d->h1c = (DAT_a807dc04[port].regs[0x24 / 4] >> 16) & 0x3fff;
    d->h1e = (DAT_a807dc04[port].regs[0x24 / 4]) & 0x3fff;
    d->h20 = (DAT_a807dc04[port].regs[0x28 / 4]) & 0x3fff;
    d->h22 = (DAT_a807dc04[port].regs[0x2c / 4] >> 16) & 0xfff;
    d->h24 = (DAT_a807dc04[port].regs[0x2c / 4]) & 0x3fff;
    d->h26 = (DAT_a807dc04[port].regs[0x30 / 4] >> 16) & 0x3fff;
    d->h28 = (DAT_a807dc04[port].regs[0x30 / 4]) & 0x3fff;
    d->h2a = (DAT_a807dc04[port].regs[0x34 / 4] >> 16) & 0x3fff;
    d->h2c = (DAT_a807dc04[port].regs[0x34 / 4]) & 0x3fff;
    d->h2e = (DAT_a807dc04[port].regs[0x38 / 4] >> 16) & 0x3fff;
    d->h30 = (DAT_a807dc04[port].regs[0x38 / 4]) & 0x3fff;
    d->b32 = (DAT_a807dc04[port].regs[0x3c / 4] >> 17) & 1;
    d->b33 = (DAT_a807dc04[port].regs[0x3c / 4] >> 16) & 1;
    d->h34 = (DAT_a807dc04[port].regs[0x3c / 4]) & 0x3fff;
    d->h36 = (DAT_a807dc04[port].regs[0x40 / 4] >> 16) & 0x3fff;
    d->h38 = (DAT_a807dc04[port].regs[0x40 / 4]) & 0x3fff;
    d->b3a = (DAT_a807dc04[port].regs[0x44 / 4] >> 6) & 1;
    d->b3b = (DAT_a807dc04[port].regs[0x44 / 4] >> 5) & 1;
    d->b3c = (DAT_a807dc04[port].regs[0x44 / 4] >> 4) & 1;
    d->b3d = (DAT_a807dc04[port].regs[0x44 / 4] >> 3) & 1;
    d->b3e = (DAT_a807dc04[port].regs[0x44 / 4] >> 2) & 1;
    d->b3f = DAT_a807dc04[port].regs[0x44 / 4] & 3;
    d->b40 = DAT_a807dc04[port].regs[0x48 / 4] >> 31;
    d->w44 = DAT_a807dc04[port].regs[0x48 / 4] & 0x1ffffff;
}
