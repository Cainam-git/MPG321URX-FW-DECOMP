/* ldc_hw_start  (FUN_a00fbfd4)
 *
 * Initialise the grid block, set its strength and switch it on with its interrupt.
 * Name basis: derived - ldc_hw_command(init), ldc_hw_command(strength), enable bit, interrupt handler; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fbfd4, flags -mcpu=v8 -O3 -g.
 * The firmware never writes %i0, so the function returns its first parameter unchanged. ldc_hw_command takes three
 * arguments (the firmware sets %o0..%o2) and is declared without a prototype, as int-returning; the control register
 * is a constant address (a symbol would give the sethi/%lo form).
 */

/* Commands of ldc_hw_command. */
#define LDC_COMMAND_INIT         1
#define LDC_COMMAND_SET_STRENGTH 4

/* Interrupt level and source mask of the grid block's interrupt. */
#define LDC_IRQ_LEVEL  0xc
#define LDC_IRQ_SOURCE 0x100

extern unsigned char ldc_hw_mode3_pass_entry[];
extern unsigned short ldc_started_flag;
extern int ldc_hw_command();
extern int irq_unmask_sources();
extern void irq_set_source_handler();

/*
 * Start the grid block: run its init command, set ldc_started_flag, run its set-strength command (selector 0 and
 * unused third argument in both), set the enable bit (bit 31 of the control register 0xD0040000), register
 * ldc_hw_mode3_pass_entry as the handler of the block's interrupt source and unmask it.
 * Returns param_1 unchanged; param_2 is not read. No routine calls this one.
 */
unsigned int ldc_hw_start(unsigned int param_1, unsigned int param_2)
{
    ldc_hw_command(0, LDC_COMMAND_INIT, 0);
    ldc_started_flag = 1;
    ldc_hw_command(0, LDC_COMMAND_SET_STRENGTH, 0);
    *(volatile unsigned int *)0xd0040000 = *(volatile unsigned int *)0xd0040000 | 0x80000000;
    irq_set_source_handler(LDC_IRQ_LEVEL, LDC_IRQ_SOURCE, ldc_hw_mode3_pass_entry);
    irq_unmask_sources(LDC_IRQ_LEVEL, LDC_IRQ_SOURCE);
    return param_1;
}
