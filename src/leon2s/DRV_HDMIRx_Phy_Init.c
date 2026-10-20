/* leon2s DRV_HDMIRx_Phy_Init @ 0xa0074bf8  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
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
extern unsigned int _DAT_a8078634;
extern int DRV_HDMI_InitialSettings();
extern int FUN_a0073044();
extern void FUN_a0073500(void);
extern int FUN_a0073540();
extern int FUN_a0073578();

void DRV_HDMIRx_Phy_Init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        ,undefined4 param_5,undefined4 param_6)

{
  if ((_DAT_a8078634 & 1) != 0) {
    FUN_a0073044("[INIT]: DRV_HDMIRx_Phy_Init %d\015\012",999);
  }
  DRV_HDMI_InitialSettings();
  FUN_a0073500();
  FUN_a0073578(0);
  FUN_a0073540(0,param_2,param_3,param_4,param_5,param_6);
  return;
}