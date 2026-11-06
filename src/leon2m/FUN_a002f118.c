/* leon2m FUN_a002f118 @ 0xa002f118-0xa002f388 (156 words), flags -mcpu=v8 -O3 -g.
 * Calls func_0x0007e98c, writes 0x60 to 0xcf03c660 and waits while it reads 0x60, then reads the size
 * total = (word 0xcf03c674 << 16) + (word 0xcf03c670 << 8) + word 0xcf03c66c and passes it with
 * "total size = %ld\n" to func_0x0007f170. Calls FUN_a0029968(n, 0xffff) for n = 1..14 and FUN_a0029820(4, 1),
 * writes 0x80 to 0xcf011f80 and 0x17 to register word 0xf191 + 2 * byte 0xa802d87e, waits while 0xcf03c668 reads
 * 0xaa and while the size still equals total. Then loops without end: FUN_a002d1a0(100), byte 0xa802c9f0 =
 * size * 100 / total (as a byte, limited to 100), read back through FUN_a002f10c (inlined), and the hook at
 * 0xa802c9f4 is called (when set) each time that byte differs from the previous value. Caller: FUN_a0123cf0.
 * Source form: the limit as 'DAT_a802c9f0 = 100; if (v <= 100) DAT_a802c9f0 = v;'; the second wait loop reads
 * 0xcf03c674 through a pointer declared in a block around that loop, and its body is 'last = 0;' (the fw clears
 * last before the loop test at 0xa002f2b4 and again after the loop exit at 0xa002f37c).
 */
#define R(a) (*(volatile unsigned int *)(a))
#define SIZE() ((R(0xcf03c674) << 16) + (R(0xcf03c670) << 8) + R(0xcf03c66c))

extern unsigned char DAT_a802c9f0;
extern void (*DAT_a802c9f4)(void);
extern unsigned char DAT_a802d87e;
extern const char s_001a30b8[];

extern void func_0x0007e98c(void);

static unsigned char FUN_a002f10c(void)
{
  return DAT_a802c9f0;
}
extern int func_0x0007f170();
extern void FUN_a0029968(int, unsigned short);
extern void FUN_a0029820(int, unsigned short);
extern void FUN_a002d1a0(int);

void FUN_a002f118(void)
{
  unsigned int total, p;
  unsigned char last, v;

  func_0x0007e98c();
  R(0xcf03c660) = 0x60;
  while (R(0xcf03c660) == 0x60)
    ;
  total = SIZE();
  func_0x0007f170(s_001a30b8, total);
  FUN_a0029968(1, 0xffff);
  FUN_a0029968(2, 0xffff);
  FUN_a0029968(3, 0xffff);
  FUN_a0029968(4, 0xffff);
  FUN_a0029968(5, 0xffff);
  FUN_a0029968(6, 0xffff);
  FUN_a0029968(7, 0xffff);
  FUN_a0029968(8, 0xffff);
  FUN_a0029968(9, 0xffff);
  FUN_a0029968(10, 0xffff);
  FUN_a0029968(11, 0xffff);
  FUN_a0029968(12, 0xffff);
  FUN_a0029968(13, 0xffff);
  FUN_a0029968(14, 0xffff);
  FUN_a0029820(4, 1);
  R(0xcf011f80) = 0x80;
  R(0xcf000000 | ((DAT_a802d87e * 2 + 0xf191) << 2)) = 0x17;
  while (R(0xcf03c668) == 0xaa)
    ;
  last = 0;
  {
    volatile unsigned int *q = (volatile unsigned int *)0xcf03c674;

    while ((*q << 16) + (R(0xcf03c670) << 8) + R(0xcf03c66c) == total)
      last = 0;
  }

  for (;;) {
    FUN_a002d1a0(100);
    p = SIZE() * 100 / total;
    v = p;
    DAT_a802c9f0 = 100;
    if (v <= 100)
      DAT_a802c9f0 = v;
    v = FUN_a002f10c();
    if (last != v) {
      last = v;
      if (DAT_a802c9f4)
        DAT_a802c9f4();
    }
  }
}
