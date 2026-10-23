/* leon2m FUN_a0113cd8 @ 0xa0113cd8-0xa0113eb4 (119 words).
 * Reads n blocks of eight words through the indirect register port at 0xcf011f94: for block i the address
 * addr + i goes byte by byte (low byte first) to 0xcf011fa0 / fa4 / fa8 / fac, 0x80 to 0xcf011f84 and 0xcf011f8c;
 * then it waits (at most 0xffff polls) until 0xcf011f90 reads 0x80 and assembles out[i * 8 + k] from four port
 * reads per word, the first read as the low byte when mode == 1, else as the high byte. Read counterpart of
 * FUN_a0113eb4. No direct callers. volatile: hardware registers only.
 * Source form: unsigned short counters; each word is built with '=' and three '|=' (stored after every read);
 * flags include -msoft-float (register addresses rebuilt inside the block loop).
 */
#define REG(a) (*(volatile unsigned int *)(a))

void FUN_a0113cd8(unsigned int *out, unsigned int addr, unsigned short n, unsigned char mode)
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
            for (j = i * 8; j < i * 8 + 8; j++) {
                out[j] = REG(0xcf011f94);
                out[j] |= REG(0xcf011f94) << 8;
                out[j] |= REG(0xcf011f94) << 16;
                out[j] |= REG(0xcf011f94) << 24;
            }
        } else {
            for (j = i * 8; j < i * 8 + 8; j++) {
                out[j] = REG(0xcf011f94) << 24;
                out[j] |= REG(0xcf011f94) << 16;
                out[j] |= REG(0xcf011f94) << 8;
                out[j] |= REG(0xcf011f94);
            }
        }
        addr++;
    }
}
