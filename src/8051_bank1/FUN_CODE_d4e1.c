/* 8051_bank1 FUN_CODE_d4e1 @ 0xd4e1 (mechanical draft at 38.6 %, finished by hand)
 * Sets (on != 0) or clears bit 0 of byte 0x10 of the record pointed to by the generic pointer at XDATA 0xA76D
 * (?C?CLDPTR / ?C?CSTPTR; the store is the shared, cross-jumped tail). Only caller 0xd8e7.
 * Byte-exact with OPTIMIZE(8,SPEED) (also LARGE).
 */
extern unsigned char * xdata DAT_EXTMEM_a76d;
void FUN_CODE_d4e1(unsigned char on)
{
    if (on) DAT_EXTMEM_a76d[0x10] |= 0x01;
    else DAT_EXTMEM_a76d[0x10] &= 0xfe;
}
