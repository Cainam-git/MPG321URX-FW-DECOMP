/* reg_set_channel_ctrl_bit  (FUN_a002e3c4)
 *
 * Set or clear bit n of register 0xCF011FC0.
 *   bit: bit number
 *   set: non-zero = set
 * Name basis: descriptive - code only; callers pass a channel number 0..7 (sys_latch_unit_event_ch0..,
 *   input_apply_8051_port_flags)
 *
 * Matching notes
 * --------------
 * flags -mcpu=v8 -O3 -g. Source forms the exact build depends on: the register is a fixed-address volatile macro
 * (not an extern), and the mask is held in an unsigned char, so only bits 0..7 can be changed. The register is
 * read and written back once in either case.
 */
/* The control register whose bits the callers set and clear one at a time. */
#define CHANNEL_CTRL_REG (*(volatile unsigned int *)0xcf011fc0)

/* Set or clear one bit of CHANNEL_CTRL_REG.
 *   bit:  bit number; only 0..7 have an effect (the mask is one byte wide)
 *   set:  non-zero sets the bit, zero clears it
 * The callers pass a small number: a constant 0..3, or a field taken from a record (channel_records status
 * word >> 12, in input_apply_8051_port_flags). */
void reg_set_channel_ctrl_bit(unsigned char bit, unsigned char set)
{
    unsigned char mask = 1 << bit;

    if (set)
        CHANNEL_CTRL_REG |= mask;
    else
        CHANNEL_CTRL_REG &= ~mask;
}
