/* sys_user_apply_mode_byte  (FUN_a00db174)
 *
 * Store the mode byte from settings bit 30.
 * Name basis: descriptive - bit 30 of the settings word at 0xA802D484
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00db174 @ 0xa00db174, flags -mcpu=v8 -O3 -g.
 * Source form: the two calls and returns are written out separately (an if with an early return).
 */
extern unsigned int user_settings_word_0x1f4;
extern void sys_set_mode_byte_c9f8(unsigned char value);

#define WORD_0x1F4_BIT30 0x40000000

/* Store 1 or 0 in the mode byte at 0xA802C9F8, by bit 30 of the settings word at +0x1F4. */
void sys_user_apply_mode_byte(void)
{
  if ((user_settings_word_0x1f4 & WORD_0x1F4_BIT30) != 0) {
    sys_set_mode_byte_c9f8(1);
    return;
  }
  sys_set_mode_byte_c9f8(0);
  return;
}
