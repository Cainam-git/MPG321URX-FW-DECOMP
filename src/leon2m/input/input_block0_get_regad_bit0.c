/* input_block0_get_regad_bit0  (FUN_a010b330)
 *
 * Return bit 0 of register 0xAD of input block 0.
 * Returns: 0 or 1
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010b330 @ 0xa010b330, flags -mcpu=v8 -O2 -g (section default).
 * Source form: input_capture_read8 is declared as unprototyped int-returning; the routine takes two (unused) int
 * parameters and returns the 64-bit expression ((unused2 << 32) | value) & 0xffffffff00000001 truncated to int.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern int input_capture_read8();

/*
 * Read register 0xAD of input block 0 and return its bit 0.
 *
 * No routine in the image calls it.
 */
int input_block0_get_regad_bit0(unsigned int unused1, unsigned int unused2)
{
    unsigned int reg;

    reg = input_capture_read8(0, 0xad);
    return CONCAT44(unused2, reg) & 0xffffffff00000001;
}
