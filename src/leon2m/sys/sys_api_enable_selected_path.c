/* sys_api_enable_selected_path  (FUN_a010a824)
 *
 * Switch the selected path on.
 * Name basis: descriptive - sys_set_selected_path_enable(1, path)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010a824 @ 0xa010a824, flags -mcpu=v8 -O2 -g (section default).
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
 * Switch the selected path on (sys_set_selected_path_enable with enable = 1).
 * path is the path number handed on unchanged.
 */
void sys_api_enable_selected_path(undefined1 path)

{
  sys_set_selected_path_enable(1,path);
  return;
}