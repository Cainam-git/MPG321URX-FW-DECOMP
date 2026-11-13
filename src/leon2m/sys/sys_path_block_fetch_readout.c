/* sys_path_block_fetch_readout  (FUN_a012043c)
 *
 * Fetch the read-out words of a signal path block when it has finished.
 * Returns: 1 when data was fetched, else 0
 * Name basis: descriptive - registers 0x50/0x51/0x57; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012043c @ 0xa012043c-0xa01205c0 (388 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the byte read helper read_byte (the helper of sys_path_block_is_enabled with the 0xcf011428 write before the
 * clamp) is inlined; the count is computed between the two reads; sys_path_block_readouts is an array of
 * unsigned short pairs, so the two clears keep their order in the scheduler.
 */
#define R(a) (*(volatile unsigned int *)(a))
/* Register `a` of the register area: address 0xCF000000 + 4 * a. */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short sys_path_block_bases[2];     /* register base of each of the two path blocks */
extern unsigned short sys_path_block_readouts[][2];      /* the two read-out halfwords of each path block */

#define PATH_ACCESS_REG       0xcf011428   /* bits 0..1 are set before every path block register access */
#define PATH_REG_READOUT_SETUP 0x50        /* bits 6..7: log2 of (words / 4); see sys_path_block_start_readout */
#define PATH_REG_READOUT_START 0x51        /* bit 0 set: read-out not ready */
#define PATH_REG_READOUT_DATA  0x57        /* three reads give one word */

/* Read one byte of register `reg` of path block `block`; a block number above 1 reads block 0. */
static unsigned char read_byte(unsigned int block, unsigned char reg)
{
    R(PATH_ACCESS_REG) |= 3;
    if (block > 1)
        block = 0;
    return RB(sys_path_block_bases[block] + reg);
}

/*
 * Fetch the read-out words of path block `block` into `out`.
 *
 * Returns 0 and fetches nothing while bit 0 of register 0x51 is set. Otherwise it clears both halfwords of
 * sys_path_block_readouts[block] and fetches 4 << (bits 6..7 of register 0x50) words: each word is three bytes
 * read from register 0x57, the first read as the low byte (word = third << 16 | second << 8 | first).
 * Returns 1 after fetching. A block number above 1 reads block 0 but clears the table entry of that number.
 * Nothing calls this routine.
 */
int sys_path_block_fetch_readout(unsigned int block, unsigned int *out)
{
    unsigned char setup, status, count, i, first, second, third;

    setup = read_byte(block, PATH_REG_READOUT_SETUP);
    count = 4 << (setup >> 6);
    status = read_byte(block, PATH_REG_READOUT_START);
    if (status & 1)
        return 0;
    sys_path_block_readouts[block][0] = 0;
    sys_path_block_readouts[block][1] = 0;
    for (i = 0; i < count; i++) {
        first = read_byte(block, PATH_REG_READOUT_DATA);
        second = read_byte(block, PATH_REG_READOUT_DATA);
        third = read_byte(block, PATH_REG_READOUT_DATA);
        out[i] = (third << 16) | (second << 8) | first;
    }
    return 1;
}
