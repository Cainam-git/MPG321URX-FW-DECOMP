/* leon2m FUN_a0121d4c @ 0xa0121d4c-0xa0121e3c (60 words), flags -mcpu=v8 -O3 -g.
 * Called by FUN_a00f446c, FUN_a00f59c4, FUN_a013bd00, FUN_a013bdb8, FUN_a013beb0 and FUN_a013c144.
 * t = FUN_a00fd820(port); returns 0 when t is one of 0x31, 0x41, 0x51, 0x61, 0x71, 0x81,
 * 0xc1, 0x91, 0xa1, 0xe1, 0xe2, 0xb1 or 0xe8, else 1. Source form: one || chain of equality tests in this
 * order (gcc evaluates them in pairs with xor/subx and orcc; the last test, 0xe8, stays a plain compare).
 */
extern unsigned char FUN_a00fd820(unsigned char);

int FUN_a0121d4c(unsigned char port)
{
    unsigned char t = FUN_a00fd820(port);

    if (t == 0x31 || t == 0x41 || t == 0x51 || t == 0x61 || t == 0x71 || t == 0x81 || t == 0xc1 ||
        t == 0x91 || t == 0xa1 || t == 0xe1 || t == 0xe2 || t == 0xb1 || t == 0xe8)
        return 0;
    return 1;
}
