/* leon2m FUN_a00fd9a0 @ 0xa00fd9a0-0xa00fde94 (317 words), -mcpu=v8 -O3 -g: jf 100.00 match=True, rawcmp 0/317.
 * GlobalModeHandler main source
 * selection, part 2 (FUN_a0131518 calls it after FUN_a00fd594 with the same blk / class code).
 * What it does: copies the ROM table DAT_0019a4fb (12 rows x 16 bytes) to the stack (FUN_a013c910 = fw memcpy);
 *   row index by class: 0x12 -> 1, 0x13 -> 2, 0x21 -> 3 (plus a pulse: block reg 1 bit 6 set, 2 ms, cleared),
 *   0x31/0x41 -> 4, 0x51/0x61 -> 5, 0x71/0x81 -> 6, 0xc1 -> 7, 0x91/0xa1 -> 8, 0xb1 -> 9, 0xe1/0xe2 -> 10, 0xe8 -> 11,
 *   others (0x11 included) -> 0. Then from the row: block reg 0 (FUN_a00f1fe0) = b0; for classes 0x11..0x13 and
 *   0x21: 0xcf020114 = b1, 0xcf020088 = 0xa0 when (0xcf020114 & 7) == 5 else 0, 0xcf0200cc = b2 then |= 1,
 *   0xcf0200d0 = b3, and 0xcf020134..0x144 = d0/2/80/80/40 (0x13, 0x21) or 50/22/0 (others); reg 0 = b4;
 *   blk 6/7: reg 0 bit 7 = (row <= 3); reg 1 = b5; reg 3 = (reg 3 & 1) | b6; reg 5 = b7; blk 6/7: reg 5 bit 0 set;
 *   regs 6, 0x16, 0x54 = b8, b9, b10; FUN_a00f2298(blk, 0x32, b11); reg 0x56 = b13 (b12 unused);
 *   FUN_a0120848(blk, 1, 8 for 0x71/0x81 else 4); FUN_a0121b98 / FUN_a0121b50 (blk, 0/0 for 0x31..0x61, 3/1 for
 *   0x71/0x81 and 0xb1, 2/1 for 0x91/0xe1/0xe2, else 0/0); FUN_a00f913c(blk, 0x15, cls == 0xe8).
 * The register values depend only on the class code of the source (row of the table),
 *   not on the refresh rate.
 * Code facts that fix the source:
 *   - the class switch needs an explicit 'case 0x11: idx = 0;' (gcc balance_case_nodes with 16 nodes + the
 *     0xe1..0xe2 range gives the fw tree: root 0x71, then 0x21 / 0xb1).
 *   - the 0x91 arm and the 0xe1/0xe2 arm of the FUN_a0121b98 chain are TWO else-if arms with identical bodies
 *     (crossjump merges them; one '||' arm keeps the body inline).
 *   - a table row is a struct of 16 'unsigned char bN : 8' bit-fields. Same ldub loads, but a bit-field
 *     access carries the row struct's alias set instead of alias set 0 (char), so sched1 no longer makes the row
 *     loads depend on the volatile register stores. Checked with -fsched-verbose=5: with plain bytes the 0xcc
 *     store (insn 298) and the 'cls == 0x13' xor (insn 319) tie at priority 7 and the reg-weight tie-break puts
 *     the store first; with the bit-field rows the store chain is one shorter and the xor goes first like the fw
 *     (this fixed the last 17 raw words in 0xa00fda90..fdb00). No aids.
 */
#define R(a) (*(volatile unsigned int *)(a))
struct Row {
  unsigned char b0 : 8;
  unsigned char b1 : 8;
  unsigned char b2 : 8;
  unsigned char b3 : 8;
  unsigned char b4 : 8;
  unsigned char b5 : 8;
  unsigned char b6 : 8;
  unsigned char b7 : 8;
  unsigned char b8 : 8;
  unsigned char b9 : 8;
  unsigned char b10 : 8;
  unsigned char b11 : 8;
  unsigned char b12 : 8;
  unsigned char b13 : 8;
  unsigned char b14 : 8;
  unsigned char b15 : 8;
};
extern const unsigned char DAT_0019a4fb[];
extern void *FUN_a013c910(void *dst, const void *src, int n);
extern void FUN_a00f1fe0(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a0120848(unsigned char blk, unsigned char a, unsigned char b);
extern void FUN_a0121b98(unsigned char blk, unsigned char on);
extern void FUN_a0121b50(unsigned char blk, unsigned char on);
extern void FUN_a00f913c(unsigned char blk, unsigned char reg, unsigned char on);
extern void func_0x4008d1a0(int ms);

void FUN_a00fd9a0(unsigned char blk, unsigned char cls)
{
  struct Row tab[12];
  unsigned char idx;

  FUN_a013c910(tab, DAT_0019a4fb, 0xc0);
  idx = 0;
  switch (cls) {
  case 0x11: idx = 0; break;
  case 0x12: idx = 1; break;
  case 0x13: idx = 2; break;
  case 0x21:
    FUN_a00f1b5c(blk, 1, 0x40, 1);
    func_0x4008d1a0(2);
    FUN_a00f1b5c(blk, 1, 0x40, 0);
    idx = 3;
    break;
  case 0x31: case 0x41: idx = 4; break;
  case 0x51: case 0x61: idx = 5; break;
  case 0x71: case 0x81: idx = 6; break;
  case 0xc1: idx = 7; break;
  case 0x91: case 0xa1: idx = 8; break;
  case 0xb1: idx = 9; break;
  case 0xe1: case 0xe2: idx = 10; break;
  case 0xe8: idx = 11; break;
  }
  FUN_a00f1fe0(blk, 0, tab[idx].b0);
  if ((unsigned char)(cls - 0x11) < 3 || cls == 0x21) {
    R(0xcf020114) = tab[idx].b1;
    if ((R(0xcf020114) & 7) == 5)
      R(0xcf020088) = 0xa0;
    else
      R(0xcf020088) = 0;
    R(0xcf0200cc) = tab[idx].b2;
    R(0xcf0200cc) |= 1;
    R(0xcf0200d0) = tab[idx].b3;
    if (cls == 0x13 || cls == 0x21) {
      R(0xcf020134) = 0xd0;
      R(0xcf020138) = 2;
      R(0xcf02013c) = 0x80;
      R(0xcf020140) = 0x80;
      R(0xcf020144) = 0x40;
    } else {
      R(0xcf020134) = 0x50;
      R(0xcf020138) = 0x22;
      R(0xcf02013c) = 0;
    }
  }
  FUN_a00f1ad4(blk, 0, tab[idx].b4);
  if ((unsigned char)(blk - 6) <= 1) {
    if (idx <= 3)
      FUN_a00f1b5c(blk, 0, 0x80, 1);
    else
      FUN_a00f1b5c(blk, 0, 0x80, 0);
  }
  FUN_a00f1ad4(blk, 1, tab[idx].b5);
  FUN_a00f1ad4(blk, 3, (FUN_a00f1a90(blk, 3) & 1) | tab[idx].b6);
  FUN_a00f1ad4(blk, 5, tab[idx].b7);
  if ((unsigned char)(blk - 6) <= 1)
    FUN_a00f1b5c(blk, 5, 1, 1);
  FUN_a00f1ad4(blk, 6, tab[idx].b8);
  FUN_a00f1ad4(blk, 0x16, tab[idx].b9);
  FUN_a00f1ad4(blk, 0x54, tab[idx].b10);
  FUN_a00f2298(blk, 0x32, tab[idx].b11);
  FUN_a00f1ad4(blk, 0x56, tab[idx].b13);
  if (cls == 0x71 || cls == 0x81)
    FUN_a0120848(blk, 1, 8);
  else
    FUN_a0120848(blk, 1, 4);
  if (cls == 0x31 || cls == 0x41 || cls == 0x51 || cls == 0x61) {
    FUN_a0121b98(blk, 0);
    FUN_a0121b50(blk, 0);
  } else if (cls == 0x71 || cls == 0x81) {
    FUN_a0121b98(blk, 3);
    FUN_a0121b50(blk, 1);
  } else if (cls == 0x91) {
    FUN_a0121b98(blk, 2);
    FUN_a0121b50(blk, 1);
  } else if ((unsigned char)(cls + 0x1f) <= 1) {
    FUN_a0121b98(blk, 2);
    FUN_a0121b50(blk, 1);
  } else if (cls == 0xb1) {
    FUN_a0121b98(blk, 3);
    FUN_a0121b50(blk, 1);
  } else {
    FUN_a0121b98(blk, 0);
    FUN_a0121b50(blk, 0);
  }
  FUN_a00f913c(blk, 0x15, cls == 0xe8);
}
