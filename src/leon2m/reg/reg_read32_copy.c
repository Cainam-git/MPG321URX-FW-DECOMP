/* reg_read32_copy  (FUN_a00e021c)
 *
 * Return the 32-bit word at addr.
 *   addr: register address
 * Returns: word read
 * Note: Identical copy of reg_read32.
 * Name basis: proven - code: single volatile load; used for every mailbox read
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e021c @ 0xa00e021c, flags -mcpu=v8 -O2 -g. The code is the same as reg_read32 (reg_read32).
 */

/* Read the word at 'addr' through a volatile pointer. */
unsigned int reg_read32_copy(unsigned int addr)
{
    return *(volatile unsigned int *)addr;
}
