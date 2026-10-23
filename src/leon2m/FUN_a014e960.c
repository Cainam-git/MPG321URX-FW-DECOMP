/* FUN_a014e960 (leon2m 0xa014e960-0xa014e974, 20 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns byte i of the array DAT_a802a480. Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between FUN_a014e8ec and FUN_a014e974. Source form: an unsigned char index (and 0xff)
 * into an extern byte array.
 */
extern unsigned char DAT_a802a480[];

unsigned char FUN_a014e960(unsigned char i)
{
    return DAT_a802a480[i];
}
