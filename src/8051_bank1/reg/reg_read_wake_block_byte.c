/* reg_read_wake_block_byte  (FUN_CODE_dd85)
 *
 * Read one register of the wake detection block.
 *   reg: register
 * Returns: register byte
 * Note: Not called anywhere.
 * Name basis: descriptive - no caller in the image
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dd85 @ 0xdd85..0xdd96 (17 bytes), OPTIMIZE(7,SPEED).
 * Source form: the base is the array symbol, then 'ptr += reg' (generic pointer, ?C?CLDPTR).
 */
extern unsigned char xdata reg_wake_block_window[];

/* Return register reg of the wake detection block (window at XDATA 0x9A00).
 *   reg: offset from the window base
 * Nothing in the bank calls it. */
unsigned char reg_read_wake_block_byte(unsigned char reg)
{
    unsigned char *ptr;
    ptr = reg_wake_block_window;
    ptr += reg;
    return *ptr;
}
