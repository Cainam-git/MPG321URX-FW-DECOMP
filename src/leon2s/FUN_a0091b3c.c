/* leon2s FUN_a0091b3c @ 0xa0091b3c..0xa0091b74 (56 bytes, 14 words)
 * Flags: -mcpu=v8 -Os -g.
 * ch = param & 0xff selects a 28-byte (7-word) record of the table ARR_a807d580 (firmware:
 * ch * 7 * 4 + 0xa807d580); only for ch <= 1 it sets bit 1 of record word 4 (offset +0x10).
 * Callers: FUN_a00958d4.
 * The table base 0xa807d580 is the firmware 'or %g1, 0x180', the name the other ARR_a807d580 users in
 * src/leon2s use.
 */
extern unsigned int ARR_a807d580[];

void FUN_a0091b3c(unsigned char ch)
{
  unsigned int *p = &ARR_a807d580[ch * 7];

  if (ch <= 1)
    p[4] |= 2;
}
