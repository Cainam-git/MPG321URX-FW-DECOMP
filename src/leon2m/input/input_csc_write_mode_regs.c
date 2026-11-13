/* input_csc_write_mode_regs  (FUN_a0100a40)
 *
 * Write block registers 0x19 and 0x1A for the current colour format.
 * Name basis: descriptive - 43-case switch on the format code
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0100a40 @ 0xa0100a40-0xa0100e6c (267 words), flags -mcpu=v8 -O3 -g.
 * Source form: the table of format code 41 is read through a local pointer (values).
 */
extern unsigned int input_csc_selector;
extern unsigned char input_csc_format_code, input_csc_last_format_code;
extern const unsigned short input_csc_mode_reg_values[15];
extern void input_capture_write8(unsigned char block, unsigned char reg, unsigned char value);
extern void input_capture_update_bits(unsigned char block, unsigned char reg, unsigned char mask, unsigned char set);
extern void input_capture_write16(unsigned char block, unsigned char reg, unsigned short value);

#define SELECTOR_FIXED    2     /* input_csc_selector: colour format code 1 (as in input_csc_setup) */

#define KEPT_FORMAT_BLOCK 4     /* the block whose format code is kept in input_csc_last_format_code */

/*
 * Write capture registers 0x19 and 0x1A of a block for the colour format chosen by input_csc_setup.
 *
 *   block  input block (input_csc_setup calls this for blocks 0..4)
 *
 * Phases:
 *   1. selector 2 (SELECTOR_FIXED): both registers 0.
 *      Selector 0 or 1: by the format code input_csc_format_code, as in the table below.
 *      Selector 3 or more: register 0x19 = 0x80 | (selector << 3), low 3 bits clear; register 0x1A = 0x19.
 *   2. for block 4 the format code is kept in input_csc_last_format_code (read by input_csc_map_format_code).
 *
 * By format code (register 0x1A: "bit 5 set/clear" and "bit 0 clear" change only those bits):
 *   0, 26                       0x19 = 0x88, 0x1A = 0x19, bit 5 clear
 *   1, 27                       0x19 = 0xF8, 0x1A = 0x19, bit 5 clear
 *   2, 6, 8, 12, 14, 18, 20, 24 0x19 = 0xB0, 0x1A = 0x19, bit 5 clear
 *   4, 10, 16, 22               0x19 = 0xB0, 0x1A = 0x39
 *   5, 11, 17, 23               0x19 = 0, 0x1A bit 0 clear and bit 5 set
 *   28, 32, 34, 38              0x19 = 0x88 (block 0) or 0xB0, 0x1A = 0x19, bit 5 clear
 *   29, 33, 35, 39              block 0: 0x19 = 0xF8, 0x1A = 0x19; others: 0x19 = 0, 0x1A bit 0 clear; bit 5 clear
 *   30, 36                      as 28, but bit 5 set
 *   31, 37                      as 29, but bit 5 set
 *   41                          the 15 halfwords of input_csc_mode_reg_values, see below; then 0x1A = 0x19, bit 5 clear
 *   42                          0x19 = 0, 0x1A = 0xFE, bit 5 clear
 *   any other                   0x19 = 0, 0x1A bit 0 clear and bit 5 clear
 */
void input_csc_write_mode_regs(unsigned char block)
{
    /* 1. The register values by selector and format code. */
    if (input_csc_selector == SELECTOR_FIXED) {
        input_capture_write8(block, 0x19, 0);
        input_capture_write8(block, 0x1a, 0);
    } else if (input_csc_selector <= 1) {
        switch (input_csc_format_code) {
        case 0: case 26:
            input_capture_write8(block, 0x19, 0x88);
            input_capture_write8(block, 0x1a, 0x19);
            input_capture_update_bits(block, 0x1a, 0x20, 0);
            break;
        case 1: case 27:
            input_capture_write8(block, 0x19, 0xf8);
            input_capture_write8(block, 0x1a, 0x19);
            input_capture_update_bits(block, 0x1a, 0x20, 0);
            break;
        case 2: case 6: case 8: case 12: case 14: case 18: case 20: case 24:
            input_capture_write8(block, 0x19, 0xb0);
            input_capture_write8(block, 0x1a, 0x19);
            input_capture_update_bits(block, 0x1a, 0x20, 0);
            break;
        case 4: case 10: case 16: case 22:
            input_capture_write8(block, 0x19, 0xb0);
            input_capture_write8(block, 0x1a, 0x39);
            break;
        case 5: case 11: case 17: case 23:
            input_capture_write8(block, 0x19, 0);
            input_capture_update_bits(block, 0x1a, 1, 0);
            input_capture_update_bits(block, 0x1a, 0x20, 1);
            break;
        case 28: case 32: case 34: case 38:
            if (block != 0)
                input_capture_write8(block, 0x19, 0xb0);
            else
                input_capture_write8(block, 0x19, 0x88);
            input_capture_write8(block, 0x1a, 0x19);
            input_capture_update_bits(block, 0x1a, 0x20, 0);
            break;
        case 29: case 33: case 35: case 39:
            if (block == 0) {
                input_capture_write8(block, 0x19, 0xf8);
                input_capture_write8(block, 0x1a, 0x19);
            } else {
                input_capture_write8(block, 0x19, 0);
                input_capture_update_bits(block, 0x1a, 1, 0);
            }
            input_capture_update_bits(block, 0x1a, 0x20, 0);
            break;
        case 30: case 36:
            if (block == 0)
                input_capture_write8(block, 0x19, 0x88);
            else
                input_capture_write8(block, 0x19, 0xb0);
            input_capture_write8(block, 0x1a, 0x19);
            input_capture_update_bits(block, 0x1a, 0x20, 1);
            break;
        case 31: case 37:
            if (block == 0) {
                input_capture_write8(block, 0x19, 0xf8);
                input_capture_write8(block, 0x1a, 0x19);
            } else {
                input_capture_write8(block, 0x19, 0);
                input_capture_update_bits(block, 0x1a, 1, 0);
            }
            input_capture_update_bits(block, 0x1a, 0x20, 1);
            break;
        case 41: {
            /* Both registers 0, then three groups of five halfwords to registers 0x1B, 0x1D, 0x1F, 0x21 and
               0x23, each group followed by two writes to register 0x1A (8 then 2, 0xA then 4, 0xC then 9). */
            const unsigned short *values = input_csc_mode_reg_values;
            input_capture_write8(block, 0x19, 0);
            input_capture_write8(block, 0x1a, 0);
            input_capture_write16(block, 0x1b, values[0]);
            input_capture_write16(block, 0x1d, values[1]);
            input_capture_write16(block, 0x1f, values[2]);
            input_capture_write16(block, 0x21, values[3]);
            input_capture_write16(block, 0x23, values[4]);
            input_capture_write8(block, 0x1a, 8);
            input_capture_write8(block, 0x1a, 2);
            input_capture_write16(block, 0x1b, values[5]);
            input_capture_write16(block, 0x1d, values[6]);
            input_capture_write16(block, 0x1f, values[7]);
            input_capture_write16(block, 0x21, values[8]);
            input_capture_write16(block, 0x23, values[9]);
            input_capture_write8(block, 0x1a, 0xa);
            input_capture_write8(block, 0x1a, 4);
            input_capture_write16(block, 0x1b, values[10]);
            input_capture_write16(block, 0x1d, values[11]);
            input_capture_write16(block, 0x1f, values[12]);
            input_capture_write16(block, 0x21, values[13]);
            input_capture_write16(block, 0x23, values[14]);
            input_capture_write8(block, 0x1a, 0xc);
            input_capture_write8(block, 0x1a, 9);
            input_capture_write8(block, 0x1a, 0x19);
            input_capture_update_bits(block, 0x1a, 0x20, 0);
            break;
        }
        case 42:
            input_capture_write8(block, 0x19, 0);
            input_capture_write8(block, 0x1a, 0xfe);
            input_capture_update_bits(block, 0x1a, 0x20, 0);
            break;
        default:
            input_capture_write8(block, 0x19, 0);
            input_capture_update_bits(block, 0x1a, 1, 0);
            input_capture_update_bits(block, 0x1a, 0x20, 0);
            break;
        }
    } else {
        input_capture_write8(block, 0x19, ((input_csc_selector << 3) | 0x80) & 0xf8);
        input_capture_write8(block, 0x1a, 0x19);
    }

    /* 2. Keep the format code of block 4. */
    if (block == KEPT_FORMAT_BLOCK)
        input_csc_last_format_code = input_csc_format_code;
}
