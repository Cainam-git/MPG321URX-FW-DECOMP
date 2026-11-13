/* input_adc_wait_clock_stable  (FUN_a00f381c)
 *
 * Wait until the measured clock value stays near its target for 30 ticks, at most 299 ticks.
 * Name basis: descriptive - 24-bit value within 8191 of the stored target; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f381c @ 0xa00f381c, flags -mcpu=v8 -O3 -g.
 * Source form: the range test is nested ifs (a combined && folds into one range compare).
 */

#define REG32(a) (*(volatile unsigned int *)(a))

extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);
extern unsigned int reg_read24_bytes(volatile unsigned int *r);
extern int input_adc_clock_target;

/*
 * Wait until the 24-bit value at 0xCF012848 is close to input_adc_clock_target, but give up after 299 ticks.
 * The value is multiplied by 4 when register 0xCF012844 reads 0xA and by 2 when it reads 0xB (the values
 * input_adc_set_line_width writes there). The wait ends when the difference to the target is within
 * +-8191 and more than 30 ticks have passed since the start. No code calls this routine.
 */
void input_adc_wait_clock_stable(void)
{
    unsigned short start = timer_get_ticks16();
    int value, difference;

    for (;;) {
        value = reg_read24_bytes((volatile unsigned int *)0xcf012848);
        if (REG32(0xcf012844) == 0xa)
            value <<= 2;
        else if (REG32(0xcf012844) == 0xb)
            value <<= 1;
        difference = value - input_adc_clock_target;
        if (difference >= -8191)
            if (difference <= 8191)
                if (timer_ticks_since(start) > 30)
                    break;
        if (timer_ticks_since(start) > 299)
            break;
    }
}
