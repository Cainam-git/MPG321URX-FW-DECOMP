/* hdr_dump_hdr10plus_metadata  (targeted_system_display_maximum_luminance)
 *
 * Print the received HDR10+ metadata, the guided curve and the tone-mapping table when requested.
 * Note: Runs only when register 0xD0013FF0 reads 1 and clears it; the old label was a field name, not the
 *   routine's.
 * Name basis: proven - prints '[Dynamic HDR]targeted_system_display_maximum_luminance', knee_point, bezier
 *   anchors and TMO_LUT
 *
 * Matching notes
 * --------------
 * leon2s 0xa0061adc-0xa0061d60, flags -mcpu=v8 -Os -g.
 * Source forms: w = 0 before the first register write; i is set to 0 before the last header print;
 * reg_write_bit_field_copy is declared void (its result is not used; an int return reorders the argument set-up).
 */
/* The HDR10+ metadata record (hdr10plus_metadata); the field names are the ones the printed lines use. */
struct HdrMeta {
    unsigned char _0;
    unsigned char tone_mapping_flag;
    unsigned short knee_point_x;
    unsigned short knee_point_y;
    unsigned char _6[0x58 - 6];
    unsigned char num_bezier_curve_anchors;
    unsigned char _59;
    unsigned short bezier_curve_anchor[(0x88 - 0x5a) / 2];
    unsigned short max_display_luminance;
};
extern struct HdrMeta hdr10plus_metadata;
extern unsigned int hdr10plus_scene_luminance, hdr10plus_target_luminance, hdr10plus_panel_peak_x10;
extern unsigned int hdr_tmo_lut[];
extern unsigned char hdr_meta_receiver_index;
extern unsigned char (*hdr_meta_reg_read_fn)(unsigned char, unsigned short);
extern unsigned int reg_read32(volatile unsigned int *);
extern void reg_write32(volatile unsigned int *, unsigned int);
extern void reg_write_bit_field_copy(unsigned int *, unsigned int, unsigned int, unsigned int);
extern void timer_delay_long_units(unsigned short);
extern int dbg_printf(const char *, ...);

/* The dump runs when this register reads 1; the routine writes 0 to it first. */
#define HDR_DUMP_REQUEST_REG ((volatile unsigned int *)0xd0013ff0)
/* Tone-mapping table access: bit 0 opens it, bits 8..16 = entry index; the entry is then read from
   TMO_LUT_READ_DATA. */
#define TMO_LUT_ACCESS    ((volatile unsigned int *)0xd0013f60)
#define TMO_LUT_READ_DATA ((volatile unsigned int *)0xd0013f64)
/* Metadata register of bezier anchor i is HDR_META_ANCHOR_REG + i (read through hdr_meta_reg_read_fn). */
#define HDR_META_ANCHOR_REG 0x275
/* The dump visits table entries 0, 0x10, ... 0x100. */
#define TMO_LUT_LAST  0x100
#define TMO_LUT_STEP  0x10

/*
 * Debug dump, on request. Does nothing unless HDR_DUMP_REQUEST_REG reads 1; it then clears the register and:
 *  1. prints the HDR10+ metadata record: maximum display luminance, anchor count, knee point x/y, then the
 *     scene and product maximum luminance and the panel peak (hdr10plus_panel_peak_x10), and the tone-mapping flag;
 *  2. prints the 9 bezier anchors twice: the value read back from the receiver's metadata registers
 *     (register 0x275 + i, shifted left by 2), and the "guided" value kept in the record;
 *  3. opens the tone-mapping table (TMO_LUT_ACCESS bits 0 and 20 set), and for every 0x10th entry sets the index,
 *     writes the register three times with waits (5, 5, 10) between, and prints the table value read from
 *     TMO_LUT_READ_DATA next to the same entry of the working table hdr_tmo_lut;
 *  4. closes the table (bits 0 and 20 cleared).
 * No parameters, no return value. Called as the last step of hdr_task.
 */

void hdr_dump_hdr10plus_metadata(void)
{
    unsigned int w;
    unsigned int i;

    if (reg_read32(HDR_DUMP_REQUEST_REG) != 1)
        return;
    w = 0;
    reg_write32(HDR_DUMP_REQUEST_REG, 0);
    dbg_printf("[Dynamic HDR]targeted_system_display_maximum_luminance=%d\n",
                 hdr10plus_metadata.max_display_luminance);
    dbg_printf("[Dynamic HDR]num_bezier_curve_anchors=%d\n", hdr10plus_metadata.num_bezier_curve_anchors);
    dbg_printf("[Dynamic HDR]knee_point_x=%d\n", hdr10plus_metadata.knee_point_x);
    dbg_printf("[Dynamic HDR]knee_point_y=%d\n", hdr10plus_metadata.knee_point_y);
    dbg_printf("[Dynamic HDR]g_SceneMaxL=%d\n", hdr10plus_scene_luminance);
    dbg_printf("[Dynamic HDR]g_SenceProductMax=%d\n", hdr10plus_target_luminance);
    dbg_printf("[Dynamic HDR]g_stDISP_Info.u16MaxLum=%d\n", hdr10plus_panel_peak_x10);
    i = 0;
    dbg_printf("[Dynamic HDR]g_stMetaData10Plus.tone_mapping_flag=%d\n", hdr10plus_metadata.tone_mapping_flag);
    for (; i <= 8; i++) {
        dbg_printf("[Dynamic HDR]Metadata bezier_curve_anchor[%d]=%d\n", i,
                     hdr_meta_reg_read_fn(hdr_meta_receiver_index, i + HDR_META_ANCHOR_REG) << 2);
        dbg_printf("[Dynamic HDR]Guided bezier_curve_anchor[%d]=%d\n", i, hdr10plus_metadata.bezier_curve_anchor[i]);
    }
    w = reg_read32(TMO_LUT_ACCESS);
    reg_write_bit_field_copy(&w, 0, 0, 1);
    reg_write_bit_field_copy(&w, 0x14, 0x14, 1);
    reg_write_bit_field_copy(&w, 0x10, 8, 0);
    reg_write32(TMO_LUT_ACCESS, w);
    for (i = 0; i <= TMO_LUT_LAST; i += TMO_LUT_STEP) {
        reg_write_bit_field_copy(&w, 0, 0, 1);
        reg_write_bit_field_copy(&w, 0x10, 8, i);
        reg_write32(TMO_LUT_ACCESS, w);
        timer_delay_long_units(5);
        reg_write32(TMO_LUT_ACCESS, w);
        timer_delay_long_units(5);
        reg_write32(TMO_LUT_ACCESS, w);
        timer_delay_long_units(10);
        dbg_printf("[Dynamic HDR]   TMO_LUT[%d]=%d\n", i, reg_read32(TMO_LUT_READ_DATA));
        dbg_printf("[Dynamic HDR]g_usTMOBuf[%d]=%d\n", i, hdr_tmo_lut[i]);
    }
    w = reg_read32(TMO_LUT_ACCESS);
    reg_write_bit_field_copy(&w, 0, 0, 0);
    reg_write_bit_field_copy(&w, 0x14, 0x14, 0);
    reg_write32(TMO_LUT_ACCESS, w);
}
