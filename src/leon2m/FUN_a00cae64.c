/* leon2m FUN_a00cae64 @ 0xa00cae64  MATCH (-mcpu=v8 -O3 -g, twin)
 * Twin of FUN_a00c9e9c: same code, constants swapped; byte-exact.
 * See FUN_a00c9e9c for the explanation; this copy's constants differ, so its comments were removed.
 */
struct R290 { unsigned char pad[0x1dc]; unsigned int w174; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern void FUN_a00dab20(void);
extern void FUN_a00b88cc(void);
extern void FUN_a00baa6c(unsigned char);
extern void FUN_a00ba950(unsigned char);
extern void FUN_a00bab80(unsigned char, int);

int FUN_a00cae64(unsigned char param_1)
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
  DAT_a802d290.w174 = (DAT_a802d290.w174 & ~0x8000) | ((d & 1) << 15);
  FUN_a00dab20();
  FUN_a00b88cc();
  FUN_a00baa6c(param_1);
  FUN_a00ba950(param_1);
  FUN_a00bab80(param_1, 6);
  return 0;
}
