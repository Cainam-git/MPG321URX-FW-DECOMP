/* dp_tx_get_path_byte20  (FUN_a0087710)
 *
 * Return byte 20 of a video path record.
 *   path
 * Name basis: descriptive - 40-byte path records; value used for register 0x66/0x67
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0087710 @ 0xa0087710 (-mcpu=v8 -Os -g)
 * Same code as dp_tx_get_path_bits_per_colour with other constants.
 */
extern unsigned char dp_tx_path_records[];    /* 40-byte path records */

/*
 * Return byte 0x14 of the path record of a path. dp_tx_set_video_timing switches on it for path 0.
 *   path: record index
 */
unsigned char dp_tx_get_path_byte20(unsigned int path)
{
    return dp_tx_path_records[(path & 0xff) * 40 + 0x14];
}
