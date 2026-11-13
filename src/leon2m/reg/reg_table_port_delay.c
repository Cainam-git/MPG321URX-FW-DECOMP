/* reg_table_port_delay  (FUN_a00f2e74)
 *
 * Wait for 32 idle instructions between two table port writes.
 * Name basis: derived - nop loop
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f2e74 @ 0xa00f2e74, -mcpu=v8 -O2 -g (the section default).
 * Source form: a byte counter runs 0..0x1f with one nop per iteration (the byte counter produces the
 * 'and %o5, 0xff' mask); the nop is an explicit __asm__ statement.
 */

#define TABLE_PORT_DELAY_NOPS 0x20

/*
 * Wait for 32 nop instructions. reg_table_port_write and reg_table_port_write_second wait the same way
 * (each has its own inlined copy of this loop); nothing calls this routine.
 */
void reg_table_port_delay(void)

{
  unsigned char count;
  
  for (count = 0; count < TABLE_PORT_DELAY_NOPS; count++) __asm__("nop");
  return;
}
