/* usb_cc_set_control_bit0  (FUN_CODE_d4e1)
 *
 * Set or clear bit 0 of control byte 0x10 in the Type-C CC block.
 *   on: 1 set, 0 clear
 * Name basis: descriptive - CC register block pointer 0xA76D
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d4e1 @ 0xd4e1
 * Byte-exact with OPTIMIZE(8,SPEED) (also LARGE). The access goes through the generic pointer at XDATA 0xA76D
 * (?C?CLDPTR / ?C?CSTPTR; the store is the shared, cross-jumped tail).
 */
#define CC_CONTROL_BYTE   0x10  /* offset of the control byte in the Type-C port register block */
#define CC_CONTROL_BIT0   0x01

extern unsigned char * xdata usb_cc_block_ptr;

/*
 * Set (on != 0) or clear bit 0 of the control byte (offset 0x10) of the selected Type-C port's register block
 * (pointer usb_cc_block_ptr, chosen by usb_cc_select_port_block). Only caller: usb_cc_init_port_mode.
 */
void usb_cc_set_control_bit0(unsigned char on)
{
    if (on) usb_cc_block_ptr[CC_CONTROL_BYTE] |= CC_CONTROL_BIT0;
    else usb_cc_block_ptr[CC_CONTROL_BYTE] &= 0xfe;
}
