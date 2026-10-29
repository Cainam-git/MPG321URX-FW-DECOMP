/* FUN_a00297c0 (leon2m 0xa00297c0-0xa00297ec, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns FUN_a0029638((unsigned char)(c + 0x3f)) as an unsigned char: b = (c + 0x3f) & 0xff; r = ((((b + 0x21) &
 * 0xff) + 0x0e) & 0xff) >> 1; returns (r * 3) & 0xff. Nothing in the image refers to it. It belongs to the chain of
 * byte routines FUN_a00295ec..FUN_a00297ec, each built on an earlier one; the routines it uses (FUN_a00295ec,
 * FUN_a00295f4, FUN_a0029604, FUN_a002961c, FUN_a0029638) are defined in this file and inlined.
 * Compiler aid: the copy of FUN_a00295f4 keeps that routine's always-true test '(r & 0x80000000) == 0' (no
 * instructions; see FUN_a00295f4.c), which keeps the firmware's 'and 0xff' around its '+ 0x21' step.
 */
unsigned char FUN_a00295ec(unsigned char c)
{
    return c;
}

unsigned char FUN_a00295f4(unsigned char c)
{
    unsigned char r = FUN_a00295ec(c);

    if ((r & 0x80000000) == 0)
        r = r + 0x21;
    return r;
}

unsigned char FUN_a0029604(unsigned char c)
{
    return FUN_a00295f4(c) + 0xe;
}

unsigned char FUN_a002961c(unsigned char c)
{
    return FUN_a0029604(c) >> 1;
}

unsigned char FUN_a0029638(unsigned char c)
{
    return FUN_a002961c(c) * 3;
}

unsigned char FUN_a00297c0(unsigned char c)
{
    return FUN_a0029638(c + 0x3f);
}
