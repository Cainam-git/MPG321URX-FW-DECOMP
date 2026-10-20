/* leon2m FUN_a00922f0 @ 0xa00922f0 (-mcpu=v8 -O2 -g)
 * Calls FUN_a00a8ee8 and FUN_a00aa01c with (_DAT_a802afec - 30) & 0xFF, FUN_a00a900c with the low byte of
 * FUN_a01445fc(DAT_a802d2ae), sets _DAT_a802afec = 6, calls FUN_a00b4144(4, 1) and FUN_a00a9468(1, 2), and returns
 * the result of the tail call FUN_a00b34d4(0, 1).
 */
extern unsigned char DAT_a802d2ae;      /* 0xa802d2ae */
extern unsigned int _DAT_a802afec;      /* 0xa802afec */
extern int FUN_a00a8ee8(int);           /* 0xa00a8ee8 */
extern void FUN_a00a900c(int, int);     /* 0xa00a900c */
extern int FUN_a00a9468(int, int);      /* 0xa00a9468 */
extern void FUN_a00aa01c(int, int);     /* 0xa00aa01c */
extern int FUN_a00b34d4(int, int);      /* 0xa00b34d4 */
extern void FUN_a00b4144(int, int);     /* 0xa00b4144 */
extern int FUN_a01445fc(unsigned char); /* 0xa01445fc */

int FUN_a00922f0(void)
{
  FUN_a00a8ee8((_DAT_a802afec - 30) & 0xff);
  FUN_a00aa01c((_DAT_a802afec - 30) & 0xff, 0);
  FUN_a00a900c(FUN_a01445fc(DAT_a802d2ae) & 0xff, 0);
  _DAT_a802afec = 6;
  FUN_a00b4144(4, 1);
  FUN_a00a9468(1, 2);
  return FUN_a00b34d4(0, 1);
}
