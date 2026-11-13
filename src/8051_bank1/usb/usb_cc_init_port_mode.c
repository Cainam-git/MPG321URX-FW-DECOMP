/* usb_cc_init_port_mode  (FUN_CODE_d8c8)
 *
 * Choose the start-up mode of the Type-C CC controller and apply it.
 * Name basis: descriptive - step of USBCC_Initial; mode byte 0xA66E = 0x20 or 0x10 by status 0xA6A6, then
 *   usb_cc_set_control_bit0(0)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d8c8 @ 0xd8c8  OPTIMIZE(8,SPEED)
 */
#define CC_CHANNEL0_START 1  /* value of usb_cc_channel_select that starts channel 0 */

extern unsigned char xdata usb_cc_channel_select;
extern unsigned char xdata DAT_EXTMEM_a66e;
extern unsigned char xdata usb_cc_mode_ch1;
extern bit usb_cc_ch1_mode_on_flag;
void usb_cc_set_mode_ch1(void);
void usb_cc_set_control_bit0(unsigned char);

/*
 * Start-up step of the Type-C CC controller. When usb_cc_channel_select is 1, write 0x20 to XDATA 0xA66E.
 * Otherwise write 0x10 there, mark the stored mode of channel 1 as applied, set that mode to 2 and apply it
 * (usb_cc_set_mode_ch1). Both paths end by clearing bit 0 of the control byte of the CC block.
 */
void usb_cc_init_port_mode(void)
{
    if (usb_cc_channel_select == CC_CHANNEL0_START)
    {
        DAT_EXTMEM_a66e = 0x20;
    }
    else
    {
        DAT_EXTMEM_a66e = 0x10;
        usb_cc_ch1_mode_on_flag = 1;
        usb_cc_mode_ch1 = 0x02;
        usb_cc_set_mode_ch1();
    }
    usb_cc_set_control_bit0(0);
}
