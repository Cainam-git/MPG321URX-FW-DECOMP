/* irq_write_control_value  (FUN_a00de98c)
 *
 * Write 0x1000 to core register 0x9F120008.
 * Name basis: descriptive - used by the update progress loop
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de98c @ 0xa00de98c-0xa00de9a8 (7 words), flags -mcpu=v8 -O2 -g.
 * Source form: a single call as the last statement, which the compiler makes a tail call (the caller's return
 * address is handed on).
 */

#define CONTROL_REG_8      0x9f120008   /* core register in the same block as the software interrupt register 0x9F120024 */
#define CONTROL_VALUE      0x1000

extern void reg_write32(unsigned int addr, unsigned int value);

/*
 * Write 0x1000 to core register 0x9F120008.
 * Called first by fwupd_run_progress_loop.
 */
void irq_write_control_value(void)
{
  reg_write32(CONTROL_REG_8, CONTROL_VALUE);
}
