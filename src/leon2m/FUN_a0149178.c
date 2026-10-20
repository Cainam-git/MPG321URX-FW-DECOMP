/* leon2m FUN_a0149178 @ 0xa0149178-0xa0149210 (38 words), flags -mcpu=v8 -O3 -g.
 * Code facts: a stack record {u8 ch @-16; u16 v @-14} defaults to {0xff, 0}; when the high nibble of the u8
 * param is 1 or 3 (both compares as subx flags joined by orcc) and the param is 0x30, it becomes {0, 0x8000}.
 * ch == 0xff (stb then ldub reload) -> if FUN_a00dd614(0x40) is non-zero, print FUN_a00df170(s_001a6fa8);
 * else FUN_a012ced8(ch). Returns nothing (Ghidra's CONCAT44 return is not real).
 * Source form: defaults first, then nested ifs (an if/else with the && test gives other registers for -1 and
 * the sethi and swaps the 2nd xor/subx pair). Aids: none.
 */
struct Sel { unsigned char ch; unsigned short v; };
extern unsigned char FUN_a00dd614(unsigned int level);
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a012ced8(unsigned char);
extern char s_001a6fa8[];

void FUN_a0149178(unsigned char x)
{
  struct Sel s;

  s.ch = 0xff;
  s.v = 0;
  if ((x & 0xf0) == 0x10 || (x & 0xf0) == 0x30) {
    if (x == 0x30) {
      s.ch = 0;
      s.v = 0x8000;
    }
  }
  if (s.ch == 0xff) {
    if (FUN_a00dd614(0x40))
      FUN_a00df170(s_001a6fa8);
  } else {
    FUN_a012ced8(s.ch);
  }
}
