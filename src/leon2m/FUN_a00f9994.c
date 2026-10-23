/* FUN_a00f9994 (leon2m 0xa00f9994-0xa00f99a0, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores v to the word *p. Nothing in the image refers to it: no call, branch, sethi/or constant or address word.
 * It lies between FUN_a00f9988 and FUN_a00f99a0. Source form: p points to volatile data; with a plain pointer the
 * store moves into the retl delay slot.
 */
void FUN_a00f9994(volatile unsigned int *p, unsigned int v)
{
    *p = v;
}
