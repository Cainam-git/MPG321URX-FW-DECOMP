/* leon2s DRV_HDMI_PHY_Clr_EQ_Err @ 0xa0074e38 (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Clears the HDMI equaliser error state of one
 * port (0-3). Logs '[EQ]: Port<letter> DRV_HDMI_PHY_Clr_EQ_Err' when bit 1 of the debug mask
 * at 0xa8078634 is set. Sets single bits via FUN_a00a7424(value 1, bit, port, register): bit
 * 29 of PHY register 0x1e94, bits 5 and 13 of 0x1e98; then pulses bit 6 of the low byte of
 * 0x1ea0 (0x87, 0xc7, 0x87) via the masked write FUN_a00a7488.
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
extern unsigned int DAT_a0066a78;
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044();
extern void FUN_a00a7424();
extern void FUN_a00a7488();

void DRV_HDMI_PHY_Clr_EQ_Err(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xff;
  if ((_DAT_a8078634 & 2) != 0) {
    FUN_a0073044(&DAT_a0066a78,(char)(param_1 + 'A'),
                 "DRV_HDMI_PHY_Clr_EQ_Err");
  }
  FUN_a00a7424(1,0x1d,uVar1,0x1e94);
  FUN_a00a7424(1,5,uVar1,0x1e98);
  FUN_a00a7424(1,0xd,uVar1,0x1e98);
  FUN_a00a7488(uVar1,0x1ea0,0xffffff00,0x87);
  FUN_a00a7488(uVar1,0x1ea0,0xffffff00,199);
  FUN_a00a7488(uVar1,0x1ea0,0xffffff00,0x87);
  return;
}