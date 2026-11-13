/* power_test_ddc_wake  (FUN_CODE_9d75)
 *
 * Report whether a DDC/CI request arrived on a port listed in the wake table.
 * Returns: 1 when found
 * Name basis: derived - per-port done bits 0xA0F3 (ddc_rearm_idle_slaves) tested for the entries of table
 *   0xA62F
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_9d75 @ 0x9d75 (202 bytes), OPTIMIZE(8,SPEED) (no XDATA locals: the LARGE build gives the
 * same bytes).
 * Source form: each shift count goes to its own local (channel_a, channel_b, dp_channel).
 */
/* One entry of the wake-up port table (message type 9 from the main processor). */
struct list_record {
    unsigned char header;   /* bits 0..4 = kind, bit 5 = option for the port signal check */
    unsigned char byte_1;   /* time slot of the entry, read by power_poll_wake_sources */
    unsigned char byte_2;   /* here: DDC/CI channel numbers, bits 3..0 and (kinds 1..6) bits 7..4 */
};
extern struct list_record xdata power_wake_port_table[10];
extern unsigned char ddc_get_pending_channels(void);

#define WAKE_TABLE_ENTRIES  10
#define WAKE_KIND_MASK      0x1f
#define WAKE_KIND_DP0_A     7   /* kinds 7..10: DP receiver entries */
#define WAKE_KIND_DP1_B     10

/*
 * power_test_ddc_wake - return 1 when a DDC/CI message waits on a channel named by an entry of the wake-up port
 * table (ddc_get_pending_channels gives one bit per channel). Entries of kinds 1..6 name two channels in byte_2
 * (bits 3..0 and 7..4), entries of kinds 7..10 one (bits 3..0); other kinds are skipped.
 * Only caller: sys_main.
 */
bit power_test_ddc_wake(void)
{
    bit found;
    unsigned char pending, i, channel_a, channel_b, dp_channel;

    found = 0;
    pending = ddc_get_pending_channels();
    for (i = 0; i != WAKE_TABLE_ENTRIES; i++) {
        if ((power_wake_port_table[i].header & WAKE_KIND_MASK) >= 1 && (power_wake_port_table[i].header & WAKE_KIND_MASK) < WAKE_KIND_DP0_A) {
            channel_a = power_wake_port_table[i].byte_2 & 0x0f;
            if ((1 << channel_a) & pending) found = 1;
            else {
                channel_b = power_wake_port_table[i].byte_2 >> 4;
                if ((1 << channel_b) & pending) found = 1;
            }
        } else if ((power_wake_port_table[i].header & WAKE_KIND_MASK) >= WAKE_KIND_DP0_A && (power_wake_port_table[i].header & WAKE_KIND_MASK) < WAKE_KIND_DP1_B + 1) {
            dp_channel = power_wake_port_table[i].byte_2 & 0x0f;
            if ((1 << dp_channel) & pending) found = 1;
        }
    }
    return found;
}
