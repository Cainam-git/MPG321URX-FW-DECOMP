/* FUN_a00aa308 (leon2s 0xa00aa308-0xa00aa3a4, 156 bytes), flags -mcpu=v8 -Os -g.
 * Writes four registers of port 1 through FUN_a00a7cc0(1, reg, value), reg = 0x3d, 0x60, 0x83, 0xa6.
 * When byte 0 of the buffer DAT_a807d3d1 is 0xa0, the values are buffer bytes 3, 4, 5 and 6; otherwise
 * each value is 0x10. The last call is a tail call.
 */
extern unsigned char DAT_a807d3d1[];
extern void FUN_a00a7cc0(unsigned int, unsigned short, unsigned int);

void FUN_a00aa308(void)
{
    if (DAT_a807d3d1[0] == 0xa0) {
        FUN_a00a7cc0(1, 0x3d, DAT_a807d3d1[3]);
        FUN_a00a7cc0(1, 0x60, DAT_a807d3d1[4]);
        FUN_a00a7cc0(1, 0x83, DAT_a807d3d1[5]);
        FUN_a00a7cc0(1, 0xa6, DAT_a807d3d1[6]);
    } else {
        FUN_a00a7cc0(1, 0x3d, 0x10);
        FUN_a00a7cc0(1, 0x60, 0x10);
        FUN_a00a7cc0(1, 0x83, 0x10);
        FUN_a00a7cc0(1, 0xa6, 0x10);
    }
}
