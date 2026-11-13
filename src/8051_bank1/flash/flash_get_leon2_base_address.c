/* flash_get_leon2_base_address  (FUN_CODE_dde5)
 *
 * Return the LEON flash window base saved during start-up.
 * Returns: base address
 * Name basis: derived - value stored by the start-up copy startup_load_core_images, passed to
 *   FE2P_SetLeon2BaseAddress
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dde5 @ 0xdde5  OPTIMIZE(7,SPEED)
 * Same code as FUN_CODE_e4e9 with other addresses and constants.
 */
extern unsigned long xdata flash_leon2_base_address;

/* Return the 32-bit value at flash_leon2_base_address (the LEON flash
 * window base saved at the end of start-up). */
unsigned long flash_get_leon2_base_address(void)
{
    return flash_leon2_base_address;
}
