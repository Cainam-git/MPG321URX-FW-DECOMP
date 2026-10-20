/* FUN_a00a338c (leon2s 0xa00a338c-0xa00a33f4, 104 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a00a80cc(port, 1, 0x3b, bit, v) for bit = 0x20 then 0x10 with v = 1 when on is 1, else 0; the last
 * call is a tail call. Both arms are written out in full (form of FUN_a008da88).
 */
extern void FUN_a00a80cc(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);

void FUN_a00a338c(unsigned char port, unsigned char on)
{
    if (on == 1) {
        FUN_a00a80cc(port, 1, 0x3b, 0x20, 1);
        FUN_a00a80cc(port, 1, 0x3b, 0x10, 1);
    } else {
        FUN_a00a80cc(port, 1, 0x3b, 0x20, 0);
        FUN_a00a80cc(port, 1, 0x3b, 0x10, 0);
    }
}
