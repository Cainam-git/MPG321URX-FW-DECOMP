/* FUN_a00d3f88 (leon2s 0xa00d3f88-0xa00d3fa0, 24 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Stores 1 to the byte DAT_a8078c34 and v to the byte DAT_a8078c33.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. The two stores use
 * separate sethi instructions: the bytes are separate symbols. It lies in the code range 0xa00d3eb0-0xa00d3fa0 that
 * is followed by the unreferenced data 0xa00d3fa0-0xa00d649c (byte tables and '[HDR]' format strings).
 */
extern unsigned char DAT_a8078c34;
extern unsigned char DAT_a8078c33;

void FUN_a00d3f88(unsigned char v)
{
    DAT_a8078c34 = 1;
    DAT_a8078c33 = v;
}
