/* pq_gamma_write_primary_lut  (FUN_a010ae8c)
 *
 * Write a block of the primary gamma table of one colour channel.
 * Name basis: derived - table command (channel << 4) | 4; the last entry is repeated at the table end
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010ae8c @ 0xa010ae8c-0xa010af18 (35 words), flags -mcpu=v8 -O3 -g.
 * Source form: the two bytes are stored into the local buffer in ascending order; channel is an unsigned int
 * parameter (the cut to 8 bits happens in the unsigned char device).
 */
#define REG_CF00EAC0 (*(volatile unsigned int *)0xcf00eac0)
#define REG_CF00EAC0_BIT7 0x80                 /* bit 7: set by pq_gamma_set_lut_options (first argument 0) */
#define GAMMA_TABLE_END_OFFSET 0x100           /* offset at which the last two bytes are written again */
extern void reg_table_port_write(unsigned char, unsigned short, unsigned short, unsigned char *);

/*
 * Write a block of the primary gamma table of one colour channel through the table port (reg_table_port_write).
 *
 *   channel                colour channel; the table port device number is (channel << 4) | 4, cut to 8 bits
 *                          (0x04, 0x14, 0x24 for channels 0..2)
 *   offset, length, data   block position, byte count and bytes to write
 *
 * While bit 7 of REG_CF00EAC0 is set, a block that ends exactly at GAMMA_TABLE_END_OFFSET
 * (offset + length / 2 == 0x100) is followed by a second write of its last two bytes at offset 0x100.
 *
 * Callers: pq_api_write_gamma_lut, pq_fga_expand_gamma_blocks, pq_fga_expand_gamma_blocks_scaled and
 * pq_load_gamma_curve_interpolated.
 */
void pq_gamma_write_primary_lut(unsigned int channel, unsigned short offset, unsigned short length, unsigned char *data)
{
    unsigned char device;
    unsigned char last_two_bytes[2];

    device = channel << 4 | 4;
    reg_table_port_write(device, offset, length, data);
    if (REG_CF00EAC0 & REG_CF00EAC0_BIT7) {
        if (offset + (length >> 1) == GAMMA_TABLE_END_OFFSET) {
            last_two_bytes[0] = data[length - 2];
            last_two_bytes[1] = data[length - 1];
            reg_table_port_write(device, GAMMA_TABLE_END_OFFSET, 2, last_two_bytes);
        }
    }
}
