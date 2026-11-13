/* edid_get_port_size  (FUN_a012c16c)
 *
 * Return the stored EDID size of a port in bytes.
 * Returns: size in bytes
 * Name basis: derived - nibble of the word at 0xA802CB08 times 128; used when the internal EDID is switched
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012c16c @ 0xa012c16c (-mcpu=v8 -O3 -g)
 */
#define SIZE_CODE_SHIFT 7                       /* a size code counts 128-byte units */

/* One 4-bit size code per port: bits 4 * port .. 4 * port + 3. */
extern unsigned int edid_port_size_codes;

/*
 * Return the stored EDID size of a port in bytes: its 4-bit size code in edid_port_size_codes times 128.
 * Called by edid_enable_internal_edid.
 */
int edid_get_port_size(unsigned int port)
{
    return (edid_port_size_codes >> (port << 2) & 0xf) << SIZE_CODE_SHIFT;
}
