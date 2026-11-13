/* input_block_handle_mode_change  (FUN_a01213a4)
 *
 * Re-detect the sync mode of a block after a change and reprogram it.
 * Name basis: proven - prints '----------Mode(%d) Change Flag !!!!----------'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01213a4 @ 0xa01213a4 (-mcpu=v8 -O3 -g)
 * Source form: old-style (K&R) definition; the parameter block itself receives the input_block_detect_sync_mode
 * result (declared without a prototype, so the int result is not zero-extended) and the value 1, which is set
 * before the dbg_printf call; the final block reads the block number through an unsigned short copy
 * (block_copy) taken at entry.
 */
/* One entry of input_block_configs (12 bytes); word_8 is split into bytes here. */
struct input_block_config { unsigned int word_0, word_4; unsigned char byte_8, byte_9, byte_10, byte_11; };
extern struct input_block_config input_block_configs[];
extern unsigned int sys_unit_event_bits;
extern int dbg_printf(const char *fmt, ...);
extern unsigned char input_block_get_signal_code(unsigned char);
extern int input_block_detect_sync_mode();
extern void input_block_set_sync_source(unsigned char blk, unsigned short h, unsigned char on);
extern void input_measure_write8(unsigned char blk, unsigned char reg, unsigned char val);

/* Measure block registers written when the sync mode has changed. */
#define MEASURE_REG_1C  0x1c
#define MEASURE_REG_1D  0x1d
#define MEASURE_REG_1E  0x1e
#define MEASURE_REG_1F  0x1f

/*
 * Re-detect the sync mode of an input block and, when it has changed to one of 2 to 5, reprogram the block.
 *
 *   block          input block (0..7)
 *   line_rate      passed on to input_block_set_sync_source when a change flag is found
 *   previous_mode  the sync mode returned by the previous call for this block
 *
 * Returns the sync mode: the result of input_block_detect_sync_mode for the block's signal code, or 1 when the
 * block's change flag (its bit in sys_unit_event_bits) was set. A set flag is cleared here, the block's sync
 * source is switched with input_block_set_sync_source(block, line_rate, 0) and "Mode(%d) Change Flag" is
 * printed.
 *
 * When the mode is 2 to 5 and not the same as previous_mode, measure registers 0x1e = 0x3f, 0x1f = 0x1f,
 * 0x1c = reg1c_value and 0x1d = reg1d_value & 0x17 are written. reg1c_value is 0x3c (0 for signal code 0xe8),
 * with bit 5 cleared when byte 8 of the block's input_block_configs entry is not 0. reg1d_value is 7 for the
 * codes 0x11, 0x12, 0x13 and 0x21 (and for any code not listed), 0x13 for 0x31, 0x41, 0x51 and 0x61, 3 for 0x71,
 * 0x81, 0xb1, 0xe1 and 0xe2, 0 for 0xe8, and for 0x91 3, or 2 when byte 9 of the configuration entry is not 0.
 *
 * Called by input_port_sync_task, which keeps the returned mode in the port record and passes it back as
 * previous_mode on the next call.
 */
unsigned char input_block_handle_mode_change(block, line_rate, previous_mode)
    unsigned int block;
    unsigned char line_rate, previous_mode;
{
    unsigned char blk = block;
    unsigned short block_copy = block;
    unsigned char signal_code, result_mode, reg1c_value, reg1d_value, mode_minus_2;
    unsigned int change_flag;

    signal_code = input_block_get_signal_code(blk);
    block = input_block_detect_sync_mode(signal_code, blk);
    change_flag = (sys_unit_event_bits >> blk) & 1;
    if (change_flag == 1) {
        sys_unit_event_bits &= ~(change_flag << blk);
        input_block_set_sync_source(blk, line_rate, 0);
        block = 1;
        dbg_printf("\r\n----------Mode(%d) Change Flag !!!!----------\r\n", blk);
    }
    mode_minus_2 = block - 2;
    result_mode = block;
    if (mode_minus_2 < 4 && result_mode != previous_mode) {
        unsigned char blk_again = block_copy;
        reg1c_value = 0x3c;
        reg1d_value = 7;
        switch (signal_code) {
        case 0x11: case 0x12: case 0x13: case 0x21:
            reg1d_value = 7;
            break;
        case 0x31: case 0x41: case 0x51: case 0x61:
            reg1d_value = 0x13;
            break;
        case 0x71: case 0x81: case 0xb1: case 0xe1: case 0xe2:
            reg1d_value = 3;
            break;
        case 0x91:
            reg1d_value = 3;
            if (input_block_configs[blk].byte_9 != 0)
                reg1d_value = 2;
            break;
        case 0xe8:
            reg1c_value = 0;
            reg1d_value = 0;
            break;
        }
        if (input_block_configs[blk_again].byte_8 != 0)
            reg1c_value &= 0xdf;
        input_measure_write8(blk_again, MEASURE_REG_1E, 0x3f);
        input_measure_write8(blk_again, MEASURE_REG_1F, 0x1f);
        input_measure_write8(blk_again, MEASURE_REG_1C, reg1c_value);
        input_measure_write8(blk_again, MEASURE_REG_1D, reg1d_value & 0x17);
    }
    return result_mode;
}
