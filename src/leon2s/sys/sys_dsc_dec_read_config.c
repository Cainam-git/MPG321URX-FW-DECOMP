/* sys_dsc_dec_read_config  (FUN_a00a5d8c)
 *
 * Read the DSC decoder registers back into a set-up record.
 *   port: decoder
 *   cfg: record
 * Name basis: derived - unpacks register words 0x10..0x48; reverse of sys_dsc_dec_write_config
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * 'regs' is word 2 of the 12-byte record sys_dsc_dec_records[port] and is volatile, so every field re-reads
 * its register word. The record pointer is re-read after each byte store (char stores may alias it): the
 * fields are written through 'cfg->' with the register expression repeated as in the firmware.
 */
/* Set-up record of a DSC decoder (the first 0x48 bytes of the 80-byte record). Fields not named here keep
 * their offset in the name. Same layout as in sys_dsc_dec_fill_default_config. */
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
    unsigned short vtotal;
    unsigned char byte_0x12;
    unsigned char byte_0x13;
    unsigned short htotal;
    unsigned short vtotal_2;
    unsigned short hsync_width;
    unsigned short half_0x1a;
    unsigned short half_0x1c;
    unsigned short half_0x1e;
    unsigned short hactive;
    unsigned short half_0x22;
    unsigned short vactive;
    unsigned short half_0x26;
    unsigned short half_0x28;
    unsigned short half_0x2a;
    unsigned short half_0x2c;
    unsigned short half_0x2e;
    unsigned short half_0x30;
    unsigned char byte_0x32;
    unsigned char byte_0x33;
    unsigned short half_0x34;
    unsigned short half_0x36;
    unsigned short hblank_rest_div8;
    unsigned char byte_0x3a;
    unsigned char byte_0x3b;
    unsigned char byte_0x3c;
    unsigned char byte_0x3d;
    unsigned char byte_0x3e;
    unsigned char byte_0x3f;
    unsigned char byte_0x40;
    unsigned char _41[3];
    unsigned int word_0x44;
};
/* One 12-byte record per decoder; regs points at the decoder's register block. */
struct rec12 { unsigned int w0; unsigned int w4; volatile unsigned int *regs; };
extern struct rec12 sys_dsc_dec_records[];

/*
 * Read the current settings of a DSC decoder back from its registers into a set-up record. This is the
 * reverse of sys_dsc_dec_write_config. Each field is cut out of one register word of the decoder's block
 * (word offsets 0x10 to 0x48, in steps of 4): 14-bit halves (bits 16..29 and 0..13), single bits, 2- and
 * 3-bit fields. Register word -> record fields:
 *   0x10 -> +0x00, +0x02        0x14 -> +0x04..+0x0f
 *   0x18 -> vtotal (+0x10), +0x12, +0x13
 *   0x1c -> htotal (+0x14), vtotal_2 (+0x16)         0x20 -> hsync_width (+0x18), +0x1a
 *   0x24 -> +0x1c, +0x1e   0x28 -> hactive (+0x20)   0x2c -> +0x22 (12 bits), vactive (+0x24)
 *   0x30 -> +0x26, +0x28   0x34 -> +0x2a, +0x2c      0x38 -> +0x2e, +0x30
 *   0x3c -> +0x32, +0x33, +0x34   0x40 -> +0x36, hblank_rest_div8 (+0x38)
 *   0x44 -> +0x3a..+0x3f (bits 6..2, then 0..1)      0x48 -> +0x40 (bit 31), word_0x44 (bits 0..24)
 *   port: decoder number
 *   cfg:  the record to fill (bytes 0x00..0x47)
 * Caller: sys_dsc_dec_run_state.
 */
void sys_dsc_dec_read_config(unsigned char port, struct dsc_dec_config *cfg)
{
    cfg->half_0x00 = (sys_dsc_dec_records[port].regs[0x10 / 4] >> 16) & 0x3fff;
    cfg->half_0x02 = (sys_dsc_dec_records[port].regs[0x10 / 4]) & 0x3fff;
    cfg->byte_0x04 = (sys_dsc_dec_records[port].regs[0x14 / 4] >> 27) & 7;
    cfg->byte_0x05 = (sys_dsc_dec_records[port].regs[0x14 / 4] >> 23) & 7;
    cfg->byte_0x06 = sys_dsc_dec_records[port].regs[0x14 / 4] >> 15;
    cfg->byte_0x07 = (sys_dsc_dec_records[port].regs[0x14 / 4] >> 11) & 1;
    cfg->byte_0x08 = (sys_dsc_dec_records[port].regs[0x14 / 4] >> 10) & 1;
    cfg->byte_0x09 = (sys_dsc_dec_records[port].regs[0x14 / 4] >> 8) & 1;
    cfg->byte_0x0a = (sys_dsc_dec_records[port].regs[0x14 / 4] >> 7) & 1;
    cfg->byte_0x0b = (sys_dsc_dec_records[port].regs[0x14 / 4] >> 6) & 1;
    cfg->byte_0x0c = (sys_dsc_dec_records[port].regs[0x14 / 4] >> 5) & 1;
    cfg->byte_0x0d = (sys_dsc_dec_records[port].regs[0x14 / 4] >> 4) & 1;
    cfg->byte_0x0e = (sys_dsc_dec_records[port].regs[0x14 / 4] >> 3) & 1;
    cfg->byte_0x0f = sys_dsc_dec_records[port].regs[0x14 / 4] & 3;
    cfg->vtotal = (sys_dsc_dec_records[port].regs[0x18 / 4] >> 16) & 0x3fff;
    cfg->byte_0x12 = (sys_dsc_dec_records[port].regs[0x18 / 4] >> 8);
    cfg->byte_0x13 = (sys_dsc_dec_records[port].regs[0x18 / 4] >> 4) & 3;
    cfg->htotal = (sys_dsc_dec_records[port].regs[0x1c / 4] >> 16) & 0x3fff;
    cfg->vtotal_2 = (sys_dsc_dec_records[port].regs[0x1c / 4]) & 0x3fff;
    cfg->hsync_width = (sys_dsc_dec_records[port].regs[0x20 / 4] >> 16) & 0x3fff;
    cfg->half_0x1a = (sys_dsc_dec_records[port].regs[0x20 / 4]) & 0x3fff;
    cfg->half_0x1c = (sys_dsc_dec_records[port].regs[0x24 / 4] >> 16) & 0x3fff;
    cfg->half_0x1e = (sys_dsc_dec_records[port].regs[0x24 / 4]) & 0x3fff;
    cfg->hactive = (sys_dsc_dec_records[port].regs[0x28 / 4]) & 0x3fff;
    cfg->half_0x22 = (sys_dsc_dec_records[port].regs[0x2c / 4] >> 16) & 0xfff;
    cfg->vactive = (sys_dsc_dec_records[port].regs[0x2c / 4]) & 0x3fff;
    cfg->half_0x26 = (sys_dsc_dec_records[port].regs[0x30 / 4] >> 16) & 0x3fff;
    cfg->half_0x28 = (sys_dsc_dec_records[port].regs[0x30 / 4]) & 0x3fff;
    cfg->half_0x2a = (sys_dsc_dec_records[port].regs[0x34 / 4] >> 16) & 0x3fff;
    cfg->half_0x2c = (sys_dsc_dec_records[port].regs[0x34 / 4]) & 0x3fff;
    cfg->half_0x2e = (sys_dsc_dec_records[port].regs[0x38 / 4] >> 16) & 0x3fff;
    cfg->half_0x30 = (sys_dsc_dec_records[port].regs[0x38 / 4]) & 0x3fff;
    cfg->byte_0x32 = (sys_dsc_dec_records[port].regs[0x3c / 4] >> 17) & 1;
    cfg->byte_0x33 = (sys_dsc_dec_records[port].regs[0x3c / 4] >> 16) & 1;
    cfg->half_0x34 = (sys_dsc_dec_records[port].regs[0x3c / 4]) & 0x3fff;
    cfg->half_0x36 = (sys_dsc_dec_records[port].regs[0x40 / 4] >> 16) & 0x3fff;
    cfg->hblank_rest_div8 = (sys_dsc_dec_records[port].regs[0x40 / 4]) & 0x3fff;
    cfg->byte_0x3a = (sys_dsc_dec_records[port].regs[0x44 / 4] >> 6) & 1;
    cfg->byte_0x3b = (sys_dsc_dec_records[port].regs[0x44 / 4] >> 5) & 1;
    cfg->byte_0x3c = (sys_dsc_dec_records[port].regs[0x44 / 4] >> 4) & 1;
    cfg->byte_0x3d = (sys_dsc_dec_records[port].regs[0x44 / 4] >> 3) & 1;
    cfg->byte_0x3e = (sys_dsc_dec_records[port].regs[0x44 / 4] >> 2) & 1;
    cfg->byte_0x3f = sys_dsc_dec_records[port].regs[0x44 / 4] & 3;
    cfg->byte_0x40 = sys_dsc_dec_records[port].regs[0x48 / 4] >> 31;
    cfg->word_0x44 = sys_dsc_dec_records[port].regs[0x48 / 4] & 0x1ffffff;
}
