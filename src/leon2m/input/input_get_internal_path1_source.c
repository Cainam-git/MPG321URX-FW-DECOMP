/* input_get_internal_path1_source  (FUN_a00fe184)
 *
 * Return the source 1..3 selected for internal signal path 1.
 * Returns: 1..3
 * Name basis: derived - bits of 0xCF0116E0 or 0xCF0116D4 by chip revision; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fe184 @ 0xa00fe184, flags -mcpu=v8 -O3 -g.
 * Source form (as in the writer): the register is read as an if/else of two loads into an unsigned char, then
 * masked.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define PATH_REG_NEW 0xcf0116e0
#define PATH_REG_OLD 0xcf0116d4
#define CHIP_REVISION_LIMIT 0x81

extern unsigned char sys_get_chip_revision(void);

/* Return the source (1, 2 or 3) of internal path 1 that Set_INTERNAL_1_INPUT_Path stored: 3 when bit 6 of the
 * path register is set, 2 when bit 4 is set, else 1. Nothing calls this routine. */
unsigned char input_get_internal_path1_source(void)
{
    unsigned char path_bits;
    unsigned int source;

    if (sys_get_chip_revision() > CHIP_REVISION_LIMIT)
        path_bits = R(PATH_REG_NEW);
    else
        path_bits = R(PATH_REG_OLD);
    path_bits &= 0x50;
    if (path_bits == 0x40)
        source = 3;
    else if (path_bits == 0x10)
        source = 2;
    else
        source = 1;
    return source;
}
