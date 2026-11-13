/* pq_apply_settings_by_mask  (FUN_a00874c8)
 *
 * Write value v to setting ids 4..11 for each bit set in bits.
 *   mask: bit i selects setting id 4 + i
 *   value
 * Name basis: derived - calls the setting-id dispatcher panel_blurfree_set_parameter
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00874c8 @ 0xa00874c8-0xa00875ec.
 * Source form: a sequence of eight independent if statements; the last call is a tail call.
 */
extern void panel_blurfree_set_parameter(unsigned int, unsigned short);

#define SETTING_ID_BASE 4 /* BLURFREE_PARAM_DELAY_CHANNEL_0: ids 4..11 = delays of PWM channels 0..7 */

/*
 * Set the blur-reduction delay of each PWM channel selected by mask to value.
 * For each bit i (0..7) set in mask, panel_blurfree_set_parameter(SETTING_ID_BASE + i, value) sets the delay
 * of PWM channel i.
 * Caller: panel_blurfree_apply_user_mode.
 */
void pq_apply_settings_by_mask(unsigned char mask, unsigned char value)
{
  if (mask & 0x01)
    panel_blurfree_set_parameter(4, value);
  if (mask & 0x02)
    panel_blurfree_set_parameter(5, value);
  if (mask & 0x04)
    panel_blurfree_set_parameter(6, value);
  if (mask & 0x08)
    panel_blurfree_set_parameter(7, value);
  if (mask & 0x10)
    panel_blurfree_set_parameter(8, value);
  if (mask & 0x20)
    panel_blurfree_set_parameter(9, value);
  if (mask & 0x40)
    panel_blurfree_set_parameter(10, value);
  if (mask & 0x80)
    panel_blurfree_set_parameter(11, value);
}
