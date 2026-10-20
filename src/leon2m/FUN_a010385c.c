/* leon2m FUN_a010385c @ 0xa010385c-0xa01038c0 (25 words). BYTE-EXACT: -mcpu=v8 -O3 -g, jf 100 match=True,
 * rawcmp 0/25 (hand).
 * What it does (leaf): keeps the low byte of the hardware register 0xcf00eac8, clears bit 4 of 0xcf00eac8,
 * sets (on != 0) or clears bit 7 of the hardware register 0xcf00e9c4, then writes the kept low byte back
 * to 0xcf00eac8 (so bit 4 comes back as it was and bits 8..31 end as 0). Callers: the per-port fill colour
 * set FUN_a0145fe8 (colour-cycling chain), FUN_a009eb38 (twice), FUN_a0149bf0. It is not on the timing
 * path; it only flips the 0xcf00e9c4 bit 7 around a bit-4 clear of 0xcf00eac8.
 * Lever: the kept value is an unsigned char (the fw 'and %o3,0xff' is its zero-extension at the
 * store); 'unsigned int save ... save & 0xff' gives the same instructions with other registers.
 * volatile only on the real hardware registers (0xcf00eac8 is read twice by the firmware). Aids: none.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a010385c(unsigned char on)
{
    unsigned char save = R(0xcf00eac8);

    R(0xcf00eac8) &= ~0x10;
    if (on)
        R(0xcf00e9c4) |= 0x80;
    else
        R(0xcf00e9c4) &= ~0x80;
    R(0xcf00eac8) = save;
}
