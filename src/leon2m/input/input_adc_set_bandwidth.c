/* input_adc_set_bandwidth  (FUN_a00f35d0)
 *
 * Write a 3-bit setting to three registers of the analogue input stage.
 * Name basis: descriptive - selector 8 = a level 0..7 from a measured count; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f35d0 @ 0xa00f35d0, flags -mcpu=v8 -O3 -g.
 */

#define REG32(a) (*(volatile unsigned int *)(a))

extern int timer_sleep_ticks(int, ...);
extern unsigned int reg_read16_bytes(volatile unsigned int *p);

/*
 * Write a 3-bit level (level << 5) to the three registers 0xCF020024, 0xCF02002C and 0xCF020034.
 * Level 8 asks for a level to be worked out first: it clears 0xCF01245C, writes 5 to 0xCF012458, waits
 * (FUN_4008d1a0(5)), reads the 16-bit count n at 0xCF012460 and takes q = 0x180000 / n. The level is then
 *   q <= 0x24: 7   <= 0x36: 6   <= 0x4F: 5   <= 0x59: 4   <= 0x6D: 3   <= 0x8B: 2   <= 0xB3: 1   larger: 0.
 * No code calls this routine.
 */
void input_adc_set_bandwidth(unsigned int level)
{
    unsigned short count, quotient;

    if (level == 8) {
        REG32(0xcf01245c) = 0;
        REG32(0xcf012458) = 5;
        timer_sleep_ticks(5);
        count = reg_read16_bytes((volatile unsigned int *)0xcf012460);
        quotient = 0x180000 / count;
        if (quotient <= 0x24)
            level = 7;
        else if (quotient <= 0x36)
            level = 6;
        else if (quotient <= 0x4f)
            level = 5;
        else if (quotient <= 0x59)
            level = 4;
        else if (quotient <= 0x6d)
            level = 3;
        else if (quotient <= 0x8b)
            level = 2;
        else if (quotient <= 0xb3)
            level = 1;
        else
            level = 0;
    }
    REG32(0xcf020024) = (unsigned char)(level << 5);
    REG32(0xcf02002c) = (unsigned char)(level << 5);
    REG32(0xcf020034) = (unsigned char)(level << 5);
}
