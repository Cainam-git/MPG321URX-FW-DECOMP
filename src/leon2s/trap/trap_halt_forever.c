/* trap_halt_forever  (FUN_a0061224)
 *
 * Stop the processor in an endless loop.
 * Name basis: derived - body 'for (;;);'; its only user is the unreached trap_call_halt_handler wrapper
 *
 * Matching notes
 * --------------
 * FUN_a0061224 (leon2s 0xa0061224-0xa006122c, 8 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Its address is the word at 0xa00b6080 and is also loaded by trap_call_halt_handler_part5.
 * Source form: 'for (;;) ;' compiles to 'b .' with a nop in the delay slot; with -g no return code follows.
 */
/* Endless loop: the processor stays here once it is entered. */
void trap_halt_forever(void)
{
    for (;;)
        ;
}
