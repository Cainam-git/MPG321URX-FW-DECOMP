/* FUN_a012b354 (leon2m 0xa012b354-0xa012b370, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns byte (i & 0xff) * 0x16 + 3 of the array DAT_a802d8ae (byte +3 of 0x16-byte entry i counted from
 * 0xa802d8ae). Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies
 * between FUN_a012b328 and FUN_a012b370.
 */
extern unsigned char DAT_a802d8ae[];

unsigned char FUN_a012b354(unsigned int i)
{
    return DAT_a802d8ae[(i & 0xff) * 0x16 + 3];
}
