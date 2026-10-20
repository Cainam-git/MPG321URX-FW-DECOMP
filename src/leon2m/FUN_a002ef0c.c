/* leon2m FUN_a002ef0c @ 0xa002ef0c..0xa002efd4 (200 bytes, 50 words)  BYTE-EXACT
 * Flags: -mcpu=v8 -O3 -g.
 * Judge: jf 100.00 match=True; rawcmp.py 0 mismatches / 50 words (a002ef0c a002efd4).
 * What it does (code facts): st = func_0x00092254(0, 0x54) (call to the absolute ROM address
 * 0x92254); only when (st & 3) == 0 AND 0xcf011aa0 & 0xf == 0 AND bit 7 of 0xcf011aa4,
 * 0xcf011aa8 and 0xcf011aac are all clear, it calls func_0x000ee758() (ROM 0xee758). Then it
 * clears the registers 0xcf006b30 and 0xcf006b34, calls the hook pointer _DAT_a802c9e0 if it
 * is non-null, calls FUN_a002e3c4(0, 1) and sets bit 0 of _DAT_a802c9e4.
 * Callers: no direct 'call 0xa002ef0c' in asm/leon2m (reached via a pointer/table).
 * Aids: none. Code fact that makes it exact: the hook takes NO argument
 * ('void (*)(void)'). With the draft's '_DAT_a802c9e0(0)' gcc sets %o0 = 0 for the hook in
 * the 'be' delay slot and reorg does not advance the branch past the clr %o0 at the join
 * (be target +84 vs fw +88, jf 98.00); with no hook argument the delay-slot clr %o0 is
 * FUN_a002e3c4's first argument stolen from the target, exactly as in the fw. Draft's
 * 'return 0' in a void function dropped. FUN_a002e3c4 = (bit, on): (int, unsigned char).
 */
extern int func_0x00092254(int, int);
extern int func_0x000ee758(void);
extern void FUN_a002e3c4(unsigned int, unsigned char);
extern unsigned int _DAT_a802c9e4;
extern void (*_DAT_a802c9e0)(void);

#define _DAT_cf006b30 (*(volatile unsigned int *)0xcf006b30)
#define _DAT_cf006b34 (*(volatile unsigned int *)0xcf006b34)
#define _DAT_cf011aa0 (*(volatile unsigned int *)0xcf011aa0)
#define _DAT_cf011aa4 (*(volatile unsigned int *)0xcf011aa4)
#define _DAT_cf011aa8 (*(volatile unsigned int *)0xcf011aa8)
#define _DAT_cf011aac (*(volatile unsigned int *)0xcf011aac)

void FUN_a002ef0c(void)
{
  unsigned int status = func_0x00092254(0, 0x54);

  if ((status & 3) == 0) {
    if ((_DAT_cf011aa0 & 0xf) == 0) {
      if ((_DAT_cf011aa4 & 0x80) == 0) {
        if ((_DAT_cf011aa8 & 0x80) == 0) {
          if ((_DAT_cf011aac & 0x80) == 0)
            func_0x000ee758();
        }
      }
    }
  }
  _DAT_cf006b30 = 0;
  _DAT_cf006b34 = 0;
  if (_DAT_a802c9e0 != 0)
    _DAT_a802c9e0();
  FUN_a002e3c4(0, 1);
  _DAT_a802c9e4 |= 1;
}
