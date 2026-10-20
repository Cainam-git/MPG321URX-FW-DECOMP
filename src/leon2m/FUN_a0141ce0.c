/* leon2m FUN_a0141ce0 @ 0xa0141ce0-0xa0141d50 (28 words).
 * Returns bits 12-15 of the first halfword of the 18-byte record selected by t: 0x51 -> 0xa802e116,
 * 0x61 -> 0xa802e128, 0x71 -> 0xa802e13a, 0x81 -> 0xa802e14c; any other t returns 8. Each record is a separate
 * extern (own address constant). Called from FUN_a01302e0, FUN_a0130438 and others.
 */
extern unsigned short DAT_a802e116, DAT_a802e128, DAT_a802e13a, DAT_a802e14c;

int FUN_a0141ce0(unsigned char t)
{
    int r;

    switch (t) {
    case 0x51: r = DAT_a802e116 >> 12; break;
    case 0x61: r = DAT_a802e128 >> 12; break;
    case 0x71: r = DAT_a802e13a >> 12; break;
    case 0x81: r = DAT_a802e14c >> 12; break;
    default: r = 8; break;
    }
    return r;
}
