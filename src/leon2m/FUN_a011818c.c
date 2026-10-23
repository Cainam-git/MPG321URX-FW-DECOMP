/* FUN_a011818c (leon2m 0xa011818c-0xa0118198, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns the byte DAT_a802c98c. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a0118180 and FUN_a0118198. Source form: a direct read of the extern symbol (sethi %hi +
 * load with the %lo offset in the retl delay slot).
 */
extern unsigned char DAT_a802c98c;

unsigned char FUN_a011818c(void)
{
    return DAT_a802c98c;
}
