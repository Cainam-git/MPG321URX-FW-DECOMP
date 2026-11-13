/* reg_read8_wrapper  (FUN_a00615dc)
 *
 * Read one byte of a register (out-of-line wrapper of reg_read8).
 * Name basis: derived - body only forwards to reg_read8; no direct caller (reached through a pointer or
 *   unused)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00615dc @ 0xa00615dc (-mcpu=v8 -Os -g)
 * reg_read8 is declared without a prototype and the second argument is declared but unused; both keep the
 * generated code as it is in the firmware.
 */
extern int reg_read8();

/* Return reg_read8(addr). No routine calls this wrapper. */
unsigned char reg_read8_wrapper(unsigned int addr, unsigned int unused)
{
  return reg_read8(addr);
}
