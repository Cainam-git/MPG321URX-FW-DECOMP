/* hdmi_get_color_depth  (FUN_a0090dec)
 *
 * Return the bits per colour (8, 10, 12, 16) of an HDMI receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Returns: bits per colour
 * Name basis: derived - deep colour code reg 0x45 bits 0..2: 5 -> 10, 6 -> 12, 7 -> 16, else 8
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0090dec @ 0xa0090dec (-mcpu=v8 -Os -g)
 * Source form: the cases 0..4 set 8 and fall through into the default arm, which sets 8 again. The case labels
 * 0..4 must stay in the switch (the jump table starts at 0 and the compare is with 7); the first store is dead
 * and the arms share one block. A 'case 0..4: default:' label list is merged into the default (table from 5),
 * and a separate 'case 0..4: ... break;' arm leaves the default arm with one predecessor, so that if-conversion
 * moves its store in front of the range test (bgu instead of bgu,a).
 */

#define RX_REG_45   0x45

extern int hdmi_reg_read8();

/* Bits 0..2 of register 0x45 give the bits per colour: 5 -> 10, 6 -> 12, 7 -> 16, anything else -> 8.
   hdmi_is_deep_color tests the same bits; hdmi_calc_pixel_clock divides by the result. */
int hdmi_get_color_depth(unsigned char port)

{
  unsigned char bits;
  
  port = hdmi_reg_read8(port,RX_REG_45) & 0xff;
  switch(port & 7) {
  case 5:
    bits = 10;
    break;
  case 6:
    bits = 0xc;
    break;
  case 7:
    bits = 0x10;
    break;
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
    bits = 8;
  default:
    bits = 8;
  }
  return bits;
}
