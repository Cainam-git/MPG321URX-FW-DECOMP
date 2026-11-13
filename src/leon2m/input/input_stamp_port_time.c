/* input_stamp_port_time  (FUN_a0142ea8)
 *
 * Store the current tick count in a port record.
 * Name basis: derived - halfword 0x12 of the port record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142ea8 @ 0xa0142ea8-0xa0142ed0, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 */

/* The port record (0x2A bytes), up to the field used here. */
struct port_record_stamp {
    unsigned char pad[0x12];
    unsigned short time_stamp;      /* +0x12: tick count (16 bits) */
    unsigned char rest[0x16];
};
extern struct port_record_stamp port_records[];
extern unsigned short timer_get_ticks16(void);

/*
 * Store the current tick count in the time stamp (+0x12) of a port record.
 *
 *   port  the port number
 */
void input_stamp_port_time(unsigned char port)
{
    port_records[port].time_stamp = timer_get_ticks16();
}
