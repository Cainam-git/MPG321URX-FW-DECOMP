/* SysTasksBeforeDisplay_byChannel  (FUN_a01516b0)
 *
 * Run the per-channel tasks that precede showing the picture and enable frame-rate conversion.
 * Name basis: proven - prints 'SysTasksBeforeDisplay_byChannel %d' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01516b0 @ 0xa01516b0-0xa01517f4 (81 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record switch lists the cases in the order 'case 0: default:', 1, 2, 3 (register allocation
 * follows the source block order; other orders swap registers). Callee prototypes as in the other files of
 * src/leon2m. The result of sys_get_active_port_code is not used, and the loop has no effect other than its
 * calls; both are kept because the exact build contains them.
 */
/* Channel record (0x78 bytes); only word 0 is used here: state in bits 28..31, port in bits 12..15. */
struct channel_record {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x78 - 0x04];
};
extern struct channel_record channel_records[4];
extern int dbg_printf(const char *fmt, ...);
extern unsigned char input_get_port_sync_mode(unsigned int);
extern unsigned char input_block_get_signal_code(unsigned char);
extern unsigned char sys_get_active_port_code(void);
extern void GMDHEnableFRC(void);

#define CH_STATE_C          0xc         /* channel state tested for the other channels */
#define PORT_TYPE_5         5           /* port type value tested */
#define SIGNAL_CODE_ROUTED  0xb1        /* PORT_CODE_ROUTED */

/*
 * Entry actions of channel state 0xA for one channel (called by GlobalModeHandler, GlobalModeHandler, when the
 * channel enters that state): print the channel number, then switch on the frame-rate converter channels
 * (GMDHEnableFRC) on every path.
 *
 *   channel  0..3; any other value uses channel record 0
 *
 * Before that: for a channel on port 0 whose input block 0 has signal code 0xB1 it reads the mode byte of the
 * active port (the result is not used); and if the port type of the channel's port is not 5, it looks through the
 * other channels for one in state 0xC whose port type is not 5, without doing anything with the result.
 */
void SysTasksBeforeDisplay_byChannel(unsigned char channel)
{
    unsigned char port, i;

    dbg_printf("SysTasksBeforeDisplay_byChannel %d\r\n", channel);
    switch (channel) {
    case 0: default: port = channel_records[0].u.b.port; break;
    case 1: port = channel_records[1].u.b.port; break;
    case 2: port = channel_records[2].u.b.port; break;
    case 3: port = channel_records[3].u.b.port; break;
    }
    if (port == 0) {
        if (input_block_get_signal_code(0) == SIGNAL_CODE_ROUTED)
            sys_get_active_port_code();
    }
    if (input_get_port_sync_mode(port) != PORT_TYPE_5) {
        for (i = 0; i < 4; i++) {
            if (i != channel && channel_records[i].u.b.state == CH_STATE_C && input_get_port_sync_mode(channel_records[i].u.b.port) != PORT_TYPE_5)
                break;
        }
    }
    GMDHEnableFRC();
}
