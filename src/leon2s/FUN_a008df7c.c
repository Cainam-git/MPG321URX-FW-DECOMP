/* FUN_a008df7c (leon2s 0xa008df7c-0xa008dfe4, 104 bytes), flags -mcpu=v8 -Os -g.
 * When on is non-zero and bit 4 of word 0 of the 7-word record port of ARR_a807d580 is set, tail-calls
 * FUN_a00a8054(port, 1, 5, 0xd); otherwise tail-calls FUN_a00a80cc(port, 1, 5, 1, v) with v = 1 when on is
 * non-zero, 0 otherwise.
 * Source form: three separate calls in nested if/else arms, the clear-bit test first (one shared call with a flag
 * variable gives a frameless function).
 */
extern unsigned int ARR_a807d580[];
extern void FUN_a00a80cc(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);

void FUN_a008df7c(unsigned char port, unsigned char on)
{
    if (on != 0) {
        if (!(ARR_a807d580[port * 7] & 0x10))
            FUN_a00a80cc(port, 1, 5, 1, 1);
        else
            FUN_a00a8054(port, 1, 5, 0xd);
    } else {
        FUN_a00a80cc(port, 1, 5, 1, 0);
    }
}
