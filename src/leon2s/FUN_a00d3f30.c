/* FUN_a00d3f30 (leon2s 0xa00d3f30-0xa00d3f54, 36 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Stores 1 (on != 0) or 0 to the byte DAT_a8078c31.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies in the code range
 * 0xa00d3eb0-0xa00d3fa0 that is followed by the unreferenced data 0xa00d3fa0-0xa00d649c (byte tables and '[HDR]'
 * format strings).
 */
extern unsigned char DAT_a8078c31;

void FUN_a00d3f30(unsigned char on)
{
    if (on)
        DAT_a8078c31 = 1;
    else
        DAT_a8078c31 = 0;
}
