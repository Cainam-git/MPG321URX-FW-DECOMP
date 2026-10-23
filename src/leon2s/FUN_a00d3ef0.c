/* FUN_a00d3ef0 (leon2s 0xa00d3ef0-0xa00d3efc, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns the halfword DAT_a80779dc.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies in the code range
 * 0xa00d3eb0-0xa00d3fa0 that is followed by the unreferenced data 0xa00d3fa0-0xa00d649c (byte tables and '[HDR]'
 * format strings).
 */
extern unsigned short DAT_a80779dc;

unsigned short FUN_a00d3ef0(void)
{
    return DAT_a80779dc;
}
