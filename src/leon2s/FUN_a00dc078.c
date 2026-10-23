/* FUN_a00dc078 (leon2s 0xa00dc078-0xa00dc084, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Stores v to the byte DAT_a8078841.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. Same block of
 * one-statement accessors as FUN_a00dc034..FUN_a00dc09c.
 */
extern unsigned char DAT_a8078841;

void FUN_a00dc078(unsigned char v)
{
    DAT_a8078841 = v;
}
