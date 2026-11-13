/* sys_dsc_dec_status_bit0  (FUN_a00a60ac)
 *
 * Return bit 0 of status word 0xB0 of DSC decoder 0, or 2 for others.
 *   decoder
 * Returns: bit value, 2 for other decoders
 * Name basis: descriptive - caller sys_dsc_dec_run_state
 *
 * Matching notes
 * --------------
 * FUN_a00a60ac (leon2s 0xa00a60ac-0xa00a60d8, 44 bytes), flags -mcpu=v8 -Os -g.
 * Leaf. Source form: the pointer is indexed by decoder (the firmware keeps the [base + %o0] form; the value is
 * 0 there), and the result and return type are a full unsigned int (a u8 result adds the 'and 3' extension
 * that the firmware does not have).
 */
struct dsc_regs { unsigned char pad[0xb0]; unsigned int word_0xb0; };
extern struct dsc_regs *sys_dsc_dec_records[];

/* Return bit 0 of the register word at offset 0xb0 of decoder 0's first register block; for any other
 * decoder number return 2. Called by sys_dsc_dec_run_state.
 *   decoder: decoder number
 */
unsigned int sys_dsc_dec_status_bit0(unsigned char decoder)
{
    unsigned int result = 2;

    if (decoder == 0)
        result = sys_dsc_dec_records[decoder]->word_0xb0 & 1;
    return result;
}
