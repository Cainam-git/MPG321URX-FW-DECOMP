/* pq_get_block8_variant  (FUN_a011909c)
 *
 * Return the 4-bit variant field of register 0xCF012FDC.
 * Returns: 0..15
 * Name basis: descriptive - used as an index by the preset table look-ups
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011909c @ 0xa011909c, flags -mcpu=v8 -O3 -g.
 */
#define reg_pq_block8_variant (*(volatile unsigned int *)0xcf012fdc)

#define VARIANT_MASK 0xf                    /* bits 0..3 */

/*
 * Return bits 0..3 of register 0xCF012FDC. pq_get_block8_table_byte, pq_get_block8_table_byte_alt and
 * pq_set_block8_table_value use it as the entry number within a row of the block 8 tables.
 */
unsigned int pq_get_block8_variant(void)
{
  return reg_pq_block8_variant & VARIANT_MASK;
}
