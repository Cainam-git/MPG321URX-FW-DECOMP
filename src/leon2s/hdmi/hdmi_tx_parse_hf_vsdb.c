/* hdmi_tx_parse_hf_vsdb  (FUN_a00a33f4)
 *
 * Find the HDMI Forum VSDB in a sink EDID and store its FRL and DSC fields.
 *   port: HDMI TX port
 *   edid: 512-byte EDID buffer
 * Name basis: proven - searches the CTA extension for OUI bytes D8 5D C4, version 1: SCDC present,
 *   Max_FRL_Rate, DSC fields
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a33f4 @ 0xa00a33f4-0xa00a3578, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - `block` = 0, then 'if (edid[0x80] == 2) block = 1' and so on;
 *  - `has_dsc_bytes` = 0 at its declaration;
 *  - unsigned short loop index and end; `field` is an unsigned char (see the comment at its assignment).
 */
extern unsigned char hdmi_tx_sink_scdc_present[];
extern unsigned char hdmi_tx_sink_max_frl[];
extern unsigned char hdmi_tx_sink_dsc_flags[];
extern unsigned char hdmi_tx_sink_dsc_max_frl[];
extern unsigned char hdmi_tx_sink_dsc_max_slices[];

#define EDID_BLOCK_SIZE      0x80
#define EDID_EXTENSION_TAG   2          /* first byte of the blocks searched */
#define SEARCH_LENGTH        0x7c       /* start positions searched in the block: its first 0x7C bytes */
#define DSC_BYTES_MARK       0x6d       /* byte before the pattern; only then are the DSC bytes taken */

/*
 * Look in the EDID that HDMI output `port` read from its sink for the bytes D8 5D C4 01 and store the fields
 * that follow them.
 *
 *   port  HDMI output port (index of the five per-port tables below)
 *   edid  the port's 512-byte EDID buffer (hdmi_tx_sink_edid_buffers + port * 0x200), four 128-byte blocks
 *
 * Only caller: hdmi_tx_check_hotplug, right after reading the EDID of a newly connected sink.
 *
 * Only one block is searched: the last of the blocks 1..3 whose first byte is 2; with none of them, nothing
 * is stored. On the first match (`field` = position of the 01 + 1):
 *   hdmi_tx_sink_scdc_present    1 when bit 7 of byte field + 1 is set, else 0
 *   hdmi_tx_sink_max_frl         bits 4..7 of byte field + 2
 *   hdmi_tx_sink_dsc_flags       byte field + 6                 } only when the byte before the pattern is 0x6D,
 *   hdmi_tx_sink_dsc_max_frl     bits 4..7 of byte field + 7    } else all three are 0
 *   hdmi_tx_sink_dsc_max_slices  bits 0..3 of byte field + 7    }
 * Without a match the five tables keep their values.
 */
void hdmi_tx_parse_hf_vsdb(unsigned char port, unsigned char *edid)
{
    unsigned char has_dsc_bytes = 0;
    unsigned char block, field;
    unsigned short i, end;

    block = 0;
    if (edid[0x80] == EDID_EXTENSION_TAG)
        block = 1;
    if (edid[0x100] == EDID_EXTENSION_TAG)
        block = 2;
    if (edid[0x180] == EDID_EXTENSION_TAG)
        block = 3;
    if (block == 0)
        return;
    end = block * EDID_BLOCK_SIZE + SEARCH_LENGTH;
    for (i = block * EDID_BLOCK_SIZE; i < end; i++) {
        if (edid[i] == 0xd8 && edid[i + 1] == 0x5d && edid[i + 2] == 0xc4 && edid[i + 3] == 1) {
            if (edid[i - 1] == DSC_BYTES_MARK)
                has_dsc_bytes = 1;
            /* `field` is a byte: in blocks 2 and 3 the position wraps, and the fields are read 0x100 bytes
               before the match (from block 0 or 1). */
            field = i + 4;
            if ((signed char)edid[field + 1] < 0)
                hdmi_tx_sink_scdc_present[port] = 1;
            else
                hdmi_tx_sink_scdc_present[port] = 0;
            hdmi_tx_sink_max_frl[port] = edid[field + 2] >> 4;
            if (has_dsc_bytes) {
                hdmi_tx_sink_dsc_flags[port] = edid[field + 6];
                hdmi_tx_sink_dsc_max_frl[port] = edid[field + 7] >> 4;
                hdmi_tx_sink_dsc_max_slices[port] = edid[field + 7] & 0xf;
            } else {
                hdmi_tx_sink_dsc_flags[port] = 0;
                hdmi_tx_sink_dsc_max_frl[port] = 0;
                hdmi_tx_sink_dsc_max_slices[port] = 0;
            }
            return;
        }
    }
}
