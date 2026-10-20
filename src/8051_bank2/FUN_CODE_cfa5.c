/* 8051_bank2 FUN_CODE_cfa5 @ 0xcfa5..0xd059 (180 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE over 0xCFA5..0xD059.
 * Builds the 32-bit value a:b:c:d (a = most significant byte) in the long at XDATA 0x08C9, one byte per step:
 * 0x08C9 = a, then three times 0x08C9 = (0x08C9 << 8) + next byte (?C?LSHL by 8, ?C?LSTXDATA store).
 * LARGE parameter block at XDATA 0x08EE: b and c arrive in R5 / R3 and are stored at 0x08EF / 0x08F0 at entry, the
 * fourth parameter d does not fit in registers and is passed in its slot 0x08F1. Caller at 0xA3DC.
 */
extern unsigned long xdata DAT_EXTMEM_08c9;

void FUN_CODE_cfa5(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    DAT_EXTMEM_08c9 = a;
    DAT_EXTMEM_08c9 = (DAT_EXTMEM_08c9 << 8) + b;
    DAT_EXTMEM_08c9 = (DAT_EXTMEM_08c9 << 8) + c;
    DAT_EXTMEM_08c9 = (DAT_EXTMEM_08c9 << 8) + d;
}
