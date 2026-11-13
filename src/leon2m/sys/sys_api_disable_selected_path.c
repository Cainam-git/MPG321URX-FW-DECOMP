/* sys_api_disable_selected_path  (FUN_a010a83c)
 *
 * Switch the selected path off.
 * Name basis: descriptive - sys_set_selected_path_enable(0, path)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010a83c @ 0xa010a83c, flags -mcpu=v8 -O2 -g (section default).
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int sys_set_selected_path_enable();

/*
 * Switch the selected path off (sys_set_selected_path_enable with enable = 0).
 * path is the path number handed on unchanged.
 */
void sys_api_disable_selected_path(undefined1 path)

{
  sys_set_selected_path_enable(0,path);
  return;
}