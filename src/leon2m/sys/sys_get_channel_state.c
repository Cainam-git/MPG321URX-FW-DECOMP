/* sys_get_channel_state  (FUN_a013ce6c)
 *
 * Return the state field of a channel.
 * Returns: state
 * Name basis: derived - bits 28..31 of the first word of the channel record; 0xD for a wrong channel
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013ce6c @ 0xa013ce6c (-mcpu=v8 -O3 -g)
 * Source form: the record is reached through a static accessor chan(ch) (inlined).
 */
/* Channel record (0x78 bytes); only the status word at +0 is used here. */
struct channel_record { unsigned int status_word; unsigned char pad[0x78 - 4]; };
extern struct channel_record channel_records[];

static struct channel_record *chan(unsigned char ch)
{
    return &channel_records[ch];
}

/* Return the state of channel ch (0..3): bits 28..31 of its status word. Any other channel number
 * gives 0xD. */
unsigned int sys_get_channel_state(unsigned char ch)
{
    unsigned int state = 0xd;

    if (ch < 4)
        state = chan(ch)->status_word >> 28;
    return state;
}
