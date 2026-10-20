/* 8051_bank2 FUN_CODE_d8c4 @ 0xd8c4 (116 B).
 * Callers (byte scan, xref.py): FUN_CODE_8437 (0x84ff, 0x8618; declared there as
 * `extern void FUN_CODE_d8c4(unsigned char j, unsigned long v)`).
 * Code: store v little-endian into the 32-byte record image XDATA 0x06F7 at index j: [j] = v, [j+1] = v >> 8,
 * [j+2] = v >> 16, [j+3] = v >> 24 (?C?ULSHR FUN_CODE_343e). j stays in R3; v is read from its LARGE parameter home
 * 0x08F7..0x08FA (the caller stores it there; it is not passed in registers).
 * Own segment, not one of the 8437 module's common-entry members. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_06f7[32];
void FUN_CODE_d8c4(unsigned char j, unsigned long v)
{
    DAT_EXTMEM_06f7[j] = v;
    DAT_EXTMEM_06f7[j + 1] = v >> 8;
    DAT_EXTMEM_06f7[j + 2] = v >> 16;
    DAT_EXTMEM_06f7[j + 3] = v >> 24;
}
