/* leon2m FUN_a014512c @ 0xa014512c (-mcpu=v8 -O2 -g)
 * Prints the low byte of param_1 (FUN_a00df170, format "SYSAPI_PanelOnOffControl = %02x" at 0x1A6DF8), then calls FUN_a01412b8(1) when
 * that byte is 1, else FUN_a01412b8(0), followed by FUN_a01413d0(). When the low byte of param_2 is 1, it loops
 * until FUN_a0141a98 (param_1 == 1) or FUN_a0141ad0 (otherwise) returns a nonzero low byte, calling FUN_a01413d0,
 * FUN_a01295e4 and func_0x4008ced8 on every pass.
 */
extern int FUN_a00df170();
extern int FUN_a01412b8();
extern int FUN_a01413d0();
extern int FUN_a01295e4();
extern int func_0x4008ced8();
extern int FUN_a0141a98();
extern int FUN_a0141ad0();

void FUN_a014512c(unsigned int param_1, unsigned int param_2)

{
  unsigned int uVar1;

  FUN_a00df170(0x1a6df8, param_1 & 0xff);
  if ((param_1 & 0xff) == 1) {
    FUN_a01412b8(1);
    FUN_a01413d0();
    if ((param_2 & 0xff) == 1) {
      do {
        uVar1 = FUN_a0141a98();
        if ((uVar1 & 0xff) != 0) {
          break;
        }
        FUN_a01413d0();
        FUN_a01295e4();
        func_0x4008ced8();
      } while( 1 );
    }
  }
  else {
    FUN_a01412b8(0);
    FUN_a01413d0();
    if ((param_2 & 0xff) == 1) {
      do {
        uVar1 = FUN_a0141ad0();
        if ((uVar1 & 0xff) != 0) {
          break;
        }
        FUN_a01413d0();
        FUN_a01295e4();
        func_0x4008ced8();
      } while( 1 );
    }
  }
  return;
}
