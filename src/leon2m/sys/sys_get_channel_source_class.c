/* sys_get_channel_source_class  (FUN_a013cda8)
 *
 * Return the port field of a channel when it is 1, 2 or 3, else 0.
 * Returns: 1..3 or 0
 * Name basis: descriptive - bits 12..15 of the first word of the channel record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013cda8 @ 0xa013cda8, flags -mcpu=v8 -O3 -g.
 * Source form: the return type is a 32-bit unsigned and the parameter is not narrowed to a byte in the
 * declaration; the nested if/else chain below is the form that matches.
 */
/* Size of a channel record in bytes; the port is in bits 12..15 of its first word. */
#define CHANNEL_RECORD_SIZE 0x78

extern unsigned char channel_records;

/*
 * Return the port of channel `ch` when it is 1, 2 or 3; return 0 for port 0 and for any port above 3.
 * The callers pass the result to sys_frc_set_source_class_enable, which handles the source classes 1, 2 and 3.
 *
 *   ch  channel number (only the low byte is used)
 */
unsigned int sys_get_channel_source_class(unsigned int ch)
{
  unsigned char result;
  int port;

  port = *(unsigned int *)(&channel_records + (ch & 0xff) * CHANNEL_RECORD_SIZE) >> 0xc & 0xf;
  result = 0;
  if (port == 1) {
    result = 1;
  }
  else if (1 < port) {
    if (port == 2) {
      result = 2;
    }
    else if (port == 3) {
      result = 3;
    }
  }
  return result;
}
