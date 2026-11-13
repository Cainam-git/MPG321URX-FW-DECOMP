/* sys_api_set_config_field_restart_all  (FUN_a0148fc0)
 *
 * Store a configuration field and restart all four channels at level 2.
 * Name basis: descriptive - stSysConfig field from the argument, then the channel state reset for channels
 *   0..3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148fc0 @ 0xa0148fc0 (-mcpu=v8 -O3 -g).
 * Source form: the word is accessed as member +4 of a struct at the label of the system configuration record, which
 * gives the target's base + 4 addressing.
 */
struct sys_config_words {
  unsigned int word_0;
  unsigned int converter_mode_word;     /* +4: bits 28..31 hold the converter mode */
};
extern struct sys_config_words sys_config;
extern void sys_restart_channel();

#define CONVERTER_MODE_SHIFT 28
#define CONVERTER_MODE_KEEP  0x0fffffff         /* all bits but 28..31 */

/*
 * Store the 4-bit field in bits 28..31 of word +4 of the system configuration record and restart the four
 * channels at level 2.
 *
 *   mode  the new value of the field (only its low 4 bits are kept)
 */
void sys_api_set_config_field_restart_all(int mode)
{
  sys_config.converter_mode_word = (sys_config.converter_mode_word & CONVERTER_MODE_KEEP) | (mode << CONVERTER_MODE_SHIFT);
  sys_restart_channel(0, 2);
  sys_restart_channel(1, 2);
  sys_restart_channel(2, 2);
  sys_restart_channel(3, 2);
}
