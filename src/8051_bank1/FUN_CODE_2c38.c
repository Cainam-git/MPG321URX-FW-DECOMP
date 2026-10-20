/* 8051_bank1 FUN_CODE_2c38 @ 0x2c38  external interrupt 0 service routine (byte-exact with OPTIMIZE(7,SPEED)).
 * Vector 0x0003 'LJMP 0x2C38'; 'using 1' = MOV PSW,#08H, and Keil saves only ACC, DPH, DPL, PSW.
 * Four register blocks with the same layout are served in turn, each when its bit in XDATA 0xF020 is set
 * (bit 0: registers 0xF039..0xF03F, bit 2: 0xF089..0xF08F, bit 4: 0xF09B..0xF0A1, bit 6: 0xF140..0xF146).
 * With R = the block base (0xF039, ...), per block:
 *   R+3 bit 7: R+4 = 0x80; when R+1 bit 7 is set: R+4 = 0x44, R+5 = out[0], R+2 = 0xC0, out index = 1;
 *     otherwise: R+2 = 0xA0, R+0 |= 0x40, in index = 0, IDATA 0x29 |= the block's bit.
 *   while R+3 bit 6: when out index != out count, R+5 = out[out index++]; else R+5 = out[out index] and
 *     out index = 0; R+4 = 0x40; 0xF00A = 0x55.
 *   while R+3 bit 5: in[in index++] = R+6; R+4 = 0x20; IDATA 0x29 |= the block's bit; the in index is set to 2
 *     when it exceeds 0x3B; 0xF00A = 0x55.
 *   R+3 bit 4, then R+3 bit 3 (two separate tests): R+4 = 0xFF.
 * Per block (out array, in array, IDATA out index, out count, in index):
 *   bit 0: 0xA002, 0xA0F4, 0x3A, 0x32, 0x2A    bit 2: 0xA03E, 0xA130, 0x3C, 0x34, 0x2C
 *   bit 4: 0xA07A, 0xA16C, 0x3E, 0x36, 0x2E    bit 6: 0xA0B6, 0xA1A8, 0x40, 0x38, 0x30
 * Then, when 0xF02E bit 6 is set: while 0xF0FA bit 0 is clear, bytes from 0xF0FC are stored into 0xA208[] at the
 * IDATA byte index 0x47 (reset to 0 at 0x38), each followed by 0xF00A = 0x55; then 0xF0FA |= 0x10 when its bit 4
 * is set. When 0xF02E bit 7 is set: the same with 0xF036 / 0xF038, array 0xA240 and the 16-bit IDATA index 0x48.
 * The 0xF0xx locations are hardware registers (volatile). The ANL/JZ tests of 0xF02E, 0xF0FA and 0xF036 are
 * int-typed tests '(unsigned int)(x & n)'; the JB/JNB tests are plain char tests. No aids.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f020, DAT_EXTMEM_f00a, DAT_EXTMEM_f02e;
extern unsigned char volatile xdata DAT_EXTMEM_f039, DAT_EXTMEM_f03a, DAT_EXTMEM_f03b, DAT_EXTMEM_f03c,
    DAT_EXTMEM_f03d, DAT_EXTMEM_f03e, DAT_EXTMEM_f03f;
extern unsigned char volatile xdata DAT_EXTMEM_f089, DAT_EXTMEM_f08a, DAT_EXTMEM_f08b, DAT_EXTMEM_f08c,
    DAT_EXTMEM_f08d, DAT_EXTMEM_f08e, DAT_EXTMEM_f08f;
extern unsigned char volatile xdata DAT_EXTMEM_f09b, DAT_EXTMEM_f09c, DAT_EXTMEM_f09d, DAT_EXTMEM_f09e,
    DAT_EXTMEM_f09f, DAT_EXTMEM_f0a0, DAT_EXTMEM_f0a1;
extern unsigned char volatile xdata DAT_EXTMEM_f140, DAT_EXTMEM_f141, DAT_EXTMEM_f142, DAT_EXTMEM_f143,
    DAT_EXTMEM_f144, DAT_EXTMEM_f145, DAT_EXTMEM_f146;
extern unsigned char volatile xdata DAT_EXTMEM_f0fa, DAT_EXTMEM_f0fc, DAT_EXTMEM_f036, DAT_EXTMEM_f038;
extern unsigned char xdata DAT_EXTMEM_a002[], DAT_EXTMEM_a03e[], DAT_EXTMEM_a07a[], DAT_EXTMEM_a0b6[];
extern unsigned char xdata DAT_EXTMEM_a0f4[], DAT_EXTMEM_a130[], DAT_EXTMEM_a16c[], DAT_EXTMEM_a1a8[];
extern unsigned char xdata DAT_EXTMEM_a208[], DAT_EXTMEM_a240[];
extern unsigned char idata DAT_INTMEM_29;
extern unsigned char idata DAT_INTMEM_2a, DAT_INTMEM_2c, DAT_INTMEM_2e, DAT_INTMEM_30;
extern unsigned char idata DAT_INTMEM_32, DAT_INTMEM_34, DAT_INTMEM_36, DAT_INTMEM_38;
extern unsigned char idata DAT_INTMEM_3a, DAT_INTMEM_3c, DAT_INTMEM_3e, DAT_INTMEM_40;
extern unsigned char idata DAT_INTMEM_47;
extern unsigned int idata DAT_INTMEM_48;

void FUN_CODE_2c38(void) interrupt 0 using 1
{
    if (DAT_EXTMEM_f020 & 0x01) {
        if (DAT_EXTMEM_f03c & 0x80) {
            DAT_EXTMEM_f03d = 0x80;
            if (DAT_EXTMEM_f03a & 0x80) {
                DAT_EXTMEM_f03d = 0x44;
                DAT_EXTMEM_f03e = DAT_EXTMEM_a002[0];
                DAT_EXTMEM_f03b = 0xc0;
                DAT_INTMEM_3a = 1;
            } else {
                DAT_EXTMEM_f03b = 0xa0;
                DAT_EXTMEM_f039 |= 0x40;
                DAT_INTMEM_2a = 0;
                DAT_INTMEM_29 |= 0x01;
            }
        }
        while (DAT_EXTMEM_f03c & 0x40) {
            if (DAT_INTMEM_3a != DAT_INTMEM_32) {
                DAT_EXTMEM_f03e = DAT_EXTMEM_a002[DAT_INTMEM_3a++];
                DAT_EXTMEM_f03d = 0x40;
            } else {
                DAT_EXTMEM_f03e = DAT_EXTMEM_a002[DAT_INTMEM_3a];
                DAT_EXTMEM_f03d = 0x40;
                DAT_INTMEM_3a = 0;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (DAT_EXTMEM_f03c & 0x20) {
            DAT_EXTMEM_a0f4[DAT_INTMEM_2a++] = DAT_EXTMEM_f03f;
            DAT_EXTMEM_f03d = 0x20;
            DAT_INTMEM_29 |= 0x01;
            if (DAT_INTMEM_2a > 0x3b) DAT_INTMEM_2a = 2;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (DAT_EXTMEM_f03c & 0x10) DAT_EXTMEM_f03d = 0xff;
        if (DAT_EXTMEM_f03c & 0x08) DAT_EXTMEM_f03d = 0xff;
    }
    if (DAT_EXTMEM_f020 & 0x04) {
        if (DAT_EXTMEM_f08c & 0x80) {
            DAT_EXTMEM_f08d = 0x80;
            if (DAT_EXTMEM_f08a & 0x80) {
                DAT_EXTMEM_f08d = 0x44;
                DAT_EXTMEM_f08e = DAT_EXTMEM_a03e[0];
                DAT_EXTMEM_f08b = 0xc0;
                DAT_INTMEM_3c = 1;
            } else {
                DAT_EXTMEM_f08b = 0xa0;
                DAT_EXTMEM_f089 |= 0x40;
                DAT_INTMEM_2c = 0;
                DAT_INTMEM_29 |= 0x04;
            }
        }
        while (DAT_EXTMEM_f08c & 0x40) {
            if (DAT_INTMEM_3c != DAT_INTMEM_34) {
                DAT_EXTMEM_f08e = DAT_EXTMEM_a03e[DAT_INTMEM_3c++];
                DAT_EXTMEM_f08d = 0x40;
            } else {
                DAT_EXTMEM_f08e = DAT_EXTMEM_a03e[DAT_INTMEM_3c];
                DAT_EXTMEM_f08d = 0x40;
                DAT_INTMEM_3c = 0;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (DAT_EXTMEM_f08c & 0x20) {
            DAT_EXTMEM_a130[DAT_INTMEM_2c++] = DAT_EXTMEM_f08f;
            DAT_EXTMEM_f08d = 0x20;
            DAT_INTMEM_29 |= 0x04;
            if (DAT_INTMEM_2c > 0x3b) DAT_INTMEM_2c = 2;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (DAT_EXTMEM_f08c & 0x10) DAT_EXTMEM_f08d = 0xff;
        if (DAT_EXTMEM_f08c & 0x08) DAT_EXTMEM_f08d = 0xff;
    }
    if (DAT_EXTMEM_f020 & 0x10) {
        if (DAT_EXTMEM_f09e & 0x80) {
            DAT_EXTMEM_f09f = 0x80;
            if (DAT_EXTMEM_f09c & 0x80) {
                DAT_EXTMEM_f09f = 0x44;
                DAT_EXTMEM_f0a0 = DAT_EXTMEM_a07a[0];
                DAT_EXTMEM_f09d = 0xc0;
                DAT_INTMEM_3e = 1;
            } else {
                DAT_EXTMEM_f09d = 0xa0;
                DAT_EXTMEM_f09b |= 0x40;
                DAT_INTMEM_2e = 0;
                DAT_INTMEM_29 |= 0x10;
            }
        }
        while (DAT_EXTMEM_f09e & 0x40) {
            if (DAT_INTMEM_3e != DAT_INTMEM_36) {
                DAT_EXTMEM_f0a0 = DAT_EXTMEM_a07a[DAT_INTMEM_3e++];
                DAT_EXTMEM_f09f = 0x40;
            } else {
                DAT_EXTMEM_f0a0 = DAT_EXTMEM_a07a[DAT_INTMEM_3e];
                DAT_EXTMEM_f09f = 0x40;
                DAT_INTMEM_3e = 0;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (DAT_EXTMEM_f09e & 0x20) {
            DAT_EXTMEM_a16c[DAT_INTMEM_2e++] = DAT_EXTMEM_f0a1;
            DAT_EXTMEM_f09f = 0x20;
            DAT_INTMEM_29 |= 0x10;
            if (DAT_INTMEM_2e > 0x3b) DAT_INTMEM_2e = 2;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (DAT_EXTMEM_f09e & 0x10) DAT_EXTMEM_f09f = 0xff;
        if (DAT_EXTMEM_f09e & 0x08) DAT_EXTMEM_f09f = 0xff;
    }
    if (DAT_EXTMEM_f020 & 0x40) {
        if (DAT_EXTMEM_f143 & 0x80) {
            DAT_EXTMEM_f144 = 0x80;
            if (DAT_EXTMEM_f141 & 0x80) {
                DAT_EXTMEM_f144 = 0x44;
                DAT_EXTMEM_f145 = DAT_EXTMEM_a0b6[0];
                DAT_EXTMEM_f142 = 0xc0;
                DAT_INTMEM_40 = 1;
            } else {
                DAT_EXTMEM_f142 = 0xa0;
                DAT_EXTMEM_f140 |= 0x40;
                DAT_INTMEM_30 = 0;
                DAT_INTMEM_29 |= 0x40;
            }
        }
        while (DAT_EXTMEM_f143 & 0x40) {
            if (DAT_INTMEM_40 != DAT_INTMEM_38) {
                DAT_EXTMEM_f145 = DAT_EXTMEM_a0b6[DAT_INTMEM_40++];
                DAT_EXTMEM_f144 = 0x40;
            } else {
                DAT_EXTMEM_f145 = DAT_EXTMEM_a0b6[DAT_INTMEM_40];
                DAT_EXTMEM_f144 = 0x40;
                DAT_INTMEM_40 = 0;
            }
            DAT_EXTMEM_f00a = 0x55;
        }
        while (DAT_EXTMEM_f143 & 0x20) {
            DAT_EXTMEM_a1a8[DAT_INTMEM_30++] = DAT_EXTMEM_f146;
            DAT_EXTMEM_f144 = 0x20;
            DAT_INTMEM_29 |= 0x40;
            if (DAT_INTMEM_30 > 0x3b) DAT_INTMEM_30 = 2;
            DAT_EXTMEM_f00a = 0x55;
        }
        if (DAT_EXTMEM_f143 & 0x10) DAT_EXTMEM_f144 = 0xff;
        if (DAT_EXTMEM_f143 & 0x08) DAT_EXTMEM_f144 = 0xff;
    }
    if ((unsigned int)(DAT_EXTMEM_f02e & 0x40)) {
        while (!(unsigned int)(DAT_EXTMEM_f0fa & 0x01)) {
            DAT_EXTMEM_a208[DAT_INTMEM_47++] = DAT_EXTMEM_f0fc;
            if (DAT_INTMEM_47 >= 0x38) DAT_INTMEM_47 = 0;
            DAT_EXTMEM_f00a = 0x55;
        }
        if ((unsigned int)(DAT_EXTMEM_f0fa & 0x10)) DAT_EXTMEM_f0fa |= 0x10;
    }
    if ((unsigned int)(DAT_EXTMEM_f02e & 0x80)) {
        while (!(unsigned int)(DAT_EXTMEM_f036 & 0x01)) {
            DAT_EXTMEM_a240[DAT_INTMEM_48++] = DAT_EXTMEM_f038;
            if (DAT_INTMEM_48 >= 0x38) DAT_INTMEM_48 = 0;
            DAT_EXTMEM_f00a = 0x55;
        }
        if ((unsigned int)(DAT_EXTMEM_f036 & 0x10)) DAT_EXTMEM_f036 |= 0x10;
    }
}
