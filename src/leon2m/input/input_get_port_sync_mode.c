/* input_get_port_sync_mode  (FUN_a0142e8c)
 *
 * Return byte +9 of a port record: the sync mode (1 = none recognised, 2..5) of the port.
 * Returns: sync mode
 * Name basis: derived - byte 9 of the 0x2A-byte port records, stored by input_port_sync_task from
 *   input_block_handle_mode_change
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142e8c @ 0xa0142e8c, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: the byte array port_records is indexed by (port & 0xff) * 0x2a + 9.
 */

extern unsigned char port_records[];            /* 0x2A bytes per port record */

#define PORT_RECORD_SIZE 0x2a
#define PORT_RECORD_SYNC_MODE 9         /* offset of the sync mode byte */

/*
 * Return the sync mode byte (offset 9) of a port record, which input_port_sync_task keeps up to date
 * (1 = no sync mode recognised, 2..5).
 *
 *   port  the port number
 */
unsigned char input_get_port_sync_mode(unsigned int port)
{
    return port_records[(port & 0xff) * PORT_RECORD_SIZE + PORT_RECORD_SYNC_MODE];
}
