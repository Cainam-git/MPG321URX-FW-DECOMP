/* leon2m FUN_a00c9df4 @ 0xa00c9df4-0xa00c9e9c (42 words), flags -mcpu=v8 -O3 -g. No direct callers.
 * UART command handler: takes byte 9 of the port's receive record (0xa802d049 for port 2, 0xa802d0a1 for port 3,
 * 0xa802d0d9 otherwise) as an ASCII digit d. A value above 1 returns 0xff. Otherwise d is stored in
 * bit 7 of the word 0xa802d290+0x1ec, then FUN_a00db12c(0), FUN_a00b88cc(), FUN_a00baa6c(port), FUN_a00ba950(port) and
 * FUN_a00bab80(port, 6) run (called, not inlined) and the function returns 0.
 * Same form as FUN_a00c9e9c.
 */
struct R290 { unsigned char pad[0x1ec]; unsigned int w1ec; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern void FUN_a00db12c(int);
extern void FUN_a00b88cc(void);
extern void FUN_a00baa6c(unsigned char);
extern void FUN_a00ba950(unsigned char);
extern void FUN_a00bab80(unsigned char, int);

int FUN_a00c9df4(unsigned char param_1)
{
  unsigned char value;
  int diff;
  unsigned char d;

  if (param_1 == 2)
    value = DAT_a802d049;
  else if (param_1 == 3)
    value = DAT_a802d0a1;
  else
    value = DAT_a802d0d9;
  diff = value - 0x30;
  d = diff;
  if (d > 1)
    return 0xff;
  DAT_a802d290.w1ec = (DAT_a802d290.w1ec & ~0x80) | ((d & 1) << 7);
  FUN_a00db12c(0);
  FUN_a00b88cc();
  FUN_a00baa6c(param_1);
  FUN_a00ba950(param_1);
  FUN_a00bab80(param_1, 6);
  return 0;
}
