/* sys_mode_set_pwm7_and_continue  (FUN_a01519b4)
 *
 * Set PWM port 7 to 0x3C0 and continue with the next mode step.
 * Name basis: descriptive - ConfigScalerPWM(7, 0xd, 0x3c0, 0), then sys_poll_events_stub_copy14
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01519b4 @ 0xa01519b4 (-mcpu=v8 -O2 -g, the section default).
 * Source form: the decompiler's type names and the six parameters, passed on to the second call, are kept.
 */
typedef unsigned int undefined4;

extern void ConfigScalerPWM();
extern int sys_poll_events_stub_copy14();

/*
 * Call ConfigScalerPWM(7, 0xD, 0x3C0, 0), then the empty routine sys_poll_events_stub_copy14 with the six
 * parameters unchanged.
 *
 * Called by GlobalModeHandler (GlobalModeHandler) when a channel enters state 5 and no other channel is above state 5.
 */
void sys_mode_set_pwm7_and_continue(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  ConfigScalerPWM(7,0xd,0x3c0,0);
  sys_poll_events_stub_copy14(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}
