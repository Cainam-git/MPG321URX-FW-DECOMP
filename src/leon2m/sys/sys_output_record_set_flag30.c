/* sys_output_record_set_flag30  (FUN_a012bb38)
 *
 * Write flag bit 30 of output record 0, or clear it for another record.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * FUN_a012bb38 (leon2m 0xa012bb38-0xa012bb94, 92 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a one-bit bit-field; the index == 0 arm indexes the array with index (offset-0 load through the
 * index register).
 */
/* First word of an output record (0x24 bytes, table sys_output_records); the same bit names as in sys_output_record_set_flag. */
struct output_record_flags { unsigned int bit31:1, bit30:1, rest:30; };
struct output_record { struct output_record_flags flags; unsigned char pad04[0x20]; };
extern struct output_record sys_output_records[];

/*
 * Set bit 30 of the first word of output record index to the low bit of value; for any index other than 0
 * the bit is cleared instead. Not called by name anywhere in the source.
 */
void sys_output_record_set_flag30(unsigned char index, unsigned int value)
{
    if (index == 0)
        sys_output_records[index].flags.bit30 = value;
    else
        sys_output_records[index].flags.bit30 = 0;
}
