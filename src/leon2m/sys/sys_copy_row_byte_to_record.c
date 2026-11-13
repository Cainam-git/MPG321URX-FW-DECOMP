/* sys_copy_row_byte_to_record  (FUN_a012bae0)
 *
 * Store a byte of the active panel timing row in byte 0x15 of a record.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * FUN_a012bae0 (leon2m 0xa012bae0-0xa012baf0, 16 bytes, leaf), flags -mcpu=v8 -O2 -g. Source form: the unused
 * first parameter keeps the block pointer in %o1.
 */
extern unsigned char panel_active_row_bpc;

/* Size block of one output; only the bits-per-colour byte is used here (see sys_fill_output_size_record). */
struct output_size_block
{
  unsigned char pad[0x15];
  unsigned char bits_per_colour;                /* +0x15 */
};

/* Copy panel_active_row_bpc into the bits_per_colour byte (+0x15) of block. The first argument is not used. */
void sys_copy_row_byte_to_record(unsigned int unused, struct output_size_block *block)
{
    block->bits_per_colour = panel_active_row_bpc;
}
