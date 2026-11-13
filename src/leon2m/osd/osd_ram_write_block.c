/* osd_ram_write_block  (FUN_a011b4f0)
 *
 * Send a block of bytes to a menu layer's memory with command 0xD0.
 * Name basis: derived - command, address, then the data bytes; clears bit 7 of the layer's first register
 *   first
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011b4f0 @ 0xa011b4f0, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the command and address steps are the firmware's own routines
 * osd_ram_port_write_command and osd_ram_port_write_triple (as in osd_ram_write_index_run), the data step osd_ram_port_write_data and the bit update
 * osd_update_reg_bits are defined in this file; GCC inlines all of them at -O3. x->n is read before the command step.
 * The 16-bit address field is passed straight to the address step.
 */
/* Register n of a menu layer is the word at 0xCF000000 + 4 * n; the layer's first register number is
   osd_layer_bases[layer]. */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
#define R(a) (*(volatile unsigned int *)(a))
#define LAYER_REG_FIRST     0           /* bit 7 is cleared before a block is sent */
#define COMMAND_WRITE_BLOCK 0xd0
extern unsigned short osd_layer_bases[2];

/* The request record of osd_api_write_block. */
struct block_request {
    unsigned short count;                       /* number of bytes */
    unsigned short address;                     /* address in the layer's memory */
    unsigned char *data;
};

/* Set (set == 1) or clear the bits of mask in register reg of a layer; no check of layer. */
void osd_update_reg_bits(unsigned char layer, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int value = RB(osd_layer_bases[layer] + reg);
    if (set == 1) value |= mask; else value &= ~mask;
    RB(osd_layer_bases[layer] + reg) = (unsigned char)value;
}

/* The memory port of the menu layers has two register sets: side 0 (layer 0) and side 1 (any other layer).
   Every write to one of its registers is followed by a delay of 160 nops. */
#define PORT_DELAY_NOPS     0xa0
#define PORT0_COMMAND       0xcf011780
#define PORT0_ADDRESS_LOW   0xcf011784
#define PORT0_ADDRESS_MID   0xcf011788
#define PORT0_ADDRESS_HIGH  0xcf00bfcc
#define PORT0_DATA          0xcf01178c
#define PORT1_COMMAND       0xcf011794
#define PORT1_ADDRESS_LOW   0xcf011798
#define PORT1_ADDRESS_MID   0xcf01179c
#define PORT1_ADDRESS_HIGH  0xcf00c3cc
#define PORT1_DATA          0xcf0117a0

/* Write the three address bytes (bits 0..7, 8..15, 16..23) of side `side`. */
void osd_ram_port_write_triple(unsigned char side, unsigned int address)
{
    int i;

    if (side == 0) {
        *(volatile unsigned int *)PORT0_ADDRESS_LOW = address & 0xff;
        *(volatile unsigned int *)PORT0_ADDRESS_MID = (address >> 8) & 0xff;
        *(volatile unsigned int *)PORT0_ADDRESS_HIGH = (address >> 16) & 0xff;
    } else {
        *(volatile unsigned int *)PORT1_ADDRESS_LOW = address & 0xff;
        *(volatile unsigned int *)PORT1_ADDRESS_MID = (address >> 8) & 0xff;
        *(volatile unsigned int *)PORT1_ADDRESS_HIGH = (address >> 16) & 0xff;
    }
    for (i = 0; i < PORT_DELAY_NOPS; i++)
        __asm__("nop");
}

/* Write the command byte of side `side`. */
void osd_ram_port_write_command(unsigned char side, unsigned char command)
{
    int i;

    if (side == 0)
        R(PORT0_COMMAND) = command;
    else
        R(PORT1_COMMAND) = command;
    for (i = 0; i < PORT_DELAY_NOPS; i++)
        __asm__("nop");
}

/* Write one data byte of side `side`. */
void osd_ram_port_write_data(unsigned char side, unsigned char value)
{
    int i;

    if (side == 0)
        R(PORT0_DATA) = value;
    else
        R(PORT1_DATA) = value;
    for (i = 0; i < PORT_DELAY_NOPS; i++)
        __asm__("nop");
}

/*
 * Send a block of bytes to the memory of a menu layer.
 *
 *   request  count, address and data pointer of the block (see struct block_request)
 *   layer    menu layer 0 or 1; also the side of the memory port
 *
 * In this order: clear bit 7 of the layer's first register, send command 0xD0, send the 16-bit address, then
 * send the count bytes one by one. Called by osd_api_write_block.
 */
void osd_ram_write_block(struct block_request *request, unsigned char layer)
{
    unsigned short i, count;

    osd_update_reg_bits(layer, LAYER_REG_FIRST, 0x80, 0);
    count = request->count;
    osd_ram_port_write_command(layer, COMMAND_WRITE_BLOCK);
    osd_ram_port_write_triple(layer, request->address);
    for (i = 0; i < count; i++)
        osd_ram_port_write_data(layer, request->data[i]);
}
