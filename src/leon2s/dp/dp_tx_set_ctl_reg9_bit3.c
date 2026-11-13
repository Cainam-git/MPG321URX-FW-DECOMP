/* dp_tx_set_ctl_reg9_bit3  (FUN_a00aa45c)
 *
 * Set or clear bit 3 of control register 9 of a DP / eDP transmitter.
 *   port: output
 *   on: 1 = set
 * Name basis: descriptive - mailbox command 0x5E (link limits); caller dp_tx_init_ports
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: dp_tx_ctl_reg_update_bits is declared without a prototype.
 */
extern int dp_tx_ctl_reg_update_bits();

/*
 * Set (on = 1) or clear bit 3 of control register 9 of a DP output's control bank.
 *
 *   port: output 0..4
 *   on:   1 = set, any other value = clear
 *
 * Called by dp_tx_init_ports (value from bit 12 of word +0x20 of the output's record) and from the mailbox
 * command dispatcher (ipc_dispatch_command).
 */
void dp_tx_set_ctl_reg9_bit3(unsigned char port, unsigned char on)
{
    if (on == 1) {
        dp_tx_ctl_reg_update_bits(port, 9, 8, 1);
    } else {
        dp_tx_ctl_reg_update_bits(port, 9, 8, 0);
    }
}
