/* panel_pwm_set_control_bit3  (FUN_a011e438)
 *
 * Write control bit 3 of one of the six main PWM channels.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * FUN_a011e438: the 0xf7 mask keeps bits 0-2 and 4-7 and clears everything above bit 7 of the register.
 */
#define REG(address) (*(volatile unsigned int *)(address))

/*
 * Write bit 3 of the register of PWM channel 1..6 with bit 0 of `value`, keeping bits 0..2 and 4..7 (the bits
 * above 7 are cleared). Registers: 0xCF016120, 0xCF016138, 0xCF016150, 0xCF016168, 0xCF016180, 0xCF016198
 * (0x18 apart). Any other channel writes nothing. Called from panel_level_gen_set_target.
 */
void panel_pwm_set_control_bit3(unsigned char channel, unsigned char value)
{
    value &= 1;
    switch (channel) {
    case 1:
        REG(0xcf016120) = (REG(0xcf016120) & 0xf7) | (value << 3);
        break;
    case 2:
        REG(0xcf016138) = (REG(0xcf016138) & 0xf7) | (value << 3);
        break;
    case 3:
        REG(0xcf016150) = (REG(0xcf016150) & 0xf7) | (value << 3);
        break;
    case 4:
        REG(0xcf016168) = (REG(0xcf016168) & 0xf7) | (value << 3);
        break;
    case 5:
        REG(0xcf016180) = (REG(0xcf016180) & 0xf7) | (value << 3);
        break;
    case 6:
        REG(0xcf016198) = (REG(0xcf016198) & 0xf7) | (value << 3);
        break;
    }
}
