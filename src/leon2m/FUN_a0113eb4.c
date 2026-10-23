/* leon2m FUN_a0113eb4 @ 0xa0113eb4-0xa011403c (98 words).
 * Writes n blocks of 32 bytes from p to the indirect register port at 0xcf011f88: for block i the address addr + i
 * goes byte by byte (low byte first) to 0xcf011fa0 / fa4 / fa8 / fac, 0x80 to 0xcf011f84, then the 32 bytes
 * p[i * 32 ..] in groups of four, each group in ascending byte order when mode == 1, else in descending order.
 * Called by FUN_a0110fb4. volatile: hardware registers only.
 * Source form: unsigned short counters (block and byte index); flags include -msoft-float (the register address
 * constants are rebuilt inside the block loop instead of being hoisted).
 */
#define REG(a) (*(volatile unsigned int *)(a))

void FUN_a0113eb4(const unsigned char *p, unsigned int addr, unsigned char n, unsigned char mode)
{
    unsigned short i, j;

    for (i = 0; i < n; i++) {
        REG(0xcf011fa0) = addr;
        REG(0xcf011fa4) = addr >> 8;
        REG(0xcf011fa8) = addr >> 16;
        REG(0xcf011fac) = addr >> 24;
        REG(0xcf011f84) = 0x80;
        if (mode == 1) {
            for (j = i * 32; j < i * 32 + 32; j += 4) {
                REG(0xcf011f88) = p[j];
                REG(0xcf011f88) = p[j + 1];
                REG(0xcf011f88) = p[j + 2];
                REG(0xcf011f88) = p[j + 3];
            }
        } else {
            for (j = i * 32; j < i * 32 + 32; j += 4) {
                REG(0xcf011f88) = p[j + 3];
                REG(0xcf011f88) = p[j + 2];
                REG(0xcf011f88) = p[j + 1];
                REG(0xcf011f88) = p[j];
            }
        }
        addr++;
    }
}
