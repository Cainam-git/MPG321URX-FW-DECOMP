/* leon2s FUN_a006d204 @ 0xa006d204  MATCH (-mcpu=v8 -Os -g)
 * HDMI power-off sequence: TMDS_PowerOff(port, 1) for ports 0..3, FUN_a00ab4f8(0..4), clears the registers
 * 0xCF012448 and 0xCF014760, then a fixed call order: FUN_a00afdb0(2), FUN_a00afdf4(0/1, 1), FUN_a00b0568(0/1),
 * FUN_a0095c9c(0/1), FUN_a00a9e74(), FUN_a00aa200(), FUN_a0083f04(0/1, 1, 1), FUN_a00ad478(1), FUN_a006d3d8(),
 * FUN_a0088fd4(0), and a tail call to FUN_a008a7a0().
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
#define _DAT_cf012448 (*(volatile unsigned int *)0xcf012448)
#define _DAT_cf014760 (*(volatile unsigned int *)0xcf014760)
extern void FUN_a006d3d8(void);
extern void FUN_a0083f04(uint param_1, uint param_2, uint param_3);
extern void FUN_a0088fd4(uint param_1);
extern void FUN_a008a7a0(void);
extern void FUN_a0095c9c(uint param_1);
extern void FUN_a00a9e74(void);
extern void FUN_a00aa200(void);
extern void FUN_a00ab4f8(uint param_1);
extern void FUN_a00ad478(uint param_1);
extern void FUN_a00afdb0(uint param_1);
extern void FUN_a00afdf4(uint param_1, uint param_2);
extern void FUN_a00b0568(uint param_1);
extern void TMDS_PowerOff(uint param_1, uint param_2);

void FUN_a006d204(void)
{
  TMDS_PowerOff(0,1);
  TMDS_PowerOff(1,1);
  TMDS_PowerOff(2,1);
  TMDS_PowerOff(3,1);
  FUN_a00ab4f8(0);
  FUN_a00ab4f8(1);
  FUN_a00ab4f8(2);
  FUN_a00ab4f8(3);
  FUN_a00ab4f8(4);
  _DAT_cf012448 = 0;
  _DAT_cf014760 = 0;
  FUN_a00afdb0(2);
  FUN_a00afdf4(0,1);
  FUN_a00afdf4(1,1);
  FUN_a00b0568(0);
  FUN_a00b0568(1);
  FUN_a0095c9c(0);
  FUN_a0095c9c(1);
  FUN_a00a9e74();
  FUN_a00aa200();
  FUN_a0083f04(0,1,1);
  FUN_a0083f04(1,1,1);
  FUN_a00ad478(1);
  FUN_a006d3d8();
  FUN_a0088fd4(0);
  FUN_a008a7a0();
}
