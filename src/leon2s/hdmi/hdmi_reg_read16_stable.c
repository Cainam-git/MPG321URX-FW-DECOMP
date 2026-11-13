/* hdmi_reg_read16_stable  (FUN_a00a6938)
 *
 * Read a 16-bit HDMI 2.0 receiver value until two reads agree.
 *   port: receiver
 *   reg: first register
 * Returns: 16-bit value
 * Name basis: proven - repeats hdmi_reg_read16 up to 5 times
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a6938 @ 0xa00a6938, flags -mcpu=v8 -Os -g.
 * Required forms: the loop form of the other stable-read routine; hdmi_reg_read16 is declared with an unsigned
 * int return, because the firmware re-extends every result (sll/srl 16 on both sides of the compare, srl at the
 * return), which a 16-bit return type removes. The value fits in 16 bits, so the wider type changes no value.
 */
extern unsigned int hdmi_reg_read16(unsigned char, unsigned short);

/* Read the 16-bit value at register reg of HDMI 2.0 receiver port (hdmi_reg_read16), read it again and
   compare. While the two differ the value is replaced by a fresh read, at most 5 times. Returns that value. */
unsigned short hdmi_reg_read16_stable(unsigned char port, unsigned short reg)
{
  unsigned int value;
  unsigned char tries;

  value = hdmi_reg_read16(port, reg);
  for (tries = 0; (unsigned short)value != (unsigned short)hdmi_reg_read16(port, reg) && tries <= 4; tries++)
    value = hdmi_reg_read16(port, reg);
  return value;
}
