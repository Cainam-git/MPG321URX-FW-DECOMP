/* FUN_a0118174 (leon2m 0xa0118174-0xa0118180, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the byte DAT_a802c98d. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a0117f48 and FUN_a0118180. Source form: a direct read of the extern symbol (sethi %hi +
 * load with the %lo offset in the retl delay slot).
 */
extern unsigned char DAT_a802c98d;

unsigned char FUN_a0118174(void)
{
    return DAT_a802c98d;
}
