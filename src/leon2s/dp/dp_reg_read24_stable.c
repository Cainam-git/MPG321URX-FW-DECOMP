/* dp_reg_read24_stable  (FUN_a00a6f08)
 *
 * Read a DP receiver value of three registers until two reads agree (low 16 bits).
 *   port: receiver
 *   reg: first register
 * Returns: 16-bit value
 * Name basis: proven - repeats dp_reg_read24 up to 5 times and keeps 16 bits; twin of dp_tx_reg_read24_stable
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Twin of dp_tx_reg_read24_stable (here the value is an unsigned short, the result an int; callers use the
 * full register without a zero-extension).
 * Source form: one loop 'for (retries = 0; value != read && retries <= 4; retries++) value = read;' with the
 * retry counter in the branch delay slot.
 */
extern int dp_reg_read24(unsigned char, unsigned short);

/*
 * Read a DP receiver value of three registers (dp_reg_read24) until a further read gives the same low 16
 * bits. After 5 repeats it returns the last value read; only the low 16 bits are kept.
 *
 *   port: receiver 0 or 1
 *   reg:  first register
 */
int dp_reg_read24_stable(unsigned char port, unsigned short reg)
{
  unsigned short value;
  unsigned char retries;

  value = dp_reg_read24(port, reg);
  for (retries = 0; value != dp_reg_read24(port, reg) && retries <= 4; retries++)
    value = dp_reg_read24(port, reg);
  return value;
}
