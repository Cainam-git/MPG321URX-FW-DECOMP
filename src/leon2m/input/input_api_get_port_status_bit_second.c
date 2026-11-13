/* input_api_get_port_status_bit_second  (FUN_a0144200)
 *
 * Return the bit of the second port status word for a port code.
 * Returns: 0 or 1
 * Name basis: descriptive - port codes 0x51/0x61/0x71/0x81 = bits 0..3; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0144200 @ 0xa0144200, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: the same code as input_api_get_port_status_bit (an unsigned char local that starts at
 * 0xff and is set in the cases of a switch).
 */

extern int input_get_port_status_bit_second();

/*
 * Return the bit of the second port status word (port_present_mask_alt, 0xA802CA00) for a port code.
 *
 *   port_code  0x51, 0x61, 0x71, 0x81 give bits 0 to 3; any other code asks for bit 0xFF
 *   unused     not used
 */
unsigned char input_api_get_port_status_bit_second(unsigned char port_code, unsigned int unused)
{
    unsigned char bit = 0xff;

    switch (port_code) {
    case 0x51: bit = 0; break;
    case 0x61: bit = 1; break;
    case 0x71: bit = 2; break;
    case 0x81: bit = 3; break;
    }
    return input_get_port_status_bit_second(bit);
}
