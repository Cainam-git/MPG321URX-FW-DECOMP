/* reg_write32  (FUN_a0061534)
 *
 * Write a 32-bit hardware register.
 *   reg: register address
 *   value
 * Name basis: proven - single st to the given address; used for 0xD0013Fxx
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0061534 @ 0xa0061534 (-mcpu=v8 -Os -g)
 * The volatile pointer keeps the st ahead of retl / nop; without it GCC 3.4 -Os places the st in the retl delay
 * slot.
 */
/* Store value in the 32-bit word at address reg (a hardware register). */
void reg_write32(volatile unsigned int *reg, unsigned int value)
{
    *reg = value;
}
