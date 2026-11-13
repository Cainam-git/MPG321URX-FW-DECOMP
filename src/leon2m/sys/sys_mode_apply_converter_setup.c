/* sys_mode_apply_converter_setup  (FUN_a015149c)
 *
 * Apply the converter configuration selected by the system configuration fields to units 0..3.
 * Name basis: descriptive - calls chosen by stSysConfig fields; only caller is GlobalModeHandler, for a
 *   channel in MODE_WAITPANELREADY
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015149c @ 0xa015149c, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: the converter mode is read once into a signed char and compared in the
 * order 2, (< 3) 1, 3; the last unit's first argument goes through a separate variable (`on`); the record's
 * bit-field word is not volatile and is not read before panel_get_active_row.
 */

extern void sys_frc_set_dc0_bit(int, int);
extern void sys_frc_set_dc4_bit(int, int);
extern unsigned int panel_get_active_row(void);
extern void sys_set_channel_path_mode(unsigned char, unsigned char);
extern void ldc_hw_api_pulse_reset(void);
/* Word +0 of the record is a row of flag bits; word +4 holds three 4-bit fields. */
struct E3D0bits {
    unsigned int b31:1, b30:1, b29:1, b28:1, b27:1, b26:1, b25:1, b24:1, r0:24;
    unsigned int converter_mode:4, path_mode_ch0:4, path_mode_ch1:4, r1:20;
};
union E3D0 { struct E3D0bits f; unsigned char b[0x30]; };
extern union E3D0 sys_config;
/*
 * Apply the stored converter configuration of the system configuration record.
 *
 * First the active panel row is fetched (the result is not used), then the path modes of channel 0 and
 * channel 1 are applied (sys_set_channel_path_mode). The converter mode (4-bit field at bit 28 of word +4)
 * then picks one pattern, and the same pattern is written for units 0 to 3: bit i of register 0xCF011DC0
 * (sys_frc_set_dc0_bit) and bit i of register 0xCF011DC4 (sys_frc_set_dc4_bit).
 *
 *   converter mode   2: DC0 bit 0, DC4 bit 1     1: DC0 bit 1, DC4 bit 0
 *                    3: both bits 1               any other value (0 and 4 to 15): both bits 0
 *
 * The routine ends with ldc_hw_api_pulse_reset in every case.
 *
 * Called by the per-port state step (GlobalModeHandler) when a port's state word has 0xa in its top nibble and
 * other_above(port, 9) is false.
 */
void sys_mode_apply_converter_setup(void)
{
  char mode;
  int on;
  /* The result is not used. */
  panel_get_active_row();
  sys_set_channel_path_mode(0, sys_config.f.path_mode_ch0);
  sys_set_channel_path_mode(1, sys_config.f.path_mode_ch1);
  mode = sys_config.f.converter_mode;
  if (mode == 2)
  {
    sys_frc_set_dc0_bit(0, 0);
    sys_frc_set_dc4_bit(0, 1);
    sys_frc_set_dc0_bit(1, 0);
    sys_frc_set_dc4_bit(1, 1);
    sys_frc_set_dc0_bit(2, 0);
    on = 0;
    sys_frc_set_dc4_bit(2, 1);
    sys_frc_set_dc0_bit(3, on);
    sys_frc_set_dc4_bit(3, 1);
    ldc_hw_api_pulse_reset();
    return;
  }
  if (mode < 3)
  {
    if (mode == 1)
    {
      sys_frc_set_dc0_bit(0, 1);
      sys_frc_set_dc4_bit(0, 0);
      sys_frc_set_dc0_bit(1, 1);
      sys_frc_set_dc4_bit(1, 0);
      sys_frc_set_dc0_bit(2, 1);
      on = 1;
      sys_frc_set_dc4_bit(2, 0);
      sys_frc_set_dc0_bit(3, on);
      sys_frc_set_dc4_bit(3, 0);
      ldc_hw_api_pulse_reset();
      return;
    }
  }
  else
    if (mode == 3)
  {
    sys_frc_set_dc0_bit(0, 1);
    sys_frc_set_dc4_bit(0, 1);
    sys_frc_set_dc0_bit(1, 1);
    sys_frc_set_dc4_bit(1, 1);
    sys_frc_set_dc0_bit(2, 1);
    sys_frc_set_dc4_bit(2, 1);
    on = 1;
    sys_frc_set_dc0_bit(3, on);
    sys_frc_set_dc4_bit(3, 1);
    ldc_hw_api_pulse_reset();
    return;
  }
  sys_frc_set_dc0_bit(0, 0);
  sys_frc_set_dc4_bit(0, 0);
  sys_frc_set_dc0_bit(1, 0);
  sys_frc_set_dc4_bit(1, 0);
  sys_frc_set_dc0_bit(2, 0);
  sys_frc_set_dc4_bit(2, 0);
  on = 0;
  sys_frc_set_dc0_bit(3, on);
  sys_frc_set_dc4_bit(3, 0);
  ldc_hw_api_pulse_reset();
}
