/* FUN_a008da88 (leon2s 0xa008da88-0xa008db4c, 196 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a00a80cc(port, 1, 10, bit, v) for bit = 4, 8, 0x10, 0x20 with v = 1 when on is non-zero, else 0;
 * the last call is a tail call. Both arms are written out in full (four calls each).
 */
extern void FUN_a00a80cc(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);

void FUN_a008da88(unsigned char port, unsigned char on)
{
    if (on != 0) {
        FUN_a00a80cc(port, 1, 10, 4, 1);
        FUN_a00a80cc(port, 1, 10, 8, 1);
        FUN_a00a80cc(port, 1, 10, 0x10, 1);
        FUN_a00a80cc(port, 1, 10, 0x20, 1);
    } else {
        FUN_a00a80cc(port, 1, 10, 4, 0);
        FUN_a00a80cc(port, 1, 10, 8, 0);
        FUN_a00a80cc(port, 1, 10, 0x10, 0);
        FUN_a00a80cc(port, 1, 10, 0x20, 0);
    }
}
