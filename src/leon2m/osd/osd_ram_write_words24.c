/* osd_ram_write_words24  (FUN_a011bac0)
 *
 * Send 24-bit entries to a menu layer's memory with command 0xA0.
 * Name basis: derived - three bytes of each 4-byte group, then the layer's write counters advance
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011bac0 @ 0xa011bac0-0xa011bd60 (168 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the step helpers are the firmware's own osd_ram_port_write_command, osd_ram_port_write_triple and
 * osd_ram_port_write_data, defined here and inlined at -O3 (as in osd_ram_write_index_run); the body is written twice,
 * once for layer 0 and once for the other side, and in that second copy the data bytes go to side 1 (no side
 * test in the loop at 0xa011bc8c).
 */
#define R(a) (*(volatile unsigned int *)(a))

#define COMMAND_WRITE_WORDS24 0xa0

extern unsigned char osd_glyph_write_count[];
extern unsigned short osd_glyph_write_address[];
extern unsigned char osd_cell_heights[];

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
 * Send the picture data of one cell (a glyph) to a menu layer's memory, then advance the layer's glyph
 * counters.
 *
 *   data   groups of four bytes; osd_cell_heights[layer] groups are sent. Of each group the bytes 2, 1
 *          and 0 go out, in that order (byte 3 is not sent).
 *   layer  menu layer 0 or 1; also the side of the memory port
 *
 * In this order: command 0xA0, the 16-bit address osd_glyph_write_address[layer], the data bytes. Afterwards
 * osd_glyph_write_address[layer] and osd_glyph_write_count[layer] are each incremented by one; osd_ram_write_index_run
 * reads them to write the cell numbers of the glyphs just sent.
 *
 * Called by osd_api_write_words24 (from osd_draw_text, once per cell of text).
 */
void osd_ram_write_words24(unsigned char *data, unsigned char layer)
{
    unsigned char i, byte_count;

    if (layer == 0) {
        osd_ram_port_write_command(0, COMMAND_WRITE_WORDS24);
        osd_ram_port_write_triple(0, osd_glyph_write_address[0]);
        byte_count = osd_cell_heights[0] * 4;
        for (i = 0; i < byte_count; i += 4) {
            osd_ram_port_write_data(0, data[i + 2]);
            osd_ram_port_write_data(0, data[i + 1]);
            osd_ram_port_write_data(0, data[i]);
        }
    } else {
        osd_ram_port_write_command(layer, COMMAND_WRITE_WORDS24);
        osd_ram_port_write_triple(layer, osd_glyph_write_address[layer]);
        byte_count = osd_cell_heights[layer] * 4;
        for (i = 0; i < byte_count; i += 4) {
            osd_ram_port_write_data(1, data[i + 2]);
            osd_ram_port_write_data(1, data[i + 1]);
            osd_ram_port_write_data(1, data[i]);
        }
    }
    osd_glyph_write_address[layer]++;
    osd_glyph_write_count[layer]++;
}
