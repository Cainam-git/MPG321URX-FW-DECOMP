/* 8051_bank2 FUN_CODE_9734 @ 0x9734..0x9981 (589 bytes)
 * Options: OPTIMIZE(8,SPEED) LARGE. Only caller: the tail LJMP at 0xE448, with a = XDATA 0x0401..0x0404.
 * Parameter a (unsigned long, XDATA 0x08EC) and locals b (unsigned long, 0x08F0), n (0x08F4), i (0x08F6), m (0x08F8).
 * b = the big-endian 32-bit value at XDATA 0xF19A..0xF19D, shifted left by 5; n = the big-endian 16-bit value at
 * 0xF19E..0xF19F; m = 0x5000. For i = 0 .. n - 1: XDATA 0xF194 = i * 255 / n (?C?LIMUL, ?C?ULDIV), FUN_CODE_e1eb(),
 * then the record at XDATA 0x0761: [2] = 0x2A, [3] = 8, [4..7] = a (most significant byte first), [10] = m >> 9,
 * [0] = 0x0A, [1] = 1, and the unsigned long at 0x0773 = m; then FUN_CODE_768a(b). When FUN_CODE_e4c9() returns
 * non-zero it calls FUN_CODE_e4d9(), FUN_CODE_b706() and FUN_CODE_467e() and repeats the same i; otherwise
 * a += m >> 9, b += m, i++.
 * Source forms the bytes depend on: the record at 0x0761 is one array (INC DPTR between [0]/[1] and [2]/[3]);
 * m is a local, not a constant; the loop is a while loop whose retry path is 'continue' before the increments.
 */
extern unsigned char xdata DAT_EXTMEM_f19a, DAT_EXTMEM_f19b, DAT_EXTMEM_f19c, DAT_EXTMEM_f19d, DAT_EXTMEM_f19e, DAT_EXTMEM_f19f;
extern unsigned char xdata DAT_EXTMEM_f194;
extern unsigned char xdata DAT_EXTMEM_0761[];
extern unsigned long xdata DAT_EXTMEM_0773;
void FUN_CODE_e1eb(void);
void FUN_CODE_768a(unsigned long b);
unsigned char FUN_CODE_e4c9(void);
void FUN_CODE_e4d9(void);
void FUN_CODE_b706(void);
void FUN_CODE_467e(void);

void FUN_CODE_9734(unsigned long a)
{
    unsigned long b;
    unsigned int n;
    unsigned int i;
    unsigned int m;
    b = DAT_EXTMEM_f19a;
    b = (b << 8) + DAT_EXTMEM_f19b;
    b = (b << 8) + DAT_EXTMEM_f19c;
    b = (b << 8) + DAT_EXTMEM_f19d;
    b <<= 5;
    n = DAT_EXTMEM_f19e;
    n = (n << 8) + DAT_EXTMEM_f19f;
    m = 0x5000;
    i = 0;
    while (i < n) {
        DAT_EXTMEM_f194 = (unsigned long)i * 0xff / n;
        FUN_CODE_e1eb();
        DAT_EXTMEM_0761[2] = 0x2a;
        DAT_EXTMEM_0761[3] = 8;
        DAT_EXTMEM_0761[4] = a >> 24;
        DAT_EXTMEM_0761[5] = a >> 16;
        DAT_EXTMEM_0761[6] = a >> 8;
        DAT_EXTMEM_0761[7] = a;
        DAT_EXTMEM_0761[10] = m >> 9;
        DAT_EXTMEM_0761[0] = 0x0a;
        DAT_EXTMEM_0761[1] = 1;
        DAT_EXTMEM_0773 = m;
        FUN_CODE_768a(b);
        if (FUN_CODE_e4c9()) {
            FUN_CODE_e4d9();
            FUN_CODE_b706();
            FUN_CODE_467e();
            continue;
        }
        a += m >> 9;
        b += m;
        i++;
    }
}
