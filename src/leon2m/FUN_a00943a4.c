/* leon2m FUN_a00943a4 @ 0xa00943a4 (-mcpu=v8 -O3 -g)
 * Byte 0xA8025C55 = byte 0xA802D290 + 0x13e; word 0xA802AFEC = 0x108; byte 0xA802D290 + 0x1a3 = 0;
 * FUN_a00b5080(); func_0x4008e2a4() twice; FUN_a00a6b98(0, 1, 0).
 */

extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned int _DAT_a802d290;
extern unsigned char DAT_a802d433;
extern int FUN_a00a6b98();
extern int FUN_a00b5080();
extern int func_0x4008e2a4();
void FUN_a00943a4(void)
{
  unsigned char *p = (unsigned char *) 0xa802d290;
  int new_var;
  DAT_a8025c55 = p[0x13e];
  new_var = 0;
  _DAT_a802afec = 0x108;
  p[0x1a3] = new_var;
 do { FUN_a00b5080(); func_0x4008e2a4(); } while (new_var);
  func_0x4008e2a4();
  FUN_a00a6b98(new_var, 1, new_var);
}
