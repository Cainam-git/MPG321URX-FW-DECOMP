/* hdr_tmo_write_curve  (FUN_a00d3114)
 *
 * Write the tone curve table to the tone-mapping block.
 * Returns: 1
 * Name basis: derived - table loop with the index register
 *
 * Matching notes
 * --------------
 * FUN_a00d3114 (leon2s, 0xa00d3114-0xa00d31f8, 228 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the word is cleared on the stack first (firmware 'clr [%fp-12]'); the '!= 0x100' arm is written
 * first.
 */
extern unsigned int reg_read32(unsigned int);
extern void reg_write32(unsigned int, unsigned int);
extern void reg_write_bit_field(unsigned int *, unsigned int, unsigned int, unsigned int);
extern unsigned short hdr_tone_curve[];

#define TMO_LUT_ACCESS      0xd0013f60  /* bit 0 = table access open, bits 16..8 = entry index */
#define TMO_LUT_WRITE_DATA  0xd0013f68  /* value of the entry selected in TMO_LUT_ACCESS */
#define TMO_REG_F6C         0xd0013f6c  /* bits 15..0 = last table entry */
#define TONE_CURVE_LAST     0x100       /* the curve has entries 0..0x100 (257) */

/*
 * Write the 257 entries of hdr_tone_curve to the tone-mapping block. Open the table access (bit 0 of
 * TMO_LUT_ACCESS, entry index 0), then for each entry select its index in bits 16..8 and write the 16-bit value
 * to TMO_LUT_WRITE_DATA; the last entry (0x100) goes into bits 15..0 of TMO_REG_F6C instead. Always returns 1.
 * Called by the curve loader hdr_apply_tone_curve and by hdr_update_tone_curve.
 */
int hdr_tmo_write_curve(void)
{
    unsigned int reg_value = 0;
    unsigned int i;

    reg_value = reg_read32(TMO_LUT_ACCESS);
    reg_write_bit_field(&reg_value, 0, 0, 1);
    reg_write_bit_field(&reg_value, 0x10, 8, 0);
    reg_write32(TMO_LUT_ACCESS, reg_value);
    for (i = 0; i <= TONE_CURVE_LAST; i++) {
        reg_write_bit_field(&reg_value, 0x10, 8, i);
        reg_write32(TMO_LUT_ACCESS, reg_value);
        if (i != TONE_CURVE_LAST) {
            reg_write32(TMO_LUT_WRITE_DATA, hdr_tone_curve[i]);
        } else {
            reg_value = reg_read32(TMO_REG_F6C);
            reg_write_bit_field(&reg_value, 0xf, 0, hdr_tone_curve[TONE_CURVE_LAST]);
            reg_write32(TMO_REG_F6C, reg_value);
        }
    }
    return 1;
}
