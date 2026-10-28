/* leon2m FUN_a00df588 @ 0xa00df588  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: decomp-permuter (AST mutations), judged by exact bytes
 */

extern unsigned int FUN_a00e021c(unsigned int addr);
extern void FUN_a00e0228(unsigned int addr, unsigned int val);
void FUN_a00df588(unsigned int addr, unsigned char a, unsigned char b, unsigned int v)
{
  unsigned char lo = b;
  unsigned char hi = a;
  unsigned int mask;
  if (a < b)
  {
    lo = a;
    hi = b;
  }
  mask = ((1 << hi) - (1 << lo)) + (1 << hi);
  hi = lo;
  if (((!hi) && (!hi)) && (!hi))
  {
  }
  v <<= lo;
  FUN_a00e0228(addr, (FUN_a00e021c(addr) & (~mask)) | (v & mask));
}
