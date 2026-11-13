/* reg_write_wake_block_word  (FUN_CODE_dae3)
 *
 * Write a 16-bit value into two registers of the wake detection block.
 *   reg: low register
 *   value
 * Note: Not called anywhere.
 * Name basis: descriptive - low byte first; no caller in the image
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dae3 @ 0xdae3..0xdafe (27 B)
 * Options: OPTIMIZE(8,SPEED).
 * Source form: 'ptr += reg & 0xff' loads reg into A first (MOV A,R7 / ADD A,R1); 'ptr += reg' gives MOV A,R1 / ADD A,R7.
 */
#define WAKE_BLOCK_BASE 0x9a00   /* register window of the wake detection block */

/* Write a 16-bit value into two consecutive registers of the wake detection
 * block, low byte first.
 *   reg:   number of the first register (offset from the block base)
 *   value: 16-bit value
 * Nothing in the bank calls it. */
void reg_write_wake_block_word(unsigned char reg, unsigned int value)
{
    unsigned char *ptr;

    ptr = (unsigned char xdata *)WAKE_BLOCK_BASE;
    ptr += reg & 0xff;
    *ptr = value;
    ptr++;
    *ptr = value >> 8;
}
