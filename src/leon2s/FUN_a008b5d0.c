/* FUN_a008b5d0 (leon2s 0xa008b5d0-0xa008b694, 196 bytes), flags -mcpu=v8 -Os -g.
 * Does nothing for port > 3. With en clear: FUN_a00a71fc(port, 7, 0x10, 0). With en set: when bit 4 of
 * FUN_a00a71b4(port, 7) is clear, FUN_a00a71fc(port, 7, 0x10, 0x10); then, unless bits 1..3 of
 * FUN_a00a71b4(port, 1) equal 2, when the low byte of FUN_a00a71b4(port, 0xf) is 0xf0: FUN_a00a71fc(port, 3,
 * 2, 0) followed by FUN_a00a71fc(port, 3, 2, 2). The range includes the unreachable ret/restore at 0xa008b68c.
 */
extern unsigned int FUN_a00a71b4(unsigned int param_1, unsigned int param_2);
extern void FUN_a00a71fc(unsigned char, unsigned short, unsigned char, unsigned char);

void FUN_a008b5d0(unsigned char port, unsigned char en)
{
    if (port > 3)
        return;
    if (en) {
        if (!(FUN_a00a71b4(port, 7) & 0x10))
            FUN_a00a71fc(port, 7, 0x10, 0x10);
        if ((FUN_a00a71b4(port, 1) & 0xe) == 2)
            return;
        if ((unsigned char)FUN_a00a71b4(port, 0xf) == 0xf0) {
            FUN_a00a71fc(port, 3, 2, 0);
            FUN_a00a71fc(port, 3, 2, 2);
        }
    } else {
        FUN_a00a71fc(port, 7, 0x10, 0);
    }
}
