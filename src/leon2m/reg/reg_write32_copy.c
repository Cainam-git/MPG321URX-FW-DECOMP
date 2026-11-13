/* reg_write32_copy  (FUN_a00e0228)
 *
 * Store a 32-bit value at addr.
 *   addr: register address
 *   value: word to write
 * Note: Identical copy of reg_write32.
 * Name basis: proven - code: single volatile store
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0228 @ 0xa00e0228, flags -mcpu=v8 -O2 -g. The code is the same as reg_write32 (reg_write32).
 */

/* Store 'value' at 'addr' through a volatile pointer. */
void reg_write32_copy(unsigned int addr, unsigned int value)
{
    *(volatile unsigned int *)addr = value;
}
