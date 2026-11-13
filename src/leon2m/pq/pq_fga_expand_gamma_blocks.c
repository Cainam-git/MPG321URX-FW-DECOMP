/* pq_fga_expand_gamma_blocks  (FUN_a012e004)
 *
 * Decode three stored 32-byte blocks into full gamma tables and load them.
 * Name basis: derived - key-XORed blocks expanded to 0x200-byte tables for the primary or secondary gamma
 *   table write
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012e004 @ 0xa012e004-0xa012e2ac (170 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the conversion through double gives the soft-float calls __floatsidf (__floatsidf), __adddf3
 * (__adddf3) and __fixunsdfsi (__fixunsdfsi); 0.5 is the literal at 0x19a638. The key is a const local
 * array (its initialising stores keep their place before the load of the 0.5 literal); the scaled value is
 * stored in an unsigned short array element (the firmware's halfword store at fp-536); the second loop reads
 * the stored byte stored[(unsigned char)block_offset + j] and XORs the key byte in a second statement (address
 * formed inside the loop, ldub of the stored byte before the key byte).
 */
#define GAMMA_CHANNELS     3                /* colour channels 0..2, one 32-byte block each */
#define FGA_BLOCK_BYTES    0x20
#define SECOND_SET_OFFSET  0x60             /* the second set of three blocks in a double block read */
#define PRIMARY_LUT_BYTES  0x200            /* 256 entries of two bytes */
#define STEPS_PER_BYTE     8                /* entries interpolated from one stored byte */
#define FIRST_INTERPOLATED 4                /* stored byte where interpolation starts after the second set */

extern const unsigned char pq_fga_gamma_block_codes[32];   /* all 100 in FW.021 */
extern void pq_gamma_write_primary_lut(int, int, int, unsigned char *);
extern void pq_gamma_write_secondary_lut(int, unsigned char *);

/*
 * Turn the stored gamma data in 'stored' into one table per colour channel and write it.
 *
 *   stored           the bytes read from the FGA storage: three 32-byte blocks (channel n at n * 0x20), and with
 *                    double_block a second set of three at +0x60
 *   double_block     1 when two sets were read (FGA_DOUBLE_BLOCK): build the 0x200-byte primary table;
 *                    0: build the secondary table
 *
 * Every stored byte is first XORed with the key 0F F0 10 01 (by its position modulo 4); the decoded bytes are
 * steps that add up. Each table entry is written as two bytes, value << 2 then value >> 6.
 *
 * double_block set: 32 entries from the second set, each the running sum * 16; then stored bytes 4..31 of the
 * first set, eight entries each: the running sum * 16 plus 0/8 .. 7/8 of the byte's step * 16
 * (32 + 28 * 8 = 256 entries). The table goes to pq_gamma_write_primary_lut (offset 0, 0x200 bytes).
 * double_block clear: entry 0 is 0, then for every stored byte j the running sum * 16, times
 * pq_fga_gamma_block_codes[j] / 100. pq_gamma_write_secondary_lut sends the first 64 bytes, so the entry of
 * byte 31 is built but not sent.
 *
 * Called by pq_fga_load_gamma_from_storage when the FGA layout byte (byte_0x37) is not 1;
 * pq_fga_expand_gamma_blocks_scaled is the decode for layout 1.
 */
void pq_fga_expand_gamma_blocks(unsigned char *stored, unsigned char double_block)
{
    const unsigned char key[4] = { 0x0f, 0xf0, 0x10, 0x01 };
    unsigned char table[PRIMARY_LUT_BYTES];
    unsigned short scaled[2];
    int channel, j, k;
    unsigned char step;
    int block_offset;
    unsigned short out_pos, sum, sum16;
    unsigned int value;

    block_offset = 0;
    for (channel = 0; channel <= GAMMA_CHANNELS - 1; channel++) {
        out_pos = 0;
        sum = 0;
        if (double_block) {
            /* The first 32 entries: the running sum of the second set's steps. */
            for (j = 0; j < 32; j++) {
                step = stored[(unsigned char)block_offset + SECOND_SET_OFFSET + j] ^ key[j % 4];
                value = (unsigned int)((double)((sum + step) << 4) + 0.5);
                table[out_pos++] = value << 2;
                table[out_pos++] = value >> 6;
                sum += step;
            }
        } else {
            table[0] = 0;
            table[1] = 0;
            out_pos = 2;
        }
        for (j = 0; j < 32; j++) {
            /* After the second set, the first set's bytes 0..3 are skipped. */
            if (j == 0 && double_block)
                j = FIRST_INTERPOLATED;
            step = stored[(unsigned char)block_offset + j];
            step ^= key[j % 4];
            if (double_block) {
                for (k = 0; k < STEPS_PER_BYTE; k++) {
                    value = (sum << 4) + (k * (step << 4) + 4) / 8;
                    table[out_pos++] = value << 2;
                    table[out_pos++] = value >> 6;
                }
            } else {
                value = step + sum;
                sum16 = value << 4;
                scaled[0] = (unsigned int)(sum16 * pq_fga_gamma_block_codes[j]) / 100;
                table[out_pos++] = scaled[0] << 2;
                table[out_pos++] = scaled[0] >> 6;
            }
            sum += step;
        }
        if (double_block)
            pq_gamma_write_primary_lut(channel, 0, PRIMARY_LUT_BYTES, table);
        else
            pq_gamma_write_secondary_lut(channel, table);
        block_offset += FGA_BLOCK_BYTES;
    }
}
