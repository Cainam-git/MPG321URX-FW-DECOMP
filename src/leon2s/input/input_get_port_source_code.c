/* input_get_port_source_code  (FUN_a00858f0)
 *
 * Return the source code (0x51..0x81) stored for a port.
 *   record: path
 * Name basis: derived - byte +1 of the 40-byte records 0xA807A928; codes 0x51/0x61/0x71/0x81 = the four input
 *   ports (lead lesson)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00858f0 @ 0xa00858f0, flags -mcpu=v8 -Os -g.
 */

#define SOURCE_RECORD_SIZE 40       /* bytes per record of the table at 0xA807A928 */

extern unsigned char dp_tx_path_records[];

/* Return the source code (byte +1) of record 'record' of the 40-byte table at 0xA807A928: 0x51, 0x61, 0x71 or 0x81 for the four input ports. */
unsigned char input_get_port_source_code(unsigned int record)
{
    return dp_tx_path_records[(record & 0xff) * SOURCE_RECORD_SIZE + 1];
}
