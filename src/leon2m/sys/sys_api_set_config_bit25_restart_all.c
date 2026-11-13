/* sys_api_set_config_bit25_restart_all  (FUN_a0148ef4)
 *
 * Store configuration bit 25 and restart all four channels.
 * Name basis: descriptive - stSysConfig bit 25, then the channel state reset for channels 0..3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148ef4 @ 0xa0148ef4 (-mcpu=v8 -O3 -g).
 * Source form: the decompiler's type names and its six parameters are kept. The last call is made with the
 * four extra parameters passed through, which the exact build depends on.
 */
typedef unsigned int uint, undefined4;

/* Word 0 of the system configuration record: bit 25. */
#define SYS_CONFIG_BIT25_SHIFT 25
#define SYS_CONFIG_BIT25_MASK  0xfdffffff       /* all bits but bit 25 */
/* Level passed to sys_restart_channel: the channel is set back to its earlier state. */
#define RESTART_LEVEL_1 1
extern unsigned int sys_config;
extern void sys_restart_channel();

/*
 * Store bit 25 of the system configuration word and restart the four channels at level 1.
 *
 *   bit  bit 0 is the new value of configuration bit 25
 *   unused_2 .. unused_6  not used here; unused_3 .. unused_6 are passed on to the call for channel 3
 *
 * Called with bit 30 of the settings word user_settings_option_bits. The picture-timing code tests
 * configuration bit 25 together with a flag of the channel record.
 */
void sys_api_set_config_bit25_restart_all(uint bit,undefined4 unused_2,undefined4 unused_3,undefined4 unused_4,
                 undefined4 unused_5,undefined4 unused_6)

{
  sys_config = sys_config & SYS_CONFIG_BIT25_MASK | (bit & 1) << SYS_CONFIG_BIT25_SHIFT;
  sys_restart_channel(0,RESTART_LEVEL_1);
  sys_restart_channel(1,RESTART_LEVEL_1);
  sys_restart_channel(2,RESTART_LEVEL_1);
  sys_restart_channel(3,RESTART_LEVEL_1,unused_3,unused_4,unused_5,unused_6);
  return;
}
