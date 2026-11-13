/* osd_ram_port_write_triple  (FUN_a011b428)
 *
 * Write three bytes to one of the two memory port register triples and wait.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011b428, flags -mcpu=v8 -O3 -g.
 * Nothing in the image refers to it (no call, branch or address constant).
 */
/* The memory port of the menu layers has two register sets: side 0 (layer 0) and side 1 (any other layer). */
#define PORT_DELAY_NOPS    0xa0         /* every write to a port register is followed by this many nops */
#define PORT0_ADDRESS_LOW  0xcf011784
#define PORT0_ADDRESS_MID  0xcf011788
#define PORT0_ADDRESS_HIGH 0xcf00bfcc
#define PORT1_ADDRESS_LOW  0xcf011798
#define PORT1_ADDRESS_MID  0xcf01179c
#define PORT1_ADDRESS_HIGH 0xcf00c3cc

/* Write a 24-bit address to the three address registers of a memory port side (bits 0..7, 8..15, 16..23), then
 * wait.
 *   side:    0 = port of layer 0, any other value = the other port
 *   address: the address
 */
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
