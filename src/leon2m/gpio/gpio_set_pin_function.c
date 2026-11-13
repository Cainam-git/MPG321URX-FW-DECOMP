/* gpio_set_pin_function  (FUN_a00fe880)
 *
 * Set the function of one pin of a pin group.
 * Name basis: proven - 2-bit function field per pin, selected by group and pin mask; large switch
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fe880 @ 0xa00fe880-0xa010031c (1703 words), flags -mcpu=v8 -O3 -g. Leaf function.
 * The switch on pin_group compiles to a jump table (at 0x9d510); pin_mask and function_code are tested as
 * if/else chains in the order written.
 * Source form: case 13 is the last case of the switch (the case order is part of the exact build);
 * function_code is an unsigned int, compared without masking. Group 4 writes the field and then clears it
 * (two separate statements, kept as the firmware has them).
 */

/*
 * Pin function registers. Each register holds four 2-bit fields, one per pin:
 *   pin mask 0x01 / 0x10 -> bits 6..7     pin mask 0x02 / 0x20 -> bits 4..5
 *   pin mask 0x04 / 0x40 -> bits 2..3     pin mask 0x08 / 0x80 -> bits 0..1
 * A group with eight pins has two registers: _LO for pin masks 0x01..0x08, _HI for 0x10..0x80.
 * (Group 2 is the exception: its pin masks 0x04 / 0x08 use bits 6..7 / 4..5 of its register.)
 */
#define PIN_FUNC_G2      (*(volatile unsigned int *)0xcf011540)
#define PIN_FUNC_G3      (*(volatile unsigned int *)0xcf0114cc)
#define PIN_FUNC_G4      (*(volatile unsigned int *)0xcf0114d0)
#define PIN_FUNC_G5      (*(volatile unsigned int *)0xcf0114d4)
#define PIN_FUNC_G6      (*(volatile unsigned int *)0xcf0114d8)
#define PIN_FUNC_G8_LO   (*(volatile unsigned int *)0xcf0114dc)
#define PIN_FUNC_G8_HI   (*(volatile unsigned int *)0xcf0114e0)
#define PIN_FUNC_G9_LO   (*(volatile unsigned int *)0xcf0114e4)
#define PIN_FUNC_G9_HI   (*(volatile unsigned int *)0xcf0114e8)
#define PIN_FUNC_G10_LO  (*(volatile unsigned int *)0xcf011550)
#define PIN_FUNC_G10_HI  (*(volatile unsigned int *)0xcf011554)
#define PIN_FUNC_G11_LO  (*(volatile unsigned int *)0xcf01154c)
#define PIN_FUNC_G11_HI  (*(volatile unsigned int *)0xcf011518)
#define PIN_FUNC_G12_LO  (*(volatile unsigned int *)0xcf01151c)
#define PIN_FUNC_G12_HI  (*(volatile unsigned int *)0xcf011520)
#define PIN_FUNC_G13_LO  (*(volatile unsigned int *)0xcf0116ac)
#define PIN_FUNC_G13_HI  (*(volatile unsigned int *)0xcf0116b0)
#define PIN_FUNC_G14_LO  (*(volatile unsigned int *)0xcf011524)
#define PIN_FUNC_G14_HI  (*(volatile unsigned int *)0xcf011528)
#define PIN_FUNC_G15_LO  (*(volatile unsigned int *)0xcf01152c)
#define PIN_FUNC_G15_HI  (*(volatile unsigned int *)0xcf011530)
#define PIN_FUNC_G17_LO  (*(volatile unsigned int *)0xcf011538)
#define PIN_FUNC_G17_HI  (*(volatile unsigned int *)0xcf01153c)

/*
 * Give one pin its function, or take it away.
 *
 *   pin_group      2, 3, 4, 5, 6, 8..15 or 17; any other group (0, 1, 7, 16, above 17) writes nothing.
 *   pin_mask       one bit, 0x01 .. 0x80: the pin inside the group. Each group knows only some pins; any
 *                  other mask writes nothing.
 *   function_code  the function the caller wants. The routine compares it with the codes that pin knows and
 *                  writes the 2-bit field value (1, 2 or 3) listed for that code; any other code, 0 included,
 *                  clears the field to 0.
 *
 * The routine is one switch over the pin group; inside each group an if/else chain over the pin mask picks
 * the field, and an if/else chain over the function code picks the value. The comment on each case lists
 * "code -> field value" for that group.
 *
 * The codes the callers pass:
 *    1  hdmi_cec_init, one pin of group 3 (masks 0x01..0x08)
 *    5  ConfigScalerPWM, its pin numbers 0..15 (groups 5, 10, 11, 13, 15)
 *    8  gpio_select_pwm_group_pins, all pins of groups 9 and 10
 *    9  input_set_port_pin_function, group 6 masks 0x01 / 0x02
 *   10  ConfigScalerPWM, its pin numbers 16..27 (groups 9, 11); panel_blurfree_set_pin_functions passes it with
 *       group 0xFF, which writes nothing
 *   11  audio_select_output_pins (groups 17 and 10), audio_init_config (group 12)
 *   12  input_unit_setup_by_mode, group 11 masks 0x10..0x80, after it prints "Vx1RxLink_Initial"
 *   14  audio_init_config, group 14 masks 0x04 / 0x08
 *   15  gpio_api_set_pin_function, groups 13 and 15 (0 when switching off)
 *    0  input_set_port_pin_function, panel_blurfree_set_pin_functions and gpio_api_set_pin_function to switch
 *       a pin back.
 * The codes 2, 3, 4, 6, 7, 13, 16 and 18 are known to some pins but no caller passes them.
 */
void gpio_set_pin_function(unsigned char pin_group, unsigned char pin_mask, unsigned int function_code)
{
    switch (pin_group) {
    case 2:
        /* Group 2: 16 -> 1. Only pin masks 0x04 and 0x08. */
        if (pin_mask == 4) {
            if (function_code == 16)
                PIN_FUNC_G2 = (PIN_FUNC_G2 & ~0xc0) | 0x40;
            else
                PIN_FUNC_G2 &= ~0xc0;
        }
        else if (pin_mask == 8) {
            if (function_code == 16)
                PIN_FUNC_G2 = (PIN_FUNC_G2 & ~0x30) | 0x10;
            else
                PIN_FUNC_G2 &= ~0x30;
        }
        break;
    case 3:
        /* Group 3: 1 -> 1. Pin masks 0x01..0x08. */
        if (pin_mask == 1) {
            if (function_code == 1)
                PIN_FUNC_G3 = (PIN_FUNC_G3 & ~0xc0) | 0x40;
            else
                PIN_FUNC_G3 &= ~0xc0;
        }
        else if (pin_mask == 2) {
            if (function_code == 1)
                PIN_FUNC_G3 = (PIN_FUNC_G3 & ~0x30) | 0x10;
            else
                PIN_FUNC_G3 &= ~0x30;
        }
        else if (pin_mask == 4) {
            if (function_code == 1)
                PIN_FUNC_G3 = (PIN_FUNC_G3 & ~0xc) | 4;
            else
                PIN_FUNC_G3 &= ~0xc;
        }
        else if (pin_mask == 8) {
            if (function_code == 1)
                PIN_FUNC_G3 = (PIN_FUNC_G3 & ~3) | 1;
            else
                PIN_FUNC_G3 &= ~3;
        }
        break;
    case 4:
        /* Group 4: only pin mask 0x80. Code 2 writes 1 and code 3 writes 3, but the field is cleared right
           after in every case, so it always ends at 0. */
        if (pin_mask == 0x80) {
            if (function_code == 2)
                PIN_FUNC_G4 = (PIN_FUNC_G4 & ~3) | 1;
            else if (function_code == 3)
                PIN_FUNC_G4 |= 3;
            PIN_FUNC_G4 &= ~3;
        }
        break;
    case 5:
        /* Group 5: pin mask 0x02: 4 -> 1; pin masks 0x04 / 0x08: 5 -> 1. */
        if (pin_mask == 2) {
            if (function_code == 4)
                PIN_FUNC_G5 = (PIN_FUNC_G5 & ~0x30) | 0x10;
            else
                PIN_FUNC_G5 &= ~0x30;
        }
        else if (pin_mask == 4) {
            if (function_code == 5)
                PIN_FUNC_G5 = (PIN_FUNC_G5 & ~0xc) | 4;
            else
                PIN_FUNC_G5 &= ~0xc;
        }
        else if (pin_mask == 8) {
            if (function_code == 5)
                PIN_FUNC_G5 = (PIN_FUNC_G5 & ~3) | 1;
            else
                PIN_FUNC_G5 &= ~3;
        }
        break;
    case 6:
        /* Group 6: 9 -> 1. Pin masks 0x01 and 0x02. */
        if (pin_mask == 1) {
            if (function_code == 9)
                PIN_FUNC_G6 = (PIN_FUNC_G6 & ~0xc0) | 0x40;
            else
                PIN_FUNC_G6 &= ~0xc0;
        }
        else if (pin_mask == 2) {
            if (function_code == 9)
                PIN_FUNC_G6 = (PIN_FUNC_G6 & ~0x30) | 0x10;
            else
                PIN_FUNC_G6 &= ~0x30;
        }
        break;
    case 8:
        /* Group 8: 6 -> 1. All eight pins. */
        if (pin_mask == 1) {
            if (function_code == 6)
                PIN_FUNC_G8_LO = (PIN_FUNC_G8_LO & ~0xc0) | 0x40;
            else
                PIN_FUNC_G8_LO &= ~0xc0;
        }
        else if (pin_mask == 2) {
            if (function_code == 6)
                PIN_FUNC_G8_LO = (PIN_FUNC_G8_LO & ~0x30) | 0x10;
            else
                PIN_FUNC_G8_LO &= ~0x30;
        }
        else if (pin_mask == 4) {
            if (function_code == 6)
                PIN_FUNC_G8_LO = (PIN_FUNC_G8_LO & ~0xc) | 4;
            else
                PIN_FUNC_G8_LO &= ~0xc;
        }
        else if (pin_mask == 8) {
            if (function_code == 6)
                PIN_FUNC_G8_LO = (PIN_FUNC_G8_LO & ~3) | 1;
            else
                PIN_FUNC_G8_LO &= ~3;
        }
        else if (pin_mask == 0x10) {
            if (function_code == 6)
                PIN_FUNC_G8_HI = (PIN_FUNC_G8_HI & ~0xc0) | 0x40;
            else
                PIN_FUNC_G8_HI &= ~0xc0;
        }
        else if (pin_mask == 0x20) {
            if (function_code == 6)
                PIN_FUNC_G8_HI = (PIN_FUNC_G8_HI & ~0x30) | 0x10;
            else
                PIN_FUNC_G8_HI &= ~0x30;
        }
        else if (pin_mask == 0x40) {
            if (function_code == 6)
                PIN_FUNC_G8_HI = (PIN_FUNC_G8_HI & ~0xc) | 4;
            else
                PIN_FUNC_G8_HI &= ~0xc;
        }
        else if (pin_mask == 0x80) {
            if (function_code == 6)
                PIN_FUNC_G8_HI = (PIN_FUNC_G8_HI & ~3) | 1;
            else
                PIN_FUNC_G8_HI &= ~3;
        }
        break;
    case 9:
        /* Group 9: 10 -> 1, 8 -> 3 on all eight pins; 7 -> 2 on pin masks 0x01 / 0x02 only. */
        if (pin_mask == 1) {
            if (function_code == 10)
                PIN_FUNC_G9_LO = (PIN_FUNC_G9_LO & ~0xc0) | 0x40;
            else if (function_code == 7)
                PIN_FUNC_G9_LO = (PIN_FUNC_G9_LO & ~0xc0) | 0x80;
            else if (function_code == 8)
                PIN_FUNC_G9_LO |= 0xc0;
            else
                PIN_FUNC_G9_LO &= ~0xc0;
        }
        else if (pin_mask == 2) {
            if (function_code == 10)
                PIN_FUNC_G9_LO = (PIN_FUNC_G9_LO & ~0x30) | 0x10;
            else if (function_code == 7)
                PIN_FUNC_G9_LO = (PIN_FUNC_G9_LO & ~0x30) | 0x20;
            else if (function_code == 8)
                PIN_FUNC_G9_LO |= 0x30;
            else
                PIN_FUNC_G9_LO &= ~0x30;
        }
        else if (pin_mask == 4) {
            if (function_code == 10)
                PIN_FUNC_G9_LO = (PIN_FUNC_G9_LO & ~0xc) | 4;
            else if (function_code == 8)
                PIN_FUNC_G9_LO |= 0xc;
            else
                PIN_FUNC_G9_LO &= ~0xc;
        }
        else if (pin_mask == 8) {
            if (function_code == 10)
                PIN_FUNC_G9_LO = (PIN_FUNC_G9_LO & ~3) | 1;
            else if (function_code == 8)
                PIN_FUNC_G9_LO |= 3;
            else
                PIN_FUNC_G9_LO &= ~3;
        }
        else if (pin_mask == 0x10) {
            if (function_code == 10)
                PIN_FUNC_G9_HI = (PIN_FUNC_G9_HI & ~0xc0) | 0x40;
            else if (function_code == 8)
                PIN_FUNC_G9_HI |= 0xc0;
            else
                PIN_FUNC_G9_HI &= ~0xc0;
        }
        else if (pin_mask == 0x20) {
            if (function_code == 10)
                PIN_FUNC_G9_HI = (PIN_FUNC_G9_HI & ~0x30) | 0x10;
            else if (function_code == 8)
                PIN_FUNC_G9_HI |= 0x30;
            else
                PIN_FUNC_G9_HI &= ~0x30;
        }
        else if (pin_mask == 0x40) {
            if (function_code == 10)
                PIN_FUNC_G9_HI = (PIN_FUNC_G9_HI & ~0xc) | 4;
            else if (function_code == 8)
                PIN_FUNC_G9_HI |= 0xc;
            else
                PIN_FUNC_G9_HI &= ~0xc;
        }
        else if (pin_mask == 0x80) {
            if (function_code == 10)
                PIN_FUNC_G9_HI = (PIN_FUNC_G9_HI & ~3) | 1;
            else if (function_code == 8)
                PIN_FUNC_G9_HI |= 3;
            else
                PIN_FUNC_G9_HI &= ~3;
        }
        break;
    case 10:
        /* Group 10: 8 -> 3 on all eight pins; 5 -> 1 on pin masks 0x01 / 0x02; 11 -> 1 on pin masks
           0x08..0x80. */
        if (pin_mask == 1) {
            if (function_code == 5)
                PIN_FUNC_G10_LO = (PIN_FUNC_G10_LO & ~0xc0) | 0x40;
            else if (function_code == 8)
                PIN_FUNC_G10_LO |= 0xc0;
            else
                PIN_FUNC_G10_LO &= ~0xc0;
        }
        else if (pin_mask == 2) {
            if (function_code == 5)
                PIN_FUNC_G10_LO = (PIN_FUNC_G10_LO & ~0x30) | 0x10;
            else if (function_code == 8)
                PIN_FUNC_G10_LO |= 0x30;
            else
                PIN_FUNC_G10_LO &= ~0x30;
        }
        else if (pin_mask == 4) {
            if (function_code == 8)
                PIN_FUNC_G10_LO |= 0xc;
            else
                PIN_FUNC_G10_LO &= ~0xc;
        }
        else if (pin_mask == 8) {
            if (function_code == 11)
                PIN_FUNC_G10_LO = (PIN_FUNC_G10_LO & ~3) | 1;
            else if (function_code == 8)
                PIN_FUNC_G10_LO |= 3;
            else
                PIN_FUNC_G10_LO &= ~3;
        }
        else if (pin_mask == 0x10) {
            if (function_code == 11)
                PIN_FUNC_G10_HI = (PIN_FUNC_G10_HI & ~0xc0) | 0x40;
            else if (function_code == 8)
                PIN_FUNC_G10_HI |= 0xc0;
            else
                PIN_FUNC_G10_HI &= ~0xc0;
        }
        else if (pin_mask == 0x20) {
            if (function_code == 11)
                PIN_FUNC_G10_HI = (PIN_FUNC_G10_HI & ~0x30) | 0x10;
            else if (function_code == 8)
                PIN_FUNC_G10_HI |= 0x30;
            else
                PIN_FUNC_G10_HI &= ~0x30;
        }
        else if (pin_mask == 0x40) {
            if (function_code == 11)
                PIN_FUNC_G10_HI = (PIN_FUNC_G10_HI & ~0xc) | 4;
            else if (function_code == 8)
                PIN_FUNC_G10_HI |= 0xc;
            else
                PIN_FUNC_G10_HI &= ~0xc;
        }
        else if (pin_mask == 0x80) {
            if (function_code == 11)
                PIN_FUNC_G10_HI = (PIN_FUNC_G10_HI & ~3) | 1;
            else if (function_code == 8)
                PIN_FUNC_G10_HI |= 3;
            else
                PIN_FUNC_G10_HI &= ~3;
        }
        break;
    case 11:
        /* Group 11, pin masks 0x01..0x08: 10 -> 1, 5 -> 2, 6 -> 3.
           Pin masks 0x10..0x80: 12 -> 1, 6 -> 3; 13 -> 2 on pin masks 0x10 / 0x20 only. */
        if (pin_mask == 1) {
            if (function_code == 10)
                PIN_FUNC_G11_LO = (PIN_FUNC_G11_LO & ~0xc0) | 0x40;
            else if (function_code == 5)
                PIN_FUNC_G11_LO = (PIN_FUNC_G11_LO & ~0xc0) | 0x80;
            else if (function_code == 6)
                PIN_FUNC_G11_LO |= 0xc0;
            else
                PIN_FUNC_G11_LO &= ~0xc0;
        }
        else if (pin_mask == 2) {
            if (function_code == 10)
                PIN_FUNC_G11_LO = (PIN_FUNC_G11_LO & ~0x30) | 0x10;
            else if (function_code == 5)
                PIN_FUNC_G11_LO = (PIN_FUNC_G11_LO & ~0x30) | 0x20;
            else if (function_code == 6)
                PIN_FUNC_G11_LO |= 0x30;
            else
                PIN_FUNC_G11_LO &= ~0x30;
        }
        else if (pin_mask == 4) {
            if (function_code == 10)
                PIN_FUNC_G11_LO = (PIN_FUNC_G11_LO & ~0xc) | 4;
            else if (function_code == 5)
                PIN_FUNC_G11_LO = (PIN_FUNC_G11_LO & ~0xc) | 0x8;
            else if (function_code == 6)
                PIN_FUNC_G11_LO |= 0xc;
            else
                PIN_FUNC_G11_LO &= ~0xc;
        }
        else if (pin_mask == 8) {
            if (function_code == 10)
                PIN_FUNC_G11_LO = (PIN_FUNC_G11_LO & ~3) | 1;
            else if (function_code == 5)
                PIN_FUNC_G11_LO = (PIN_FUNC_G11_LO & ~3) | 2;
            else if (function_code == 6)
                PIN_FUNC_G11_LO |= 3;
            else
                PIN_FUNC_G11_LO &= ~3;
        }
        else if (pin_mask == 0x10) {
            if (function_code == 12)
                PIN_FUNC_G11_HI = (PIN_FUNC_G11_HI & ~0xc0) | 0x40;
            else if (function_code == 13)
                PIN_FUNC_G11_HI = (PIN_FUNC_G11_HI & ~0xc0) | 0x80;
            else if (function_code == 6)
                PIN_FUNC_G11_HI |= 0xc0;
            else
                PIN_FUNC_G11_HI &= ~0xc0;
        }
        else if (pin_mask == 0x20) {
            if (function_code == 12)
                PIN_FUNC_G11_HI = (PIN_FUNC_G11_HI & ~0x30) | 0x10;
            else if (function_code == 13)
                PIN_FUNC_G11_HI = (PIN_FUNC_G11_HI & ~0x30) | 0x20;
            else if (function_code == 6)
                PIN_FUNC_G11_HI |= 0x30;
            else
                PIN_FUNC_G11_HI &= ~0x30;
        }
        else if (pin_mask == 0x40) {
            if (function_code == 12)
                PIN_FUNC_G11_HI = (PIN_FUNC_G11_HI & ~0xc) | 4;
            else if (function_code == 6)
                PIN_FUNC_G11_HI |= 0xc;
            else
                PIN_FUNC_G11_HI &= ~0xc;
        }
        else if (pin_mask == 0x80) {
            if (function_code == 12)
                PIN_FUNC_G11_HI = (PIN_FUNC_G11_HI & ~3) | 1;
            else if (function_code == 6)
                PIN_FUNC_G11_HI |= 3;
            else
                PIN_FUNC_G11_HI &= ~3;
        }
        break;
    case 12:
        /* Group 12: pin masks 0x01..0x08: 11 -> 1, 6 -> 3; pin masks 0x10 / 0x20: 6 -> 3. */
        if (pin_mask == 1) {
            if (function_code == 11)
                PIN_FUNC_G12_LO = (PIN_FUNC_G12_LO & ~0xc0) | 0x40;
            else if (function_code == 6)
                PIN_FUNC_G12_LO |= 0xc0;
            else
                PIN_FUNC_G12_LO &= ~0xc0;
        }
        else if (pin_mask == 2) {
            if (function_code == 11)
                PIN_FUNC_G12_LO = (PIN_FUNC_G12_LO & ~0x30) | 0x10;
            else if (function_code == 6)
                PIN_FUNC_G12_LO |= 0x30;
            else
                PIN_FUNC_G12_LO &= ~0x30;
        }
        else if (pin_mask == 4) {
            if (function_code == 11)
                PIN_FUNC_G12_LO = (PIN_FUNC_G12_LO & ~0xc) | 4;
            else if (function_code == 6)
                PIN_FUNC_G12_LO |= 0xc;
            else
                PIN_FUNC_G12_LO &= ~0xc;
        }
        else if (pin_mask == 8) {
            if (function_code == 11)
                PIN_FUNC_G12_LO = (PIN_FUNC_G12_LO & ~3) | 1;
            else if (function_code == 6)
                PIN_FUNC_G12_LO |= 3;
            else
                PIN_FUNC_G12_LO &= ~3;
        }
        else if (pin_mask == 0x10) {
            if (function_code == 6)
                PIN_FUNC_G12_HI |= 0xc0;
            else
                PIN_FUNC_G12_HI &= ~0xc0;
        }
        else if (pin_mask == 0x20) {
            if (function_code == 6)
                PIN_FUNC_G12_HI |= 0x30;
            else
                PIN_FUNC_G12_HI &= ~0x30;
        }
        break;
    case 14:
        /* Group 14: 6 -> 3 on all eight pins; 14 -> 1 on pin masks 0x01..0x08. */
        if (pin_mask == 1) {
            if (function_code == 14)
                PIN_FUNC_G14_LO = (PIN_FUNC_G14_LO & ~0xc0) | 0x40;
            else if (function_code == 6)
                PIN_FUNC_G14_LO |= 0xc0;
            else
                PIN_FUNC_G14_LO &= ~0xc0;
        }
        else if (pin_mask == 2) {
            if (function_code == 14)
                PIN_FUNC_G14_LO = (PIN_FUNC_G14_LO & ~0x30) | 0x10;
            else if (function_code == 6)
                PIN_FUNC_G14_LO |= 0x30;
            else
                PIN_FUNC_G14_LO &= ~0x30;
        }
        else if (pin_mask == 4) {
            if (function_code == 14)
                PIN_FUNC_G14_LO = (PIN_FUNC_G14_LO & ~0xc) | 4;
            else if (function_code == 6)
                PIN_FUNC_G14_LO |= 0xc;
            else
                PIN_FUNC_G14_LO &= ~0xc;
        }
        else if (pin_mask == 8) {
            if (function_code == 14)
                PIN_FUNC_G14_LO = (PIN_FUNC_G14_LO & ~3) | 1;
            else if (function_code == 6)
                PIN_FUNC_G14_LO |= 3;
            else
                PIN_FUNC_G14_LO &= ~3;
        }
        else if (pin_mask == 0x10) {
            if (function_code == 6)
                PIN_FUNC_G14_HI |= 0xc0;
            else
                PIN_FUNC_G14_HI &= ~0xc0;
        }
        else if (pin_mask == 0x20) {
            if (function_code == 6)
                PIN_FUNC_G14_HI |= 0x30;
            else
                PIN_FUNC_G14_HI &= ~0x30;
        }
        else if (pin_mask == 0x40) {
            if (function_code == 6)
                PIN_FUNC_G14_HI |= 0xc;
            else
                PIN_FUNC_G14_HI &= ~0xc;
        }
        else if (pin_mask == 0x80) {
            if (function_code == 6)
                PIN_FUNC_G14_HI |= 3;
            else
                PIN_FUNC_G14_HI &= ~3;
        }
        break;
    case 15:
        /* Group 15: 5 -> 1 on pin masks 0x04..0x80; 15 -> 2 on pin masks 0x04 / 0x08 only. */
        if (pin_mask == 4) {
            if (function_code == 5)
                PIN_FUNC_G15_LO = (PIN_FUNC_G15_LO & ~0xc) | 4;
            else if (function_code == 15)
                PIN_FUNC_G15_LO = (PIN_FUNC_G15_LO & ~0xc) | 0x8;
            else
                PIN_FUNC_G15_LO &= ~0xc;
        }
        else if (pin_mask == 8) {
            if (function_code == 5)
                PIN_FUNC_G15_LO = (PIN_FUNC_G15_LO & ~3) | 1;
            else if (function_code == 15)
                PIN_FUNC_G15_LO = (PIN_FUNC_G15_LO & ~3) | 2;
            else
                PIN_FUNC_G15_LO &= ~3;
        }
        else if (pin_mask == 0x10) {
            if (function_code == 5)
                PIN_FUNC_G15_HI = (PIN_FUNC_G15_HI & ~0xc0) | 0x40;
            else
                PIN_FUNC_G15_HI &= ~0xc0;
        }
        else if (pin_mask == 0x20) {
            if (function_code == 5)
                PIN_FUNC_G15_HI = (PIN_FUNC_G15_HI & ~0x30) | 0x10;
            else
                PIN_FUNC_G15_HI &= ~0x30;
        }
        else if (pin_mask == 0x40) {
            if (function_code == 5)
                PIN_FUNC_G15_HI = (PIN_FUNC_G15_HI & ~0xc) | 4;
            else
                PIN_FUNC_G15_HI &= ~0xc;
        }
        else if (pin_mask == 0x80) {
            if (function_code == 5)
                PIN_FUNC_G15_HI = (PIN_FUNC_G15_HI & ~3) | 1;
            else
                PIN_FUNC_G15_HI &= ~3;
        }
        break;
    case 17:
        /* Group 17: 11 -> 3. Pin masks 0x01..0x10. */
        if (pin_mask == 1) {
            if (function_code == 11)
                PIN_FUNC_G17_LO |= 0xc0;
            else
                PIN_FUNC_G17_LO &= ~0xc0;
        }
        else if (pin_mask == 2) {
            if (function_code == 11)
                PIN_FUNC_G17_LO |= 0x30;
            else
                PIN_FUNC_G17_LO &= ~0x30;
        }
        else if (pin_mask == 4) {
            if (function_code == 11)
                PIN_FUNC_G17_LO |= 0xc;
            else
                PIN_FUNC_G17_LO &= ~0xc;
        }
        else if (pin_mask == 8) {
            if (function_code == 11)
                PIN_FUNC_G17_LO |= 3;
            else
                PIN_FUNC_G17_LO &= ~3;
        }
        else if (pin_mask == 0x10) {
            if (function_code == 11)
                PIN_FUNC_G17_HI |= 0xc0;
            else
                PIN_FUNC_G17_HI &= ~0xc0;
        }
        break;
    case 13:
        /* Group 13: 18 -> 1 on pin masks 0x01..0x20. Pin masks 0x40 / 0x80: 5 -> 1, 15 -> 2, 6 -> 3. */
        if (pin_mask == 1) {
            if (function_code == 18)
                PIN_FUNC_G13_LO = (PIN_FUNC_G13_LO & ~0xc0) | 0x40;
            else
                PIN_FUNC_G13_LO &= ~0xc0;
        }
        else if (pin_mask == 2) {
            if (function_code == 18)
                PIN_FUNC_G13_LO = (PIN_FUNC_G13_LO & ~0x30) | 0x10;
            else
                PIN_FUNC_G13_LO &= ~0x30;
        }
        else if (pin_mask == 4) {
            if (function_code == 18)
                PIN_FUNC_G13_LO = (PIN_FUNC_G13_LO & ~0xc) | 4;
            else
                PIN_FUNC_G13_LO &= ~0xc;
        }
        else if (pin_mask == 8) {
            if (function_code == 18)
                PIN_FUNC_G13_LO = (PIN_FUNC_G13_LO & ~3) | 1;
            else
                PIN_FUNC_G13_LO &= ~3;
        }
        else if (pin_mask == 0x10) {
            if (function_code == 18)
                PIN_FUNC_G13_HI = (PIN_FUNC_G13_HI & ~0xc0) | 0x40;
            else
                PIN_FUNC_G13_HI &= ~0xc0;
        }
        else if (pin_mask == 0x20) {
            if (function_code == 18)
                PIN_FUNC_G13_HI = (PIN_FUNC_G13_HI & ~0x30) | 0x10;
            else
                PIN_FUNC_G13_HI &= ~0x30;
        }
        else if (pin_mask == 0x40) {
            if (function_code == 5)
                PIN_FUNC_G13_HI = (PIN_FUNC_G13_HI & ~0xc) | 4;
            else if (function_code == 15)
                PIN_FUNC_G13_HI = (PIN_FUNC_G13_HI & ~0xc) | 0x8;
            else if (function_code == 6)
                PIN_FUNC_G13_HI |= 0xc;
            else
                PIN_FUNC_G13_HI &= ~0xc;
        }
        else if (pin_mask == 0x80) {
            if (function_code == 5)
                PIN_FUNC_G13_HI = (PIN_FUNC_G13_HI & ~3) | 1;
            else if (function_code == 15)
                PIN_FUNC_G13_HI = (PIN_FUNC_G13_HI & ~3) | 2;
            else if (function_code == 6)
                PIN_FUNC_G13_HI |= 3;
            else
                PIN_FUNC_G13_HI &= ~3;
        }
        break;
    }
}
