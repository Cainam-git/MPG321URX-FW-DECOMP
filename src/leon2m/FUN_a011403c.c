/* leon2m FUN_a011403c @ 0xa011403c-0xa01141fc (112 words).
 * Reads n blocks of 32 bytes through the indirect register port at 0xcf011f94 into out: for block i the address
 * addr + i goes byte by byte (low byte first) to 0xcf011fa0 / fa4 / fa8 / fac, 0x80 to 0xcf011f84 and 0xcf011f8c;
 * then it waits (at most 0xffff polls) until 0xcf011f90 reads 0x80 and stores the next 32 port reads to
 * out[i * 32 ..] in groups of four, each group in ascending byte order when mode == 1, else in descending order.
 * Byte-buffer counterpart of FUN_a0113cd8. Called by FUN_a0147d70. volatile: hardware registers only.
 * Source form: unsigned short counters; flags include -msoft-float (register addresses rebuilt inside the loop).
 */
#define REG(a) (*(volatile unsigned int *)(a))

void FUN_a011403c(unsigned char *out, unsigned int addr, unsigned char n, unsigned char mode)
{
    unsigned short i, j, t;

    for (i = 0; i < n; i++) {
        REG(0xcf011fa0) = addr;
        REG(0xcf011fa4) = addr >> 8;
        REG(0xcf011fa8) = addr >> 16;
        REG(0xcf011fac) = addr >> 24;
        REG(0xcf011f84) = 0x80;
        REG(0xcf011f8c) = 0x80;
        t = 0xffff;
        while (REG(0xcf011f90) != 0x80) {
            if (--t == 0)
                break;
        }
        if (mode == 1) {
            for (j = i * 32; j < i * 32 + 32; j += 4) {
                out[j] = REG(0xcf011f94);
                out[j + 1] = REG(0xcf011f94);
                out[j + 2] = REG(0xcf011f94);
                out[j + 3] = REG(0xcf011f94);
            }
        } else {
            for (j = i * 32; j < i * 32 + 32; j += 4) {
                out[j + 3] = REG(0xcf011f94);
                out[j + 2] = REG(0xcf011f94);
                out[j + 1] = REG(0xcf011f94);
                out[j] = REG(0xcf011f94);
            }
        }
        addr++;
    }
}
