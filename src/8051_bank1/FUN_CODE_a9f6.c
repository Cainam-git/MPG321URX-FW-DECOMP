/* 8051_bank1 FUN_CODE_a9f6 @ 0xa9f6 (157 B)  Byte-exact with OPTIMIZE(8,SPEED).
 * Same shape as FUN_CODE_a959 on the register block at the pointer DAT_EXTMEM_a76d, for the second channel: with
 * bit 0x17 (BITS_22_7) set: block byte 0x08 = 0x66 and, by the mode XDATA 0xA781, byte 5 = (byte 5 & 0xEF) | 0x20
 * (mode 0), (byte 5 & 0xBF) | 0x80 (mode 1) or (byte 5 & 0xAF) | 0xA0 (mode 2). With the bit clear: byte 5 &= 0x0F.
 * Callers: FUN_CODE_9522 (0x960B), FUN_CODE_d8c8 (0xD8E2) and code at 0xDBC4.
 * The pointee is volatile (byte 5 is read again after the AND store); the four paths share the final store.
 */
extern unsigned char volatile * xdata DAT_EXTMEM_a76d;
extern unsigned char xdata DAT_EXTMEM_a781;
extern bit BITS_22_7;

void FUN_CODE_a9f6(void)
{
    if (BITS_22_7) {
        DAT_EXTMEM_a76d[0x08] = 0x66;
        switch (DAT_EXTMEM_a781) {
        case 0:
            DAT_EXTMEM_a76d[5] &= 0xef;
            DAT_EXTMEM_a76d[5] |= 0x20;
            break;
        case 1:
            DAT_EXTMEM_a76d[5] &= 0xbf;
            DAT_EXTMEM_a76d[5] |= 0x80;
            break;
        case 2:
            DAT_EXTMEM_a76d[5] &= 0xaf;
            DAT_EXTMEM_a76d[5] |= 0xa0;
            break;
        }
    } else {
        DAT_EXTMEM_a76d[5] &= 0x0f;
    }
}
