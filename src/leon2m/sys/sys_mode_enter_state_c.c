/* sys_mode_enter_state_c  (FUN_a0151818)
 *
 * Run the entry actions of channel state 0xC for the given channel when it is on port 0.
 * Name basis: derived - header: state C entry; called from the global mode handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0151818 @ 0xa0151818-0xa01518c8 (44 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record switch lists the cases in the order 'case 0: default:', 1, 2, 3 (as in
 * SysTasksBeforeDisplay_byChannel). sys_get_channel_source_class returns a byte (the caller masks it with 0xff
 * after each call, so it is called twice); the second callee takes (int bit, u8 on).
 */
/* Channel record (0x78 bytes); only word 0 is used here: state in bits 28..31, port in bits 12..15. */
struct channel_record {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x78 - 0x04];
};
extern struct channel_record channel_records[4];
extern unsigned int sys_config;
extern unsigned char sys_get_channel_source_class(unsigned char channel);
extern void sys_frc_set_channel_bit_triple(unsigned char bit, unsigned char on);
extern void sys_frc_set_channel_enable(int bit, unsigned char on);

#define SYS_CONFIG_CHANNEL3_BIT 0x200000        /* bit 21 of sys_config word 0 */

/*
 * Entry actions of channel state 0xC for one channel (called by GlobalModeHandler, GlobalModeHandler, when the
 * channel enters that state).
 *
 *   channel  0..3; any other value uses channel record 0
 *
 * Only when the channel is on port 0 and bit 21 of the system configuration word is set: set the converter bit of
 * the source class of channel 3 (sys_frc_set_channel_bit_triple), then clear its enable bit
 * (sys_frc_set_channel_enable). Otherwise nothing happens.
 */
void sys_mode_enter_state_c(unsigned char channel)
{
    unsigned char port;

    switch (channel) {
    case 0: default: port = channel_records[0].u.b.port; break;
    case 1: port = channel_records[1].u.b.port; break;
    case 2: port = channel_records[2].u.b.port; break;
    case 3: port = channel_records[3].u.b.port; break;
    }
    if (port == 0 && (sys_config & SYS_CONFIG_CHANNEL3_BIT)) {
        sys_frc_set_channel_bit_triple(sys_get_channel_source_class(3), 1);
        sys_frc_set_channel_enable(sys_get_channel_source_class(3), 0);
    }
}
