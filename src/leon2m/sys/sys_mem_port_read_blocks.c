/* sys_mem_port_read_blocks  (FUN_a011403c)
 *
 * Read a number of 32-byte blocks through the memory port into a buffer.
 * Name basis: derived - data through 0xCF011F94; used by the update file checksum
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011403c @ 0xa011403c-0xa01141fc (112 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: unsigned short counters; the flags include -msoft-float (register addresses rebuilt inside the
 * loop).
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
#define BLOCK_BYTES         32
#define READY_POLLS         0xffff      /* at most this many reads of the status register per block */
#define MODE_ASCENDING      1           /* bytes of each group of four are stored in buffer order; else reversed */

/*
 * Read `count` blocks of 32 bytes from the memory port into `out`.
 *
 * out    destination, 32 bytes per block
 * addr   port address of the first block; block i is read from addr + i
 * count  number of blocks
 * mode   MODE_ASCENDING: each group of four bytes read is stored in buffer order; any other value: in
 *        reverse order
 *
 * For each block the address is written byte by byte (low byte first), 0x80 goes to the command register and to
 * the read start register, then the status register is polled until it reads 0x80 (or READY_POLLS reads are used
 * up; the block is read either way). Byte-buffer counterpart of sys_mem_port_read_word_blocks.
 * Called by fwupd_verify_file_checksum.
 */
void sys_mem_port_read_blocks(unsigned char *out, unsigned int addr, unsigned char count, unsigned char mode)
{
    unsigned short block, i, polls_left;

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
        if (mode == MODE_ASCENDING) {
            for (i = block * BLOCK_BYTES; i < block * BLOCK_BYTES + BLOCK_BYTES; i += 4) {
                out[i] = REG(MEM_PORT_READ_DATA);
                out[i + 1] = REG(MEM_PORT_READ_DATA);
                out[i + 2] = REG(MEM_PORT_READ_DATA);
                out[i + 3] = REG(MEM_PORT_READ_DATA);
            }
        } else {
            for (i = block * BLOCK_BYTES; i < block * BLOCK_BYTES + BLOCK_BYTES; i += 4) {
                out[i + 3] = REG(MEM_PORT_READ_DATA);
                out[i + 2] = REG(MEM_PORT_READ_DATA);
                out[i + 1] = REG(MEM_PORT_READ_DATA);
                out[i] = REG(MEM_PORT_READ_DATA);
            }
        }
        addr++;
    }
}
