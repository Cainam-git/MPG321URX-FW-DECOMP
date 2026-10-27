/* FUN_a0122250 (leon2m 0xa0122250-0xa01222c8, 120 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes 0xff, 0, 0xfd, 4, 0, 1 to the word registers 0xcf01cbb8, 0xcf01cbbc, 0xcf01c99c, 0xcf01c830, 0xcf01c804,
 * 0xcf01cbb8, then for i = 0..7 writes 0x80 >> i to 0xcf01cbb8 and 0 to 0xcf01c800. Nothing in the image refers to
 * it: no call, branch, sethi/or constant or address word. It lies between FUN_a0121f58 and FUN_a01222c8.
 */
#define RBB8 (*(volatile unsigned int *)0xcf01cbb8)
#define RBBC (*(volatile unsigned int *)0xcf01cbbc)
#define R99C (*(volatile unsigned int *)0xcf01c99c)
#define R830 (*(volatile unsigned int *)0xcf01c830)
#define R804 (*(volatile unsigned int *)0xcf01c804)
#define R800 (*(volatile unsigned int *)0xcf01c800)

void FUN_a0122250(void)
{
    unsigned char i;

    RBB8 = 0xff;
    RBBC = 0;
    R99C = 0xfd;
    R830 = 4;
    R804 = 0;
    RBB8 = 1;
    for (i = 0; i < 8; i++) {
        RBB8 = (unsigned char)(0x80 >> i);
        R800 = 0;
    }
}
