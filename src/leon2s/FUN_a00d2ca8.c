/* FUN_a00d2ca8 (leon2s, 0xa00d2ca8-0xa00d2d1c, 116 bytes, 29 words; includes the merged unreachable
 * ret/restore tail FUN_a00d2d14).
 * Flags: -mcpu=v8 -Os -g.
 * If the byte DAT_a8078c25 == 0: FUN_a00d2210(0, 1), FUN_a00d2288(0, 1), FUN_a00d23bc(0, 1),
 * FUN_a00d2300(0, 1), FUN_a00d2434(0, 0); DAT_a8078c25 = 1; tail call FUN_a0f834c4(DAT_9f1c63f0)
 * (firmware: 'restore %i0, %lo, %o0' builds the address in the delay slot). Twin of FUN_a00d2c38.
 * FUN_a00d2210 runs first and takes 2 args (the firmware sets %o1 before it); the callees are (u8, u8) as in
 * FUN_a00d27fc; the tail-call argument is the symbol DAT_9f1c63f0 (a plain constant gives a separate 'or'
 * and a bare restore).
 */
extern unsigned char DAT_a8078c25;
extern int FUN_a00d2210(unsigned char, unsigned char);
extern int FUN_a00d2288(unsigned char, unsigned char);
extern int FUN_a00d23bc(unsigned char, unsigned char);
extern int FUN_a00d2300(unsigned char, unsigned char);
extern int FUN_a00d2434(unsigned char, unsigned char);
extern int FUN_a0f834c4();
extern const char DAT_9f1c63f0[];

void FUN_a00d2ca8(void)
{
  if (DAT_a8078c25 == 0) {
    FUN_a00d2210(0, 1);
    FUN_a00d2288(0, 1);
    FUN_a00d23bc(0, 1);
    FUN_a00d2300(0, 1);
    FUN_a00d2434(0, 0);
    DAT_a8078c25 = 1;
    FUN_a0f834c4(DAT_9f1c63f0);
  }
}
