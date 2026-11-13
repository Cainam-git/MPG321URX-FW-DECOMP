/* sys_dsc_dec_init_register_pointers  (FUN_a00a4e68)
 *
 * Fill the register block pointers of the DSC decoder.
 * Name basis: derived - record 0xA807DC04 = 0xC0100000, 0xC0100400, 0xC0100800
 *
 * Matching notes
 * --------------
 * FUN_a00a4e68 (leon2s, 0xa00a4e68-0xa00a4ec4, 92 bytes), flags -mcpu=v8 -Os -g.
 * The loop runs once ('i < 1'); -Os emits the last source store (+8) first, then +0, +4, as the firmware does.
 * void (the firmware keeps the table base in %i0 only by allocation).
 */
/* One record per DSC decoder, 12 bytes. */
struct dsc_decoder_record {
    unsigned int regs_main;     /* base of the first register block */
    unsigned int regs_second;   /* base of the second register block */
    unsigned int regs_third;    /* base of the third register block */
};
extern struct dsc_decoder_record sys_dsc_dec_records[];

/* Store the three register block addresses, 0xc0100000 / 0xc0100400 / 0xc0100800, in the record of the
 * (single) decoder. */
void sys_dsc_dec_init_register_pointers(void)
{
    unsigned char i;

    for (i = 0; i < 1; i++) {
        sys_dsc_dec_records[i].regs_main = i + 0xc0100000;
        sys_dsc_dec_records[i].regs_second = i + 0xc0100400;
        sys_dsc_dec_records[i].regs_third = i + 0xc0100800;
    }
}
