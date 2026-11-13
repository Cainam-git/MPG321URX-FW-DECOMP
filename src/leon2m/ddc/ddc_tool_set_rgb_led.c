/* ddc_tool_set_rgb_led  (FUN_a00d24e0)
 *
 * Switch the RGB LED on or off as the factory tool asks and save it.
 *   param_1: request
 * Returns: 0xE0
 * Note: Bit 6 of settings word +0xA8 (the RGB LED switch of the PC tool).
 * Name basis: derived - same bit as uart_cmd_set_rgb_led; gpio port 2 bit 2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d24e0 @ 0xa00d24e0-0xa00d253c (23 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record base user_settings as a struct.
 */

/* The user settings record up to the word used here (docs/RECORDS.md). */
struct user_settings_record {
    unsigned char pad000[0xa8];
    unsigned int gaming_flags;                  /* +0xA8: bit 6 = RGB LED */
};
extern struct user_settings_record user_settings;
extern void gpio_set_port2_bit2_high(void);
extern void gpio_set_port2_bit2_low(void);
extern int SYSAPI_WriteEEPROM(int, void *, int, int);

#define TOOL_RESULT_DONE     0xe0               /* the command was carried out */
#define EEPROM_AREA_SETTINGS 0x30               /* first argument of SYSAPI_WriteEEPROM: the settings area */
#define USER_SETTINGS_SIZE   0x1fc              /* the user settings record, at offset 0 of that area */
#define GAMING_FLAG_RGB_LED  0x40               /* user settings word +0xA8, bit 6 */

/*
 * Factory tool command 0x70 (TOOL_CMD_RGB_LED): request byte 7 = 0 clears the RGB LED bit of the settings and
 * drives pin 2 of GPIO port 2 low; any other value sets the bit and drives the pin high. The user settings are
 * saved.
 *
 *   param_1  the request; byte 7 is the value
 *
 * Returns TOOL_RESULT_DONE. ddc_tool_dispatch_command carries an inlined copy of this routine; nothing calls
 * this one.
 */
int ddc_tool_set_rgb_led(unsigned char *param_1)
{
  if (param_1[7] == 0) {
    user_settings.gaming_flags &= ~GAMING_FLAG_RGB_LED;
    gpio_set_port2_bit2_low();
  } else {
    user_settings.gaming_flags |= GAMING_FLAG_RGB_LED;
    gpio_set_port2_bit2_high();
  }
  SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, &user_settings, 0, USER_SETTINGS_SIZE);
  return TOOL_RESULT_DONE;
}
