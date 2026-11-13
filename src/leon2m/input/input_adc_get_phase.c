/* input_adc_get_phase  (FUN_a00f3580)
 *
 * Return the sampling position from the hook or from its register.
 * Returns: value
 * Name basis: descriptive - low six bits of 0xCF01281C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3580 @ 0xa00f3580, flags -mcpu=v8 -O3 -g.
 */

/* The record of the analogue input stage: a flag byte and hook functions (see input_adc_configure). */
struct input_adc_record {
    unsigned char enabled;                      /* +0: the hooks are used only when this is not 0 */
    void *set_line_width_hook;                  /* +4 */
    unsigned int (*get_line_width_hook)(void);  /* +8 */
    void (*set_phase_hook)(unsigned char);      /* +0xC */
    unsigned int (*get_phase_hook)(void);       /* +0x10 */
    void *hook_0x14, *hook_0x18, *hook_0x1c, *hook_0x20;
};
extern struct input_adc_record input_adc_record;

/*
 * Return the phase value: the result of the get-phase hook when the record is enabled and the hook is
 * set, otherwise the low 6 bits of register 0xCF01281C (input_adc_set_phase writes that register).
 */
unsigned char input_adc_get_phase(void)
{
    if (input_adc_record.enabled && input_adc_record.get_phase_hook)
        return input_adc_record.get_phase_hook();
    return *(volatile unsigned int *)0xcf01281c & 0x3f;
}
