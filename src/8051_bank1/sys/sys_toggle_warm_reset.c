/* sys_toggle_warm_reset  (FUN_CODE_d1de)
 *
 * Pulse the warm-reset control bits and log the warm reset.
 * Note: Registers 0xF04F and 0xD570 are written several times on purpose.
 * Name basis: derived - prints '0x4570[5] toggle ==> warm Reset!!' after the register writes
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d1de @ 0xd1de  Byte-exact with OPTIMIZE(8,SPEED).
 * Source form: 0xF04F and the array at 0xD570 are volatile: the firmware writes them two and three times in a row.
 * 0xD571..0xD577 are reached by INC DPTR from 0xD570, so they are one array.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f04f;
extern unsigned char volatile xdata DAT_EXTMEM_d570[];
extern unsigned char xdata DAT_EXTMEM_cc8b;
extern void lib_printf517(void *fmt, ...) large;

/*
 * Write the warm-reset control registers in a fixed sequence and print
 * "0x4570[5] toggle ==> warm Reset!!". The sequence: 0xF04F = 0x10 then
 * 0x11; 0xD570 = 0x80, 0x60, 0x40 (three writes to the same byte);
 * 0xD571..0xD577 = 00 00 20 00 00 00 00; then bit 3 of 0xCC8B is cleared.
 */
void sys_toggle_warm_reset(void)
{
    DAT_EXTMEM_f04f = 0x10;
    DAT_EXTMEM_f04f = 0x11;
    DAT_EXTMEM_d570[0] = 0x80;
    DAT_EXTMEM_d570[0] = 0x60;
    DAT_EXTMEM_d570[0] = 0x40;
    DAT_EXTMEM_d570[1] = 0;
    DAT_EXTMEM_d570[2] = 0;
    DAT_EXTMEM_d570[3] = 0x20;
    DAT_EXTMEM_d570[4] = 0;
    DAT_EXTMEM_d570[5] = 0;
    DAT_EXTMEM_d570[6] = 0;
    DAT_EXTMEM_d570[7] = 0;
    DAT_EXTMEM_cc8b &= 0xf7;
    lib_printf517((void code *)0xcec2);
}
