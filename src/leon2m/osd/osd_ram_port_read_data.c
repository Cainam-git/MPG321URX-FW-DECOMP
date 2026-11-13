/* osd_ram_port_read_data  (FUN_a011cd80)
 *
 * Read one data byte from the memory port of a menu layer.
 * Returns: byte
 * Name basis: derived - data register 0xCF01178C or 0xCF0117A0, then the 160-nop delay; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011cd80, flags -mcpu=v8 -O3 -g.
 * Nothing in the image refers to it (no call, branch or address constant). One register read in each arm of the
 * if/else.
 */
/* The memory port of the menu layers has two register sets: side 0 (layer 0) and side 1 (any other layer). */
#define PORT_DELAY_NOPS 0xa0            /* every port access is followed by this many nops */
#define PORT0_DATA      0xcf01178c
#define PORT1_DATA      0xcf0117a0

/* Read one data byte from the data register of a memory port side, then wait.
 *   side: 0 = port of layer 0, any other value = the other port
 * Returns the low byte of the register.
 */
unsigned char osd_ram_port_read_data(unsigned char side)
{
    unsigned int v;
    int i;

    if (side == 0)
        v = *(volatile unsigned int *)PORT0_DATA;
    else
        v = *(volatile unsigned int *)PORT1_DATA;
    for (i = 0; i < PORT_DELAY_NOPS; i++)
        __asm__("nop");
    return v;
}
