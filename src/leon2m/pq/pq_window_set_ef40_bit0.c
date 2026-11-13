/* pq_window_set_ef40_bit0  (FUN_a00f6fac)
 *
 * Write bit 0 of register 0xCF00EF40 when the chip revision is above 0x83.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6fac @ 0xa00f6fac, flags -mcpu=v8 -O3 -g.
 */

#define PQ_REG_EF40 (*(volatile unsigned int *)0xcf00ef40)
#define CHIP_REVISION_83 0x83           /* only revisions above this one have the bit */

extern int sys_get_chip_revision();

/*
 * Copy bit 0 of 'value' into bit 0 of register 0xCF00EF40, keeping bits 1..7 (the bits above 7 are written
 * as 0). On chip revisions up to 0x83 nothing is written. No caller of this routine is found in the firmware,
 * and no other routine uses the register.
 *   value   bit 0 is written
 *   unused  not used
 */
void pq_window_set_ef40_bit0(unsigned int value, unsigned int unused)
{
    unsigned int revision;

    revision = sys_get_chip_revision();
    if ((revision & 0xff) > CHIP_REVISION_83) {
        PQ_REG_EF40 = PQ_REG_EF40 & 0xfe | value & 1;
    }
}
