/* leon2m FUN_a0084330 @ 0xa0084330-0xa00844f8 (114 words). BYTE-EXACT: -mcpu=v8 -O3 -g,
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 114 words. void(u8 reset).
 * What it does: a change detector for a measured signal of channel 1.
 *   reset != 0: byte 0xa8024020 = 0xff (no state), u16 0xa802af56 = 0, return.
 *   Else FUN_a0145660(1, 7) (input record field id 7 of channel 1; the result is not used), then
 *   FUN_a014e4b8(1, &u16 0xa8024006, &0xa8024004, &0xa802400a, &0xa8024008) fills four u16 values from block
 *   register reads; when it returns 0: return.
 *   r = (u16)((int)v06 * 10 / (int)v04) (signed sdiv);  f = 1 when |af56 - r| > 5, else 0;
 *   when |af58 - v0a| > 0x14 or |af5a - v06| > 0xf: byte counter af5c += 1, else af5a = v06, af58 = v0a, af5c = 0;
 *   when f differs from the kept state 0xa8024020 or af5c > 10: FUN_a00830f4(1), and for f == 1 also
 *   FUN_a00d7b20() and FUN_a014a8d4(1, 1, 500); then af58 = v0a, af5a = v06 (fresh reads), af5c = 0.
 *   Always at the end: af56 = r, 0xa8024020 = f.
 * Only the ratio r (10 * v06 / v04) and the two raw values decide. A ratio change of more than 0.5 (r in tenths) flips f and runs the f == 1
 * steps once; values that keep moving (> 20 / > 15 counts) for more than 10 calls re-run the steps.
 * Code facts that fix the source: f set by an if/else (the fw 'bg; mov 1' + 'clr'), abs() (sra/xor/sub), the
 * FUN_a00830f4(1) call written in BOTH arms of 'if (f == 1)' (with one common call before the if the jf score
 * was 42). volatile: none. Aids: none.
 */
extern unsigned short DAT_a8024004, DAT_a8024006, DAT_a8024008, DAT_a802400a;
extern unsigned char DAT_a8024020;
extern unsigned short DAT_a802af56, DAT_a802af58, DAT_a802af5a;
extern unsigned char DAT_a802af5c;
extern int FUN_a0145660(int, int);
extern unsigned char FUN_a014e4b8(int, unsigned short *, unsigned short *, unsigned short *, unsigned short *);
extern void FUN_a00830f4(int);
extern void FUN_a00d7b20(void);
extern void FUN_a014a8d4(int, int, int);
extern int abs(int);

void FUN_a0084330(unsigned char reset)
{
  unsigned short r;
  unsigned char f;

  if (reset) {
    DAT_a8024020 = 0xff;
    DAT_a802af56 = 0;
    return;
  }
  FUN_a0145660(1, 7);
  if (!FUN_a014e4b8(1, &DAT_a8024006, &DAT_a8024004, &DAT_a802400a, &DAT_a8024008))
    return;
  r = DAT_a8024006 * 10 / DAT_a8024004;
  if (abs(DAT_a802af56 - r) > 5)
    f = 1;
  else
    f = 0;
  if (abs(DAT_a802af58 - DAT_a802400a) > 0x14 || abs(DAT_a802af5a - DAT_a8024006) > 0xf) {
    DAT_a802af5c++;
  } else {
    DAT_a802af5a = DAT_a8024006;
    DAT_a802af58 = DAT_a802400a;
    DAT_a802af5c = 0;
  }
  if (DAT_a8024020 != f || DAT_a802af5c > 10) {
    if (f == 1) {
      FUN_a00830f4(1);
      FUN_a00d7b20();
      FUN_a014a8d4(1, 1, 500);
    } else {
      FUN_a00830f4(1);
    }
    DAT_a802af58 = DAT_a802400a;
    DAT_a802af5a = DAT_a8024006;
    DAT_a802af5c = 0;
  }
  DAT_a802af56 = r;
  DAT_a8024020 = f;
}
