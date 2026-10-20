/* leon2s FUN_a00a1bb0 @ 0xa00a1bb0..0xa00a1c74 (196 bytes, 49 words)  BYTE-EXACT
 * Flags: -mcpu=v8 -Os -g.
 * Judge: jf 100.00 match=True; rawcmp_l2s.py 0 mismatches / 49 words (a00a1bb0 a00a1c74).
 * What it does (code facts): rec = 0x34-byte record (param_1 & 0xff) of ARR_a807db00; with
 * w = rec word 1 (offset +4, re-read before every call) it sets (param_2 != 0) or clears
 * bits 0x1c in the bitmap at w + 0x24 and bits 8, 9, 10 in the bitmap at w + 0x28 through
 * FUN_a00a73ac (bit set: word [bit >> 5] |= 1 << (bit & 31)) / FUN_a00a73d4 (the clear
 * twin), and does the OPPOSITE for bit 0x19 at w + 0x34 (last call, a tail call).
 * Callers: FUN_a008ae80.
 * Aids: none. Draft cap was the mid-record base name ARR_a807db04; the fw base is 0xa807db00
 * (sethi 0xa807d800 | 0x300) with the word at +4, the name src/leon2s uses (ARR_a807db00).
 */
extern void FUN_a00a73ac(unsigned int, int);
extern void FUN_a00a73d4(unsigned int, int);
extern unsigned char ARR_a807db00[];
void FUN_a00a1bb0(unsigned int param_1, unsigned char param_2)
{
  if (param_2 != 0)
  {
    unsigned int *base = (unsigned int *)(ARR_a807db00 + ((param_1 & 0xff) * 0x34));
    FUN_a00a73ac(0x1c, base[1] + 0x24);
    FUN_a00a73ac(8, base[1] + 0x28);
    FUN_a00a73ac(9, base[1] + 0x28);
    FUN_a00a73ac(10, base[1] + 0x28);
    FUN_a00a73d4(0x19, base[1] + 0x34);
  }
  else
  {
    unsigned int *base = (unsigned int *)(ARR_a807db00 + ((param_1 & 0xff) * 0x34));
    FUN_a00a73d4(0x1c, base[1] + 0x24);
    FUN_a00a73d4(8, base[1] + 0x28);
    FUN_a00a73d4(9, base[1] + 0x28);
    FUN_a00a73d4(10, base[1] + 0x28);
    FUN_a00a73ac(0x19, base[1] + 0x34);
  }
}
