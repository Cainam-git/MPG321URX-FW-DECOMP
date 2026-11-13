/* dp_tx_get_mode_flag  (FUN_a00866a4)
 *
 * Return bit 29 of the first path record's mode word.
 * Name basis: descriptive - word 0 of the path records; callers training, EDID read and HPD action routines
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00866a4 @ 0xa00866a4 (-mcpu=v8 -Os -g)
 * Source form: the word is read as a plain unsigned int at the start of the path record array.
 */
extern unsigned int dp_tx_path_records;    /* word 0 of path record 0 (the records are 40 bytes each) */

/*
 * Return bit 29 of word 0 of the first path record. Callers: the link training, EDID read and hot-plug
 * action routines.
 */
unsigned int dp_tx_get_mode_flag(void)
{
  return dp_tx_path_records >> 0x1d & 1;
}
