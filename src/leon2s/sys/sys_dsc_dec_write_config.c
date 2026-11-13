/* sys_dsc_dec_write_config  (VBP_tmp)
 *
 * Write a DSC decoder set-up record to its registers and check the delay lines.
 *   port: decoder
 *   cfg: 80-byte record
 *   with_defaults: 1 = defaults
 * Note: Label VBP_tmp is a printed variable name, not the routine name.
 * Name basis: derived - prints 'DSC VBP_tmp', '[WARNING] V front porch ... DSC decode required delay lines';
 *   reverse of sys_dsc_dec_read_config
 *
 * Matching notes
 * --------------
 * VBP_tmp (leon2s 0xa00a53b0-0xa00a5cb4, 2308 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - single bits are set with |= and cleared through the volatile local mask (the firmware stores the bit to
 *    its stack slot and reads it back before each clear, as in sys_dsc_dec_run_state);
 *  - the register pointer is named in every statement (CFG_REG re-reads it after each if / else join), and
 *    regs_third points to volatile words, so every field write reads its word again;
 *  - the record fields are read where they are used (code hoisting moves the loads after the bit-3 test into
 *    the block of that test).
 */

/* Set-up record of a DSC decoder (80 bytes). Same layout and field names as in sys_dsc_dec_read_config,
 * sys_dsc_dec_fill_default_config and sys_dsc_dec_fill_hdmi21_timing; fields not named keep their offset. */
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
    unsigned short vtotal;              /* +0x10 */
    unsigned char byte_0x12;
    unsigned char byte_0x13;
    unsigned short htotal;              /* +0x14 */
    unsigned short vtotal_2;            /* +0x16, second copy of the vertical total */
    unsigned short hsync_width;         /* +0x18 */
    unsigned short half_0x1a;
    unsigned short half_0x1c;
    unsigned short half_0x1e;
    unsigned short hactive;             /* +0x20 */
    unsigned short half_0x22;
    unsigned short vactive;             /* +0x24 */
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
    unsigned short hblank_rest_div8;    /* +0x38, (htotal - h front porch - hactive) / 8 */
    unsigned char byte_0x3a;
    unsigned char byte_0x3b;
    unsigned char byte_0x3c;
    unsigned char byte_0x3d;
    unsigned char byte_0x3e;
    unsigned char byte_0x3f;
    unsigned char byte_0x40;
    unsigned char _41[3];
    unsigned int word_0x44;
    unsigned short pixel_clock;         /* +0x48 */
    unsigned short mode_word_34;        /* +0x4a */
    unsigned short vback_porch;         /* +0x4c, printed as "DSC VBP_tmp" */
    unsigned char _4e[2];
};

/* One 12-byte record per decoder with the bases of its three register blocks; the set-up goes to the third. */
struct dsc_decoder_record { unsigned int regs_main; unsigned int regs_second; volatile unsigned int *regs_third; };
extern struct dsc_decoder_record sys_dsc_dec_records[];
extern int dbg_printf(const char *, ...);
extern int sys_dsc_dec_calc_pixel_clock(unsigned short, unsigned short, int);
extern void sys_dsc_dec_set_clock(unsigned char, unsigned short);

#define DEFAULT_VBACK_PORCH   5         /* used for the default set-up (with_defaults 1) */
#define DSC_DELAY_LINES       4         /* the warning's limit: "VFP should be greater than 4 lines" */

/* Register word at byte offset 'offset' of the decoder's third register block. */
#define CFG_REG(offset) sys_dsc_dec_records[port].regs_third[(offset) / 4]
/* Set 'bit' of a register word when 'on' is non-zero, else clear it. */
#define CFG_BIT(offset, bit, on) if (on) CFG_REG(offset) |= (bit); else { mask = (bit); CFG_REG(offset) &= ~mask; }

/*
 * Write a set-up record into the register words 0x10..0x48 of the third register block of a DSC decoder.
 * sys_dsc_dec_read_config reads the same words back.
 *
 *   port           decoder number
 *   cfg            the set-up record
 *   with_defaults  0: the record holds a real timing (sys_dsc_dec_run_state, from the HDMI 2.1 input);
 *                  1: the default record (sys_dsc_dec_write_default_config); the clock is then not set and the
 *                  vertical back porch is taken as 5.
 *
 * Phases:
 *   1. word 0x1c: htotal / 8 in bits 16..29, 0x3fff in bits 0..13.
 *   2. only for a real timing: compute the pixel clock (sys_dsc_dec_calc_pixel_clock: pixel_clock * htotal /
 *      mode_word_34 * 100, in kHz), print the back porch, check the vertical front porch (vtotal - vactive -
 *      back porch) and warn when it is 4 lines or fewer, then set the decoder clock from the pixel clock in MHz.
 *   3. the record fields into words 0x10 to 0x48, field by field (each in its bits, the rest of the word kept).
 *      Words 0x24 and 0x40 get the back porch + 3 and + 4.
 * Words 0x30 to 0x3c and the fields that sys_dsc_dec_read_config reads from them are not written here.
 */
void sys_dsc_dec_write_config(unsigned char port, struct dsc_dec_config *cfg, unsigned char with_defaults)
{
    volatile unsigned int mask;
    unsigned short htotal = cfg->htotal;
    unsigned int vback_porch;
    unsigned int vfront_porch;
    unsigned int pixel_clock_khz;

    /* 1. Horizontal total in units of 8 pixels. */
    CFG_REG(0x1c) = (CFG_REG(0x1c) & 0xc000ffff) | (((htotal >> 3) & 0x3fff) << 16);
    CFG_REG(0x1c) = (CFG_REG(0x1c) & 0xffffc000) | 0x3fff;

    /* 2. Clock and the front porch check (real timing only). */
    vback_porch = DEFAULT_VBACK_PORCH;
    if (with_defaults == 0) {
        pixel_clock_khz = sys_dsc_dec_calc_pixel_clock(htotal, cfg->mode_word_34, cfg->pixel_clock);
        vback_porch = cfg->vback_porch;
        dbg_printf("DSC VBP_tmp %ld\r\n", vback_porch);
        vfront_porch = cfg->vtotal - cfg->vactive - vback_porch;
        if (vfront_porch <= DSC_DELAY_LINES)
            dbg_printf("\033[31;1m[WARNING] V front porch (= %ld) is %s DSC decode required delay lines, VFP should be greater than %d lines\n",
                         vfront_porch, vfront_porch == DSC_DELAY_LINES ? "equal to" : "less than", DSC_DELAY_LINES);
        sys_dsc_dec_set_clock(0, pixel_clock_khz / 1000);
    }

    /* 3. The record fields, word by word. */
    CFG_REG(0x10) = (CFG_REG(0x10) & 0xc000ffff) | ((cfg->half_0x00 & 0x3fff) << 16);
    CFG_REG(0x10) = (CFG_REG(0x10) & 0xffffc000) | (cfg->half_0x02 & 0x3fff);

    /* Word 0x14: bits 28..30, 24..26 and 16..23, then single bits, then bits 0..1. sys_dsc_dec_read_config
       reads the first three fields one bit lower (from bits 27, 23 and 15). */
    CFG_REG(0x14) = (CFG_REG(0x14) & 0x8fffffff) | ((cfg->byte_0x04 & 7) << 28);
    CFG_REG(0x14) = (CFG_REG(0x14) & 0xf8ffffff) | (cfg->byte_0x05 << 24);
    CFG_REG(0x14) = (CFG_REG(0x14) & 0xff00ffff) | (cfg->byte_0x06 << 16);
    CFG_BIT(0x14, 0x800, cfg->byte_0x07);
    CFG_BIT(0x14, 0x400, cfg->byte_0x08);
    CFG_BIT(0x14, 0x100, cfg->byte_0x09);
    CFG_BIT(0x14, 0x80, cfg->byte_0x0a);
    CFG_BIT(0x14, 0x40, cfg->byte_0x0b);
    /* Bit 5 is the inverse of byte_0x0c (read back without inverting). */
    if (cfg->byte_0x0c) { mask = 0x20; CFG_REG(0x14) &= ~mask; } else CFG_REG(0x14) |= 0x20;
    CFG_BIT(0x14, 0x10, cfg->byte_0x0d);
    CFG_BIT(0x14, 8, cfg->byte_0x0e);
    CFG_REG(0x14) = (CFG_REG(0x14) & ~3) | (cfg->byte_0x0f & 3);

    /* Word 0x18: bits 16..29 fixed at 0x3fff; vtotal is not written. */
    CFG_REG(0x18) = (CFG_REG(0x18) & 0xc000ffff) | 0x3fff0000;
    CFG_REG(0x18) = (CFG_REG(0x18) & 0xffff00ff) | (cfg->byte_0x12 << 8);
    CFG_REG(0x18) = (CFG_REG(0x18) & ~0x30) | ((cfg->byte_0x13 & 3) << 4);

    CFG_REG(0x20) = (CFG_REG(0x20) & 0xc000ffff) | (((cfg->hsync_width >> 3) & 0x3fff) << 16);
    CFG_REG(0x20) = (CFG_REG(0x20) & 0xffffc000) | (cfg->half_0x1a & 0x3fff);
    CFG_REG(0x24) = (CFG_REG(0x24) & 0xffffc000) | (cfg->hblank_rest_div8 & 0x3fff);
    CFG_REG(0x24) = (CFG_REG(0x24) & 0xc000ffff) | (((vback_porch + 3) & 0x3fff) << 16);
    CFG_REG(0x28) = (CFG_REG(0x28) & 0xffffc000) | ((cfg->hactive >> 3) & 0x3fff);
    CFG_REG(0x2c) = (CFG_REG(0x2c) & 0xf000ffff) | ((cfg->half_0x22 & 0xfff) << 16);
    CFG_REG(0x2c) = (CFG_REG(0x2c) & 0xffffc000) | (cfg->vactive & 0x3fff);
    CFG_REG(0x40) = (CFG_REG(0x40) & 0xffffc000) | (cfg->hblank_rest_div8 & 0x3fff);
    CFG_REG(0x40) = (CFG_REG(0x40) & 0xc000ffff) | (((vback_porch + 4) & 0x3fff) << 16);

    /* Word 0x44: bits 6..2 and 0..1; word 0x48: bit 31 and bits 0..24. */
    CFG_BIT(0x44, 0x40, cfg->byte_0x3a);
    CFG_BIT(0x44, 0x20, cfg->byte_0x3b);
    CFG_BIT(0x44, 0x10, cfg->byte_0x3c);
    CFG_BIT(0x44, 8, cfg->byte_0x3d);
    CFG_BIT(0x44, 4, cfg->byte_0x3e);
    CFG_REG(0x44) = (CFG_REG(0x44) & ~3) | (cfg->byte_0x3f & 3);
    CFG_BIT(0x48, 0x80000000, cfg->byte_0x40);
    CFG_REG(0x48) = (CFG_REG(0x48) & 0xfe000000) | (cfg->word_0x44 & 0x1ffffff);
}
