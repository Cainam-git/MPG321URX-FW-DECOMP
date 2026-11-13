/* pq_fga_load_gamma_from_storage  (FUN_a012e3ec)
 *
 * Read one stored gamma block set and load it into the gamma tables.
 * Name basis: derived - block chosen by one bit of the table mask 0x508; used by the routine that prints
 *   'LoadGamma'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012e3ec @ 0xa012e3ec-0xa012e550 (89 words), flags -mcpu=v8 -O3 -g.
 * Source form: the index count is an inlined static helper with an unsigned char result (0xff for no match); the
 * offset index * 0x60 is computed into an unsigned short local before the length choice.
 */

/* The FGA block in storage; fields and helper as in FGA_Init (FGA_Init). */
#define FGA_BLOCK_KEYS      0x508    /* bit 0x008 = key 0x16, 0x100 = key 0x20, 0x400 = key 0x24 */
#define FGA_BLOCK_SIZE      0x60     /* one stored gamma block */
#define FGA_DOUBLE_BLOCK    0x200    /* asks for two blocks (0xc0 bytes) and sets the flag */

struct fga_location {
    unsigned char fga_selector;         /* +0x34: storage device of the FGA block (nvram_read) */
    unsigned int address : 16;          /* +0x35: start address of the FGA block on that device */
    unsigned char byte_0x37;            /* +0x37: block layout, see FGA_Init */
};
struct device_settings_record {
    unsigned char bytes_0x00[0x34];
    struct fga_location fga;
    unsigned char rest[0x18];
};
extern struct device_settings_record device_settings;
extern void *memset(void *, int, unsigned int);
extern void nvram_read(unsigned char, unsigned short, unsigned short, void *);
extern void pq_fga_expand_gamma_blocks_scaled(unsigned char *, unsigned char);
extern void pq_fga_expand_gamma_blocks(unsigned char *, unsigned char);

/* Number of FGA_BLOCK_KEYS bits below the single bit 'bit' (0x008 -> 0, 0x100 -> 1, 0x400 -> 2); 0xFF when bit
   shares no bit with the keys. */
static unsigned char block_index(unsigned short bit)
{
    unsigned char j;
    unsigned char index = 0;

    if (!(bit & FGA_BLOCK_KEYS))
        index = 0xff;
    else {
        for (j = 0; (bit >> j) != 1; j++)
            if ((FGA_BLOCK_KEYS >> j) & 1)
                index++;
    }
    return index;
}

/*
 * Read the stored gamma block set selected by bit into the tables.
 *
 *   bit  one set bit selecting the block: 0x008 -> block 0, 0x100 -> block 1, 0x400 -> block 2.
 *        With FGA_DOUBLE_BLOCK (0x200) set, 0xC0 bytes (two blocks) are read instead of 0x60.
 *        Any bit outside FGA_BLOCK_KEYS (0x200 alone too) gives block index 0xFF, so the read starts
 *        0xFF * 0x60 = 0x5FA0 bytes after the FGA start address.
 *
 * The bytes are read with nvram_read (device and start address from device settings +0x34 / +0x35) into a
 * cleared 0xC0-byte buffer. An empty nested loop of (length >> 4) x 16 passes follows the read. The buffer then
 * goes to pq_fga_expand_gamma_blocks_scaled when device settings byte +0x37 is 1, else to
 * pq_fga_expand_gamma_blocks, with a flag that is 1 when FGA_DOUBLE_BLOCK is set or byte +0x37 is 1, else 0.
 *
 * Caller: pq_load_gamma.
 */
void pq_fga_load_gamma_from_storage(unsigned int bit)
{
    unsigned char buf[0xc0];
    unsigned char row, i, len;
    unsigned short off;
    unsigned char flag;

    memset(buf, 0, sizeof(buf));
    flag = 0;
    len = FGA_BLOCK_SIZE;
    off = block_index(bit) * FGA_BLOCK_SIZE;
    if (bit & FGA_DOUBLE_BLOCK) {
        len = 0xc0;
        flag = 1;
    } else if (device_settings.fga.byte_0x37 == 1) {
        len = FGA_BLOCK_SIZE;
        flag = 1;
    }
    nvram_read(device_settings.fga.fga_selector, device_settings.fga.address + off, len, buf);
    for (row = 0; row < (len >> 4); row++)
        for (i = 0; i < 16; i++)
            ;
    if (device_settings.fga.byte_0x37 == 1)
        pq_fga_expand_gamma_blocks_scaled(buf, flag);
    else
        pq_fga_expand_gamma_blocks(buf, flag);
}
