/* hdmi_tx_is_active  (FUN_a0091bac)
 *
 * Return whether an HDMI TX channel is marked as running.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - word 4 bit 1; when set the disable path runs TX command 9 (power down) and resets
 *   the record
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091bac @ 0xa0091bac-0xa0091be8 (15 words), flags -mcpu=v8 -Os -g.
 * Leaf. Source form: the base hdmi_tx_output_records and a record pointer taken before the range test (0x1c-byte
 * records, port * 7 * 4).
 */
/* One HDMI TX channel record (0x1c bytes); only word 4 (+0x10) is used here. */
struct hdmi_tx_channel_record { unsigned char pad[0x10]; unsigned int word_0x10; unsigned char pad2[0x1c - 0x14]; };
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];

/* Return active, bit 1 of word 4 (+0x10) of the record of HDMI TX channel 'port'; 0 for ports above 1. */
unsigned int hdmi_tx_is_active(unsigned char port)
{
    struct hdmi_tx_channel_record *record = &hdmi_tx_output_records[port];
    unsigned int active = 0;

    if (port < 2)
        active = (record->word_0x10 >> 1) & 1;
    return active;
}
