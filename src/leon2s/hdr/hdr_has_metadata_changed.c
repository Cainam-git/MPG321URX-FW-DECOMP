/* hdr_has_metadata_changed  (FUN_a00d2b88)
 *
 * Return 1 when the HDR settings must be applied again, and store the current metadata values.
 * Returns: 1 when changed
 * Name basis: derived - compares with the stored copies
 *
 * Matching notes
 * --------------
 * FUN_a00d2b88 (leon2s 0xa00d2b88-0xa00d2c38, 176 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: hdr_static_info is a structure (one base register for +4 and +0x1c); the 0/4 test is an
 * if/else-if pair; the result is an unsigned char returned as changed & 1.
 */
/* The static HDR information of the source (field names as printed by hdr_print_static_state). */
struct hdr_info_record {
    unsigned int w0;
    unsigned int enEOTF_Type;           /* +4 */
    unsigned char _8[0x14];
    unsigned short u16Max_MasterLum;    /* +0x1c */
};
extern struct hdr_info_record hdr_static_info;
extern unsigned char hdr_settings_changed_flag;
extern unsigned char hdr_status_code;
extern unsigned int hdr_last_meta_word;
extern unsigned short hdr_last_meta_half;
extern unsigned short hdr_peak_luminance;
extern unsigned short hdr_last_peak_luminance;

#define HDR_STATUS_OFF         0        /* values of hdr_status_code */
#define HDR_STATUS_SECOND_SET  4

/*
 * Tell hdr_task whether the HDR settings have to be applied again. Returns 1 when any of these holds, else 0:
 *   - hdr_settings_changed_flag is 1 (the flag is cleared here);
 *   - hdr_status_code is 0 (off) or 4 (second tone-mapping set on);
 *   - the transfer function type (enEOTF_Type) or the mastering luminance (u16Max_MasterLum) of
 *     hdr_static_info differs from the copy kept here (hdr_last_meta_word / hdr_last_meta_half);
 *   - the panel peak luminance hdr_peak_luminance differs from hdr_last_peak_luminance.
 * The three copies are updated to the new values; the tests are all made, none is skipped.
 */
unsigned char hdr_has_metadata_changed(void)
{
    unsigned char changed = 0;

    if (hdr_settings_changed_flag == 1) {
        hdr_settings_changed_flag = 0;
        changed = 1;
    }
    if (hdr_status_code == HDR_STATUS_OFF)
        changed = 1;
    else if (hdr_status_code == HDR_STATUS_SECOND_SET)
        changed = 1;
    if (hdr_static_info.enEOTF_Type != hdr_last_meta_word) {
        hdr_last_meta_word = hdr_static_info.enEOTF_Type;
        changed = 1;
    }
    if (hdr_static_info.u16Max_MasterLum != hdr_last_meta_half) {
        hdr_last_meta_half = hdr_static_info.u16Max_MasterLum;
        changed = 1;
    }
    if (hdr_last_peak_luminance != hdr_peak_luminance) {
        hdr_last_peak_luminance = hdr_peak_luminance;
        changed = 1;
    }
    return changed & 1;
}
