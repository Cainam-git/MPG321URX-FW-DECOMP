/* sys_get_block_5a00_byte  (FUN_a011440c)
 *
 * Return the low byte of register 0xCF015A00.
 * Returns: byte
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011440c @ 0xa011440c, flags -mcpu=v8 -O3 -g.
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
#define _DAT_cf015a00 (*(volatile unsigned int *)0xcf015a00)

/*
 * Return the low byte of register 0xCF015A00. sys_set_selected_path_enable writes 1 or 0 to this register.
 * input_block_set_size_pair uses a non-zero result, together with the path selector, to halve a size above 0x780.
 */
uint sys_get_block_5a00_byte(void)

{
  return _DAT_cf015a00 & 0xff;
}