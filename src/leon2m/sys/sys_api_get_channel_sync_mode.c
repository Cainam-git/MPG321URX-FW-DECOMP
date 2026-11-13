/* sys_api_get_channel_sync_mode  (FUN_a0147bb0)
 *
 * Return the sync mode 1..5 of the port a channel is mapped to, or 6.
 * Returns: sync mode, 6 for any other value
 * Name basis: descriptive - byte 9 (sync mode) of the port record through input_get_port_sync_mode; called
 *   from the DDC/CI request handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147bb0 @ 0xa0147bb0-0xa0147c38 (34 words).
 * Source form: the port number is a 4-bit bit-field of the channel record's first word, and the result
 * is a switch with one case per sync mode (jump table; 0 shares the default arm).
 */
/* Channel record (0x78 bytes). Status word at +0, from bit 31 down: 16 bits not used here,
 * port (4 bits), 12 bits not used here. */
struct channel_record { unsigned int unused_31_16 : 16; unsigned int port : 4; unsigned int unused_11_0 : 12; unsigned char rest[0x74]; };
extern struct channel_record channel_records[4];
extern unsigned char input_get_port_sync_mode(unsigned int);

/* Look up the sync mode of the port that channel ch is on. Modes 1..5 are returned as they are; every other
 * value (including 0) gives 6. ch is not range-checked. */
int sys_api_get_channel_sync_mode(unsigned char ch)
{
    int sync_mode;

    switch (input_get_port_sync_mode(channel_records[ch].port)) {
    case 1: sync_mode = 1; break;
    case 2: sync_mode = 2; break;
    case 3: sync_mode = 3; break;
    case 4: sync_mode = 4; break;
    case 5: sync_mode = 5; break;
    default: sync_mode = 6; break;
    }
    return sync_mode;
}
