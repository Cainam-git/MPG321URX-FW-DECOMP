/* FUN_a00e0268 (leon2m 0xa00e0268-0xa00e02a0, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the word at byte offset off from base i of the local array {0xc0020000, 0xc0030000, 0xc0040000}. Nothing
 * in the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00e0234 and
 * FUN_a00e02a0. Source form: an initialised local array (built on the stack); the word is read through a volatile
 * pointer.
 */
unsigned int FUN_a00e0268(unsigned int i, unsigned int off)
{
    unsigned int t[3] = { 0xc0020000, 0xc0030000, 0xc0040000 };

    return *(volatile unsigned int *)(t[i] + off);
}
