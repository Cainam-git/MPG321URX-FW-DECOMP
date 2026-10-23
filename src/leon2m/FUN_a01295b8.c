/* leon2m FUN_a01295b8 @ 0xa01295b8 (-mcpu=v8 -Os -g, gcc 3.4.4; autoc)
 * OLED FRC row index setter: stores the byte argument in 0xA802D893 (low byte of the OLED FRC handler state 0xA802D892),
 * the row index later sent to panel controller register 0xB2 by FUN_a01295e4 -> FUN_a0126704. Getter: FUN_a01295c4.
 * Callers: only FUN_a00dac38 (3 sites: once the chosen row, twice the constant 1, one of them on the forced path).
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
extern unsigned char DAT_a802d893;

void FUN_a01295b8(undefined1 param_1)

{
  DAT_a802d893 = param_1;
  return;
}