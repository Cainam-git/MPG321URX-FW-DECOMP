/* dp_tx_set_reg11_mode  (FUN_a0088ee0)
 *
 * Set or clear the register 0x11 / 0x66 mode of a DP output.
 *   port: output
 *   on: 1 = on
 * Name basis: descriptive - 0x1B to 0x11 and 0x28 to 0x66 when on, 0 to 0x11 when off; caller
 *   ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. The last register write is a tail call shared by both arms.
 */
extern void dp_tx_reg_write8(unsigned char, unsigned short, unsigned char);

/*
 * Write registers 0x11 and 0x66 of a DP output: 0x1B and 0x28 when on, otherwise 0 to register 0x11 only.
 *
 *   port: DP output 0..4
 *   on:   non-zero = write the values, 0 = clear register 0x11
 *
 * Called from the mailbox command dispatcher (ipc_dispatch_command). Register 0x11 = 0x1B / 0 is also what
 * dp_tx_update_edp_post_pattern writes for the printed 'EDPPostPattern' switch of eDP outputs 1..4.
 */
void dp_tx_set_reg11_mode(unsigned char port, unsigned char on)
{
    if (on != 0) {
        dp_tx_reg_write8(port, 0x11, 0x1b);
        dp_tx_reg_write8(port, 0x66, 0x28);
    } else {
        dp_tx_reg_write8(port, 0x11, 0);
    }
}
