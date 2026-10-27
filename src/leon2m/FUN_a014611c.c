/* FUN_a014611c (leon2m 0xa014611c-0xa014613c, 32 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 0x14000 when c is 0, otherwise 0x6000. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a0146108 and FUN_a014613c. Source form: a conditional expression
 * with the c == 0 arm first; GCC turns it into subx/and/add arithmetic.
 */
unsigned int FUN_a014611c(unsigned char c)
{
    return c == 0 ? 0x14000 : 0x6000;
}
