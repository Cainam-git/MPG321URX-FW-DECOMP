/* input_set_port_mode  (FUN_a0142ed0)
 *
 * Set the mode byte of a port record and reprogram the receiver when it changes.
 * Name basis: descriptive - byte 0x0A of the port record; time-out 1000 or 100 stored with it
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142ed0 @ 0xa0142ed0-0xa0142fcc, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: each pair of conditions is held in int locals and combined with "|" (the
 * firmware computes both flags with addx/subx and tests them with orcc).
 */

/* The port record (0x2A bytes), up to the fields used here. */
struct port_record_mode {
    unsigned char byte_0, byte_1;
    unsigned char state;            /* +2 */
    unsigned char pad3[7];
    unsigned char port_code;        /* +0xA */
    unsigned char pad_b[3];
    unsigned char byte_0xe;
    unsigned char pad_f;
    unsigned short half_0x10;
    unsigned char rest[0x2a - 0x12];
};
extern struct port_record_mode port_records[];
extern void input_reroute_shared_block(unsigned char port);
extern void input_select_block_source(unsigned char port, unsigned char code);
extern void input_load_block_source_registers(unsigned char port, unsigned char code);

/*
 * Give a port a new port code (byte +0xA of its port record) and set the input up for it.
 *
 *   port   the port number
 *   code   the new port code
 *   force  nonzero: do it even when the code is unchanged
 *
 * Only when the code changes, or force is set:
 *   - if the old code is 0x11 to 0x13 or 0x21, input_reroute_shared_block releases the block's route first;
 *   - the code is stored, the record's state (+2) is set to 2, and the block is set up for the code
 *     (input_select_block_source, input_load_block_source_registers);
 *   - halfword +0x10 is set to 1000 when the new code is 0x11 to 0x13 or 0x21, else to 100; byte +0xE is set to 5.
 * Called from sys_set_channel_port.
 */
void input_set_port_mode(unsigned char port, unsigned char code, unsigned char force)
{
    unsigned char old_code = port_records[port].port_code;     /* reused below for the stored code */
    int changed = old_code != code, forced = force != 0;

    if (changed | forced) {
        int in_range = (unsigned char)(old_code - 0x11) < 3, is_0x21 = old_code == 0x21;
        if (in_range | is_0x21)
            input_reroute_shared_block(port);
        port_records[port].port_code = code;
        port_records[port].state = 2;
        input_select_block_source(port, code);
        input_load_block_source_registers(port, code);
        old_code = port_records[port].port_code;
        in_range = (unsigned char)(old_code - 0x11) < 3;
        is_0x21 = old_code == 0x21;
        if (in_range | is_0x21)
            port_records[port].half_0x10 = 1000;
        else
            port_records[port].half_0x10 = 100;
        port_records[port].byte_0xe = 5;
    }
}
