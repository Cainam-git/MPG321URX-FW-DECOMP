/* 8051_bank1 FUN_CODE_c59a @ 0xc59a (86 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Sets bit 7 of one XDATA register per set bit of m (bit 0 -> 0xF01C, 1 -> 0xF01E, 2 -> 0xF085, 3 -> 0xF087,
 * 4 -> 0xF099, 5 -> 0xF0A3, 6 -> 0xF076; the same registers as FUN_CODE_c87f). m is copied to R3.
 * Only caller: the command switch FUN_CODE_224f, command 1 (after FUN_CODE_abc4).
 * The firmware tests bits 0..3, 5 and 6 with 'ANL A,#n / JZ' (an int-typed test, '(unsigned int)(m & n)') and
 * bit 4 with 'JNB ACC.4' (a plain 'm & 0x10' test).
 */
extern unsigned char xdata DAT_EXTMEM_f01c, DAT_EXTMEM_f01e, DAT_EXTMEM_f085, DAT_EXTMEM_f087;
extern unsigned char xdata DAT_EXTMEM_f099, DAT_EXTMEM_f0a3, DAT_EXTMEM_f076;

void FUN_CODE_c59a(unsigned char m)
{
    if ((unsigned int)(m & 0x01)) DAT_EXTMEM_f01c |= 0x80;
    if ((unsigned int)(m & 0x02)) DAT_EXTMEM_f01e |= 0x80;
    if ((unsigned int)(m & 0x04)) DAT_EXTMEM_f085 |= 0x80;
    if ((unsigned int)(m & 0x08)) DAT_EXTMEM_f087 |= 0x80;
    if (m & 0x10) DAT_EXTMEM_f099 |= 0x80;
    if ((unsigned int)(m & 0x20)) DAT_EXTMEM_f0a3 |= 0x80;
    if ((unsigned int)(m & 0x40)) DAT_EXTMEM_f076 |= 0x80;
}
