/* leon2m FUN_a00f6898 @ 0xa00f6898-0xa00f6940 (42 words). -mcpu=v8 -O3 -g.
 * What it does (leaf): sets enable bits in two hardware registers chosen by p; the set-twin of
 * src/leon2m/FUN_a00f67d0.c (which clears bit 0/1 of 0xcf00ec80 / 0xcf00eca8):
 *   p 0: 0xcf00ec80 |= 1, 0xcf00ee40 |= 3      p 1: 0xcf00ec80 |= 2, 0xcf00ee40 |= 0xc
 *   p 2: 0xcf00eca8 |= 1, 0xcf00ee68 |= 3      p 3: 0xcf00eca8 |= 2, 0xcf00ee68 |= 0xc
 *   other p: nothing. Each value is written back masked to 8 bits (bits 8..31 end as 0).
 * Both registers are READ FIRST, then both are written (fw: ld A, ld B, st A, st B), so the source keeps
 * the two read values in locals before the two stores (volatile keeps that order). Callers: the channel
 * bring-up dc6c and FUN_a012d554. This is the per-port enable step of the bring-up; it does not
 * depend on the rate.
 * Lever: the reads-first order (one statement per register gave ld/st/ld/st); a plain switch gives the fw
 * compare tree 'cmp 1; be; bcc'. volatile only on the real hardware registers. Aids: none.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00f6898(unsigned int p)
{
    unsigned int a, b;

    switch (p) {
    case 0:
        a = R(0xcf00ec80); b = R(0xcf00ee40);
        R(0xcf00ec80) = (a | 1) & 0xff; R(0xcf00ee40) = (b | 3) & 0xff;
        break;
    case 1:
        a = R(0xcf00ec80); b = R(0xcf00ee40);
        R(0xcf00ec80) = (a | 2) & 0xff; R(0xcf00ee40) = (b | 0xc) & 0xff;
        break;
    case 2:
        a = R(0xcf00eca8); b = R(0xcf00ee68);
        R(0xcf00eca8) = (a | 1) & 0xff; R(0xcf00ee68) = (b | 3) & 0xff;
        break;
    case 3:
        a = R(0xcf00eca8); b = R(0xcf00ee68);
        R(0xcf00eca8) = (a | 2) & 0xff; R(0xcf00ee68) = (b | 0xc) & 0xff;
        break;
    }
}
