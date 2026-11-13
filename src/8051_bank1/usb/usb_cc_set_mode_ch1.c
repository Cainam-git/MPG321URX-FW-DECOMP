/* usb_cc_set_mode_ch1  (FUN_CODE_a9f6)
 *
 * Set the mode bits of USB-C CC channel 1 from the stored mode.
 * Note: With the channel's on-flag clear, bits 4..7 of block byte 5 are cleared: the mode bits of both
 *   channels.
 * Name basis: derived - twin of usb_cc_set_mode_ch0: register byte 0x08, mode 0xA781; callers usb_cc_init_phy,
 *   usb_cc_apply_orientation_ch1, usb_cc_init_port_mode
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_a9f6 @ 0xa9f6 (157 bytes), OPTIMIZE(8,SPEED).
 * Same shape as usb_cc_set_mode_ch0: the pointee is volatile (byte 5 is read again after the AND store); the four
 *   paths share the final store.
 */
extern unsigned char volatile * xdata usb_cc_block_ptr;
extern unsigned char xdata usb_cc_mode_ch1;
extern bit usb_cc_ch1_mode_on_flag;

#define CC_REG_MODE      5      /* block byte with the mode bits 4..7 of both channels */
#define CC_REG_CH1_08    0x08   /* block byte set to 0x66 when channel 1 gets a mode */
#define CC_MODE_KEEP     0x0f   /* channel off: bits 4..7 of CC_REG_MODE cleared */

/*
 * usb_cc_set_mode_ch1 - write the stored mode of USB-C CC channel 1 (usb_cc_mode_ch1) into the register block
 * of the selected Type-C port (usb_cc_block_ptr); twin of usb_cc_set_mode_ch0.
 * With usb_cc_ch1_mode_on_flag set: byte 0x08 = 0x66, and in byte 5 the bits of channel 1 are set by the mode:
 * mode 0 bit 5 (bit 4 cleared), mode 1 bit 7 (bit 6 cleared), mode 2 bits 5 and 7 (bits 4 and 6 cleared). Bits 4
 * and 6 are the places of channel 0. Another mode value changes only byte 0x08.
 * With the flag clear, bits 4..7 of byte 5 are cleared, those of channel 0 too.
 * Callers set the flag and the mode first: usb_cc_apply_orientation_ch1 (mode 0 or 1), usb_cc_init_phy and
 * usb_cc_init_port_mode (mode 2).
 */
void usb_cc_set_mode_ch1(void)
{
    if (usb_cc_ch1_mode_on_flag) {
        usb_cc_block_ptr[CC_REG_CH1_08] = 0x66;
        switch (usb_cc_mode_ch1) {
        case 0:
            usb_cc_block_ptr[CC_REG_MODE] &= 0xef;
            usb_cc_block_ptr[CC_REG_MODE] |= 0x20;
            break;
        case 1:
            usb_cc_block_ptr[CC_REG_MODE] &= 0xbf;
            usb_cc_block_ptr[CC_REG_MODE] |= 0x80;
            break;
        case 2:
            usb_cc_block_ptr[CC_REG_MODE] &= 0xaf;
            usb_cc_block_ptr[CC_REG_MODE] |= 0xa0;
            break;
        }
    } else {
        usb_cc_block_ptr[CC_REG_MODE] &= CC_MODE_KEEP;
    }
}
