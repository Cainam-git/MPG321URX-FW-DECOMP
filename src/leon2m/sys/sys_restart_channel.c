/* sys_restart_channel  (FUN_a012f1ec)
 *
 * Set a channel back to an earlier state so that it is brought up again.
 * Name basis: derived - lowers the state field to the level chosen by mode, clears the step and flag bit 22,
 *   then calls sys_mode_restart_channel
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012f1ec @ 0xa012f1ec-0xa012f2dc (60 words), flags -mcpu=v8 -O3 -g.
 * Source form: switch without a case 1 (it falls to the default, so GCC builds a compare tree); the state test
 * compares (unsigned int)state_wanted with the bit-field (unsigned compare).
 */
/* Channel states (bits 28..31 of channel record word 0). */
enum channel_state {
    CH_STATE_OFF = 0,
    CH_STATE_WAIT_SYNC = 5,
    MODE_MODESEARCH = 6,
    MODE_CAPTURE = 7,
    MODE_DISPLAY = 8,
    MODE_WAIT2SHOW = 9,
    MODE_WAITMODECHANGE = 12
};
#define CH_RESTART_FIELD 0xc000                 /* bits 14..15 of channel flag word +0x70 */
#define CH_RESTART_FIELD_2 0x8000               /* value 2 in that field */
#define CH_RUN_AGAIN 0x400000                   /* flag bit 22 */
#define LAST_CHANNEL_INDEX 3

/* Channel record (0x78 bytes): word 0 holds the state, step and port fields; word +0x70 holds the flags. */
struct channel_record {
    union {
        unsigned int w;
        struct { unsigned int state:4, bits_24_27:4, step:4, bits_16_19:4, port:4, receiver:4, window:4, bits_1_3:3, bit0:1; } b;
    } u;
    unsigned char p04[0x70 - 0x04];
    unsigned int flags;                         /* +0x70 */
    unsigned char p74[0x78 - 0x74];
};
extern struct channel_record channel_records[4];
extern void sys_mode_restart_channel(unsigned char ch);

/*
 * Bring channel ch back to an earlier state, chosen by mode, and run the restart entry actions.
 *
 *   ch    channel index 0..3; 0xFF and values above 3 do nothing
 *   mode  0 -> state 5 (CH_STATE_WAIT_SYNC), 2 -> 7 (MODE_CAPTURE), 3 -> 8 (MODE_DISPLAY), 4 -> 9 (MODE_WAIT2SHOW),
 *         any other value -> 6 (MODE_MODESEARCH)
 *
 * Nothing happens when the channel's present state is lower than the chosen one. A channel in state 12
 * (MODE_WAITMODECHANGE) first has the field 0xC000 of its flag word set to 2. Then the state is set, the step
 * field is cleared, flag bit 22 (CH_RUN_AGAIN) is cleared and sys_mode_restart_channel(ch) is called as a tail call.
 * Callers include APPSetPowerOff (restart of channels 0, 1 and 3) and SYSAPI_ConfigSystemPIPMode (all four channels).
 */
void sys_restart_channel(unsigned char ch, unsigned char mode)
{
    unsigned char state_wanted;

    switch (mode) {
    case 0: state_wanted = CH_STATE_WAIT_SYNC; break;
    case 2: state_wanted = MODE_CAPTURE; break;
    case 3: state_wanted = MODE_DISPLAY; break;
    case 4: state_wanted = MODE_WAIT2SHOW; break;
    default: state_wanted = MODE_MODESEARCH; break;
    }
    if (ch == 0xff)
        return;
    if (ch > LAST_CHANNEL_INDEX)
        return;
    if ((unsigned int)state_wanted > channel_records[ch].u.b.state)
        return;
    if (channel_records[ch].u.b.state == MODE_WAITMODECHANGE)
        channel_records[ch].flags = (channel_records[ch].flags & ~CH_RESTART_FIELD) | CH_RESTART_FIELD_2;
    channel_records[ch].u.b.state = state_wanted;
    channel_records[ch].u.b.step = 0;
    channel_records[ch].flags &= ~CH_RUN_AGAIN;
    sys_mode_restart_channel(ch);
}
