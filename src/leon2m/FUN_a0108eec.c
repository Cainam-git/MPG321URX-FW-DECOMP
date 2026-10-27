/* FUN_a0108eec (leon2m 0xa0108eec-0xa0108f70, 132 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * For c = 1..3 clears bits 0..2 of the word register 0xcf011aa0 + 4 * c and then ors in v & 7 (two
 * read-modify-writes); other c do nothing. Nothing in the image refers to it: no call, branch, sethi/or constant or
 * address word. It lies between FUN_a0108e70 and FUN_a0108f70. Source form: a switch with the two register
 * statements written out in every case; v is an unsigned char.
 */
#define RA4 (*(volatile unsigned int *)0xcf011aa4)
#define RA8 (*(volatile unsigned int *)0xcf011aa8)
#define RAC (*(volatile unsigned int *)0xcf011aac)
void FUN_a0108eec(unsigned char c, unsigned char v)
{
    switch (c) {
    case 1:
        RA4 &= ~7u;
        RA4 |= v & 7;
        break;
    case 2:
        RA8 &= ~7u;
        RA8 |= v & 7;
        break;
    case 3:
        RAC &= ~7u;
        RAC |= v & 7;
        break;
    }
}
