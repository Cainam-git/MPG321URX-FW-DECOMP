/* FUN_a00a1f84 (leon2s 0xa00a1f84-0xa00a2010, 140 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Maps code 4 / 5 / 6 / 7 to v = 0 / 1 / 2 / 3 (other codes 0). For sel 0 writes v into bits 0-1 of hardware
 * register 0xcf0147f0, otherwise into bits 4-5; the other bits of the low byte are kept, bits 8-31 cleared.
 */
#define REG_47F0 (*(volatile unsigned int *)0xcf0147f0)

void FUN_a00a1f84(unsigned char sel, unsigned char code)
{
    unsigned char v;

    switch (code) {
    case 4: v = 0; break;
    case 5: v = 1; break;
    case 6: v = 2; break;
    case 7: v = 3; break;
    default: v = 0; break;
    }
    if (sel == 0)
        REG_47F0 = (REG_47F0 & 0xfc) | v;
    else
        REG_47F0 = (REG_47F0 & 0xcf) | (v << 4);
}
