/* leon2s FUN_a00af94c @ 0xa00af94c (-mcpu=v8 -Os -g)
 * Finished by hand from mechanical Ghidra C. Per-port step (param_1 = port): reads a byte
 * for the port via 0x9f1c6624, passes it to FUN_a00add48(port, value), and with the port
 * number that call returns runs FUN_a00a8370(p, 0, 0) and then FUN_a00a8370(p, 1, 0x6a).
 * Ghidra had dropped that the second call's result replaces the port.
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
extern int FUN_a00a8370();
extern int FUN_a00add48();
extern int func_0x9f1c6624();

void FUN_a00af94c(unsigned char param_1)

{
  uint uVar1;
  
  param_1 = param_1 & 0xff;
  uVar1 = func_0x9f1c6624(param_1);
  param_1 = FUN_a00add48(param_1,uVar1 & 0xff);
  FUN_a00a8370(param_1 & 0xff,0,0);
  FUN_a00a8370(param_1 & 0xff,1,0x6a);
  return;
}