/* input_adc_set_line_width  (FUN_a00f36b8)
 *
 * Write the 16-bit width value and select the matching range.
 * Name basis: descriptive - range 0xA / 0xB / 0xC in 0xCF012844 from a measured count
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f36b8 @ 0xa00f36b8, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the float comparison value is written from (int)count.
 */

#define REG32(a) (*(volatile unsigned int *)(a))

/* The record of the analogue input stage: a flag byte and hook functions (see input_adc_configure). */
struct input_adc_record {
    unsigned char enabled;                      /* +0: the hooks are used only when this is not 0 */
    void (*set_line_width_hook)(unsigned char, unsigned short);     /* +4 */
    unsigned int (*get_line_width_hook)(void);  /* +8 */
    void (*set_phase_hook)(unsigned char);      /* +0xC */
    unsigned int (*get_phase_hook)(void);       /* +0x10 */
    void *hook_0x14, *hook_0x18, *hook_0x1c, *hook_0x20;
};
extern struct input_adc_record input_adc_record;
extern int input_adc_clock_target;
extern unsigned short input_measure_read16(unsigned char blk, unsigned char reg);
extern void reg_write16_bytes(volatile unsigned int *r, unsigned int v);

/*
 * Set the line width value of measurement block blk to val.
 * The 13-bit count in register 0x12 of the block (input_measure_read16) chooses the value written to
 * 0xCF012844: 0xA above 3840, 0xB above 1920, else 0xC. Bit 5 of 0xCF012804 is cleared. The clock target
 * that input_adc_wait_clock_stable waits for becomes count << 13, or -1 when the count is 0 or 0x1FFF.
 * val goes to the register pair 0xCF012820 (low byte first) and, when the record is enabled and the hook
 * is set, to the set-line-width hook together with blk.
 * Called by input_adc_step_width_to_target and input_block_power.
 */
void input_adc_set_line_width(unsigned char blk, unsigned short val)
{
    unsigned short count = input_measure_read16(blk, 0x12) & 0x1fff;
    float count_float = (int)count;

    if (count_float > 3840.0f)
        REG32(0xcf012844) = 0xa;
    else if (count_float > 1920.0f)
        REG32(0xcf012844) = 0xb;
    else
        REG32(0xcf012844) = 0xc;
    REG32(0xcf012804) &= ~0x20;
    if (count == 0x1fff || count == 0)
        input_adc_clock_target = -1;
    else
        input_adc_clock_target = count << 13;
    reg_write16_bytes((volatile unsigned int *)0xcf012820, val);
    if (input_adc_record.enabled && input_adc_record.set_line_width_hook)
        input_adc_record.set_line_width_hook(blk, val);
}
