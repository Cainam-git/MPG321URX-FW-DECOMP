/* lib_byte_chain_identity  (FUN_a00295ec)
 *
 * Return the byte argument unchanged.
 *   c: byte value
 * Returns: c
 * Note: First of an unreferenced chain of byte routines (FUN_a00295ec..lib_byte_chain_offset_0x41).
 * Name basis: descriptive - code only; nothing refers to it
 *
 * Matching notes
 * --------------
 * FUN_a00295ec (leon2m 0xa00295ec-0xa00295f4, 8 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: in each routine that calls an earlier one, the result is kept in an unsigned char local r and the
 * constant is added as its own statement; this keeps the firmware's 'and 0xff' between the steps. The earlier
 * routines of the chain are defined in this file and are inlined into the one this file is for.
 */
/* Step 0 of the chain: returns the byte unchanged. */
unsigned char lib_byte_chain_identity(unsigned char c)
{
    return c;
}
