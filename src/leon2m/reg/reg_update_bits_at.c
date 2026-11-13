/* reg_update_bits_at  (FUN_a00df51c)
 *
 * Replace the masked bits of the word at an address.
 * Name basis: derived - read, merge, write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df51c @ 0xa00df51c, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: reg_write32_copy is declared without a prototype, so the call passes the merged word, the
 * masked new value and the three extra arguments the firmware passes on (the callee uses only the first two).
 */
extern int reg_read32_copy();
extern int reg_write32_copy();

/*
 * Change the bits of the word at 'address' that are set in 'mask' to the same bits of 'value'; the other
 * bits keep their value. Called by mwb_from_phy.
 *
 *   address, mask, value  as above
 *   extra_1 .. extra_3    handed on to reg_write32_copy, which does not use them
 */
void reg_update_bits_at(unsigned int address,unsigned int mask,unsigned int value,unsigned int extra_1,
                 unsigned int extra_2,unsigned int extra_3)

{
  unsigned int current;
  
  current = reg_read32_copy(address);
  reg_write32_copy(address,current & ~mask | value & mask,value & mask,extra_1,
               extra_2,extra_3);
  return;
}
