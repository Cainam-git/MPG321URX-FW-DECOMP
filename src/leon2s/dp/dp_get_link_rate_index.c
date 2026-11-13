/* dp_get_link_rate_index  (FUN_a00ab690)
 *
 * Return the link rate of a DP receiver as an index (RBR, HBR, HBR2, HBR3, other).
 *   port: DP receiver
 * Returns: index 0..4
 * Name basis: proven - register 0x21C codes 6 / 0xA / 0x14 / 0x1E -> 0..3, else 4; caller
 *   audio_calc_dp_sample_rate
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ab690 @ 0xa00ab690, flags -mcpu=v8 -Os -g.
 * Source form: the parameter is masked to a byte, then reused for the register value.
 */
extern int dp_reg_read8();

/*
 * Turn register 0x21C of a DP receiver into an index.
 *
 * The register values 6, 10, 0x14 and 0x1E give 0, 1, 2 and 3; any other value gives 4.
 *   port: DP receiver
 * Returns: 0..4
 */
int dp_get_link_rate_index(unsigned char port)
{
  int index;

  port = port & 0xff;
  port = dp_reg_read8(port, 0x21c) & 0xff;
  index = 0;
  if (((port != 6) && (index = 1, port != 10)) && (index = 2, port != 0x14)) {
    index = (port == 0x1e) ? 3 : 4;
  }
  return index;
}
