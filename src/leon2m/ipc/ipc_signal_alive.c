/* ipc_signal_alive  (FUN_a002ced8)
 *
 * Copy the 8051 alive counters F204 -> F208 and F240 -> F244.
 * Note: The 8051 sends two tokens round (8051, main processor, input processor); when a round takes longer
 *   than 15,000 ticks (10,000 for the second token) it prints '###SYSTEM CRASH, RESET###', stops both LEON
 *   processors, runs its power-off sequence and stays stopped.
 * Name basis: proven - copies the two token bytes that sys_watch_main_core of the 8051 writes and times
 *   (docs/MAP.md start-up sequence)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002ced8 @ 0xa002ced8..0xa002cf04 (11 words, RAM copy: CPU 0x4008ced8), flags -mcpu=v8 -O2 -g
 * (the section default). The register accesses are volatile, as they are hardware registers.
 */
/*
 * Tell the 8051 that the main processor is still running.
 * Copies the 8051 counter at XDATA 0xF204 (0xCF03C810) to 0xF208 (0xCF03C820), and the one at 0xF240
 * (0xCF03C900) to 0xF244 (0xCF03C910). The 8051 checks for this sign of life: after 15,000 ticks without it, it
 * prints "###SYSTEM CRASH, RESET###", stops both LEON processors and runs its power-off sequence (docs/MAP.md,
 * start-up). Callers include the main loop task and the GPIO I2C transfer routine.
 */
void ipc_signal_alive(void)
{
    *(volatile unsigned int *)0xCF03C820 = *(volatile unsigned int *)0xCF03C810;
    *(volatile unsigned int *)0xCF03C910 = *(volatile unsigned int *)0xCF03C900;
}
