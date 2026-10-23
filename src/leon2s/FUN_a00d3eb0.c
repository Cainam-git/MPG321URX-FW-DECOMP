/* FUN_a00d3eb0 (leon2s 0xa00d3eb0-0xa00d3ef0, 64 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Stores a halfword to DAT_a80779dc: 10000 when v > 10000, 1000 when v is 0, else v.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies in the code range
 * 0xa00d3eb0-0xa00d3fa0 that is followed by the unreferenced data 0xa00d3fa0-0xa00d649c (byte tables and '[HDR]'
 * format strings).
 */
extern unsigned short DAT_a80779dc;

void FUN_a00d3eb0(unsigned short v)
{
    if (v > 10000)
        DAT_a80779dc = 10000;
    else if (v == 0)
        DAT_a80779dc = 1000;
    else
        DAT_a80779dc = v;
}
