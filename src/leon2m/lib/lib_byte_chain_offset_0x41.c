/* lib_byte_chain_offset_0x41  (FUN_a00297ec)
 *
 * Return lib_byte_chain_triple(c + 0x41) as a byte.
 *   c: byte value
 * Returns: byte result
 * Note: Unreferenced byte routine chain.
 * Name basis: descriptive - code only; nothing refers to it
 *
 * Matching notes
 * --------------
 * FUN_a00297ec (leon2m 0xa00297ec-0xa0029818, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
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

/* Step 2: adds 0x0E to the result of step 1; the sum wraps at 256. */
unsigned char lib_byte_chain_add_0x0e(unsigned char c)
{
    unsigned char r = lib_byte_chain_add_0x21(c);

    r += 0xe;
    return r;
}

/* Step 3: the result of step 2 shifted right by one. */
unsigned char lib_byte_chain_halve(unsigned char c)
{
    return lib_byte_chain_add_0x0e(c) >> 1;
}

/* Step 4: the result of step 3 times 3; the product wraps at 256. */
unsigned char lib_byte_chain_triple(unsigned char c)
{
    return lib_byte_chain_halve(c) * 3;
}

/*
 * Adds 0x41 to the byte, then runs step 4 (lib_byte_chain_triple) on the sum. Nothing calls this routine.
 */
unsigned char lib_byte_chain_offset_0x41(unsigned char c)
{
    return lib_byte_chain_triple(c + 0x41);
}
