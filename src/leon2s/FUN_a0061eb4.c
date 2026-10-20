/* leon2s FUN_a0061eb4 @ 0xa0061eb4 (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Register access helper for port param_1 keyed
 * by a 16-bit register number param_2. Register 5 goes straight to FUN_a00a6f78(port, 5).
 * Register 0x1b8 is an indirect read: sets the 3-bit field of reg 0x1b7 to 2 (SC_MaskSetByte),
 * raises bit 6 of 0x1b7, writes the low byte of param_2 to 0x1b8, reads the result from 0x1b9,
 * then drops bit 6 again; that byte is returned. Anything else returns 0. param_2 is compared
 * as unsigned short.
 * Still needs a real name and proper types.
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
extern int FUN_a00a6bb8();
extern void FUN_a00a6c00();
extern void FUN_a00a6c98();
extern int FUN_a00a6f78();
extern void SC_MaskSetByte();

int FUN_a0061eb4(unsigned char param_1,uint param_2)

{
  unsigned char uVar1;
  
  uVar1 = 0;
  if (((unsigned short)param_2) == 5) {
    uVar1 = 0;
    FUN_a00a6f78(param_1 & 0xff,5);
  }
  else {
    param_1 = param_1 & 0xff;
    if (((unsigned short)param_2) == 0x1b8) {
      SC_MaskSetByte(1,param_1,0x1b7,7,2);
      FUN_a00a6c98(param_1,0x1b7,0x40,1);
      FUN_a00a6c00(param_1,0x1b8,param_2 & 0xff);
      uVar1 = FUN_a00a6bb8(param_1,0x1b9);
      FUN_a00a6c98(param_1,0x1b7,0x40,0);
    }
    uVar1 = uVar1 & 0xff;
  }
  return CONCAT44(param_2,uVar1);
}