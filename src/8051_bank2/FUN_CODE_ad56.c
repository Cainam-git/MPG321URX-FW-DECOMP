/* 8051_bank2 FUN_CODE_ad56 @ 0xad56..0xaed9 (only caller: LCALL at 0x3e5d in FUN_CODE_35a9). Returns 1 or 0.
 * LARGE locals in XDATA declaration order: v (0x08FE, the FUN_CODE_4ffa result, stored and not read again),
 * i (0x08FF), n (0x0901), sum (0x0903), j (0x0905); k stays in R6:R7. Compiled OPTIMIZE(8,SPEED) LARGE.
 * XDATA[0x014A] == 0: return 1. Otherwise the word at 0x0156 = 0, FUN_CODE_e141(XDATA ulong 0x0152, 0x200) (the
 * second argument goes to e141's parameter block 0x090B through ?C?LSTKXDATA), FUN_CODE_d4b2(0, buf) with buf =
 * XDATA 0x01E6. Then every 16th offset i < 0x200 of buf is tested for the bytes 0xAA, 0x55, 0x04 at i, i + 1, i + 2.
 * No such offset: return 1. At the first one: word 0x0156 = (buf[i + 0x10] << 8) + buf[i + 0x11];
 * n = XDATA ulong 0x0109 / 0x200; sum = 16-bit sum of all bytes of n blocks, each block j read with
 * FUN_CODE_e54b(j, buf) and summed over buf[0..0x1FF]; XDATA 0xF19A = low byte of sum, 0xF19B = high byte;
 * return 1 when sum equals word 0x0156, else 0.
 * Source form: the word at 0x0156 is built in two statements (first the high byte, then '(w << 8) + low').
 */
#include <absacc.h>
extern unsigned char xdata DAT_EXTMEM_014a;
extern unsigned int xdata DAT_EXTMEM_0156;
extern unsigned long xdata DAT_EXTMEM_0152;
extern unsigned long xdata DAT_EXTMEM_0109;
extern unsigned char xdata DAT_EXTMEM_01e6[];
unsigned char FUN_CODE_4ffa(void);
void FUN_CODE_e141(unsigned long a, unsigned long b);
void FUN_CODE_d4b2(unsigned char k, unsigned char *p);
void FUN_CODE_e54b(unsigned int off, unsigned char *buf);

unsigned char FUN_CODE_ad56(void)
{
    unsigned char v;
    unsigned int i;
    unsigned int n;
    unsigned int sum;
    unsigned int j;
    unsigned int k;
    v = FUN_CODE_4ffa();
    if (DAT_EXTMEM_014a == 0) return 1;
    DAT_EXTMEM_0156 = 0;
    FUN_CODE_e141(DAT_EXTMEM_0152, 0x200);
    FUN_CODE_d4b2(0, DAT_EXTMEM_01e6);
    for (i = 0; i < 0x200; i += 0x10) {
        if (DAT_EXTMEM_01e6[i] == 0xaa && DAT_EXTMEM_01e6[i + 1] == 0x55 && DAT_EXTMEM_01e6[i + 2] == 4) {
            DAT_EXTMEM_0156 = DAT_EXTMEM_01e6[i + 0x10];
            DAT_EXTMEM_0156 = (DAT_EXTMEM_0156 << 8) + DAT_EXTMEM_01e6[i + 0x11];
            n = DAT_EXTMEM_0109 / 0x200;
            sum = 0;
            for (j = 0; j < n; j++) {
                FUN_CODE_e54b(j, DAT_EXTMEM_01e6);
                for (k = 0; k < 0x200; k++) sum += DAT_EXTMEM_01e6[k];
            }
            XBYTE[0xF19A] = sum;
            XBYTE[0xF19B] = sum >> 8;
            if (sum == DAT_EXTMEM_0156) return 1;
            return 0;
        }
    }
    return 1;
}
