/* FUN_a0083648 (leon2s 0xa0083648-0xa00836f4, 172 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Status bit test by index. Indexes 1..4 are first mapped through the 2-bit fields of DAT_a80761a8
 * (field index-1, value + 1). The resulting index 0..6 selects one bit of the status byte DAT_a80789e0
 * (4, 8, 0x10, 0x20, 0x40, 1, 2; jump table); returns 1 when that bit is clear, 0 when set, and 2 for any
 * other index.
 * Source forms: the default case jumps past the result assignment, so the value 2 and the 0/1 result share
 * one register and one return; the selected bits go through an unsigned int temporary.
 */
extern unsigned char DAT_a80761a8;
extern unsigned char DAT_a80789e0;

int FUN_a0083648(int param_1)
{
    int r = 2;
    unsigned int b;

    if ((unsigned int)(param_1 - 1) <= 3)
        param_1 = ((DAT_a80761a8 >> (param_1 * 2 - 2)) & 3) + 1;
    switch (param_1) {
    case 0:
        b = DAT_a80789e0 & 4;
        break;
    case 1:
        b = DAT_a80789e0 & 8;
        break;
    case 2:
        b = DAT_a80789e0 & 0x10;
        break;
    case 3:
        b = DAT_a80789e0 & 0x20;
        break;
    case 4:
        b = DAT_a80789e0 & 0x40;
        break;
    case 5:
        b = DAT_a80789e0 & 1;
        break;
    case 6:
        b = DAT_a80789e0 & 2;
        break;
    default:
        goto out;
    }
    r = b == 0;
out:
    return r;
}
