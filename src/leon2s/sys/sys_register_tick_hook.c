/* sys_register_tick_hook  (FUN_a00b2070)
 *
 * Store a routine in the first free tick hook slot.
 * Note: timer_tick_isr calls only the two hooks of group 0; a hook stored in another group is never called by
 *   it.
 * Name basis: derived - two slots per index in the record at 0xA80793A4; prints when both are taken
 *
 * Matching notes
 * --------------
 * FUN_a00b2070 (leon2s 0xa00b2070-0xa00b20dc, 108 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The callback words start at offset 0xc of timer_tick_record; the full-table message is printed by a tail call.
 */
/* Layout of timer_tick_record; the 16 task records follow it at 0xa80793b8 (see timer_tick_isr). */
struct Timers {
    unsigned int w0;
    unsigned int tick;
    unsigned int w8;
    void (*hook[1][2])(int);    /* two hook slots per group */
};
extern struct Timers timer_tick_record;
extern int dbg_printf(const char *, ...);

/* Store a routine in the first free one of the two hook slots of a group, or print "No H/W timer ISR available"
 * when both are taken. timer_tick_isr calls the two hooks of group 0 with the argument 0 on every tick.
 *   group: hook group (callers pass 0)
 *   hook: routine to call
 */
void sys_register_tick_hook(unsigned int group, void (*hook)(int))
{
    int slot;

    for (slot = 0; slot < 2; slot++)
        if (timer_tick_record.hook[group][slot] == 0)
            break;
    if (slot == 2) {
        dbg_printf("\nNo H/W timer ISR available");
        return;
    }
    timer_tick_record.hook[group][slot] = hook;
}
