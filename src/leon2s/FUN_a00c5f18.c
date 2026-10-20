/* FUN_a00c5f18 (leon2s 0xa00c5f18-0xa00c5fb0, 152 bytes), flags -mcpu=v8 -Os -g.
 * Compares bit param_1 of the byte DAT_a8078c58 with the 8-bit value param_2. When they differ, sets the bit
 * (param_2 != 0) or clears it, ORs a bit into the byte DAT_a80788d2 (1 << param_1 for param_1 0..3, 0x10 for
 * param_1 == 4, 0x20 above) and calls FUN_a00c5da8(param_1, param_2). Always ends with a tail call to
 * FUN_a00c5d34(param_1, param_2).
 * Source forms: the byte is copied into an unsigned int before the masked shift; the value ORed into DAT_a80788d2 is chosen
 * in an if/else chain (port == 4 tested before the default) and ORed in once.
 */
extern unsigned char DAT_a8078c58;
extern unsigned char DAT_a80788d2;
extern void FUN_a00c5da8(unsigned int param_1, unsigned int param_2);
extern void FUN_a00c5d34(unsigned char param_1, unsigned char param_2);

void FUN_a00c5f18(unsigned int param_1, unsigned int param_2)
{
    unsigned char port = param_1;
    unsigned char v = param_2;
    int m = 1 << port;
    unsigned char c = DAT_a8078c58;
    unsigned int w = c;
    unsigned char b;

    if (((int)(w & m) >> port) != v) {
        if (v != 0)
            DAT_a8078c58 = m | c;
        else
            DAT_a8078c58 = c & ~m;
        if (port < 4)
            b = 1 << port;
        else if (port == 4)
            b = 0x10;
        else
            b = 0x20;
        DAT_a80788d2 |= b;
        FUN_a00c5da8(port, v);
    }
    FUN_a00c5d34(param_1, param_2);
}
