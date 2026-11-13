/* panel_level_gen_set_frequency  (FUN_a010178c)
 *
 * Program the level generator's divider for a frequency.
 * Name basis: derived - 12 MHz / x, with x clamped to 60..11000
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010178c @ 0xa010178c-0xa0101858 (51 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * The float arithmetic goes through the soft-float library routines (__floatsisf, __divsf3, __extendsfdf2,
 * __subdf3, __fixunsdfsi); the constants 12000000.0f and 0.5 sit at 0x19a634 / 0x19a638.
 * Source form: mode << 6 is computed into a variable before the register read (scheduling).
 */

/* Registers of the level generator. */
#define LEVEL_GEN_REG_C0 (*(volatile unsigned int *)0xcf0160c0)    /* control register (reg_panel_level_gen_ctrl) */
#define LEVEL_GEN_REG_CC (*(volatile unsigned int *)0xcf0160cc)
#define LEVEL_GEN_REG_D0 (*(volatile unsigned int *)0xcf0160d0)
#define LEVEL_GEN_REG_D4 (*(volatile unsigned int *)0xcf0160d4)
#define LEVEL_GEN_REG_F4 (*(volatile unsigned int *)0xcf0160f4)

#define FREQUENCY_MIN    0x3c               /* 60 */
#define FREQUENCY_MAX    0x2af8             /* 11000 */
#define DIVIDER_BASE     12000000.0f        /* divided by the frequency */
#define CC_KEEP_BIT5     0x20               /* the bit panel_level_gen_set_cc_bit5 controls */

/*
 * Program the level generator's divider for a frequency.
 *
 *   frequency  limited to 60..11000; the divider is 12000000 / frequency - 0.5, cut to a whole number
 *   mode       written to bits 6 and up of register 0xCF0160CC
 *
 * Bit 2 of the control register is cleared first. Register 0xCF0160CC gets mode << 6 and the fixed bits 0x1A,
 * keeping its bit 5; register 0xCF0160D0 gets bits 10..17 of the divider, 0xCF0160D4 the value 0xFF, and bit 0 of
 * 0xCF0160F4 is set.
 *
 * Called once, by startup_init_level_generator, with frequency 960 and mode 3.
 */
void panel_level_gen_set_frequency(unsigned short frequency, unsigned int mode)
{
    unsigned int divider;
    unsigned int mode_bits;

    if (frequency > FREQUENCY_MAX)
        frequency = FREQUENCY_MAX;
    if (frequency < FREQUENCY_MIN)
        frequency = FREQUENCY_MIN;
    LEVEL_GEN_REG_C0 &= ~4;
    divider = (unsigned int)(DIVIDER_BASE / frequency - 0.5);
    mode_bits = mode << 6;
    LEVEL_GEN_REG_CC = (LEVEL_GEN_REG_CC & CC_KEEP_BIT5) | mode_bits | 0x1a;
    LEVEL_GEN_REG_D0 = (divider >> 10) & 0xff;
    LEVEL_GEN_REG_D4 = 0xff;
    LEVEL_GEN_REG_F4 |= 1;
}
