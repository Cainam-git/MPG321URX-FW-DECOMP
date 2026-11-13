/* pq_fga_expand_gamma_blocks_scaled  (FUN_a012e2ac)
 *
 * Decode three stored 32-byte blocks into scaled gamma tables and load them.
 * Name basis: derived - as pq_fga_expand_gamma_blocks with a scaling in hundredths
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012e2ac @ 0xa012e2ac-0xa012e3ec (80 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: written like the twin pq_fga_expand_gamma_blocks (the stored byte is read as
 * stored[(unsigned char)block_offset + j] with the key XOR in a second statement). The declarations keep the
 * twin's 'unsigned short unused_slot[2]', which this routine does not use: the firmware frame (save -632) holds
 * its 8-byte slot at fp-536, the twin's position, with no access. The key array here is not const.
 */
extern const unsigned char pq_fga_gamma_block_codes[32];
extern void pq_gamma_write_primary_lut(int, int, int, unsigned char *);

#define GAMMA_CHANNELS     3                /* colour channels 0..2, one 32-byte block each */
#define FGA_BLOCK_BYTES    0x20
#define PRIMARY_LUT_BYTES  0x200            /* 256 entries of two bytes */
#define STEPS_PER_BYTE     8                /* entries interpolated from one stored byte */

/*
 * Turn the three stored 32-byte blocks in 'stored' (channel n at n * 0x20) into one 256-entry table per colour
 * channel and write it with pq_gamma_write_primary_lut (offset 0, 0x200 bytes).
 *
 *   stored        the bytes read from the FGA storage
 *   unused_flag   not used
 *
 * Every stored byte is XORed with the key 0F F0 10 01 (by its position modulo 4); the decoded bytes are steps
 * that add up. Each stored byte j gives eight entries: the running sum * 16 plus 0/8 .. 7/8 of the step * 16,
 * times pq_fga_gamma_block_codes[j] / 100. Each entry is written as two bytes, value << 2 then value >> 6.
 *
 * Called by pq_fga_load_gamma_from_storage when the FGA layout byte (device settings +0x37) is 1.
 */
void pq_fga_expand_gamma_blocks_scaled(unsigned char *stored, unsigned char unused_flag)
{
    unsigned char key[4] = { 0x0f, 0xf0, 0x10, 0x01 };
    unsigned char table[PRIMARY_LUT_BYTES];
    unsigned short unused_slot[2];
    int channel, j, k;
    unsigned char step;
    int block_offset;
    unsigned short out_pos, sum, value, scaled;

    block_offset = 0;
    for (channel = 0; channel <= GAMMA_CHANNELS - 1; channel++) {
        out_pos = 0;
        sum = 0;
        for (j = 0; j < 32; j++) {
            step = stored[(unsigned char)block_offset + j];
            step ^= key[j % 4];
            for (k = 0; k < STEPS_PER_BYTE; k++) {
                value = (sum << 4) + ((k * step << 4) + 4) / 8;
                scaled = (unsigned int)(value * pq_fga_gamma_block_codes[j]) / 100;
                table[out_pos++] = scaled << 2;
                table[out_pos++] = scaled >> 6;
            }
            sum += step;
        }
        pq_gamma_write_primary_lut(channel, 0, PRIMARY_LUT_BYTES, table);
        block_offset += FGA_BLOCK_BYTES;
    }
}
