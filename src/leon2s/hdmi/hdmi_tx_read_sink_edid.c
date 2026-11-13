/* hdmi_tx_read_sink_edid  (FUN_a0095ca4)
 *
 * Read the EDID base block and up to three extensions of an HDMI TX sink.
 *   port: HDMI TX port 0/1
 * Name basis: proven - 128-byte blocks through hdmi_tx_read_edid; extension count = byte 0x7F; buffer
 *   0x9F1B0200 + port * 0x200
 *
 * Matching notes
 * --------------
 * FUN_a0095ca4 (leon2s, 0xa0095ca4-0xa0095d34, 144 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the buffer pointer is advanced by 0x80 before the 'n == 0' return (the firmware's add sits in the
 * bleu delay slot) and after each call; the firmware's double 'be' is the n == 0 return plus the loop's entry test.
 */
#define EDID_BLOCK_BYTES     0x80       /* one EDID block */
#define EDID_EXTENSION_COUNT 0x7f       /* byte of the base block that holds the number of extension blocks */
#define EDID_MAX_EXTENSIONS  3          /* more extension blocks are not read */

extern unsigned char hdmi_tx_sink_edid_buffers[][0x200];    /* 0x200 bytes per port, at 0x9F1B0200 */
extern void hdmi_tx_read_edid(unsigned int, unsigned char *, unsigned int, unsigned int);

/*
 * Read the EDID of the display on an HDMI TX port into the port's buffer: the base block, then as many
 * extension blocks as byte 0x7F of the base block says, at most 3. hdmi_tx_read_edid gets the port, the
 * destination, the block size and the byte offset in the EDID.
 *   port: HDMI TX port 0/1
 * Called by hdmi_tx_check_hotplug.
 */
void hdmi_tx_read_sink_edid(unsigned char port)
{
    unsigned char *block;
    unsigned char extensions, i;

    block = hdmi_tx_sink_edid_buffers[port];
    hdmi_tx_read_edid(port, block, EDID_BLOCK_BYTES, 0);
    extensions = block[EDID_EXTENSION_COUNT];
    block += EDID_BLOCK_BYTES;
    if (extensions > EDID_MAX_EXTENSIONS)
        extensions = EDID_MAX_EXTENSIONS;
    if (extensions == 0)
        return;
    for (i = 0; i < extensions; i++) {
        hdmi_tx_read_edid(port, block, EDID_BLOCK_BYTES, (i << 7) + EDID_BLOCK_BYTES);
        block += EDID_BLOCK_BYTES;
    }
}
