/* dp_tx_post_action_flags  (FUN_a0088f90)
 *
 * Add pending action flags for one DP output.
 *   port: DP output
 *   bits: action flags
 * Name basis: derived - ORs into the per-output halfword table that the HPD action routines read and clear
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. A leaf routine.
 * The compiler uses the byte offset port * 2 itself ('add %o0,%o0') for the halfword table.
 */
extern unsigned short dp_tx_action_flags[];

/*
 * Add bits to the pending action flags of a DP output. The HPD action routines collect and clear them with
 * dp_tx_take_action_flags.
 *
 *   port: DP output 0..4
 *   bits: action flags to add
 */
void dp_tx_post_action_flags(unsigned char port, unsigned short bits)
{
    dp_tx_action_flags[port] |= bits;
}
