/* FUN_a00a66dc (leon2s 0xa00a66dc-0xa00a67b8, 220 bytes), flags -mcpu=v8 -Os -g.
 * Writes a 16-bit value as two byte registers of a hardware block: low byte to register reg, high byte
 * to register reg + 1. Register address = ((u16 base table DAT_a00b4d9c[n] + reg) * 4) | 0xcf000000.
 * port (arg & 0xff) 0 or 1 writes block n = port; port 2 writes blocks 0 and 1 in a loop; larger ports
 * write nothing.
 * Source forms: the inlined helper reg_addr() keeps (base + reg + 1) * 4 as add + shift; the bytes are
 * (unsigned char) casts of the unsigned short value.
 */
extern unsigned short DAT_a00b4d9c[];

static __inline__ volatile unsigned int *reg_addr(unsigned int a)
{
    return (volatile unsigned int *)((a * 4) | 0xcf000000);
}

void FUN_a00a66dc(unsigned int port, unsigned short reg, unsigned short val)
{
    unsigned char i;

    port &= 0xff;
    if (port > 2)
        return;
    if (port == 2) {
        i = 0;
        do {
            *reg_addr(DAT_a00b4d9c[i] + reg) = (unsigned char)val;
            *reg_addr(DAT_a00b4d9c[i] + reg + 1) = (unsigned char)(val >> 8);
            i++;
        } while (i <= 1);
    } else if (port <= 1) {
        *reg_addr(DAT_a00b4d9c[port] + reg) = (unsigned char)val;
        *reg_addr(DAT_a00b4d9c[port] + reg + 1) = (unsigned char)(val >> 8);
    }
}
