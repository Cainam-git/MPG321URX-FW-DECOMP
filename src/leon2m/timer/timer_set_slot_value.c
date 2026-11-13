/* timer_set_slot_value  (FUN_a00ded78)
 *
 * Store a value in a slot of the timer record when the record is active.
 * Name basis: descriptive - record pointer at 0xA802B0C4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ded78 @ 0xa00ded78, flags -mcpu=v8 -O2 -g (a leaf routine).
 * Source form: one record structure (flag byte at +0, hook word array at +0xc).
 */

/* The timer record at timer_tick_record; the hook words start at +0x0c. */
struct timer_record {
    unsigned char initialised;
    unsigned char pad[0xb];
    unsigned int hooks[4];
};
extern struct timer_record timer_tick_record;

/*
 * Store 'value' in hook word 'slot' of the timer record, but only once the record is initialised.
 * Nothing calls it. timer_tick_isr calls hook word 0; the interrupt routines timer_isr_hook1 and
 * timer_isr_hook4 call hook words 1 and 4.
 */
void timer_set_slot_value(unsigned int slot, unsigned int value)
{
    if (timer_tick_record.initialised != 0)
        timer_tick_record.hooks[slot] = value;
}
