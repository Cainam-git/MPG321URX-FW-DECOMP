/* sys_api_set_config_bit21  (FUN_a014a7f4)
 *
 * Store configuration bit 21.
 * Name basis: descriptive - stSysConfig bit 21; called from UserSetPIPMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a7f4 @ 0xa014a7f4 (-mcpu=v8 -O2 -g, the section default).
 * Source form: the decompiler's type names and the mask/shift expression are kept.
 */
typedef unsigned int uint;

/* Word 0 of the system configuration record: bit 21 (channel 3 is switched on, see sys_restart_channel callers). */
#define SYS_CONFIG_BIT21_SHIFT 21
#define SYS_CONFIG_BIT21_MASK  0xffdfffff       /* all bits but bit 21 */
extern unsigned int sys_config;

/*
 * Store bit 21 of the system configuration word.
 *
 *   bit  bit 0 is the new value
 *
 * Called from UserSetPIPMode (UserSetPIPMode) with 0 or 1.
 */
void sys_api_set_config_bit21(uint bit)

{
  sys_config = sys_config & SYS_CONFIG_BIT21_MASK | (bit & 1) << SYS_CONFIG_BIT21_SHIFT;
  return;
}
