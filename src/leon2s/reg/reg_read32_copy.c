/* reg_read32_copy  (FUN_a00618c0)
 *
 * Read a 32-bit hardware register.
 *   reg: register address
 * Returns: register value
 * Note: Identical copy of reg_read32.
 * Name basis: proven - single ld from the given address; used for 0xD0013Fxx
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00618c0 @ 0xa00618c0 (-mcpu=v8 -Os -g)
 * ld; retl; nop. The pointer is declared volatile. Same code as reg_read32.
 */
/* Return the 32-bit word at address reg (a hardware register). */
unsigned int reg_read32_copy(volatile unsigned int *reg)
{
    return *reg;
}
