/* FUN_a012a128 (leon2m 0xa012a128-0xa012a164, 60 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the absolute difference DAT_a802ca9c[i] - DAT_a802ca5c[i] of two word arrays as a halfword. Nothing in
 * the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0129edc and
 * FUN_a012a164. Source form: __builtin_abs on the int difference.
 */
extern int DAT_a802ca5c[];
extern int DAT_a802ca9c[];
unsigned short FUN_a012a128(unsigned char i)
{
    return __builtin_abs(DAT_a802ca9c[i] - DAT_a802ca5c[i]);
}
