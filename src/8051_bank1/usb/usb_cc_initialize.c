/* usb_cc_initialize  (FUN_CODE_dc92)
 *
 * Log and run the Type-C CC PHY and controller set-up.
 * Name basis: proven - prints 'USB CC Initialize'; calls the 'Initial CC PHY' routine and the CC register
 *   loaders
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dc92 @ 0xdc92  OPTIMIZE(8,SPEED)
 * Keil passes a generic pointer in R3 (memory type, 0xFF = code), R2 (high address byte) and R1 (low address byte); the
 * firmware loads R3 = 0xFF, R2 = 0xB5, R1 = 0x45, i.e. code address 0xB545.
 */
extern void lib_printf517(void *text);
extern void usb_cc_init_phy(void);
extern void usb_cc_load_config_regs(void);
extern void usb_cc_set_default_bytes(void);
extern void usb_cc_load_default_params(void);

/* Print the text at code address 0xB545, then run the Type-C CC set-up
 * steps in order: PHY, configuration registers, default bytes, default
 * parameters. Called by USBCC_Initial. */
void usb_cc_initialize(void)
{
    lib_printf517((void code *)0xffb545);
    usb_cc_init_phy();
    usb_cc_load_config_regs();
    usb_cc_set_default_bytes();
    usb_cc_load_default_params();
}
