/* sys_frc_divide_by_ratio  (FUN_a01085a4)
 *
 * Replace a value by value / (ratio + 1) + 1 when channel is 0 and bit 4 of 0xCF011A00 is set.
 * Name basis: descriptive - (0xCF0116D0 & 0x7F) + 1; one more for channel 0 with bit 4 set; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01085a4 @ 0xa01085a4, flags -mcpu=v8 -O3 -g.
 */
#define REG_CF011A00 (*(volatile unsigned int *)0xcf011a00)
#define REG_CF0116D0 (*(volatile unsigned int *)0xcf0116d0)

/*
 * When `channel` is 0 and bit 4 of register 0xCF011A00 is set, replace *value with
 * *value / ((register 0xCF0116D0 & 0x7f) + 1) + 1. Otherwise *value is left alone.
 * Nothing in the image calls it.
 */
void sys_frc_divide_by_ratio(unsigned char channel, unsigned int *value)
{
    if (channel == 0 && (REG_CF011A00 & 0x10))
        *value = *value / ((REG_CF0116D0 & 0x7f) + 1) + 1;
}
