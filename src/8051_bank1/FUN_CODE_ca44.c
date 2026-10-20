/* 8051_bank1 FUN_CODE_ca44 @ 0xca44 (73 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Writes three bytes of the structure that the generic pointer DAT_EXTMEM_a76d points to: byte 0x38 keeps its low
 * nibble and gets a ORed in (two read-modify-writes), byte 0x39 = (c >> 8) | b, byte 0x3A = low byte of c.
 * Only caller FUN_CODE_d13a (five calls).
 * LARGE: b goes to its XDATA parameter slot 0xA783 because R5 is reused for the low byte of c (R2:R3 -> R4:R5).
 * The last value must be 'c & 0xff': a plain or (unsigned char) conversion loads A after DPTR instead of before.
 */
extern unsigned char * xdata DAT_EXTMEM_a76d;

void FUN_CODE_ca44(unsigned char a, unsigned char b, unsigned int c)
{
    DAT_EXTMEM_a76d[0x38] &= 0x0f;
    DAT_EXTMEM_a76d[0x38] |= a;
    DAT_EXTMEM_a76d[0x39] = (c >> 8) | b;
    DAT_EXTMEM_a76d[0x3a] = c & 0xff;
}
