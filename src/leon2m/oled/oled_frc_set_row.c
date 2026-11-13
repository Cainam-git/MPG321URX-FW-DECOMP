/* oled_frc_set_row  (FUN_a01295b8)
 *
 * Store the refresh-rate row index that is sent to the panel.
 * Name basis: derived - byte at 0xA802D893, sent to panel register 0xB2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01295b8 @ 0xa01295b8, flags -mcpu=v8 -O2 -g (gcc 3.4.4).
 * Source form: a direct store to the extern byte.
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
 * Store the refresh-rate row index that oled_frc_task sends to the OLED panel controller (register 0xB2 of
 * the device at I2C address 0x60; the task prints "OLED set Frame rate control %d").
 *
 *   row  index of the row in panel_mode_rows
 *
 * Called only by SYSAPI_GetPanelParamStruct, at three places.
 */
void oled_frc_set_row(unsigned char row)
{
  oled_frc_state_row_index = row;
}