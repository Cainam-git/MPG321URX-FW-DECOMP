/* osd_api_ram_put_data  (FUN_a014648c)
 *
 * Send a byte, a byte and a word, or a word as data to the memory port.
 * Name basis: derived - forwards to osd_ram_port_write_data, osd_ram_put_byte_and_word or osd_ram_put_word
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014648c, flags -mcpu=v8 -O2 -g (section default).
 * A switch with separate identical calls for cases 0 and 3 (GCC merges them); every case is a tail call.
 */
extern void osd_ram_put_byte_and_word(unsigned char first, unsigned short word, unsigned char side);
extern void osd_ram_put_word(unsigned short word, unsigned char side);
extern void osd_ram_port_write_data(unsigned char side, unsigned char v);

/* Send data to a menu layer's memory port.
 *   kind:  0 or 3 = the byte `first`; 1 = the byte `first`, then the low and high byte of `word`; 2 = the low and
 *          high byte of `word`; other values do nothing
 *   first: the byte
 *   word:  the 16-bit value
 *   layer: menu layer number, passed on as the port side (0 = port of layer 0, other = the other port)
 * Called by ShowLogo (ShowLogo).
 */
void osd_api_ram_put_data(unsigned char kind, unsigned char first, unsigned short word, unsigned char layer)
{
    switch (kind) {
    case 0:
        osd_ram_port_write_data(layer, first);
        break;
    case 1:
        osd_ram_put_byte_and_word(first, word, layer);
        break;
    case 2:
        osd_ram_put_word(word, layer);
        break;
    case 3:
        osd_ram_port_write_data(layer, first);
        break;
    }
}
