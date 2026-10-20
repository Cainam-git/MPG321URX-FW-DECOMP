/* 8051_bank1 FUN_CODE_a959 @ 0xa959 (157 B)  Byte-exact with OPTIMIZE(8,SPEED).
 * Works on the register block that the generic pointer DAT_EXTMEM_a76d points to (FUN_CODE_d66e sets it to XDATA
 * 0xB250 or 0x1A50 from the low bits of 0xA6A5). With bit 0x16 (BITS_22_6) set: block byte 0x0B = 0x9C and, by the
 * mode XDATA 0xA780, byte 5 = (byte 5 & 0xDF) | 0x10 (mode 0), (byte 5 & 0x7F) | 0x40 (mode 1) or
 * (byte 5 & 0x5F) | 0x50 (mode 2), each as two read-modify-writes. With the bit clear: byte 5 &= 0x0F.
 * Callers: FUN_CODE_9522 (0x9600) and code at 0xDBAB and 0xDE8F.
 * The pointee is volatile: after the AND store the firmware reads byte 5 again (?C?CLDPTR) for the OR. Keil shares
 * the final store of all four paths (SJMP to one 'LCALL ?C?CSTPTR; RET').
 */
extern unsigned char volatile * xdata DAT_EXTMEM_a76d;
extern unsigned char xdata DAT_EXTMEM_a780;
extern bit BITS_22_6;

void FUN_CODE_a959(void)
{
    if (BITS_22_6) {
        DAT_EXTMEM_a76d[0x0b] = 0x9c;
        switch (DAT_EXTMEM_a780) {
        case 0:
            DAT_EXTMEM_a76d[5] &= 0xdf;
            DAT_EXTMEM_a76d[5] |= 0x10;
            break;
        case 1:
            DAT_EXTMEM_a76d[5] &= 0x7f;
            DAT_EXTMEM_a76d[5] |= 0x40;
            break;
        case 2:
            DAT_EXTMEM_a76d[5] &= 0x5f;
            DAT_EXTMEM_a76d[5] |= 0x50;
            break;
        }
    } else {
        DAT_EXTMEM_a76d[5] &= 0x0f;
    }
}
