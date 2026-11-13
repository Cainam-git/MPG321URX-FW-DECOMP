/* usb_cc_set_mode_ch0  (FUN_CODE_a959)
 *
 * Set the mode bits of USB-C CC channel 0 from the stored mode.
 * Note: With the channel's on-flag clear, bits 4..7 of block byte 5 are cleared: the mode bits of both
 *   channels.
 * Name basis: derived - register byte 0x0B and byte 5 of the block at the pointer 0xA76D, mode 0xA780; callers
 *   usb_cc_init_phy, usb_cc_apply_orientation_ch0, usb_cc_set_mode2_ch0
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_a959 @ 0xa959 (157 bytes), OPTIMIZE(8,SPEED).
 * The pointee of usb_cc_block_ptr is volatile: after the AND store the firmware reads byte 5 again (?C?CLDPTR) for
 *   the OR. Keil shares the final store of all four paths (SJMP to one 'LCALL ?C?CSTPTR; RET').
 */
extern unsigned char volatile * xdata usb_cc_block_ptr;
extern unsigned char xdata usb_cc_mode_ch0;
extern bit usb_cc_ch0_mode_on_flag;

#define CC_REG_MODE      5      /* block byte with the mode bits 4..7 of both channels */
#define CC_REG_CH0_0B    0x0b   /* block byte set to 0x9C when channel 0 gets a mode */
#define CC_MODE_KEEP     0x0f   /* channel off: bits 4..7 of CC_REG_MODE cleared */

/*
 * usb_cc_set_mode_ch0 - write the stored mode of USB-C CC channel 0 (usb_cc_mode_ch0) into the register block
 * of the selected Type-C port (usb_cc_block_ptr, set by usb_cc_select_port_block).
 * With usb_cc_ch0_mode_on_flag set: byte 0x0B = 0x9C, and in byte 5 the bits of channel 0 are set by the mode:
 * mode 0 bit 4 (bit 5 cleared), mode 1 bit 6 (bit 7 cleared), mode 2 bits 4 and 6 (bits 5 and 7 cleared). Bits 5
 * and 7 are the same places for channel 1 (usb_cc_set_mode_ch1). Another mode value changes only byte 0x0B.
 * With the flag clear, bits 4..7 of byte 5 are cleared, those of channel 1 too.
 * Callers set the flag and the mode first: usb_cc_apply_orientation_ch0 (mode 0 or 1 by
 * usb_cc_test_orientation_bits), usb_cc_init_phy and usb_cc_set_mode2_ch0 (mode 2).
 */
void usb_cc_set_mode_ch0(void)
{
    if (usb_cc_ch0_mode_on_flag) {
        usb_cc_block_ptr[CC_REG_CH0_0B] = 0x9c;
        switch (usb_cc_mode_ch0) {
        case 0:
            usb_cc_block_ptr[CC_REG_MODE] &= 0xdf;
            usb_cc_block_ptr[CC_REG_MODE] |= 0x10;
            break;
        case 1:
            usb_cc_block_ptr[CC_REG_MODE] &= 0x7f;
            usb_cc_block_ptr[CC_REG_MODE] |= 0x40;
            break;
        case 2:
            usb_cc_block_ptr[CC_REG_MODE] &= 0x5f;
            usb_cc_block_ptr[CC_REG_MODE] |= 0x50;
            break;
        }
    } else {
        usb_cc_block_ptr[CC_REG_MODE] &= CC_MODE_KEEP;
    }
}
