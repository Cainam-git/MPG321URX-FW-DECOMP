/* osd_api_ram_seek  (FUN_a01463f8)
 *
 * Start a memory access at an address with one of the four commands.
 * Name basis: derived - forwards to osd_ram_seek_cmd_0x90 and its three twins
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01463f8, flags -mcpu=v8 -O3 -g.
 * A switch with one tail call per case.
 */
extern void osd_ram_seek_cmd_0x80(unsigned short address, unsigned char side);
extern void osd_ram_seek_cmd_0x70(unsigned short address, unsigned char side);
extern void osd_ram_seek_cmd_0x90(unsigned short address, unsigned char side);
extern void osd_ram_seek_cmd_0x40(unsigned short address, unsigned char side);

/* Start a memory access at an address of a menu layer, with the command chosen by the selector.
 *   selector: 0 = command 0x90, 1 = 0x80, 2 = 0x70, 3 = 0x40; other values do nothing
 *   address:  16-bit address in the layer's memory
 *   layer:    menu layer number, passed on as the port side (0 = port of layer 0, other = the other port)
 * Called by ShowLogo (ShowLogo).
 */
void osd_api_ram_seek(unsigned char selector, unsigned short address, unsigned char layer)
{
    switch (selector) {
    case 0:
        osd_ram_seek_cmd_0x90(address, layer);
        break;
    case 1:
        osd_ram_seek_cmd_0x80(address, layer);
        break;
    case 2:
        osd_ram_seek_cmd_0x70(address, layer);
        break;
    case 3:
        osd_ram_seek_cmd_0x40(address, layer);
        break;
    }
}
