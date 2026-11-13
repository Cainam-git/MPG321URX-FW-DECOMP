/* input_fill_port_timing  (FUN_a014285c)
 *
 * Fill a port's timing record from the measurement hardware.
 * Name basis: derived - horizontal rate, vertical rate and sizes read from the measurement block
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014285c @ 0xa014285c-0xa0142910, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: the two arms store the same fields in the same order, each with its own
 * calls.
 */

/* The port record (0x2A bytes), up to the fields written here. */
struct port_record_timing {
    unsigned char pad0[0x1e];
    unsigned short line_rate;       /* +0x1E: units of 100 Hz */
    unsigned short refresh_rate;    /* +0x20: tenths of a hertz (timing field 2) */
    unsigned char register_0x22;    /* +0x22: register 0x22 of the input block */
    unsigned char register_0x23;    /* +0x23: register 0x23 of the input block */
    unsigned char pixel_repeat;     /* +0x24 */
    unsigned char pad25;
    unsigned short pixel_clock_value;   /* +0x26 */
};
extern unsigned char input_block_get_reg8c_bit7(unsigned char port);
extern unsigned short input_get_const_375(unsigned char port);
extern unsigned short input_get_const_500(unsigned char port);
extern unsigned char input_block_read_reg22(unsigned char port);
extern unsigned char input_block_read_reg23(unsigned char port);
extern unsigned short input_block_read_reg97_word(unsigned char port);
extern unsigned short input_block_measure_hfreq(unsigned char port);
extern unsigned short input_block_measure_vfreq(unsigned char port);
extern unsigned char input_block_get_pixel_repeat(unsigned char port);
extern unsigned short input_block_measure_pixel_clock(unsigned char port);

#define PIXEL_REPEAT_FIXED 8            /* stored when bit 7 of register 0x8C is set */

/*
 * Fill the timing fields of a port record from the input block of the port.
 *
 *   record  the port record
 *   port    the port number
 *
 * When bit 7 of register 0x8C of the block is set, the line rate is the constant 375 and the refresh rate the
 * constant 500, the pixel repeat is 8 and the last field is register 0x97.
 * Otherwise the line rate, the refresh rate and the last field are measured (input_block_measure_hfreq,
 * input_block_measure_vfreq, input_block_measure_pixel_clock) and the pixel repeat is read from the block.
 * Called from input_port_sync_task.
 */
void input_fill_port_timing(struct port_record_timing *record, unsigned char port)
{
    if (input_block_get_reg8c_bit7(port)) {
        record->line_rate = input_get_const_375(port);
        record->refresh_rate = input_get_const_500(port);
        record->register_0x22 = input_block_read_reg22(port);
        record->register_0x23 = input_block_read_reg23(port);
        record->pixel_repeat = PIXEL_REPEAT_FIXED;
        record->pixel_clock_value = input_block_read_reg97_word(port);
    } else {
        record->line_rate = input_block_measure_hfreq(port);
        record->refresh_rate = input_block_measure_vfreq(port);
        record->register_0x22 = input_block_read_reg22(port);
        record->register_0x23 = input_block_read_reg23(port);
        record->pixel_repeat = input_block_get_pixel_repeat(port);
        record->pixel_clock_value = input_block_measure_pixel_clock(port);
    }
}
