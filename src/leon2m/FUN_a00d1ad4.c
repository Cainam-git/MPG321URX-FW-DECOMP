/* leon2m FUN_a00d1ad4 @ 0xa00d1ad4-0xa00d1b48 (29 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0 mismatches.
 * Code facts: b = byte at param_1 + 7. b == 1: FUN_a00cea18() (result unused), u16 at
 * DAT_a802d290 + 0x1f6 (= 0xa802d486) = 0x55aa, FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc).
 * b == 0: FUN_a00cea44(), same u16 = 0xbb99. Then FUN_a0145360(1); returns 0xe0.
 * Fixes vs the autoc draft (89.66): BEHAVIOUR, arm 1 stores the constant 0x55aa (fw sethi 0x5400 |
 * 0x1aa); the draft stored FUN_a00cea18()'s return. In arm 1 the u16 is addressed through a local
 * base pointer p = DAT_a802d290 (fw: sth [base + 0x1f6] shares the call argument's base register;
 * a plain DAT_a802d290 + 0x1f6 gives add -502, 56.67); arm 0 keeps the sym + 0x1f6 form. FUN_a014aed0
 * returns int (its value is 1 bit; the void declaration put 'mov 0x30, %o0' first, 93.10). Aids: none.
 */
extern unsigned char DAT_a802d290[];
extern void FUN_a00cea18(void);
extern void FUN_a00cea44(void);
extern void FUN_a0145360(int);
extern int FUN_a014aed0(unsigned char, void *, unsigned short, unsigned short); /* its asm: and 0xff on %i0, sll 16 on %i2/%i3, returns l0 & 1 */

int FUN_a00d1ad4(unsigned char *param_1)
{
  if (param_1[7] == 1) {
    FUN_a00cea18();
    unsigned char *p = DAT_a802d290;
    *(unsigned short *)(p + 0x1f6) = 0x55aa;
    FUN_a014aed0(0x30, p, 0, 0x1fc);
  } else if (param_1[7] == 0) {
    FUN_a00cea44();
    *(unsigned short *)(DAT_a802d290 + 0x1f6) = 0xbb99;
  }
  FUN_a0145360(1);
  return 0xe0;
}
