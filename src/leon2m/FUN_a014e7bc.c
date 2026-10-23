/* FUN_a014e7bc (leon2m 0xa014e7bc-0xa014e7d0, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns byte i of the array DAT_a802cc18. Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between FUN_a014e768 and FUN_a014e7d0. Source form: an unsigned char index (and 0xff)
 * into an extern byte array.
 */
extern unsigned char DAT_a802cc18[];

unsigned char FUN_a014e7bc(unsigned char i)
{
    return DAT_a802cc18[i];
}
