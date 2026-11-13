/* hdr_apply_tone_curve  (FUN_a00d31f8)
 *
 * Copy one of two stored 0x101-entry tone curves (chosen by an option bit) and write it to hardware.
 * Name basis: derived - 0x101 entries into the table at 0xA8077A08 from one of two tables by bit 2 of
 *   hdr_option_byte, then hdr_tmo_write_curve; runs only while bit 3 is set and clears it
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g. The two curve sources are indexed arrays of 0x101 halfwords; the
 * alternate one is an extern array at the symbol address 0x9f1b0800 (declared like the other bases, stride 1
 * element). The register word is read once per register and reused for every field write.
 */
extern unsigned char hdr_option_byte;
extern void hdr_tmo_set_table_index(unsigned int);
extern void hdr_tmo_enable(void);
extern void hdr_tmo_write_curve(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void reg_write_bit_field(unsigned int *, unsigned int, unsigned int, unsigned int);
extern unsigned int reg_read32(unsigned int);
extern void reg_write32(unsigned int, unsigned int);
extern unsigned short hdr_tone_curve[];
extern unsigned short ARR_a80783de[];
extern unsigned short hdr_tone_curve_alternate[];

/* HDR_OPTION_LOAD_CURVE: bit 3 of hdr_option_byte; the curve is loaded while it is set and it is cleared here.
 * HDR_OPTION_ALTERNATE: choose the table at 0x9f1b0800 instead of the table ARR_a80783de. */
#define HDR_OPTION_LOAD_CURVE 8
#define HDR_OPTION_ALTERNATE  4
/* Number of entries minus one: the curve table has 0x101 halfwords. */
#define TONE_CURVE_LAST 0x100
/* Two control registers written by this routine. */
#define TMO_REG_F6C 0xd0013f6c  /* bits 30..31 pulsed to 3 here */
#define TMO_REG_FDC 0xd0013fdc  /* bits 24..25 and 30..31 written here */

/*
 * Load a tone curve into the working table and start the tone-mapping stages with it.
 * Does nothing unless the "load curve" bit (8) of hdr_option_byte is set. Then, in order:
 *  1. copy the 0x101-entry curve into hdr_tone_curve, from ARR_a80783de, or from the table at 0x9f1b0800
 *     when the "alternate" bit (4) is set;
 *  2. set the table index to 0x100 and write the curve to the tone-mapping block (hdr_tmo_write_curve);
 *  3. read and write back TMO_REG_F6C with bits 31..30 set to 0 and then to 3, and TMO_REG_FDC with bits 25..24
 *     set to 1, then bits 31..30 set to 0 and then to 3 (each field change is written at once);
 *  4. switch the tone-mapping stages on (hdr_tmo_enable) and clear the "load curve" bit.
 * Takes no parameters and returns nothing. Called from hdr_task (bits 0 and 1 of hdr_option_byte set)
 * and from hdr_update_tone_curve (HLG source, bit 0 set).
 */
void hdr_apply_tone_curve(void)
{
    unsigned int reg_value;
    unsigned int i;

    if ((hdr_option_byte & HDR_OPTION_LOAD_CURVE) != 0) {
        if ((hdr_option_byte & HDR_OPTION_ALTERNATE) == 0) {
            for (i = 0; i <= TONE_CURVE_LAST; i++)
                hdr_tone_curve[i] = ARR_a80783de[i];
        } else {
            for (i = 0; i <= TONE_CURVE_LAST; i++)
                hdr_tone_curve[i] = hdr_tone_curve_alternate[i];
        }
        hdr_tmo_set_table_index(TONE_CURVE_LAST);
        hdr_tmo_write_curve(0, 0, 0, 0, 0);
        reg_value = reg_read32(TMO_REG_F6C);
        reg_write_bit_field(&reg_value, 0x1f, 0x1e, 0);
        reg_write32(TMO_REG_F6C, reg_value);
        reg_write_bit_field(&reg_value, 0x1f, 0x1e, 3);
        reg_write32(TMO_REG_F6C, reg_value);
        /* Second register: bits 25..24 = 1, then bits 31..30 = 0 and 3. */
        reg_value = reg_read32(TMO_REG_FDC);
        reg_write_bit_field(&reg_value, 0x19, 0x18, 1);
        reg_write32(TMO_REG_FDC, reg_value);
        reg_write_bit_field(&reg_value, 0x1f, 0x1e, 0);
        reg_write32(TMO_REG_FDC, reg_value);
        reg_write_bit_field(&reg_value, 0x1f, 0x1e, 3);
        reg_write32(TMO_REG_FDC, reg_value);
        hdr_tmo_enable();
        hdr_option_byte = hdr_option_byte & ~HDR_OPTION_LOAD_CURVE;
    }
}
