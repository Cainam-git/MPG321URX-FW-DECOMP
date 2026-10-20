/* leon2s DRV_HDMI21_PHY_INV_PICDR_Reset @ 0xa007aca0 (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
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
extern unsigned int DAT_a00678c8;
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044();
extern void FUN_a00a7488();
extern int FUN_a00b1794();

void DRV_HDMI21_PHY_INV_PICDR_Reset(undefined1 param_1)

{
  
  if ((_DAT_a8078634 & 0x800) != 0) {
    FUN_a0073044(&DAT_a00678c8,"DRV_HDMI21_PHY_INV_PICDR_Reset");
  }
  FUN_a00a7488(param_1,0x2028,0xff00ffff,0x20000);
  FUN_a00a7488(param_1,0x2428,0xff00ffff,0x20000);
  FUN_a00a7488(param_1,0x2828,0xff00ffff,0x20000);
  FUN_a00a7488(param_1,0x3028,0xff00ffff,0x20000);
  FUN_a00a7488(param_1,0x2008,0xff00ffff,0x20000);
  FUN_a00a7488(param_1,0x2408,0xff00ffff,0x20000);
  FUN_a00a7488(param_1,0x2808,0xff00ffff,0x20000);
  FUN_a00a7488(param_1,0x3008,0xff00ffff,0x20000);
  FUN_a00b1794(1);
  FUN_a00a7488(param_1,0x2008,0xff00ffff,0);
  FUN_a00a7488(param_1,0x2408,0xff00ffff,0);
  FUN_a00a7488(param_1,0x2808,0xff00ffff,0);
  FUN_a00a7488(param_1,0x3008,0xff00ffff,0);
  FUN_a00a7488(param_1,0x2028,0xff00ffff,0);
  FUN_a00a7488(param_1,0x2428,0xff00ffff,0);
  FUN_a00a7488(param_1,0x2828,0xff00ffff,0);
  FUN_a00a7488(param_1,0x3028,0xff00ffff,0);
  return;
}