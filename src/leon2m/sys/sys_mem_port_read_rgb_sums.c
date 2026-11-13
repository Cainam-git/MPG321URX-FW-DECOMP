/* sys_mem_port_read_rgb_sums  (FUN_a01139c8)
 *
 * Read twelve blocks through the memory port and store the average of every eight value triples.
 * Note: Each call gives 16 entries in each of three output arrays (third, second and first value of the
 *   triples).
 * Name basis: descriptive - blocks of eight words read as value triples; three sums divided by 8 stored per
 *   entry; called by pq_read_zone_color_averages once per row
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01139c8, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - every read uses the literal port address (the word at 0x001a2f18 that the firmware loads is the compiler's
 *    literal-pool copy of 0xcf011f94);
 *  - the block count is a local variable (blocks = 12): a literal 12 compiles to a different compare;
 *  - 'count++' is a statement of its own before the test for eight; the sums are cleared in the order first,
 *    second, third (the order of the reads) and stored in the order third, second, first; 'phase = 0' follows
 *    the last test of case 2;
 *  - the flush is the same text in each case (macro FLUSH_IF_EIGHT, same expansion).
 */
#define REG(a) (*(volatile unsigned int *)(a))

/* Memory port of the picture hardware (the same port as sys_mem_port_read_word_blocks). */
#define MEM_PORT_ADDR_BYTE0 0xcf011fa0      /* start address, low byte first */
#define MEM_PORT_ADDR_BYTE1 0xcf011fa4
#define MEM_PORT_ADDR_BYTE2 0xcf011fa8
#define MEM_PORT_ADDR_BYTE3 0xcf011fac
#define MEM_PORT_START_A    0xcf011f84      /* 0x80 to both registers starts the read of a block */
#define MEM_PORT_START_B    0xcf011f8c
#define MEM_PORT_STATUS     0xcf011f90      /* reads 0x80 when the block is ready */
#define MEM_PORT_DATA       0xcf011f94      /* four reads give one word */
#define MEM_PORT_READY      0x80
#define MEM_PORT_POLLS      0xffff          /* at most this many status reads */

#define MEM_BLOCKS          12              /* blocks of eight words */
#define MEM_BLOCK_WORDS     8
#define SUMS_PER_ENTRY      8               /* triples added up for one output entry */

/* When eight triples are summed, store the sums divided by 8 as the next entry and start new sums. */
#define FLUSH_IF_EIGHT() \
                if (count == SUMS_PER_ENTRY) { \
                    out_third[entry] = sum_third >> 3; \
                    out_second[entry] = sum_second >> 3; \
                    out_first[entry] = sum_first >> 3; \
                    count = 0; \
                    entry++; \
                    sum_first = 0; \
                    sum_second = 0; \
                    sum_third = 0; \
                }

/*
 * Read twelve blocks of eight words each (384 values) from the memory port and reduce them to three arrays
 * of 16 entries.
 *
 *   start_address  word address of the first block; every further block is the next address
 *   out_third      output array that receives the average of the third value of each triple
 *   out_second     the same for the second value
 *   out_first      the same for the first value
 *
 * The values arrive in order and are taken as triples (first, second, third), each added to its own sum.
 * After every eighth triple the three sums divided by 8 are stored as one entry in the three arrays and the
 * sums start again. A word holds four values, so a triple can begin in the middle of a word and end in the next
 * one; `phase` is the number of values of the current triple already read when a word starts.
 * Called from pq_read_zone_color_averages, which passes pq_zone_averages_red, _green and _blue in that order,
 * once per row of 16 entries.
 */
void sys_mem_port_read_rgb_sums(unsigned int start_address, unsigned char *out_third, unsigned char *out_second, unsigned char *out_first)
{
    unsigned short block, word, polls, entry;
    unsigned char count, phase;
    unsigned int sum_third, sum_second, sum_first;
    unsigned short blocks;

    count = 0;
    entry = 0;
    sum_third = 0;
    sum_second = 0;
    sum_first = 0;
    phase = 0;
    blocks = MEM_BLOCKS;

    for (block = 0; block < blocks; block++) {
        REG(MEM_PORT_ADDR_BYTE0) = start_address;
        REG(MEM_PORT_ADDR_BYTE1) = start_address >> 8;
        REG(MEM_PORT_ADDR_BYTE2) = start_address >> 16;
        REG(MEM_PORT_ADDR_BYTE3) = start_address >> 24;
        REG(MEM_PORT_START_A) = MEM_PORT_READY;
        REG(MEM_PORT_START_B) = MEM_PORT_READY;
        polls = MEM_PORT_POLLS;
        while (REG(MEM_PORT_STATUS) != MEM_PORT_READY) {
            if (--polls == 0)
                break;
        }
        for (word = block * 8; word < block * 8 + MEM_BLOCK_WORDS; word++) {
            switch (phase) {
            case 0:     /* triple starts at the first value of the word: one triple and the first value of the next */
                sum_first += REG(MEM_PORT_DATA);
                sum_second += REG(MEM_PORT_DATA);
                sum_third += REG(MEM_PORT_DATA);
                count++;
                FLUSH_IF_EIGHT()
                sum_first += REG(MEM_PORT_DATA);
                phase++;
                break;
            case 1:     /* one value of a triple is already read: finish it, start the next with two values */
                sum_second += REG(MEM_PORT_DATA);
                sum_third += REG(MEM_PORT_DATA);
                count++;
                FLUSH_IF_EIGHT()
                sum_first += REG(MEM_PORT_DATA);
                sum_second += REG(MEM_PORT_DATA);
                phase++;
                break;
            case 2:     /* two values are already read: finish that triple, then one whole triple follows */
                sum_third += REG(MEM_PORT_DATA);
                count++;
                FLUSH_IF_EIGHT()
                sum_first += REG(MEM_PORT_DATA);
                sum_second += REG(MEM_PORT_DATA);
                sum_third += REG(MEM_PORT_DATA);
                count++;
                FLUSH_IF_EIGHT()
                phase = 0;
                break;
            }
        }
        start_address++;
    }
}
