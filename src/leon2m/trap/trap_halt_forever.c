/* trap_halt_forever  (FUN_a002a878)
 *
 * Loop forever (halt)
 * Note: Entry 16 of handler table 0xA8027B50 and the call target of trap_enter_halt_loop.
 * Name basis: proven - code is an endless empty loop
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002a878 @ 0xa002a878, flags -mcpu=v8 -O2 -g (the section default).
 */

/*
 * Stop here for good: an empty endless loop. Its address is entry 16 of the interrupt level table (the word
 * after the 15 level routines and irq_empty_handler), and trap_enter_halt_loop calls it.
 */
void trap_halt_forever(void)
{
  do {
  } while (1);
}