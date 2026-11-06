/* FUN_a0029768 (leon2m 0xa0029768-0xa0029794, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns FUN_a0029638((unsigned char)(c + 0x38)) as an unsigned char: b = (c + 0x38) & 0xff; r = ((((b + 0x21) &
 * 0xff) + 0x0e) & 0xff) >> 1; returns (r * 3) & 0xff. Nothing in the image refers to it. It belongs to the chain of
 * byte routines FUN_a00295ec..FUN_a00297ec, each built on an earlier one; the routines it uses (FUN_a00295ec,
 * FUN_a00295f4, FUN_a0029604, FUN_a002961c, FUN_a0029638) are defined in this file and inlined.
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

unsigned char FUN_a0029638(unsigned char c)
{
    return FUN_a002961c(c) * 3;
}

unsigned char FUN_a0029768(unsigned char c)
{
    return FUN_a0029638(c + 0x38);
}
