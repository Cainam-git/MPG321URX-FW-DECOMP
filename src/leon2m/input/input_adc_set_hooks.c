/* input_adc_set_hooks  (FUN_a00f3a04)
 *
 * Store the four function pointers of the calibration's hook record.
 * Note: Nothing calls it. The adjustment routines call through the record's entries when they are set.
 * Name basis: descriptive - 16-byte record at 0xA802B79C; its words are called as functions by
 *   input_adc_get_line_width, input_adc_get_phase and the adjustment routines
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3a04 @ 0xa00f3a04, 44 bytes, leaf, flags -mcpu=v8 -O3 -g.
 * Source form: a structure assignment of a four-word structure (copied word by word).
 */
struct adc_hook_record { unsigned int word[4]; };
extern struct adc_hook_record input_adc_cal_hooks;

/* Copy a four-word record to 0xA802B79C. Nothing calls this routine. */
void input_adc_set_hooks(const struct adc_hook_record *record)
{
    input_adc_cal_hooks = *record;
}
