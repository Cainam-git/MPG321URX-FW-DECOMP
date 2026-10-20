/* leon2s FUN_a00cfab8 @ 0xa00cfab8-0xa00cfb20 (26 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/26 mismatches.
 * Code facts: timer tick: now = func_0xa0fc2064() (ROM tick); d = now - _DAT_a8078bf8; _DAT_a8078bf8 = now;
 * then for 15 u32 countdown slots ARR_a8078b60[0..14] (u8 index): slot = 0 if d > slot, else slot -= d.
 * void (the fw never sets %i0; the draft returned 0).
 * Fixes vs the autoc draft (75.86): plain RAM array (the draft's volatile reloaded each slot 3 times),
 * void, and the '> -> 0' arm first (the fw falls through to the clear and branches bleu to the subtract).
 * Aids: none.
 */
extern unsigned int _DAT_a8078bf8;
extern unsigned int ARR_a8078b60[];
extern unsigned int func_0xa0fc2064(void);

void FUN_a00cfab8(void)
{
    unsigned int now;
    unsigned int d;
    unsigned char i;

    now = func_0xa0fc2064();
    d = now - _DAT_a8078bf8;
    _DAT_a8078bf8 = now;
    for (i = 0; i < 15; i++) {
        if (d > ARR_a8078b60[i])
            ARR_a8078b60[i] = 0;
        else
            ARR_a8078b60[i] -= d;
    }
}
