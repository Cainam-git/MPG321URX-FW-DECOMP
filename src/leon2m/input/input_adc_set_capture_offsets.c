/* input_adc_set_capture_offsets  (FUN_a00f3a30)
 *
 * Compute two limited capture offsets from the block's registers and apply them.
 * Name basis: descriptive - six register reads and the size / position routines
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f3a30 @ 0xa00f3a30-0xa00f3c18 (488 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the second limit updates `new_height` in place (its zero-extension is then computed on every path, the
 *    shifted value kept in %o0);
 *  - the compute arm of each limit is the 'if' arm ('if (reg_38 > reg_0c) { ... } else');
 *  - the three tail stores are written in the order 0x16, 0x18, 0x1a.
 */
/* The record that input_adc_search_gain passes in (the one input_adc_auto_adjust gets); only these fields are used here. */
struct adc_window_record {
    unsigned char pad00[0xc];
    unsigned short sweep_lower_bound;           /* +0x0C */
    unsigned char pad0e[0x14 - 0xe];
    unsigned short height_after;                /* +0x14: input_block_get_capture_reg12 after the update */
    unsigned short reg_0c_after;                /* +0x16: input_block_get_reg0c_11bit after the update */
    unsigned short height_after_copy;           /* +0x18: copy of +0x14 */
    unsigned short reg_0c_after_copy;           /* +0x1A: copy of +0x16 */
    unsigned char pad1c[0x2c - 0x1c];
    unsigned short halfword_0x2c;               /* +0x2C */
    unsigned short halfword_0x2e;               /* +0x2E */
};
extern int input_block_get_capture_vstart(int);
extern unsigned int input_block_get_capture_hstart(unsigned int);
extern unsigned short input_capture_read16(unsigned char blk, unsigned char reg);
extern unsigned short input_block_measure_pixel_clock(unsigned char port);
extern unsigned short input_adc_get_line_width(void);
extern void input_block_set_capture_reg12(unsigned char, unsigned short);
extern void input_block_set_capture_reg0e(unsigned char blk, unsigned short v);
extern unsigned short input_block_get_capture_reg12(unsigned int);
extern unsigned int input_block_get_reg0c_11bit(unsigned int);

/*
 * Recompute two values from the registers of input block `block` and write them back: the 11-bit value of
 * register 0x0C (through input_block_set_capture_reg0e) and the 12-bit value of register 0x12 (through
 * input_block_set_capture_reg12). Then store the values the block holds afterwards in the record.
 * Called by input_adc_search_gain on its failure paths.
 *
 *   block   input block number
 *   record  the caller's record; see struct adc_window_record
 *
 * The first value starts as register 0x0C. When register 0x3C is below the block's vertical start (reg 0x10) and
 * input_block_measure_pixel_clock(block) is above register 0x38: if register 0x38 is not above register 0x0C
 * the value becomes register 0x38; otherwise sum = reg 0x3C + reg 0x38 - reg 0x0C, and when sum is above the
 * vertical start the value becomes reg 0x0C + (sum - vertical start).
 * The second value is built the same way from registers 0x12, 0x40 and 0x3E, the block's horizontal start
 * (reg 0x14) and input_adc_get_line_width() in place of the measured value. It is then raised to record
 * halfword +0x2C when that is larger; failing that it becomes halfword +0x2E when value + horizontal start is
 * above halfword +0x2E + sweep_lower_bound.
 * All arithmetic is on 16-bit values.
 */
void input_adc_set_capture_offsets(unsigned char block, struct adc_window_record *record)
{
    unsigned short vstart = input_block_get_capture_vstart(block);
    unsigned short hstart = input_block_get_capture_hstart(block);
    unsigned short reg_0c = input_capture_read16(block, 0xc) & 0x7ff;
    unsigned short new_height = input_capture_read16(block, 0x12) & 0xfff;
    unsigned short reg_3c = input_capture_read16(block, 0x3c) & 0x7ff;
    unsigned short reg_40 = input_capture_read16(block, 0x40) & 0xfff;
    unsigned short reg_38 = input_capture_read16(block, 0x38) & 0x7ff;
    unsigned short reg_3e = input_capture_read16(block, 0x3e) & 0xfff;
    unsigned short new_width = reg_0c, sum, reg_0c_now;

    if (reg_3c < vstart && input_block_measure_pixel_clock(block) > reg_38) {
        if (reg_38 > reg_0c) {
            sum = reg_3c + reg_38 - reg_0c;
            if (sum > vstart)
                new_width = reg_0c + (sum - vstart);
        } else
            new_width = reg_38;
    }
    if (reg_40 < hstart && input_adc_get_line_width() > reg_3e) {
        if (reg_3e > new_height) {
            sum = reg_40 + reg_3e - new_height;
            if (sum > hstart)
                new_height = new_height + (sum - hstart);
        } else
            new_height = reg_3e;
    }
    if (record->halfword_0x2c > new_height)
        new_height = record->halfword_0x2c;
    else if (new_height + hstart > record->halfword_0x2e + record->sweep_lower_bound)
        new_height = record->halfword_0x2e;
    input_block_set_capture_reg12(block, new_height);
    input_block_set_capture_reg0e(block, new_width);
    record->height_after = input_block_get_capture_reg12(block);
    reg_0c_now = input_block_get_reg0c_11bit(block);
    record->reg_0c_after = reg_0c_now;
    record->height_after_copy = record->height_after;
    record->reg_0c_after_copy = reg_0c_now;
}
