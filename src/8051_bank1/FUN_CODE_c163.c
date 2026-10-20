/* 8051_bank1 FUN_CODE_c163 @ 0xc163 (94 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Polls mailbox word 0xB8 (FUN_CODE_a4e9 reads one word into the long at XDATA 0xA4B3) up to 20000 times until its
 * low byte (XDATA 0xA4B6) is 1. Returns 1 when it became 1, 0 after 20000 reads.
 * Callers: the command switch FUN_CODE_224f (five calls: the flash-job commands run their job only when it returns 1,
 * then call FUN_CODE_cb1d).
 * LARGE: the counter i lives in XDATA 0xA4B7..0xA4B8; the low-byte test '(x & 0xff) == 1' is a 32-bit compare
 * (?C?ULCMP) of the zero-extended byte.
 */
extern unsigned long xdata DAT_EXTMEM_a4b3;
void FUN_CODE_a4e9(unsigned char off, unsigned long *dst, unsigned char n);

unsigned char FUN_CODE_c163(void)
{
    unsigned int i;

    for (i = 0; i < 20000; i++) {
        FUN_CODE_a4e9(0xb8, &DAT_EXTMEM_a4b3, 1);
        if ((DAT_EXTMEM_a4b3 & 0xff) == 1) break;
    }
    if (i == 20000) return 0;
    return 1;
}
