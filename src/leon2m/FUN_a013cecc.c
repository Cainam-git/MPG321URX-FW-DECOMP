/* leon2m FUN_a013cecc @ 0xa013cecc-0xa013cf84 (46 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a013c144.
 * Leaf. Returns 1 when v is within the limit selected by byte 0xa802e1a7 (0: v == 0; 1, 2, 5: v <= 1;
 * 3, 6: v <= 2; 4, 7: v <= 3; other values: no limit passes), or when v == 3 and bit 21 (0x200000) of word
 * 0xa802e3d0 is set; otherwise 0. The limits are a switch with a jump table (0xdc89c).
 */
extern unsigned char DAT_a802e1a7;
extern unsigned int DAT_a802e3d0;

unsigned char FUN_a013cecc(unsigned char v)
{
    unsigned char r = 0;

    switch (DAT_a802e1a7) {
    case 0:
        if (v == 0)
            r = 1;
        break;
    case 1:
    case 2:
    case 5:
        if (v <= 1)
            r = 1;
        break;
    case 3:
    case 6:
        if (v <= 2)
            r = 1;
        break;
    case 4:
    case 7:
        if (v <= 3)
            r = 1;
        break;
    }
    if (v == 3 && (DAT_a802e3d0 & 0x200000))
        r = 1;
    return r & 1;
}
