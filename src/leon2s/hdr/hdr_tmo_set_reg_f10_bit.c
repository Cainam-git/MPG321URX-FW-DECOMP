/* hdr_tmo_set_reg_f10_bit  (FUN_a00d2434)
 *
 * Write one control bit of the tone-mapping register 0xD0013F10.
 *   which: 0: bit 0, other: bit 1
 *   value: new value of the bit
 * Name basis: descriptive - bit 0 (selector 0) or bit 1 (selector not 0) of 0xD0013F10, through
 *   reg_write_bit_field; every caller passes selector 0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d2434 @ 0xa00d2434 (-mcpu=v8 -Os -g)
 * Source form: the register value is read into the local local_c and copied into buf[0], the field write works
 * on buf, and buf[0] is written back; the two branches are two complete copies of this sequence.
 */
extern int reg_read32(unsigned int);
extern void reg_write_bit_field(unsigned int *, int, int, unsigned char);
extern int reg_write32(unsigned int, unsigned int);

#define TMO_REG_F10 0xd0013f10

/*
 * Write bit 0 of the tone-mapping register 0xD0013F10 (which = 0) or bit 1 of it (which non-zero) with value.
 * Always returns 1. Every caller passes which = 0: hdr_tmo_enable clears the bit, hdr_tmo_enable_second sets
 * it, hdr_init, hdr_tmo_disable and hdr_tmo_disable_and_print clear it.
 */
int hdr_tmo_set_reg_f10_bit(unsigned char which, unsigned char value)
{
    unsigned int local_c;
    unsigned int buf[1];
    
    buf[0] = 0;
    if ((which & 0xff) == 0) {
        local_c = reg_read32(TMO_REG_F10);
        buf[0] = local_c;
        reg_write_bit_field(buf, 0, 0, value & 0xff);
        reg_write32(TMO_REG_F10, buf[0]);
    } else {
        local_c = reg_read32(TMO_REG_F10);
        buf[0] = local_c;
        reg_write_bit_field(buf, 1, 1, value & 0xff);
        reg_write32(TMO_REG_F10, buf[0]);
    }
    return 1;
}
