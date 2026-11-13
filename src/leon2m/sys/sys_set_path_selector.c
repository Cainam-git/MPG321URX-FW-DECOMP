/* sys_set_path_selector  (FUN_a011433c)
 *
 * Write the 2-bit path selector.
 * Name basis: descriptive - low bits of register 0xCF01166C; set by GlobalModeHandler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011433c @ 0xa011433c, flags -mcpu=v8 -O2 -g (section default).
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

#define PATH_SELECTOR_MASK 3    /* bits 0..1 of the register hold the path number */

/*
 * Write the path number (low 2 bits of `path`) to bits 0..1 of reg_sys_path_selector, keeping bits 2..7 and
 * clearing the rest of the register. sys_set_selected_path_enable compares its path argument with this field.
 * Called by a routine in the code of GlobalModeHandler (with the source field of a channel's record).
 */
void sys_set_path_selector(uint path)

{
  reg_sys_path_selector = reg_sys_path_selector & 0xfc | path & PATH_SELECTOR_MASK;
  return;
}