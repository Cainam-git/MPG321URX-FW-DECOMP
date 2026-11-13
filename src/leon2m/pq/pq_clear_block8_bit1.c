/* pq_clear_block8_bit1  (FUN_a0119114)
 *
 * Clear bit 1 of register 0xCF012F74 when the chip revision is above 0x83.
 * Returns: its argument
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0119114 @ 0xa0119114, flags -mcpu=v8 -O3 -g.
 * Source form: sys_get_chip_revision is declared without a prototype, returning int, so its low byte is
 * taken here; the first argument is handed back unchanged.
 */
#define BLOCK8_F74 (*(volatile unsigned int *)0xcf012f74)
extern int sys_get_chip_revision();

#define BLOCK8_F74_BIT1     0x2             /* set by pq_enable_block8_path; while set, pq_block8_stop keeps
                                               the other block 8 bits on */
#define CHIP_REVISION_83    0x83            /* sys_get_chip_revision returns 0x80..0x84 */

/*
 * On chip revisions above 0x83 only: clear bit 1 of 0xCF012F74, the bit pq_enable_block8_path sets.
 *
 *   value   returned unchanged
 *   unused  not used
 *
 * Nothing in the firmware calls this routine directly.
 */
int pq_clear_block8_bit1(unsigned int value, unsigned int unused)
{
  unsigned int revision;

  revision = sys_get_chip_revision();
  if (CHIP_REVISION_83 < (revision & 0xff)) {
    BLOCK8_F74 = BLOCK8_F74 & ~BLOCK8_F74_BIT1;
  }
  return value;
}
