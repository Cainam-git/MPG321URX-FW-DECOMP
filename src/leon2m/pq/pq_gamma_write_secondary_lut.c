/* pq_gamma_write_secondary_lut  (FUN_a010af6c)
 *
 * Write a 64-byte block of the secondary gamma table of one colour channel.
 * Name basis: derived - table command derived from the channel; used by the FGA gamma loader
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010af6c @ 0xa010af6c, flags -mcpu=v8 -O3 -g.
 * Source form: the shift is written as '<< 4'; the form 'channel * 16' gives a different register allocation.
 */
#define GAMMA_BLOCK_SIZE 64

extern int reg_table_port_write(int device, int offset, int length, int data);

/*
 * Write a 64-byte block of the secondary gamma table of one colour channel through the table port, at offset 0.
 *
 *   channel  colour channel; the table port device number is (((channel << 4) - 46) | 4) & 0xFE, which is
 *            0xD6, 0xE6, 0xF6 for channels 0..2
 *   data     address of the 64 bytes
 *
 * Callers: pq_fga_expand_gamma_blocks and pq_load_gamma.
 */
void pq_gamma_write_secondary_lut(int channel, int data)
{
    /* The device number of the channel's secondary table. */
    reg_table_port_write((((channel << 4) - 46) | 4) & 0xfe, 0, GAMMA_BLOCK_SIZE, data);
}
