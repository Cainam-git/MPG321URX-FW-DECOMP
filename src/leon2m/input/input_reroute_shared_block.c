/* input_reroute_shared_block  (FUN_a00fde94)
 *
 * Move the shared route to another free input block when it points at a given block.
 * Name basis: descriptive - register 0xCF02010C; used when a port's mode changes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fde94 @ 0xa00fde94, 44 words, flags -mcpu=v8 -O3 -g.
 * Source form: the byte value is built in two statements (value = n << 4; value |= n;) with an if/else for
 * the range test; the counter is an unsigned char.
 */
#define SHARED_ROUTE_REG (*(volatile unsigned int *)0xcf02010c)
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);

/* If the shared route register (0xCF02010C) points at the block, move it to another block.
 * The register holds (n << 4) | n for a block n from 0 to 7 (input_set_shared_route writes that form).
 * When it holds the form of the given block, the first other block i (0 to 7) whose register 4 has bits 0-1
 * clear and whose register 3 has bit 5 clear is written to it as (i << 4) | i. Otherwise nothing is written.
 * Called by input_set_port_mode when a port leaves one of the modes 0x11 to 0x13 or 0x21. */
void input_reroute_shared_block(unsigned char block)
{
    unsigned char route;
    unsigned char i;

    if (block > 7)
        route = 0;
    else {
        route = block << 4;
        route |= block;
    }
    if (SHARED_ROUTE_REG == route) {
        for (i = 0; i <= 7; i++) {
            if (i != block) {
                if (!(input_capture_read8(i, 4) & 3)) {
                    if (!(input_capture_read8(i, 3) & 0x20)) {
                        route = i << 4;
                        route |= i;
                        SHARED_ROUTE_REG = route;
                        return;
                    }
                }
            }
        }
    }
}
