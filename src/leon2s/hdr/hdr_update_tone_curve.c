/* hdr_update_tone_curve  (FUN_a00d3364)
 *
 * Derive the curve parameters from the HDR mastering luminance and program the curve block.
 * Name basis: derived - mastering luminance values; registers at 0xD0013F6C and following
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d3364 @ 0xa00d3364-0xa00d3670 (195 words), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - mastering_lum is unsigned int; in the hdr_enable branch the arm "not above the panel peak" is written first;
 *  - fdc_bits = 0 is written in both mode-7 arms;
 *  - the gain limit is one conditional-expression assignment;
 *  - hdr_tmo_write_curve is declared with five parameters and called with five zeros (the routine itself reads
 *    none of them).
 */

/* Transfer function values of enEOTF_Type, from the firmware's own value/text list (hdmi_rx21_hdr_eotf_names:
   0 EN_EOTF_TYPE_TSDR, 1 _THDR, 2 _ST2084, 3 _HLG, 4 _RESERVED). */
#define EN_EOTF_TYPE_ST2084  2
#define EN_EOTF_TYPE_HLG     3

/* Values of hdr_eotf_mode, printed by hdr_print_static_state as "u8EOTFMode". The value selects the
   table that hdr_tmo_write_gain_table writes; for 7 it writes none. */
#define EOTF_MODE_UP_TO_1000 3          /* mastering luminance 1..1000 */
#define EOTF_MODE_UP_TO_1500 4          /* 1001..1500 */
#define EOTF_MODE_UP_TO_2000 5          /* 1501..2000 */
#define EOTF_MODE_UP_TO_4000 6          /* 2001..4000 */
#define EOTF_MODE_OTHER      7          /* 0 or above 4000 */

#define HDR_OPTION_BIT0      0x01       /* hdr_option_byte bit 0: with HLG, hdr_apply_tone_curve instead */

#define LUMINANCE_MAX        10000      /* largest divisor of the gain */
#define TMO_SCALE_MAX        0xfff      /* the scale field (bits 0..11 of 0xD0013F50) has 12 bits */

/* ipc_request_8051_access modes. */
#define IPC_8051_SHARED_BYTE_REQUEST 0  /* write 0x55 to the shared byte at 0xCF03C800 */
#define IPC_8051_IRQ_REQUEST 1          /* raise the interrupt instead */

/* Registers of the tone-mapping block. */
#define TMO_REG_F6C          0xd0013f6c /* bits 0..15 = last table entry; bits 30..31 pulsed to 3 */
#define TMO_REG_FDC          0xd0013fdc /* bits 24..25 set here; bits 30..31 pulsed to 3 */

/* The static HDR information of the source; the field names are the ones hdr_print_static_state prints
   ("[Static HDR]g_HDR_Info.enEOTF_Type=%d" ...). */
struct HdrInfo {
    unsigned int w0;
    unsigned int enEOTF_Type;
    unsigned char _8[0x1c - 8];
    unsigned short u16Max_MasterLum;
    unsigned char _1e[2];
    unsigned short u16MaxCLL;
};
extern struct HdrInfo hdr_static_info;
extern unsigned short hdr_mastering_luminance;
extern unsigned char hdr_option_byte, hdr_enable, hdr_eotf_mode;
extern unsigned short hdr_gain, hdr_peak_luminance;  /* printed as "u16HDRGain" and "PanelMaxLum" */
extern unsigned short hdr_tone_curve[];
extern void hdr_build_static_tone_curve(unsigned short, unsigned short, unsigned short *);
extern unsigned char ipc_request_8051_access(int);
extern void ipc_release_8051_access(void);
extern unsigned int reg_read32(unsigned int);
extern void reg_write32(unsigned int, unsigned int);
extern void reg_write_bit_field(unsigned int *, unsigned int, unsigned int, unsigned int);
extern void hdr_reset_tone_curve(void);
extern void hdr_apply_tone_curve(void);
extern void hdr_tmo_write_gain_table(unsigned char);
extern void hdr_tmo_write_curve(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void hdr_tmo_set_table_index(unsigned int);
extern void hdr_tmo_enable_second(void);

/*
 * Set up the tone-mapping block for a static HDR source. Called by hdr_task when enEOTF_Type is above 1; on a
 * return of 1 hdr_task sets hdr_status_code (reported to the main processor) to 2.
 *
 * Phases:
 *  1. ST2084 source: pick the luminance the curve is built for. With hdr_enable set and a mastering luminance
 *     (u16Max_MasterLum) above the panel peak, hdr_build_static_tone_curve fills hdr_tone_curve for the two
 *     values; otherwise the panel peak is used and the curve is reset to neutral (0x400 in every entry).
 *  2. ST2084 source: from that luminance derive the mode (hdr_eotf_mode, EOTF_MODE_*), the value for
 *     bits 24..25 of TMO_REG_FDC, and the gain hdr_gain = factor of the mode / luminance, limited to
 *     0xFFF. The luminance is kept in hdr_mastering_luminance.
 *     HLG source with bit 0 of hdr_option_byte: hand over to hdr_apply_tone_curve and return 1.
 *     Any other source keeps the mode and gain of the last ST2084 pass.
 *  3. Write the gain table of the mode, inside a shared-table access granted by the 8051.
 *  4. Write hdr_tone_curve, inside a second access.
 *  5. Write the gain to bits 0..11 of 0xD0013F50, pulse bits 30..31 of TMO_REG_F6C, set bits 24..25 and pulse
 *     bits 30..31 of TMO_REG_FDC, and switch the second tone-mapping set on.
 *
 * Returns 0 when the 8051 does not grant an access (the rest is then skipped), else 1.
 */
int hdr_update_tone_curve(void)
{
    unsigned int mastering_lum;
    unsigned char fdc_bits = 0;
    unsigned int divisor;
    unsigned int reg_value;

    if (hdr_static_info.enEOTF_Type == EN_EOTF_TYPE_ST2084) {
        /* Phase 1: the luminance to build the curve for. */
        if (hdr_enable == 1) {
            mastering_lum = hdr_static_info.u16Max_MasterLum;
            if (mastering_lum <= hdr_peak_luminance) {
                /* Not above the panel peak: a neutral curve, modes taken from the panel peak. */
                mastering_lum = hdr_peak_luminance;
                hdr_reset_tone_curve();
            } else
                hdr_build_static_tone_curve(hdr_peak_luminance, mastering_lum, hdr_tone_curve);
        } else {
            mastering_lum = hdr_peak_luminance;
            hdr_reset_tone_curve();
        }

        /* Phase 2: mode and register value by luminance range. */
        if (mastering_lum == 0) {
            hdr_eotf_mode = EOTF_MODE_OTHER;
            fdc_bits = 0;
        } else if (mastering_lum <= 1000) {
            hdr_eotf_mode = EOTF_MODE_UP_TO_1000;
            fdc_bits = 2;
        } else if (mastering_lum <= 1500) {
            hdr_eotf_mode = EOTF_MODE_UP_TO_1500;
            fdc_bits = 2;
        } else if (mastering_lum <= 2000) {
            hdr_eotf_mode = EOTF_MODE_UP_TO_2000;
            fdc_bits = 2;
        } else if (mastering_lum <= 4000) {
            hdr_eotf_mode = EOTF_MODE_UP_TO_4000;
            fdc_bits = 2;
        } else {
            hdr_eotf_mode = EOTF_MODE_OTHER;
            fdc_bits = 0;
        }
        hdr_mastering_luminance = mastering_lum;

        /* The gain: a factor per mode divided by the luminance (1 for 0, at most LUMINANCE_MAX). */
        divisor = 1;
        if (mastering_lum != 0) {
            divisor = mastering_lum;
            if (mastering_lum > LUMINANCE_MAX)
                divisor = LUMINANCE_MAX;
        }
        if (hdr_eotf_mode == EOTF_MODE_UP_TO_1000)
            hdr_gain = 256000 / divisor;
        else if (hdr_eotf_mode == EOTF_MODE_UP_TO_1500)
            hdr_gain = 384000 / divisor;
        else if (hdr_eotf_mode == EOTF_MODE_UP_TO_2000)
            hdr_gain = 512000 / divisor;
        else if (hdr_eotf_mode == EOTF_MODE_UP_TO_4000)
            hdr_gain = 1024000 / divisor;
        else
            hdr_gain = 2560000 / divisor;
        hdr_gain = hdr_gain > TMO_SCALE_MAX ? TMO_SCALE_MAX : hdr_gain;
    } else if (hdr_static_info.enEOTF_Type == EN_EOTF_TYPE_HLG) {
        if (hdr_option_byte & HDR_OPTION_BIT0) {
            hdr_apply_tone_curve();
            return 1;
        }
    }

    /* Phase 3: the gain table of the mode. */
    if (!ipc_request_8051_access(IPC_8051_IRQ_REQUEST))
        return 0;
    hdr_tmo_write_gain_table(hdr_eotf_mode);
    ipc_release_8051_access();

    /* Phase 4: the tone curve. */
    if (!ipc_request_8051_access(IPC_8051_SHARED_BYTE_REQUEST))
        return 0;
    hdr_tmo_write_curve(0, 0, 0, 0, 0);
    ipc_release_8051_access();

    /* Phase 5: gain and control bits. */
    hdr_tmo_set_table_index(hdr_gain);
    reg_value = reg_read32(TMO_REG_F6C);
    reg_write_bit_field(&reg_value, 0x1f, 0x1e, 0);
    reg_write32(TMO_REG_F6C, reg_value);
    reg_write_bit_field(&reg_value, 0x1f, 0x1e, 3);
    reg_write32(TMO_REG_F6C, reg_value);
    reg_value = reg_read32(TMO_REG_FDC);
    reg_write_bit_field(&reg_value, 0x19, 0x18, fdc_bits & 2);
    reg_write32(TMO_REG_FDC, reg_value);
    reg_value = reg_read32(TMO_REG_FDC);
    reg_write_bit_field(&reg_value, 0x1f, 0x1e, 0);
    reg_write32(TMO_REG_FDC, reg_value);
    reg_write_bit_field(&reg_value, 0x1f, 0x1e, 3);
    reg_write32(TMO_REG_FDC, reg_value);
    hdr_tmo_enable_second();
    return 1;
}
