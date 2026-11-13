/* dp_tx_switch_reg_setup  (FUN_a0087db4)
 *
 * Switch a DP output between two register set-ups (regs 0x76, 0xA0, 0x67).
 *   port: output
 *   setup: set-up
 * Name basis: descriptive - en 1 and en 0 set the opposite bits; caller dp_tx_set_video_timing
 *
 * Matching notes
 * --------------
 * FUN_a0087db4 (leon2s 0xa0087db4-0xa0087e60, 172 bytes), flags -mcpu=v8 -Os -g.
 * Source form: each arm ends with its own register 0x67 call (GCC sets the shared sibling-call arguments once).
 */
extern void dp_tx_reg_update_bits(unsigned int port, short reg, unsigned int mask, unsigned int mode);

/*
 * Put a link output into one of two register set-ups. With setup 1: bit 1 of register 0x76 is cleared, bits
 * 0 and 1 of register 0xa0 and bit 6 of register 0x67 are set. With any other value the same four bits get
 * the opposite values. Called by dp_tx_set_video_timing.
 *   port:  link output
 *   setup: 1 = first set-up
 */
void dp_tx_switch_reg_setup(unsigned int port, unsigned char setup)
{
    port &= 0xff;
    if (setup == 1) {
        dp_tx_reg_update_bits(port, 0x76, 2, 0);
        dp_tx_reg_update_bits(port, 0xa0, 1, 1);
        dp_tx_reg_update_bits(port, 0xa0, 2, 1);
        dp_tx_reg_update_bits(port, 0x67, 0x40, 1);
    } else {
        dp_tx_reg_update_bits(port, 0x76, 2, 1);
        dp_tx_reg_update_bits(port, 0xa0, 1, 0);
        dp_tx_reg_update_bits(port, 0xa0, 2, 0);
        dp_tx_reg_update_bits(port, 0x67, 0x40, 0);
    }
}
