/* FUN_a0088a80 (leon2s 0xa0088a80-0xa0088af0, 112 bytes), flags -mcpu=v8 -Os -g.
 * For a port byte of 0, 2, 3, 4 or 1 calls FUN_a0083710 with that value and returns 1 if bit 2 (0x4) of the
 * returned status byte is set, else 0; any other value returns 0 without a call. Same code shape as
 * FUN_a0088af0: the if/else chain tests the values in the order 0, 2, 3, 4, 1 and the result local starts
 * at 0 and is set to 1 only on success.
 */
extern unsigned char FUN_a0083710(int param_1);

int FUN_a0088a80(unsigned char param_1)
{
    unsigned char l0;
    
    param_1 = param_1 & 0xff;
    l0 = 0;
    if (param_1 == 0) {
        if (FUN_a0083710(0) & 4) {
            l0 = 1;
        }
    } else if (param_1 == 2) {
        if (FUN_a0083710(2) & 4) {
            l0 = 1;
        }
    } else if (param_1 == 3) {
        if (FUN_a0083710(3) & 4) {
            l0 = 1;
        }
    } else if (param_1 == 4) {
        if (FUN_a0083710(4) & 4) {
            l0 = 1;
        }
    } else if (param_1 == 1) {
        if (FUN_a0083710(1) & 4) {
            l0 = 1;
        }
    }
    return l0 & 1;
}
