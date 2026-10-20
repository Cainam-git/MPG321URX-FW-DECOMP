/* FUN_a00b12cc (leon2s 0xa00b12cc-0xa00b1350, 132 bytes), flags -mcpu=v8 -Os -g.
 * When FUN_a00b12c4(port) returns non-zero: FUN_a00a6c00(port, 0x46, 0x13) and FUN_a00a6c98(port, 0xc0, 1, 1).
 * Else when on is non-zero: FUN_a00a6c00(port, 0x46, 0x17) and FUN_a00a6c98(port, 0xc0, 1, 1). Else
 * FUN_a00a6c00(port, 0x46, 0x13) and FUN_a00a6c98(port, 0xc0, 1, 0). The last call is a tail call.
 * on is a raw word parameter tested as a byte.
 */
extern unsigned char FUN_a00b12c4(unsigned char);
extern void FUN_a00a6c00(unsigned int, unsigned short, unsigned int);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned int, unsigned int);

void FUN_a00b12cc(unsigned char port, unsigned int on)
{
    if (FUN_a00b12c4(port) != 0) {
        FUN_a00a6c00(port, 0x46, 0x13);
        FUN_a00a6c98(port, 0xc0, 1, 1);
    } else if ((unsigned char)on != 0) {
        FUN_a00a6c00(port, 0x46, 0x17);
        FUN_a00a6c98(port, 0xc0, 1, 1);
    } else {
        FUN_a00a6c00(port, 0x46, 0x13);
        FUN_a00a6c98(port, 0xc0, 1, 0);
    }
}
