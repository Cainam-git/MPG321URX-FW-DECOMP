/* irq_set_level12_source_mode  (FUN_a002a5e4)
 *
 * OR ((b & 0xFF) << a) << 16 into the level-12 mask register.
 *   a: source bit position
 *   b: mode bits
 * Note: Upper half of 0x9F020064 decides whether a source's handler runs before or after the ack; nothing
 *   calls it.
 * Name basis: descriptive - register 0x9F020064 = level-12 mask register of irq_service_level12
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002a5e4 @ 0xa002a5e4, flags -mcpu=v8 -O3 -g.
 * Source forms: reg_read32 is declared to return int here; reg_write32 is declared with six parameters and
 * gets the routine's last four parameters unchanged (the firmware never touches %i2..%i5, which the restore
 * of the tail call hands on as %o2..%o5).
 */
/* 0xa002c250 */
extern int reg_read32(unsigned int addr);
/* 0xa002c25c */
extern int reg_write32(unsigned int addr, unsigned int val, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6);

#define LEVEL12_SOURCE_MASK_REG 0x9f020064  /* source mask of level 12 (0x9F020034 + 4 * 12): the high half
                                               selects handler before acknowledge, see irq_service_level12 */

/*
 * Set bits in the high half of the level-12 source mask register: the low byte of 'mode_bits', shifted left
 * by 'source', lands at bit 16 + source upwards. Bits already set stay set. Nothing calls it.
 *
 *   source       source number within level 12
 *   mode_bits    bits to set (low byte used)
 *   pass_3 .. pass_6  not used; handed on to reg_write32 as they came
 */
void irq_set_level12_source_mode(unsigned int source, unsigned int mode_bits, unsigned int pass_3, unsigned int pass_4, unsigned int pass_5, unsigned int pass_6)
{
    unsigned int old_value;
    unsigned int new_value;

    old_value = reg_read32(LEVEL12_SOURCE_MASK_REG);
    new_value = ((mode_bits & 0xff) << source) << 16 | old_value;
    reg_write32(LEVEL12_SOURCE_MASK_REG, new_value, pass_3, pass_4, pass_5, pass_6);
}
