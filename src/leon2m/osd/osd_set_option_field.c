/* osd_set_option_field  (FUN_a01198c8)
 *
 * Store a 2-bit option in the first or second field of the option byte.
 * Name basis: descriptive - bits 2-3 or 4-5 of the byte at 0xA802C9B0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01198c8, flags -mcpu=v8 -O3 -g.
 */
extern unsigned char osd_option_byte;

/* Store a 2-bit value in one of the two fields of the option byte.
 *   value: the new value (only bits 0..1 are used)
 *   field: 0 = bits 2..3 of the byte, any other value = bits 4..5
 */
void osd_set_option_field(unsigned int value, unsigned char field)

{
  if (field == '\0') {
    osd_option_byte = osd_option_byte & 0xf3 | (unsigned char)((value & 3) << 2);
  }
  else {
    osd_option_byte = osd_option_byte & 0xcf | (unsigned char)((value & 3) << 4);
  }
  return;
}
