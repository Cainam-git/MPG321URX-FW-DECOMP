/* input_block_setup_capture_quarter  (FUN_a00f8a98)
 *
 * Set an input block up with sizes in units of 4, retrying on block 1 until it is stable.
 * Name basis: derived - prints 'Toggle(%d) P1 420/444 for ASYNC FIFO over/under fl...'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8a98 @ 0xa00f8a98-0xa00f8cc4 (139 words), flags -mcpu=v8 -O3 -g.
 * Source form: each signal code has its own input_format_write8 call (the compiler merges them); the rounding
 * of width and height is an if/else per value; the retry count is incremented inside the second operand of the
 * loop condition.
 */
extern int dbg_printf(const char *fmt, ...);
extern unsigned char input_block_get_signal_code(unsigned char);
extern void input_format_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_format_write16(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned char input_format_read8(unsigned char blk, unsigned char reg);
extern void ipc_signal_alive(void);
extern void timer_sleep_ticks(int ms);

#define FORMAT_REG_MODE        0x00         /* 0, 1 or 2, chosen from the signal code */
#define FORMAT_REG_WIDTH       0x10         /* 16-bit */
#define FORMAT_REG_HEIGHT      0x12         /* 16-bit */
#define FORMAT_REG_14          0x14         /* 16-bit, the caller's reg14_value */
#define FORMAT_REG_16          0x16
#define FORMAT_REG_STATUS      0x4a         /* bits 0..1: the firmware's text calls them ASYNC FIFO over/under flow */
#define FORMAT_FIFO_ERROR_BITS 3
#define MAX_TOGGLES            9            /* the toggle sequence is run at most 10 times */

/*
 * Set up the format block of an input block with width and height in units of 4 (rounded up), as
 * input_block_setup_capture does in units of 8.
 *
 *   block        input block
 *   width        divided by 4, rounded up, and written to format register 0x10
 *   height       divided by 4, rounded up, and written to format register 0x12
 *   reg14_value  written unchanged to format register 0x14
 *
 * Format register 0 gets 0 for signal code 0xB1, 2 for 0x71 and 0x81, and 1 for every other code (0x31, 0x41,
 * 0x51, 0x61 and the rest). Blocks other than 1 end by writing 0x42 to register 0x16.
 *
 * Block 1 runs a toggle sequence instead (registers 0x48, 0x16 and 0x49, with waits between the writes) and
 * reads register 0x4a afterwards. While bits 0..1 of it are set it prints the "Toggle(n) P1 420/444 for ASYNC
 * FIFO over/under flow" text and repeats the sequence, at most 10 times in all. It ends by writing 3 to
 * register 0x49.
 *
 * Called by sys_channel_apply_output_timing (it uses input_block_setup_capture instead in one case).
 */
void input_block_setup_capture_quarter(unsigned char block, unsigned short width, unsigned short height, unsigned short reg14_value)
{
    unsigned char toggle_count = 0;
    unsigned char signal_code;

    if (width % 4)
        width = width / 4 + 1;
    else
        width = width / 4;
    if (height % 4)
        height = height / 4 + 1;
    else
        height = height / 4;
    signal_code = input_block_get_signal_code(block);
    if (signal_code == 0xb1)
        input_format_write8(block, FORMAT_REG_MODE, 0);
    else if (signal_code == 0x31 || signal_code == 0x41 || signal_code == 0x51 || signal_code == 0x61)
        input_format_write8(block, FORMAT_REG_MODE, 1);
    else if (signal_code == 0x71 || signal_code == 0x81)
        input_format_write8(block, FORMAT_REG_MODE, 2);
    else
        input_format_write8(block, FORMAT_REG_MODE, 1);
    input_format_write16(block, FORMAT_REG_WIDTH, width);
    input_format_write16(block, FORMAT_REG_HEIGHT, height);
    input_format_write16(block, FORMAT_REG_14, reg14_value);
    if (block == 1) {
        do {
            ipc_signal_alive();
            input_format_write8(block, 0x48, 1);
            input_format_write8(block, FORMAT_REG_16, 0x4a);
            timer_sleep_ticks(1);
            input_format_write8(block, FORMAT_REG_16, 0x42);
            input_format_write8(block, 0x48, 0);
            input_format_write8(block, 0x49, 0xc3);
            timer_sleep_ticks(0x32);
            input_format_write8(block, 0x49, 1);
            timer_sleep_ticks(5);
            if (input_format_read8(block, FORMAT_REG_STATUS) & FORMAT_FIFO_ERROR_BITS)
                dbg_printf("\x1b[1;31mToggle(%d) P1 420/444 for ASYNC FIFO over/under flow(%02x)\r\n\x1b[m", toggle_count,
                             input_format_read8(block, FORMAT_REG_STATUS) & FORMAT_FIFO_ERROR_BITS);
        } while ((input_format_read8(block, FORMAT_REG_STATUS) & FORMAT_FIFO_ERROR_BITS) && ++toggle_count <= MAX_TOGGLES);
        input_format_write8(block, 0x49, 3);
    } else
        input_format_write8(block, FORMAT_REG_16, 0x42);
}
