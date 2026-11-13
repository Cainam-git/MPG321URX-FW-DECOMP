/* sys_find_channel_by_path  (FUN_a013ce10)
 *
 * Return the channel record whose path field equals an id.
 * Returns: record or NULL
 * Name basis: descriptive - bits 1..3 of the first word of the channel records
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013ce10 @ 0xa013ce10-0xa013ce6c (23 words), flags -mcpu=v8 -O3 -g.
 * Twin of sys_find_channel_by_port.
 * Source form: one struct array of 0x78-byte records indexed by i (not a byte offset), a plain for loop
 * with an early return; the counter is an unsigned char. Aids: none.
 */
/* Channel record (0x78 bytes); only the status word at +0 is used here. */
struct channel_record { unsigned int status_word; unsigned char pad[0x78 - 4]; };
extern struct channel_record channel_records[4];

/* Scan the four channel records and return the first one whose path field (status word bits 1..3)
 * equals id, or NULL when none matches. */
struct channel_record *sys_find_channel_by_path(unsigned char id)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (id == ((channel_records[i].status_word >> 1) & 7))
            return &channel_records[i];
    }
    return 0;
}
