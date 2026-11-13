/* timer_init  (FUN_a00deb9c)
 *
 * Start the timers and register their interrupt handlers.
 * Name basis: proven - prints 'Timer Init %d'; called from startup_init_core
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00deb9c @ 0xa00deb9c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the clock parameter is an unsigned int; the five hook words are
 * cleared by a counted loop (i < 5) over the array, not by five stores; the flag test is the first statement
 * and returns at once when the flag is set.
 */

/* Timer registers: timer 0 and timer 1, each three words (reload value, control, third word). */
#define TIMER0_RELOAD  0xc00a0000
#define TIMER0_CONTROL 0xc00a0004
#define TIMER0_WORD_8  0xc00a0008
#define TIMER1_RELOAD  0xc00a0040
#define TIMER1_CONTROL 0xc00a0044
#define TIMER1_WORD_8  0xc00a0048
#define TIMER_CONTROL_START 0x83        /* value written to both control words */
#define TIMER_RELOAD_DIVIDER 8000       /* reload = cpu clock / 8000 */

#define TIMER_INTERRUPT_LEVEL     4     /* both handlers are registered for interrupt level 4 */
#define TIMER_SOURCE_TICK         1     /* source bit 0: timer_tick_isr */
#define TIMER_SOURCE_HOOK4        0x10  /* source bit 4: timer_isr_hook4 */
#define TIMER_HOOK_COUNT          5

/* The timer record at timer_tick_record; the other timer routines use the same layout. */
struct timer_record {
    unsigned char initialised;          /* 1 once timer_init has run */
    unsigned char pad[11];
    unsigned int hooks[TIMER_HOOK_COUNT]; /* +0x0c: hook words, cleared here; hook 0 is called by timer_tick_isr */
    unsigned int word_0x20;             /* not touched here */
    unsigned int word_0x24;             /* cleared here */
};
extern struct timer_record timer_tick_record;
extern unsigned int timer_isr_count_since_init;
extern void reg_write32(unsigned int, unsigned int);
extern int dbg_printf(const char *, ...);
extern void irq_set_source_handler(int, int, void (*)(void));
extern void irq_unmask_sources(int, int);
extern void timer_tick_isr(void);
extern void timer_isr_hook4(void);

/*
 * Start the two timers and register the timer interrupt handlers. Runs once: a later call returns at once
 * because the record is marked initialised.
 *
 *   cpu_clock  the processor clock in hertz; the caller (the start-up routine) passes 96000000, which
 *              makes the reload value 12000
 *
 * Clears the interrupt counter, the five hook words and word 0x24 of the record, writes the reload value and
 * the control value 0x83 to both timers, and prints "Timer Init 1". Then it registers timer_tick_isr (source
 * bit 0) and timer_isr_hook4 (source bit 4) on interrupt level 4 and unmasks source bit 4.
 */
void timer_init(unsigned int cpu_clock)
{
    unsigned int reload;
    int i;

    if (timer_tick_record.initialised != 0)
        return;
    timer_isr_count_since_init = 0;
    for (i = 0; i < TIMER_HOOK_COUNT; i++)
        timer_tick_record.hooks[i] = 0;
    reload = cpu_clock / TIMER_RELOAD_DIVIDER;
    timer_tick_record.word_0x24 = 0;
    reg_write32(TIMER0_RELOAD, reload);
    reg_write32(TIMER0_CONTROL, TIMER_CONTROL_START);
    reg_write32(TIMER0_WORD_8, 0);
    reg_write32(TIMER1_RELOAD, reload);
    reg_write32(TIMER1_CONTROL, TIMER_CONTROL_START);
    reg_write32(TIMER1_WORD_8, 0);
    timer_tick_record.initialised = 1;
    dbg_printf("\nTimer Init %d\r\n", 1);
    irq_set_source_handler(TIMER_INTERRUPT_LEVEL, TIMER_SOURCE_TICK, timer_tick_isr);
    irq_set_source_handler(TIMER_INTERRUPT_LEVEL, TIMER_SOURCE_HOOK4, timer_isr_hook4);
    irq_unmask_sources(TIMER_INTERRUPT_LEVEL, TIMER_SOURCE_HOOK4);
}
