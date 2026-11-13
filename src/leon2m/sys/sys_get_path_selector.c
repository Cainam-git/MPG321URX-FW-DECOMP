/* sys_get_path_selector  (FUN_a0114360)
 *
 * Return the 2-bit path selector.
 * Returns: 0..3
 * Name basis: descriptive - low bits of register 0xCF01166C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0114360 @ 0xa0114360, flags -mcpu=v8 -O3 -g.
 * Source form: Ghidra's type and symbol names are kept.
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
#define reg_sys_path_selector (*(volatile unsigned int *)0xcf01166c)

/* Return bits 0..1 of reg_sys_path_selector (0xCF01166C): the path number set by sys_set_path_selector. */
uint sys_get_path_selector(void)

{
  return reg_sys_path_selector & 3;
}