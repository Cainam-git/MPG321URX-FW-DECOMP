/* input_adc_step_width_to_target  (FUN_a00f42b8)
 *
 * Step a 16-bit width value towards a target in steps of 4, applying each step.
 * Name basis: descriptive - waits for a frame per step
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f42b8 @ 0xa00f42b8-0xa00f4434 (380 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - a do-while loop whose body is wrapped in 'if (target_width != start_width)' (the code tests the equality at
 *    the top of every pass);
 *  - the result of input_block_get_capture_hstart is compared through an unsigned short local and the routine is
 *    called a second time for the sum.
 */
#define REG_CF011800 (*(volatile unsigned int *)0xcf011800)

extern unsigned short input_adc_get_line_width(void);
extern void panel_wait_sync_pulse(void);
extern void input_adc_set_line_width(unsigned char blk, unsigned short val);
extern unsigned int input_block_get_capture_hstart(unsigned int blk);
extern unsigned char sys_path_block_is_enabled(unsigned int blk);
extern void sys_path_block_set_width(unsigned int blk, unsigned short v);
extern unsigned char sys_path_get_mux_field(void);
extern void (*input_adc_cal_hook3)(void);

#define WIDTH_STEP          4       /* size of one step of the line width value */
#define HSTART_MARGIN       0x14    /* added to the block's horizontal start when that is above the width */

/*
 * Move the line width value from its present setting to `target_width` in steps of 4 and apply every step.
 * Called by input_adc_auto_adjust.
 *
 *   block         input block number
 *   target_width  the value to reach; the last step is cut short so that it is hit exactly
 *
 * Each step: wait for a sync pulse of the panel, write the new value with input_adc_set_line_width, then give
 * the signal path block a width: the value itself, or the block's horizontal start plus 0x14 when that start is
 * above the value. Block 0 sets signal path block 0 when that is enabled; otherwise, when the mux field
 * (sys_path_get_mux_field) equals `block` and signal path block 1 is enabled, it sets signal path block 1. When the target equals the present value nothing is done.
 * After the last step, for block 0 only: when bit 4 of register 0xCF011800 is set and the hook
 * input_adc_cal_hook3 is set, the hook is called.
 */
void input_adc_step_width_to_target(unsigned char block, unsigned short target_width)
{
    unsigned short start_width;
    unsigned short current_width, path_width;
    unsigned short hstart;

    start_width = input_adc_get_line_width();
    current_width = start_width;
    do {
        if (target_width != start_width) {
            if (target_width > start_width) {
                current_width += WIDTH_STEP;
                if (current_width > target_width)
                    current_width = target_width;
            } else {
                current_width -= WIDTH_STEP;
                if (current_width < target_width)
                    current_width = target_width;
            }
            panel_wait_sync_pulse();
            input_adc_set_line_width(block, current_width);
            hstart = input_block_get_capture_hstart(block);
            if (hstart > current_width)
                path_width = input_block_get_capture_hstart(block) + HSTART_MARGIN;
            else
                path_width = current_width;
            if (block == 0 && sys_path_block_is_enabled(0))
                sys_path_block_set_width(0, path_width);
            else if (sys_path_get_mux_field() == block && sys_path_block_is_enabled(1))
                sys_path_block_set_width(1, path_width);
        }
    } while (current_width != target_width);
    if (block == 0 && (REG_CF011800 & 0x10) && input_adc_cal_hook3 != 0)
        input_adc_cal_hook3();
}
