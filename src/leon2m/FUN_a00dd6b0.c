/* FUN_a00dd6b0 (leon2m 0xa00dd6b0-0xa00dd6bc, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the byte DAT_a802b0ae. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a00dd660 and FUN_a00dd6bc. Source form: a direct read of the extern symbol (sethi %hi +
 * load with the %lo offset in the retl delay slot).
 */
extern unsigned char DAT_a802b0ae;

unsigned char FUN_a00dd6b0(void)
{
    return DAT_a802b0ae;
}
