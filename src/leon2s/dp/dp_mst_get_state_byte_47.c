/* dp_mst_get_state_byte_47  (FUN_a00dc084)
 *
 * Return the MST service's state byte at 0xA8078847.
 * Returns: byte
 * Name basis: descriptive - plain getter
 *
 * Matching notes
 * --------------
 * FUN_a00dc084 (leon2s 0xa00dc084-0xa00dc090, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 */
extern unsigned char dp_mst_message_state_byte_0x4f;
/*
 * Return dp_mst_message_state_byte_0x4f. dp_run_link_state tests it for stream 1: the stream runs only while the
 * byte is non-zero. dp_mst_handle_allocate_payload sets it to 1 or 0; dp_mst_append_chunk_to_message clears it
 * for the requests 0x10 and 0x11.
 */
unsigned char dp_mst_get_state_byte_47(void)
{
    return dp_mst_message_state_byte_0x4f;
}
