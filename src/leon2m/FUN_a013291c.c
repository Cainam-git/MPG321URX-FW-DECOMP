/* leon2m FUN_a013291c @ 0xa013291c (-mcpu=v8 -O3 -g)
 * Finished by hand from mechanical Ghidra C. Per-port 4-bit field lookup: for port 0-3 takes
 * bits 12-15 of word 30*port in the table at 0xa802df30, any other port gets 0xff; the byte is
 * passed to FUN_a0142fe4 and its low byte returned. Needs a byte temporary to match.
 * Still needs a real name and proper types.
 */
extern unsigned int DAT_a802df30[]; /* 0xa802df30 */
extern int FUN_a0142fe4(unsigned char x); /* 0xa0142fe4 */

unsigned int FUN_a013291c(unsigned int x)
{
    unsigned int v = x & 0xff;
    unsigned char r;
    if (v > 3) {
        r = -1;
    } else {
        r = (DAT_a802df30[v * 30] >> 12) & 0xf;
    }
    return FUN_a0142fe4(r) & 0xff;
}
