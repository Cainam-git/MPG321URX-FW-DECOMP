/* dp_tx_get_path_bits_per_colour  (FUN_a00876ec)
 *
 * Return the bits per colour (byte 0x15) of a video path record.
 *   path
 * Name basis: derived - byte 0x15 of the 40-byte path records, filled by mailbox commands of the main program;
 *   the link training routine compares it with 8, 6 and 10
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00876ec @ 0xa00876ec (-mcpu=v8 -Os -g)
 * GCC computes the row offset as ((index << 2) + index) << 3 = index * 40. Same shape as input_get_port_source_code and
 * hdmi_tx_get_source_code (other strides and offsets).
 */
extern unsigned char dp_tx_path_records[];    /* 40-byte path records */

/*
 * Return byte 0x15 of the path record of a path. The link training routine compares it with 8, 6 and 10 to
 * pick the value written to register 0x66.
 *   path: record index
 */
unsigned char dp_tx_get_path_bits_per_colour(unsigned int path)
{
    return dp_tx_path_records[(path & 0xff) * 40 + 0x15];
}
