/* sys_dsc_dec_fill_default_config  (FUN_a00a507c)
 *
 * Fill a DSC decoder set-up record with fixed default values.
 *   port: unused
 *   cfg: record
 * Name basis: derived - 80-byte record, of which this routine fills bytes 0..0x47; later written by VBP_tmp
 *   (sys_dsc_dec_write_config)
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * The stores are written in ascending offset order; the scheduler groups the stores of each repeated
 * constant (1, 2, 0x8ca, 0x12) into the order seen in the firmware. The gaps (0x26..0x35, 0x41..0x43) are not
 * written. The first argument is unused.
 */
/* Set-up record of a DSC decoder (80 bytes; this routine fills the first 0x48). Fields not named here keep their
 * offset in the name. Same layout as in sys_dsc_dec_read_config and sys_dsc_dec_fill_hdmi21_timing. */
struct dsc_dec_config {
    unsigned short half_0x00;
    unsigned short half_0x02;
    unsigned char byte_0x04;
    unsigned char byte_0x05;
    unsigned char byte_0x06;
    unsigned char byte_0x07;
    unsigned char byte_0x08;
    unsigned char byte_0x09;
    unsigned char byte_0x0a;
    unsigned char byte_0x0b;
    unsigned char byte_0x0c;
    unsigned char byte_0x0d;
    unsigned char byte_0x0e;
    unsigned char byte_0x0f;
    unsigned short vtotal;          /* +0x10 */
    unsigned char byte_0x12;
    unsigned char byte_0x13;
    unsigned short htotal;          /* +0x14 */
    unsigned short vtotal_2;        /* +0x16, second copy of the vertical total */
    unsigned short hsync_width;     /* +0x18 */
    unsigned short half_0x1a;
    unsigned short half_0x1c;
    unsigned short half_0x1e;
    unsigned short hactive;         /* +0x20 */
    unsigned short half_0x22;
    unsigned short vactive;         /* +0x24 */
    unsigned char pad_26[0x10];
    unsigned short half_0x36;
    unsigned short hblank_rest_div8; /* +0x38 */
    unsigned char byte_0x3a;
    unsigned char byte_0x3b;
    unsigned char byte_0x3c;
    unsigned char byte_0x3d;
    unsigned char byte_0x3e;
    unsigned char byte_0x3f;
    unsigned char byte_0x40;
    unsigned char pad_41[0x3];
    unsigned int word_0x44;
};

/*
 * Fill a DSC decoder set-up record with fixed values. The timing fields get htotal 4400, vtotal 2250 (both
 * copies), hsync_width 5, hactive 3840 and vactive 2160; every other written field gets a constant as well.
 * Bytes 0x26..0x35 and 0x41..0x43, and the fields from 0x48 on, are not touched.
 *   port: decoder number the caller passes; not used
 *   cfg:  the record to fill
 * Caller: sys_dsc_dec_write_default_config, which then writes the record to the decoder.
 */
void sys_dsc_dec_fill_default_config(unsigned int port, struct dsc_dec_config *cfg)
{
    cfg->half_0x00 = 0x0;
    cfg->half_0x02 = 0x0;
    cfg->byte_0x04 = 0x1;
    cfg->byte_0x05 = 0x2;
    cfg->byte_0x06 = 0x0;
    cfg->byte_0x07 = 0x0;
    cfg->byte_0x08 = 0x0;
    cfg->byte_0x09 = 0x0;
    cfg->byte_0x0a = 0x0;
    cfg->byte_0x0b = 0x0;
    cfg->byte_0x0c = 0x1;
    cfg->byte_0x0d = 0x1;
    cfg->byte_0x0e = 0x1;
    cfg->byte_0x0f = 0x0;
    cfg->vtotal = 0x8ca;
    cfg->byte_0x12 = 0x0;
    cfg->byte_0x13 = 0x0;
    cfg->htotal = 0x1130;
    cfg->vtotal_2 = 0x8ca;
    cfg->hsync_width = 0x5;
    cfg->half_0x1a = 0xa;
    cfg->half_0x1c = 0x55;
    cfg->half_0x1e = 0x12;
    cfg->hactive = 0xf00;
    cfg->half_0x22 = 0x4;
    cfg->vactive = 0x870;
    cfg->half_0x36 = 0x56;
    cfg->hblank_rest_div8 = 0x12;
    cfg->byte_0x3a = 0x0;
    cfg->byte_0x3b = 0x0;
    cfg->byte_0x3c = 0x0;
    cfg->byte_0x3d = 0x0;
    cfg->byte_0x3e = 0x0;
    cfg->byte_0x3f = 0x2;
    cfg->byte_0x40 = 0x0;
    cfg->word_0x44 = 0x100;
}
