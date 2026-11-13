/* dp_tx_set_reg70_bit5  (FUN_a0087d50)
 *
 * Set or clear bit 5 of register 0x70 of a DP output.
 *   port: output
 *   value: 1 = set
 * Name basis: descriptive - single masked write; callers ipc_dispatch_command and dp_tx_set_video_timing
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0087d50 @ 0xa0087d50 (-mcpu=v8 -Os -g)
 * Source form: two calls, one per arm, with the constant 1 or 0 written out.
 */
extern int dp_tx_reg_update_bits();

/*
 * Set or clear bit 5 (0x20) of register 0x70 of a link output.
 *   port:  link output
 *   value: non-zero = set, 0 = clear
 * Called by ipc_dispatch_command and dp_tx_set_video_timing.
 */
void dp_tx_set_reg70_bit5(unsigned char port, unsigned char value)
{
    if (value != 0)
        dp_tx_reg_update_bits(port, 0x70, 0x20, 1);
    else
        dp_tx_reg_update_bits(port, 0x70, 0x20, 0);
    return;
}
