/* leon2m FUN_a01421c4 @ 0xa01421c4-0xa0142218 (21 words).
 * Maps x to a byte through a jump table: 0 -> 0x51, 1 -> 0x61, 2 -> 0x71, 3 -> 0x81, 6 -> 0xe8, any other value
 * -> 0xff. Inverse of FUN_a0142168. Called from FUN_a0136054, FUN_a0144574, FUN_a014464c, FUN_a0149588 and others.
 */
unsigned char FUN_a01421c4(unsigned char x)
{
    unsigned char r = 0xff;

    switch (x) {
    case 0:
        r = 0x51;
        break;
    case 1:
        r = 0x61;
        break;
    case 2:
        r = 0x71;
        break;
    case 3:
        r = 0x81;
        break;
    case 6:
        r = 0xe8;
        break;
    }
    return r;
}
