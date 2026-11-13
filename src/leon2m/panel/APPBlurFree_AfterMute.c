/* APPBlurFree_AfterMute  (FUN_a00875ec)
 *
 * Switch blur reduction off after the picture was muted and apply the brightness as for off.
 * Note: Puts back only the low byte of settings word +0xB0 afterwards; its upper three bytes end up 0.
 * Name basis: proven - prints 'APPBlurFree_AfterMute' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00875ec @ 0xa00875ec-0xa008767c (36 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the saved copy is an unsigned char (the firmware loads only the low byte, +0xB3) and is stored back into
 *    the whole word;
 *  - bit 14 of the halfword at +0x3E is a 1-bit bit-field (a mask test gives btst before andn).
 */

#define BLURFREE_MODE_OFF 0                 /* panel_api_set_blurfree_mode: 0 off, 1 GEN1, 2 and 3 GEN2 */

/* The field of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0xb0];
    unsigned int blur_free_mode;            /* +0xB0: the blur reduction setting */
};
/* The flag halfword at +0x3E of the application state record. */
struct app_state_record {
    unsigned char pad0[0x3e];
    unsigned short flag_15 : 1,
                   flag_14 : 1,             /* +0x3E bit 14: when set, the brightness step below is skipped */
                   rest : 14;
};
extern struct user_settings_record user_settings;
extern struct app_state_record app_state_record;
extern void sys_user_apply_brightness(void);
extern void dbg_printf(char *);
extern void ldc_api_set_mode_byte(int);
extern void panel_blurfree_set_parameter(unsigned int number, unsigned short value);
extern void panel_api_set_blurfree_mode(int);
extern void ldc_api_set_direct_pwm(int);
extern void panel_blurfree_set_pin_functions(int, int);

/*
 * Put the blur reduction hardware into its off state, as needed after the picture was muted, and apply the
 * brightness once more as for blur reduction off.
 *
 * The dimming processor gets mode byte 0 and direct PWM off (ldc_api_set_direct_pwm(0)); blur reduction
 * parameter 2 becomes 0x3FF and the blur reduction mode 0 (off).
 *
 * sys_user_apply_brightness chooses full brightness when the blur reduction setting is on (and the input meets
 * its rate test), so the setting is cleared for the time of that call and then put back. When flag bit 14 of the
 * application state halfword +0x3E is set, the brightness step is skipped once and the flag cleared.
 *
 * Note: only the low byte of the setting is put back; the upper three bytes of the word end up 0.
 */
void APPBlurFree_AfterMute(void)
{
  unsigned char saved_mode = user_settings.blur_free_mode;

  dbg_printf("APPBlurFree_AfterMute\r\n");
  ldc_api_set_mode_byte(0);
  panel_blurfree_set_pin_functions(1, 0xff);
  panel_blurfree_set_parameter(2, 0x3ff);
  panel_api_set_blurfree_mode(BLURFREE_MODE_OFF);
  ldc_api_set_direct_pwm(0);
  user_settings.blur_free_mode = 0;
  if (app_state_record.flag_14)
    app_state_record.flag_14 = 0;
  else
    sys_user_apply_brightness();
  user_settings.blur_free_mode = saved_mode;
}
