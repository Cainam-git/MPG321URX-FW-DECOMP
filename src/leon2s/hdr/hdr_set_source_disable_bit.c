/* hdr_set_source_disable_bit  (FUN_a00d2618)
 *
 * Set or clear the bit of a source that switches HDR processing off for it.
 *   source: source number (bit number)
 *   on: not 0 sets the bit (processing off for the source), 0 clears it
 * Note: While the bit of the current source is set, hdr_task switches the tone mapping off and the HDR10+
 *   update returns at once. Mailbox command 0x78.
 * Name basis: derived - bit mask at 0xA8078C36; hdr_task and hdr_update_hdr10plus_metadata treat a set bit as
 *   'off for this source'; set by mailbox command 0x78 from the main processor
 *
 * Matching notes
 * --------------
 * FUN_a00d2618 (leon2s 0xa00d2618-0xa00d264c, 52 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: the expression '1 << bit' is written in each arm (as in dp_set_port_flag_bit).
 */
extern unsigned char hdr_source_disable_bits;

/*
 * Set (on != 0) or clear (on == 0) the bit of source number source in hdr_source_disable_bits. hdr_task and
 * hdr_update_hdr10plus_metadata test this bit for the current source (hdr_source): when it is set, hdr_task
 * switches the tone mapping off and the HDR10+ update returns without doing anything. Called by the mailbox
 * command IPC_CMD_SET_HDR_SOURCE_ENABLE with the source index and data byte 1.
 */
void hdr_set_source_disable_bit(unsigned char source, unsigned char on)
{
    if (on)
        hdr_source_disable_bits |= 1 << source;
    else
        hdr_source_disable_bits &= ~(1 << source);
}
