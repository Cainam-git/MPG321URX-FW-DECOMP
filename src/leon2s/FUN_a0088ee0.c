/* FUN_a0088ee0 (leon2s 0xa0088ee0-0xa0088f28, 72 bytes), flags -mcpu=v8 -Os -g.
 * When on is non-zero calls FUN_a00a78fc(port, 0x11, 0x1b) and FUN_a00a78fc(port, 0x66, 0x28); otherwise
 * FUN_a00a78fc(port, 0x11, 0). The last call is a tail call shared by both arms.
 */
extern void FUN_a00a78fc(unsigned char, unsigned short, unsigned char);

void FUN_a0088ee0(unsigned char port, unsigned char on)
{
    if (on != 0) {
        FUN_a00a78fc(port, 0x11, 0x1b);
        FUN_a00a78fc(port, 0x66, 0x28);
    } else {
        FUN_a00a78fc(port, 0x11, 0);
    }
}
