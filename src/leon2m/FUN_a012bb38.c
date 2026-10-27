/* FUN_a012bb38 (leon2m 0xa012bb38-0xa012bb94, 92 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets bit 30 of the first word of 0x24-byte entry i of DAT_a802d8dc to b & 1 when i is 0, clears it otherwise.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a012bb14 and FUN_a012bb94. Source form: a one-bit bit-field; the i == 0 arm indexes the array with i
 * (offset-0 load through the index register).
 */
struct RecF { unsigned int b31:1, b30:1, rest:30; };
struct Rec { struct RecF f; unsigned char p04[0x20]; };
extern struct Rec DAT_a802d8dc[];

void FUN_a012bb38(unsigned char i, unsigned int b)
{
    if (i == 0)
        DAT_a802d8dc[i].f.b30 = b;
    else
        DAT_a802d8dc[i].f.b30 = 0;
}
