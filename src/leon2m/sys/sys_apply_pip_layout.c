/* sys_apply_pip_layout  (FUN_a0130438)
 *
 * Switch the four channels on or off as the picture-in-picture mode requires.
 * Name basis: derived - by the PIP mode byte and three flags; inlines sys_set_channel_enable
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0130438 @ 0xa0130438, flags -mcpu=v8 -O3 -g.
 * Source form: the body of sys_set_channel_enable (sys_set_channel_enable, the routine just before this one) is copied
 * here as the static function set_channel_enable and called with constant arguments; GCC inlines every call.
 */

/* State field of a channel record (word 0, bits 28..31). */
enum {
    CH_STATE_OFF = 0,
    CH_STATE_WAIT_SYNC = 5              /* a channel that is switched on waits for the sync of its port */
};

/* Channel record: word 0 holds the state, the port (bits 12..15) and the picture window (bits 4..7);
   word +0x70 holds flags, bit 24 of it being the "switched on" flag. */
struct Chan {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, receiver:4, window:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x70 - 0x04];
    union { unsigned int w; struct { unsigned int r31:7, on_flag:1, rest:24; } b; } w70;
    unsigned char p74[0x78 - 0x74];
};
/* Port record: +2 state, +0xA port code. */
struct Port { unsigned char b00, b01, state; unsigned char p03[7]; unsigned char port_code; unsigned char rest[0x2a - 0x0b]; };
extern struct Chan channel_records[4];
extern struct Port port_records[];
extern unsigned char input_get_port_class(unsigned char t);
extern void input_set_port_class(unsigned char t, unsigned char v);
extern void pq_window_disable(int p);
extern unsigned char sys_get_channel_source_class(unsigned char ch);
extern void sys_frc_set_source_class_enable(unsigned char sel, unsigned char on);

/*
 * Switch channel ch on (on != 0) or off. This is the body of sys_set_channel_enable.
 *
 * It stores `on` in the on flag of the channel record. When switching on, a channel in state 0 goes to
 * state 5, the state 1 of its port record becomes 2 and the port class 1 becomes 2. Whatever `on` is, the
 * channel's picture window is switched off unless the window field is 4. Switching off puts the channel
 * in state 0. The last call passes the channel's source class (1..3, or 0) with enable 0.
 */
static void set_channel_enable(unsigned char ch, unsigned char on)
{
    int was_off, turning_on, port_waiting;

    channel_records[ch].w70.b.on_flag = on & 1;
    was_off = channel_records[ch].u.b.state == CH_STATE_OFF;
    turning_on = on != 0;
    if (was_off & turning_on)
        channel_records[ch].u.b.state = CH_STATE_WAIT_SYNC;
    port_waiting = port_records[channel_records[ch].u.b.port].state == 1;
    if (port_waiting & turning_on)
        port_records[channel_records[ch].u.b.port].state = 2;
    if (input_get_port_class(port_records[channel_records[ch].u.b.port].port_code) == 1 && on)
        input_set_port_class(port_records[channel_records[ch].u.b.port].port_code, 2);
    if (channel_records[ch].u.b.window != 4)
        pq_window_disable(channel_records[ch].u.b.window);
    if (!on)
        channel_records[ch].u.b.state = CH_STATE_OFF;
    sys_frc_set_source_class_enable(sys_get_channel_source_class(ch), 0);
}

/* System configuration record (sys_config): word 0, and the two enable bytes of channels 2 and 3. */
struct S3d0 {
    unsigned int w0;
    unsigned char p04[0x26];
    unsigned char channel2_enable, b2b, channel3_enable;
};
extern unsigned char device_settings_pip_mode;
extern struct S3d0 sys_config;

#define SYS_CONFIG_CHANNEL3_BIT 0x200000    /* bit 21 of sys_config word 0: channel 3 is switched on */

/*
 * Switch the four channels on or off to match the PIP/PBP mode (device_settings_pip_mode, 0..7).
 * Takes no parameters and returns nothing. Called by sys_apply_pip_layout_and_windows.
 *
 * The mode decides how many channels are on, always counting up from channel 0:
 *   mode 0 -> channel 0;   modes 1, 2, 5 -> channels 0..1;   modes 3, 6 -> channels 0..2;
 *   modes 4, 7 -> channels 0..3.
 * Any other mode value leaves the channels as they are.
 * After that three extra flags can only switch more channels on, never off: bit 21 of sys_config word 0
 * switches channel 3 on, sys_config_channel2_enable == 1 switches channel 2 on and
 * sys_config_channel3_enable == 1 switches channel 3 on.
 */
void sys_apply_pip_layout(void)
{
    switch (device_settings_pip_mode) {
    case 0:
        set_channel_enable(0, 1);
        set_channel_enable(1, 0);
        set_channel_enable(2, 0);
        set_channel_enable(3, 0);
        break;
    case 1:
    case 2:
    case 5:
        set_channel_enable(0, 1);
        set_channel_enable(1, 1);
        set_channel_enable(2, 0);
        set_channel_enable(3, 0);
        break;
    case 3:
    case 6:
        set_channel_enable(0, 1);
        set_channel_enable(1, 1);
        set_channel_enable(2, 1);
        set_channel_enable(3, 0);
        break;
    case 4:
    case 7:
        set_channel_enable(0, 1);
        set_channel_enable(1, 1);
        set_channel_enable(2, 1);
        set_channel_enable(3, 1);
        break;
    }
    if (sys_config.w0 & SYS_CONFIG_CHANNEL3_BIT)
        set_channel_enable(3, 1);
    if (sys_config.channel2_enable == 1)
        set_channel_enable(2, 1);
    if (sys_config.channel3_enable == 1)
        set_channel_enable(3, 1);
}
