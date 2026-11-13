/* panel_pwm_set_clock_fields  (FUN_a011d670)
 *
 * Write two 2-bit clock fields of a PWM channel.
 * Name basis: descriptive - (a << 2) | b into the low bits of the channel's register; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011d670 @ 0xa011d670-0xa011d740 (52 words, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: every arm of the if/else-if chain holds its own copy of the two read-modify-writes with its own
 * register address; GCC merges the identical tails into one block and computes each address before its test,
 * so each arm keeps its own sethi of 0xcf016000 as in the firmware. One shared pointer variable lets the
 * compiler share that high part.
 */
#define REG(address) ((volatile unsigned int *)(address))

/*
 * Write two 2-bit values into the low bits of the register of PWM channel `channel`, keeping bits 4..7 of the
 * register and clearing the rest of the low byte first. The new low bits are (first_field << 2) | second_field;
 * each field is limited to 3.
 *
 * Registers: channels 1..6 -> 0xCF016134, 0xCF01614C, 0xCF016164, 0xCF01617C, 0xCF016194, 0xCF0161AC (0x18 apart);
 * channels 16..19 -> the one register 0xCF01640C; any other channel writes nothing.
 * No routine calls it directly.
 */
void panel_pwm_set_clock_fields(unsigned char channel, unsigned char first_field, unsigned char second_field)
{
    if (first_field > 3)
        first_field = 3;
    if (second_field > 3)
        second_field = 3;
    if (channel == 1) {
        *REG(0xcf016134) &= 0xf0;
        *REG(0xcf016134) |= (unsigned char)((first_field << 2) | second_field);
    } else if (channel == 2) {
        *REG(0xcf01614c) &= 0xf0;
        *REG(0xcf01614c) |= (unsigned char)((first_field << 2) | second_field);
    } else if (channel == 3) {
        *REG(0xcf016164) &= 0xf0;
        *REG(0xcf016164) |= (unsigned char)((first_field << 2) | second_field);
    } else if (channel == 4) {
        *REG(0xcf01617c) &= 0xf0;
        *REG(0xcf01617c) |= (unsigned char)((first_field << 2) | second_field);
    } else if (channel == 5) {
        *REG(0xcf016194) &= 0xf0;
        *REG(0xcf016194) |= (unsigned char)((first_field << 2) | second_field);
    } else if (channel == 6) {
        *REG(0xcf0161ac) &= 0xf0;
        *REG(0xcf0161ac) |= (unsigned char)((first_field << 2) | second_field);
    } else if ((unsigned char)(channel - 16) < 4) {
        *REG(0xcf01640c) &= 0xf0;
        *REG(0xcf01640c) |= (unsigned char)((first_field << 2) | second_field);
    }
}
