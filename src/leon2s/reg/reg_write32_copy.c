/* reg_write32_copy  (FUN_a00618cc)
 *
 * Write a 32-bit hardware register.
 *   reg: register address
 *   value
 * Note: Identical copy of reg_write32.
 * Name basis: proven - single st to the given address; used for 0xD0013Fxx
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00618cc @ 0xa00618cc (-mcpu=v8 -Os -g)
 * Same code as reg_write32.
 */
/* Store value in the 32-bit word at address reg (a hardware register). */
void reg_write32_copy(volatile unsigned int *reg, unsigned int value)
{
    *reg = value;
}
