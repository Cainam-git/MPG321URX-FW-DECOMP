/* oled_power_get_field_10  (FUN_a01279ac)
 *
 * Return field +0x10 of the OLED power state record.
 * Returns: byte
 * Name basis: descriptive - byte at 0xA802D896 + 0x10
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01279ac @ 0xa01279ac, flags -mcpu=v8 -O2.
 * Source form: a direct read of the extern byte.
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
extern unsigned char oled_power_state_qsm_done;

/*
 * Return field +0x10 of the OLED power state record. APPSetPowerOff reads it together with fields +0x11 and +0x12.
 */
unsigned char oled_power_get_field_10(void)
{
  return oled_power_state_qsm_done;
}