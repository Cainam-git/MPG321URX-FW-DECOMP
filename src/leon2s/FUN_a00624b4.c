/* leon2s FUN_a00624b4 @ 0xa00624b4-0xa006250c (22 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp 0/22 mismatches.
 * Code facts: timeout check. base = word DAT_a8078a3c (read before the flag test); if byte
 * DAT_a8078a3a == 0 return 0. now = FUN_a00b2064() (tick); d = now - base, or 0xffffffff - base
 * + now when the tick wrapped (now < base); if d > 200: DAT_a8078a3a = 0. Returns DAT_a8078a3a
 * (reloaded). u8 result.
 * Fix vs the autoc draft (84.38 band): the wrap arm is the explicit '0xffffffff - base + now'
 * with the '>=' arm first (a 'd--' or 'd - 1' form is merged into one subx: 63.64); no volatile
 * on the RAM word a3c (the draft had it). Aids: none.
 */
extern unsigned char DAT_a8078a3a;
extern unsigned int DAT_a8078a3c;
extern unsigned int FUN_a00b2064(void);

unsigned char FUN_a00624b4(void)
{
    unsigned int now;
    unsigned int d;
    unsigned int base = DAT_a8078a3c;

    if (DAT_a8078a3a == 0)
        return 0;
    now = FUN_a00b2064();
    if (now >= base)
        d = now - base;
    else
        d = 0xffffffff - base + now;
    if (d > 200)
        DAT_a8078a3a = 0;
    return DAT_a8078a3a;
}
