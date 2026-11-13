/* sys_dsc_dec_reset_state  (FUN_a00a5050)
 *
 * Set the DSC decoder state machine back to its first state.
 * Name basis: derived - clears the state word of record 0xA807DC10
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a5050 @ 0xa00a5050 (-mcpu=v8 -Os -g)
 * A do/while with an unsigned char counter that runs once ('while (i == 0)').
 */
extern unsigned int sys_dsc_dec_state_records[];

/* Clear the first word of the state record of decoder 0. The records are 8 bytes (two words) apart. */
void sys_dsc_dec_reset_state(void)
{
    unsigned char i = 0;
    do {
        sys_dsc_dec_state_records[i * 2] = 0;
        i++;
    } while (i == 0);
}
