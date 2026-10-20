/* leon2s FUN_a0091b3c @ 0xa0091b3c..0xa0091b74 (56 bytes, 14 words)  BYTE-EXACT
 * Flags: -mcpu=v8 -Os -g.
 * Judge: jf 100.00 match=True; rawcmp_l2s.py 0 mismatches / 14 words (a0091b3c a0091b74).
 * What it does (code facts): ch = param & 0xff selects a 28-byte (7-word) record of the table
 * ARR_a807d580 (fw: ch * 7 * 4 + 0xa807d580); only for ch <= 1 it sets bit 1 of record word 4 (offset +0x10).
 * Callers: FUN_a00958d4.
 * Aids: none. Draft cap was a mid-record base name (ARR_a807d584 / ARR_a807d590); the real
 * table base 0xa807d580 is the fw 'or %g1, 0x180' and the name the other ARR_a807d580 users
 * in src/leon2s use.
 */
extern unsigned int ARR_a807d580[];

void FUN_a0091b3c(unsigned char ch)
{
  unsigned int *p = &ARR_a807d580[ch * 7];

  if (ch <= 1)
    p[4] |= 2;
}
