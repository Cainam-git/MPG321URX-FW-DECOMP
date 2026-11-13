/* lib_write_masked_byte  (FUN_a00a6428)
 *
 * Replace the masked bits of a 32-bit word in memory and clear every bit above bit 7.
 *   target: address of a 32-bit word (a register)
 *   mask: bits to replace
 *   new_bits
 * Note: The new bits are not cut to the mask; the callers pass hardware register addresses.
 * Name basis: descriptive - *target = (new_bits | *target & ~mask) & 0xff on a 32-bit word; called by
 *   hdmi_tx_select_packet_source with register addresses
 *
 * Matching notes
 * --------------
 * FUN_a00a6428 (leon2s 0xa00a6428), flags -mcpu=v8 -Os -g.
 * Ghidra's type names (uint) are kept: the target is a 32-bit word and the result is cut to 8 bits.
 */
typedef unsigned int uint;

/*
 * Replace the bits selected by mask in the 32-bit word at target with new_bits, and clear all bits above
 * bit 7 of the result: *target = (new_bits | *target & ~mask) & 0xff. new_bits is not cut to the mask.
 * Callers pass hardware register addresses.
 */
void lib_write_masked_byte(uint *target,uint mask,uint new_bits)

{
  *target = (new_bits | *target & ~mask) & 0xff;
  return;
}
