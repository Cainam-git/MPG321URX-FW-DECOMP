/* osd_ram_write_packed_block  (FUN_a011c4cc)
 *
 * Send a block to a menu layer's memory, plain or with runs of 0x00/0xFF expanded.
 * Name basis: derived - command, address and data from a record; optional run-length form
 *
 * Matching notes
 * --------------
 * leon2m 0xa011c4cc-0xa011c6c8 (508 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the RB() register macro accesses 'volatile unsigned long'; with 'volatile unsigned int' (the type of
 * the selected pointers) the registers of the inlined bit clear differ.
 */
#define RB(a) (*(volatile unsigned long *)(0xcf000000 | ((a) << 2)))
extern unsigned short osd_layer_bases[2];

/* The memory port of a menu layer: one set of five registers per side (side 0 = layer 0, side 1 = the other). */
#define PORT0_COMMAND      0xcf011780
#define PORT0_ADDRESS_LOW  0xcf011784
#define PORT0_ADDRESS_MID  0xcf011788
#define PORT0_ADDRESS_HIGH 0xcf00bfcc
#define PORT0_DATA         0xcf01178c
#define PORT1_COMMAND      0xcf011794
#define PORT1_ADDRESS_LOW  0xcf011798
#define PORT1_ADDRESS_MID  0xcf01179c
#define PORT1_ADDRESS_HIGH 0xcf00c3cc
#define PORT1_DATA         0xcf0117a0
/* Empty loop passes after every port write. */
#define PORT_DELAY_NOPS    0xa0

/* Layer register 0, bit 7: cleared before a block is sent. */
#define LAYER_REG_FIRST    0
#define LAYER_REG_FIRST_BIT7 0x80

/* One block request, as built by osd_api_write_packed_block. */
struct packed_block {
    unsigned short count;       /* number of data bytes in `data` (packed bytes when run-length coded) */
    unsigned short pad;
    unsigned int command;       /* only the high nibble is sent */
    union { unsigned int word; unsigned short half[2]; } address;   /* low byte, next byte and high halfword go to the three address ports */
    unsigned char *data;
};

/* Set or clear the bits of `mask` in register `reg` of layer `blk`. */
void osd_update_reg_bits(unsigned char blk, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int v = RB(osd_layer_bases[blk] + reg);
    if (set == 1) v |= mask; else v &= ~mask;
    RB(osd_layer_bases[blk] + reg) = (unsigned char)v;
}

/*
 * Send the data of one block request to the memory of the layer on `side`.
 *   run_length : 0 = every data byte is sent as it is;
 *                otherwise a data byte of 0x00 or 0xFF is followed by a count byte and is sent that many times
 *                (a count of 0 means 256). Any other byte is sent as it is.
 *   req        : the block: command (high nibble only), address, number of data bytes, data
 *   side       : 0 = layer 0, otherwise the other layer
 * Order: bit 7 of layer register 0 is cleared, then the command, the address (the word, the word shifted down 8 bits and its high halfword) and the
 * data bytes go to the port of the side. Each port write is followed by the delay loop.
 * Called by osd_api_write_packed_block.
 */
void osd_ram_write_packed_block(int run_length, struct packed_block *req, unsigned char side)
{
    volatile unsigned int *data_port;
    volatile unsigned int *command_port;
    volatile unsigned int *address_low_port;
    volatile unsigned int *address_mid_port;
    volatile unsigned int *address_high_port;
    unsigned short count, i;
    unsigned char value, repeat;
    int k;

    if (side == 0) {
        address_high_port = (volatile unsigned int *)PORT0_ADDRESS_HIGH;
        command_port = (volatile unsigned int *)PORT0_COMMAND;
        address_low_port = (volatile unsigned int *)PORT0_ADDRESS_LOW;
        address_mid_port = (volatile unsigned int *)PORT0_ADDRESS_MID;
        data_port = (volatile unsigned int *)PORT0_DATA;
    } else {
        address_high_port = (volatile unsigned int *)PORT1_ADDRESS_HIGH;
        command_port = (volatile unsigned int *)PORT1_COMMAND;
        address_low_port = (volatile unsigned int *)PORT1_ADDRESS_LOW;
        address_mid_port = (volatile unsigned int *)PORT1_ADDRESS_MID;
        data_port = (volatile unsigned int *)PORT1_DATA;
    }
    osd_update_reg_bits(side, LAYER_REG_FIRST, LAYER_REG_FIRST_BIT7, 0);
    *command_port = req->command & 0xf0;
    count = req->count;
    for (k = 0; k < PORT_DELAY_NOPS; k++)
        __asm__("nop");
    *address_low_port = req->address.word;
    *address_mid_port = req->address.word >> 8;
    *address_high_port = req->address.half[0];
    for (k = 0; k < PORT_DELAY_NOPS; k++)
        __asm__("nop");
    if (run_length == 0) {
        for (i = 0; i < count; i++) {
            *data_port = req->data[i];
            for (k = 0; k < PORT_DELAY_NOPS; k++)
                __asm__("nop");
        }
    } else {
        for (i = 0; i < count; i++) {
            value = req->data[i];
            if (value == 0 || value == 0xff) {
                /* the next data byte is the repeat count */
                repeat = req->data[++i];
                do {
                    *data_port = value;
                    for (k = 0; k < PORT_DELAY_NOPS; k++)
                        __asm__("nop");
                } while (--repeat);
            } else {
                *data_port = value;
                for (k = 0; k < PORT_DELAY_NOPS; k++)
                    __asm__("nop");
            }
        }
    }
}
