/* leon2m FUN_a00d8034 @ 0xa00d8034-0xa00d8064 (12 words), flags -mcpu=v8 -O3 -g.
 * Code facts: returns 1 when (u8)(FUN_a014448c(0) - 0xb) < 5 (mode 0xb..0xf), else 0. The fw sets r = 0 / r = 1
 * per path and then 'and %i0,1,%i0' at the join, i.e. a 0/1 flag masked with 1. FUN_a014448c takes one argument
 * (clr %o0, u8 param) and returns u8.
 * Source form: the result is a u8 flag with 'return r & 1'; void params.
 * Compiler aids: none.
 */
extern unsigned char FUN_a014448c(unsigned char);

unsigned char FUN_a00d8034(void)
{
    unsigned char r;

    r = 0;
    if ((unsigned char)(FUN_a014448c(0) - 0xb) < 5)
        r = 1;
    return r & 1;
}
