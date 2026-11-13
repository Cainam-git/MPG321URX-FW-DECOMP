/* reg_read_wake_block_word  (FUN_CODE_d9e1)
 *
 * Read a 16-bit value from two registers of the wake detection block.
 *   reg: low register
 * Returns: 16-bit value
 * Note: Not called anywhere.
 * Name basis: descriptive - low byte first; no caller in the image
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d9e1 @ 0xD9E1..0xD9FF (30 bytes).
 * Both bytes are read through a generic pointer (Keil ?C?CLDPTR). No aids.
 */
extern unsigned char xdata reg_wake_block_window[];

/*
 * Read a 16-bit value from the wake detection block: low byte at register 'reg', high byte at 'reg' + 1.
 * Nothing in the image calls this routine.
 */
unsigned int reg_read_wake_block_word(unsigned char reg)
{
    unsigned char *reg_ptr;
    unsigned char lo, hi;

    reg_ptr = reg_wake_block_window;
    reg_ptr += reg;
    lo = *reg_ptr;
    reg_ptr++;
    hi = *reg_ptr;
    return ((unsigned int)hi << 8) | lo;
}
