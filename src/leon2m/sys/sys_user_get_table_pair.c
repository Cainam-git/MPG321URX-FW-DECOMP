/* sys_user_get_table_pair  (FUN_a00d80d8)
 *
 * Fetch two 16-bit values of a record of the table at 0x1984C8.
 * Name basis: descriptive - halfwords 0 and 4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d80d8 @ 0xa00d80d8-0xa00d8100 (10 words), flags -mcpu=v8 -O3 -g.
 * No caller found by address (it may be reached through a pointer or jump table).
 */
/* One 16-byte record of the table at 0x1984C8 (eight halfwords, no field is named). */
struct channel_record_16 {
    unsigned short h[8];
};
extern const struct channel_record_16 sys_user_channel_records[];

/* Store halfwords 0 and 4 of record number index of the table at 0x1984C8 through the two pointers. */
void sys_user_get_table_pair(unsigned char index, unsigned short *first, unsigned short *second)
{
    *first = sys_user_channel_records[index].h[0];
    *second = sys_user_channel_records[index].h[4];
}
