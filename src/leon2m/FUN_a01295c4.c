/* leon2m FUN_a01295c4 @ 0xa01295c4  MATCH (-mcpu=v8 -O2, gcc 3.4.4)
 * OLED FRC row index getter: returns the byte 0xA802D893 (low byte of the OLED FRC handler state halfword 0xA802D892),
 * the panel row index that the handler FUN_a01295e4 sends to the panel controller register 0xB2 ("OLED set Frame rate
 * control %d", FUN_a0126704). 0xFF = no row selected (reset by FUN_a0129598). Setter: FUN_a01295b8.
 * Callers: only the row picker FUN_a00dac38 (7 sites), which compares it with the row it chose.
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

undefined1 FUN_a01295c4(void)

{
  return DAT_a802d893;
}