/* 8051_bank1 FUN_CODE_8731 @ 0x8731..0x883d (268 bytes), OPTIMIZE(8,SPEED).
 * Writes 29 bytes into the register block that the generic pointer at XDATA 0xA76D points to (?C?CSTOPTR with the
 * offset in DPTR, last one as tail jump): byte 0x10 = 0x2C | (bit 2 of XDATA 0xA677) << 4 | (bit 1 of 0xA677) << 7,
 * then the constants below in the firmware's order (bytes 0x3D and 0x11 are written twice).
 * The pointee is volatile as in FUN_CODE_a959 (register block).
 * Source form: 0x2C first in the OR chain, so Keil ORs it into the bit-4 term before the bit-7 term.
 * Caller: FUN_CODE_dc92 (LCALL at 0xDC9E).
 */
extern unsigned char volatile * xdata DAT_EXTMEM_a76d;
extern unsigned char xdata DAT_EXTMEM_a677;

void FUN_CODE_8731(void)
{
    DAT_EXTMEM_a76d[0x10] = 0x2c | (((DAT_EXTMEM_a677 >> 2) & 1) << 4) | (((DAT_EXTMEM_a677 >> 1) & 1) << 7);
    DAT_EXTMEM_a76d[0x12] = 0x8c;
    DAT_EXTMEM_a76d[0x2f] = 0x40;
    DAT_EXTMEM_a76d[0x20] = 0x27;
    DAT_EXTMEM_a76d[0x23] = 0x03;
    DAT_EXTMEM_a76d[0x26] = 0x11;
    DAT_EXTMEM_a76d[0x28] = 0xa8;
    DAT_EXTMEM_a76d[0x29] = 0x73;
    DAT_EXTMEM_a76d[0x2a] = 0x21;
    DAT_EXTMEM_a76d[0x2b] = 0x35;
    DAT_EXTMEM_a76d[0x13] = 0x36;
    DAT_EXTMEM_a76d[0x1f] = 0x01;
    DAT_EXTMEM_a76d[0x1a] = 0xa3;
    DAT_EXTMEM_a76d[0x1b] = 0x09;
    DAT_EXTMEM_a76d[0x2d] = 0x76;
    DAT_EXTMEM_a76d[0x2e] = 0x7a;
    DAT_EXTMEM_a76d[0x25] = 0x01;
    DAT_EXTMEM_a76d[0x22] = 0xf0;
    DAT_EXTMEM_a76d[0x14] = 0x08;
    DAT_EXTMEM_a76d[0x2c] = 0x34;
    DAT_EXTMEM_a76d[0x3d] = 0x0f;
    DAT_EXTMEM_a76d[0x3d] = 0x00;
    DAT_EXTMEM_a76d[0x11] = 0x47;
    DAT_EXTMEM_a76d[0x11] = 0x40;
    DAT_EXTMEM_a76d[0x40] = 0xef;
    DAT_EXTMEM_a76d[0x41] = 0xff;
    DAT_EXTMEM_a76d[0x42] = 0xff;
    DAT_EXTMEM_a76d[0x44] = 0xff;
    DAT_EXTMEM_a76d[0x33] = 0x00;
}
