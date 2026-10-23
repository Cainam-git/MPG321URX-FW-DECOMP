/* 8051_bank1 FUN_CODE_3091 @ 0x3091  external interrupt 1 service routine (OPTIMIZE(7,SPEED)).
 * Vector 0x0013 'LJMP 0x3091'; 'using 3' = MOV PSW,#18H, and Keil saves ACC, B, DPH, DPL, PSW (it calls
 * functions). Counterpart of FUN_CODE_2c38 (interrupt 0) for the other register blocks, with the same arrays
 * but descending indices. In order:
 *   XDATA 0xF020 bit 7: when 0xF021 & 0xA1E7 is non-zero, 0xF021 = 0xA1E7 and FUN_CODE_bc3d().
 *   0xF031 bit 6: while 0xF072 bit 0 is clear, bytes from 0xF074 go into 0xA278[] at the 16-bit IDATA index 0x4A
 *     (reset to 0 at 0x38), each followed by 0xF00A = 0x55; then 0xF072 |= 0x10 when its bit 4 is set.
 *   FUN_CODE_c1c1().
 *   Four register blocks, served when 0xF020 bit 1 (registers 0xF041..0xF047), 0xF020 bit 3 (0xF091..0xF097),
 *   0xF020 bit 5 (0xF0B8..0xF0BE) or 0xF0A7 bit 7 (0xF014..0xF01A) is set. With R = the block base, per block:
 *   R+3 bit 7: R+4 = 0x80; when R+1 bit 7 is set: R+4 = 0x44, R+5 = out[0x3B], R+2 = 0xC0, out index = 0x3A;
 *     otherwise: R+2 = 0xA0, R+0 |= 0x40, in index = 0x3B, IDATA 0x29 |= the block's bit.
 *   while R+3 bit 6: when out index != out count, R+5 = out[out index--]; else R+5 = out[out index] and
 *     out index = 0x3B; R+4 = 0x40; 0xF00A = 0x55.
 *   while R+3 bit 5: in[in index--] = R+6; R+4 = 0x20; IDATA 0x29 |= the block's bit; the in index is set to
 *     0x39 when it is 1 or less; 0xF00A = 0x55.
 *   R+3 bit 4, then R+3 bit 3 (two separate tests): R+4 = 0xFF.
 * Per block (0x29 bit, out array, in array, IDATA out index, out count, in index):
 *   0x02: 0xA002, 0xA0F4, 0x3B, 0x33, 0x2B    0x08: 0xA03E, 0xA130, 0x3D, 0x35, 0x2D
 *   0x20: 0xA07A, 0xA16C, 0x3F, 0x37, 0x2F    0x80: 0xA0B6, 0xA1A8, 0x41, 0x39, 0x31
 * In the 0x20 block Keil reuses A = 0x20 from the preceding store for 'IDATA 0x29 |= 0x20' (ORL A,@R0).
 * The 0xF0xx locations are hardware registers (volatile). The ANL/JZ tests of 0xF031, 0xF072 and 0xF0A7 are
 * int-typed tests '(unsigned int)(x & n)'; the JB/JNB tests are plain char tests. 'f021 & a1e7' in this operand
 * order loads 0xA1E7 first and keeps it in R7 for the store. No aids.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f020, DAT_EXTMEM_f021, DAT_EXTMEM_f00a, DAT_EXTMEM_f031, DAT_EXTMEM_f0a7;
extern unsigned char volatile xdata DAT_EXTMEM_f072, DAT_EXTMEM_f074;
extern unsigned char volatile xdata DAT_EXTMEM_f041, DAT_EXTMEM_f042, DAT_EXTMEM_f043, DAT_EXTMEM_f044, DAT_EXTMEM_f045, DAT_EXTMEM_f046, DAT_EXTMEM_f047;
extern unsigned char volatile xdata DAT_EXTMEM_f091, DAT_EXTMEM_f092, DAT_EXTMEM_f093, DAT_EXTMEM_f094, DAT_EXTMEM_f095, DAT_EXTMEM_f096, DAT_EXTMEM_f097;
extern unsigned char volatile xdata DAT_EXTMEM_f0b8, DAT_EXTMEM_f0b9, DAT_EXTMEM_f0ba, DAT_EXTMEM_f0bb, DAT_EXTMEM_f0bc, DAT_EXTMEM_f0bd, DAT_EXTMEM_f0be;
extern unsigned char volatile xdata DAT_EXTMEM_f014, DAT_EXTMEM_f015, DAT_EXTMEM_f016, DAT_EXTMEM_f017, DAT_EXTMEM_f018, DAT_EXTMEM_f019, DAT_EXTMEM_f01a;
extern unsigned char xdata DAT_EXTMEM_a1e7;
extern unsigned char xdata DAT_EXTMEM_a002[], DAT_EXTMEM_a03e[], DAT_EXTMEM_a07a[], DAT_EXTMEM_a0b6[];
extern unsigned char xdata DAT_EXTMEM_a0f4[], DAT_EXTMEM_a130[], DAT_EXTMEM_a16c[], DAT_EXTMEM_a1a8[];
extern unsigned char xdata DAT_EXTMEM_a278[];
extern unsigned char idata DAT_INTMEM_29;
extern unsigned char idata DAT_INTMEM_2b, DAT_INTMEM_2d, DAT_INTMEM_2f, DAT_INTMEM_31;
extern unsigned char idata DAT_INTMEM_33, DAT_INTMEM_35, DAT_INTMEM_37, DAT_INTMEM_39;
extern unsigned char idata DAT_INTMEM_3b, DAT_INTMEM_3d, DAT_INTMEM_3f, DAT_INTMEM_41;
extern unsigned int idata DAT_INTMEM_4a;
void FUN_CODE_bc3d(void);
void FUN_CODE_c1c1(void);

void FUN_CODE_3091(void) interrupt 2 using 3
{
    if (DAT_EXTMEM_f020 & 0x80) {
        if (DAT_EXTMEM_f021 & DAT_EXTMEM_a1e7) {
            DAT_EXTMEM_f021 = DAT_EXTMEM_a1e7;
            FUN_CODE_bc3d();
        }
    }
    if ((unsigned int)(DAT_EXTMEM_f031 & 0x40)) {
        while (!(unsigned int)(DAT_EXTMEM_f072 & 0x01)) {
            DAT_EXTMEM_a278[DAT_INTMEM_4a++] = DAT_EXTMEM_f074;
            if (DAT_INTMEM_4a >= 0x38) DAT_INTMEM_4a = 0;
            DAT_EXTMEM_f00a = 0x55;
        }
        if ((unsigned int)(DAT_EXTMEM_f072 & 0x10)) DAT_EXTMEM_f072 |= 0x10;
    }
    FUN_CODE_c1c1();
    if (DAT_EXTMEM_f020 & 0x02) {
        if (DAT_EXTMEM_f044 & 0x80) {
            DAT_EXTMEM_f045 = 0x80;
            if (DAT_EXTMEM_f042 & 0x80) {
                DAT_EXTMEM_f045 = 0x44;
                DAT_EXTMEM_f046 = DAT_EXTMEM_a002[0x3b];
                DAT_EXTMEM_f043 = 0xc0;
                DAT_INTMEM_3b = 0x3a;
            } else {
                DAT_EXTMEM_f043 = 0xa0;
                DAT_EXTMEM_f041 |= 0x40;
                DAT_INTMEM_2b = 0x3b;
                DAT_INTMEM_29 |= 0x02;
            }
        }
        while (DAT_EXTMEM_f044 & 0x40) {
            if (DAT_INTMEM_3b != DAT_INTMEM_33) {
                DAT_EXTMEM_f046 = DAT_EXTMEM_a002[DAT_INTMEM_3b--];
                DAT_EXTMEM_f045 = 0x40;
            } else {
                DAT_EXTMEM_f046 = DAT_EXTMEM_a002[DAT_INTMEM_3b];
                DAT_EXTMEM_f045 = 0x40;
                DAT_INTMEM_3b = 0x3b;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (DAT_EXTMEM_f044 & 0x20) {
            DAT_EXTMEM_a0f4[DAT_INTMEM_2b--] = DAT_EXTMEM_f047;
            DAT_EXTMEM_f045 = 0x20;
            DAT_INTMEM_29 |= 0x02;
            if (DAT_INTMEM_2b <= 1) DAT_INTMEM_2b = 0x39;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (DAT_EXTMEM_f044 & 0x10) DAT_EXTMEM_f045 = 0xff;
        if (DAT_EXTMEM_f044 & 0x08) DAT_EXTMEM_f045 = 0xff;
    }
    if (DAT_EXTMEM_f020 & 0x08) {
        if (DAT_EXTMEM_f094 & 0x80) {
            DAT_EXTMEM_f095 = 0x80;
            if (DAT_EXTMEM_f092 & 0x80) {
                DAT_EXTMEM_f095 = 0x44;
                DAT_EXTMEM_f096 = DAT_EXTMEM_a03e[0x3b];
                DAT_EXTMEM_f093 = 0xc0;
                DAT_INTMEM_3d = 0x3a;
            } else {
                DAT_EXTMEM_f093 = 0xa0;
                DAT_EXTMEM_f091 |= 0x40;
                DAT_INTMEM_2d = 0x3b;
                DAT_INTMEM_29 |= 0x08;
            }
        }
        while (DAT_EXTMEM_f094 & 0x40) {
            if (DAT_INTMEM_3d != DAT_INTMEM_35) {
                DAT_EXTMEM_f096 = DAT_EXTMEM_a03e[DAT_INTMEM_3d--];
                DAT_EXTMEM_f095 = 0x40;
            } else {
                DAT_EXTMEM_f096 = DAT_EXTMEM_a03e[DAT_INTMEM_3d];
                DAT_EXTMEM_f095 = 0x40;
                DAT_INTMEM_3d = 0x3b;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (DAT_EXTMEM_f094 & 0x20) {
            DAT_EXTMEM_a130[DAT_INTMEM_2d--] = DAT_EXTMEM_f097;
            DAT_EXTMEM_f095 = 0x20;
            DAT_INTMEM_29 |= 0x08;
            if (DAT_INTMEM_2d <= 1) DAT_INTMEM_2d = 0x39;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (DAT_EXTMEM_f094 & 0x10) DAT_EXTMEM_f095 = 0xff;
        if (DAT_EXTMEM_f094 & 0x08) DAT_EXTMEM_f095 = 0xff;
    }
    if (DAT_EXTMEM_f020 & 0x20) {
        if (DAT_EXTMEM_f0bb & 0x80) {
            DAT_EXTMEM_f0bc = 0x80;
            if (DAT_EXTMEM_f0b9 & 0x80) {
                DAT_EXTMEM_f0bc = 0x44;
                DAT_EXTMEM_f0bd = DAT_EXTMEM_a07a[0x3b];
                DAT_EXTMEM_f0ba = 0xc0;
                DAT_INTMEM_3f = 0x3a;
            } else {
                DAT_EXTMEM_f0ba = 0xa0;
                DAT_EXTMEM_f0b8 |= 0x40;
                DAT_INTMEM_2f = 0x3b;
                DAT_INTMEM_29 |= 0x20;
            }
        }
        while (DAT_EXTMEM_f0bb & 0x40) {
            if (DAT_INTMEM_3f != DAT_INTMEM_37) {
                DAT_EXTMEM_f0bd = DAT_EXTMEM_a07a[DAT_INTMEM_3f--];
                DAT_EXTMEM_f0bc = 0x40;
            } else {
                DAT_EXTMEM_f0bd = DAT_EXTMEM_a07a[DAT_INTMEM_3f];
                DAT_EXTMEM_f0bc = 0x40;
                DAT_INTMEM_3f = 0x3b;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (DAT_EXTMEM_f0bb & 0x20) {
            DAT_EXTMEM_a16c[DAT_INTMEM_2f--] = DAT_EXTMEM_f0be;
            DAT_EXTMEM_f0bc = 0x20;
            DAT_INTMEM_29 |= 0x20;
            if (DAT_INTMEM_2f <= 1) DAT_INTMEM_2f = 0x39;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (DAT_EXTMEM_f0bb & 0x10) DAT_EXTMEM_f0bc = 0xff;
        if (DAT_EXTMEM_f0bb & 0x08) DAT_EXTMEM_f0bc = 0xff;
    }
    if ((unsigned int)(DAT_EXTMEM_f0a7 & 0x80)) {
        if (DAT_EXTMEM_f017 & 0x80) {
            DAT_EXTMEM_f018 = 0x80;
            if (DAT_EXTMEM_f015 & 0x80) {
                DAT_EXTMEM_f018 = 0x44;
                DAT_EXTMEM_f019 = DAT_EXTMEM_a0b6[0x3b];
                DAT_EXTMEM_f016 = 0xc0;
                DAT_INTMEM_41 = 0x3a;
            } else {
                DAT_EXTMEM_f016 = 0xa0;
                DAT_EXTMEM_f014 |= 0x40;
                DAT_INTMEM_31 = 0x3b;
                DAT_INTMEM_29 |= 0x80;
            }
        }
        while (DAT_EXTMEM_f017 & 0x40) {
            if (DAT_INTMEM_41 != DAT_INTMEM_39) {
                DAT_EXTMEM_f019 = DAT_EXTMEM_a0b6[DAT_INTMEM_41--];
                DAT_EXTMEM_f018 = 0x40;
            } else {
                DAT_EXTMEM_f019 = DAT_EXTMEM_a0b6[DAT_INTMEM_41];
                DAT_EXTMEM_f018 = 0x40;
                DAT_INTMEM_41 = 0x3b;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (DAT_EXTMEM_f017 & 0x20) {
            DAT_EXTMEM_a1a8[DAT_INTMEM_31--] = DAT_EXTMEM_f01a;
            DAT_EXTMEM_f018 = 0x20;
            DAT_INTMEM_29 |= 0x80;
            if (DAT_INTMEM_31 <= 1) DAT_INTMEM_31 = 0x39;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (DAT_EXTMEM_f017 & 0x10) DAT_EXTMEM_f018 = 0xff;
        if (DAT_EXTMEM_f017 & 0x08) DAT_EXTMEM_f018 = 0xff;
    }
}
