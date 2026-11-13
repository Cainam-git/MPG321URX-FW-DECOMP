/* hdr_tmo_set_reg_f50_bit  (FUN_a00d2300)
 *
 * Write one control bit of the tone-mapping register 0xD0013F50.
 *   which: 0: bit 31, other: bit 30
 *   value: new value of the bit
 * Name basis: descriptive - bit 31 (selector 0) or bit 30 (selector not 0) of 0xD0013F50, through
 *   reg_write_bit_field; every caller passes selector 0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d2300 @ 0xa00d2300 (-mcpu=v8 -Os -g).
 * Source form: the register value is read into the local local_c and copied into buf[0], the field write works
 * on buf, and buf[0] is written back; the two branches are two complete copies of this sequence.
 */
extern int reg_read32(unsigned int);
extern void reg_write_bit_field(unsigned int *, int, int, unsigned char);
extern int reg_write32(unsigned int, unsigned int);

#define TMO_REG 0xd0013f50   /* bit 31 / bit 30 are the bits written below */

/*
 * Write one bit of the tone-mapping register 0xd0013f50: bit 31 when which is 0, bit 30 otherwise, set to value.
 * Always returns 1. Every caller passes which = 0: hdr_tmo_enable and hdr_tmo_enable_second set the bit,
 * hdr_init, hdr_tmo_disable and hdr_tmo_disable_and_print clear it.
 */
int hdr_tmo_set_reg_f50_bit(unsigned char which, unsigned char value)
{
    unsigned int local_c;
    unsigned int buf[1];
    
    buf[0] = 0;
    if ((which & 0xff) == 0) {
        local_c = reg_read32(TMO_REG);
        buf[0] = local_c;
        reg_write_bit_field(buf, 0x1f, 0x1f, value & 0xff);
        reg_write32(TMO_REG, buf[0]);
    } else {
        local_c = reg_read32(TMO_REG);
        buf[0] = local_c;
        reg_write_bit_field(buf, 0x1e, 0x1e, value & 0xff);
        reg_write32(TMO_REG, buf[0]);
    }
    return 1;
}
