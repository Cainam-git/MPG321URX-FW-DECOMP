/* leon2s FUN_a00adf64 @ 0xa00adf64  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Finished by hand from mechanical Ghidra C. Returns bit (param_1 * 4 + param_2) of the
 * status byte at 0xa807de70: four status bits per port. Ghidra had added a shift mask.
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
extern unsigned char DAT_a807de70;

uint FUN_a00adf64(unsigned char param_1, int param_2)

{
  return (int)(uint)DAT_a807de70 >> (param_2 + param_1 * 4) & 1;
}