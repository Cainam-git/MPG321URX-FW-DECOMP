/* FUN_a008e004 (leon2s 0xa008e004-0xa008e050, 76 bytes, leaf), flags -mcpu=v8 -Os -g.
 * v = 0xc; when byte 0 of DAT_a807d3c1 is 0xa0, v = byte 3 of it for port 0 or byte 9 for port 1. Then
 * tail-calls FUN_a008dfe4(port, v).
 */
extern unsigned char DAT_a807d3c1[];
extern void FUN_a008dfe4(unsigned char, unsigned char);

void FUN_a008e004(unsigned char port)
{
    unsigned char v = 0xc;

    if (DAT_a807d3c1[0] == 0xa0) {
        if (port == 0)
            v = DAT_a807d3c1[3];
        else if (port == 1)
            v = DAT_a807d3c1[9];
    }
    FUN_a008dfe4(port, v);
}
