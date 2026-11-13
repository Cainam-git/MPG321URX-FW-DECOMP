/* input_adc_set_phase  (FUN_a00f37d0)
 *
 * Write the sampling position and pass it to the hook.
 * Name basis: descriptive - register 0xCF01281C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f37d0 @ 0xa00f37d0, flags -mcpu=v8 -O3 -g.
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
 * Write phase to register 0xCF01281C and, when the record is enabled and the hook is set, pass it to the
 * set-phase hook as well. input_adc_get_phase reads it back.
 */
void input_adc_set_phase(unsigned char phase)
{
    *(volatile unsigned int *)0xcf01281c = phase;
    if (input_adc_record.enabled && input_adc_record.set_phase_hook)
        input_adc_record.set_phase_hook(phase);
}
