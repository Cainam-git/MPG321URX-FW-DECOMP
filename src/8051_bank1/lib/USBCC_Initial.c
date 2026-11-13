/* USBCC_Initial  (FUN_CODE_dd2f)
 *
 * Select the CC port, initialise it and log the start-up.
 * Note: Not called anywhere.
 * Name basis: proven - (original name printed: 'USBCC_Initial'); no caller in the image
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dd2f @ 0xdd2f (18 B, 0xdd2f..0xdd41), OPTIMIZE(8,SPEED).
 * The last call is a tail jump (LJMP). No LCALL, LJMP or stored address in the bank-1 image leads here.
 */
extern void lib_printf517(void *fmt, ...) large;
extern void usb_cc_select_port_block(void);
extern void usb_cc_initialize(void);
extern void usb_cc_init_port_mode(void);

/* Select the Type-C port block, run usb_cc_initialize and
 * usb_cc_init_port_mode, then print the text "USBCC_Initial" (code 0xB55A).
 * Nothing in the bank calls it. */
void USBCC_Initial(void)
{
    usb_cc_select_port_block();
    usb_cc_initialize();
    usb_cc_init_port_mode();
    lib_printf517((void code *)0xb55a);
}
