/* 8051_bank1 FUN_CODE_c389 @ 0xc389 (91 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * For v < 9 only: for each selected bit of m (bit 0, 2, 3, 4) stores v in its shadow byte (XDATA 0xA763, 0xA764,
 * 0xA765, 0xA766) and puts the low nibble of v into the low nibble of the matching register (0xF054, 0xF0F6,
 * 0xF032, 0xF06E). m is copied to R4. Callers: FUN_CODE_a775 (0xA7E8) and FUN_CODE_dcf6 (0xDD06).
 * The last block works on a copy of v in R7 ('MOV R7,AR5'): written with '(char)v', which places the converted
 * value in a temporary register; the first three blocks use v from R5 directly.
 */
extern unsigned char xdata DAT_EXTMEM_a763, DAT_EXTMEM_a764, DAT_EXTMEM_a765, DAT_EXTMEM_a766;
extern unsigned char xdata DAT_EXTMEM_f054, DAT_EXTMEM_f0f6, DAT_EXTMEM_f032, DAT_EXTMEM_f06e;

void FUN_CODE_c389(unsigned char m, unsigned char v)
{
    if (v < 9) {
        if (m & 0x01) { DAT_EXTMEM_a763 = v; DAT_EXTMEM_f054 = (DAT_EXTMEM_f054 & 0xf0) | (v & 0x0f); }
        if (m & 0x04) { DAT_EXTMEM_a764 = v; DAT_EXTMEM_f0f6 = (DAT_EXTMEM_f0f6 & 0xf0) | (v & 0x0f); }
        if (m & 0x08) { DAT_EXTMEM_a765 = v; DAT_EXTMEM_f032 = (DAT_EXTMEM_f032 & 0xf0) | (v & 0x0f); }
        if (m & 0x10) { DAT_EXTMEM_a766 = (char)v; DAT_EXTMEM_f06e = (DAT_EXTMEM_f06e & 0xf0) | ((char)v & 0x0f); }
    }
}
