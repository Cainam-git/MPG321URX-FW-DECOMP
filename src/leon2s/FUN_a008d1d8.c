/* FUN_a008d1d8 (leon2s 0xa008d1d8-0xa008d280, 168 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Searches row hi of the halfword table DAT_a807d252 (rows of 10 entries; hi = 1 when v > 0x7ff, else 0) for
 * the value v, using the byte DAT_a8078c01 as the index from 0 up to the count in the byte DAT_a8078c02.
 * Returns 1 when found (DAT_a8078c01 then holds the index) and 0 otherwise.
 * Source form: hi is set in an if/else with the v <= 0x7ff arm first.
 */
extern unsigned char DAT_a8078c01;
extern unsigned char DAT_a8078c02;
extern unsigned short DAT_a807d252[][10];

int FUN_a008d1d8(unsigned short v)
{
    unsigned char hi;

    if (v <= 0x7ff)
        hi = 0;
    else
        hi = 1;
    for (DAT_a8078c01 = 0; DAT_a8078c01 < DAT_a8078c02; DAT_a8078c01++)
        if (DAT_a807d252[hi][DAT_a8078c01] == (unsigned short)v)
            return 1;
    return 0;
}
