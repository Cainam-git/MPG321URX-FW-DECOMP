/* FUN_a00c0a88 (leon2s 0xa00c0a88-0xa00c0b48, 192 bytes), flags -mcpu=v8 -Os -g.
 * Saves the low byte of the hardware register 0xcf011674 and sets its bits 3 and 4. Writes a[0..4] to the
 * registers (0x6349 + i) << 2 | 0xcf000000 (0xcf018d24..0xcf018d34), then b[0..0x119] to consecutive words from
 * 0xcf037800, clears register 0xcf011780 and writes the saved byte back to 0xcf011674.
 * Source forms: unsigned short loop counters; the second destination is a volatile word pointer that is
 * incremented; volatile only on the 0xcf... hardware registers.
 */
#define REG_674 (*(volatile unsigned int *)0xcf011674)
#define REG_780 (*(volatile unsigned int *)0xcf011780)

void FUN_a00c0a88(unsigned char *a, unsigned char *b)
{
    unsigned char saved = REG_674;
    unsigned short i;
    volatile unsigned int *p;

    REG_674 |= 0x18;
    for (i = 0; i < 5; i++)
        *(volatile unsigned int *)(((i + 0x6349) << 2) | 0xcf000000) = a[i];
    p = (volatile unsigned int *)0xcf037800;
    for (i = 0; i < 0x11a; i++)
        *p++ = b[i];
    REG_780 = 0;
    REG_674 = saved;
}
