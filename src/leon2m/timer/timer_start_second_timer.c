/* timer_start_second_timer  (FUN_a00decf4)
 *
 * Store two values and program the second timer.
 * Name basis: descriptive - registers 0xC00A0020 / 0xC00A0024; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00decf4 @ 0xa00decf4, flags -mcpu=v8 -O3 -g.
 * Source form: one record structure; the register helper for the masked write is declared void with three
 * arguments, the plain write with two.
 */

/* Registers at 0xC00A0020: a value word and a control word whose bit 0x80 is cleared and then set. */
#define SECOND_TIMER_VALUE   0xc00a0020
#define SECOND_TIMER_CONTROL 0xc00a0024
#define SECOND_TIMER_CONTROL_BIT 0x80
#define SECOND_TIMER_VALUE_MASK  0xffffff   /* only 24 bits of the value are written */
#define SECOND_TIMER_VALUE_FACTOR 10

/* The timer record at timer_tick_record; the other timer routines use the same layout. */
struct timer_record {
    unsigned char initialised;          /* 1 once timer_init has run */
    unsigned char pad[3];
    unsigned int tick_count;            /* +4: counted by timer_tick_isr */
    unsigned int word_0x8;
    unsigned int hooks[5];              /* +0x0c: hook words; hook 0 is called by timer_tick_isr */
    unsigned int word_0x20;
    unsigned int word_0x24;
};
extern struct timer_record timer_tick_record;
extern void reg_write32_masked(unsigned int, unsigned int, unsigned int);
extern void reg_write32(unsigned int, unsigned int);

/*
 * Do nothing while the timer record is not initialised. Otherwise store 'record_word_0x20' and
 * 'record_word_0x24' in the record, clear bit 0x80 of the control word at 0xC00A0024 and, when 'start' is
 * not zero, write (value * 10) & 0xffffff to 0xC00A0020 and set that bit again. Nothing calls it.
 *
 *   start              nonzero: load the value and set the bit
 *   record_word_0x20   stored at +0x20 of the record
 *   value              loaded (times 10, 24 bits) into the value word
 *   record_word_0x24   stored at +0x24 of the record
 */
void timer_start_second_timer(unsigned char start, unsigned int record_word_0x20, unsigned int value,
                              unsigned int record_word_0x24)
{
    if (timer_tick_record.initialised) {
        timer_tick_record.word_0x20 = record_word_0x20;
        timer_tick_record.word_0x24 = record_word_0x24;
        reg_write32_masked(SECOND_TIMER_CONTROL, 0, SECOND_TIMER_CONTROL_BIT);
        if (start) {
            reg_write32(SECOND_TIMER_VALUE, (value * SECOND_TIMER_VALUE_FACTOR) & SECOND_TIMER_VALUE_MASK);
            reg_write32_masked(SECOND_TIMER_CONTROL, SECOND_TIMER_CONTROL_BIT, SECOND_TIMER_CONTROL_BIT);
        }
    }
}
