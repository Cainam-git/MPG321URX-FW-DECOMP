/* hdcp_get_default_id_reversed  (FUN_a00c12d8)
 *
 * Copy a built-in 16-byte value into the caller's buffer in reverse order.
 * Name basis: descriptive - ROM data at 0x9F1C1E38
 *
 * Matching notes
 * --------------
 * FUN_a00c12d8 (leon2s 0xa00c12d8-0xa00c1314), flags -mcpu=v8 -Os -g.
 * Source form: the source is a plain (non-volatile) extern array, matching the target's ldub; the 16-bit index is
 * copied before the increment and compared after it.
 */
extern unsigned char hdcp_default_id_block[];

#define ID_BLOCK_LENGTH 16                      /* bytes of the built-in value */

/*
 * Copy the built-in 16-byte value hdcp_default_id_block into dest in reverse byte order (dest[0] = last byte).
 * InitHDCP uses it for the stored key header when the 16 bytes read from the one-time-programmable store
 * are all zero.
 */
void hdcp_get_default_id_reversed(unsigned char *dest) {
    unsigned short next = 0;
    do {
        unsigned short i = next;
        next = next + 1;
        dest[i] = hdcp_default_id_block[ID_BLOCK_LENGTH - 1 - i];
    } while (next < ID_BLOCK_LENGTH);
}
