/* pq_api_set_gamma_lut_options  (FUN_a014e0d4)
 *
 * Set the two option bits of the gamma look-up table from a value 0..3.
 * Name basis: descriptive - two bits to 0xCF00EAC0.7 and 0xCF00EAC8.6, the block the gamma table writes use;
 *   unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e0d4 @ 0xa014e0d4-0xa014e144 (28 words), flags -mcpu=v8 -O2 -g (section default).
 * Source form: a switch with one tail call per case.
 */
extern void pq_gamma_set_lut_options(unsigned char, unsigned char);

/*
 * Split a value 0..3 into two option bits for pq_gamma_set_lut_options: bit 1 is its first argument, bit 0 its
 * second. A first argument of 0 sets bit 7 of register 0xCF00EAC0 (1 clears it); a second argument of 0 sets
 * bit 6 of 0xCF00EAC8 (1 clears it). While bit 7 of 0xCF00EAC0 is set, pq_gamma_write_primary_lut repeats the
 * last entry of a block that ends at entry 0x100 as entry 0x100.
 *
 *   options  0..3; any other value does nothing
 *
 * Nothing in the firmware calls this routine.
 */
void pq_api_set_gamma_lut_options(unsigned char options)
{
    switch (options) {
    case 0:
        pq_gamma_set_lut_options(0, 0);
        break;
    case 1:
        pq_gamma_set_lut_options(0, 1);
        break;
    case 2:
        pq_gamma_set_lut_options(1, 0);
        break;
    case 3:
        pq_gamma_set_lut_options(1, 1);
        break;
    }
}
