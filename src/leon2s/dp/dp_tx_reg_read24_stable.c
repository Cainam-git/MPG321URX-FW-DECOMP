/* dp_tx_reg_read24_stable  (FUN_a00a7a5c)
 *
 * Read a 24-bit DP / eDP transmitter value until two reads agree.
 *   port: output
 *   reg: first register
 * Returns: 24-bit value
 * Name basis: proven - repeats dp_tx_reg_read24 up to 5 times
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Twin of dp_reg_read24_stable (an int here, no 16-bit truncation); the result is returned as an int without
 * extension.
 */
extern int dp_tx_reg_read24(unsigned char, unsigned short);

/*
 * Read a 24-bit value of a DP transmitter output (dp_tx_reg_read24) until a further read gives the same
 * value. After 5 repeats it returns the last value read.
 *
 *   port: output 0..4
 *   reg:  first register
 */
int dp_tx_reg_read24_stable(unsigned char port, unsigned short reg)
{
  int value;
  unsigned char retries;

  value = dp_tx_reg_read24(port, reg);
  for (retries = 0; value != dp_tx_reg_read24(port, reg) && retries <= 4; retries++)
    value = dp_tx_reg_read24(port, reg);
  return value;
}
