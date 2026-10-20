/* leon2m FUN_a0099440 @ 0xa0099440-0xa00994b8 (30 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 30 words.
 * Code facts: toggles bit 15 (0x8000) of the word at 0xa802d290+0x174 (one ld; btst; both the andn and the or
 * value are computed before the branch, one st per arm); FUN_a00aa0e8(word 0xa802afec - 0xe, as u8, 1);
 * FUN_a00aacb4(1, 1); FUN_a00db690(); byte 0xa802b08e |= 2. void(void).
 * Fix vs the autoc draft (68.75): real base DAT_a802d290 (draft used mid-record _DAT_a802d404 as a u16 and an
 * unconditional |= plus a conditional overwrite); if/else of the &= / |= mask forms (a 1-bit bit-field gives
 * srl + btst 1); no volatile on the RAM byte 0xa802b08e. Aids: none.
 */
struct R290 { unsigned char pad[0x174]; unsigned int w174; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern unsigned int _DAT_a802afec;
extern void FUN_a00aa0e8(unsigned char, int);
extern void FUN_a00aacb4(int, int);
extern void FUN_a00db690(void);

void FUN_a0099440(void)
{
  if (DAT_a802d290.w174 & 0x8000)
    DAT_a802d290.w174 &= ~0x8000;
  else
    DAT_a802d290.w174 |= 0x8000;
  FUN_a00aa0e8(_DAT_a802afec - 0xe, 1);
  FUN_a00aacb4(1, 1);
  FUN_a00db690();
  DAT_a802b08e |= 2;
}
