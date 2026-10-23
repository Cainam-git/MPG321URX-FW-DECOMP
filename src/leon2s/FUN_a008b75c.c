/* FUN_a008b75c (leon2s 0xa008b75c-0xa008b838, 220 bytes, including the ret/restore tail), flags -mcpu=v8 -Os -g.
 * Does nothing for port > 3. en == 0: FUN_a00a71fc(port, 2, 4, 0). en != 0: when bit 2 of
 * FUN_a00a71b4(port, 2) is clear, calls FUN_a008b694(port != 0), FUN_a00a71fc(port, 2, 4, 4) and
 * FUN_a008b6f4(port != 0); then returns when (FUN_a00a71b4(port, 1) & 0xe) == 2, and otherwise, when the low
 * byte of FUN_a00a71b4(port, 0xf) is 0xf0, calls FUN_a00a71fc(port, 3, 2, 0) and FUN_a00a71fc(port, 3, 2, 2).
 * Same source form as FUN_a008b5d0.
 */
extern unsigned int FUN_a00a71b4(unsigned int param_1, unsigned int param_2);
extern void FUN_a00a71fc(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a008b694(unsigned char);
extern void FUN_a008b6f4(unsigned char);

void FUN_a008b75c(unsigned char port, unsigned char en)
{
    if (port > 3)
        return;
    if (en) {
        if (!(FUN_a00a71b4(port, 2) & 4)) {
            FUN_a008b694(port != 0);
            FUN_a00a71fc(port, 2, 4, 4);
            FUN_a008b6f4(port != 0);
        }
        if ((FUN_a00a71b4(port, 1) & 0xe) == 2)
            return;
        if ((unsigned char)FUN_a00a71b4(port, 0xf) == 0xf0) {
            FUN_a00a71fc(port, 3, 2, 0);
            FUN_a00a71fc(port, 3, 2, 2);
        }
    } else {
        FUN_a00a71fc(port, 2, 4, 0);
    }
}
