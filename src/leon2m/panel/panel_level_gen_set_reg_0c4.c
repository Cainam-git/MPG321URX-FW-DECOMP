/* panel_level_gen_set_reg_0c4  (FUN_a0101884)
 *
 * Write two 4-bit fields of register 0xCF0160C4.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101884 @ 0xa0101884-0xa01018b0 (11 words, leaf without a register window), flags -mcpu=v8 -O3 -g.
 * Source form: two statements, a write and then a read-modify-write of the volatile register.
 */
#define LEVEL_GEN_REG_C4 (*(volatile unsigned int *)0xcf0160c4)

/*
 * Write register 0xCF0160C4 of the level generator: high_field (4 bits) in bits 4..7, then low_field (4 bits)
 * ORed into bits 0..3. The register is written twice, first with the high field alone.
 *
 * startup_init_level_generator writes (4, 1); panel_level_gen_set_target writes (0, 1).
 */
void panel_level_gen_set_reg_0c4(unsigned int high_field, unsigned int low_field)
{
    LEVEL_GEN_REG_C4 = (high_field & 0xf) << 4;
    LEVEL_GEN_REG_C4 |= low_field & 0xf;
}
