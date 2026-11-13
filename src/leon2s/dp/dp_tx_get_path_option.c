/* dp_tx_get_path_option  (FUN_a0086678)
 *
 * Return bit 15 of the option word of a video path.
 *   path
 * Name basis: descriptive - word +0x20 of the 40-byte path records; caller dp_tx_run_hpd_actions
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0086678 (0xa0086678-0xa00866a4, 11 words), flags -mcpu=v8 -Os -g. Leaf (retl).
 * Source form: the record is a 40-byte struct array indexed by the unsigned char; the firmware loads from
 * base + index * 0x28 + 0x20.
 */
struct dp_tx_path_record { unsigned char before_0x20[0x20]; unsigned int word_0x20; unsigned int after_0x24; };
extern struct dp_tx_path_record dp_tx_path_records[];    /* 40-byte record per path, base 0xa807a928 */

/*
 * Return bit 15 of the word at +0x20 of the path record of a path (0 or 1).
 *   path: record index
 * Called by dp_tx_run_hpd_actions.
 */
unsigned int dp_tx_get_path_option(unsigned char path)
{
  return dp_tx_path_records[path].word_0x20 >> 15 & 1;
}
