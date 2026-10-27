/* FUN_a0125318 (leon2m 0xa0125318-0xa0125334, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns byte +0xe of entry (i & 0xff) of the 0x16-byte table at 0x1a42a8. Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a01252fc and FUN_a0125334. Source form: the
 * same form as FUN_a01252fc with another offset.
 */
extern unsigned char DAT_001a42a8[];

unsigned char FUN_a0125318(unsigned int i)
{
    return DAT_001a42a8[(i & 0xff) * 0x16 + 0xe];
}
