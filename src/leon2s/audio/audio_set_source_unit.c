/* audio_set_source_unit  (FUN_a008aba8)
 *
 * Assign an audio source to an audio unit (the DP sources 4..7 have fixed units 0..3).
 *   src: audio source id: 1, 2, 3, 0x11, 0x13, 4..7 (DP), 8 / 10 (HDMI 2.0), 12 / 14 (HDMI 2.1)
 *   unit: audio unit 0..3; for the ids 4..7 only the bit number cleared in 0xCF014770
 * Note: Ids 1, 2, 3, 8, 10, 12, 14, 0x11, 0x13 get the unit number; 4..7 ignore it; every id but 2 also
 *   changes 0xCF014770; other ids change nothing.
 * Name basis: derived - writes the 2-bit fields read back by audio_get_source_unit (0xCF0111C0..D4)
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. Leaf.
 * Source forms the exact build depends on: the cases are written in the firmware's block order (8, 10, 12,
 * 14, 4..7, 1, 2, 3); in the cases 1 and 3 the low part of the value is an unsigned char (keeps the
 * '| 0x20' before the '| unit << 6'); the cases 1, 0x11, 2, 3 and 0x13 cast unit to unsigned char.
 */
#define R(a) (*(volatile unsigned int *)(a))

/*
 * Assign an audio source to an audio unit by writing the unit number into the source's own 2-bit field.
 *
 *   src   audio source id; any id not handled below changes nothing
 *   unit  audio unit 0..3
 *
 * Each source has a fixed field in one of the registers 0xCF0111C0..0xCF0111D4: bits 6..7 for the first
 * source of a register, bits 2..3 for the second (audio_get_source_unit reads them back):
 *   8 / 12 (HDMI 2.0 / 2.1 receiver 0), 1, 0x11, 3, 0x13   bits 6..7 take unit
 *   10 / 14 (HDMI 2.0 / 2.1 receiver 1), 2                  bits 2..3 take unit
 *   4, 5, 6, 7 (the DP sources)                             the field is set to the fixed unit 0, 1, 2, 3
 *                                                           and unit is not written into it
 * Besides the field, every case except 2 changes register 0xCF014770: it clears bit "unit" (for 3 and 0x13
 * it sets the bits given by unit). The extra bits set in the field registers (0x20, 0x02, 0xa0, 0x06, 0x0e,
 * 0x10) are written as shown in the code; their meaning is not documented.
 * Callers: audio_route_source.
 */
void audio_set_source_unit(unsigned char src, unsigned int unit)
{
    switch (src) {
    case 8:
        R(0xcf014770) &= ~(1 << unit);
        R(0xcf0111cc) = ((R(0xcf0111cc) & 0x3f) | (unit << 6) | 0x20) & 0xff;
        break;
    case 10:
        R(0xcf014770) &= ~(1 << unit);
        R(0xcf0111cc) = ((R(0xcf0111cc) & ~0xc) | (unit << 2) | 2) & 0xff;
        break;
    case 12:
        R(0xcf014770) &= ~(1 << unit);
        R(0xcf0111d0) = ((R(0xcf0111d0) & 0x3f) | (unit << 6) | 0x20) & 0xff;
        break;
    case 14:
        R(0xcf014770) &= ~(1 << unit);
        R(0xcf0111d0) = ((R(0xcf0111d0) & ~0xc) | (unit << 2) | 2) & 0xff;
        break;
    /* DP sources: fixed units 0 (src 4), 1 (src 5), 2 (src 6), 3 (src 7) */
    case 4:
        R(0xcf014770) &= ~(1 << unit);
        R(0xcf0111c4) = (R(0xcf0111c4) & 0x3f) | 0x20;
        break;
    case 5:
        R(0xcf014770) &= ~(1 << unit);
        R(0xcf0111c4) = (R(0xcf0111c4) | 6) & 0xf7;
        break;
    case 6:
        R(0xcf014770) &= ~(1 << unit);
        R(0xcf0111c8) = (R(0xcf0111c8) & 0x3f) | 0xa0;
        break;
    case 7:
        R(0xcf014770) &= ~(1 << unit);
        R(0xcf0111c8) = (R(0xcf0111c8) | 0xe) & 0xff;
        break;
    case 1:
    case 0x11:
        R(0xcf014770) &= ~(1 << (unsigned char)unit);
        R(0xcf0111c0) = (unsigned char)((R(0xcf0111c0) & 0x1f) | 0x20) | ((unsigned char)unit << 6);
        break;
    case 2:
        R(0xcf0111c0) = ((R(0xcf0111c0) | 0x10) & 0xf3) | ((unsigned char)unit << 2);
        break;
    case 3:
    case 0x13:
        R(0xcf014770) |= (unsigned char)unit;
        R(0xcf0111d4) = (unsigned char)((R(0xcf0111d4) & 0x1f) | 0x20) | ((unsigned char)unit << 6);
        break;
    }
}
