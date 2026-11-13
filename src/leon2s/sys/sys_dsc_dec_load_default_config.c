/* sys_dsc_dec_load_default_config  (FUN_a00a5ce8)
 *
 * Set the DSC decoder clock and load its default set-up with the decoder held off.
 * Name basis: derived - sys_dsc_dec_set_clock(1, 0), clears record 0xA807DB74, bit 0 of words 0xB0/0xBC off,
 *   bit 13 of 0xC0 on
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a5ce8 @ 0xa00a5ce8-0xa00a5d8c (41 words).
 * The mask 1 is a volatile local: the firmware stores it to the stack and loads it back before each of the
 * two clears.
 */
struct dsc_decoder_record { volatile unsigned int *regs_main; unsigned int regs_second; unsigned int regs_third; };
extern struct dsc_decoder_record sys_dsc_dec_records[];
extern unsigned char sys_dsc_dec_default_config[];
extern void sys_dsc_dec_set_clock(unsigned int, unsigned short);
extern void lib_memset(void *, int, int);
extern void sys_dsc_dec_write_default_config(unsigned char);

#define DSC_REG_B0 (0xb0 / 4)   /* word offsets in the first register block */
#define DSC_REG_BC (0xbc / 4)
#define DSC_REG_C0 (0xc0 / 4)

/* Set the decoder clock (sys_dsc_dec_set_clock(1, 0)), clear the 0x90-byte sys_dsc_dec_default_config and, for
 * the decoder, clear bit 0 of the registers at offsets 0xb0 and 0xbc of its first register block, write the
 * default set-up with sys_dsc_dec_write_default_config and set bit 13 of the register at offset 0xc0.
 * Called by sys_dsc_dec_init.
 */
void sys_dsc_dec_load_default_config(void)
{
    unsigned char i;
    volatile unsigned int mask;

    sys_dsc_dec_set_clock(1, 0);
    lib_memset(sys_dsc_dec_default_config, 0, 0x90);
    for (i = 0; i < 1; i++) {
        mask = 1;
        sys_dsc_dec_records[i].regs_main[DSC_REG_B0] &= ~mask;
        mask = 1;
        sys_dsc_dec_records[i].regs_main[DSC_REG_BC] &= ~mask;
        sys_dsc_dec_write_default_config(i);
        sys_dsc_dec_records[i].regs_main[DSC_REG_C0] |= 0x2000;
    }
}
