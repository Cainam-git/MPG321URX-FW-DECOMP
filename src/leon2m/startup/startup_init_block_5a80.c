/* startup_init_block_5a80  (FUN_a01141fc)
 *
 * Write the start values and two constant tables of the block at 0xCF015A80.
 * Name basis: descriptive - called from System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01141fc, flags -mcpu=v8 -O3 -g.
 * Source form: the two byte tables are initialised const local arrays declared in an inner block after the five
 * register stores (b before a); GCC builds them on the stack with byte stores.
 */
#define R(a) (*(volatile unsigned int *)(a))
/* Register number n is the word at address 0xCF000000 | n << 2. */
#define PREG(n) R(0xcf000000 | ((n) << 2))

/*
 * Write 0x1D, 0x11, 0xFF, 0 and 0x1D to the words 0xCF015B7C..0xCF015B8C; then the twelve bytes of table_a to the
 * registers numbered 0x56E4.. (words 0xCF015B90..0xCF015BBC) and the three bytes of table_b to the registers
 * numbered 0x56A0.. (words 0xCF015A80..0xCF015A88); last 0 to 0xCF015BC0. Called by System_Initialize.
 */
void startup_init_block_5a80(void)
{
    unsigned char i;

    R(0xcf015b7c) = 0x1d;
    R(0xcf015b80) = 0x11;
    R(0xcf015b84) = 0xff;
    R(0xcf015b88) = 0;
    R(0xcf015b8c) = 0x1d;
    {
        const unsigned char table_b[3] = { 0x01, 0x00, 0x2b };
        const unsigned char table_a[12] = { 0x01, 0x00, 0x67, 0x12, 0x68, 0xcf, 0x24, 0xd0, 0x37, 0x45, 0x38, 0x9f };

        for (i = 0; i < 12; i++)
            PREG(0x56e4 + i) = table_a[i];
        for (i = 0; i < 3; i++)
            PREG(0x56a0 + i) = table_b[i];
    }
    R(0xcf015bc0) = 0;
}
