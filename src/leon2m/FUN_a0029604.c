/* FUN_a0029604 (leon2m 0xa0029604-0xa002961c, 24 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns FUN_a00295f4(c) + 0x0e as an unsigned char: returns ((((c & 0xff) + 0x21) & 0xff) + 0x0e) & 0xff. Nothing
 * in the image refers to it. It belongs to the chain of byte routines FUN_a00295ec..FUN_a00297ec, each built on an
 * earlier one; the routines it uses (FUN_a00295ec, FUN_a00295f4) are defined in this file and inlined.
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
