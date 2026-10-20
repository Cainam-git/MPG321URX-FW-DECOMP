/* leon2s FUN_a00cfab8 @ 0xa00cfab8-0xa00cfb20 (26 words), flags -mcpu=v8 -Os -g.
 * now = func_0xa0fc2064() (ROM call); d = now - _DAT_a8078bf8; _DAT_a8078bf8 = now; then for 15 u32 slots
 * ARR_a8078b60[0..14] (u8 index): slot = 0 if d > slot, else slot -= d. void (the firmware never sets %i0).
 * Source form: a plain RAM array (a volatile one reloads each slot 3 times), and the '> -> 0' arm first
 * (the firmware falls through to the clear and branches bleu to the subtract).
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
