/* FUN_a008f450 (leon2s 0xa008f450-0xa008f4d0, 128 bytes), flags -mcpu=v8 -Os -g.
 * Limit by mode: 8 -> 0x50, 0xa -> 0x40, 0xc -> 0x36, other -> 0x50. Tail-calls FUN_a00a8184(port, 1, 5, 0xc0,
 * 0xc0) when val (signed) is below the limit, otherwise FUN_a00a8184(port, 1, 5, 0xc0, 0).
 */
extern void FUN_a00a8184(unsigned char, unsigned char, unsigned short, unsigned int, unsigned int);

void FUN_a008f450(unsigned char port, unsigned char mode, int val)
{
    unsigned char lim;

    if (mode == 8)
        lim = 0x50;
    else if (mode == 0xa)
        lim = 0x40;
    else if (mode == 0xc)
        lim = 0x36;
    else
        lim = 0x50;
    if (val < lim)
        FUN_a00a8184(port, 1, 5, 0xc0, 0xc0);
    else
        FUN_a00a8184(port, 1, 5, 0xc0, 0);
}
