/* osd_ram_port_write_data  (FUN_a011b3e8)
 *
 * Write one data byte to the memory port of a menu layer and wait.
 * Name basis: derived - data register 0xCF01178C or 0xCF0117A0, then the 160-nop delay
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011b3e8, flags -mcpu=v8 -O3 -g.
 * The register is picked with an if (side == 0) / else of two stores (that arm order gives the firmware branch).
 */
#define R(a) (*(volatile unsigned int *)(a))

/* The memory port of the menu layers has two register sets: side 0 (layer 0) and side 1 (any other layer). */
#define PORT_DELAY_NOPS 0xa0            /* every write to a port register is followed by this many nops */
#define PORT0_DATA      0xcf01178c
#define PORT1_DATA      0xcf0117a0

/* Write one data byte to the data register of a memory port side, then wait.
 *   side: 0 = port of layer 0, any other value = the other port
 *   v:    the byte
 * Called by osd_api_ram_put_data.
 */
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
