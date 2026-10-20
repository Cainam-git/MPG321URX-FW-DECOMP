/* 8051_bank2 FUN_CODE_d64c @ 0xd64c (133 B).
 * Callers (byte scan, xref.py): FUN_CODE_8437 (0x8476, 0x8504, 0x85ac, 0x85c3, 0x86f4; declared there as
 * `extern unsigned long FUN_CODE_d64c(unsigned char j)`).
 * Code: read the little-endian unsigned long at index j of the 32-byte record image XDATA 0x06F7 (bytes j+3 down to
 * j, each step ?C?LSHL FUN_CODE_3451 by 8 then OR). Inverse of FUN_CODE_d8c4. LARGE parameter j (0x08F6, stored and
 * re-read per byte). One expression. Own segment, not one of the 8437 module's common-entry members. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_06f7[32];
unsigned long FUN_CODE_d64c(unsigned char j)
{
    return ((((unsigned long)DAT_EXTMEM_06f7[j + 3] << 8 | DAT_EXTMEM_06f7[j + 2]) << 8
             | DAT_EXTMEM_06f7[j + 1]) << 8) | DAT_EXTMEM_06f7[j];
}
