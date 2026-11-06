/* FUN_a0123cf0 (leon2m 0xa0123cf0-0xa0124168), flags -mcpu=v8 -O3 -g.
 * Source form: the three writes to mailbox port 0xf191 go through one static helper cmd(c); the 0xee wait loop
 * stays in the caller after cmd(0x13).
 * Compiler aid: the helper has an arm for c == 0x47 that is dead for the commands used here (cmd(0) / cmd(0x13));
 * its folded test ends the cse1 path at both mailbox stores as in the firmware.
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

extern unsigned char DAT_a802d87e;
extern unsigned char FUN_a00f2254(unsigned char blk, unsigned char reg);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short FUN_a00f25f8(unsigned char blk, unsigned char reg);
extern unsigned int FUN_a010a864(void);
extern void func_0x4008f118(void);
extern void func_0x4008d1a0(int ms);
extern void func_0x4008e2a4(void);
extern void func_0x4008ced8(void);

static void cmd(unsigned char c)
{
    RB(DAT_a802d87e * 2 + 0xf191) = c;
    if (c == 0x47) {
        if (RB(DAT_a802d87e * 2 + 0xf191) == 0x47)
            func_0x4008ced8();
    }
}

void FUN_a0123cf0(int mode)
{
    unsigned char s[13];
    unsigned char ok;
    unsigned int w, h, v;

    switch (mode) {
    case 0:
        REG(0xcf011658) &= ~0x80;
        if (RB(DAT_a802d87e * 2 + 0xf190) == 0x97)
            func_0x4008f118();
        break;
    case 5:
        s[0] = REG(0xcf011a84);
        s[1] = REG(0xcf011a88);
        s[2] = REG(0xcf011a8c);
        s[3] = REG(0xcf013440);
        s[4] = REG(0xcf013444);
        s[5] = REG(0xcf011d8c);
        s[6] = REG(0xcf011800);
        s[7] = REG(0xcf011a00);
        s[8] = REG(0xcf012e00);
        s[9] = REG(0xcf011bf8);
        s[10] = REG(0xcf0116d4);
        s[11] = REG(0xcf011a80);
        s[12] = FUN_a00f2254(0, 0x86);
        cmd(0);
        ok = FUN_a010a864();
        REG(0xcf0116d4) &= ~1;
        REG(0xcf011a80) &= ~1;
        FUN_a00f2298(0, 0x86, 0);
        REG(0xcf011a84) = 0;
        REG(0xcf011a88) = 0;
        REG(0xcf011a8c) = 0;
        REG(0xcf012e00) = 0;
        if (REG(0xcf011d8c) & 3) {
            REG(0xcf011bf8) = 0;
            REG(0xcf011a00) = 0;
            REG(0xcf011800) = 0;
            func_0x4008d1a0(0x32);
            REG(0xcf011d8c) &= ~3;
        }
        if (!(REG(0xcf013440) & 1)) {
            REG(0xcf011bf8) = 0;
            REG(0xcf011a00) = 0;
            REG(0xcf011800) = 0;
            REG(0xcf013440) = 1;
            REG(0xcf013444) &= ~4;
        }
        REG(0xcf011800) = 1;
        REG(0xcf011a00) = 1;
        REG(0xcf011bf8) = 1;
        REG(0xcf011808) = 0xff;
        func_0x4008d1a0(100);
        if (REG(0xcf011808) & 3) {
            REG(0xcf011a00) = 0;
            func_0x4008e2a4();
            REG(0xcf011800) = 0;
            func_0x4008e2a4();
            REG(0xcf011a00) = 1;
        }
        if (!ok) {
            REG(0xcf011a00) = 0;
            REG(0xcf011800) = 0;
            REG(0xcf011bf8) = 0;
        }
        REG(0xcf03c668) = REG(0xcf01188c);
        REG(0xcf03c66c) = REG(0xcf011888);
        REG(0xcf03c670) = REG(0xcf011884);
        REG(0xcf03c674) = REG(0xcf011880);
        w = FUN_a00f25f8(0, 0x71);
        h = FUN_a00f25f8(0, 0x75);
        v = w * h * 3 / 0x5000 + 1;
        REG(0xcf03c678) = (v >> 8) & 0xff;
        REG(0xcf03c67c) = v & 0xff;
        cmd(0x13);
        while (RB(DAT_a802d87e * 2 + 0xf191) != 0xee)
            func_0x4008ced8();
        cmd(0);
        REG(0xcf011a84) = s[0];
        REG(0xcf011a88) = s[1];
        REG(0xcf011a8c) = s[2];
        REG(0xcf013440) = s[3];
        REG(0xcf013444) = s[4];
        REG(0xcf011d8c) = s[5];
        REG(0xcf011800) = s[6];
        REG(0xcf011a00) = s[7];
        REG(0xcf012e00) = s[8];
        REG(0xcf011bf8) = s[9];
        REG(0xcf0116d4) = s[10];
        REG(0xcf011a80) = s[11];
        FUN_a00f2298(0, 0x86, s[12]);
        break;
    }
}
