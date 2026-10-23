/* FUN_a0143fe4 (leon2m 0xa0143fe4-0xa0143ff0, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the byte DAT_a802d990. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a0143fc4 and FUN_a0143ff0. Source form: a direct read of the extern symbol (sethi %hi +
 * load with the %lo offset in the retl delay slot).
 */
extern unsigned char DAT_a802d990;

unsigned char FUN_a0143fe4(void)
{
    return DAT_a802d990;
}
