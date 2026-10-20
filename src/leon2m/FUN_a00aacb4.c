/* leon2m FUN_a00aacb4 @ 0xa00aacb4-0xa00aad30 (31 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a0095fb0,
 * FUN_a0099440, FUN_a009bfb4, FUN_a009c22c, FUN_a00a01fc.
 * Calls FUN_a0146a80(0x14, row * 2 + 6, 0xd, c, 0) with c = 0x792 when FUN_a00aa520(row) returns non-zero and
 * c = 0x292 otherwise. Then, when a is 2 and row is 1, tail-calls FUN_a00b6d58.
 * Exact form: the zero test is written first; the two tests on a and row are nested ifs (an && merges them into
 * flag arithmetic).
 */
extern unsigned char FUN_a00aa520(unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a00b6d58(void);

void FUN_a00aacb4(unsigned char a, unsigned char row)
{
    if (!FUN_a00aa520(row))
        FUN_a0146a80(0x14, row * 2 + 6, 0xd, 0x292, 0);
    else
        FUN_a0146a80(0x14, row * 2 + 6, 0xd, 0x792, 0);
    if (a == 2)
        if (row == 1)
            FUN_a00b6d58();
}
