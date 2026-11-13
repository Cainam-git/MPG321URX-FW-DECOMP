/* sys_api_is_channel_port_state4  (FUN_a0143db8)
 *
 * Return whether the port of a channel is in state 4.
 * Returns: 0 or 1
 * Name basis: descriptive - byte 2 of the port record; used by the OLED power state machine
 *
 * Matching notes
 * --------------
 * FUN_a0143db8 (leon2m 0xa0143db8-0xa0143e70, 184 bytes), flags -mcpu=v8 -O3 -g.
 * Same lookup as input_api_get_channel_status_bit. Source form: the channel record address is taken into the pointer local
 * first; indexing the array inside the expression puts the operands of the word load the other way
 * round ([base + index]).
 */
#define PORT_STATE_OFFSET 2     /* byte +2 of a port record is its state */
#define PORT_STATE_4      4

/* Channel record (0x78 bytes); only the status word at +0 is used here (port = bits 12..15). */
struct channel_record { unsigned int status_word; unsigned char rest[0x74]; };
extern struct channel_record channel_records[4];
/* Port record (0x2a bytes). */
struct port_record { unsigned char data[42]; };
extern struct port_record port_records[];
extern int dbg_printf();                     /* formatted output (vsnprintf) */

/* Return ch for 0..3, else -1. */
static int remap(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/* Return 1 when the state (byte +2) of the port record that channel ch is on equals 4, else 0. A channel
 * above 3 prints "SYS remapping channel OOR" and is treated as channel 0. */
unsigned char sys_api_is_channel_port_state4(unsigned char ch)
{
    unsigned char i = remap(ch);
    struct channel_record *c;
    if (i > 3) { dbg_printf("SYS remapping channel OOR\r\n"); i = 0; }
    c = &channel_records[i];
    return port_records[(c->status_word >> 12) & 0xf].data[PORT_STATE_OFFSET] == PORT_STATE_4;
}
