/* usb_cc_load_config_regs  (FUN_CODE_8731)
 *
 * Load the USB-C CC controller's 29 configuration registers.
 * Name basis: derived - register block at the pointer 0xA76D (USB-C block); only caller usb_cc_initialize
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_8731 @ 0x8731..0x883d (268 bytes), OPTIMIZE(8,SPEED).
 * The pointee is volatile (register block), so the double writes of 0x3D and 0x11 both stay.
 * Source form: 0x2C first in the OR chain, so Keil ORs it into the bit-4 term before the bit-7 term.
 */
extern unsigned char volatile * xdata usb_cc_block_ptr;
extern unsigned char xdata DAT_EXTMEM_a677;

/*
 * usb_cc_load_config_regs - write the fixed set-up of the selected Type-C port's register block (the block
 * usb_cc_block_ptr points to: 0xB250 or 0x1A50). Register 0x10 is 0x2C plus bit 2 of XDATA 0xA677 as bit 4
 * and bit 1 of XDATA 0xA677 as bit 7; all other values are constants, written in the firmware's order.
 * Registers 0x3D (0x0F, then 0) and 0x11 (0x47, then 0x40) are written twice. What the single registers
 * control is not shown in this program.
 * Only caller: usb_cc_initialize.
 */
void usb_cc_load_config_regs(void)
{
    usb_cc_block_ptr[0x10] = 0x2c | (((DAT_EXTMEM_a677 >> 2) & 1) << 4) | (((DAT_EXTMEM_a677 >> 1) & 1) << 7);
    usb_cc_block_ptr[0x12] = 0x8c;
    usb_cc_block_ptr[0x2f] = 0x40;
    usb_cc_block_ptr[0x20] = 0x27;
    usb_cc_block_ptr[0x23] = 0x03;
    usb_cc_block_ptr[0x26] = 0x11;
    usb_cc_block_ptr[0x28] = 0xa8;
    usb_cc_block_ptr[0x29] = 0x73;
    usb_cc_block_ptr[0x2a] = 0x21;
    usb_cc_block_ptr[0x2b] = 0x35;
    usb_cc_block_ptr[0x13] = 0x36;
    usb_cc_block_ptr[0x1f] = 0x01;
    usb_cc_block_ptr[0x1a] = 0xa3;
    usb_cc_block_ptr[0x1b] = 0x09;
    usb_cc_block_ptr[0x2d] = 0x76;
    usb_cc_block_ptr[0x2e] = 0x7a;
    usb_cc_block_ptr[0x25] = 0x01;
    usb_cc_block_ptr[0x22] = 0xf0;
    usb_cc_block_ptr[0x14] = 0x08;
    usb_cc_block_ptr[0x2c] = 0x34;
    usb_cc_block_ptr[0x3d] = 0x0f;
    usb_cc_block_ptr[0x3d] = 0x00;
    usb_cc_block_ptr[0x11] = 0x47;
    usb_cc_block_ptr[0x11] = 0x40;
    usb_cc_block_ptr[0x40] = 0xef;
    usb_cc_block_ptr[0x41] = 0xff;
    usb_cc_block_ptr[0x42] = 0xff;
    usb_cc_block_ptr[0x44] = 0xff;
    usb_cc_block_ptr[0x33] = 0x00;
}
