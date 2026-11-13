/* usb_cc_set_default_bytes  (FUN_CODE_cdcd)
 *
 * Write the default values of bytes 0x48..0x4D of the USB-C CC block.
 * Name basis: descriptive - 00 08 7F 04 00 00 at the pointer 0xA76D, 0xF030 bit 2; caller usb_cc_initialize
 *
 * Matching notes
 * --------------
 * FUN_CODE_cdcd, 8051_bank1, range 0xCDCD..0xCE0D (64 B).
 * Options: OPTIMIZE(8,SPEED) (also with REGFILE(R.ORC) added).
 * Source form: each byte is stored through ?C?CSTOPTR with a DPTR offset; the pointer is loaded once into R3/R2/R1.
 */
extern unsigned char * xdata usb_cc_block_ptr;
extern unsigned char xdata DAT_EXTMEM_f030;

/*
 * Write the default values 00 08 7F 04 00 00 into bytes 0x48..0x4D of the
 * block that usb_cc_block_ptr points to, then set bit 2 of 0xF030.
 * Caller: the code at 0xDCA1.
 */
void usb_cc_set_default_bytes(void)
{
    usb_cc_block_ptr[0x48] = 0;
    usb_cc_block_ptr[0x49] = 8;
    usb_cc_block_ptr[0x4a] = 0x7f;
    usb_cc_block_ptr[0x4b] = 4;
    usb_cc_block_ptr[0x4c] = 0;
    usb_cc_block_ptr[0x4d] = 0;
    DAT_EXTMEM_f030 |= 4;
}
