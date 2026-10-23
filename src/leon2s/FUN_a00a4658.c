/* leon2s FUN_a00a4658 @ 0xa00a4658-0xa00a47b0, -mcpu=v8 -Os -g.
 * void; it is the callback that FUN_a00a4610 puts into the timer descriptor DAT_a8079218. For i = 0 and 1:
 * DAT_a8079210[i] = 1 when bit 1 of FUN_a00a7fd8(i, 0, 9) is set, else 0. When that byte is 0, or when
 * ((u8)FUN_a0091a10(i) == 0 or bit 11 of word +0x14 of the 0x1c-byte record ARR_a807d580[i] is clear) and
 * (u8)FUN_a0091bac(i) == 0, the state word ARR_a807db6c[i] = 0. Otherwise: when DAT_a8079208[i] != 0 and
 * the state is > 1, state = 2 and DAT_a8079208[i] = 0; then the function DAT_a00b4cf8[state](i) is called
 * again as long as it returns non-zero (u8). After each pass the descriptor's period word = _DAT_a8078744
 * and CONV2HDMITX_UpdateInterface_4(&DAT_a8079218).
 */
struct TimerDesc { unsigned int periodic; unsigned int period; void (*fn)(void); };
struct Ch1c { unsigned char pad[0x14]; unsigned int w14; unsigned char rest[4]; };
extern struct TimerDesc DAT_a8079218;
extern unsigned int _DAT_a8078744;
extern unsigned char DAT_a8079210[];
extern unsigned char DAT_a8079208[];
extern unsigned int ARR_a807db6c[];
extern struct Ch1c ARR_a807d580[];
extern unsigned char (*DAT_a00b4cf8[])(unsigned char);
extern short FUN_a00a7fd8(unsigned int, unsigned short, unsigned short);
extern unsigned char FUN_a0091a10(unsigned char);
extern unsigned int FUN_a0091bac(unsigned char);
extern void CONV2HDMITX_UpdateInterface_4(struct TimerDesc *);

void FUN_a00a4658(void)
{
    unsigned char i;

    i = 0;
    do {
        if (FUN_a00a7fd8(i, 0, 9) & 2)
            DAT_a8079210[i] = 1;
        else
            DAT_a8079210[i] = 0;
        if (DAT_a8079210[i] == 0
            || (((unsigned char)FUN_a0091a10(i) == 0 || (ARR_a807d580[i].w14 & 0x800) == 0)
                && (unsigned char)FUN_a0091bac(i) == 0)) {
            ARR_a807db6c[i] = 0;
        } else {
            if (DAT_a8079208[i] != 0 && ARR_a807db6c[i] > 1) {
                ARR_a807db6c[i] = 2;
                DAT_a8079208[i] = 0;
            }
            while (DAT_a00b4cf8[ARR_a807db6c[i]](i))
                ;
        }
        DAT_a8079218.period = _DAT_a8078744;
        CONV2HDMITX_UpdateInterface_4(&DAT_a8079218);
        i++;
    } while (i <= 1);
}
