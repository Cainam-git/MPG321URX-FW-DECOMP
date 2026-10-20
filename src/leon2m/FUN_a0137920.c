/* leon2m FUN_a0137920 @ 0xa0137920-0xa013797c (23 words). BYTE-EXACT: -mcpu=v8 -O3 -g, jf 100 match=True,
 * rawcmp 0/23.
 * What it does: mailbox command 0x12 sender. A 4-byte message buffer m is cleared (one word store
 * 'clr [%fp-16]'), then m[0] = 2 for ch 0, 3 for ch 1, 0xff for any other ch; when m[0] is not 0xff the
 * 1-byte message { m[0] } goes through the inter-processor mailbox FUN_a01370dc(cmd 0x12, length 1, m, 0)
 * (the callee uses only its first three arguments; the fw caller still passes 0 in %o3).
 * Callers: GlobalModeHandler FUN_a0131518 and FUN_a0151aa4 (twice). This does
 * not look at the input: it only tells the other processor which channel (code 2 or 3) is active.
 * ch is an int (no 'and 0xff' on %i0 in the fw; the caller src/leon2m/FUN_a0131518.c declares it
 * unsigned char, which is the same register value for 0/1).
 * Lever: the switch writes the code STRAIGHT INTO the buffer (m[0] = 2 / 3 / 0xff) and the test
 * reads m[0] back; a separate 'v' local gives the same instructions with 'mov 2' after the clr (block-0
 * order) and needed a scheduling barrier. This form needs no aid. Aids: none. volatile: none.
 */
extern void FUN_a01370dc(int cmd, int len, unsigned char *buf, int flag);

void FUN_a0137920(int ch)
{
    unsigned char m[4] = { 0, 0, 0, 0 };

    switch (ch) {
    case 0: m[0] = 2; break;
    case 1: m[0] = 3; break;
    default: m[0] = 0xff; break;
    }
    if (m[0] != 0xff)
        FUN_a01370dc(0x12, 1, m, 0);
}
