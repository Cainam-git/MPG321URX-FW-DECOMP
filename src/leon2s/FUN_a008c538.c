/* FUN_a008c538 (leon2s 0xa008c538-0xa008c5d8, 160 bytes), flags -mcpu=v8 -Os -g.
 * (u8 port), returns unsigned int. v = FUN_a008b838(port), d = FUN_a008b850(port); the low byte of
 * FUN_a00ab690(port) selects k = 0x10e (1), 0x21c (2), 0x32a (3) or 0xa2 (any other value); returns
 * v * k / 64 * 1250 / d * 100 (unsigned).
 * Source form: one complete formula per case (as in FUN_a0089898 and FUN_a00aceec), default case first.
 */
extern int FUN_a008b838(unsigned char);
extern unsigned int FUN_a008b850(unsigned int param_1);
extern int FUN_a00ab690(unsigned char param_1);

unsigned int FUN_a008c538(unsigned char port)
{
    unsigned int v, d, r;

    v = FUN_a008b838(port);
    d = FUN_a008b850(port);
    switch (FUN_a00ab690(port) & 0xff) {
    default:
        r = v * 0xa2 / 64 * 1250 / d * 100;
        break;
    case 1:
        r = v * 0x10e / 64 * 1250 / d * 100;
        break;
    case 2:
        r = v * 0x21c / 64 * 1250 / d * 100;
        break;
    case 3:
        r = v * 0x32a / 64 * 1250 / d * 100;
        break;
    }
    return r;
}
