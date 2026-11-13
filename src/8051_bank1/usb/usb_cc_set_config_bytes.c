/* usb_cc_set_config_bytes  (FUN_CODE_ca44)
 *
 * Write bytes 0x38..0x3A of the USB-C CC register block.
 *   byte38_bits: bits ORed into byte 0x38 after its low nibble is kept
 *   byte39_bits: bits ORed into byte 0x39 together with the high byte of the word
 *   word: high byte goes to byte 0x39, low byte to byte 0x3A
 * Name basis: descriptive - block at the pointer 0xA76D; caller usb_cc_load_default_params
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_ca44 @ 0xca44 (73 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * LARGE: 'byte39_bits' goes to its XDATA parameter slot 0xA783 because R5 is reused for the low byte of 'word'.
 * Source form: the last value must be 'word & 0xff'; a plain or (unsigned char) conversion loads A after DPTR
 * instead of before.
 */
extern unsigned char * xdata usb_cc_block_ptr;

/*
 * Write bytes 0x38, 0x39 and 0x3A of the block that usb_cc_block_ptr points
 * to. Byte 0x38 keeps its low nibble and gets byte38_bits ORed in; byte 0x39
 * = high byte of word | byte39_bits; byte 0x3A = low byte of word.
 * Only caller: usb_cc_load_default_params (five calls).
 */
void usb_cc_set_config_bytes(unsigned char byte38_bits, unsigned char byte39_bits, unsigned int word)
{
    usb_cc_block_ptr[0x38] &= 0x0f;
    usb_cc_block_ptr[0x38] |= byte38_bits;
    usb_cc_block_ptr[0x39] = (word >> 8) | byte39_bits;
    usb_cc_block_ptr[0x3a] = word & 0xff;
}
