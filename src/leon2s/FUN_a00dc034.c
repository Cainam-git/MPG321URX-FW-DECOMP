/* FUN_a00dc034 (leon2s 0xa00dc034-0xa00dc040, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Stores v to the byte DAT_a8076099.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. Same block of
 * one-statement accessors as FUN_a00dc034..FUN_a00dc09c.
 */
extern unsigned char DAT_a8076099;

void FUN_a00dc034(unsigned char v)
{
    DAT_a8076099 = v;
}
