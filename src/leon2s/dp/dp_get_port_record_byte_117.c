/* dp_get_port_record_byte_117  (FUN_a00b1494)
 *
 * Return byte 0x117 of a port's DisplayPort record.
 * Returns: byte
 * Name basis: descriptive - records at 0xA807DC18
 *
 * Matching notes
 * --------------
 * FUN_a00b1494 (leon2s 0xa00b1494-0xa00b14b0, 28 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Leaf routine without a register window (no save).
 */
/* One DisplayPort input record (300 bytes each, array at 0xA807DC18); only the field read here is named. */
struct dp_input_record { unsigned char _000[0x117]; unsigned char byte_0x117; unsigned char _118[0x14]; };
extern struct dp_input_record dp_input_records[];

/* Return byte 0x117 of the input record of DisplayPort input `port`. Called by dp_mst_handle_remote_i2c_read. */
unsigned char dp_get_port_record_byte_117(unsigned char port)
{
    return dp_input_records[port].byte_0x117;
}
