/* leon2m FUN_a00d24e0 @ 0xa00d24e0-0xa00d253c (23 words), flags -mcpu=v8 -O3 -g.
 * Code facts: if param_1[7] == 0: clear bit 6 (0x40) of the word at 0xa802d290+0xa8 and FUN_a0125ac8(); else set
 * it and FUN_a0125aac(); then FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc) (return unused); returns 0xe0. The 2nd
 * argument of FUN_a014aed0 is the record address.
 * Source form: the record base DAT_a802d290 as a struct.
 * Compiler aids: none.
 */
struct R290 { unsigned char pad[0xa8]; unsigned int wa8; };
extern struct R290 DAT_a802d290;
extern void FUN_a0125aac(void);
extern void FUN_a0125ac8(void);
extern int FUN_a014aed0(int, void *, int, int);

int FUN_a00d24e0(unsigned char *param_1)
{
  if (param_1[7] == 0) {
    DAT_a802d290.wa8 &= ~0x40;
    FUN_a0125ac8();
  } else {
    DAT_a802d290.wa8 |= 0x40;
    FUN_a0125aac();
  }
  FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
  return 0xe0;
}
