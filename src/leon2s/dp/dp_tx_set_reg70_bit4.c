/* dp_tx_set_reg70_bit4  (FUN_a0089758)
 *
 * Set or clear bit 4 of register 0x70 of a DP output.
 *   port: DP output
 *   on: 1 = set
 * Name basis: descriptive - mailbox command 0x55; output 0 also updates bit 0 of 0xCF018E80; read back by
 *   dp_tx_get_reg70_bit4
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. Includes the merged unreachable ret/restore tail FUN_a0089834.
 * Source form: dp_tx_reg_update_bits is declared with unsigned int parameters: its own entry extends them,
 * and a u8 prototype here makes this caller re-extend %i0. The routine returns nothing; the stub results
 * are tested as (x & 0xff) == 1.
 */
#define _DAT_cf018e80 (*(volatile unsigned int *)0xcf018e80)
extern void dp_tx_reg_update_bits(unsigned int port, unsigned int reg, unsigned int mask, unsigned int mode);
extern int dp_tx_option_enabled_stub(void);
extern int dp_tx_get_link_state(void);
extern void dp_tx_set_ctrl_bit1(unsigned char mode);

#define DP_TX_REG_0x70      0x70
#define DP_TX_REG_0x70_BIT4 0x10

/*
 * Set or clear bit 4 of register 0x70 of a DP output.
 *
 *   port: DP output 0..4
 *   on:   1 = set, any other value = clear
 *
 * Output 0 also changes register 0xCF018E80 (guarded by dp_tx_option_enabled_stub, which always returns 1):
 * switching on sets its bit 0; switching off clears bit 0 and calls dp_tx_set_ctrl_bit1(1), but only when
 * dp_tx_get_link_state() returns 0.
 * Called from the mailbox command dispatcher (ipc_dispatch_command); dp_tx_get_reg70_bit4 reads the bit back.
 */
void dp_tx_set_reg70_bit4(unsigned int port, unsigned int on)
{
    unsigned int port_masked;
    unsigned int on_masked;

    port_masked = port & 0xff;
    on_masked = on & 0xff;

    if (port_masked == 0) {
        if (on_masked == 1) {
            dp_tx_reg_update_bits(0, DP_TX_REG_0x70, DP_TX_REG_0x70_BIT4, 1);
            if ((dp_tx_option_enabled_stub() & 0xff) == 1)
                _DAT_cf018e80 |= 1;
        } else {
            dp_tx_reg_update_bits(0, DP_TX_REG_0x70, DP_TX_REG_0x70_BIT4, 0);
            if ((dp_tx_get_link_state() & 0xff) == 0) {
                if ((dp_tx_option_enabled_stub() & 0xff) == 1) {
                    _DAT_cf018e80 &= ~1;
                    dp_tx_set_ctrl_bit1(1);
                }
            }
        }
        return;
    }

    if (on_masked == 1)
        dp_tx_reg_update_bits(port_masked, DP_TX_REG_0x70, DP_TX_REG_0x70_BIT4, 1);
    else
        dp_tx_reg_update_bits(port_masked, DP_TX_REG_0x70, DP_TX_REG_0x70_BIT4, 0);
}
