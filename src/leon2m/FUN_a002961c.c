/* FUN_a002961c (leon2m 0xa002961c-0xa0029638, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns FUN_a0029604(c) >> 1 as an unsigned char: returns (((((c & 0xff) + 0x21) & 0xff) + 0x0e) & 0xff) >> 1.
 * Nothing in the image refers to it. It belongs to the chain of byte routines FUN_a00295ec..FUN_a00297ec, each
 * built on an earlier one; the routines it uses (FUN_a00295ec, FUN_a00295f4, FUN_a0029604) are defined in this file
 * and inlined.
 * Source form: FUN_a00295f4 and FUN_a0029604 keep the called routine's result in an unsigned char local and add
 * their step as a separate statement ('r += 0x21;', 'r += 0xe;'), which keeps the firmware's 'and 0xff' between
 * the two steps.
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

unsigned char FUN_a0029604(unsigned char c)
{
    unsigned char r = FUN_a00295f4(c);

    r += 0xe;
    return r;
}

unsigned char FUN_a002961c(unsigned char c)
{
    return FUN_a0029604(c) >> 1;
}
