/* dp_mst_get_ring_distance  (FUN_a00d9e5c)
 *
 * Return the distance between a ring's read and write index.
 * Returns: 0..15
 * Name basis: descriptive - 4-bit difference of the index pair chosen by mode
 *
 * Matching notes
 * --------------
 * FUN_a00d9e5c (leon2s 0xa00d9e5c-0xa00d9edc, 128 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: a switch (cases laid out after the compare chain) with its own unsigned int variables in each
 * case; shared variables let GCC merge the two compares after the join, unsigned char variables change the
 * registers. The firmware's shared tail ('bleu; 0x10 - d') comes from cross-jumping the two cases.
 */
extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_message_state_reply_write_indexes[];
extern unsigned char dp_mst_message_state_reply_read_indexes[];
extern unsigned char dp_mst_message_state_up_read_index;
extern unsigned char dp_mst_message_state_up_write_index;
#define RING_REPLY  2   /* mode: the down-reply ring of the current port */
#define RING_UP     4   /* mode: the up-request ring (port-independent) */

/*
 * Return how many entries a 16-entry ring holds: write index - read index, plus 0x10 when the read index is the
 * larger. `mode` selects the ring: 2 = down-reply ring of the current port, 4 = up-request ring; any other
 * value returns 0. Called by dp_mst_transmit_task to compare the two rings.
 */
unsigned char dp_mst_get_ring_distance(unsigned char mode)
{
    unsigned char distance;
    unsigned int reply_read, reply_write, up_read, up_write;

    switch (mode) {
    case RING_REPLY:
        reply_write = dp_mst_message_state_reply_write_indexes[dp_mst_message_state_port];
        reply_read = dp_mst_message_state_reply_read_indexes[dp_mst_message_state_port];
        if (reply_read <= reply_write)
            distance = reply_write - reply_read;
        else
            distance = 0x10 - (reply_read - reply_write);
        break;
    case RING_UP:
        up_write = dp_mst_message_state_up_write_index;
        up_read = dp_mst_message_state_up_read_index;
        if (up_read <= up_write)
            distance = up_write - up_read;
        else
            distance = 0x10 - (up_read - up_write);
        break;
    default:
        distance = 0;
        break;
    }
    return distance;
}
