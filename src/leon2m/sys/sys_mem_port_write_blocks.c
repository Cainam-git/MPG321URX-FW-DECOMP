/* sys_mem_port_write_blocks  (FUN_a0113eb4)
 *
 * Write a number of 32-byte blocks through the memory port.
 * Name basis: derived - address registers 0xCF011FA0..FAC, data through 0xCF011F88; used for the profile table
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0113eb4 @ 0xa0113eb4-0xa011403c (98 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: unsigned short counters (block and byte index); the flags include -msoft-float (the register
 * address constants are rebuilt inside the block loop instead of being hoisted).
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
#define BLOCK_BYTES         32
#define MODE_ASCENDING      1           /* bytes of each group of four go out in buffer order; else reversed */

/*
 * Write `count` blocks of 32 bytes from `data` to the memory port.
 *
 * data   the bytes, 32 per block
 * addr   port address of the first block; block i goes to addr + i
 * count  number of blocks
 * mode   MODE_ASCENDING: each group of four bytes is written in buffer order; any other value: in reverse order
 *
 * For each block the address is written byte by byte (low byte first), 0x80 goes to the command register, then
 * the 32 bytes follow in groups of four.
 * Called by pq_load_profile_table.
 */
void sys_mem_port_write_blocks(const unsigned char *data, unsigned int addr, unsigned char count, unsigned char mode)
{
    unsigned short block, i;

    for (block = 0; block < count; block++) {
        REG(MEM_PORT_ADDR_BYTE0) = addr;
        REG(MEM_PORT_ADDR_BYTE1) = addr >> 8;
        REG(MEM_PORT_ADDR_BYTE2) = addr >> 16;
        REG(MEM_PORT_ADDR_BYTE3) = addr >> 24;
        REG(MEM_PORT_COMMAND) = MEM_PORT_START;
        if (mode == MODE_ASCENDING) {
            for (i = block * BLOCK_BYTES; i < block * BLOCK_BYTES + BLOCK_BYTES; i += 4) {
                REG(MEM_PORT_WRITE_DATA) = data[i];
                REG(MEM_PORT_WRITE_DATA) = data[i + 1];
                REG(MEM_PORT_WRITE_DATA) = data[i + 2];
                REG(MEM_PORT_WRITE_DATA) = data[i + 3];
            }
        } else {
            for (i = block * BLOCK_BYTES; i < block * BLOCK_BYTES + BLOCK_BYTES; i += 4) {
                REG(MEM_PORT_WRITE_DATA) = data[i + 3];
                REG(MEM_PORT_WRITE_DATA) = data[i + 2];
                REG(MEM_PORT_WRITE_DATA) = data[i + 1];
                REG(MEM_PORT_WRITE_DATA) = data[i];
            }
        }
        addr++;
    }
}
