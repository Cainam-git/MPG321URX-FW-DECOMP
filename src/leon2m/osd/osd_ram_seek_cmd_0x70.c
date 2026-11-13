/* osd_ram_seek_cmd_0x70  (FUN_a011c830)
 *
 * Start a memory access with command 0x70 at a 16-bit address.
 * Name basis: derived - twin of osd_ram_seek_cmd_0x90 with command 0x70
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011c830, flags -mcpu=v8 -O3 -g.
 * Same code as osd_ram_seek_cmd_0x90 (osd_ram_seek_cmd_0x90) with command 0x70, written out in one routine: the command
 * write, a delay loop, the address bytes and the second delay loop.
 */
#define REG(a) (*(volatile unsigned int *)(a))

/* The memory port of the menu layers has two register sets: side 0 (layer 0) and side 1 (any other layer). */
#define PORT_DELAY_NOPS    0xa0         /* every write to a port register is followed by this many nops */
#define PORT0_COMMAND      0xcf011780
#define PORT0_ADDRESS_LOW  0xcf011784
#define PORT0_ADDRESS_MID  0xcf011788
#define PORT0_ADDRESS_HIGH 0xcf00bfcc
#define PORT1_COMMAND      0xcf011794
#define PORT1_ADDRESS_LOW  0xcf011798
#define PORT1_ADDRESS_MID  0xcf01179c
#define PORT1_ADDRESS_HIGH 0xcf00c3cc

#define COMMAND_WRITE_CELLS 0x70        /* command of this routine */

/* Start a memory access of a menu layer with command 0x70, the command osd_ram_write_cells sends before it
 * writes cells: write the command, then the 16-bit address (low byte, high byte, and 0 as the third byte), each
 * followed by the port delay.
 *   address: 16-bit address
 *   side:    0 = port of layer 0, any other value = the other port
 * Called through osd_api_ram_seek (selector 2).
 */
void osd_ram_seek_cmd_0x70(unsigned short address, unsigned char side)
{
    int i;
    unsigned int w;

    if (side == 0)
        REG(PORT0_COMMAND) = COMMAND_WRITE_CELLS;
    else
        REG(PORT1_COMMAND) = COMMAND_WRITE_CELLS;
    for (i = 0; i < PORT_DELAY_NOPS; i++)
        __asm__("nop");
    w = address;
    if (side == 0) {
        REG(PORT0_ADDRESS_LOW) = w & 0xff;
        REG(PORT0_ADDRESS_MID) = w >> 8;
        REG(PORT0_ADDRESS_HIGH) = 0;
    } else {
        REG(PORT1_ADDRESS_LOW) = w & 0xff;
        REG(PORT1_ADDRESS_MID) = w >> 8;
        REG(PORT1_ADDRESS_HIGH) = 0;
    }
    for (i = 0; i < PORT_DELAY_NOPS; i++)
        __asm__("nop");
}
