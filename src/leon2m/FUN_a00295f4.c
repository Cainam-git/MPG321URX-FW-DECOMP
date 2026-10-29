/* FUN_a00295f4 (leon2m 0xa00295f4-0xa0029604, 16 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns FUN_a00295ec(c) + 0x21 as an unsigned char: returns (c + 0x21) & 0xff. Nothing in the image refers to it.
 * It belongs to the chain of byte routines FUN_a00295ec..FUN_a00297ec, each built on an earlier one; the routines
 * it uses (FUN_a00295ec) are defined in this file and inlined.
 * Compiler aid: the step '+ 0x21' is written under 'if ((r & 0x80000000) == 0)', a test that is always true for the
 * unsigned char r and emits no instructions. combine removes it, but while combine runs the test still splits the
 * code into separate blocks, so the 'and 0xff' before and after that step stays as in the firmware (written
 * unconditionally, combine merges the masks, and in the routines built on this one + 0x21 + 0x0e into one + 0x2f).
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
