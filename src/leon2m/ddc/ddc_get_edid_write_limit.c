/* ddc_get_edid_write_limit  (FUN_a00cf288)
 *
 * Return the byte limit of an EDID write block sent over DDC/CI.
 *   offset_low: offset
 *   size_code: the byte that lands at EDID offset 0x7E (0, 1, 2 or more)
 *   edid_end: out: limit
 * Note: Uncalled copy of the limit used by the 0xEF arm of ddc_apply_maker_vcp_set (0x80 .. 0x200).
 * Name basis: descriptive - same values as halfword h2 of record 0xA802D250 in the 0xEF arm
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O2 -g (section default). Nothing in the image calls this routine.
 * Source form: plain if / else chain storing the halfword through the pointer.
 */
/*
 * Work out the end (length) of the EDID that a factory tool is writing in pieces, from the offset of a piece.
 *   offset_low  low byte of the offset of the piece in the EDID
 *   size_code   the byte that lands at EDID offset 0x7E (0, 1, 2 or more)
 *   edid_end    out: the length
 * Pieces below offset 0x60 give 0x80. The piece at 0x60 gives 0x80, 0x100, 0x180 or 0x200 for size_code 0, 1, 2
 * or more. Pieces above 0x60 leave *edid_end unchanged. ddc_apply_maker_vcp_set (sub-code 0xEF) has the same code
 * inline, where size_code is request byte 0x26.
 */
void ddc_get_edid_write_limit(unsigned char offset_low, unsigned char size_code, unsigned short *edid_end)
{
    if (offset_low < 0x60)
        *edid_end = 0x80;
    else if (offset_low == 0x60) {
        if (size_code == 0)
            *edid_end = 0x80;
        else if (size_code == 1)
            *edid_end = 0x100;
        else if (size_code == 2)
            *edid_end = 0x180;
        else
            *edid_end = 0x200;
    }
}
