/* sys_find_channel_by_port  (FUN_a013cd4c)
 *
 * Return the channel record whose port field equals an id.
 * Returns: record or NULL
 * Name basis: derived - bits 12..15 of the first word of the 0x78-byte channel records
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013cd4c @ 0xa013cd4c-0xa013cda8 (23 words), flags -mcpu=v8 -O3 -g.
 * Twin of sys_find_channel_by_path.
 * Source form: one struct array of 0x78-byte records indexed by i (not a byte offset), a plain for loop
 * with an early return.
 */
struct channel_record { unsigned int word0; unsigned char pad[0x78 - 4]; };
extern struct channel_record channel_records[4];

/* Return the first channel record whose port field (bits 12..15 of word 0) equals id, or NULL (0) when none does. */
struct channel_record *sys_find_channel_by_port(unsigned char id)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (id == ((channel_records[i].word0 >> 12) & 0xf))
            return &channel_records[i];
    }
    return 0;
}
