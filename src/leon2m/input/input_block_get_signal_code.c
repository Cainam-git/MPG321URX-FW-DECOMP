/* input_block_get_signal_code  (FUN_a00fd820)
 *
 * Return the signal code of an input block.
 * Returns: code
 * Name basis: derived - code 1 or 0x11..0xE8 from the block's registers; many callers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fd820 @ 0xa00fd820 (-mcpu=v8 -O3 -g).
 * Source form: one result variable (signal_code) set in the branches and returned at the end of the two inner
 * paths; the early returns for 0xE8 and 0xC1 are plain returns.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned char input_block_get_reg8c_bit7(unsigned char port);
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern unsigned char input_format_read8(unsigned char blk, unsigned char reg);
extern unsigned char input_measure_read8(unsigned char blk, unsigned char reg);

/* Capture block registers read here. */
#define MEASURE_REG_0     0x00
#define CAPTURE_REG_3      0x03
#define CAPTURE_REG_4      0x04
#define CAPTURE_REG_54     0x54
#define FORMAT_REG_40      0x40

/*
 * Work out the signal code of an input block from the registers that input_select_block_source writes.
 *
 *   block  input block
 *
 * Returns the signal code, tested in this order:
 *   0xE8  bit 7 of capture register 0x8c is set (the test pattern is on, see input_block_enable_pre_pattern)
 *   capture register 3 bit 5 set: by bits 0..1 of format register 0x40: 0 gives 0x91, 2 gives 0xA1, else 0xB1
 *   0xC1  capture register 3 bit 4 set
 *   otherwise by the low 4 bits of capture register 4:
 *     0 or 1       bit 3 of measure register 0 set: 0x21 when the low 3 bits of register 0xCF020114 are 5, else
 *                  0x13; bit 3 clear: 0x12 when bit 0 of capture register 0x54 is set, else 0x11
 *     2 / 6 / 10 / 14   0x31 / 0x41 / 0x51 / 0x61
 *     3, 7, 11 or 15    0x81 when bit 0 of capture register 3 is set, else 0x71
 *     anything else     1
 * In the input program's DSC decoder the sources 0x51 and 0x61 are HDMI 2.1 and 0x71 and 0x81 are DisplayPort.
 * Called by many routines of the input handling, for example sys_get_channel_signal_code,
 * sys_channel_apply_output_timing and input_csc_setup.
 */
unsigned char input_block_get_signal_code(unsigned char block)
{
    unsigned char signal_code;
    unsigned char format_bits;

    if (input_block_get_reg8c_bit7(block))
        return 0xe8;
    if (input_capture_read8(block, CAPTURE_REG_3) & 0x20) {
        format_bits = input_format_read8(block, FORMAT_REG_40) & 3;
        if (format_bits == 0)
            signal_code = 0x91;
        else if (format_bits == 2)
            signal_code = 0xa1;
        else
            signal_code = 0xb1;
        return signal_code;
    }
    if (input_capture_read8(block, CAPTURE_REG_3) & 0x10)
        return 0xc1;
    switch (input_capture_read8(block, CAPTURE_REG_4) & 0xf) {
    case 0:
    case 1:
        if (input_measure_read8(block, MEASURE_REG_0) & 8) {
            if ((R(0xcf020114) & 7) == 5)
                signal_code = 0x21;
            else
                signal_code = 0x13;
        } else if (input_capture_read8(block, CAPTURE_REG_54) & 1)
            signal_code = 0x12;
        else
            signal_code = 0x11;
        break;
    case 2:
        signal_code = 0x31;
        break;
    case 6:
        signal_code = 0x41;
        break;
    case 10:
        signal_code = 0x51;
        break;
    case 14:
        signal_code = 0x61;
        break;
    case 3:
    case 7:
    case 11:
    case 15:
        if (input_capture_read8(block, CAPTURE_REG_3) & 1)
            signal_code = 0x81;
        else
            signal_code = 0x71;
        break;
    default:
        signal_code = 1;
        break;
    }
    return signal_code;
}
