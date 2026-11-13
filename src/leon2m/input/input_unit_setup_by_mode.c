/* input_unit_setup_by_mode  (FUN_a0122e80)
 *
 * Print 'Vx1RxLink_Initial' and write one of two start-up register lists of a receiver unit.
 * Note: The print is a fixed text, not the mode. Nothing calls it.
 * Name basis: derived - prints 'Vx1RxLink_Initial'; register list chosen by the mode argument, written through
 *   the unit register write; no caller
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0122e80 @ 0xa0122e80-0xa0123184 (193 words), flags -mcpu=v8 -O3 -g.
 * Source form: high_bits is a full word masked at the use ('shifted = (high_bits & 0xff) << 4' in its own
 * variable keeps the fw 'and' and the 'or low_bits, shifted' operand order); the 0xcf01d940 address is the
 * register-window form with a local 'window_base = 0x7600' (fw computes sethi 0x7400|0x200, +0x50, sll 2,
 * | 0xcf000000 at run time; a literal 0xcf01d940 shares 0xcf01d858's %hi). input_unit_write8 takes
 * (u8, u8, u8) and re-masks all three arguments. volatile only on the 0xcf... hardware registers.
 */
extern int dbg_printf(const char *fmt, ...);
extern void input_unit_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_unit_update_bits(unsigned char, unsigned int, unsigned int, unsigned int);
extern void gpio_set_pin_function(unsigned char, unsigned int, unsigned int);
extern const unsigned char input_unit_mode_regs40[16];

#define R(a) (*(volatile unsigned int *)(a))

/*
 * Write the start-up register list of one receiver unit, in one of two variants, and print "Vx1RxLink_Initial".
 *
 *   unit       receiver unit number
 *   low_bits   low part of the value written to unit register 0x10
 *   high_bits  its low byte is shifted left by 4 and or-ed into the same register 0x10 value
 *   mode       non-zero: the first register list; 0: the second list, which also loads the 16 registers
 *              0x40..0x4f from the ROM table input_unit_mode_regs40
 *
 * No result, and no routine calls it. Order: print, clear bits 0xea of unit register 0x0e, set the
 * function field 0xc of the four pins 0x10, 0x20, 0x40 and 0x80 of pin group 0xb, clear bits 2 and 3 of
 * 0xcf03c548, clear 0xcf011814, the mode's register list, clear bit 2 of unit register 0x30, and last a
 * sequence on 0xcf03d024: the old value is kept, 0xc is written, 0xcf01d858 gets 0xff, 0xcf03d024 gets 0xf,
 * 0xcf01d940 gets 2, and the kept low byte is written back.
 * The two lists differ in registers 0xcc (0 or 2), 0x39, 0x19, 0x60, 0x64; only the first list writes
 * register 0x60 three times.
 */
void input_unit_setup_by_mode(unsigned char unit, unsigned int low_bits, unsigned int high_bits, unsigned char mode)
{
    unsigned char i;
    unsigned int saved_d024;
    unsigned int shifted;
    unsigned int window_base;

    dbg_printf("Vx1RxLink_Initial\r\n");
    input_unit_update_bits(unit, 0xe, 0xea, 0);
    gpio_set_pin_function(0xb, 0x10, 0xc);
    gpio_set_pin_function(0xb, 0x20, 0xc);
    gpio_set_pin_function(0xb, 0x40, 0xc);
    gpio_set_pin_function(0xb, 0x80, 0xc);
    R(0xcf03c548) &= 0xf3;
    R(0xcf011814) = 0;
    if (mode != 0) {
        input_unit_write8(unit, 0xcc, 0);
        shifted = (high_bits & 0xff) << 4;
        input_unit_write8(unit, 0x10, low_bits | shifted);
        input_unit_write8(unit, 0x11, 0x1e);
        input_unit_write8(unit, 0x12, 1);
        input_unit_write8(unit, 0x30, 0x47);
        input_unit_write8(unit, 0x33, 0xf6);
        input_unit_write8(unit, 0x60, 0x1c);
        input_unit_write8(unit, 0x19, 0x10);
        input_unit_write8(unit, 0x60, 1);
        input_unit_write8(unit, 0x60, 0x1c);
        input_unit_write8(unit, 0x64, 0x22);
        input_unit_write8(unit, 0x39, 0);
        input_unit_write8(unit, 0x65, 0);
        input_unit_write8(unit, 0x80, 0xff);
    } else {
        input_unit_write8(unit, 0xcc, 2);
        shifted = (high_bits & 0xff) << 4;
        input_unit_write8(unit, 0x10, low_bits | shifted);
        input_unit_write8(unit, 0x11, 0x1e);
        input_unit_write8(unit, 0x12, 1);
        input_unit_write8(unit, 0x30, 0x47);
        input_unit_write8(unit, 0x33, 0xf6);
        input_unit_write8(unit, 0x39, 0x10);
        input_unit_write8(unit, 0x60, 0x1c);
        input_unit_write8(unit, 0x19, 0x12);
        input_unit_write8(unit, 0x60, 0x5e);
        input_unit_write8(unit, 0x64, 0x21);
        input_unit_write8(unit, 0x65, 0);
        input_unit_write8(unit, 0x80, 0xff);
        for (i = 0; i <= 0xf; i++)
            input_unit_write8(unit, i + 0x40, input_unit_mode_regs40[i]);
    }
    input_unit_update_bits(unit, 0x30, 4, 0);
    saved_d024 = R(0xcf03d024);
    R(0xcf03d024) = 0xc;
    R(0xcf01d858) = 0xff;
    R(0xcf03d024) = 0xf;
    window_base = 0x7600;
    R(0xcf000000 | ((window_base + 0x50) << 2)) = 2;
    R(0xcf03d024) = saved_d024 & 0xff;
}
