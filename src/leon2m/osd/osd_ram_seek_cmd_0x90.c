/* osd_ram_seek_cmd_0x90  (FUN_a011c6c8)
 *
 * Start a memory access with command 0x90 at a 16-bit address.
 * Name basis: derived - command 0x90, the two address bytes and 0, with a delay before and after
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011c6c8, flags -mcpu=v8 -O3 -g.
 * The command and address steps are the firmware's own osd_ram_port_write_command (osd_ram_port_write_command) and
 * osd_ram_port_write_triple (osd_ram_port_write_triple), defined here and inlined; the 16-bit address is passed to the unsigned
 * int address parameter (the sll/srl narrowing), so the third address byte is 0.
 */
#define R(a) (*(volatile unsigned int *)(a))

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

#define COMMAND_PLANE_1    0x90         /* command of this routine */

void osd_ram_port_write_triple(unsigned char side, unsigned int address)
{
    int i;

    if (side == 0) {
        *(volatile unsigned int *)PORT0_ADDRESS_LOW = address & 0xff;
        *(volatile unsigned int *)PORT0_ADDRESS_MID = (address >> 8) & 0xff;
        *(volatile unsigned int *)PORT0_ADDRESS_HIGH = (address >> 16) & 0xff;
    } else {
        *(volatile unsigned int *)PORT1_ADDRESS_LOW = address & 0xff;
        *(volatile unsigned int *)PORT1_ADDRESS_MID = (address >> 8) & 0xff;
        *(volatile unsigned int *)PORT1_ADDRESS_HIGH = (address >> 16) & 0xff;
    }
    for (i = 0; i < PORT_DELAY_NOPS; i++)
        __asm__("nop");
}

void osd_ram_port_write_command(unsigned char side, unsigned char command)
{
    int i;

    if (side == 0)
        R(PORT0_COMMAND) = command;
    else
        R(PORT1_COMMAND) = command;
    for (i = 0; i < PORT_DELAY_NOPS; i++)
        __asm__("nop");
}

/* Start a memory access of a menu layer with command 0x90: write the command, then the 16-bit address (low
 * byte, high byte, and 0 as the third byte), each followed by the port delay.
 *   address: 16-bit address
 *   side:    0 = port of layer 0, any other value = the other port
 * COMMAND_PLANE_1 is also the command osd_ram_write_index_run sends for plane 1. Called through osd_api_ram_seek
 * (selector 0).
 */
void osd_ram_seek_cmd_0x90(unsigned short address, unsigned char side)
{
    osd_ram_port_write_command(side, COMMAND_PLANE_1);
    osd_ram_port_write_triple(side, address);
}
