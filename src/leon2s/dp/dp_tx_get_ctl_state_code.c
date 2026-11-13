/* dp_tx_get_ctl_state_code  (FUN_a00aa7cc)
 *
 * Return a small code (0..5, 7) decoded from a control register of a DP output.
 *   port: output
 * Returns: code, 7 when unknown
 * Name basis: descriptive - register 10 (output 0) or 99 (eDP) values 0x11/0x22/0x66/0x44/0x33;
 *   dp_tx_is_link_active tests for 4
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: the output number is masked into itself, the result is masked with 7 at the return.
 */
extern int dp_tx_ctl_reg_read8();

#define CTL_STATE_UNKNOWN 7

/*
 * Decode a state code from a control register of a DP output.
 *
 *   port: output 0..4
 *
 * Output 0 reads control register 10 and maps 0x11 -> 0, 0x22 -> 1, 0x66 -> 2, 0x44 -> 4, 0x33 -> 5. The other
 * outputs read control register 99 (0x63), keep bits 4..6 and map 0x10 -> 0, 0x20 -> 1, 0x60 -> 2, 0x40 -> 4,
 * 0x30 -> 5. Any other value gives 7. dp_tx_is_link_active asks whether the code is 4.
 */
unsigned char dp_tx_get_ctl_state_code(unsigned char port)
{
    unsigned char result;
    unsigned char val;
    
    result = CTL_STATE_UNKNOWN;
    port = port & 0xff;
    if (port == 0) {
        val = (unsigned char)(dp_tx_ctl_reg_read8(0, 10) & 0xff);
        if (val == 0x11) {
            result = 0;
        } else if (val == 0x22) {
            result = 1;
        } else if (val == 0x66) {
            result = 2;
        } else if (val == 0x44) {
            result = 4;
        } else if (val == 0x33) {
            result = 5;
        }
    } else {
        val = (unsigned char)(dp_tx_ctl_reg_read8(port, 99) & 0x70);
        if (val == 0x10) {
            result = 0;
        } else if (val == 0x20) {
            result = 1;
        } else if (val == 0x60) {
            result = 2;
        } else if (val == 0x40) {
            result = 4;
        } else if (val == 0x30) {
            result = 5;
        }
    }
    return (unsigned char)(result & 7);
}
