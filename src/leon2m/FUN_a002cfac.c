/* FUN_a002cfac (leon2m 0xa002cfac-0xa002cfb8, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the word DAT_a802b0c8. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a002cf78 and FUN_a002cfb8. Source form: a direct read of the extern symbol (sethi %hi +
 * load with the %lo offset in the retl delay slot).
 */
extern unsigned int DAT_a802b0c8;

unsigned int FUN_a002cfac(void)
{
    return DAT_a802b0c8;
}
