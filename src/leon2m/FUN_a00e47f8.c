/* leon2m FUN_a00e47f8 @ 0xa00e47f8-0xa00e4f8c, flags -mcpu=v8 -O3. Called from FUN_a00e0e44.
 * Parameters: dev (passed to every register call), ofs, and byte_idx (named by the firmware's string
 * "byte_idx %d out of range.\n"). byte_idx outside 0..3: calls FUN_a00df80c and FUN_a00e0bc0, passes that
 * string to FUN_a00df170 and returns -1.
 * Otherwise, through FUN_a00e05d8(dev, reg, mask, val) (masked write), it sets fields of the per-index
 * registers (0x30e/0x31b/0x328/0x335, then bits 0x13 of the other three of 0x306/0x313/0x320/0x32d),
 * pulses bit (1 << byte_idx) of 0x165/0x15f/0x15a/0x6a, writes 0x300, and polls FUN_a00e0788(dev, 0x300,
 * 0x80, 0x80) up to 5 times (FUN_a00e0ba8 and a "check_phy ... wait" line between tries; 5 failures set the
 * result to -1). It reads three registers of the selected index with FUN_a00e0514 and writes them back to
 * the index's registers (the first value also minus ofs to 0x161 + byte_idx), then checks registers
 * 0x301..0x306 with FUN_a00e0788 in a loop of i = 1..6 (a switch on i with jump table 0xa00e47dc); each
 * failed check sets the result to -1 and prints the register, mask, value and FUN_a00e02ec(dev, reg).
 * Finally it clears bits 0x13 of the three other index registers and returns the result (0 or -1).
 * Source form: the twelve read values are separate variables set to 0 at the start, filled by one switch
 * on byte_idx and written by a second one; reg, mask and val are set to 0 before the switch on i, and
 * every case sets all three.
 */
extern void FUN_a00dffb4(unsigned int, unsigned int, unsigned int);
extern int FUN_a00dfc50(unsigned int, unsigned int, unsigned int);
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int FUN_a00e0514(unsigned int, unsigned int, unsigned int);
extern int FUN_a00e0788(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00dffa4(unsigned int);
extern void FUN_a00e0ba8(void);
extern void FUN_a00e0090(unsigned int);
extern unsigned int FUN_a00e02ec(unsigned int, unsigned int);

int FUN_a00e47f8(unsigned int dev, unsigned int ofs, int byte_idx)
{
    unsigned int a0 = 0, a1 = 0, a2 = 0, a3 = 0;
    unsigned int b0 = 0, b1 = 0, b2 = 0, b3 = 0;
    unsigned int c0 = 0, c1 = 0, c2 = 0, c3 = 0;
    int ret = 0;
    int i;
    unsigned int m, reg, mask, val;

    FUN_a00dffb4(4, dev, byte_idx);
    FUN_a00dfc50(dev, 2, 4);
    if (byte_idx < 0 || byte_idx > 3) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("byte_idx %d out of range.\n", byte_idx);
        return -1;
    }
    switch (byte_idx) {
    case 0:
        FUN_a00e05d8(dev, 0x30e, 0xf0, 0x80);
        FUN_a00e05d8(dev, 0x30e, 0xf, 0xc);
        break;
    case 1:
        FUN_a00e05d8(dev, 0x31b, 0xf0, 0x80);
        FUN_a00e05d8(dev, 0x31b, 0xf, 0xc);
        break;
    case 2:
        FUN_a00e05d8(dev, 0x328, 0xf0, 0x80);
        FUN_a00e05d8(dev, 0x328, 0xf, 0xc);
        break;
    case 3:
        FUN_a00e05d8(dev, 0x335, 0xf0, 0x80);
        FUN_a00e05d8(dev, 0x335, 0xf, 0xc);
        break;
    }
    if (byte_idx != 0)
        FUN_a00e05d8(dev, 0x306, 0x13, 0x13);
    if (byte_idx != 1)
        FUN_a00e05d8(dev, 0x313, 0x13, 0x13);
    if (byte_idx != 2)
        FUN_a00e05d8(dev, 0x320, 0x13, 0x13);
    if (byte_idx != 3)
        FUN_a00e05d8(dev, 0x32d, 0x13, 0x13);
    FUN_a00e05d8(dev, 1, 0x40, 0);
    m = 1 << byte_idx;
    FUN_a00e05d8(dev, 0x165, m, m);
    FUN_a00e05d8(dev, 0x15f, m, 0);
    FUN_a00e05d8(dev, 0x15a, m, 0);
    FUN_a00e05d8(dev, 0x6a, m, 0);
    FUN_a00e05d8(dev, 0x6a, m, m);
    switch (byte_idx) {
    case 0:
        FUN_a00e05d8(dev, 0x306, 0xf, 0);
        break;
    case 1:
        FUN_a00e05d8(dev, 0x313, 0xf, 0);
        break;
    case 2:
        FUN_a00e05d8(dev, 0x320, 0xf, 0);
        break;
    case 3:
        FUN_a00e05d8(dev, 0x32d, 0xf, 0);
        break;
    }
    FUN_a00e05d8(dev, 0x300, 3, 2);
    FUN_a00e05d8(dev, 0x300, 3, 3);
    FUN_a00dffa4(20);
    for (i = 0; i < 5; i++) {
        if (FUN_a00e0788(dev, 0x300, 0x80, 0x80) != 0)
            break;
        FUN_a00e0ba8();
        FUN_a00df170("check_phy(%d,0x300,0x80,0x80) wait %d/%d\n", dev, i, 5);
    }
    if (i == 5)
        ret = -1;
    switch (byte_idx) {
    case 0:
        a0 = FUN_a00e0514(dev, 0x308, 0xff);
        b0 = FUN_a00e0514(dev, 0x33a, 0xff);
        c0 = FUN_a00e0514(dev, 0x309, 0x7f);
        break;
    case 1:
        a1 = FUN_a00e0514(dev, 0x315, 0xff);
        b1 = FUN_a00e0514(dev, 0x33b, 0xff);
        c1 = FUN_a00e0514(dev, 0x316, 0x7f);
        break;
    case 2:
        a2 = FUN_a00e0514(dev, 0x322, 0xff);
        b2 = FUN_a00e0514(dev, 0x33c, 0xff);
        c2 = FUN_a00e0514(dev, 0x323, 0x7f);
        break;
    case 3:
        a3 = FUN_a00e0514(dev, 0x32f, 0xff);
        b3 = FUN_a00e0514(dev, 0x33d, 0xff);
        c3 = FUN_a00e0514(dev, 0x330, 0x7f);
        break;
    }
    switch (byte_idx) {
    case 0:
        FUN_a00e05d8(dev, 0x310, 0xff, a0);
        FUN_a00e05d8(dev, 0x161, 0xff, a0 - ofs);
        FUN_a00e05d8(dev, 0x30f, 0xff, b0);
        FUN_a00e05d8(dev, 0x312, 0x7f, c0);
        break;
    case 1:
        FUN_a00e05d8(dev, 0x31d, 0xff, a1);
        FUN_a00e05d8(dev, 0x162, 0xff, a1 - ofs);
        FUN_a00e05d8(dev, 0x31c, 0xff, b1);
        FUN_a00e05d8(dev, 0x31f, 0x7f, c1);
        break;
    case 2:
        FUN_a00e05d8(dev, 0x32a, 0xff, a2);
        FUN_a00e05d8(dev, 0x163, 0xff, a2 - ofs);
        FUN_a00e05d8(dev, 0x329, 0xff, b2);
        FUN_a00e05d8(dev, 0x32c, 0x7f, c2);
        break;
    case 3:
        FUN_a00e05d8(dev, 0x337, 0xff, a3);
        FUN_a00e05d8(dev, 0x164, 0xff, a3 - ofs);
        FUN_a00e05d8(dev, 0x336, 0xff, b3);
        FUN_a00e05d8(dev, 0x339, 0x7f, c3);
        break;
    }
    FUN_a00e05d8(dev, 0x300, 3, 0);
    FUN_a00e05d8(dev, 1, 0x40, 0x40);
    m = 1 << byte_idx;
    FUN_a00e05d8(dev, 0x15f, m, m);
    FUN_a00e05d8(dev, 0x15a, m, m);
    FUN_a00e0090(dev);
    FUN_a00e05d8(dev, 0x300, 0xc, byte_idx << 2);
    for (i = 1; i <= 6; i++) {
        reg = 0; mask = 0; val = 0;
        switch (i) {
        case 1:
            reg = 0x301; mask = 0xff; val = 0x78;
            break;
        case 2:
            reg = 0x302; mask = 0xff; val = 0;
            break;
        case 3:
            reg = 0x303; mask = 0xff; val = 0;
            break;
        case 4:
            reg = 0x304; mask = 0xff; val = 0;
            break;
        case 5:
            reg = 0x305; mask = 0xff; val = 0;
            break;
        case 6:
            reg = 0x306; mask = 0x80; val = 0;
            break;
        }
        if (FUN_a00e0788(dev, reg, mask, val) == 0) {
            ret = -1;
            FUN_a00df80c();
            FUN_a00e0bc0();
            FUN_a00df170("PSD_B%d: check_phy(%d,0x%03x,0x%02x,0x%02x)=0x%02x fail\n",
                         byte_idx, dev, reg, mask, val, FUN_a00e02ec(dev, reg));
        }
    }
    if (byte_idx != 0)
        FUN_a00e05d8(dev, 0x306, 0x13, 0);
    if (byte_idx != 1)
        FUN_a00e05d8(dev, 0x313, 0x13, 0);
    if (byte_idx != 2)
        FUN_a00e05d8(dev, 0x320, 0x13, 0);
    if (byte_idx != 3)
        FUN_a00e05d8(dev, 0x32d, 0x13, 0);
    return ret;
}
