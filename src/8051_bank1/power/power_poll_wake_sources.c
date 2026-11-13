/* power_poll_wake_sources  (FUN_CODE_a57e)
 *
 * Check the wake-up table's inputs in turn, moving to the next after its time slot.
 * Returns: entry kind that fired, or 0x0D
 * Name basis: derived - table 0xA62F index 0xA64D, slot time from entry byte 1; power_check_wake_entry,
 *   power_apply_wake_block_mode, power_init_wake_detection
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_a57e @ 0xa57e..0xa627 (169 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE local: kind at XDATA 0xA473 (read back from there for the return).
 * Source form: the end-marker test compares through a char cast, '(char)next_kind == 0x1f', which gives the
 *   firmware's 'MOV R7,A / CJNE R7,#1FH' (a plain compare tests A). The last return is the constant, not kind.
 */
/* One entry of the wake-up port table (message type 9 from the main processor). */
struct list_record {
    unsigned char header;   /* bits 0..4 = kind, bit 5 = option for the port signal check; kind 0x1F ends the table */
    unsigned char byte_1;   /* time slot of the entry, in units of 10 ticks */
    unsigned char byte_2;
};
extern struct list_record xdata power_wake_port_table[10];
extern unsigned char xdata power_wake_table_index;
extern unsigned int xdata power_wake_slot_ticks;
extern unsigned int timer_get_ticks(void);
extern void power_apply_wake_block_mode(void);
extern void power_init_wake_detection(void);
extern unsigned char power_check_wake_entry(void);

#define WAKE_TABLE_ENTRIES  10
#define WAKE_TABLE_END      0x1f   /* kind that ends the table; as index: scan restarts (power_reset_wake_table) */
#define RECORD_KIND_MASK    0x1f
#define ENTRY_KIND_NONE     0x0d   /* power_check_wake_entry: nothing fired */
#define SLOT_TICK_UNIT      10     /* byte_1 counts in units of 10 ticks */

/*
 * power_poll_wake_sources - test the wake-up port table one entry at a time, each for its time slot.
 * Returns the kind of the current entry when its test fired (power_check_wake_entry), else ENTRY_KIND_NONE.
 * When power_reset_wake_table has set the index to WAKE_TABLE_END, the scan starts again at entry 0: the time is
 * noted and the wake block and detection are set up anew. When the current entry's slot (byte_1 * 10 ticks) has
 * run out, the next entry becomes current and the wake block is set for it; the scan goes back to entry 0 at an
 * entry of kind WAKE_TABLE_END or after the tenth entry. The current entry is tested before and after that step.
 * At index 10 the end test reads the byte after the table (power_wake_table_index itself) before the index
 * test wraps it to 0.
 * Only caller: sys_main in power saving, which turns the kind into its wake-up code.
 */
unsigned char power_poll_wake_sources(void)
{
    unsigned char next_kind;
    unsigned char kind;

    if (power_wake_table_index == WAKE_TABLE_END) {
        power_wake_table_index = 0;
        power_wake_slot_ticks = timer_get_ticks();
        power_apply_wake_block_mode();
        power_init_wake_detection();
    }
    if ((kind = power_check_wake_entry()) != ENTRY_KIND_NONE)
        return kind;
    /* Time slot of the current entry over: go on to the next entry. */
    if ((timer_get_ticks() - power_wake_slot_ticks) / SLOT_TICK_UNIT > power_wake_port_table[power_wake_table_index].byte_1) {
        power_wake_table_index++;
        power_wake_slot_ticks = timer_get_ticks();
        next_kind = power_wake_port_table[power_wake_table_index].header & RECORD_KIND_MASK;
        if ((char)next_kind == WAKE_TABLE_END)
            power_wake_table_index = 0;
        if (power_wake_table_index == WAKE_TABLE_ENTRIES)
            power_wake_table_index = 0;
        power_apply_wake_block_mode();
    }
    if ((kind = power_check_wake_entry()) != ENTRY_KIND_NONE)
        return kind;
    return ENTRY_KIND_NONE;
}
