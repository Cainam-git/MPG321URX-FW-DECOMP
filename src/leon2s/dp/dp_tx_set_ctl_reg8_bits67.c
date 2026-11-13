/* dp_tx_set_ctl_reg8_bits67  (FUN_a00aa49c)
 *
 * Set bits 6 and 7 of control register 8 of a DP / eDP transmitter by mode.
 *   port: output
 *   mode
 * Name basis: descriptive - mode 3/2/1/other -> (1,1)/(1,0)/(0,1)/(0,0); mailbox command 0x5E
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. The second update call is a tail call.
 */
extern void dp_tx_ctl_reg_update_bits(unsigned int, unsigned short, unsigned int, unsigned int);

/*
 * Set bits 7 and 6 of control register 8 of a DP output's control bank from a 2-bit mode: bit 7 is set for
 * modes 2 and 3, bit 6 for modes 1 and 3; any other value clears both.
 *
 *   port: output 0..4
 *   mode: 0..3
 *
 * Called by dp_tx_init_ports (mode from bits 13..14 of word +0x20 of the output's record) and from the
 * mailbox command dispatcher (ipc_dispatch_command).
 */
void dp_tx_set_ctl_reg8_bits67(unsigned char port, unsigned char mode)
{
    if (mode == 3) {
        dp_tx_ctl_reg_update_bits(port, 8, 0x80, 1);
        dp_tx_ctl_reg_update_bits(port, 8, 0x40, 1);
    } else if (mode == 2) {
        dp_tx_ctl_reg_update_bits(port, 8, 0x80, 1);
        dp_tx_ctl_reg_update_bits(port, 8, 0x40, 0);
    } else if (mode == 1) {
        dp_tx_ctl_reg_update_bits(port, 8, 0x80, 0);
        dp_tx_ctl_reg_update_bits(port, 8, 0x40, 1);
    } else {
        dp_tx_ctl_reg_update_bits(port, 8, 0x80, 0);
        dp_tx_ctl_reg_update_bits(port, 8, 0x40, 0);
    }
}
