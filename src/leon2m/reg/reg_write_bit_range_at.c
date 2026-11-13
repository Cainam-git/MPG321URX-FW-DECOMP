/* reg_write_bit_range_at  (FUN_a00e21a4)
 *
 * Write a value into the bits lo..hi of the word at an address.
 * Name basis: derived - mask built from the two bit positions; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e21a4 @ 0xa00e21a4, flags -mcpu=v8 -O3 -g.
 * Source form: reg_write32_copy is declared without a prototype; the call passes the merged word, the low bit
 * position, the shifted value and the two extra arguments (the callee uses only the first two).
 */
extern int reg_read32_copy();
extern int reg_write32_copy();

/*
 * Write 'value' into bits 'low'..'high' (both included) of the word at 'address'. The other bits keep their
 * value; bits of 'value' that do not fit the field are dropped. Nothing calls it.
 *
 *   extra_1, extra_2  handed on to reg_write32_copy, which does not use them
 */
void reg_write_bit_range_at(unsigned int address, int high,unsigned int low,int value,unsigned int extra_1,
                 unsigned int extra_2)

{
  unsigned int current;
  unsigned int mask;
  unsigned int field;
  
  mask = (1 << (high + 1U)) - (1 << low);
  field = value << low & mask;
  current = reg_read32_copy(address);
  reg_write32_copy(address,current & ~mask | field,low,field,extra_1,extra_2);
  return;
}
