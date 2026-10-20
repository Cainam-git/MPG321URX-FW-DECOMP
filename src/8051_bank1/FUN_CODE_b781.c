/* 8051_bank1 FUN_CODE_b781 @ 0xb781..0xb802 (129 bytes)
 * MATCH: tools/diff8051.py 8051_bank1 FUN_CODE_b781 -> 129/129 bytes at OPTIMIZE(8,SPEED) LARGE.
 * Reads 4 blocks of 512 bytes from XDATA 0xA800 upwards through a generic pointer. For each block it forms the 8-bit
 * sum of its bytes and shifts the 32-bit result left by (sum + 8) (?C?LSHL, count in R0); returns the result in R4..R7.
 * LARGE locals (XDATA): i 0xA4B3, sum 0xA4B4, r 0xA4B5..0xA4B8 (cleared by ?C?LSTKXDATA with the inline constant 0),
 * p 0xA4B9..0xA4BB (generic pointer 0x01:0xA800, advanced by ?C?ILDIX); the 512-count j is a register pair (R6:R7).
 * Callers (code): LCALL at 0x21B0 (range 0x1D0C..0x224F, no functions.json entry) and at 0x2448 (FUN_CODE_224f).
 */
extern unsigned char xdata DAT_EXTMEM_a800[];

unsigned long FUN_CODE_b781(void)
{
    unsigned char i;
    unsigned char sum;
    unsigned long r;
    unsigned char *p;
    unsigned int j;

    r = 0;
    p = DAT_EXTMEM_a800;
    for (i = 0; i != 4; i++) {
        sum = 0;
        for (j = 0; j != 0x200; j++) {
            sum += *p++;
        }
        r = r << (sum + 8);
    }
    return r;
}
