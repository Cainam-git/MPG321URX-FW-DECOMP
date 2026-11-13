/* sys_lookup_clock_factor  (FUN_CODE_de20)
 *
 * Return the timing factor for a clock divider setting from a table.
 *   param_1: divider setting
 * Returns: factor
 * Note: Runs in register bank 3 (interrupt context).
 * Name basis: descriptive - CODE table 0xDC89 indexed by the divider bits of reg 0xD929
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de20 @ 0xde20  OPTIMIZE(7,SPEED)
 * `using 3` selects register bank 3 (PSW value 0x18).
 */
extern unsigned char code sys_clock_factor_table[];

/* Return entry clock_select of sys_clock_factor_table (the factor per
 * clock select value, used to scale timings). The routine uses register
 * bank 3.
 *   clock_select: table index */
unsigned char sys_lookup_clock_factor(unsigned char clock_select) using 3 {
    return sys_clock_factor_table[clock_select];
}
