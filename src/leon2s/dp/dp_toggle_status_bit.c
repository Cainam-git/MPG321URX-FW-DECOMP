/* dp_toggle_status_bit  (FUN_a00af464)
 *
 * Bring bit 0 of register 0x461 of a port to the state given by a flag, changing it only if it differs.
 * Name basis: descriptive - one register read and three bit updates per arm, the bit changed only when it
 *   differs from the flag
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00af464 @ 0xa00af464-0xa00af524 (48 words incl. the merged ret/restore tail), -mcpu=v8 -Os -g.
 * Source form: each arm holds its own three calls inside the bit test. -Os code hoisting then moves the shared
 * sibcall arguments (0x30, 0x80, 0) above the test in both arms, and crossjumping merges the two final calls
 * into one, as in the firmware. Early returns with one shared final call give a different layout.
 */
extern unsigned char dp_reg_read8(unsigned char, unsigned short);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);

/*
 * Bring bit 0 of register 0x461 of the port to the wanted state. It is changed only when it differs: if on is 1
 * and the bit is clear it is set; if on is not 1 and the bit is set it is cleared. The change is made with
 * bit 7 of register 0x30 set around it.
 *   port: DP receiver (0 or 1)
 *   on: 1 = the bit should be set, anything else = clear
 * Called from dp_run_link_state.
 */
void dp_toggle_status_bit(unsigned char port, unsigned char on)
{
    if (on == 1) {
        if ((dp_reg_read8(port, 0x461) & 1) == 0) {
            dp_reg_update_bits(port, 0x30, 0x80, 1);
            dp_reg_update_bits(port, 0x461, 1, 1);
            dp_reg_update_bits(port, 0x30, 0x80, 0);
        }
    } else {
        if (dp_reg_read8(port, 0x461) & 1) {
            dp_reg_update_bits(port, 0x30, 0x80, 1);
            dp_reg_update_bits(port, 0x461, 1, 0);
            dp_reg_update_bits(port, 0x30, 0x80, 0);
        }
    }
}
