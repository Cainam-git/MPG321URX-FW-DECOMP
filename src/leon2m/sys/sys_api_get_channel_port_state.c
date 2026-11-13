/* sys_api_get_channel_port_state  (FUN_a01476e4)
 *
 * Return a 0/1 state of the port a channel is mapped to.
 * Returns: 0 or 1
 * Name basis: descriptive - forwards with the port index of the channel record; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01476e4 @ 0xa01476e4 (-mcpu=v8 -O3 -g)
 * Source form: channel_records is declared as a byte and indexed with * 0x78 in the expression; the
 * second parameter is declared and not used.
 */
extern unsigned char channel_records;       /* start of the channel records, 0x78 bytes each */
extern int input_block_get_reg6_bit6();

/* Take the port number of channel (bits 12..15 of word 0 of its channel record) and return
 * input_block_get_reg6_bit6 for that port. channel is not range-checked. unused is not used. */
unsigned char sys_api_get_channel_port_state(unsigned int channel, unsigned int unused)

{
  unsigned int port;
  
  port = *(unsigned int *)(&channel_records + (channel & 0xff) * 0x78) >> 0xc & 0xf;
  return input_block_get_reg6_bit6(port);
}
