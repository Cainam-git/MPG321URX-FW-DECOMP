/* leon2m FUN_a0129b44 @ 0xa0129b44  MATCH (-mcpu=v8 -O2 -g)
 * Fixed set-up sequence of calls into the FUN_a01016cc..FUN_a0101b20 group: FUN_a0101704(0x1A3128),
 * FUN_a010178c(0x3C0, 3), FUN_a0101868(8, 0), FUN_a0101884(4, 1), FUN_a01018b0(0), FUN_a010192c(0xF); copies
 * DAT_a802a449 to DAT_a802a448 and calls FUN_a0101a28(DAT_a802ca03, DAT_a802a449); then FUN_a0101a4c(5, 5),
 * FUN_a0101a70(2), FUN_a0101abc(0, 1), FUN_a0101af0(0), FUN_a0101b08(0), FUN_a0101b20(1), FUN_a01016cc(),
 * func_0x4008e2a4() and finally FUN_a01016e8() as a tail call.
 */
extern unsigned char DAT_a802a448;
extern unsigned char DAT_a802a449;
extern unsigned char DAT_a802ca03;
extern int FUN_a01016cc();
extern int FUN_a01016e8();
extern int FUN_a0101704();
extern void FUN_a010178c();
extern void FUN_a0101868();
extern int FUN_a0101884();
extern int FUN_a01018b0();
extern int FUN_a010192c();
extern int FUN_a0101a28();
extern int FUN_a0101a4c();
extern int FUN_a0101a70();
extern int FUN_a0101abc();
extern int FUN_a0101af0();
extern int FUN_a0101b08();
extern int FUN_a0101b20();
extern int func_0x4008e2a4();

void FUN_a0129b44(void)
{
  FUN_a0101704(0x1a3128);
  FUN_a010178c(0x3c0,3);
  FUN_a0101868(8,0);
  FUN_a0101884(4,1);
  FUN_a01018b0(0);
  FUN_a010192c(0xf);
  DAT_a802a448 = DAT_a802a449;
  FUN_a0101a28(DAT_a802ca03, DAT_a802a449);
  FUN_a0101a4c(5,5);
  FUN_a0101a70(2);
  FUN_a0101abc(0,1);
  FUN_a0101af0(0);
  FUN_a0101b08(0);
  FUN_a0101b20(1);
  FUN_a01016cc();
  func_0x4008e2a4();
  FUN_a01016e8();
  return;
}
