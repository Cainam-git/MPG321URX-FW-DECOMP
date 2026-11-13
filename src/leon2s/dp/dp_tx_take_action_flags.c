/* dp_tx_take_action_flags  (FUN_a0088fb0)
 *
 * Return and clear the pending action flags of one DP output.
 *   port: DP output 0..4
 * Returns: action flags
 * Name basis: derived - read-and-clear of the table dp_tx_post_action_flags fills; callers the HPD action
 *   routines
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the byte offset (port & 0xff) * 2 is formed first and the table is indexed with offset / 2; the
 * target uses the doubled offset in lduh / clrh.
 */
extern unsigned short dp_tx_action_flags[];

/*
 * Return the pending action flags of a DP output and clear them.
 *
 *   port: DP output 0..4
 *
 * The flags are set by dp_tx_post_action_flags; dp_tx_run_hpd_actions and dp_tx_edp_run_hpd_actions call this
 * routine.
 */
unsigned short dp_tx_take_action_flags(unsigned int port)
{
    unsigned short flags;
    int byte_offset;

    byte_offset = (port & 0xff) * 2;
    flags = dp_tx_action_flags[byte_offset / 2];
    dp_tx_action_flags[byte_offset / 2] = 0;
    return flags;
}
