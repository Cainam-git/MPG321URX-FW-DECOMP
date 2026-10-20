/* FUN_a00d2d8c (leon2s, 0xa00d2d8c-0xa00d2e00, 116 bytes, 29 words; includes the merged unreachable
 * ret/restore tail FUN_a00d2df8). Flags: -mcpu=v8 -Os -g.
 * Code facts: if the byte DAT_a8078c26 == 0: FUN_a00d2210(0, 1), FUN_a00d2288(0, 1),
 * FUN_a00d23bc(0, 1), FUN_a00d2300(0, 1), FUN_a00d2434(0, 1); DAT_a8078c26 = 1; tail call
 * FUN_a0f834c4(DAT_9f1c6420) (fw: 'restore %i0, %lo, %o0'). Sibling of FUN_a00d2ca8/FUN_a00d2c38
 * (flag a8078c25) on the flag a8078c26.
 * Fixes vs draft: the tail-call argument is the SYMBOL DAT_9f1c6420 (a constant gives a separate 'or'
 * and a bare restore); (u8, u8) callee prototypes; void without return values. Aids: none.
 */
extern unsigned char DAT_a8078c26;
extern int FUN_a00d2210(unsigned char, unsigned char);
extern int FUN_a00d2288(unsigned char, unsigned char);
extern int FUN_a00d23bc(unsigned char, unsigned char);
extern int FUN_a00d2300(unsigned char, unsigned char);
extern int FUN_a00d2434(unsigned char, unsigned char);
extern int FUN_a0f834c4();
extern const char DAT_9f1c6420[];

void FUN_a00d2d8c(void)
{
  if (DAT_a8078c26 == 0) {
    FUN_a00d2210(0, 1);
    FUN_a00d2288(0, 1);
    FUN_a00d23bc(0, 1);
    FUN_a00d2300(0, 1);
    FUN_a00d2434(0, 1);
    DAT_a8078c26 = 1;
    FUN_a0f834c4(DAT_9f1c6420);
  }
}
