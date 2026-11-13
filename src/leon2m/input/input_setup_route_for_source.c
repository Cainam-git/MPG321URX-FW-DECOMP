/* input_setup_route_for_source  (FUN_a00fe4a4)
 *
 * Set the routing registers for a source of class 0x51, 0x61, 0x71 or 0x81.
 * Name basis: derived - route registers 0xCF02DC04 / 0xCF02DC18 and others; called from GlobalModeHandler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fe4a4 @ 0xa00fe4a4, 137 words, flags -mcpu=v8 -O3 -g.
 * Source form: a plain switch (the compiler's case tree gives the firmware's compare order 0x61, 0x71, 0x81,
 * 0x51). The value written to 0xCF011750 goes through an unsigned char local ("and -8; or; and 0xff"; a cast of
 * the whole expression folds to "or; and 0xfa"). Only the 0xCF.. hardware registers are volatile.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_capture_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char input_format_read8(unsigned char blk, unsigned char reg);
extern void input_format_write8(unsigned char blk, unsigned char reg, unsigned char val);

/* Set the routing registers of the block for a signal code of 0x51, 0x61, 0x71 or 0x81; other codes change
 * only the last two steps below. GlobalModeHandler calls it, in its modes 1 and 2, with the mode byte (+0x0A)
 * of the source port record as the code.
 *
 *   0x51 and 0x61: clear bits 0, 1 and 4 of 0xCF02DC04; set the low three bits of 0xCF011750 to 2 (0x51) or 5
 *                  (0x61); write capture register 4 of the block: 0x8A (0x51) or 0x8E (0x61).
 *   0x71 and 0x81: set bits 0, 1 and 4 of 0xCF02DC04 and bit 0 of 0xCF02DC18; clear bit 0 of 0xCF011674 (0x71) or
 *                  set it (0x81); write capture register 4 = 0x83; clear (0x71) or set (0x81) bit 0 of
 *                  capture register 3.
 * Then in every case: clear bit 0 of capture register 0x5C, and in format register 0x40 set bit 0 and clear
 * bit 1.
 * input_get_routed_port_pair reads the choice back from the same registers. */
void input_setup_route_for_source(unsigned char block, unsigned char signal_code)
{
  unsigned char value;

  switch (signal_code) {
  case 0x51:
    R(0xcf02dc04) &= ~0x13;
    value = (R(0xcf011750) & ~7) | 2;
    R(0xcf011750) = value;
    input_capture_write8(block, 4, 0x8a);
    break;
  case 0x61:
    R(0xcf02dc04) &= ~0x13;
    value = (R(0xcf011750) & ~7) | 5;
    R(0xcf011750) = value;
    input_capture_write8(block, 4, 0x8e);
    break;
  case 0x71:
    R(0xcf02dc04) |= 0x13;
    R(0xcf02dc18) |= 1;
    R(0xcf011674) &= ~1;
    input_capture_write8(block, 4, 0x83);
    input_capture_update_bits(block, 3, 1, 0);
    break;
  case 0x81:
    R(0xcf02dc04) |= 0x13;
    R(0xcf02dc18) |= 1;
    R(0xcf011674) |= 1;
    input_capture_write8(block, 4, 0x83);
    input_capture_update_bits(block, 3, 1, 1);
    break;
  }
  input_capture_update_bits(block, 0x5c, 1, 0);
  input_format_write8(block, 0x40, (input_format_read8(block, 0x40) | 1) & ~2);
}
