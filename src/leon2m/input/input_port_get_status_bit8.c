/* input_port_get_status_bit8  (FUN_a0140078)
 *
 * Return status bit 8 of a port record.
 * Returns: 0 or 1
 * Name basis: descriptive - first halfword of the 0x2A-byte port record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0140078 @ 0xa0140078, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: the byte-array label port_records is indexed by (port & 0xff) * 0x2a and
 * the halfword is read through a cast, shifted and masked.
 */

extern unsigned char port_records[];            /* 0x2A bytes per port record */

#define PORT_RECORD_SIZE 0x2a

/*
 * Return bit 8 of the status halfword (halfword 0) of a port record.
 *
 *   port  the port number
 *
 * input_port_sync_task copies this bit from flag bit 2 of the port entry (when the entry's class is 5).
 */
unsigned short input_port_get_status_bit8(unsigned int port)
{
  return *(unsigned short *)((port & 0xff) * PORT_RECORD_SIZE + (int)port_records) >> 8 & 1;
}
