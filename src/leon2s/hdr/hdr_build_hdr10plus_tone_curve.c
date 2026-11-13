/* hdr_build_hdr10plus_tone_curve  (FUN_a0062fc8)
 *
 * Build and load the 257-point tone-mapping table from the received HDR10+ metadata.
 *   panel_peak_x10: metadata record
 *   metadata: panel peak luminance x 10
 * Returns: 1 when the table was loaded into the tone-mapping block, 0 when the 8051 access was not granted
 * Note: The peak argument is the panel peak luminance x 10, raised to 1000 when lower.
 * Name basis: derived - derives g_SceneMaxL / g_SenceProductMax (dump prints), builds table TMO_LUT and writes
 *   it under the 8051 handshake
 *
 * Matching notes
 * --------------
 * FUN_a0062fc8 (leon2s 0xa0062fc8-0xa006370c, 1860 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the record copy is a structure assignment; GCC emits it as a call of the firmware memcpy lib_memcpy
 *    (declared with that link name), so the record type must keep its size of 0x8A bytes;
 *  - hdr_build_guided_curve takes the record address as a fifth parameter;
 *  - the stride 4 of the in-between fill is the variable step (hdr_tmo_lut[i] and hdr_tmo_lut[i - step] load
 *    through one pointer);
 *  - the curve-order choice lists order 2 explicitly with the default's table;
 *  - the in-between fill sits inside its own entry test, with j = knee_index + 1 set after that test;
 *  - the rising fill has an index k and a separate counter m running from -4 while m < -1: GCC turns that
 *    counter into a count-down from 3 tested against zero, while the falling fill's counter (bound 4) becomes
 *    a count-down from 2 tested for >= 0;
 *  - volatile only on the hardware registers.
 */

/*
 * The HDR10+ metadata record (0x8A bytes). hdr_read_hdr10plus_metadata fills it from the received packet; the
 * field names are the ones the firmware prints in hdr_dump_hdr10plus_metadata ("[Dynamic HDR]...").
 */
struct hdr10plus_metadata_record {
    unsigned char byte_0x00;
    unsigned char tone_mapping_flag;            /* +0x01 */
    unsigned short knee_point_x;                /* +0x02, 0..0xFFF */
    unsigned short knee_point_y;                /* +0x04 */
    unsigned char bytes_0x06[0x58 - 6];         /* percentile list (+0x07 count, +0x08 values, +0x30 keys) */
    unsigned char num_bezier_curve_anchors;     /* +0x58 */
    unsigned char bytes_0x59[0x82 - 0x59];      /* +0x5A bezier_curve_anchor[] */
    unsigned short scene_max_0, scene_max_1, scene_max_2;  /* +0x82..+0x86; the largest is hdr10plus_scene_max */
    unsigned short targeted_system_display_maximum_luminance;  /* +0x88 */
};

/* Registers of the tone-mapping block. */
#define TMO_REG_F50          REG(0xd0013f50)    /* bits 0..11 = curve scale, bit 31 set after loading */
#define TMO_LUT_ACCESS       REG(0xd0013f60)    /* bit 0 = table access open, bits 8..16 = entry index */
#define TMO_LUT_WRITE_DATA   REG(0xd0013f68)    /* value of the entry selected in TMO_LUT_ACCESS */
#define TMO_REG_F6C          REG(0xd0013f6c)    /* bits 0..15 = last table entry; bits 30..31 pulsed to 3 */
#define TMO_REG_FDC          REG(0xd0013fdc)    /* bits 24..25 cleared before the table is built */

#define TMO_LUT_LAST         0x100              /* the table has entries 0..0x100 (257) */
#define TMO_LUT_NEUTRAL      0x400              /* curve value / input level = 1 */
#define TMO_SCALE_MAX        0xfff              /* the scale field has 12 bits */
#define PANEL_PEAK_MIN       1000               /* lowest panel peak used (luminance x 10) */
#define IPC_8051_IRQ_REQUEST 1                  /* ipc_request_8051_access: raise the interrupt */

extern struct hdr10plus_metadata_record hdr10plus_metadata;
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
extern unsigned int hdr10plus_scene_max, hdr10plus_scene_luminance, hdr10plus_target_luminance;
extern unsigned int hdr10plus_percentile_99, hdr10plus_percentile_50, hdr_curve_bezier_scale, hdr_curve_knee_slope;
extern unsigned char hdr10plus_use_scene_max_flag, hdr10plus_guided_curve_flag;
extern unsigned int hdr_tmo_lut[];
extern unsigned short (*hdr_bezier_weights_ptr)[65];
extern unsigned short hdr_bezier_weights_order10[][65], hdr_bezier_weights_order9[][65], hdr_bezier_weights_order8[][65], hdr_bezier_weights_order7[][65];
extern unsigned short hdr_bezier_weights_order6[][65], hdr_bezier_weights_order5[][65], hdr_bezier_weights_order4[][65], hdr_bezier_weights_order3[][65];
extern unsigned short hdr_bezier_weights_order2[][65];
extern unsigned int reg_read32(volatile unsigned int *);
extern void reg_write32(volatile unsigned int *, unsigned int);
extern void reg_write_bit_field_copy(unsigned int *, unsigned int, unsigned int, unsigned int);
extern unsigned int hdr_evaluate_tone_curve(unsigned int);
extern int ipc_request_8051_access(unsigned char);
extern void ipc_release_8051_access(void);
extern void hdr_find_percentile_luminance(void);
extern void hdr_build_guided_curve(unsigned int, unsigned int, unsigned int, unsigned int, struct hdr10plus_metadata_record *);
extern void hdr_fill_unused_anchors(struct hdr10plus_metadata_record *);

#define REG(a) ((volatile unsigned int *)(a))

/*
 * Turn a received HDR10+ metadata record into the 257-entry tone-mapping table hdr_tmo_lut and load it into the
 * tone-mapping block.
 *
 *   panel_peak_x10  panel peak luminance x 10 (the caller passes hdr10plus_panel_peak_x10)
 *   metadata        the record to use; it is copied to hdr10plus_metadata first
 *
 * Returns 1 when the table was loaded, 0 when the 8051 did not grant access (the table is then built in RAM
 * only). Called by hdr_update_hdr10plus_metadata with a copy of the freshly read record; that caller writes the
 * result to register 0xD0013FFC (0xAA with the source mode on success, 0xFF otherwise).
 *
 * Phases:
 *  1. Copy the record; take the largest of its three scene_max values, look up the 50th and 99th percentile
 *     brightness, and choose the scene luminance (x 10).
 *  2. Target luminance = the larger of scene luminance and panel peak. Curve scale = 25600000 / target, halved
 *     up to three times to fit 12 bits; 'shift' counts the halvings and scales the whole table the same way.
 *  3. Clear bits 24..25 of TMO_REG_FDC.
 *  4. Complete the curve description: a guided knee point and anchors (hdr_build_guided_curve) when asked for
 *     or when the record has none; unused anchors to full scale; knee slope and Bezier scale; the Bezier weight
 *     table that matches the number of anchors.
 *  5. Build the table. Each entry holds the curve value divided by its input level (input level = index * 16):
 *     up to the knee the knee slope, every 4th entry above it from hdr_evaluate_tone_curve, the top entries
 *     neutral (0x400 << shift).
 *  6. Fill the three entries between each pair of computed entries by stepping from the lower one.
 *  7. With the 8051's grant, write entries 0..0xFF through TMO_LUT_ACCESS / TMO_LUT_WRITE_DATA and the last
 *     entry into TMO_REG_F6C, pulse bits 30..31 of TMO_REG_F6C, release the 8051 and write the curve scale.
 */
unsigned char hdr_build_hdr10plus_tone_curve(unsigned int panel_peak_x10, struct hdr10plus_metadata_record *metadata)
{
    unsigned int reg_value;
    unsigned int target;
    unsigned int tmo_scale;
    unsigned char shift;
    unsigned short knee_index;
    unsigned short last_computed;
    unsigned int i, j;
    int k;
    int m;
    unsigned int upper, lower, delta;
    int loaded;
    int curve_order;
    int step;

    /* 1. Scene brightness from the record. */
    hdr10plus_metadata = *metadata;
    if (panel_peak_x10 < PANEL_PEAK_MIN)
        panel_peak_x10 = PANEL_PEAK_MIN;
    hdr10plus_scene_max = hdr10plus_metadata.scene_max_0 > hdr10plus_metadata.scene_max_1 ? hdr10plus_metadata.scene_max_0 : hdr10plus_metadata.scene_max_1;
    step = 4;
    hdr10plus_scene_max = hdr10plus_metadata.scene_max_2 > hdr10plus_scene_max ? hdr10plus_metadata.scene_max_2 : hdr10plus_scene_max;
    /* When the percentile list gives no 99th percentile, that routine takes hdr10plus_scene_max instead. */
    hdr_find_percentile_luminance();
    if (hdr10plus_scene_max == 0) {
        hdr10plus_scene_luminance = hdr10plus_percentile_99 * 10;
    } else {
        hdr10plus_scene_luminance = hdr10plus_use_scene_max_flag ? hdr10plus_scene_max * 10 : hdr10plus_percentile_99 * 10;
    }

    /* 2. Target luminance and the curve scale. */
    hdr10plus_target_luminance = hdr10plus_scene_luminance >= panel_peak_x10 ? hdr10plus_scene_luminance : panel_peak_x10;
    target = hdr10plus_target_luminance;
    if (target == 0)
        target = 1;
    hdr10plus_target_luminance = target;
    tmo_scale = 25600000 / target;
    shift = 0;
    if (tmo_scale > TMO_SCALE_MAX) {
        tmo_scale >>= 1;
        shift = 1;
        if (tmo_scale > TMO_SCALE_MAX) {
            tmo_scale >>= 1;
            shift = 2;
            if (tmo_scale > TMO_SCALE_MAX) {
                tmo_scale >>= 1;
                shift = 3;
                if (tmo_scale > TMO_SCALE_MAX)
                    tmo_scale = TMO_SCALE_MAX;
            }
        }
    }

    /* 3. */
    reg_value = reg_read32(TMO_REG_FDC);
    reg_write_bit_field_copy(&reg_value, 0x19, 0x18, 0);
    reg_write32(TMO_REG_FDC, reg_value);

    /* 4. Curve description: knee point, anchors, slope and Bezier scale, weight table. */
    if (hdr10plus_metadata.num_bezier_curve_anchors != 0)
        hdr10plus_metadata.tone_mapping_flag = 1;
    if (hdr10plus_guided_curve_flag != 0 || hdr10plus_metadata.tone_mapping_flag == 0)
        hdr_build_guided_curve(panel_peak_x10, hdr10plus_scene_luminance, hdr10plus_percentile_99, hdr10plus_percentile_50, &hdr10plus_metadata);
    hdr_fill_unused_anchors(&hdr10plus_metadata);
    hdr_curve_bezier_scale = 0x10000000 / (int)(0x1000 - hdr10plus_metadata.knee_point_x);
    if (hdr10plus_metadata.knee_point_x == 0)
        hdr_curve_knee_slope = (unsigned int)hdr10plus_metadata.knee_point_y << 10;
    else
        hdr_curve_knee_slope = (int)(hdr10plus_metadata.knee_point_y << 10) / (int)hdr10plus_metadata.knee_point_x;
    /* Curve order = anchors + 1; orders above 10 and below 2 use the order-2 weights. */
    curve_order = hdr10plus_metadata.num_bezier_curve_anchors + 1;
    if (curve_order == 10)
        hdr_bezier_weights_ptr = hdr_bezier_weights_order10;
    else if (curve_order == 9)
        hdr_bezier_weights_ptr = hdr_bezier_weights_order9;
    else if (curve_order == 8)
        hdr_bezier_weights_ptr = hdr_bezier_weights_order8;
    else if (curve_order == 7)
        hdr_bezier_weights_ptr = hdr_bezier_weights_order7;
    else if (curve_order == 6)
        hdr_bezier_weights_ptr = hdr_bezier_weights_order6;
    else if (curve_order == 5)
        hdr_bezier_weights_ptr = hdr_bezier_weights_order5;
    else if (curve_order == 4)
        hdr_bezier_weights_ptr = hdr_bezier_weights_order4;
    else if (curve_order == 3)
        hdr_bezier_weights_ptr = hdr_bezier_weights_order3;
    else if (curve_order == 2)
        hdr_bezier_weights_ptr = hdr_bezier_weights_order2;
    else
        hdr_bezier_weights_ptr = hdr_bezier_weights_order2;

    /* 5. The table. The knee point is on a 0..0xFFF scale; one entry covers 16 input levels. */
    knee_index = (int)(hdr10plus_metadata.knee_point_x >> 4) >> shift;
    hdr_curve_knee_slope <<= shift;
    last_computed = 0;
    if (knee_index == 0)
        hdr_tmo_lut[0] = hdr_evaluate_tone_curve(8) >> (11 - shift);
    else
        hdr_tmo_lut[0] = hdr_curve_knee_slope;
    /* Below the knee the curve is a straight line: every entry is its slope. */
    for (i = 1; i <= knee_index + 1; i++)
        hdr_tmo_lut[i] = hdr_curve_knee_slope;
    /* Above the knee every 4th entry is computed from the curve ... */
    for (i = knee_index + 1; i < (TMO_LUT_LAST >> shift); i += step) {
        hdr_tmo_lut[i] = (hdr_evaluate_tone_curve((i << 4) << shift) >> (12 - shift)) / (i << shift);
        last_computed = i;
    }
    /* ... and every entry after the last of those up to the scaled end. */
    for (i = last_computed + 1; i < (TMO_LUT_LAST >> shift); i++)
        hdr_tmo_lut[i] = (hdr_evaluate_tone_curve((i << 4) << shift) >> (12 - shift)) / (i << shift);
    /* The entries the scaled range does not reach are neutral. */
    if (shift == 0)
        hdr_tmo_lut[TMO_LUT_LAST] = TMO_LUT_NEUTRAL;
    else
        for (i = TMO_LUT_LAST >> shift; i <= TMO_LUT_LAST; i++)
            hdr_tmo_lut[i] = TMO_LUT_NEUTRAL << shift;

    /* 6. Fill the three entries between each pair of computed entries (j = lower entry of the pair, i = upper).
       The step per entry is |upper - lower| << 6 in 1/256 units, rounded. */
    i = knee_index + step + 1;
    if (i <= TMO_LUT_LAST) {
        j = knee_index + 1;
        for (; i <= TMO_LUT_LAST; i += step, j += step) {
            upper = hdr_tmo_lut[i];
            lower = hdr_tmo_lut[i - step];
            if (upper >= lower) {
                delta = (upper - lower) << 6;
                for (k = 1, m = -4; m < -1; m++, k++)
                    hdr_tmo_lut[j + k] = ((hdr_tmo_lut[j + k - 1] << 8) + delta + 0x80) >> 8;
            } else {
                delta = (lower - upper) << 6;
                for (k = 1; k < 4; k++)
                    hdr_tmo_lut[i + k - step] = ((hdr_tmo_lut[i + k - step - 1] << 8) - delta + 0x80) >> 8;
            }
        }
    }

    /* 7. Load the table; the 8051 must grant access to the block first. */
    loaded = 0;
    if ((unsigned char)ipc_request_8051_access(IPC_8051_IRQ_REQUEST)) {
        reg_value = reg_read32(TMO_LUT_ACCESS);
        reg_write_bit_field_copy(&reg_value, 0, 0, 1);
        reg_write_bit_field_copy(&reg_value, 0x10, 8, 0);
        reg_write32(TMO_LUT_ACCESS, reg_value);
        for (i = 0; i <= 0xff; i++) {
            reg_write_bit_field_copy(&reg_value, 0x10, 8, i);
            reg_write32(TMO_LUT_ACCESS, reg_value);
            reg_write32(TMO_LUT_WRITE_DATA, hdr_tmo_lut[i]);
        }
        reg_value = reg_read32(TMO_LUT_ACCESS);
        reg_write_bit_field_copy(&reg_value, 0, 0, 0);
        reg_write32(TMO_LUT_ACCESS, reg_value);
        /* The last entry (0x100) goes into its own register. */
        reg_value = reg_read32(TMO_REG_F6C);
        reg_write_bit_field_copy(&reg_value, 0xf, 0, hdr_tmo_lut[TMO_LUT_LAST]);
        reg_write32(TMO_REG_F6C, reg_value);
        reg_value = reg_read32(TMO_REG_F6C);
        reg_write_bit_field_copy(&reg_value, 0x1f, 0x1e, 3);
        reg_write32(TMO_REG_F6C, reg_value);
        reg_write_bit_field_copy(&reg_value, 0x1f, 0x1e, 0);
        reg_write32(TMO_REG_F6C, reg_value);
        loaded = 1;
        ipc_release_8051_access();
        reg_value = reg_read32(TMO_REG_F50);
        reg_write_bit_field_copy(&reg_value, 0xb, 0, tmo_scale);
        reg_write_bit_field_copy(&reg_value, 0x1f, 0x1f, 1);
        reg_write32(TMO_REG_F50, reg_value);
    }
    return loaded;
}
