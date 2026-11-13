/* sys_frc_derive_output_sizes  (FUN_a0109844)
 *
 * Derive the converter's output size registers from its input size registers.
 * Name basis: descriptive - halved or scaled by 10/3 and rounded to 32, by bits of 0xCF011D8C; called from
 *   GMDHEnableFRC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0109844 @ 0xa0109844, flags -mcpu=v8 -O3 -g.
 * Source form: the two halves are written out in full; the 16-bit arithmetic uses unsigned short locals.
 */
#define REG(a) ((volatile unsigned int *)(a))
extern unsigned int reg_read16_bytes(volatile unsigned int *p);
extern void reg_write16_bytes(volatile unsigned int *r, unsigned int v);

/*
 * Compute the converter's two output size registers from its two input size registers, under control of the low
 * byte of the register 0xCF011D8C (called `flags` below):
 *
 *   flags bit 0 clear   0 goes to 0xCF011F64
 *   flags bit 0 set     0xCF011DE0 is read; with flags bit 1 clear the result is half of it. With bit 1 set
 *                       the result is size * 10 / 3; when that is not a multiple of 10 it becomes result / 10 + 1;
 *                       when it is then not a multiple of 32 it is rounded up to the next multiple of 32.
 *                       The result goes to 0xCF011F64.
 *   flags bits 2 and 3  the same for 0xCF011E00, written to 0xCF011F6C.
 *
 * All arithmetic is 16 bit. Called by GMDHEnableFRC.
 */
void sys_frc_derive_output_sizes(void)
{
    unsigned char flags = *REG(0xcf011d8c);
    unsigned short input_size, output_size;

    if (flags & 1) {
        input_size = reg_read16_bytes(REG(0xcf011de0));
        if (flags & 2) {
            output_size = input_size * 10 / 3;
            if (output_size % 10)
                output_size = output_size / 10 + 1;
            if (output_size & 0x1f)
                output_size = (output_size >> 5 << 5) + 0x20;
        } else
            output_size = input_size >> 1;
        reg_write16_bytes(REG(0xcf011f64), output_size);
    } else {
        reg_write16_bytes(REG(0xcf011f64), 0);
    }
    if (flags & 4) {
        input_size = reg_read16_bytes(REG(0xcf011e00));
        if (flags & 8) {
            output_size = input_size * 10 / 3;
            if (output_size % 10)
                output_size = output_size / 10 + 1;
            if (output_size & 0x1f)
                output_size = (output_size >> 5 << 5) + 0x20;
        } else
            output_size = input_size >> 1;
        reg_write16_bytes(REG(0xcf011f6c), output_size);
    } else {
        reg_write16_bytes(REG(0xcf011f6c), 0);
    }
}
