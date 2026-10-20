/* leon2s FUN_a00acb94 @ 0xa00acb94 (-mcpu=v8 -Os -g)
 * Reads a 3-bit code: when bit 2 of FUN_a00a6f78(port, 5) and bit 6 of FUN_a00a6bb8(port, 0x8E) are both set, it
 * calls FUN_a00a6c98(port, 0xBE, 0x80, 1) and takes FUN_a00a6bb8(port, 0xBD) & 7; otherwise bits 5..7 of
 * FUN_a00a6bb8(port, 0x8D). Codes 0, 1, 2, 3, 4 map to 6, 8, 10, 12, 16 (others 8), returned & 0x1E. The dense
 * switch produces the target's jump table, and the `&&` gives the two conditional branches to the shared else
 * path.
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

extern uint FUN_a00a6bb8(uint, unsigned short);
extern uint FUN_a00a6f78(uint, unsigned short);
extern void FUN_a00a6c98(uint, unsigned short, unsigned short, unsigned short);

uint FUN_a00acb94(uint param_1)
{
  uint val;
  unsigned char result;
  
  param_1 &= 0xff;
  if ((FUN_a00a6f78(param_1, 5) & 4) != 0 &&
      (FUN_a00a6bb8(param_1, 0x8e) & 0x40) != 0) {
    FUN_a00a6c98(param_1, 0xbe, 0x80, 1);
    val = FUN_a00a6bb8(param_1, 0xbd) & 7;
  }
  else {
    val = (FUN_a00a6bb8(param_1, 0x8d) & 0xff) >> 5;
  }
  
  result = 8;
  switch (val & 0xff) {
    case 0: result = 6; break;
    case 1: result = 8; break;
    case 2: result = 10; break;
    case 3: result = 12; break;
    case 4: result = 16; break;
  }
  return result & 0x1e;
}
