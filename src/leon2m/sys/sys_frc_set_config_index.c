/* sys_frc_set_config_index  (FUN_a01118c0)
 *
 * Store the first index that selects the frame-rate converter's ROM settings.
 * Name basis: descriptive - byte at 0xA802C98E; called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01118c0 @ 0xa01118c0, flags -mcpu=v8 -O2 -g (section default).
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
extern unsigned char sys_frc_config_index;

/*
 * Store the first index into the converter's ROM settings table. sys_frc_load_rom_settings reads it together
 * with sys_frc_config_index2 to pick the settings set.
 */
void sys_frc_set_config_index(undefined1 index)

{
  sys_frc_config_index = index;
  return;
}