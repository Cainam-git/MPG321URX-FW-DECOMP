/* FUN_a00dedb0 (leon2m 0xa00dedb0-0xa00dedbc, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the byte DAT_a802b0bd. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a00deda8 and FUN_a00dedbc. Source form: a direct read of the extern symbol (sethi %hi +
 * load with the %lo offset in the retl delay slot).
 */
extern unsigned char DAT_a802b0bd;

unsigned char FUN_a00dedb0(void)
{
    return DAT_a802b0bd;
}
