/* pq_apply_table_entry_both_channels  (FUN_a0087d5c)
 *
 * Apply entry n (0..3) of the 0x44-byte ROM records to channels 1 and 0.
 *   entry_index: entry, 4 and above = 0
 * Note: Records at ROM 0xFF600.
 * Name basis: descriptive - code only; caller sys_user_apply_dimming_mode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0087d5c @ 0xa0087d5c-0xa0087da4 (18 words), flags -mcpu=v8 -O3 -g.
 */
#define ACE_TABLE_COUNT 4
#define ACE_TABLE_SIZE 0x44
#define CHANNEL_1 1
#define CHANNEL_0 0

struct ace_table_record {
    unsigned char data[ACE_TABLE_SIZE];
};

extern const struct ace_table_record pq_ace_tables[ACE_TABLE_COUNT];
extern void pq_api_load_ace_table(int, const struct ace_table_record *);

/*
 * Apply entry entry_index (0..3) of the ACE tables to both channels.
 * If entry_index is out of range, entry 0 is used.
 * Loads the table for channel 1 first, then channel 0.
 * Caller: sys_user_apply_dimming_mode.
 */
void pq_apply_table_entry_both_channels(unsigned char entry_index)
{
    const struct ace_table_record *table;

    if (entry_index >= ACE_TABLE_COUNT)
        entry_index = 0;
    table = &pq_ace_tables[entry_index];
    pq_api_load_ace_table(CHANNEL_1, table);
    pq_api_load_ace_table(CHANNEL_0, table);
}
