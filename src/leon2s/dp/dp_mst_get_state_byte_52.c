/* dp_mst_get_state_byte_52  (FUN_a00dc09c)
 *
 * Return the MST service's state byte at 0xA8078852.
 * Returns: byte
 * Name basis: descriptive - plain getter
 *
 * Matching notes
 * --------------
 * FUN_a00dc09c (leon2s 0xa00dc09c-0xa00dc0a8, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 */
extern unsigned char dp_mst_message_state_byte_0x5a;
/*
 * Return dp_mst_message_state_byte_0x5a. dp_run_link_state tests it for stream 3: the stream runs only while the
 * byte is non-zero.
 */
unsigned char dp_mst_get_state_byte_52(void)
{
    return dp_mst_message_state_byte_0x5a;
}
