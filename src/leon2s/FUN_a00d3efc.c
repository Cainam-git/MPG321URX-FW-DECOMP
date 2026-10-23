/* FUN_a00d3efc (leon2s 0xa00d3efc-0xa00d3f30, 52 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns 2 when the byte DAT_a8078c38 is above 3, 0 when it is 0, else the byte DAT_a807d54f.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies in the code range
 * 0xa00d3eb0-0xa00d3fa0 that is followed by the unreferenced data 0xa00d3fa0-0xa00d649c (byte tables and '[HDR]'
 * format strings).
 */
extern unsigned char DAT_a8078c38;
extern unsigned char DAT_a807d54f;

unsigned char FUN_a00d3efc(void)
{
    unsigned char r = 0;

    if (DAT_a8078c38 > 3)
        r = 2;
    else if (DAT_a8078c38 != 0)
        r = DAT_a807d54f;
    return r;
}
