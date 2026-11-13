/* sys_mem_port_write_word_blocks  (FUN_a01138fc)
 *
 * Write a number of 32-byte blocks from a word array through the memory port.
 * Name basis: descriptive - address in 0xCF011FA0..FAC, data through 0xCF011F88; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01138fc @ 0xa01138fc-0xa01139c8 (204 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: the word is read through a union of a plain word and four 8-bit bit-fields (the loads are
 * ldub / lduh / ldub / ld of the word, low eight bits written). The inner index `word` is initialised in its
 * declaration ('word = 0', overwritten by the inner loop before any read), which sets the order in which the
 * six hoisted register addresses are built. As in sibling sys_mem_port_write_blocks, the flags include
 * -msoft-float.
 */
#define REG(a) (*(volatile unsigned int *)(a))

/* Memory port registers. */
#define MEM_PORT_ADDR_BYTE0 0xcf011fa0  /* address, low byte ... */
#define MEM_PORT_ADDR_BYTE1 0xcf011fa4
#define MEM_PORT_ADDR_BYTE2 0xcf011fa8
#define MEM_PORT_ADDR_BYTE3 0xcf011fac  /* ... high byte */
#define MEM_PORT_COMMAND    0xcf011f84  /* 0x80 is written here after the address */
#define MEM_PORT_WRITE_DATA 0xcf011f88  /* data goes in one byte per write */
#define MEM_PORT_START      0x80
#define WORDS_PER_BLOCK     8           /* a block is 32 bytes */

/* A data word seen as four bytes, most significant byte first. */
union word_bytes { unsigned int value; struct { unsigned int byte3:8, byte2:8, byte1:8, byte0:8; } f; };

/*
 * Write `count` blocks of 8 words each from `words` to the memory port.
 *
 * words  the data, 8 words per block
 * addr   port address of the first block; block i goes to addr + i
 * count  number of blocks
 *
 * For each block the address is written byte by byte (low byte first) to the four address registers, 0x80 to
 * the command register, then the 8 words one after the other, each as four byte writes from the most
 * significant byte down. No caller is known.
 */
void sys_mem_port_write_word_blocks(union word_bytes *words, unsigned int addr, unsigned int count)
{
    unsigned int block, word = 0, first_word;

    first_word = 0;
    for (block = 0; block < count; block++) {
        REG(MEM_PORT_ADDR_BYTE0) = addr;
        REG(MEM_PORT_ADDR_BYTE1) = addr >> 8;
        REG(MEM_PORT_ADDR_BYTE2) = addr >> 16;
        REG(MEM_PORT_ADDR_BYTE3) = addr >> 24;
        REG(MEM_PORT_COMMAND) = MEM_PORT_START;
        for (word = first_word; word < first_word + WORDS_PER_BLOCK; word++) {
            REG(MEM_PORT_WRITE_DATA) = words[word].f.byte3;
            REG(MEM_PORT_WRITE_DATA) = words[word].f.byte2;
            REG(MEM_PORT_WRITE_DATA) = words[word].f.byte1;
            REG(MEM_PORT_WRITE_DATA) = words[word].f.byte0;
        }
        first_word += WORDS_PER_BLOCK;
        addr++;
    }
}
