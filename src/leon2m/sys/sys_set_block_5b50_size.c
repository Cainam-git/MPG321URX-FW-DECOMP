/* sys_set_block_5b50_size  (FUN_a0114420)
 *
 * Write a width rounded up to 8 and half a height to the block at 0xCF015B50.
 * Name basis: descriptive - width halved above 1920; used by the output timing set-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0114420 @ 0xa0114420-0xa0114498 (30 words), flags -mcpu=v8 -O3 -g.
 * Source form: both parameters are unsigned short; reg_write16_bytes(unsigned int, unsigned int) returns
 * nothing, and its last call compiles to a tail call.
 */
extern void reg_write16_bytes(unsigned int, unsigned int);

#define HALVE_ABOVE_WIDTH 0x780     /* widths above this (1920) are halved first */

/*
 * Write a width and a height to the two register pairs of the block at 0xCF015B50.
 *
 * width  halved first when it is above HALVE_ABOVE_WIDTH, then rounded up to a multiple of 8
 * height halved
 *
 * The rounded width goes to 0xCF015B50 and 0xCF015B6C, the halved height to 0xCF015B58 and 0xCF015B74, each
 * through reg_write16_bytes (low byte at the address, high byte at address + 4).
 * Called by sys_channel_apply_output_timing.
 */
void sys_set_block_5b50_size(unsigned short width, unsigned short height)
{
    unsigned short rounded_width;
    unsigned short half_height;

    half_height = height >> 1;
    if (width > HALVE_ABOVE_WIDTH)
        width = width >> 1;
    rounded_width = ((width + 7) >> 3) << 3;
    reg_write16_bytes(0xcf015b50, rounded_width);
    reg_write16_bytes(0xcf015b58, half_height);
    reg_write16_bytes(0xcf015b6c, rounded_width);
    reg_write16_bytes(0xcf015b74, half_height);
}
