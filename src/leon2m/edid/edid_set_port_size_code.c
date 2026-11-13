/* edid_set_port_size_code  (FUN_a012c138)
 *
 * Store the EDID size code of a port.
 * Name basis: descriptive - value >> 7 in a nibble of the word at 0xA802CB08; unused
 *
 * Matching notes
 * --------------
 * FUN_a012c138 (leon2m 0xa012c138-0xa012c16c, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 */
#define SIZE_CODE_SHIFT 7                       /* a size code counts 128-byte units */

/* One 4-bit size code per port: bits 4 * port .. 4 * port + 3. */
extern unsigned int edid_port_size_codes;

/*
 * Store the size code of one port: size_bytes / 128 replaces the four bits of the port in
 * edid_port_size_codes. Nothing in the image calls this routine or stores its address.
 */
void edid_set_port_size_code(unsigned char port, unsigned short size_bytes)
{
    unsigned int shift = port * 4;

    edid_port_size_codes = ((size_bytes >> SIZE_CODE_SHIFT) << shift) | (edid_port_size_codes & ~(0xf << shift));
}
