/* audio_check_dp_fifo_unmute  (FUN_a008b9ec)
 *
 * Unmute DP audio once the stream has been stable long enough.
 *   port: DP receiver 0/1
 * Name basis: proven - prints 'DP fifo mute off %d'; debounce counter per receiver
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: abs is a static inline '(s ^ v) - s' helper (iabs) used inside the
 * '||'; the record pointer is formed inside the '&&' (comma expression) so that the +0x62 offset is not folded
 * into the symbol; the unit passed to audio_enable_unit_dp is the unsigned char result of audio_get_source_unit.
 */
extern unsigned char input_port_records[];
extern unsigned char audio_dp_stable_counts[];
extern unsigned int audio_dp_last_mauds[];     /* last Maud per DP receiver */
extern unsigned char audio_dp_unmute_flags[];
extern unsigned char audio_dp_resync_flag;
extern unsigned char audio_dp_fifo_muted_flag;
extern int dbg_printf(const char *, ...);
extern void dp_tx_get_link_state(void);
extern unsigned short audio_find_outputs_of_source(unsigned char);
extern unsigned char audio_get_source_unit(unsigned char);
extern void audio_enable_unit_dp(unsigned char, unsigned char);
extern int audio_read_dp_maud(unsigned char);
extern void audio_clear_dp_status(unsigned char);
extern unsigned char audio_dp_status_bit6(unsigned int);
extern unsigned char audio_dp_status_bit4(unsigned int);
extern void audio_mute_dp_fifo(unsigned char);
extern void audio_unmute_dp_fifo(unsigned char, unsigned char);
extern int dp_reg_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned char dp_get_regc1_bit0(unsigned int);

#define PORT_RECORD_SIZE        0x14    /* bytes of one port record */
#define DP0_RECORD_STATE        0x50    /* state of port record 4 (DP input 0) */
#define DP1_RECORD_STATE        0x64    /* state of port record 5 (DP input 1) */
#define LINK_STATE_READY        5       /* 'LINK_READY' */
#define RECORD_FLAGS_OFFSET     0x62    /* flags halfword (+0x12) of record 4 + port, counted from record 0 + port */
#define RECORD_FLAG_BIT6        0x40
#define MAUD_STABLE_RANGE       0x14    /* largest change of Maud that still counts as the same stream */
#define STABLE_ROUNDS           3       /* the unmute needs more than this many rounds in a row */
#define MUTED_BIT(port)         (1 << (port))           /* in audio_dp_fifo_muted_flag: FIFO muted */
#define UNMUTED_BIT(port)       (0x10 << (port))        /* in audio_dp_fifo_muted_flag: set at the unmute */

static inline int iabs(int v)
{
    int s = v >> 31;

    return (s ^ v) - s;
}

/*
 * Debounced unmute of the audio FIFO of one DisplayPort receiver. audio_run_service calls it for port 0
 * when audio source 4 is routed to an output and for port 1 when source 6 is.
 *
 *   port  DP receiver 0 or 1; its audio source is source 4 (port 0) or 6 (port 1)
 *
 * Returns at once unless the receiver's port record (records 4 and 5) is in link state LINK_READY (5).
 * Then, with maud = audio_read_dp_maud(port):
 *  - If the FIFO is flagged muted, or maud differs by more than 0x14 from the value kept in audio_dp_last_mauds
 *    for this port: when audio status bit 6 and bit 4 of the receiver are both set, a round counts as good
 *    if the source is routed to at least one output and bit 6 of the record's flags halfword (+0x12) is set;
 *    a bad round resets the count. After more than 3 good rounds in a row: reset the count, enable the
 *    source's audio unit, unmute the FIFO, print 'DP fifo mute off', for port 0 with bit 0 of DP register 0xC1
 *    set also set bit 4 of register 0x50, read the DP output link state, clear the audio status registers,
 *    clear the muted bit and set the unmuted bit of audio_dp_fifo_muted_flag, keep maud as the last value and
 *    set audio_dp_unmute_flags[port].
 *  - Otherwise (FIFO not muted and maud stable): when the resync flag of the port is set
 *    (audio_flag_dp_resync) and the FIFO is not muted, mute the FIFO and clear the flag.
 * At the end, a set audio_dp_unmute_flags[port] is cleared if the port's muted bit is clear.
 */
void audio_check_dp_fifo_unmute(unsigned char port)
{
    unsigned char source;
    unsigned int maud;
    unsigned char *record;

    if (port != 1) {
        source = 4;
        if (input_port_records[DP0_RECORD_STATE] != LINK_STATE_READY)
            return;
    } else {
        source = 6;
        if (input_port_records[DP1_RECORD_STATE] != LINK_STATE_READY)
            return;
    }
    maud = audio_read_dp_maud(port);
    if ((audio_dp_fifo_muted_flag & MUTED_BIT(port)) == MUTED_BIT(port) || iabs(maud - audio_dp_last_mauds[port]) > MAUD_STABLE_RANGE) {
        if (audio_dp_status_bit6(port) == 1 && audio_dp_status_bit4(port) == 1) {
            if (audio_find_outputs_of_source(source) != 0 &&
                (record = input_port_records + port * PORT_RECORD_SIZE, *(unsigned short *)(record + RECORD_FLAGS_OFFSET) & RECORD_FLAG_BIT6) != 0) {
                if (++audio_dp_stable_counts[port] > STABLE_ROUNDS) {
                    audio_dp_stable_counts[port] = 0;
                    audio_enable_unit_dp(audio_get_source_unit(source), 1);
                    audio_unmute_dp_fifo(port, 1);
                    dbg_printf("\033[0;38mDP fifo mute off %d\r\n\033[m", port);
                    if (port == 0 && dp_get_regc1_bit0(0) == 1)
                        dp_reg_update_bits(0, 0x50, 0x10, 1);
                    dp_tx_get_link_state();
                    audio_clear_dp_status(port);
                    audio_dp_fifo_muted_flag = (audio_dp_fifo_muted_flag & ~MUTED_BIT(port)) | UNMUTED_BIT(port);
                    audio_dp_last_mauds[port] = maud;
                    audio_dp_unmute_flags[port] = 1;
                }
            } else {
                audio_dp_stable_counts[port] = 0;
            }
        }
    } else if (((audio_dp_fifo_muted_flag >> port) & 1) == 0 && ((audio_dp_resync_flag >> port) & 1) != 0) {
        audio_mute_dp_fifo(port);
        audio_dp_resync_flag &= ~(1 << port);
    }
    if (((audio_dp_fifo_muted_flag >> port) & 1) == 0 && audio_dp_unmute_flags[port] == 1)
        audio_dp_unmute_flags[port] = 0;
}
