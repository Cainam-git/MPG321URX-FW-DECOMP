/* reg_update_bits_at_copy  (FUN_a00e2180)
 *
 * Replace the masked bits of the word at an address.
 * Note: Identical copy of reg_update_bits_at.
 * Name basis: derived - read, merge, write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e2180 @ 0xa00e2180, flags -mcpu=v8 -O2 -g (the section default). Same code as
 * reg_update_bits_at.
 * Source form: reg_write32_copy is declared without a prototype, so the call passes the merged word, the
 * masked new value and the three extra arguments (the callee uses only the first two).
 */
extern int reg_read32_copy();
extern int reg_write32_copy();

/*
 * Change the bits of the word at 'address' that are set in 'mask' to the same bits of 'value'; the other
 * bits keep their value. Called by sys_ddr_run_script.
 *
 *   address, mask, value  as above
 *   extra_1 .. extra_3    handed on to reg_write32_copy, which does not use them
 */
void reg_update_bits_at_copy(unsigned int address,unsigned int mask,unsigned int value,unsigned int extra_1,
                 unsigned int extra_2,unsigned int extra_3)

{
  unsigned int current;
  
  current = reg_read32_copy(address);
  reg_write32_copy(address,current & ~mask | value & mask,value & mask,extra_1,
               extra_2,extra_3);
  return;
}
