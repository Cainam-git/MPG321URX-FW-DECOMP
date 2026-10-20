/* leon2m FUN_a013b7e0 @ 0xa013b7e0-0xa013b86c (35 words), flags -mcpu=v8 -O3 -g.
 * Code facts: now = ROM func_0x4008d588() (u16 tick); d = now - u16 0xa802cbd0; u16 0xa802cbd0 = now; each of the
 * 9 u16 down-counters at 0xa802cbbe (i = 0..8, u8) is reduced by d, clamped at 0; returns counter[idx].
 * The new time is the ROM call's return value (fw sub %o0 after the call, sth %o0). Aids: none.
 */
extern unsigned short DAT_a802cbd0;
extern unsigned short ARR_a802cbbe[];
extern unsigned short func_0x4008d588(void);

unsigned short FUN_a013b7e0(int idx)
{
    unsigned short now = func_0x4008d588();
    unsigned short d = now - DAT_a802cbd0;
    unsigned char i;

    DAT_a802cbd0 = now;
    for (i = 0; i <= 8; i++) {
        if (ARR_a802cbbe[i] < d)
            ARR_a802cbbe[i] = 0;
        else
            ARR_a802cbbe[i] -= d;
    }
    return ARR_a802cbbe[idx];
}
