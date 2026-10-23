/* FUN_a00dc264 (leon2s 0xa00dc264-0xa00dc270, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Stores v to the byte DAT_a8078832.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. Same form as the
 * one-statement accessors FUN_a00dc034..FUN_a00dc09c.
 */
extern unsigned char DAT_a8078832;

void FUN_a00dc264(unsigned char v)
{
    DAT_a8078832 = v;
}
