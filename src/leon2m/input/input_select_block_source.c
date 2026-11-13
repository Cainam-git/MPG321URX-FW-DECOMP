/* input_select_block_source  (FUN_a00fd594)
 *
 * Set a picture block's mode code and route bits for a source class.
 * Name basis: derived - main source selection per source class 0x11..0xE8; called from GlobalModeHandler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fd594 @ 0xa00fd594-0xa00fd820 (163 words). -mcpu=v8 -O3 -g.
 * Source form: one switch in natural value order, which gives the compare tree of the firmware (root 0x71; the
 * range 0x11..0x13 is merged by the compiler). Only the two hardware registers 0xcf0115e0 / 0xcf0115e4 are
 * accessed through volatile.
 */
extern void input_capture_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned char input_format_read8(unsigned char blk, unsigned char reg);
extern void input_format_write8(unsigned char blk, unsigned char reg, unsigned char val);
#define R(a) (*(volatile unsigned int *)(a))

/* Capture block registers written here. */
#define CAPTURE_REG_3     0x03      /* bit 0, bit 4 (0xc1) and bit 5 (0xb1) are changed; bits 4..5 are cleared first */
#define CAPTURE_REG_4     0x04      /* low 4 bits: the code that input_block_get_signal_code decodes */
#define CAPTURE_REG_5C    0x5c      /* bit 0 cleared first; bits 0 and 3 are set or cleared for 0xe1 and 0xe2 */
/* Format block register written here. */
#define FORMAT_REG_40     0x40      /* bits 0..1: 0 for 0x91, 2 for 0xa1, 1 for 0xb1 */

/*
 * Route an input block to one kind of source: set the block's selection registers for a signal code.
 *
 *   block        input block
 *   signal_code  the kind of source: 0x11, 0x12, 0x13, 0x21, 0x31, 0x41, 0x51, 0x61, 0x71, 0x81, 0x91, 0xa1, 0xb1,
 *                0xc1, 0xe1, 0xe2 or 0xe8 (any other value changes nothing beyond the two clears at the start)
 *
 * First it clears bit 0 of capture register 0x5c and bits 4..5 of capture register 3. Then, per code:
 *   0x11, 0x12, 0x13, 0x21, 0xe8      register 4 = 0x80
 *   0x31 / 0x41 / 0x51 / 0x61         register 4 = 0x82 / 0x86 / 0x8a / 0x8e
 *   0x71 and 0x81                     register 4 = 0x83; register 3 bit 0 is set for 0x81 and cleared for 0x71
 *   0x91 / 0xa1                       register 4 = 0x82; format register 0x40 bits 0..1 = 0 / 2; the
 *                                     hardware registers 0xcf0115e0 = 0 and 0xcf0115e4 = 4
 *   0xb1                              register 3 bit 5 set; format register 0x40 bits 0..1 = 1
 *   0xc1                              register 4 = 0x8a; register 3 bit 4 set
 *   0xe1 / 0xe2                       register 4 = 0x83; register 0x5c bit 0 set and bit 3 set (0xe1) or
 *                                     cleared (0xe2)
 * For every listed code except 0xb1, register 3 bit 0 is written last (set for 0x81, cleared for the others).
 *
 * input_block_get_signal_code reads these same bits back (register 3 bits 4 and 5, register 4 bits 0..3, format
 * register 0x40 bits 0..1) to produce the signal code of a block. The caller loads the block's remaining
 * registers for the same code with input_load_block_source_registers. Called by GlobalModeHandler and
 * input_set_port_mode.
 */
void input_select_block_source(unsigned char block, unsigned char signal_code)
{
    input_capture_update_bits(block, CAPTURE_REG_5C, 1, 0);
    input_capture_update_bits(block, CAPTURE_REG_3, 0x30, 0);
    switch (signal_code) {
    case 0x11: case 0x12: case 0x13: case 0x21: case 0xe8:
        input_capture_write8(block, CAPTURE_REG_4, 0x80);
        input_capture_update_bits(block, CAPTURE_REG_3, 1, 0);
        break;
    case 0x31:
        input_capture_write8(block, CAPTURE_REG_4, 0x82);
        input_capture_update_bits(block, CAPTURE_REG_3, 1, 0);
        break;
    case 0x41:
        input_capture_write8(block, CAPTURE_REG_4, 0x86);
        input_capture_update_bits(block, CAPTURE_REG_3, 1, 0);
        break;
    case 0x51:
        input_capture_write8(block, CAPTURE_REG_4, 0x8a);
        input_capture_update_bits(block, CAPTURE_REG_3, 1, 0);
        break;
    case 0x61:
        input_capture_write8(block, CAPTURE_REG_4, 0x8e);
        input_capture_update_bits(block, CAPTURE_REG_3, 1, 0);
        break;
    case 0x71:
        input_capture_write8(block, CAPTURE_REG_4, 0x83);
        input_capture_update_bits(block, CAPTURE_REG_3, 1, 0);
        break;
    case 0x81:
        input_capture_write8(block, CAPTURE_REG_4, 0x83);
        input_capture_update_bits(block, CAPTURE_REG_3, 1, 1);
        break;
    case 0x91:
        input_capture_write8(block, CAPTURE_REG_4, 0x82);
        input_format_write8(block, FORMAT_REG_40, input_format_read8(block, FORMAT_REG_40) & 0xfc);
        R(0xcf0115e0) = 0;
        R(0xcf0115e4) = 4;
        input_capture_update_bits(block, CAPTURE_REG_3, 1, 0);
        break;
    case 0xa1:
        input_capture_write8(block, CAPTURE_REG_4, 0x82);
        input_format_write8(block, FORMAT_REG_40, (input_format_read8(block, FORMAT_REG_40) | 2) & 0xfe);
        R(0xcf0115e0) = 0;
        R(0xcf0115e4) = 4;
        input_capture_update_bits(block, CAPTURE_REG_3, 1, 0);
        break;
    case 0xb1:
        input_capture_update_bits(block, CAPTURE_REG_3, 0x20, 1);
        input_format_write8(block, FORMAT_REG_40, (input_format_read8(block, FORMAT_REG_40) | 1) & 0xfd);
        break;
    case 0xc1:
        input_capture_write8(block, CAPTURE_REG_4, 0x8a);
        input_capture_update_bits(block, CAPTURE_REG_3, 0x10, 1);
        input_capture_update_bits(block, CAPTURE_REG_3, 1, 0);
        break;
    case 0xe1:
        input_capture_update_bits(block, CAPTURE_REG_5C, 1, 1);
        input_capture_update_bits(block, CAPTURE_REG_5C, 8, 1);
        input_capture_write8(block, CAPTURE_REG_4, 0x83);
        input_capture_update_bits(block, CAPTURE_REG_3, 1, 0);
        break;
    case 0xe2:
        input_capture_update_bits(block, CAPTURE_REG_5C, 1, 1);
        input_capture_update_bits(block, CAPTURE_REG_5C, 8, 0);
        input_capture_write8(block, CAPTURE_REG_4, 0x83);
        input_capture_update_bits(block, CAPTURE_REG_3, 1, 0);
        break;
    }
}
