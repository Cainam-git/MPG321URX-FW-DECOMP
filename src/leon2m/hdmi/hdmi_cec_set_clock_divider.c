/* hdmi_cec_set_clock_divider  (FUN_a00fc1cc)
 *
 * Write the CEC clock divider for the current clock setting.
 * Name basis: descriptive - 0x78 >> (0xCF011480 & 3) to 0xCF012004; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fc1cc @ 0xa00fc1cc, flags -mcpu=v8 -O3 -g.
 * Source form: a separate register write in each arm of the if/else (signed shift of the int constant).
 */
#define REG_1480           (*(volatile unsigned int *)0xcf011480)   /* bits 0..1: shift count for the divider */
#define CEC_DIVIDER_REG    (*(volatile unsigned int *)0xcf012004)
#define CEC_DIVIDER_BASE   0x78

/*
 * Write the value of the divider register of the CEC block: 0x78, shifted right by the number in bits 0..1 of
 * register 0xCF011480. hdmi_cec_init ends with the same steps. Nothing calls this routine.
 */
void hdmi_cec_set_clock_divider(void)
{
    unsigned int shift = REG_1480 & 3;
    if (shift)
        CEC_DIVIDER_REG = CEC_DIVIDER_BASE >> shift;
    else
        CEC_DIVIDER_REG = CEC_DIVIDER_BASE;
}
