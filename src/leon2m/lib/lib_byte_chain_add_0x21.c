/* lib_byte_chain_add_0x21  (FUN_a00295f4)
 *
 * Return c + 0x21 as a byte.
 *   c: byte value
 * Returns: (c + 0x21) & 0xFF
 * Note: Unreferenced byte routine chain.
 * Name basis: descriptive - code only; nothing refers to it
 *
 * Matching notes
 * --------------
 * FUN_a00295f4 (leon2m 0xa00295f4-0xa0029604, 16 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: in each routine that calls an earlier one, the result is kept in an unsigned char local r and the
 * constant is added as its own statement; this keeps the firmware's 'and 0xff' between the steps. The earlier
 * routines of the chain are defined in this file and are inlined into the one this file is for.
 */
/* Step 0 of the chain: returns the byte unchanged. */
unsigned char lib_byte_chain_identity(unsigned char c)
{
    return c;
}

/* Step 1: adds 0x21 to the byte; the sum wraps at 256. */
unsigned char lib_byte_chain_add_0x21(unsigned char c)
{
    unsigned char r = lib_byte_chain_identity(c);

    r += 0x21;
    return r;
}
