/* input_adc_select_reference  (FUN_a00f31bc)
 *
 * Select the reference of the analogue input stage by a selector.
 * Name basis: descriptive - registers 0xCF020080 / 0xCF02006C / 0xCF02003C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f31bc @ 0xa00f31bc, flags -mcpu=v8 -O3 -g.
 * Source form: the two selector cases are tested inside 'if (selector <= 3)' (the firmware compares with 3 first),
 * 2 before 0, each with its own return; every other value falls through to the common block.
 */

#define ANALOG_REG_80 (*(volatile unsigned int *)0xcf020080)
#define ANALOG_REG_6C (*(volatile unsigned int *)0xcf02006c)
#define ANALOG_REG_3C (*(volatile unsigned int *)0xcf02003c)

/*
 * Set the three registers 0xCF020080, 0xCF02006C and 0xCF02003C according to selector:
 *   2          bits 0xE0 of 6C and 3C cleared, bit 4 of 80 cleared and bit 7 set
 *   0          bits 0xE0 of 6C and 3C cleared, bit 7 of 80 cleared and bit 4 set
 *   any other  bits 4 and 7 of 80 cleared, bits 0xE0 of 6C and 3C set
 * Called by input_adc_calibrate_levels and input_adc_calibrate_internal.
 */
void input_adc_select_reference(unsigned int selector)
{
    if (selector <= 3) {
        if (selector == 2) {
            ANALOG_REG_6C &= ~0xe0;
            ANALOG_REG_80 &= ~0x10;
            ANALOG_REG_80 |= 0x80;
            ANALOG_REG_3C &= ~0xe0;
            return;
        }
        if (selector == 0) {
            ANALOG_REG_6C &= ~0xe0;
            ANALOG_REG_80 &= ~0x80;
            ANALOG_REG_80 |= 0x10;
            ANALOG_REG_3C &= ~0xe0;
            return;
        }
    }
    ANALOG_REG_80 &= ~0x90;
    ANALOG_REG_6C |= 0xe0;
    ANALOG_REG_3C |= 0xe0;
}
