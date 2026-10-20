/* FUN_a0140098 (leon2m), range 0xa0140098-0xa01400bc (9 words), flags -mcpu=v8 -O3 -g.
 * Code facts: returns bit 'bit' of the RAM byte DAT_a802cbd4 as 0/1: ldub the byte, sra by the
 * u8 param (in %o0), btst 1, then the 0/1 flag is re-masked with 'and 1' at the join (retl delay slot).
 * Source form: 'u8 r = 0; if (...) r = 1; return r & 1;' (_Bool drops the and 1).
 * Twin: FUN_a01400bc (same code on the neighbouring byte). Aids: none.
 */
extern unsigned char DAT_a802cbd4;

unsigned char FUN_a0140098(unsigned char bit)
{
  unsigned char r = 0;
  if (((int)DAT_a802cbd4 >> bit) & 1)
    r = 1;
  return r & 1;
}
