/* FUN_a00dd6bc (leon2m 0xa00dd6bc-0xa00dd6c8, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the byte DAT_a802b0ad. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a00dd6b0 and FUN_a00dd6c8. Source form: a direct read of the extern symbol (sethi %hi +
 * load with the %lo offset in the retl delay slot).
 */
extern unsigned char DAT_a802b0ad;

unsigned char FUN_a00dd6bc(void)
{
    return DAT_a802b0ad;
}
