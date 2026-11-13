/* SetBrightness_copy  (FUN_a0145eb8)
 *
 * Print the brightness value and write it to the panel.
 * Note: Identical copy of SetBrightness.
 * Name basis: proven - prints 'SetBrightness %d' (original name), then the 16-bit write to panel register 0x5E
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145eb8 @ 0xa0145eb8, flags -mcpu=v8 -O2 -g.
 * Source form: both arguments are masked/passed as in the firmware: the first as (value & 0xffff) for the print
 * and the call, the second passed on unchanged.
 * The text "SetBrightness %d\r\n" is at address 0x1a6dc0, named by its address so that the reference follows when
 * the text moves.
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
#define CONCAT11(a, b) ((unsigned short)(((unsigned)(a) << 8) | (unsigned char)(b)))
#define CONCAT12(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT13(a, b) (((unsigned)(a) << 24) | ((unsigned)(b) & 0xffffff))
#define CONCAT21(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define CONCAT22(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT31(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define SUB41(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define SUB42(x, c) ((unsigned short)((unsigned)(x) >> ((c) * 8)))
#define SUB43(x, c) (((unsigned)(x) >> ((c) * 8)) & 0xffffff)
#define SUB21(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define ZEXT14(x) ((unsigned)(unsigned char)(x))
#define ZEXT24(x) ((unsigned)(unsigned short)(x))
#define ZEXT12(x) ((unsigned short)(unsigned char)(x))
#define SEXT14(x) ((int)(signed char)(x))
#define SEXT24(x) ((int)(short)(x))
#define SEXT12(x) ((short)(signed char)(x))
extern int dbg_printf();
extern int oled_set_lum_gain();

/*
 * Print the brightness value and write it as luminance gain (register 0x5E) to the OLED panel controller.
 *
 *   level   brightness value, 0..0x3FF in the calls of the firmware
 *   unused  handed on to oled_set_lum_gain, which takes only one argument; the callers pass nothing
 */
void SetBrightness_copy(unsigned short level, unsigned int unused)
{
  dbg_printf("SetBrightness %d\r\n", level & 0xffff);
  oled_set_lum_gain(level & 0xffff, unused);
}