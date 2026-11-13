/* sys_dsc_dec_set_regb4_bit1  (FUN_a00aec10)
 *
 * Set bit 1 of register 0xB4 of DSC decoder 0.
 * Name basis: derived - register block pointer at 0xA807DC04 (first word of the DSC decoder records); the same
 *   bit sys_dsc_dec_run_state sets after writing the set-up
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00aec10 @ 0xa00aec10 (-mcpu=v8 -Os -g)
 * Source form: the pointer variable is declared as an unsigned int and added to the offset.
 */
extern unsigned int sys_dsc_dec_records;        /* address of a register block */

/* Set bit 1 (mask 2) of the word at +0xB4 of the register block. Called by sys_dsc_dec_run_state and dp_start_stream. */
void sys_dsc_dec_set_regb4_bit1(void)
{
    *(volatile unsigned int *)(sys_dsc_dec_records + 0xb4) = *(volatile unsigned int *)(sys_dsc_dec_records + 0xb4) | 2;
    return;
}
