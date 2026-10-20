/* leon2s hdmi_PHY_Set_CTLE @ 0xa0075278 (-mcpu=v8 -Os -g)
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
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044();
extern int FUN_a0073520();
extern void FUN_a00a7488();

static const char fn_[] = "_hdmi_PHY_Set_CTLE";   /* function name kept as a separate .rodata object by the firmware */

void hdmi_PHY_Set_CTLE(unsigned char param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0xff;
  if ((_DAT_a8078634 & 2) != 0) {
    FUN_a0073044("[EQ]: Port%c  %s\012",(char)(param_1 + 'A'),
                 fn_);
  }
  uVar1 = FUN_a0073520(param_1);
  if ((uVar1 & 0xff) != 0) {
    FUN_a00a7488(uVar2,0x3604,0xffffff,0x21000000);
  }
  FUN_a00a7488(uVar2,0x1f44,0xffff00ff,0x1100);
  FUN_a00a7488(uVar2,0x1f44,0xff00ffff,0x110000);
  FUN_a00a7488(uVar2,0x1f44,0xffffff,0x11000000);
  FUN_a00a7488(uVar2,0x1f48,0xffffff00,0x11);
  FUN_a00a7488(uVar2,0x1020,0xffffff,0xa2000000);
  return;
}