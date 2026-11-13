/* sys_mem_port_read_word_blocks  (FUN_a0113cd8)
 *
 * Read a number of 8-word blocks through the memory port.
 * Name basis: derived - sets the address, waits for the ready value 0x80, reads through 0xCF011F94; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0113cd8 @ 0xa0113cd8-0xa0113eb4 (119 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: unsigned short counters; each word is built with '=' and three '|=' (stored after every read);
 * the flags include -msoft-float (register addresses rebuilt inside the block loop).
 */
#define REG(a) (*(volatile unsigned int *)(a))

/* Memory port registers. */
#define MEM_PORT_ADDR_BYTE0 0xcf011fa0  /* address, low byte ... */
#define MEM_PORT_ADDR_BYTE1 0xcf011fa4
#define MEM_PORT_ADDR_BYTE2 0xcf011fa8
#define MEM_PORT_ADDR_BYTE3 0xcf011fac  /* ... high byte */
#define MEM_PORT_COMMAND    0xcf011f84  /* 0x80 is written here after the address */
#define MEM_PORT_READ_START 0xcf011f8c  /* 0x80 is written here to start the read */
#define MEM_PORT_STATUS     0xcf011f90  /* reads MEM_PORT_READY when the data can be read */
#define MEM_PORT_READ_DATA  0xcf011f94  /* data comes out one byte per read */
#define MEM_PORT_START      0x80
#define MEM_PORT_READY      0x80
#define WORDS_PER_BLOCK     8           /* a block is 32 bytes */
#define READY_POLLS         0xffff      /* at most this many reads of the status register per block */
#define MODE_LOW_BYTE_FIRST 1           /* the first byte read is the low byte of the word; else the high byte */

/*
 * Read `count` blocks of 8 words each from the memory port into `out`.
 *
 * out    destination, 8 words per block
 * addr   port address of the first block; block i is read from addr + i
 * count  number of blocks
 * mode   MODE_LOW_BYTE_FIRST: of the four bytes read for a word the first is the low byte; any other value:
 *        the first is the high byte
 *
 * For each block the address is written byte by byte (low byte first), 0x80 goes to the command register and to
 * the read start register, then the status register is polled until it reads 0x80 (or READY_POLLS reads are
 * used up; the block is read either way). Read counterpart of sys_mem_port_write_blocks. No caller is known.
 */
void sys_mem_port_read_word_blocks(unsigned int *out, unsigned int addr, unsigned short count, unsigned char mode)
{
    unsigned short block, word, polls_left;

    for (block = 0; block < count; block++) {
        REG(MEM_PORT_ADDR_BYTE0) = addr;
        REG(MEM_PORT_ADDR_BYTE1) = addr >> 8;
        REG(MEM_PORT_ADDR_BYTE2) = addr >> 16;
        REG(MEM_PORT_ADDR_BYTE3) = addr >> 24;
        REG(MEM_PORT_COMMAND) = MEM_PORT_START;
        REG(MEM_PORT_READ_START) = MEM_PORT_START;
        polls_left = READY_POLLS;
        while (REG(MEM_PORT_STATUS) != MEM_PORT_READY) {
            if (--polls_left == 0)
                break;
        }
        if (mode == MODE_LOW_BYTE_FIRST) {
            for (word = block * WORDS_PER_BLOCK; word < block * WORDS_PER_BLOCK + WORDS_PER_BLOCK; word++) {
                out[word] = REG(MEM_PORT_READ_DATA);
                out[word] |= REG(MEM_PORT_READ_DATA) << 8;
                out[word] |= REG(MEM_PORT_READ_DATA) << 16;
                out[word] |= REG(MEM_PORT_READ_DATA) << 24;
            }
        } else {
            for (word = block * WORDS_PER_BLOCK; word < block * WORDS_PER_BLOCK + WORDS_PER_BLOCK; word++) {
                out[word] = REG(MEM_PORT_READ_DATA) << 24;
                out[word] |= REG(MEM_PORT_READ_DATA) << 16;
                out[word] |= REG(MEM_PORT_READ_DATA) << 8;
                out[word] |= REG(MEM_PORT_READ_DATA);
            }
        }
        addr++;
    }
}
