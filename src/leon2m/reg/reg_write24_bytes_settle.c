/* reg_write24_bytes_settle  (FUN_a00f30f0)
 *
 * Write a 24-bit value to three byte registers and wait for it to settle.
 * Name basis: proven - used for the clock generator values
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f30f0 @ 0xa00f30f0, flags -mcpu=v8 -O3 -g.
 * Source form: the settle loop is a counted loop of ten volatile nops after the three stores.
 */
#define SETTLE_NOPS 10

/*
 * Write a 24-bit value to three registers that each hold one byte (bits 0..7 to reg[0], bits 8..15 to reg[1],
 * bits 16..23 to reg[2]), then wait for ten nop instructions. Used by panel_set_pll_frequency,
 * startup_init_clocks and startup_init_display_clocks.
 */
void reg_write24_bytes_settle(volatile unsigned int *reg, unsigned int value)
{
    unsigned char i;
    reg[0] = value & 0xff;
    reg[1] = value >> 8 & 0xff;
    reg[2] = value >> 16 & 0xff;
    for (i = 0; i < SETTLE_NOPS; i++) __asm__ volatile ("nop");     /* settle */
}
