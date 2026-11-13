/* dp_reg_read16_stable  (FUN_a00a6e8c)
 *
 * Read a 16-bit DP receiver value until two reads agree.
 *   port: receiver
 *   reg: first register
 * Returns: 16-bit value
 * Name basis: proven - repeats dp_reg_read16 up to 5 times
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Same code as hdmi_reg_read16_stable.
 */
extern unsigned int dp_reg_read16(unsigned char, unsigned short);

/*
 * Read a 16-bit DP receiver value (dp_reg_read16) until a further read gives the same value. After 5 repeats
 * it returns the last value read.
 *
 *   port: receiver 0 or 1
 *   reg:  first register
 */
unsigned short dp_reg_read16_stable(unsigned char port, unsigned short reg)
{
  unsigned int value;
  unsigned char retries;

  value = dp_reg_read16(port, reg);
  for (retries = 0; (unsigned short)value != (unsigned short)dp_reg_read16(port, reg) && retries <= 4; retries++)
    value = dp_reg_read16(port, reg);
  return value;
}
