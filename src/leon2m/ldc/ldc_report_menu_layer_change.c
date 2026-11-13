/* ldc_report_menu_layer_change  (FUN_a0152fac)
 *
 * Tell the dimming processor whether menu layer 0 or 1 is switched on, when that changes.
 * Note: Sends -1 (a layer is on) or 0 with ldc_write_status_word.
 * Name basis: derived - osd_is_enabled(0 / 1), compare with the last value sent, then ldc_write_status_word
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0152fac @ 0xa0152fac-0xa0153018 (27 words), flags -mcpu=v8 -O2 -g.
 * Source form: the second test of osd_is_enabled uses the second call's result; the callee arguments are the
 * constants 0 and 1.
 */
extern int ldc_menu_layer_status_last;
extern unsigned char osd_is_enabled(int);
extern void ldc_write_status_word(int);

/*
 * Tell the dimming processor when the menu layers go on or off.
 * Builds one value from the state of menu layers 0 and 1: -1 (all bits set) when layer 0 or layer 1 is switched
 * on, 0 when both are off. When the value differs from the one sent last (ldc_menu_layer_status_last), it is written
 * to the dimming processor's mailbox with ldc_write_status_word; the value is then remembered.
 * Called by the main-loop task.
 */
void ldc_report_menu_layer_change(void)
{
  int layers_on = 0;

  if (osd_is_enabled(0) || osd_is_enabled(1))
    layers_on = -1;
  if (layers_on != ldc_menu_layer_status_last)
    ldc_write_status_word(layers_on);
  ldc_menu_layer_status_last = layers_on;
}
