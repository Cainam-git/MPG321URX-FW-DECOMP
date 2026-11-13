/* dp_get_port_record_byte_129  (FUN_a00b14b0)
 *
 * Return byte 0x129 of a port's DisplayPort record, 0 for other ports.
 * Returns: byte
 * Name basis: descriptive - records at 0xA807DC18
 *
 * Matching notes
 * --------------
 * FUN_a00b14b0 (leon2s 0xa00b14b0-0xa00b14dc, 44 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: early return of 0 (a result variable adds a final and 0xff).
 */
extern unsigned char dp_input_records[][300];

/* Return byte 0x129 of the 300-byte input record of DisplayPort input `port` (array at 0xA807DC18);
 * 0 for any port above 1. */
unsigned char dp_get_port_record_byte_129(unsigned char port)
{
    if (port > 1)
        return 0;
    return dp_input_records[port][0x129];
}
