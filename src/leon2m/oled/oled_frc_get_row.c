/* oled_frc_get_row  (FUN_a01295c4)
 *
 * Return the refresh-rate row index that is sent to the panel.
 * Returns: row index
 * Name basis: derived - byte at 0xA802D893
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01295c4 @ 0xa01295c4, flags -mcpu=v8 -O2.
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
extern unsigned char oled_frc_state_row_index;

/*
 * Return the refresh-rate row index last stored by oled_frc_set_row (0xFF after oled_frc_reset).
 * Called only by SYSAPI_GetPanelParamStruct, which compares it with the row it has chosen.
 */
unsigned char oled_frc_get_row(void)
{
  return oled_frc_state_row_index;
}