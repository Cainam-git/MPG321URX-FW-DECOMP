/* input_get_internal_path2_source  (FUN_a00fe3ec)
 *
 * Return the source 1..3 selected for internal signal path 2.
 * Returns: 1..3
 * Name basis: derived - bits of 0xCF0116E0 or 0xCF0116D4 by chip revision; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fe3ec @ 0xa00fe3ec, flags -mcpu=v8 -O3 -g.
 * Source form (as in the writer): the register is read as an if/else of two loads into an unsigned char, then
 * masked.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define PATH_REG_NEW 0xcf0116e0
#define PATH_REG_OLD 0xcf0116d4
#define CHIP_REVISION_LIMIT 0x81

extern unsigned char sys_get_chip_revision(void);

/* Return the source (1, 2 or 3) of internal path 2 that Set_INTERNAL_2_INPUT_Path stored: 3 when bit 5 of the
 * path register is set, 2 when bit 3 is set, else 1. Nothing calls this routine. */
unsigned char input_get_internal_path2_source(void)
{
    unsigned char path_bits;
    unsigned int source;

    if (sys_get_chip_revision() > CHIP_REVISION_LIMIT)
        path_bits = R(PATH_REG_NEW);
    else
        path_bits = R(PATH_REG_OLD);
    path_bits &= 0x28;
    if (path_bits == 0x20)
        source = 3;
    else if (path_bits == 0x08)
        source = 2;
    else
        source = 1;
    return source;
}
