/* osd_ram_port_write_command  (FUN_a011b4b0)
 *
 * Write a command byte to the memory port of a menu layer and wait.
 * Name basis: derived - command register 0xCF011780 or 0xCF011794; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011b4b0, flags -mcpu=v8 -O3 -g.
 * Nothing in the image refers to it (no call, branch or address constant). One register write in each arm of the
 * if/else.
 */
/* The memory port of the menu layers has two register sets: side 0 (layer 0) and side 1 (any other layer). */
#define PORT_DELAY_NOPS 0xa0            /* every write to a port register is followed by this many nops */
#define PORT0_COMMAND   0xcf011780
#define PORT1_COMMAND   0xcf011794
#define REG380 (*(volatile unsigned int *)PORT0_COMMAND)
#define REG394 (*(volatile unsigned int *)PORT1_COMMAND)

/* Write a command byte to the command register of a memory port side, then wait.
 *   side:    0 = port of layer 0, any other value = the other port
 *   command: the command byte
 */
void osd_ram_port_write_command(unsigned char side, unsigned char command)
{
    int i;

    if (side == 0)
        REG380 = command;
    else
        REG394 = command;
    for (i = 0; i < PORT_DELAY_NOPS; i++)
        __asm__("nop");
}
