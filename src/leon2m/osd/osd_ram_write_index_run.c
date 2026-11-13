/* osd_ram_write_index_run  (FUN_a011b648)
 *
 * Write a run of rising byte values, padded with zeros, into a menu layer's memory.
 * Name basis: descriptive - command 0x90 or 0x40 with a 16-bit address, then zeros, start + i, zeros
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011b648 @ 0xa011b648-0xa011bac0 (286 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the step helpers are the firmware's own osd_ram_port_write_command (command byte),
 * osd_ram_port_write_triple (address bytes v & 0xff, (v >> 8) & 0xff, (v >> 16) & 0xff) and osd_ram_port_write_data (data byte),
 * defined here and inlined at -O3; the address is the unsigned short addr, so the third address byte is 0
 * (sll/srl 16 at 0xa011b6bc / 0xa011b83c); the body is written twice, once for layer 0 and once for the other
 * side; start is computed before the address sum.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define COMMAND_PLANE_1  0x90           /* command when the plane argument is 1 */
#define COMMAND_PLANE_0  0x40           /* command otherwise */

/* Text modes of a layer (osd_ram_write_index_run puts no empty cells in front of the text in mode 0, all
   unused cells in mode 1 and half of them in mode 2). */
enum {
    TEXT_ALIGN_LEFT   = 0,
    TEXT_ALIGN_RIGHT  = 1,
    TEXT_ALIGN_CENTRE = 2
};

extern unsigned char osd_glyph_write_count[];
extern unsigned short osd_glyph_write_address[];
extern unsigned int osd_layer_text_modes[];             /* text mode of each layer (low byte used) */
extern unsigned short osd_layer_columns[];           /* columns of each layer in cells */

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
 * Write the cell numbers of a text into a field of cells of a menu layer: a row of `width` cells, the text's
 * glyph numbers in a run, and empty cells (value 0) before and after it.
 *
 *   plane   1: command 0x90, otherwise command 0x40
 *   column  first cell of the field
 *   row     row of the field; the cell address is column + row * columns of the layer
 *   width   number of cells in the field
 *   layer   menu layer 0 or 1; also the side of the memory port
 *
 * The glyphs are those just sent with osd_ram_write_words24: the run is osd_glyph_write_count[layer] cells
 * long and starts at number osd_glyph_write_address[layer] - osd_glyph_write_count[layer], rising by one. In
 * front of the run come none (left), width - count (right) or (width - count) / 2 (centre) empty cells,
 * following the layer's text mode; empty cells fill the rest of the field.
 *
 * Called by osd_api_write_index_run (from osd_draw_text).
 */
void osd_ram_write_index_run(unsigned char plane, unsigned int column, unsigned int row, unsigned char width, unsigned char layer)
{
    unsigned char i, empty_in_front;
    unsigned int text_mode;
    unsigned short first_glyph;
    unsigned short address;

    first_glyph = osd_glyph_write_address[layer] - osd_glyph_write_count[layer];
    row *= osd_layer_columns[layer];
    column += row;
    address = column;
    if (layer == 0) {
        if (plane == 1)
            osd_ram_port_write_command(0, COMMAND_PLANE_1);
        else
            osd_ram_port_write_command(0, COMMAND_PLANE_0);
        osd_ram_port_write_triple(0, address);
        empty_in_front = 0;
        text_mode = (unsigned char)osd_layer_text_modes[0];
        if ((unsigned char)text_mode != 0) {
            if ((unsigned char)text_mode == TEXT_ALIGN_RIGHT)
                empty_in_front = width - osd_glyph_write_count[0];
            else if ((unsigned char)text_mode == TEXT_ALIGN_CENTRE)
                empty_in_front = (width - osd_glyph_write_count[0]) >> 1;
        }
        for (i = 0; i < empty_in_front; i++)
            osd_ram_port_write_data(0, 0);
        for (i = 0; i < osd_glyph_write_count[0]; i++)
            osd_ram_port_write_data(0, first_glyph + i);
        for (i = osd_glyph_write_count[0] + empty_in_front; i < width; i++)
            osd_ram_port_write_data(0, 0);
    } else {
        /* The same for the other side. */
        if (plane == 1)
            osd_ram_port_write_command(layer, COMMAND_PLANE_1);
        else
            osd_ram_port_write_command(layer, COMMAND_PLANE_0);
        osd_ram_port_write_triple(layer, address);
        empty_in_front = 0;
        text_mode = (unsigned char)osd_layer_text_modes[layer];
        if ((unsigned char)text_mode != 0) {
            if ((unsigned char)text_mode == TEXT_ALIGN_RIGHT)
                empty_in_front = width - osd_glyph_write_count[layer];
            else if ((unsigned char)text_mode == TEXT_ALIGN_CENTRE)
                empty_in_front = (width - osd_glyph_write_count[layer]) >> 1;
        }
        for (i = 0; i < empty_in_front; i++)
            osd_ram_port_write_data(layer, 0);
        for (i = 0; i < osd_glyph_write_count[layer]; i++)
            osd_ram_port_write_data(layer, first_glyph + i);
        for (i = osd_glyph_write_count[layer] + empty_in_front; i < width; i++)
            osd_ram_port_write_data(layer, 0);
    }
}
