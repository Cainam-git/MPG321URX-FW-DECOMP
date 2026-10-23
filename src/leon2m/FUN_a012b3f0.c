/* FUN_a012b3f0 (leon2m 0xa012b3f0-0xa012b404, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns byte i of the array DAT_a802cb00. Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between FUN_a012b39c and FUN_a012b404. Source form: an unsigned char index (and 0xff)
 * into an extern byte array.
 */
extern unsigned char DAT_a802cb00[];

unsigned char FUN_a012b3f0(unsigned char i)
{
    return DAT_a802cb00[i];
}
