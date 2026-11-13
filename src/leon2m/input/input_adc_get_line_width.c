/* input_adc_get_line_width  (FUN_a00f3528)
 *
 * Return the 16-bit width value from the hook or from its register pair.
 * Returns: value
 * Name basis: descriptive - register pair at 0xCF012820
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3528 @ 0xa00f3528, flags -mcpu=v8 -O3 -g.
 * Source form: two early returns (not one result variable) give the firmware's register use after the calls.
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
extern unsigned int reg_read16_bytes(volatile unsigned int *p);

/*
 * Return the line width value (16 bits): the result of the get-line-width hook when the record is
 * enabled and the hook is set, otherwise the register pair at 0xCF012820 (low byte first).
 * input_adc_set_line_width writes the same register pair.
 */
unsigned short input_adc_get_line_width(void)
{
    if (input_adc_record.enabled && input_adc_record.get_line_width_hook)
        return input_adc_record.get_line_width_hook();
    return reg_read16_bytes((volatile unsigned int *)0xcf012820);
}
