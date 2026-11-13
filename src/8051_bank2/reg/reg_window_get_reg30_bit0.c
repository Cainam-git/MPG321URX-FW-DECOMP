/* reg_window_get_reg30_bit0  (FUN_CODE_e3f9)
 *
 * Return bit 0 of the 32-bit register 0x30.
 * Returns: 0 or 1
 * Name basis: descriptive - through the register window read
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e3f9 @ 0xe3f9, no options recorded: the default OPTIMIZE(7,SPEED).
 * Source form: the test is written (value & 1) == 1 on the unsigned long, which Keil compiles as a long compare
 * (?C?ULCMP).
 */
unsigned long reg_window_read32(unsigned int reg);

#define REG_30      0x0030  /* USB controller register, read through the register window */

/* Return 1 when bit 0 of controller register 0x30 of the current port is set, else 0.
 * fwupd_step_port_state goes back to waiting while it is clear and on to the enumeration once it is set;
 * usb_host_scan_hub_ports stops its walk over the hub ports when it is clear. */
unsigned char reg_window_get_reg30_bit0(void)
{
    if ((reg_window_read32(REG_30) & 1) == 1) return 1;
    return 0;
}
