/* sys_set_state_bit10_and_apply  (FUN_a0083b14)
 *
 * Set bit 10 of the app state word; with PIP/PBP off make channel 0's port the source of channel 1.
 * Note: Application callback number 7; no direct caller.
 * Name basis: descriptive - app_state_record |= 0x400; when settings +0x1F is 0:
 *   sys_api_select_channel_source(1, port code of channel 0); registered as callback 7 by
 *   startup_register_app_callbacks
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0083b14 @ 0xa0083b14, flags -mcpu=v8 -O3 -g.
 * Source form: the decompiler's form is kept: declared void with six parameters that are handed on to
 * sys_api_select_channel_source unchanged, the 'return' statements with values, and the dead store to
 * unused_flag; the registered-callback caller passes none of them.
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
extern unsigned char user_settings_pip_pbp_mode;
extern unsigned short app_state_record;
extern int input_api_get_channel_port_code();
extern int sys_api_select_channel_source();

/*
 * Callback number 7 of the application layer (registered by startup_register_app_callbacks; nothing calls it
 * directly). It marks the application state and, while picture-in-picture / picture-by-picture is off, copies
 * the port of channel 0 to channel 1.
 *
 * Sets bit 10 (0x400) of app_state_record. Then, only when the PIP/PBP mode of the user settings is 0 (off),
 * it asks channel 0 for its port code and calls sys_api_select_channel_source(1, port_code), which sets that
 * port as the source of channel 1. With any other PIP/PBP mode nothing more happens.
 *
 *   param_3 .. param_6   handed on to sys_api_select_channel_source, which takes only two arguments
 *   param_1, param_2     not used for anything
 */
void sys_set_state_bit10_and_apply(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  uint port_code;
  undefined4 unused_flag;
  
  app_state_record = app_state_record | 0x400;
  port_code = 0;
  if (user_settings_pip_pbp_mode == '\0') {
    port_code = input_api_get_channel_port_code(0) & 0xff;
    unused_flag = 1;
    return sys_api_select_channel_source(1,port_code,param_3,param_4,param_5,param_6);
  }
  return CONCAT44(param_2,1);
}