/* leon2s FUN_a008983c @ 0xa008983c  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Finished by hand from mechanical Ghidra C. Writes the 16-bit value param_2 to register
 * 0x57 of port param_1 as two byte writes, low byte first, through FUN_a00a78fc. It then
 * pulses bit 4 of register 0x70 (set, wait 5 via FUN_a00b1794, clear) to latch the value.
 * param_2 is an int read as unsigned short.
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
extern void FUN_a00a78fc(uint param_1, unsigned short param_2,uint param_3);
extern void FUN_a00a7940();
extern int FUN_a00b1794();

void FUN_a008983c(undefined1 param_1, int param_2)

{
  FUN_a00a78fc(param_1,0x57,param_2 & 0xff);
  FUN_a00a78fc(param_1,0x57,((unsigned short)param_2) >> 8);
  FUN_a00a7940(param_1,0x70,0x10,1);
  FUN_a00b1794(5);
  FUN_a00a7940(param_1,0x70,0x10,0);
  return;
}