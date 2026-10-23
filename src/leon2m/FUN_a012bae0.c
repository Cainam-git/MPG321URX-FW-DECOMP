/* FUN_a012bae0 (leon2m 0xa012bae0-0xa012baf0, 16 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Copies the byte DAT_a802e37f to p[0x15], p being the second argument; the first argument is not used. Nothing in
 * the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a012b9a8 and
 * FUN_a012baf0. Source form: the unused first parameter keeps p in %o1.
 */
extern unsigned char DAT_a802e37f;

void FUN_a012bae0(unsigned int unused, unsigned char *p)
{
    p[0x15] = DAT_a802e37f;
}
