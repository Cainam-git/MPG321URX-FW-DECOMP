/* reg_read32  (FUN_a0061528)
 *
 * Read a 32-bit hardware register.
 *   reg: register address
 * Returns: register value
 * Name basis: proven - single ld from the given address; used for 0xD0013Fxx
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0061528 @ 0xa0061528 (-mcpu=v8 -Os -g)
 * Same code as reg_read32_copy (reg_read32_copy).
 */
/* Return the 32-bit word at address reg (a hardware register). */
unsigned int reg_read32(volatile unsigned int *reg)
{
    return *reg;
}
