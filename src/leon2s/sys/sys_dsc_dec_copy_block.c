/* sys_dsc_dec_copy_block  (FUN_a00a60d8)
 *
 * Copy 24 words between the two register areas of a DSC decoder record.
 *   decoder
 * Name basis: descriptive - lib_copy_words(rec.a, rec.b, 0x18); caller sys_dsc_dec_run_state
 *
 * Matching notes
 * --------------
 * FUN_a00a60d8 (leon2s, 0xa00a60d8-0xa00a610c, 52 bytes, leaf with sibcall), flags -mcpu=v8 -Os -g.
 * The record table starts at 0xa807dc04 (a 0xa807dc00-based array with the fields at +4/+8 gives a different
 * add order). The call is a tail call (leaf 'mov %o7,%g1' sibcall).
 */
struct dsc_decoder_record { unsigned int regs_main; unsigned int regs_second; unsigned int regs_third; };
extern struct dsc_decoder_record sys_dsc_dec_records[];
extern void lib_copy_words(unsigned int, unsigned int, unsigned int);

/* Copy 0x18 words from the first register block of the decoder to its second register block address
 * (lib_copy_words(first, second, 0x18)). Called by sys_dsc_dec_run_state.
 *   decoder: decoder number
 */
void sys_dsc_dec_copy_block(unsigned char decoder)
{
    lib_copy_words(sys_dsc_dec_records[decoder].regs_main, sys_dsc_dec_records[decoder].regs_second, 0x18);
}
