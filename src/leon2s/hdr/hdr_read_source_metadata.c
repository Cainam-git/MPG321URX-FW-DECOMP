/* hdr_read_source_metadata  (FUN_a00d38a8)
 *
 * Read EOTF type, mastering luminance and MaxCLL of the source; clamp the mastering luminance.
 * Name basis: derived - source selected by the byte at 0xA8078C37; values kept at 0xA807D548
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source forms: an if/else chain on hdr_source (no jump table); the low byte of each register pair is held in
 * an unsigned int local, except in the DisplayPort branches where it is stored into the record first and
 * read back for the addition.
 */
/* The static HDR information of the source; the field names are the ones hdr_print_static_state prints
   ("[Static HDR]g_HDR_Info.enEOTF_Type=%d" ...). */
struct HdrInfo {
    unsigned int w0;
    unsigned int enEOTF_Type;
    unsigned char _8[0x14];
    unsigned short u16Max_MasterLum;
    unsigned char _1e[2];
    unsigned short u16MaxCLL;
};
extern struct HdrInfo hdr_static_info;
extern unsigned char hdr_source;
extern unsigned char hdmi_reg_read8(unsigned char, unsigned short);
extern unsigned char hdmi_rx21_reg_read8(unsigned char, unsigned short);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern unsigned char dp_reg_read8(unsigned char, unsigned short);

/* Source numbers in hdr_source: two HDMI 2.0 receivers, two HDMI 2.1 receivers, two read through the indirect
 * index/data register pair (DP_INDEX_REG selects, DP_DATA_REG returns one byte). */
#define HDR_META_HDMI20_RX0   0
#define HDR_META_HDMI20_RX1   1
#define HDR_META_HDMI21_RX0   2
#define HDR_META_HDMI21_RX1   3
#define HDR_META_INDIRECT_RX0 4
#define HDR_META_INDIRECT_RX1 5
#define DP_INDEX_REG 0x73
#define DP_DATA_REG  0x74
/* The maximum-luminance value is clamped to this. */
#define HDR_LUMINANCE_LIMIT 10000

/*
 * Read the static HDR metadata of the current source (hdr_source) into hdr_static_info:
 *   enEOTF_Type      = low 2 bits of one register byte;
 *   u16Max_MasterLum = 16-bit value from two consecutive registers, low byte first;
 *   u16MaxCLL        = 16-bit value from two further consecutive registers, low byte first.
 * Which receiver routine and which registers are read depends on the source: sources 0 and 1 use
 * hdmi_reg_read8 (registers 0x1b4, 0x1c6/0x1c7, 0x1ca/0x1cb), sources 2 and 3 use hdmi_rx21_reg_read8
 * (0x504, 0x516/0x517, 0x51a/0x51b). The receiver number passed is 0 or 1 (the first or second source of the pair). Sources 4 and 5 go
 * through the index/data pair (index 6, 0x18/0x19, 0x1c/0x1d). Any other source number leaves the record
 * unchanged. Finally u16Max_MasterLum is clamped to HDR_LUMINANCE_LIMIT.
 * No parameters, no return value. Called from hdr_task when the source reports HDR.
 */
void hdr_read_source_metadata(void)
{
    unsigned int low_byte;

    if (hdr_source == HDR_META_HDMI20_RX0) {
        hdr_static_info.enEOTF_Type = hdmi_reg_read8(0, 0x1b4) & 3;
        low_byte = hdmi_reg_read8(0, 0x1c6);
        hdr_static_info.u16Max_MasterLum = (hdmi_reg_read8(0, 0x1c7) << 8) + low_byte;
        low_byte = hdmi_reg_read8(0, 0x1ca);
        hdr_static_info.u16MaxCLL = (hdmi_reg_read8(0, 0x1cb) << 8) + low_byte;
    } else if (hdr_source == HDR_META_HDMI20_RX1) {
        hdr_static_info.enEOTF_Type = hdmi_reg_read8(1, 0x1b4) & 3;
        low_byte = hdmi_reg_read8(1, 0x1c6);
        hdr_static_info.u16Max_MasterLum = (hdmi_reg_read8(1, 0x1c7) << 8) + low_byte;
        low_byte = hdmi_reg_read8(1, 0x1ca);
        hdr_static_info.u16MaxCLL = (hdmi_reg_read8(1, 0x1cb) << 8) + low_byte;
    } else if (hdr_source == HDR_META_HDMI21_RX0) {
        hdr_static_info.enEOTF_Type = hdmi_rx21_reg_read8(0, 0x504) & 3;
        low_byte = hdmi_rx21_reg_read8(0, 0x516);
        hdr_static_info.u16Max_MasterLum = (hdmi_rx21_reg_read8(0, 0x517) << 8) + low_byte;
        low_byte = hdmi_rx21_reg_read8(0, 0x51a);
        hdr_static_info.u16MaxCLL = (hdmi_rx21_reg_read8(0, 0x51b) << 8) + low_byte;
    } else if (hdr_source == HDR_META_HDMI21_RX1) {
        hdr_static_info.enEOTF_Type = hdmi_rx21_reg_read8(1, 0x504) & 3;
        low_byte = hdmi_rx21_reg_read8(1, 0x516);
        hdr_static_info.u16Max_MasterLum = (hdmi_rx21_reg_read8(1, 0x517) << 8) + low_byte;
        low_byte = hdmi_rx21_reg_read8(1, 0x51a);
        hdr_static_info.u16MaxCLL = (hdmi_rx21_reg_read8(1, 0x51b) << 8) + low_byte;
    } else if (hdr_source == HDR_META_INDIRECT_RX0) {
        dp_reg_write8(0, DP_INDEX_REG, 6);
        hdr_static_info.enEOTF_Type = dp_reg_read8(0, DP_DATA_REG) & 3;
        dp_reg_write8(0, DP_INDEX_REG, 0x18);
        hdr_static_info.u16Max_MasterLum = dp_reg_read8(0, DP_DATA_REG);
        dp_reg_write8(0, DP_INDEX_REG, 0x19);
        hdr_static_info.u16Max_MasterLum = (dp_reg_read8(0, DP_DATA_REG) << 8) + hdr_static_info.u16Max_MasterLum;
        dp_reg_write8(0, DP_INDEX_REG, 0x1c);
        hdr_static_info.u16MaxCLL = dp_reg_read8(0, DP_DATA_REG);
        dp_reg_write8(0, DP_INDEX_REG, 0x1d);
        hdr_static_info.u16MaxCLL = (dp_reg_read8(0, DP_DATA_REG) << 8) + hdr_static_info.u16MaxCLL;
    } else if (hdr_source == HDR_META_INDIRECT_RX1) {
        dp_reg_write8(1, DP_INDEX_REG, 6);
        hdr_static_info.enEOTF_Type = dp_reg_read8(1, DP_DATA_REG) & 3;
        dp_reg_write8(1, DP_INDEX_REG, 0x18);
        hdr_static_info.u16Max_MasterLum = dp_reg_read8(1, DP_DATA_REG);
        dp_reg_write8(1, DP_INDEX_REG, 0x19);
        hdr_static_info.u16Max_MasterLum = (dp_reg_read8(1, DP_DATA_REG) << 8) + hdr_static_info.u16Max_MasterLum;
        dp_reg_write8(1, DP_INDEX_REG, 0x1c);
        hdr_static_info.u16MaxCLL = dp_reg_read8(1, DP_DATA_REG);
        dp_reg_write8(1, DP_INDEX_REG, 0x1d);
        hdr_static_info.u16MaxCLL = (dp_reg_read8(1, DP_DATA_REG) << 8) + hdr_static_info.u16MaxCLL;
    }
    if (hdr_static_info.u16Max_MasterLum > HDR_LUMINANCE_LIMIT)
        hdr_static_info.u16Max_MasterLum = HDR_LUMINANCE_LIMIT;
}
