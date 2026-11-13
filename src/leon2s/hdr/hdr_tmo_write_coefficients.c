/* hdr_tmo_write_coefficients  (FUN_a00d24ac)
 *
 * Write nine table values into the coefficient fields of the tone-mapping block.
 * Name basis: descriptive - registers 0xD0013F18..0xD0013F28
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d24ac @ 0xa00d24ac-0xa00d25f4, -mcpu=v8 -Os -g.
 * Source form: the word local is initialised to 0 at its declaration (the firmware clears it first); the
 * register helpers are the ROM routines outside the image (reg_read32, reg_write_bit_field, reg_write32).
 */
extern unsigned int hdr_tmo_coefficients[];
extern unsigned int reg_read32(unsigned int);
extern void reg_write_bit_field(unsigned int *, int, int, unsigned int);
extern void reg_write32(unsigned int, unsigned int);

#define TMO_COEF_REG_0 0xd0013f18       /* registers of the tone-mapping block that take the coefficients */
#define TMO_COEF_REG_1 0xd0013f1c
#define TMO_COEF_REG_2 0xd0013f20
#define TMO_COEF_REG_3 0xd0013f24
#define TMO_COEF_REG_4 0xd0013f28       /* receives only the low field */

/*
 * Write the nine words of hdr_tmo_coefficients to the tone-mapping block, two to a register: the even word into
 * bits 15..0 and the odd word into bits 31..16 of 0xD0013F18, F1C, F20 and F24; the ninth word into bits 15..0
 * of 0xD0013F28. The other bits of each register stay as they are. Always returns 1. Called by hdr_init after it
 * has restored or kept the table.
 */
int hdr_tmo_write_coefficients(void)
{
    unsigned int local = 0;

    local = reg_read32(TMO_COEF_REG_0);
    reg_write_bit_field(&local, 0xf, 0, hdr_tmo_coefficients[0]);
    reg_write_bit_field(&local, 0x1f, 0x10, hdr_tmo_coefficients[1]);
    reg_write32(TMO_COEF_REG_0, local);
    local = reg_read32(TMO_COEF_REG_1);
    reg_write_bit_field(&local, 0xf, 0, hdr_tmo_coefficients[2]);
    reg_write_bit_field(&local, 0x1f, 0x10, hdr_tmo_coefficients[3]);
    reg_write32(TMO_COEF_REG_1, local);
    local = reg_read32(TMO_COEF_REG_2);
    reg_write_bit_field(&local, 0xf, 0, hdr_tmo_coefficients[4]);
    reg_write_bit_field(&local, 0x1f, 0x10, hdr_tmo_coefficients[5]);
    reg_write32(TMO_COEF_REG_2, local);
    local = reg_read32(TMO_COEF_REG_3);
    reg_write_bit_field(&local, 0xf, 0, hdr_tmo_coefficients[6]);
    reg_write_bit_field(&local, 0x1f, 0x10, hdr_tmo_coefficients[7]);
    reg_write32(TMO_COEF_REG_3, local);
    local = reg_read32(TMO_COEF_REG_4);
    reg_write_bit_field(&local, 0xf, 0, hdr_tmo_coefficients[8]);
    reg_write32(TMO_COEF_REG_4, local);
    return 1;
}
