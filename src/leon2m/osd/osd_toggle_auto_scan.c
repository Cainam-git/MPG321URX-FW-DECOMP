/* osd_toggle_auto_scan  (FUN_a0097138)
 *
 * Switch automatic input scanning on or off.
 * Note: Toggles bit 9 of the settings word +0x00.
 * Name basis: proven - handler table 0xA802422C: OK on state 0x22 = 'Auto Scan'; texts 0x196B24: HDMI 1, HDMI
 *   2, DP, Type C, Auto Scan
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097138 @ 0xa0097138-0xa0097190 (22 words), flags -mcpu=v8 -O3 -g.
 * Source form: an if/else with the clear test first ((word & 0x200) == 0 sets the bit, the else arm clears it);
 * the opposite arm order swaps the or/andn values and the branches. The settings word is read again for the
 * call. Same pattern as osd_toggle_ai_vision.
 */
/* The first word of the user settings record. */
struct user_settings_record { unsigned int word_0x0; };
extern struct user_settings_record user_settings;
extern unsigned char osd_request_bits;
extern void sys_api_set_config_bit31(unsigned int);
extern void osd_draw_auto_scan_switch(unsigned char);

#define SETTINGS_WORD0_AUTO_SCAN     0x200      /* bit 9 of settings word +0: Auto Scan on */
#define AUTO_SCAN_SHIFT              9
#define OSD_REQUEST_SETTINGS_CHANGED 0x02       /* bit of osd_request_bits: event 0x80 */

/*
 * OK on the Auto Scan item of the Input Source page: flip bit 9 of settings word +0 and pass the new bit to
 * sys_api_set_config_bit31. Then the Auto Scan switch is redrawn and the settings-changed request bit is set.
 */
void osd_toggle_auto_scan(void)
{
  if ((user_settings.word_0x0 & SETTINGS_WORD0_AUTO_SCAN) == 0)
    user_settings.word_0x0 |= SETTINGS_WORD0_AUTO_SCAN;
  else
    user_settings.word_0x0 &= ~SETTINGS_WORD0_AUTO_SCAN;
  sys_api_set_config_bit31(user_settings.word_0x0 >> AUTO_SCAN_SHIFT & 1);
  osd_draw_auto_scan_switch(1);
  osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
}
