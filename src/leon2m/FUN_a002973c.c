/* FUN_a002973c (leon2m 0xa002973c-0xa0029768, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns FUN_a0029638((unsigned char)(c + 0x33)) as an unsigned char: b = (c + 0x33) & 0xff; r = ((((b + 0x21) &
 * 0xff) + 0x0e) & 0xff) >> 1; returns (r * 3) & 0xff. Nothing in the image refers to it. It belongs to the chain of
 * byte routines FUN_a00295ec..FUN_a00297ec, each built on an earlier one; the routines it uses (FUN_a00295ec,
 * FUN_a00295f4, FUN_a0029604, FUN_a002961c, FUN_a0029638) are defined in this file and inlined.
 * Source form: the copies of FUN_a00295f4 and FUN_a0029604 are written as in their own files: the inner result in
 * an unsigned char local r, then 'r += k' as its own statement and 'return r' (the firmware's 'and 0xff' steps).
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

unsigned char FUN_a002973c(unsigned char c)
{
    return FUN_a0029638(c + 0x33);
}
