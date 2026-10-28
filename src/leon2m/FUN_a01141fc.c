/* leon2m FUN_a01141fc @ 0xa01141fc-0xa011433c (80 words), -mcpu=v8 -O3 -g. Called by FUN_a015209c.
 * Writes 0x1d, 0x11, 0xff, 0 and 0x1d to the registers 0xcf015b7c..0xcf015b8c, then the twelve bytes
 * 01 00 67 12 68 cf 24 d0 37 45 38 9f to the word registers 0xcf015b90..0xcf015bbc (PREG(0x56e4 + i), register
 * number n at 0xcf000000 | n << 2) and the three bytes 01 00 2b to 0xcf015a80..0xcf015a88 (PREG(0x56a0 + i)), and
 * finally 0 to 0xcf015bc0.
 * Source form: the two byte tables are initialised const local arrays declared in an inner block after the five
 * register stores (b before a); GCC builds them on the stack with byte stores.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define PREG(n) R(0xcf000000 | ((n) << 2))

void FUN_a01141fc(void)
{
    unsigned char i;

    R(0xcf015b7c) = 0x1d;
    R(0xcf015b80) = 0x11;
    R(0xcf015b84) = 0xff;
    R(0xcf015b88) = 0;
    R(0xcf015b8c) = 0x1d;
    {
        const unsigned char b[3] = { 0x01, 0x00, 0x2b };
        const unsigned char a[12] = { 0x01, 0x00, 0x67, 0x12, 0x68, 0xcf, 0x24, 0xd0, 0x37, 0x45, 0x38, 0x9f };

        for (i = 0; i < 12; i++)
            PREG(0x56e4 + i) = a[i];
        for (i = 0; i < 3; i++)
            PREG(0x56a0 + i) = b[i];
    }
    R(0xcf015bc0) = 0;
}
