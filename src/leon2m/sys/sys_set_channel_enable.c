/* sys_set_channel_enable  (FUN_a01302e0)
 *
 * Switch a channel on or off.
 * Name basis: derived - flag bit 24, state 5 or 0, port state 2, window and source enable bits
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01302e0 @ 0xa01302e0-0xa0130438 (86 words), flags -mcpu=v8 -O3 -g.
 * Source form: the two combined conditions are int flags joined with '&' (the turning-on flag is reused for the
 * second test).
 */
/* Channel states (bits 28..31 of channel record word 0). */
enum channel_state {
    CH_STATE_OFF = 0,
    CH_STATE_WAIT_SYNC = 5
};
#define WINDOW_NONE 4                           /* window field value: no picture window */

/* Channel record (0x78 bytes): word 0 holds the state, port and window fields; word +0x70 holds the flags. */
struct channel_record {
    union {
        unsigned int w;
        struct { unsigned int state:4, bits_24_27:4, step:4, bits_16_19:4, port:4, receiver:4, window:4, bits_1_3:3, bit0:1; } b;
    } u;
    unsigned char p04[0x70 - 0x04];
    union { unsigned int w; struct { unsigned int r31:7, on_flag:1, rest:24; } b; } flags;      /* +0x70; bit 24 = on flag */
    unsigned char p74[0x78 - 0x74];
};
/* Port record (0x2a bytes): the state at +2 and the port code at +0xA. */
struct port_record { unsigned char b00, b01, state; unsigned char p03[7]; unsigned char port_code; unsigned char rest[0x2a - 0x0b]; };
extern struct channel_record channel_records[4];
extern struct port_record port_records[];
extern unsigned char input_get_port_class(unsigned char port_code);
extern void input_set_port_class(unsigned char port_code, unsigned char port_class);
extern void pq_window_disable(int window);
extern unsigned char sys_get_channel_source_class(unsigned char ch);
extern void sys_frc_set_source_class_enable(unsigned char source_class, unsigned char enable);

/*
 * Switch channel ch on (on != 0) or off.
 *
 * The on flag (bit 24 of the flag word +0x70) gets the low bit of `on`. When switching on: a channel in state 0
 * goes to state 5; the state of its port record goes from 1 to 2; and the port class of its port code goes from
 * 1 to 2. Whatever `on` is, the channel's picture window is switched off unless the window field is 4. Switching
 * off puts the channel in state 0. The last step passes the channel's source class with enable 0 to
 * sys_frc_set_source_class_enable. Called by startup_reset_channel_records.
 */
void sys_set_channel_enable(unsigned char ch, unsigned char on)
{
    int was_off, turning_on;

    channel_records[ch].flags.b.on_flag = on & 1;
    was_off = channel_records[ch].u.b.state == CH_STATE_OFF;
    turning_on = on != 0;
    if (was_off & turning_on)
        channel_records[ch].u.b.state = CH_STATE_WAIT_SYNC;
    was_off = port_records[channel_records[ch].u.b.port].state == 1;
    if (was_off & turning_on)
        port_records[channel_records[ch].u.b.port].state = 2;
    if (input_get_port_class(port_records[channel_records[ch].u.b.port].port_code) == 1 && on)
        input_set_port_class(port_records[channel_records[ch].u.b.port].port_code, 2);
    if (channel_records[ch].u.b.window != WINDOW_NONE)
        pq_window_disable(channel_records[ch].u.b.window);
    if (!on)
        channel_records[ch].u.b.state = CH_STATE_OFF;
    sys_frc_set_source_class_enable(sys_get_channel_source_class(ch), 0);
}
