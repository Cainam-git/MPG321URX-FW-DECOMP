/* FUN_a00f6ab4 (leon2m 0xa00f6ab4-0xa00f6b34, 128 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears bit 6 (c = 0 or 4) or bit 7 (c = 1) of the word register 0xcf00ee40, or bit 6 (c = 2) or bit 7 (c = 3) of
 * 0xcf00ee68; other c do nothing. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a00f6940 and FUN_a00f6b34. Source form: a switch with a jump table (run-time 0x963a8,
 * image 0xa00f63a8).
 */
#define R40 (*(volatile unsigned int *)0xcf00ee40)
#define R68 (*(volatile unsigned int *)0xcf00ee68)

void FUN_a00f6ab4(unsigned int c)
{
    switch (c) {
    case 0:
    case 4:
        R40 &= ~0x40u;
        break;
    case 1:
        R40 &= ~0x80u;
        break;
    case 2:
        R68 &= ~0x40u;
        break;
    case 3:
        R68 &= ~0x80u;
        break;
    }
}
