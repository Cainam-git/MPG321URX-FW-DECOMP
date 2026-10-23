/* FUN_a00f9988 (leon2m 0xa00f9988-0xa00f9994, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns the word *p. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It
 * lies between switchdataD_a00f9940 and FUN_a00f9994. Source form: p points to volatile data; with a plain pointer
 * the load moves into the retl delay slot.
 */
unsigned int FUN_a00f9988(volatile unsigned int *p)
{
    return *p;
}
