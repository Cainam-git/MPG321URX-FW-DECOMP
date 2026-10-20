/* leon2m FUN_a0124df8 @ 0xa0124df8 (-mcpu=v8 -O2 -g)
 * This computes the table pointer (sethi/or, smul, add) before the comparison, matching the target's ordering. The function reads three bytes from the table entry and calls func with them if the first isn't 0xff.
 */
extern int func_0x4008c86c();

void FUN_a0124df8(unsigned int param_1)

{
  unsigned char *table;
  unsigned int idx;
  
  idx = param_1 & 0xff;
  table = (unsigned char *)0x1a42a8 + idx * 0x16;
  if (idx <= 7) {
    if (table[0xe] != 0xff) {
      func_0x4008c86c(table[0xe],table[0xf],table[0x10]);
    }
  }
  return;
}
