/* usb_cc_apply_orientation_ch0  (FUN_CODE_db96)
 *
 * Store the plug orientation as mode of CC channel 0 and apply it.
 * Note: Not called anywhere.
 * Name basis: descriptive - mode 0xA780 from usb_cc_test_orientation_bits, then usb_cc_set_mode_ch0; no caller
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_db96 @ 0xdb96 (25 B)
 * Options: OPTIMIZE(8,SPEED).
 * Source form: the call is written in both arms; Keil then shares the tail 'MOVX @DPTR,A / LCALL / RET' of the
 * two arms (SJMP from the first) and keeps LCALL + RET instead of a tail LJMP.
 */
extern unsigned char xdata usb_cc_mode_ch0;
extern bit usb_cc_ch0_mode_on_flag;
extern unsigned char usb_cc_test_orientation_bits(void);
extern void usb_cc_set_mode_ch0(void);

/* Set flag bit 0x16, store 1 in the mode of CC channel 0 when
 * usb_cc_test_orientation_bits returns non-zero (else 0), then call
 * usb_cc_set_mode_ch0, which reads the flag and the mode. Nothing in the
 * bank calls it. */
void usb_cc_apply_orientation_ch0(void)
{
    if (!usb_cc_test_orientation_bits()) {
        usb_cc_ch0_mode_on_flag = 1;
        usb_cc_mode_ch0 = 0;
        usb_cc_set_mode_ch0();
    } else {
        usb_cc_ch0_mode_on_flag = 1;
        usb_cc_mode_ch0 = 1;
        usb_cc_set_mode_ch0();
    }
}
