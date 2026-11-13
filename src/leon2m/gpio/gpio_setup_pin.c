/* gpio_setup_pin  (FUN_a0107bac)
 *
 * Set up the function and direction of one pin.
 * Name basis: derived - pin-mux words 0xCF03C348 / 0xCF03C2B8; called by startup_init_input_ports (groups 0
 *   and 1, as outputs) and UartSetI2CEnable (group 0, as input)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0107bac, flags -mcpu=v8 -O3 -g.
 * Source form:
 *   - the mux word is chosen with one ?: expression, which makes it a leaf function like the firmware (an
 *     if-assignment needs a register window).
 *   - 0xCF03C294 is read once, modified under the group test and always written back (v = R; if (group == 0) v &=
 *     ...; R = v), and with output_enable == 0 the hardware register is cleared before the shadow is set.
 *   - the three mux read-modify-writes are written out twice, once per group register inside if (group == 0) {...}
 *     else {...}; gcc merges the identical tails (cross-jumping) and the else branch re-loads its address before
 *     jumping back, as the firmware does. A pointer chosen by ?: or if shares the %hi part.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* The pin number that means "no pin": the routine returns at once. */
#define GPIO_PIN_NONE 15

extern unsigned char gpio_pin_register_copy;

/*
 * Set up one pin of group 0 or group 1.
 *
 *   group          0 or 1: group 0 uses the mux word 0xCF03C348, every other value the mux word 0xCF03C2B8
 *   pin            pin number 0..7 (GPIO_PIN_NONE returns at once); the callers pass the bus id from the port table
 *   output_enable  1 makes the pin an output, 0 an input
 *   level          bit 0 of the mux word
 *
 * Steps: bits 2..4 of the mux word get pin, bit 1 output_enable and bit 0 level. Bit 'pin' of 0xCF03C294 is cleared
 * for group 0 and set for group 1. Bit 'pin' of 0xCF03C3F8 is set and the same bit of gpio_pin_register_copy
 * cleared for an output, the other way round for an input. For the pins 0..6 one more bit follows output_enable:
 * pins 0 and 1 use bits 6 and 7 of 0xCF03C348, pins 2..6 bits 3..7 of 0xCF03C34C. At the end gpio_pin_register_copy
 * is written to 0xCF03C1A8 and bit 7 of 0xCF03C354 is set.
 *
 * Called by startup_init_input_ports (groups 0 and 1, outputs) and by UartSetI2CEnable (group 0, input).
 */
void gpio_setup_pin(unsigned char group, unsigned char pin, unsigned char output_enable, unsigned char level)
{
    unsigned int v;
    if (pin == GPIO_PIN_NONE) return;
    if (group == 0) {
        R(0xcf03c348) = (R(0xcf03c348) & ~0x1c) | ((pin << 2) & 0x1c);
        R(0xcf03c348) = (R(0xcf03c348) & ~2) | ((output_enable << 1) & 2);
        R(0xcf03c348) = (R(0xcf03c348) & ~1) | (level & 1);
    } else {
        R(0xcf03c2b8) = (R(0xcf03c2b8) & ~0x1c) | ((pin << 2) & 0x1c);
        R(0xcf03c2b8) = (R(0xcf03c2b8) & ~2) | ((output_enable << 1) & 2);
        R(0xcf03c2b8) = (R(0xcf03c2b8) & ~1) | (level & 1);
    }
    v = R(0xcf03c294);
    if (group == 0) v &= ~(1 << pin);
    R(0xcf03c294) = v;
    v = R(0xcf03c294);
    if (group == 1) v |= group << pin;
    R(0xcf03c294) = v;
    if (output_enable != 0) {
        R(0xcf03c3f8) |= 1 << pin;
        gpio_pin_register_copy &= ~(1 << pin);
    } else {
        R(0xcf03c3f8) &= ~(1 << pin);
        gpio_pin_register_copy |= 1 << pin;
    }
    if (pin == 0) { if (output_enable) R(0xcf03c348) |= 0x40; else R(0xcf03c348) &= ~0x40; }
    else if (pin == 1) { if (output_enable) R(0xcf03c348) |= 0x80; else R(0xcf03c348) &= ~0x80; }
    else if (pin == 2) { if (output_enable) R(0xcf03c34c) |= 0x08; else R(0xcf03c34c) &= ~0x08; }
    else if (pin == 3) { if (output_enable) R(0xcf03c34c) |= 0x10; else R(0xcf03c34c) &= ~0x10; }
    else if (pin == 4) { if (output_enable) R(0xcf03c34c) |= 0x20; else R(0xcf03c34c) &= ~0x20; }
    else if (pin == 5) { if (output_enable) R(0xcf03c34c) |= 0x40; else R(0xcf03c34c) &= ~0x40; }
    else if (pin == 6) { if (output_enable) R(0xcf03c34c) |= 0x80; else R(0xcf03c34c) &= ~0x80; }
    R(0xcf03c1a8) = gpio_pin_register_copy;
    R(0xcf03c354) |= 0x80;
}
