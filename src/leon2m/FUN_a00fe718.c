/* FUN_a00fe718 (leon2m 0xa00fe718-0xa00fe7d8, 192 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Reads m = register 0xcf0116dc & 0x3f; for c = 0, 1, 2 sets bit 5 of the word register 0xcf02dc04 and writes m, m
 * | 0x80 or m | 0xc0 back to 0xcf0116dc; for c = 3 clears bit 5 of 0xcf02dc04. Called by gap (4 calls). It lies
 * between FUN_a00fe6c8 and FUN_a00fe7d8. Source form: m is an unsigned char local read before the switch.
 */
#define R16DC (*(volatile unsigned int *)0xcf0116dc)
#define RDC04 (*(volatile unsigned int *)0xcf02dc04)
void FUN_a00fe718(unsigned char c)
{
    unsigned char m = R16DC & 0x3f;
    switch (c) {
    case 0:
        RDC04 |= 0x20;
        R16DC = m;
        break;
    case 1:
        RDC04 |= 0x20;
        R16DC = m | 0x80;
        break;
    case 2:
        RDC04 |= 0x20;
        R16DC = m | 0xc0;
        break;
    case 3:
        RDC04 &= ~0x20u;
        break;
    }
}
