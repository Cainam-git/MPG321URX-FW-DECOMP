/* FUN_a00e0e28 (leon2m 0xa00e0e28-0xa00e0e44, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 4 when v is 0xff, otherwise v unchanged. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between switchdataD_a00e0d30 and FUN_a00e0e44.
 */
unsigned int FUN_a00e0e28(unsigned int v)
{
    if (v == 0xff)
        return 4;
    return v;
}
