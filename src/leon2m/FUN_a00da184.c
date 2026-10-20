/* leon2m FUN_a00da184 @ 0xa00da184-0xa00da254 (52 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 52 words.
 * Code facts: FUN_a00d99f8(2, 1); FUN_a014a8d4(4, 1, 1000); if FUN_a01445fc(FUN_a014448c(0)) != 0 and bit 20
 * (0x100000) of the word at 0xa802d290+0xac is set: u16 at 0xa802cff4+0xa |= 0x40 and FUN_a00869b0(0x14, 5000)
 * (arm out of line). Then FUN_a0089f6c(); FUN_a0148268(0, 1); FUN_a0148268(1, 1); FUN_a0151aa4(0xf, 1);
 * FUN_a014a768(0xc, bit 7 of the word at 0xa802d290+0xa8); tail FUN_a014a768(0xd, same bit re-read). void.
 * Fix vs the autoc draft (67.31): BEHAVIOUR: FUN_a014448c(0) runs FIRST and its u8 result is the argument of
 * FUN_a01445fc, whose return is the tested value (the draft called them in the other order with no args);
 * real bases DAT_a802d290 / DAT_a802cff4 (draft: mid-record words d338/d33c/cffe); the tail call has 2 args.
 * Aids: none.
 */
struct Rcff4 { unsigned char pad[0xa]; unsigned short h0a; };
extern struct Rcff4 DAT_a802cff4;
struct R290 { unsigned char pad[0xa8]; unsigned int wa8; unsigned int wac; };
extern struct R290 DAT_a802d290;
extern void FUN_a00d99f8(int, int);
extern void FUN_a014a8d4(int, int, int);
extern unsigned char FUN_a014448c(int);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a00869b0(int, int);
extern void FUN_a0089f6c(void);
extern void FUN_a0148268(int, int);
extern void FUN_a0151aa4(unsigned int, unsigned int);
extern void FUN_a014a768(int, unsigned int);

void FUN_a00da184(void)
{
  FUN_a00d99f8(2, 1);
  FUN_a014a8d4(4, 1, 1000);
  if (FUN_a01445fc(FUN_a014448c(0)) && (DAT_a802d290.wac & 0x100000)) {
    DAT_a802cff4.h0a |= 0x40;
    FUN_a00869b0(0x14, 5000);
  }
  FUN_a0089f6c();
  FUN_a0148268(0, 1);
  FUN_a0148268(1, 1);
  FUN_a0151aa4(0xf, 1);
  FUN_a014a768(0xc, DAT_a802d290.wa8 >> 7 & 1);
  FUN_a014a768(0xd, DAT_a802d290.wa8 >> 7 & 1);
}
