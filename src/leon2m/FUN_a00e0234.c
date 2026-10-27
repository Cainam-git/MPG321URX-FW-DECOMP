/* FUN_a00e0234 (leon2m 0xa00e0234-0xa00e0268, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns element i of the local word array {0xc0020000, 0xc0030000, 0xc0040000}. Nothing in the image refers to
 * it: no call, branch, sethi/or constant or address word. It lies between FUN_a00e0228 and FUN_a00e0268. Source
 * form: an initialised local array (built on the stack).
 */
unsigned int FUN_a00e0234(unsigned int i)
{
    unsigned int t[3] = { 0xc0020000, 0xc0030000, 0xc0040000 };

    return t[i];
}
