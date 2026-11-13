/* panel_vx1_write_test_sequence  (FUN_a0122250)
 *
 * Write a register sequence to the V-by-One block and shift a walking bit through it.
 * Name basis: descriptive - registers 0xCF01C8xx and 0xCF01CBB8; unused
 *
 * Matching notes
 * --------------
 * FUN_a0122250 (leon2m 0xa0122250-0xa01222c8, 120 bytes, leaf), flags -mcpu=v8 -O3 -g.
 */
#define REG_CBB8 (*(volatile unsigned int *)0xcf01cbb8)
#define REG_CBBC (*(volatile unsigned int *)0xcf01cbbc)
#define REG_C99C (*(volatile unsigned int *)0xcf01c99c)
#define REG_C830 (*(volatile unsigned int *)0xcf01c830)
#define REG_C804 (*(volatile unsigned int *)0xcf01c804)
#define REG_C800 (*(volatile unsigned int *)0xcf01c800)

/*
 * Write a fixed sequence to registers of the 0xCF01C800..0xCF01CBBC block: 0xFF to 0xCF01CBB8, 0 to 0xCF01CBBC,
 * 0xFD to 0xCF01C99C, 4 to 0xCF01C830, 0 to 0xCF01C804, 1 to 0xCF01CBB8. Then, for bit = 0..7, write
 * (0x80 >> bit) to 0xCF01CBB8 followed by 0 to 0xCF01C800, so a single set bit moves from bit 7 down to bit 0.
 * No routine in the image calls it.
 */
void panel_vx1_write_test_sequence(void)
{
    unsigned char bit;

    REG_CBB8 = 0xff;
    REG_CBBC = 0;
    REG_C99C = 0xfd;
    REG_C830 = 4;
    REG_C804 = 0;
    REG_CBB8 = 1;
    for (bit = 0; bit < 8; bit++) {
        REG_CBB8 = (unsigned char)(0x80 >> bit);
        REG_C800 = 0;
    }
}
