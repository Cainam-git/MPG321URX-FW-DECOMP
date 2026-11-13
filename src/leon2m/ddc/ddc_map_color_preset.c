/* ddc_map_color_preset  (FUN_a00cf194)
 *
 * Map a DDC/CI colour preset code to the colour temperature setting value.
 *   preset_code
 * Returns: setting value, 0 when not known
 * Note: Uncalled copy of the mapping in ddc_apply_maker_vcp_set (maker code 0xFE, sub-code 0x14, byte 7 = 1):
 *   5 -> 1, 6 -> 4, 8 -> 7, 0x0B -> 0x17.
 * Name basis: derived - the same mapping is inline in the colour arm (sub-code 0x14 of the maker code 0xFE) of
 *   ddc_apply_maker_vcp_set
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O2 -g (section default). Nothing in the image calls this routine.
 * Source form: r = 0 before a switch with cases 5, 6, 8, 0xb in ascending order; the result is returned as
 * r & 0x17.
 */
/*
 * Map the colour preset code of a DDC/CI request to the colour temperature setting value: 5 -> 1, 6 -> 4,
 * 8 -> 7, 0xB -> 0x17, any other code -> 0. ddc_apply_maker_vcp_set has the same mapping inline, for the colour
 * request (sub-code 0x14 of the maker code 0xFE, value byte 1); there the code is request byte 5.
 */
unsigned char ddc_map_color_preset(unsigned char preset_code)
{
    unsigned char setting = 0;

    switch (preset_code) {
    case 5:
        setting = 1;
        break;
    case 6:
        setting = 4;
        break;
    case 8:
        setting = 7;
        break;
    case 0xb:
        setting = 0x17;
        break;
    }
    return setting & 0x17;
}
