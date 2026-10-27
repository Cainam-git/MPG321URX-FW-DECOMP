/* FUN_a0101b78 (leon2m 0xa0101b78-0xa0101bb0, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 1 when bit 3 of the word register 0xcf0160c0 is set and bits 5..6 (0x60) of the word register 0xcf0160f4
 * are clear, otherwise 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It
 * lies between FUN_a0101b60 and FUN_a0101bb0.
 */
#define REGC0 (*(volatile unsigned int *)0xcf0160c0)
#define REGF4 (*(volatile unsigned int *)0xcf0160f4)

int FUN_a0101b78(void)
{
    if ((REGC0 & 8) && (REGF4 & 0x60) == 0)
        return 1;
    return 0;
}
