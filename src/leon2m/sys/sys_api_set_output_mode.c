/* sys_api_set_output_mode  (FUN_a0148f4c)
 *
 * Store the output mode byte and reconfigure the output timing when it changes.
 * Name basis: descriptive - stSysConfig byte +3; FRCConfigPostFRC and channel restarts on a change
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148f4c @ 0xa0148f4c-0xa0148fc0 (29 words), flags -mcpu=v8 -O3 -g.
 * Source form: the byte is reached as sys_config[3] (base + 3, not a separate label); u8 parameter; the arm with both
 * values non-zero comes first.
 */
extern unsigned char sys_config[];
extern void FRCConfigPostFRC(int, int, int);
extern void sys_restart_channel(int, int);

#define SYS_CONFIG_OUTPUT_MODE 3        /* byte +3 of the system configuration record */
#define OUTPUT_TIMING_ARG      0x960    /* second argument of FRCConfigPostFRC in the switch-over case */

/*
 * Store the output mode (byte +3 of the system configuration record). When the value changes, channel 0 is
 * restarted: at level 4 if the old and the new mode are both non-zero, otherwise the output timing is
 * reconfigured (FRCConfigPostFRC) and channel 0 is restarted at level 2.
 *
 *   mode  the new output mode; 0 and non-zero are told apart
 *
 * The value is stored after the restart request, only when it differs from the stored one.
 */
void sys_api_set_output_mode(unsigned char mode)
{
  unsigned char old_mode = sys_config[SYS_CONFIG_OUTPUT_MODE];

  if (old_mode != mode) {
    if (old_mode != 0 && mode != 0)
      sys_restart_channel(0, 4);
    else {
      FRCConfigPostFRC(0, OUTPUT_TIMING_ARG, 1);
      sys_restart_channel(0, 2);
    }
    sys_config[SYS_CONFIG_OUTPUT_MODE] = mode;
  }
}
