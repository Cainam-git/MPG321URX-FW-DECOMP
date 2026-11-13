/* osd_ram_put_byte_and_word  (FUN_a011c998)
 *
 * Send one byte and one 16-bit value as data to the memory port.
 * Name basis: derived - three data writes through osd_ram_port_write_data
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011c998, flags -mcpu=v8 -O3 -g.
 * osd_ram_port_write_data (osd_ram_port_write_data) is defined here because GCC inlines it at -O3.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* The memory port of the menu layers has two register sets: side 0 (layer 0) and side 1 (any other layer). */
#define PORT_DELAY_NOPS 0xa0            /* every write to a port register is followed by this many nops */
#define PORT0_DATA      0xcf01178c
#define PORT1_DATA      0xcf0117a0

void osd_ram_port_write_data(unsigned char side, unsigned char v)
{
    int i;

    if (side == 0)
        R(PORT0_DATA) = v;
    else
        R(PORT1_DATA) = v;
    for (i = 0; i < PORT_DELAY_NOPS; i++)
        __asm__("nop");
}

/* Send three data bytes to the memory port: the byte first, then the low and the high byte of the 16-bit value.
 *   first: the first byte
 *   word:  the 16-bit value
 *   side:  0 = port of layer 0, any other value = the other port
 * Called by osd_api_ram_put_data.
 */
void osd_ram_put_byte_and_word(unsigned char first, unsigned short word, unsigned char side)
{
    osd_ram_port_write_data(side, first);
    osd_ram_port_write_data(side, word);
    osd_ram_port_write_data(side, word >> 8);
}
