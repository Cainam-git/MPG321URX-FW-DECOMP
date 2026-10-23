/* FUN_a00d66b0 (leon2s 0xa00d66b0-0xa00d66bc, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Stores v to the byte DAT_a80760ac.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word.
 */
extern unsigned char DAT_a80760ac;

void FUN_a00d66b0(unsigned char v)
{
    DAT_a80760ac = v;
}
