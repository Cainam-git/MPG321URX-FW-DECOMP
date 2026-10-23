/* FUN_a008899c (leon2s 0xa008899c-0xa0088a80, 228 bytes), flags -mcpu=v8 -Os -g.
 * For port 0, 2, 3, 4 or 1 (tested in that order): returns 1 when bit 0 of FUN_a0083710(port) is set,
 * else 2 when bit 1 of a second FUN_a0083710(port) call is set, else 0. Any other port returns 0.
 * Source form: an if/else-if chain with one arm per port value, each arm with its own two calls; the
 * result byte r starts at 0 and the function returns r & 3 (GCC merges the second calls into one block).
 */
extern unsigned char FUN_a0083710(int param_1);

unsigned char FUN_a008899c(unsigned char port)
{
    unsigned char r = 0;

    if (port == 0) {
        if (FUN_a0083710(0) & 1)
            r = 1;
        else if (FUN_a0083710(0) & 2)
            r = 2;
    } else if (port == 2) {
        if (FUN_a0083710(2) & 1)
            r = 1;
        else if (FUN_a0083710(2) & 2)
            r = 2;
    } else if (port == 3) {
        if (FUN_a0083710(3) & 1)
            r = 1;
        else if (FUN_a0083710(3) & 2)
            r = 2;
    } else if (port == 4) {
        if (FUN_a0083710(4) & 1)
            r = 1;
        else if (FUN_a0083710(4) & 2)
            r = 2;
    } else if (port == 1) {
        if (FUN_a0083710(1) & 1)
            r = 1;
        else if (FUN_a0083710(1) & 2)
            r = 2;
    }
    return r & 3;
}
