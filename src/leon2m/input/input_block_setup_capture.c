/* input_block_setup_capture  (FUN_a00f896c)
 *
 * Set an input block up for its signal type and capture size.
 * Name basis: derived - type from input_block_get_signal_code, sizes in units of 8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f896c @ 0xa00f896c, 75 words, flags -mcpu=v8 -O3 -g.
 * Source form: as in the next routine (input_block_setup_capture_quarter, which divides by 4): every signal code has its own
 * input_format_write8 call (the compiler merges them), and the rounding is an if/else per value.
 */
extern unsigned char input_block_get_signal_code(unsigned char);
extern void input_format_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_format_write16(unsigned char blk, unsigned char reg, unsigned short val);

/* Set up the format block for the signal on the input block. Width and height are divided by 8, rounded up.
 * Format register 0 gets 0 for signal code 0xB1, 2 for 0x71 and 0x81, and 1 for everything else (including
 * 0x31, 0x41, 0x51 and 0x61). Then the width goes to register 0x10, the height to 0x12, reg14_value to 0x14,
 * and 0x4A to register 0x16. Called by sys_channel_apply_output_timing. */
void input_block_setup_capture(unsigned char block, unsigned short width, unsigned short height, unsigned short reg14_value)
{
    unsigned char signal_code;

    if (width % 8)
        width = width / 8 + 1;
    else
        width = width / 8;
    if (height % 8)
        height = height / 8 + 1;
    else
        height = height / 8;
    signal_code = input_block_get_signal_code(block);
    if (signal_code == 0xb1)
        input_format_write8(block, 0, 0);
    else if (signal_code == 0x31 || signal_code == 0x41 || signal_code == 0x51 || signal_code == 0x61)
        input_format_write8(block, 0, 1);
    else if (signal_code == 0x71 || signal_code == 0x81)
        input_format_write8(block, 0, 2);
    else
        input_format_write8(block, 0, 1);
    input_format_write16(block, 0x10, width);
    input_format_write16(block, 0x12, height);
    input_format_write16(block, 0x14, reg14_value);
    input_format_write8(block, 0x16, 0x4a);
}
