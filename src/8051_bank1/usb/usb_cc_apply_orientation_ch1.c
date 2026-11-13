/* usb_cc_apply_orientation_ch1  (FUN_CODE_dbaf)
 *
 * Store the plug orientation as mode of CC channel 1 and apply it.
 * Note: Not called anywhere.
 * Name basis: descriptive - twin of usb_cc_apply_orientation_ch0 with mode 0xA781 and usb_cc_set_mode_ch1; no
 *   caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dbaf @ 0xdbaf (25 B)
 * Options: OPTIMIZE(8,SPEED).
 * Source form: the call is written in both arms; Keil then shares the tail 'MOVX @DPTR,A / LCALL / RET' of the
 * two arms (SJMP from the first) and keeps LCALL + RET instead of a tail LJMP.
 */
extern unsigned char xdata usb_cc_mode_ch1;
extern bit usb_cc_ch1_mode_on_flag;
extern unsigned char usb_cc_test_orientation_bits(void);
extern void usb_cc_set_mode_ch1(void);

/* Channel 1 twin of usb_cc_apply_orientation_ch0: set flag bit 0x17, store
 * 1 or 0 in the mode of CC channel 1 as the orientation test returns
 * non-zero or zero, then call usb_cc_set_mode_ch1. Nothing in the bank
 * calls it. */
void usb_cc_apply_orientation_ch1(void)
{
    if (!usb_cc_test_orientation_bits()) {
        usb_cc_ch1_mode_on_flag = 1;
        usb_cc_mode_ch1 = 0;
        usb_cc_set_mode_ch1();
    } else {
        usb_cc_ch1_mode_on_flag = 1;
        usb_cc_mode_ch1 = 1;
        usb_cc_set_mode_ch1();
    }
}
