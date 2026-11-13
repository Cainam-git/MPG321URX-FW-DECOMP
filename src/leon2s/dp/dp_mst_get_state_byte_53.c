/* dp_mst_get_state_byte_53  (FUN_a00dc090)
 *
 * Return the MST service's state byte at 0xA8078853.
 * Returns: byte
 * Name basis: descriptive - plain getter
 *
 * Matching notes
 * --------------
 * FUN_a00dc090 (leon2s 0xa00dc090-0xa00dc09c, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 */
extern unsigned char dp_mst_message_state_byte_0x5b;
/*
 * Return dp_mst_message_state_byte_0x5b. dp_run_link_state tests it for stream 2: the stream runs only while the
 * byte is non-zero.
 */
unsigned char dp_mst_get_state_byte_53(void)
{
    return dp_mst_message_state_byte_0x5b;
}
