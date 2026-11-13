/* hdr_tmo_set_table_index  (FUN_a00d2378)
 *
 * Write the table index field of the tone-mapping block.
 * Name basis: descriptive - register 0xD0013F50
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d2378 @ 0xa00d2378 (-mcpu=v8 -Os -g)
 * Source form: the register value is read into the local local_c and copied into buf[0], the field write works
 * on buf, and buf[0] is written back; the two branches are two complete copies of this sequence.
 */
extern int reg_read32(unsigned int);
extern void reg_write_bit_field(unsigned int *, int, int, unsigned short);
extern int reg_write32(unsigned int, unsigned int);

#define TMO_REG_F50 0xd0013f50  /* bits 0..11 are set here; bit 31 / 30 are set by hdr_tmo_set_reg_f50_bit */

/*
 * Store index in bits 11..0 of the tone-mapping register 0xD0013F50 and leave its other bits. Always returns 1.
 * hdr_update_tone_curve calls it with the smoothed level; the curve loader (hdr_apply_tone_curve) calls it with the last
 * curve entry number (0x100) before it writes the curve.
 */
int hdr_tmo_set_table_index(unsigned short index)
{
    unsigned int local_c;
    unsigned int buf[1];
    
    buf[0] = 0;
    local_c = reg_read32(TMO_REG_F50);
    buf[0] = local_c;
    reg_write_bit_field(buf, 0xb, 0, index & 0xffff);
    reg_write32(TMO_REG_F50, buf[0]);
    return 1;
}
