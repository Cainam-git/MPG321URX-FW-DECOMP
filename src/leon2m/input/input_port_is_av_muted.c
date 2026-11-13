/* input_port_is_av_muted  (FUN_a0132964)
 *
 * Return the AV mute flag (bit 6) of the port entry behind an input's signal code 0x51 or 0x61.
 * Returns: 0 or 1
 * Note: Bring-up state 9 waits while it is 1; in state 12 a 1 prints "AV MUTE(%d)" and sends the channel back
 *   to state 5.
 * Name basis: derived - the bring-up state machine prints "AV MUTE" when it returns 1; reads flag bit 6 of
 *   port entry 0 or 1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0132964 @ 0xa0132964-0xa0132a14 (44 words), flags -mcpu=v8 -O3 -g.
 * Source form: the choice of entry is a switch with two cases inside the four-code test. An if/else-if chain
 * instead lets the scheduler move the 0x51/0x61 compare pair into the 0x31/0x41 test block.
 * The second parameter is never read.
 */
extern unsigned char input_block_get_signal_code(unsigned char);
extern unsigned char sys_get_active_port_code(void);
extern unsigned char input_port_entry_get_flag_bit6_hi(unsigned char);

/* A signal code that does not settle the question by itself: the active channel's port mode is used instead. */
#define SIGNAL_CODE_USE_PORT_MODE 0xb1

/*
 * Answer the channel bring-up state machine (input_channel_bring_up_task): in state 9 the channel waits while
 * this returns 1 and moves on to state 10 only on 0; in state 12 a 1 prints "AV MUTE" and restarts it at state 5.
 *
 *   port    input block whose signal code is read
 *   unused  passed by the caller, not read
 *
 * For the signal code 0x51 the result is flag bit 6 of the second halfword of port entry 0, for 0x61 the same
 * bit of port entry 1. Every code other than 0x31, 0x41, 0x51 and 0x61 gives 0.
 *
 * For the codes 0x31 and 0x41 the entry number stays 0xFF, so the flag is read from port entry 255, which lies
 * outside the seven port entries; the result is whatever bit 6 of that memory holds.
 */
unsigned char input_port_is_av_muted(unsigned char port, unsigned int unused)
{
    unsigned char result, entry, code;

    code = input_block_get_signal_code(port);
    result = 0;
    entry = 0xff;
    if (code == SIGNAL_CODE_USE_PORT_MODE)
        code = sys_get_active_port_code();
    if (code == 0x31 || code == 0x41 || code == 0x51 || code == 0x61) {
        switch (code) {
        case 0x51: entry = 0; break;
        case 0x61: entry = 1; break;
        }
        result = input_port_entry_get_flag_bit6_hi(entry);
    }
    return result;
}
