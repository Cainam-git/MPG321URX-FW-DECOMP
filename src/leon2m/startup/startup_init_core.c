/* startup_init_core  (FUN_a00de7c4)
 *
 * Set up the processor core, the debug serial port and the timers, and print the banner.
 * Name basis: proven - core registers, 96 MHz timer, DataRam check, banner; called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de7c4 @ 0xa00de7c4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the 0xFA00 x 2-nop wait is a static helper delay_loops(n) called with 1 and inlined (gcc keeps the
 *    'cmp j, 1; bcs' outer test only when the bound arrives through inlining; a literal 'j < 1' folds to j == 0);
 *  - the nops are real firmware instructions (inline asm nop, as in power_core_sleep_sequence / power_core_sleep_sequence_alt);
 *  - the data RAM check is the same code as startup_check_data_ram_config, written out here.
 */

extern void reg_write32(unsigned int addr, unsigned int value);
extern unsigned int reg_read32(unsigned int addr);
extern int irq_set_source_handler();
extern int dbg_print_stack_overflow();
extern void uart_init(unsigned int f);
extern void timer_init(unsigned int f);
extern void sys_poll_events_stub_copy2(void);
extern void irq_init_controller(void);
extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_clock_hz;
extern char sys_fake_sleep_led_flag[];      /* first byte of the initialised data: the address the linker gave the data RAM */

#define SYS_CLOCK_HZ              96000000  /* clock handed to the serial port and the timer set-up */
#define DATARAM_REG_ZEROS         0x9f020204    /* bits 0..23: every bit that is 0 counts one block */
#define DATARAM_REG_ONES          0x9f020200    /* bits 4..27: every bit that is 1 counts one block */
#define DATARAM_TOP               0xa803c000    /* the data RAM bottom is this minus 4 KiB per counted block */
#define DATARAM_BLOCK_SHIFT       12            /* 4 KiB */

/* Busy wait of n rounds of 0xFA00 loops with two nops each. */
static void delay_loops(unsigned int n)
{
    unsigned int j, k;
    for (j = 0; j < n; j++)
        for (k = 0; k <= 0xf9ff; k++) {
            __asm__ __volatile__("nop");
            __asm__ __volatile__("nop");
        }
}

/*
 * Set up the processor core, the serial port and the timer of the main program, check the data RAM set-up and
 * print the start banner. Called once from the start-up routine.
 *
 * Order:
 *  1. Core registers: 0x9F0200E0 = 0xC0, five nops, 0x9F000014 = 0x210003, a wait of 1024 nops, then
 *     0xC0000000 = 0x21, a long wait, 0xC0000000 = 0.
 *  2. 0x9F020320 = 5 and 0x9F020324 = 0xA803E400; dbg_print_stack_overflow becomes the handler of interrupt
 *     source 1, bit 0x10.
 *  3. sys_clock_hz = 96 MHz, then the serial port and the timer are set up with it.
 *  4. Data RAM check: the number of zero bits 0..23 of 0x9F020204 plus the number of one bits 4..27 of 0x9F020200,
 *     times 4 KiB, taken from 0xA803C000, must equal the address where the linker put the initialised data. If
 *     it does not, the register values and the linker address are printed and the processor stays in an endless
 *     loop.
 *  5. The event poll set-up and the interrupt controller are initialised, and the banner with the version
 *     text is printed.
 */
void startup_init_core(void)
{
    int wait_count;
    unsigned int value;
    unsigned char bit;
    unsigned char block_count;
    unsigned int bottom;
    char *data_start;

    reg_write32(0x9f0200e0, 0xc0);
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
    reg_write32(0x9f000014, 0x210003);
    wait_count = 0x3ff;
    do {
        __asm__ __volatile__("nop");
    } while (--wait_count >= 0);
    reg_write32(0xc0000000, 0x21);
    delay_loops(1);
    reg_write32(0xc0000000, 0);
    reg_write32(0x9f020320, 5);
    reg_write32(0x9f020324, 0xa803e400);
    irq_set_source_handler(1, 0x10, dbg_print_stack_overflow);
    sys_clock_hz = SYS_CLOCK_HZ;
    uart_init(SYS_CLOCK_HZ);
    timer_init(sys_clock_hz);
    data_start = sys_fake_sleep_led_flag;
    block_count = 0;
    value = reg_read32(DATARAM_REG_ZEROS);
    for (bit = 0; bit < 24; bit++)
        if (!((value >> bit) & 1))
            block_count++;
    value = reg_read32(DATARAM_REG_ONES);
    for (bit = 27; bit > 3; bit--)
        if ((value >> bit) & 1)
            block_count++;
    bottom = DATARAM_TOP - (block_count << DATARAM_BLOCK_SHIFT);
    if ((char *)bottom != data_start) {
        dbg_printf("\033[1;31mDataRam register config : 0x%08X, ld config : 0x%08X\r\n\033[m", bottom, data_start);
        for (;;)
            ;
    }
    sys_poll_events_stub_copy2();
    irq_init_controller();
    dbg_printf("\n\rNT68500 Leon2M system compiled under Linux\n\r%s\n\r", "version: 5e5d1dc6407-master commit: 2020-07-31 17:00:07 release build: 2020-08-04 16:45:42");
}
