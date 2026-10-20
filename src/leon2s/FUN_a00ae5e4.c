/* FUN_a00ae5e4 (leon2s 0xa00ae5e4-0xa00ae850, 620 bytes), flags -mcpu=v8 -Os -g.
 * Called by FUN_a00ae850 (port 0) and FUN_a00aea0c (port 1). When bit 3 of register 0xf7 of the port is set:
 * ver = (u8)reg 0xf8 >> 3; while bit 0 of reg 0xf8 is set, reads reg 0xf9 and stores the byte into
 * DAT_a807de78[i] for the first 20 bytes (later bytes are read and dropped). Then, by the bytes 0 and 2 of that
 * buffer: 0x10/0x30 runs the bit sequence on reg 0x24 (bit 1 off, bit 2 on, reg 0x25 = 0) twice, sets bit 3,
 * waits FUN_a00b160c(800) and clears bit 0; 0x10/0x50 runs it once and sets bit 3; 0x50/0x50 with byte 3 == 0
 * and ver == 4 sets bit 0 and runs it once. Finally sets bit 3 of reg 0xf7 again. Register access through
 * FUN_a00a6bb8 (read), FUN_a00a6c98 (port, reg, mask, set/clear) and FUN_a00a6c00 (write).
 * Source forms: every call passes the raw parameter to a callee whose first parameter is unsigned char, so
 * the 'and 0xff' is redone after each join, as in the firmware; the function returns its parameter, which
 * keeps the final call a normal call (no sibling call).
 */
extern unsigned char DAT_a807de78[];
extern unsigned int FUN_a00a6bb8(unsigned char, unsigned short);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned int, unsigned int);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned int);
extern void FUN_a00b160c(unsigned int);

unsigned int FUN_a00ae5e4(unsigned int param_1)
{
    unsigned char ver;
    unsigned char i;

    if (FUN_a00a6bb8(param_1, 0xf7) & 8) {
        ver = (unsigned char)FUN_a00a6bb8(param_1, 0xf8) >> 3;
        i = 0;
        while (FUN_a00a6bb8(param_1, 0xf8) & 1) {
            if (i < 0x14) {
                DAT_a807de78[i] = FUN_a00a6bb8(param_1, 0xf9);
                i++;
            } else {
                FUN_a00a6bb8(param_1, 0xf9);
            }
        }
        if (DAT_a807de78[0] == 0x10 && DAT_a807de78[2] == 0x30) {
            FUN_a00a6c98(param_1, 0x24, 2, 0);
            FUN_a00a6c98(param_1, 0x24, 4, 1);
            FUN_a00a6c00(param_1, 0x25, 0);
            FUN_a00a6c98(param_1, 0x24, 2, 0);
            FUN_a00a6c98(param_1, 0x24, 4, 1);
            FUN_a00a6c00(param_1, 0x25, 0);
            FUN_a00a6c98(param_1, 0x24, 8, 1);
            FUN_a00b160c(800);
            FUN_a00a6c98(param_1, 0x24, 1, 0);
        }
        if (DAT_a807de78[0] == 0x10 && DAT_a807de78[2] == 0x50) {
            FUN_a00a6c98(param_1, 0x24, 2, 0);
            FUN_a00a6c98(param_1, 0x24, 4, 1);
            FUN_a00a6c00(param_1, 0x25, 0);
            FUN_a00a6c98(param_1, 0x24, 8, 1);
        }
        if (DAT_a807de78[0] == 0x50 && DAT_a807de78[2] == 0x50 && DAT_a807de78[3] == 0 && ver == 4) {
            FUN_a00a6c98(param_1, 0x24, 1, 1);
            FUN_a00a6c98(param_1, 0x24, 2, 0);
            FUN_a00a6c98(param_1, 0x24, 4, 1);
            FUN_a00a6c00(param_1, 0x25, 0);
        }
        FUN_a00a6c98(param_1, 0xf7, 8, 1);
    }
    return param_1;
}
