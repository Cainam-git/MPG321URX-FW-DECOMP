/* dp_tx_write_downspread  (FUN_a008661c)
 *
 * Write the spread-spectrum setting of the link to the sink.
 *   port: output
 * Returns: 1 on success
 * Name basis: derived - DPCD 0x107 DOWNSPREAD_CTRL bit 7 from the sink caps record
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008661c (0xa008661c-0xa0086678, 23 words), flags -mcpu=v8 -Os -g.
 * Source form: '(x >> 3) & 1' with an if/else into an unsigned char (a '& 8 ? 0x80 : 0' form becomes sll 4);
 * the firmware if-converts it (srl 3 / and 1 / cmp %g0 / addx -1 / and -128 / add -128).
 */
extern unsigned char dp_tx_sink_caps_records[];                    /* 6-byte record per output */
extern unsigned char dp_tx_aux_write_byte(unsigned char, int, int, unsigned char);

/*
 * Write DPCD 0x107 (DOWNSPREAD_CTRL): 0x80 when bit 3 of byte 0 of the output's 6-byte record in
 * dp_tx_sink_caps_records is set, else 0. Returns 1 when the write succeeded.
 *   port: link output
 */
unsigned char dp_tx_write_downspread(unsigned char port)
{
  unsigned char value;
  if ((dp_tx_sink_caps_records[port * 6] >> 3) & 1)
    value = 0x80;
  else
    value = 0;
  return dp_tx_aux_write_byte(port, 0x80, 0x107, value) == 0;
}
