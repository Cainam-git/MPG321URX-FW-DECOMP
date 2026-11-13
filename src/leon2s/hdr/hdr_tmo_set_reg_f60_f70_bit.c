/* hdr_tmo_set_reg_f60_f70_bit  (FUN_a00d23bc)
 *
 * Write bit 31 of the tone-mapping register 0xD0013F60 (selector 0) or 0xD0013F70.
 *   which: 0: register 0xD0013F60, other: 0xD0013F70
 *   value: new value of bit 31
 * Name basis: descriptive - bit 31 of 0xD0013F60 (selector 0) or of 0xD0013F70 (selector not 0), through
 *   reg_write_bit_field; every caller passes selector 0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d23bc @ 0xa00d23bc (-mcpu=v8 -Os -g)
 * Source form: the register value is read into the local local_c and copied into buf[0], the field write works
 * on buf, and buf[0] is written back; the two branches are two complete copies of this sequence.
 */
extern int reg_read32(unsigned int);
extern void reg_write_bit_field(unsigned int *, int, int, unsigned char);
extern int reg_write32(unsigned int, unsigned int);

#define TMO_LUT_ACCESS 0xd0013f60       /* register used when which is 0 */
#define TMO_REG_F70    0xd0013f70       /* register used otherwise */

/*
 * Write bit 31 of the tone-mapping register 0xD0013F60 (which = 0) or of 0xD0013F70 (which non-zero) with value.
 * Always returns 1. Every caller passes which = 0: hdr_tmo_enable and hdr_tmo_enable_second set the bit,
 * hdr_init, hdr_tmo_disable and hdr_tmo_disable_and_print clear it.
 */
int hdr_tmo_set_reg_f60_f70_bit(unsigned char which, unsigned char value)
{
    unsigned int local_c;
    unsigned int buf[1];
    
    buf[0] = 0;
    if ((which & 0xff) == 0) {
        local_c = reg_read32(TMO_LUT_ACCESS);
        buf[0] = local_c;
        reg_write_bit_field(buf, 0x1f, 0x1f, value & 0xff);
        reg_write32(TMO_LUT_ACCESS, buf[0]);
    } else {
        local_c = reg_read32(TMO_REG_F70);
        buf[0] = local_c;
        reg_write_bit_field(buf, 0x1f, 0x1f, value & 0xff);
        reg_write32(TMO_REG_F70, buf[0]);
    }
    return 1;
}
