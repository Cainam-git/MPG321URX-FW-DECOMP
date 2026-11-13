/* dp_get_vactive  (FUN_a00acb00)
 *
 * Return the active line count of a DP input: the 16-bit value of registers 0x8B / 0x8C.
 * Returns: lines
 * Name basis: derived - high byte first; fills the vactive slot of input_read_port_timing and the vactive
 *   field of the DP record, next to dp_get_hactive
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00acb00 @ 0xa00acb00, flags -mcpu=v8 -Os -g (set in symbols/leon2s.json). Same form as dp_get_hactive.
 */
extern unsigned int dp_reg_read8(unsigned int, unsigned short);

/*
 * Read the 16-bit value of receiver registers 0x8B (high byte) and 0x8C (low byte).
 * dp_run_link_state and the other callers store the result as the vactive field of the port's timing, next to
 * the values of dp_get_hactive, dp_read_reg90_word and dp_read_reg92_word.
 *   port: DP receiver
 */
unsigned short dp_get_vactive(unsigned int port)
{
    unsigned int high;

    port = port & 0xff;
    high = (dp_reg_read8(port, 0x8b) & 0xff) << 8;
    return (unsigned short)(high + (dp_reg_read8(port, 0x8c) & 0xff));
}
