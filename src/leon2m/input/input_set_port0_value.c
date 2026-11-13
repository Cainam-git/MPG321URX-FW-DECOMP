/* input_set_port0_value  (FUN_a0142e80)
 *
 * Store a 16-bit value in port record 0.
 * Name basis: descriptive - halfword at 0xA802E234
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142e80 @ 0xa0142e80, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 */

extern unsigned short port_records_half_0x10;       /* halfword +0x10 of port record 0 */

/*
 * Store a value in halfword +0x10 of port record 0 (the field that input_set_port_mode sets to 1000 or 100).
 */
void input_set_port0_value(unsigned short value)
{
  port_records_half_0x10 = value;
}
