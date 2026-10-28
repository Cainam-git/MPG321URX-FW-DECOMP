/* 8051_bank1 FUN_CODE_568f @ 0x568f (469 B). Options: OPTIMIZE(8,SPEED) LARGE.
 * LARGE local i at XDATA 0xA473, bit local f (BIT 0x00). For i = 0..7: when bit i of IDATA 0x29 is set, the uint
 * at XDATA 0xA000 = FUN_CODE_d94a(), global bit 0x10 = 1, and f = bit 0 of register i of 0xF03A, 0xF042, 0xF08A,
 * 0xF092, 0xF09C, 0xF0B9, 0xF141, 0xF015; when f is set, bit i is cleared in IDATA 0x29 and set in XDATA 0xA0F3.
 * Otherwise: when FUN_CODE_d94a() - (0xA000) > 1000 and bit 0x10 is set, each of 0xF03D, 0xF045, 0xF08D, 0xF095,
 * 0xF09F, 0xF0BC, 0xF144, 0xF018 gets 0x10 when bit 0 of 0xF040, 0xF048, 0xF090, 0xF098, 0xF0A2, 0xF0BF, 0xF147,
 * 0xF01B (same order) is set, and bit 0x10 is cleared; then bit 6 is set in 0xF039, 0xF041, 0xF089, 0xF091, 0xF09B,
 * 0xF0B8, 0xF140, 0xF014 under the same bit-0 tests.
 * Source form: the mask 1 << i is built in a local m.
 */

extern unsigned char idata DAT_INTMEM_29;
extern unsigned int xdata DAT_EXTMEM_a000;
extern unsigned char xdata DAT_EXTMEM_a0f3;
extern bit BITS_22_0;
extern unsigned char xdata DAT_EXTMEM_f03a, DAT_EXTMEM_f042, DAT_EXTMEM_f08a, DAT_EXTMEM_f092;
extern unsigned char xdata DAT_EXTMEM_f09c, DAT_EXTMEM_f0b9, DAT_EXTMEM_f141, DAT_EXTMEM_f015;
extern unsigned char xdata DAT_EXTMEM_f040, DAT_EXTMEM_f048, DAT_EXTMEM_f090, DAT_EXTMEM_f098;
extern unsigned char xdata DAT_EXTMEM_f0a2, DAT_EXTMEM_f0bf, DAT_EXTMEM_f147, DAT_EXTMEM_f01b;
extern unsigned char xdata DAT_EXTMEM_f03d, DAT_EXTMEM_f045, DAT_EXTMEM_f08d, DAT_EXTMEM_f095;
extern unsigned char xdata DAT_EXTMEM_f09f, DAT_EXTMEM_f0bc, DAT_EXTMEM_f144, DAT_EXTMEM_f018;
extern unsigned char xdata DAT_EXTMEM_f039, DAT_EXTMEM_f041, DAT_EXTMEM_f089, DAT_EXTMEM_f091;
extern unsigned char xdata DAT_EXTMEM_f09b, DAT_EXTMEM_f0b8, DAT_EXTMEM_f140, DAT_EXTMEM_f014;
extern unsigned int FUN_CODE_d94a(void);

void FUN_CODE_568f(void)
{
    unsigned char i, m;
    bit f;

    for (i = 0; i < 8; i++) {
        f = 0;
        if ((DAT_INTMEM_29 >> i) & 1) {
            DAT_EXTMEM_a000 = FUN_CODE_d94a();
            BITS_22_0 = 1;
            switch (i) {
            case 0: if (DAT_EXTMEM_f03a & 1) f = 1; break;
            case 1: if (DAT_EXTMEM_f042 & 1) f = 1; break;
            case 2: if (DAT_EXTMEM_f08a & 1) f = 1; break;
            case 3: if (DAT_EXTMEM_f092 & 1) f = 1; break;
            case 4: if (DAT_EXTMEM_f09c & 1) f = 1; break;
            case 5: if (DAT_EXTMEM_f0b9 & 1) f = 1; break;
            case 6: if (DAT_EXTMEM_f141 & 1) f = 1; break;
            case 7: if (DAT_EXTMEM_f015 & 1) f = 1; break;
            }
            if (f) {
                m = 1 << i;
                DAT_INTMEM_29 &= ~m;
                DAT_EXTMEM_a0f3 |= m;
            }
        } else {
            if (FUN_CODE_d94a() - DAT_EXTMEM_a000 > 1000 && BITS_22_0) {
                if (DAT_EXTMEM_f040 & 1) DAT_EXTMEM_f03d = 0x10;
                if (DAT_EXTMEM_f048 & 1) DAT_EXTMEM_f045 = 0x10;
                if (DAT_EXTMEM_f090 & 1) DAT_EXTMEM_f08d = 0x10;
                if (DAT_EXTMEM_f098 & 1) DAT_EXTMEM_f095 = 0x10;
                if (DAT_EXTMEM_f0a2 & 1) DAT_EXTMEM_f09f = 0x10;
                if (DAT_EXTMEM_f0bf & 1) DAT_EXTMEM_f0bc = 0x10;
                if (DAT_EXTMEM_f147 & 1) DAT_EXTMEM_f144 = 0x10;
                if (DAT_EXTMEM_f01b & 1) DAT_EXTMEM_f018 = 0x10;
                BITS_22_0 = 0;
            }
            if (DAT_EXTMEM_f040 & 1) DAT_EXTMEM_f039 |= 0x40;
            if (DAT_EXTMEM_f048 & 1) DAT_EXTMEM_f041 |= 0x40;
            if (DAT_EXTMEM_f090 & 1) DAT_EXTMEM_f089 |= 0x40;
            if (DAT_EXTMEM_f098 & 1) DAT_EXTMEM_f091 |= 0x40;
            if (DAT_EXTMEM_f0a2 & 1) DAT_EXTMEM_f09b |= 0x40;
            if (DAT_EXTMEM_f0bf & 1) DAT_EXTMEM_f0b8 |= 0x40;
            if (DAT_EXTMEM_f147 & 1) DAT_EXTMEM_f140 |= 0x40;
            if (DAT_EXTMEM_f01b & 1) DAT_EXTMEM_f014 |= 0x40;
        }
    }
}
