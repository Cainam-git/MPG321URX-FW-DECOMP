/* FUN_a0108e70 (leon2m 0xa0108e70-0xa0108eec, 124 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * For c = 0..3 clears bits 4..5 of the word register 0xcf011aa0 + 4 * c and then ors in (v & 3) << 4 (two
 * read-modify-writes); other c do nothing. Nothing in the image refers to it: no call, branch, sethi/or constant or
 * address word. It lies between FUN_a0108e54 and FUN_a0108eec. Source form: a switch with the two register
 * statements written out in every case.
 */
#define RA0 (*(volatile unsigned int *)0xcf011aa0)
#define RA4 (*(volatile unsigned int *)0xcf011aa4)
#define RA8 (*(volatile unsigned int *)0xcf011aa8)
#define RAC (*(volatile unsigned int *)0xcf011aac)
void FUN_a0108e70(unsigned char c, unsigned int v)
{
    switch (c) {
    case 0:
        RA0 &= ~0x30u;
        RA0 |= (v & 3) << 4;
        break;
    case 1:
        RA4 &= ~0x30u;
        RA4 |= (v & 3) << 4;
        break;
    case 2:
        RA8 &= ~0x30u;
        RA8 |= (v & 3) << 4;
        break;
    case 3:
        RAC &= ~0x30u;
        RAC |= (v & 3) << 4;
        break;
    }
}
