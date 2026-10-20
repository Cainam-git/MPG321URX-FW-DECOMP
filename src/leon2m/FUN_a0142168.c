/* leon2m FUN_a0142168 @ 0xa0142168  port id byte -> index into the 18-byte port entry table 0xA802E116
 * (hand; BYTE-EXACT at -mcpu=v8 -O3 -g).
 *
 * Maps 0x51 -> 0, 0x61 -> 1, 0x71 -> 2, 0x81 -> 3, 0xE8 -> 6, anything else -> 0xFF (returned as unsigned char).
 * FUN_a0142910 uses it to pick entry k = FUN_a0142168(port byte +0xa).
 * Callers: many (FUN_a0142518 twice, FUN_a0149588 seven times, FUN_a013dc6c, FUN_a0144144, FUN_a012f43c, ...).
 * BYTE-EXACT keys: a plain switch on the unsigned char with cases in ascending order (gcc builds the signed
 *   compare tree around 0x71), result in an unsigned char local.
 */
unsigned char FUN_a0142168(unsigned char t)
{
    unsigned char r;
    switch (t) {
    case 0x51: r = 0; break;
    case 0x61: r = 1; break;
    case 0x71: r = 2; break;
    case 0x81: r = 3; break;
    case 0xe8: r = 6; break;
    default: r = 0xff; break;
    }
    return r;
}
