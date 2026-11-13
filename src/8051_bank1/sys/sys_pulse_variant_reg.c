/* sys_pulse_variant_reg  (FUN_CODE_db18)
 *
 * Pulse the start-up control register on chip variant 0x1A.
 * Name basis: descriptive - reg 0xF06B = 3 then 1 when chip id 0xD511 is 0x1A; called first in the application
 *   start-up
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_db18 @ 0xdb18
 * Options: OPTIMIZE(8,SPEED) (also level 7). The register 0xF06B is volatile: two writes in a row.
 */
#define CHIP_ID_1A 0x1a   /* reg_chip_id value */

extern unsigned char xdata DAT_EXTMEM_d510, reg_chip_id;
extern unsigned char volatile xdata DAT_EXTMEM_f06b;

/* On chip variant 0x1A, when the byte at 0xD510 is not zero, write 3 and
 * then 1 to the register at 0xF06B. Only caller: the call at 0x3ffa. */
void sys_pulse_variant_reg(void)
{
    if (reg_chip_id == CHIP_ID_1A && DAT_EXTMEM_d510 >= 1) {
        DAT_EXTMEM_f06b = 3;
        DAT_EXTMEM_f06b = 1;
    }
}
