/* pq_pivot_update_counter  (FUN_a010a4d0)
 *
 * Copy a quarter of a 16-bit counter into the rotation block.
 * Name basis: descriptive - registers 0xCF01EAC4 / 0xCF01EAC0; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010a4d0 @ 0xa010a4d0 (34 instructions), flags -mcpu=v8 -O3 -g.
 * Source form: the reg_read16_bytes arm is the early-return unsigned short function read_converter_counter,
 * as in pq_pivot_setup_timing, which holds an inlined copy of this routine.
 */
/* Names as in pq_pivot_setup_timing. */
#define FRC_OUTPUT_SELECT 0xcf011a80        /* bit 0 and bit 7 choose where the counter is read */
#define FRC_OUTPUT_SELECT_BIT0 0x01
#define FRC_OUTPUT_SELECT_BIT7 0x80
#define FRC_COUNTER_A 0xcf011ad8            /* byte register pairs read with reg_read16_bytes */
#define FRC_COUNTER_B 0xcf011c18
#define PIVOT_COUNTER_LOW 0xcf01eac4
#define PIVOT_COUNTER_HIGH 0xcf01eac0       /* bit 7 set together with the counter's high byte */

#define R(a) (*(volatile unsigned int *)(a))
extern int pq_block_read_reg64_word_copy(unsigned char);
extern int reg_read16_bytes(int);

/* The converter pair: FRC_COUNTER_A when bit 7 of FRC_OUTPUT_SELECT is set, else FRC_COUNTER_B. */
static unsigned short read_converter_counter(void)
{
  if (R(FRC_OUTPUT_SELECT) & FRC_OUTPUT_SELECT_BIT7)
    return reg_read16_bytes(FRC_COUNTER_A);
  return reg_read16_bytes(FRC_COUNTER_B);
}

/*
 * Copy a quarter of a 16-bit counter into the pivot block.
 *
 * The counter is register 0x64 of picture block 0 (pq_block_read_reg64_word_copy) when bit 0 of
 * FRC_OUTPUT_SELECT is set, else one of the two converter register pairs (read_converter_counter). The value
 * shifted right by 2 goes to PIVOT_COUNTER_LOW (low byte) and PIVOT_COUNTER_HIGH (high byte with bit 7 set).
 *
 * Nothing calls this routine; pq_pivot_setup_timing, which nothing calls either, holds an inlined copy.
 */
void pq_pivot_update_counter(void)
{
  unsigned short counter;
  if (R(FRC_OUTPUT_SELECT) & FRC_OUTPUT_SELECT_BIT0)
    counter = pq_block_read_reg64_word_copy(0);   /* picture block 0, register 0x64 */
  else
    counter = read_converter_counter();
  counter >>= 2;
  R(PIVOT_COUNTER_LOW) = counter & 0xff;
  R(PIVOT_COUNTER_HIGH) = (counter >> 8) | 0x80;
}
