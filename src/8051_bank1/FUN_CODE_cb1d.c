/* 8051_bank1 FUN_CODE_cb1d @ 0xcb1d (72 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * Reads mailbox word 0xB8 into the long at XDATA 0xA4B3 (FUN_CODE_a4e9, one word), replaces its low byte with 2,
 * writes the long back to word 0xB8 (FUN_CODE_b228, one word) and reads word 0xB8 into 0xA4B3 again.
 * Callers: the command switch FUN_CODE_224f (five calls, after FUN_CODE_c163 returned 1).
 * The low-byte replacement is the 32-bit expression '(x & 0xffffff00) | 2' (bytes 0..2 loaded, byte 3 = 2, stored
 * with ?C?LSTXDATA); the third argument of both callees is passed in their XDATA parameter blocks.
 */
extern unsigned long xdata DAT_EXTMEM_a4b3;
void FUN_CODE_a4e9(unsigned char off, unsigned long *dst, unsigned char n);
void FUN_CODE_b228(unsigned char off, unsigned long *src, unsigned char n);

void FUN_CODE_cb1d(void)
{
    FUN_CODE_a4e9(0xb8, &DAT_EXTMEM_a4b3, 1);
    DAT_EXTMEM_a4b3 = (DAT_EXTMEM_a4b3 & 0xffffff00) | 2;
    FUN_CODE_b228(0xb8, &DAT_EXTMEM_a4b3, 1);
    FUN_CODE_a4e9(0xb8, &DAT_EXTMEM_a4b3, 1);
}
