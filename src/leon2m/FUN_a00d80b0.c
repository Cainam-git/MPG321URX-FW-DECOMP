/* leon2m FUN_a00d80b0 @ 0xa00d80b0-0xa00d80d8 (10 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 10 words.
 * Code facts: FUN_a014a428(0xc, byte 0xa802d290+0x1d); tail FUN_a014a428(0xd, re-read rec+0x1d)
 * (the fw loads the byte twice, once per call). void(void).
 * Fix vs the autoc draft (70.00): real base DAT_a802d290 as a struct (draft: DAT_a802d2ad mid-record name),
 * the byte is read at each call (the draft cached it in one local). Aids: none.
 */
struct R290 { unsigned char pad[0x1d]; unsigned char b1d; };
extern struct R290 DAT_a802d290;
extern void FUN_a014a428(unsigned char, unsigned char);

void FUN_a00d80b0(void)
{
  struct R290 *p = &DAT_a802d290;

  FUN_a014a428(0xc, p->b1d);
  FUN_a014a428(0xd, p->b1d);
}
