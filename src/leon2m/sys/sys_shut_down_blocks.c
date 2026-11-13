/* sys_shut_down_blocks  (FUN_a011d194)
 *
 * Run the shut-down sequence of the picture blocks and switch the PWM outputs off.
 * Returns: its argument
 * Name basis: derived - called from SYSAPI_PowerOff and SYSAPI_PowerSaving; ends by writing 0xF to 0xCF0115C0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011d194 @ 0xa011d194, flags -mcpu=v8 -O3 -g.
 * Source form: Ghidra's type and symbol names are kept; the result is the CONCAT44 of both parameters, so the
 * 32-bit return value is the first parameter.
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
#define _DAT_cf0115c0 (*(volatile unsigned int *)0xcf0115c0)
extern int input_adc_power_down();
extern int sys_poll_events_stub_copy4();
extern void pq_block_set_mode1_and_value();
extern int pq_block_blank();
extern int sys_api_reset_memory_interfaces();
extern void panel_pwm_enable();
extern int Vx1RxPowerOff();

/*
 * Shut the picture blocks and their supporting units down, in this order:
 *   1. picture block 8 to mode 1 with the value 0xB0 (pq_block_set_mode1_and_value)
 *   2. PWM channel number 0 and number 0x1F switched off (panel_pwm_enable with enable = 0)
 *   3. an empty event source (sys_poll_events_stub_copy4)
 *   4. the analogue input stage powered down (input_adc_power_down)
 *   5. the V-by-One receiver powered off (Vx1RxPowerOff)
 *   6. picture block 8 blanked (pq_block_blank)
 *   7. the memory interfaces' register sequence (sys_api_reset_memory_interfaces)
 *   8. 0xF written to register 0xCF0115C0
 * The two parameters are not used; the 32-bit result is the first one.
 * Called by SYSAPI_PowerOff and SYSAPI_PowerSaving; both call it without arguments.
 */
int sys_shut_down_blocks(undefined4 unused_1,undefined4 unused_2)

{
  pq_block_set_mode1_and_value(8,0xb0);
  panel_pwm_enable(0,0);
  panel_pwm_enable(0x1f,0);
  sys_poll_events_stub_copy4();
  input_adc_power_down();
  Vx1RxPowerOff();
  pq_block_blank(8);
  sys_api_reset_memory_interfaces();
  _DAT_cf0115c0 = 0xf;
  return CONCAT44(unused_2,unused_1);
}