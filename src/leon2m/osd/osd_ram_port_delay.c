/* osd_ram_port_delay  (FUN_a011b3cc)
 *
 * Wait for 160 idle instructions between two memory port writes.
 * Name basis: derived - nop loop used after each port write; unused as a routine of its own
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011b3cc, flags -mcpu=v8 -O2 -g.
 * Nothing in the image refers to it (no call, branch or address constant). The loop counter is unused, so GCC
 * counts it down from 0x9f to -1.
 */
#define PORT_DELAY_NOPS 0xa0            /* every write to a memory port register is followed by this many nops */

/* Run 160 nop instructions: the pause the memory port routines leave after a port write. */
void osd_ram_port_delay(void)
{
    int i;
    for (i = 0; i < PORT_DELAY_NOPS; i++)
        __asm__("nop");
}
