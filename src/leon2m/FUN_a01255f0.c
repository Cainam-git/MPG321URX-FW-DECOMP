/* FUN_a01255f0 (leon2m 0xa01255f0-0xa012560c, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns byte +0xb of entry (i & 0xff) of the 0x16-byte table at 0x1a42a8. Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a01255dc and FUN_a012560c. Source form: the
 * same form as FUN_a01252fc with another offset.
 */
extern unsigned char DAT_001a42a8[];

unsigned char FUN_a01255f0(unsigned int i)
{
    return DAT_001a42a8[(i & 0xff) * 0x16 + 0xb];
}
