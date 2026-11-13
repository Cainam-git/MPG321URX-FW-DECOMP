/* dp_tx_set_bits_1_1  (FUN_a00b230c)
 *
 * Forward the fixed arguments (1, 1) to a DisplayPort output routine.
 * Name basis: descriptive - tail call
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b230c @ 0xa00b230c-0xa00b2324 (6 words), flags -mcpu=v8 -Os -g.
 * dp_tx_post_action_flags(1, 1) is a tail call: the caller's return address is handed on, so the callee
 * returns straight to this routine's caller. The last word is the nop the compiler places behind such a call
 * sequence.
 */
extern void dp_tx_post_action_flags(unsigned char port, unsigned short bits);

/* Add action flag bit 0 (value 1) for DisplayPort output 1 (dp_tx_post_action_flags(1, 1)). No call
 * instruction in the firmware targets it; its address is stored at file offset 0xa4f34, in the last entry
 * (empty name) of the table of 36-byte entries {routine address, 32-byte name} that also holds
 * dbg_hdmi_menu_wrapper. */
void dp_tx_set_bits_1_1(void)
{
    dp_tx_post_action_flags(1, 1);
}
