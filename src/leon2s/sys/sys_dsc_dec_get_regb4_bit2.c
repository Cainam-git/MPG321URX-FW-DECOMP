/* sys_dsc_dec_get_regb4_bit2  (FUN_a00aec2c)
 *
 * Return bit 2 of register 0xB4 of DSC decoder 0.
 * Returns: 0 or 1
 * Name basis: derived - register block pointer at 0xA807DC04 (first word of the DSC decoder records); the same
 *   bit sys_dsc_dec_run_state tests in its checksum wait
 *
 * Matching notes
 * --------------
 * FUN_a00aec2c (leon2s 0xa00aec2c-0xa00aec50, 36 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: a result byte that starts at 0, returned as result & 1.
 */
extern volatile unsigned int *sys_dsc_dec_records;      /* register block; word 0x2d = byte offset 0xB4 */

#define BLOCK_WORD_0xB4 0x2d    /* word index of byte offset 0xB4 */

/* Return 1 when bit 2 of the word at +0xB4 of the register block is set, else 0. Called by sys_dsc_dec_run_state. */
unsigned char sys_dsc_dec_get_regb4_bit2(void)
{
    unsigned char result = 0;

    if (sys_dsc_dec_records[BLOCK_WORD_0xB4] & 4)
        result = 1;
    return result & 1;
}
