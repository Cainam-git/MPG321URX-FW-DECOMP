/* leon2s FUN_a00624b4 @ 0xa00624b4-0xa006250c (22 words), flags -mcpu=v8 -Os -g.
 * base = word DAT_a8078a3c (read before the flag test); if byte DAT_a8078a3a == 0 returns 0.
 * now = FUN_a00b2064(); d = now - base, or 0xffffffff - base + now when now < base; if d > 200:
 * DAT_a8078a3a = 0. Returns DAT_a8078a3a (reloaded). u8 result. The RAM word a3c is not volatile.
 * Source form: the wrap arm is the explicit '0xffffffff - base + now' with the '>=' arm first (a 'd--' or
 * 'd - 1' form is merged into one subx).
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
