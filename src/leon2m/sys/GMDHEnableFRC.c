/* GMDHEnableFRC  (FUN_a012fcf4)
 *
 * Switch the frame-rate converter channels on as the picture-in-picture mode says.
 * Name basis: proven - prints 'GMDHEnableFRC' texts (original name); called from
 *   SysTasksBeforeDisplay_byChannel
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012fcf4 @ 0xa012fcf4-0xa01302a4 (364 words). Flags -mcpu=v8 -O3 -g. Each switch builds to a
 * jump table (switchdataD_a012f18c, switchdataD_a012f1ac).
 * Source forms the exact build depends on:
 *  - the second switch has SEPARATE case bodies for 5, 3, 6, 4 and 7 (only 1 and 2 share a label group); the
 *    bodies of 1/2 and 5, 3 and 6, 4 and 7 are identical and the compiler merges them. Written as four merged
 *    groups, the mode-0 block lands before the first switch's mode blocks instead of after them;
 *  - in the first switch, modes 1 and 2 share one block that tests pip_mode == 1 again and lets mode 2 fall
 *    through into the all-off block;
 *  - the mode-0 test is written 'if (!(bit 0)) { on } else { off }'.
 * Splitting 1/2/5 as {1},{2,5} gives the same bytes.
 */
/* Byte +7 of the device settings record: the picture-in-picture / picture-by-picture mode (0 = one picture). */
struct device_settings_record {
  unsigned char bytes_0x0[7];
  unsigned char pip_mode;
};

/* Bits of word 0 of the system configuration record. */
#define SYS_CONFIG_CHANNEL3_BIT  0x200000   /* bit 21 */
#define SYS_CONFIG_MAIN_BYPASS   26         /* bit number: bypass of the converter for the main picture */

/* Bit 0 of the first word of channel record 0 (frc_off): GlobalModeHandler sets it where it prints "FRC OFF" and
   clears it where it prints "FRC ON". */
#define CHANNEL_FRC_OFF          1

extern struct device_settings_record device_settings;
extern unsigned int channel_records;
extern unsigned int sys_config;
extern unsigned char sys_frc_last_pip_mode, sys_frc_last_bypass_bit;
extern int dbg_printf();
extern unsigned char sys_get_channel_source_class(unsigned char channel);
extern void sys_frc_set_source_class_enable(unsigned char source_class, unsigned char on);
extern void sys_frc_set_source_bit(unsigned char source_class, unsigned char on);
extern unsigned char sys_is_channel_value_below_default(void);
extern unsigned char sys_is_pip_mode_above_4(void);
extern unsigned char sys_api_is_pip_mode_above_4(void);
extern void sys_frc_switch_mode(unsigned char mode);
extern void sys_frc_derive_output_sizes(void);
extern unsigned char sys_return_zero_copy4(void);
extern void sys_frc_write_mode_values(void);
extern void sys_frc_set_active(unsigned char active);
extern void sys_frc_set_channel_bit_triple(unsigned char source_class, unsigned char on);
extern void FRC_SetMainBypassMode(unsigned char enable);
extern void ldc_hw_api_pulse_reset(void);
extern void sys_frc_set_channel_enable(int source_class, unsigned char on);

/*
 * Set up the frame-rate converter's channels for the current picture-in-picture mode (device settings byte +7,
 * 0..7; 0 = one picture). Takes no arguments; everything comes from the device settings, the system
 * configuration word and the channel records.
 *
 * Called by SysTasksBeforeDisplay_byChannel, the entry actions of channel state 0xA in GlobalModeHandler.
 *
 * Every converter bit below is chosen per channel with sys_get_channel_source_class(channel): the port of that
 * channel when it is 1, 2 or 3, else 0.
 *
 * Phases, in order:
 *   1. Print the mode and channel 0's frc_off bit (bit 0 of its first word).
 *   2. Channels 1..3, first set of switches: modes 1 / 3 / 4 set the source class enable of the first one / two /
 *      three channels (bit 7 of 0xCF011AA4..AC); modes 5 / 6 / 7 set the source bit of the first one / two /
 *      three channels (0xCF011AA0); every other switch of channels 1..3 is cleared. Modes 0, 2 and above 7
 *      clear them all.
 *   3. Channel 0's source bit: set when sys_is_channel_value_below_default or sys_is_pip_mode_above_4 says so.
 *   4. Converter mode: sys_frc_switch_mode with 1 when the picture-in-picture mode is above 4, else 0; then the
 *      output sizes are derived from the input sizes. sys_return_zero_copy4 always returns 0, so
 *      sys_frc_write_mode_values is never reached from here.
 *   5. Channels 0..3, second set of switches: the channel bit in the three converter registers
 *      (sys_frc_set_channel_bit_triple) and the converter's active bit:
 *        mode 0         channel 0 and the active bit on when channel 0's frc_off bit is clear, off when it
 *                       is set; channels 1..3 off
 *        modes 1, 2, 5  active; channels 0 and 1 on, 2 and 3 off
 *        modes 3, 6     active; channels 0..2 on, 3 off
 *        modes 4, 7     active; channels 0..3 on
 *      Each of these modes then sets the main-picture bypass from bit 26 of the system configuration word.
 *      A mode above 7 does nothing in this phase.
 *   6. System configuration bit 21: channel 3's bit is set in the three registers and then cleared again in
 *      0xCF011A00 (sys_frc_set_channel_enable).
 *   7. When the mode or bit 26 differ from the values kept at the last call, pulse the reset of the grid block
 *      (ldc_hw_api_pulse_reset) and keep the new values.
 */
void GMDHEnableFRC(void)
{
  /* Phase 1. */
  dbg_printf("\033[1;35mGMDHEnableFRC %d %d\r\n\033[m", device_settings.pip_mode, channel_records & CHANNEL_FRC_OFF);

  /* Phase 2: source enables and source bits of channels 1..3. */
  switch (device_settings.pip_mode) {
  case 1:
  case 2:
    if (device_settings.pip_mode == 1) {
      sys_frc_set_source_class_enable(sys_get_channel_source_class(1), 1);
      sys_frc_set_source_bit(sys_get_channel_source_class(1), 0);
      sys_frc_set_source_class_enable(sys_get_channel_source_class(2), 0);
      sys_frc_set_source_bit(sys_get_channel_source_class(2), 0);
      sys_frc_set_source_class_enable(sys_get_channel_source_class(3), 0);
      sys_frc_set_source_bit(sys_get_channel_source_class(3), 0);
      break;
    }
    /* mode 2 continues: all off */
  default:
  case 0:
    sys_frc_set_source_class_enable(sys_get_channel_source_class(1), 0);
    sys_frc_set_source_bit(sys_get_channel_source_class(1), 0);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(2), 0);
    sys_frc_set_source_bit(sys_get_channel_source_class(2), 0);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(3), 0);
    sys_frc_set_source_bit(sys_get_channel_source_class(3), 0);
    break;
  case 3:
    sys_frc_set_source_class_enable(sys_get_channel_source_class(1), 1);
    sys_frc_set_source_bit(sys_get_channel_source_class(1), 0);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(2), 1);
    sys_frc_set_source_bit(sys_get_channel_source_class(2), 0);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(3), 0);
    sys_frc_set_source_bit(sys_get_channel_source_class(3), 0);
    break;
  case 4:
    sys_frc_set_source_class_enable(sys_get_channel_source_class(1), 1);
    sys_frc_set_source_bit(sys_get_channel_source_class(1), 0);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(2), 1);
    sys_frc_set_source_bit(sys_get_channel_source_class(2), 0);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(3), 1);
    sys_frc_set_source_bit(sys_get_channel_source_class(3), 0);
    break;
  case 5:
    sys_frc_set_source_class_enable(sys_get_channel_source_class(1), 0);
    sys_frc_set_source_bit(sys_get_channel_source_class(1), 1);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(2), 0);
    sys_frc_set_source_bit(sys_get_channel_source_class(2), 0);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(3), 0);
    sys_frc_set_source_bit(sys_get_channel_source_class(3), 0);
    break;
  case 6:
    sys_frc_set_source_class_enable(sys_get_channel_source_class(1), 0);
    sys_frc_set_source_bit(sys_get_channel_source_class(1), 1);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(2), 0);
    sys_frc_set_source_bit(sys_get_channel_source_class(2), 1);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(3), 0);
    sys_frc_set_source_bit(sys_get_channel_source_class(3), 0);
    break;
  case 7:
    sys_frc_set_source_class_enable(sys_get_channel_source_class(1), 0);
    sys_frc_set_source_bit(sys_get_channel_source_class(1), 1);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(2), 0);
    sys_frc_set_source_bit(sys_get_channel_source_class(2), 1);
    sys_frc_set_source_class_enable(sys_get_channel_source_class(3), 0);
    sys_frc_set_source_bit(sys_get_channel_source_class(3), 1);
    break;
  }

  /* Phase 3: channel 0's source bit. */
  if (sys_is_channel_value_below_default() == 1 || sys_is_pip_mode_above_4() == 1)
    sys_frc_set_source_bit(sys_get_channel_source_class(0), 1);
  else
    sys_frc_set_source_bit(sys_get_channel_source_class(0), 0);

  /* Phase 4: converter mode (1 when the picture-in-picture mode is above 4) and output sizes. */
  sys_frc_switch_mode(sys_api_is_pip_mode_above_4());
  sys_frc_derive_output_sizes();
  if (sys_return_zero_copy4())          /* always 0 */
    sys_frc_write_mode_values();

  /* Phase 5: channel bits, active bit and main-picture bypass. */
  switch (device_settings.pip_mode) {
  case 0:
    /* One picture: channel 0 runs through the converter only while its frc_off bit is clear. */
    if (!(channel_records & CHANNEL_FRC_OFF)) {
      sys_frc_set_channel_bit_triple(sys_get_channel_source_class(0), 1);
      sys_frc_set_active(1);
    } else {
      sys_frc_set_channel_bit_triple(sys_get_channel_source_class(0), 0);
      sys_frc_set_active(0);
    }
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(1), 0);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(2), 0);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(3), 0);
    FRC_SetMainBypassMode((sys_config >> SYS_CONFIG_MAIN_BYPASS) & 1);
    break;
  case 1:
  case 2:
    /* Two channels. */
    sys_frc_set_active(1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(0), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(1), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(2), 0);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(3), 0);
    FRC_SetMainBypassMode((sys_config >> SYS_CONFIG_MAIN_BYPASS) & 1);
    break;
  case 5:
    /* Two channels. */
    sys_frc_set_active(1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(0), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(1), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(2), 0);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(3), 0);
    FRC_SetMainBypassMode((sys_config >> SYS_CONFIG_MAIN_BYPASS) & 1);
    break;
  case 3:
    /* Three channels. */
    sys_frc_set_active(1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(0), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(1), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(2), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(3), 0);
    FRC_SetMainBypassMode((sys_config >> SYS_CONFIG_MAIN_BYPASS) & 1);
    break;
  case 6:
    /* Three channels. */
    sys_frc_set_active(1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(0), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(1), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(2), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(3), 0);
    FRC_SetMainBypassMode((sys_config >> SYS_CONFIG_MAIN_BYPASS) & 1);
    break;
  case 4:
    /* Four channels. */
    sys_frc_set_active(1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(0), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(1), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(2), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(3), 1);
    FRC_SetMainBypassMode((sys_config >> SYS_CONFIG_MAIN_BYPASS) & 1);
    break;
  case 7:
    /* Four channels. */
    sys_frc_set_active(1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(0), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(1), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(2), 1);
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(3), 1);
    FRC_SetMainBypassMode((sys_config >> SYS_CONFIG_MAIN_BYPASS) & 1);
    break;
  }

  /* Phase 6: with bit 21, channel 3's bit is left set in 0xCF011800 and 0xCF011BF8 but not in 0xCF011A00. */
  if (sys_config & SYS_CONFIG_CHANNEL3_BIT) {
    sys_frc_set_channel_bit_triple(sys_get_channel_source_class(3), 1);
    sys_frc_set_channel_enable(sys_get_channel_source_class(3), 0);
  }

  /* Phase 7: reset the grid block when the mode or the bypass bit changed since the last call. */
  if (device_settings.pip_mode != sys_frc_last_pip_mode || sys_frc_last_bypass_bit != ((sys_config >> SYS_CONFIG_MAIN_BYPASS) & 1)) {
    ldc_hw_api_pulse_reset();
    sys_frc_last_pip_mode = device_settings.pip_mode;
    sys_frc_last_bypass_bit = (sys_config >> SYS_CONFIG_MAIN_BYPASS) & 1;
  }
}
