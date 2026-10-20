/* FUN_a0072970 (leon2s 0xa0072970-0xa0072a4c, 220 bytes), flags -mcpu=v8 -Os -g.
 * Fills n words of buf: for sel 0 word i is FUN_a00618c0(0x9f0a0100 + off + i * 4), for sel 1
 * FUN_a00618c0(0x9f130100 + off + i * 4), for other sel 0.
 * Source form: a switch on sel (an if/else chain gives a different test order).
 */
extern unsigned int FUN_a00618c0(volatile unsigned int *param_1);

void FUN_a0072970(unsigned char sel, unsigned char off, unsigned int *buf, unsigned char n)
{
    unsigned char i;

    switch (sel) {
    case 0:
        for (i = 0; i < n; i++)
            buf[i] = FUN_a00618c0((volatile unsigned int *)(0x9f0a0100 + off + i * 4));
        break;
    case 1:
        for (i = 0; i < n; i++)
            buf[i] = FUN_a00618c0((volatile unsigned int *)(0x9f130100 + off + i * 4));
        break;
    default:
        for (i = 0; i < n; i++)
            buf[i] = 0;
        break;
    }
}
