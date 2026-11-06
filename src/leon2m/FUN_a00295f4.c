/* FUN_a00295f4 (leon2m 0xa00295f4-0xa0029604, 16 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns FUN_a00295ec(c) + 0x21 as an unsigned char: returns (c + 0x21) & 0xff. Nothing in the image refers to it.
 * It belongs to the chain of byte routines FUN_a00295ec..FUN_a00297ec, each built on an earlier one; the routines
 * it uses (FUN_a00295ec) are defined in this file and inlined.
 * Source form: the result of FUN_a00295ec is kept in an unsigned char local r, then 'r += 0x21' as its own
 * statement and 'return r' (the firmware's 'and 0xff' before and after the step).
 */
unsigned char FUN_a00295ec(unsigned char c)
{
    return c;
}

unsigned char FUN_a00295f4(unsigned char c)
{
    unsigned char r = FUN_a00295ec(c);

    r += 0x21;
    return r;
}
