/* usb_cc_select_port_block  (FUN_CODE_d66e)
 *
 * Point the CC register block pointer at the selected Type-C port.
 * Name basis: derived - bits 0..1 of 0xA6A5 select block 0xB250 or 0x1A50 (same selection picks the CC
 *   readings)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d66e @ 0xd66e  OPTIMIZE(7,SPEED)
 * Source form: Ghidra's symbol names are kept; the variables are declared with _at_ and the body keeps the
 * early-return form.
 */
#define CC_PTR_TYPE_BYTE  1     /* first byte of the generic pointer */
#define CC_BLOCK_PORT0_HI 0xb2  /* high byte of the register block address 0xB250 (port select 0) */
#define CC_BLOCK_PORT1_HI 0x1a  /* high byte of the register block address 0x1A50 (port select 1) */
#define CC_BLOCK_LOW      0x50  /* low byte of both addresses */

unsigned char xdata usb_c_port_info_port_select _at_ 0xa6a5;
unsigned char xdata usb_cc_block_ptr _at_ 0xa76d;
unsigned char xdata usb_cc_block_ptr_high _at_ 0xa76e;
unsigned char xdata usb_cc_block_ptr_low _at_ 0xa76f;

/*
 * Point usb_cc_block_ptr (3 bytes at XDATA 0xA76D: type byte 1, then the address) at the register block of the
 * Type-C port chosen by bits 0..1 of usb_c_port_info_port_select: 0xB250 for 0, 0x1A50 for 1. For 2 and 3
 * nothing is written.
 */
void usb_cc_select_port_block(void)

{
  if ((usb_c_port_info_port_select & 3) == 0) {
    usb_cc_block_ptr = CC_PTR_TYPE_BYTE;
    usb_cc_block_ptr_high = CC_BLOCK_PORT0_HI;
    usb_cc_block_ptr_low = CC_BLOCK_LOW;
    return;
  }
  if ((usb_c_port_info_port_select & 3) == 1) {
    usb_cc_block_ptr = CC_PTR_TYPE_BYTE;
    usb_cc_block_ptr_high = CC_BLOCK_PORT1_HI;
    usb_cc_block_ptr_low = CC_BLOCK_LOW;
  }
  return;
}
