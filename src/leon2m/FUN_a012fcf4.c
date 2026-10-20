/* leon2m FUN_a012fcf4 @ 0xa012fcf4-0xa01302a4 (364 words; the asm header's "648 bytes" label is wrong, its range
 * is right) = GMDHEnableFRC (called by GlobalModeHandler state A entry FUN_a01516b0). Flags -mcpu=v8 -O3 -g.
 * What it does: m = byte DAT_a802e1a7 (DAT_a802e1a0 +7, the FRC mode 0..7); prints the s_001a5240 line with m and
 *   port 0 word0 bit 0. Switch 1 (jump table fw 0xcf1ac): per channel 1..3 FUN_a0109474(FUN_a013cda8(ch), a) and
 *   FUN_a01093a8(FUN_a013cda8(ch), b): mode 1 -> a = 1 on ch 1; 3 -> a on ch 1, 2; 4 -> a on ch 1..3; 5 -> b on
 *   ch 1; 6 -> b on ch 1, 2; 7 -> b on ch 1..3; 0, 2 and > 7 -> all 0 (modes 1 and 2 share a block that re-tests
 *   m == 1). Then FUN_a01093a8(FUN_a013cda8(0), 1 when FUN_a013d198() == 1 or FUN_a013d178() == 1, else 0);
 *   FUN_a01131d4(FUN_a0148854()); FUN_a0109844(); FUN_a01136a0() when FUN_a01423a8() != 0.
 *   Switch 2 (jump table fw 0xcf18c): FUN_a01084a8(FUN_a013cda8(ch), on) per channel 0..3 and FUN_a0109110:
 *   mode 0: ch 0 on and FUN_a0109110(on) with on = 1 when port 0 word0 bit 0 is clear, else 0; ch 1..3 off;
 *   modes 1/2/5: FUN_a0109110(1), ch 0, 1 on; 3/6: ch 0..2 on; 4/7: ch 0..3 on; each mode then
 *   FUN_a01095bc(DAT_a802e3d0 bit 26) (nothing for m > 7). DAT_a802e3d0 bit 21: ch 3 on and
 *   FUN_a0109554(FUN_a013cda8(3), 0). When m or bit 26 differ from the kept DAT_a802cb80 / DAT_a802cb81:
 *   FUN_a014e7d0() and both kept values updated.
 * The FRC channel enables depend only on the FRC mode byte m (and bits 21/26 of
 *   DAT_a802e3d0), not on the refresh rate itself; this is the function that switches the FRC channels on when
 *   the mode handler enters state A.
 * Code facts that fix the source: switch 2 is written with SEPARATE case bodies for 5, 3, 6, 4 and 7 (only
 *   1 and 2 share one label group); the bodies of 1/2 and 5, 3 and 6, 4 and 7 are identical and gcc's crossjump
 *   (flow2) merges them, so the code is the fw code. The split matters only for branch prediction: the tablejump
 *   then has 7 distinct targets at bp time (each 1/7 of the table frequency), which puts switch 2's mode-0 chain
 *   after switch 1's mode blocks in bb-reorder like the fw (with the 4 merged groups it came before them).
 *   The mode-0 test is written 'if (!(bit 0)) { on } else { off }' (fw: be to the on arm). Splitting 1/2/5 as
 *   {1},{2,5} gives the same bytes. No aids.
 */
struct Sel { unsigned char p00[7]; unsigned char b07; };
extern struct Sel DAT_a802e1a0;
extern unsigned int DAT_a802df30;
extern unsigned int DAT_a802e3d0;
extern unsigned char DAT_a802cb80, DAT_a802cb81;
extern const char s_001a5240[];
extern int FUN_a00df170();
extern unsigned char FUN_a013cda8(unsigned char ch);
extern void FUN_a0109474(unsigned char, unsigned char);
extern void FUN_a01093a8(unsigned char, unsigned char);
extern unsigned char FUN_a013d198(void);
extern unsigned char FUN_a013d178(void);
extern unsigned char FUN_a0148854(void);
extern void FUN_a01131d4(unsigned char);
extern void FUN_a0109844(void);
extern unsigned char FUN_a01423a8(void);
extern void FUN_a01136a0(void);
extern void FUN_a0109110(unsigned char);
extern void FUN_a01084a8(unsigned char bit, unsigned char on);
extern void FUN_a01095bc(unsigned char);
extern void FUN_a014e7d0(void);
extern void FUN_a0109554(int bit, unsigned char on);

void FUN_a012fcf4(void)
{
  FUN_a00df170(s_001a5240, DAT_a802e1a0.b07, DAT_a802df30 & 1);
  switch (DAT_a802e1a0.b07) {
  case 1:
  case 2:
    if (DAT_a802e1a0.b07 == 1) {
      FUN_a0109474(FUN_a013cda8(1), 1);
      FUN_a01093a8(FUN_a013cda8(1), 0);
      FUN_a0109474(FUN_a013cda8(2), 0);
      FUN_a01093a8(FUN_a013cda8(2), 0);
      FUN_a0109474(FUN_a013cda8(3), 0);
      FUN_a01093a8(FUN_a013cda8(3), 0);
      break;
    }
  default:
  case 0:
    FUN_a0109474(FUN_a013cda8(1), 0);
    FUN_a01093a8(FUN_a013cda8(1), 0);
    FUN_a0109474(FUN_a013cda8(2), 0);
    FUN_a01093a8(FUN_a013cda8(2), 0);
    FUN_a0109474(FUN_a013cda8(3), 0);
    FUN_a01093a8(FUN_a013cda8(3), 0);
    break;
  case 3:
    FUN_a0109474(FUN_a013cda8(1), 1);
    FUN_a01093a8(FUN_a013cda8(1), 0);
    FUN_a0109474(FUN_a013cda8(2), 1);
    FUN_a01093a8(FUN_a013cda8(2), 0);
    FUN_a0109474(FUN_a013cda8(3), 0);
    FUN_a01093a8(FUN_a013cda8(3), 0);
    break;
  case 4:
    FUN_a0109474(FUN_a013cda8(1), 1);
    FUN_a01093a8(FUN_a013cda8(1), 0);
    FUN_a0109474(FUN_a013cda8(2), 1);
    FUN_a01093a8(FUN_a013cda8(2), 0);
    FUN_a0109474(FUN_a013cda8(3), 1);
    FUN_a01093a8(FUN_a013cda8(3), 0);
    break;
  case 5:
    FUN_a0109474(FUN_a013cda8(1), 0);
    FUN_a01093a8(FUN_a013cda8(1), 1);
    FUN_a0109474(FUN_a013cda8(2), 0);
    FUN_a01093a8(FUN_a013cda8(2), 0);
    FUN_a0109474(FUN_a013cda8(3), 0);
    FUN_a01093a8(FUN_a013cda8(3), 0);
    break;
  case 6:
    FUN_a0109474(FUN_a013cda8(1), 0);
    FUN_a01093a8(FUN_a013cda8(1), 1);
    FUN_a0109474(FUN_a013cda8(2), 0);
    FUN_a01093a8(FUN_a013cda8(2), 1);
    FUN_a0109474(FUN_a013cda8(3), 0);
    FUN_a01093a8(FUN_a013cda8(3), 0);
    break;
  case 7:
    FUN_a0109474(FUN_a013cda8(1), 0);
    FUN_a01093a8(FUN_a013cda8(1), 1);
    FUN_a0109474(FUN_a013cda8(2), 0);
    FUN_a01093a8(FUN_a013cda8(2), 1);
    FUN_a0109474(FUN_a013cda8(3), 0);
    FUN_a01093a8(FUN_a013cda8(3), 1);
    break;
  }
  if (FUN_a013d198() == 1 || FUN_a013d178() == 1)
    FUN_a01093a8(FUN_a013cda8(0), 1);
  else
    FUN_a01093a8(FUN_a013cda8(0), 0);
  FUN_a01131d4(FUN_a0148854());
  FUN_a0109844();
  if (FUN_a01423a8())
    FUN_a01136a0();
  switch (DAT_a802e1a0.b07) {
  case 0:
    if (!(DAT_a802df30 & 1)) {
      FUN_a01084a8(FUN_a013cda8(0), 1);
      FUN_a0109110(1);
    } else {
      FUN_a01084a8(FUN_a013cda8(0), 0);
      FUN_a0109110(0);
    }
    FUN_a01084a8(FUN_a013cda8(1), 0);
    FUN_a01084a8(FUN_a013cda8(2), 0);
    FUN_a01084a8(FUN_a013cda8(3), 0);
    FUN_a01095bc((DAT_a802e3d0 >> 26) & 1);
    break;
  case 1:
  case 2:
    FUN_a0109110(1);
    FUN_a01084a8(FUN_a013cda8(0), 1);
    FUN_a01084a8(FUN_a013cda8(1), 1);
    FUN_a01084a8(FUN_a013cda8(2), 0);
    FUN_a01084a8(FUN_a013cda8(3), 0);
    FUN_a01095bc((DAT_a802e3d0 >> 26) & 1);
    break;
  case 5:
    FUN_a0109110(1);
    FUN_a01084a8(FUN_a013cda8(0), 1);
    FUN_a01084a8(FUN_a013cda8(1), 1);
    FUN_a01084a8(FUN_a013cda8(2), 0);
    FUN_a01084a8(FUN_a013cda8(3), 0);
    FUN_a01095bc((DAT_a802e3d0 >> 26) & 1);
    break;
  case 3:
    FUN_a0109110(1);
    FUN_a01084a8(FUN_a013cda8(0), 1);
    FUN_a01084a8(FUN_a013cda8(1), 1);
    FUN_a01084a8(FUN_a013cda8(2), 1);
    FUN_a01084a8(FUN_a013cda8(3), 0);
    FUN_a01095bc((DAT_a802e3d0 >> 26) & 1);
    break;
  case 6:
    FUN_a0109110(1);
    FUN_a01084a8(FUN_a013cda8(0), 1);
    FUN_a01084a8(FUN_a013cda8(1), 1);
    FUN_a01084a8(FUN_a013cda8(2), 1);
    FUN_a01084a8(FUN_a013cda8(3), 0);
    FUN_a01095bc((DAT_a802e3d0 >> 26) & 1);
    break;
  case 4:
    FUN_a0109110(1);
    FUN_a01084a8(FUN_a013cda8(0), 1);
    FUN_a01084a8(FUN_a013cda8(1), 1);
    FUN_a01084a8(FUN_a013cda8(2), 1);
    FUN_a01084a8(FUN_a013cda8(3), 1);
    FUN_a01095bc((DAT_a802e3d0 >> 26) & 1);
    break;
  case 7:
    FUN_a0109110(1);
    FUN_a01084a8(FUN_a013cda8(0), 1);
    FUN_a01084a8(FUN_a013cda8(1), 1);
    FUN_a01084a8(FUN_a013cda8(2), 1);
    FUN_a01084a8(FUN_a013cda8(3), 1);
    FUN_a01095bc((DAT_a802e3d0 >> 26) & 1);
    break;
  }
  if (DAT_a802e3d0 & 0x200000) {
    FUN_a01084a8(FUN_a013cda8(3), 1);
    FUN_a0109554(FUN_a013cda8(3), 0);
  }
  if (DAT_a802e1a0.b07 != DAT_a802cb80 || DAT_a802cb81 != ((DAT_a802e3d0 >> 26) & 1)) {
    FUN_a014e7d0();
    DAT_a802cb80 = DAT_a802e1a0.b07;
    DAT_a802cb81 = (DAT_a802e3d0 >> 26) & 1;
  }
}
