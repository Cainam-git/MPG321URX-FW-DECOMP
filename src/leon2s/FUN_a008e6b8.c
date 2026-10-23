/* leon2s FUN_a008e6b8 @ 0xa008e6b8 (-mcpu=v8 -Os -g)
 * Prints the string at 0xA0068D40 ("ESC[0;34m[HDMI_TX]:  PHY Power Down Setting  \n") through FUN_a00734c4, then
 * calls FUN_a008d8e0, FUN_a008e3c0, FUN_a008e098, FUN_a008e200, FUN_a008db90, FUN_a008db4c, FUN_a008df7c and
 * FUN_a008df40 with (p1, 0), and FUN_a008dbd4(p1, 0, 0) between FUN_a008db90 and FUN_a008db4c.
 * Source form: Ghidra's type and symbol names are kept.
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
extern unsigned int DAT_a0068d40;
extern int FUN_a00734c4();
extern void FUN_a008d8e0();
extern void FUN_a008db4c();
extern void FUN_a008db90();
extern void FUN_a008dbd4();
extern int FUN_a008df40();
extern int FUN_a008df7c();
extern void FUN_a008e098();
extern void FUN_a008e200();
extern void FUN_a008e3c0();

void FUN_a008e6b8(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_a00734c4(&DAT_a0068d40);
  FUN_a008d8e0(param_1,0);
  FUN_a008e3c0(param_1,0);
  FUN_a008e098(param_1,0);
  FUN_a008e200(param_1,0);
  FUN_a008db90(param_1,0);
  FUN_a008dbd4(param_1,0,0);
  FUN_a008db4c(param_1,0);
  FUN_a008df7c(param_1,0);
  FUN_a008df40(param_1,0,param_3,param_4,param_5,param_6);
  return;
}