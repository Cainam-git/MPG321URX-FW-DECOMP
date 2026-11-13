/* sys_find_channel_of_port  (FUN_a013b86c)
 *
 * Return the index of the first channel whose port field equals the given port, or 0xFF.
 * Returns: channel 0..3, or 0xFF
 * Name basis: derived - loop over the channel port fields; sys_check_channel_index returns 0..3 unchanged
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013b86c @ 0xa013b86c-0xa013b92c (48 words), flags -mcpu=v8 -O3 -g.
 * Form: one u8 counter reused for both loops (the firmware keeps both in %i0, the channel in %l0), the found flag
 * set at the break, 'i = 0xff' when not found; 'port == record port' with port FIRST (the firmware's 'cmp %o3,%o5').
 */
/* Channel record (0x78 bytes): word 0 holds the state, port, receiver and window fields. */
struct channel_record {
    union {
        unsigned int w;
        struct { unsigned int state:4, bits_24_27:4, step:4, bits_16_19:4, port:4, receiver:4, window:4, bits_1_3:3, bit0:1; } b;
    } u;
    unsigned char p04[0x78 - 0x04];
};
extern struct channel_record channel_records[4];
extern unsigned char sys_check_channel_index(unsigned char);

/*
 * Return the index of the first channel whose port field equals port, or 0xFF when port is above 3 or no
 * channel has it. The second loop looks for the first i with sys_check_channel_index(i) equal to the channel
 * found; that routine returns 0..3 unchanged, so the result is the channel index itself.
 */
unsigned char sys_find_channel_of_port(unsigned char port)
{
    unsigned char i = 0, found = 0;
    if (port <= 3) {
        for (i = 0; i < 4; i++)
            if (port == channel_records[i].u.b.port)
                break;
        if (i <= 3) {
            unsigned char channel = i;
            for (i = 0; i < 4; i++)
                if (sys_check_channel_index(i) == channel) { found = 1; break; }
        }
    }
    if (!found)
        i = 0xff;
    return i;
}
