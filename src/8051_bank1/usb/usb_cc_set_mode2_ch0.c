/* usb_cc_set_mode2_ch0  (FUN_CODE_de87)
 *
 * Select mode 2 for CC channel 0 and apply it.
 * Note: Not called anywhere.
 * Name basis: descriptive - mode 0xA780 = 2 then usb_cc_set_mode_ch0, as at the end of 'Initial CC PHY'; no
 *   caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de87 @ 0xde87..0xde92 (11 bytes), OPTIMIZE(8,SPEED); the call is a tail jump
 * (LJMP usb_cc_set_mode_ch0).
 */
#define CC_MODE_2 2   /* mode value of usb_cc_mode_ch0 (0, 1 or 2), as in usb_cc_init_phy */

extern unsigned char xdata usb_cc_mode_ch0;
extern bit usb_cc_ch0_mode_on_flag;
extern void usb_cc_set_mode_ch0(void);

/*
 * Switch USB-C CC channel 0 on with mode 2 and write it to the CC registers (usb_cc_set_mode_ch0). These are the
 * same three steps usb_cc_init_phy takes for channel 0 at its end. Nothing in this program calls this routine or
 * keeps its address.
 */
void usb_cc_set_mode2_ch0(void)
{
    usb_cc_ch0_mode_on_flag = 1;
    usb_cc_mode_ch0 = CC_MODE_2;
    usb_cc_set_mode_ch0();
}
