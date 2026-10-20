/* FUN_a00b115c (leon2s 0xa00b115c-0xa00b1224, 200 bytes), flags -mcpu=v8 -Os -g.
 * switch on mode: 0 -> FUN_a00a6c98(port, 0x56, 3, 0), FUN_a00a6c00(port, 0x57, 3);
 * 1 -> FUN_a00a6c98(port, 0x56, 2, 0), FUN_a00a6c98(port, 0x56, 1, 1), FUN_a00a6c00(port, 0x57, 7);
 * 2 -> FUN_a00a6c98(port, 0x56, 2, 1), FUN_a00a6c98(port, 0x56, 1, 0), FUN_a00a6c00(port, 0x57, 3);
 * other values do nothing. The final FUN_a00a6c00 call is a tail call; the range includes the trailing
 * ret/restore of the no-match path.
 */
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);

void FUN_a00b115c(unsigned char port, unsigned char mode)
{
    switch (mode) {
    case 0:
        FUN_a00a6c98(port, 0x56, 3, 0);
        FUN_a00a6c00(port, 0x57, 3);
        break;
    case 1:
        FUN_a00a6c98(port, 0x56, 2, 0);
        FUN_a00a6c98(port, 0x56, 1, 1);
        FUN_a00a6c00(port, 0x57, 7);
        break;
    case 2:
        FUN_a00a6c98(port, 0x56, 2, 1);
        FUN_a00a6c98(port, 0x56, 1, 0);
        FUN_a00a6c00(port, 0x57, 3);
        break;
    }
}
