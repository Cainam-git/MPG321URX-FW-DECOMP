/* osd_ram_write_cells  (FUN_a011bd60)
 *
 * Write a row of 16-bit cell values at a cell position of a menu layer.
 * Name basis: derived - command 0x70, address x + y * columns, low and high byte of each value; unused
 *   directly
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011bd60 @ 0xa011bd60, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the command and address steps are the firmware's own osd_ram_port_write_command
 * and osd_ram_port_write_triple (as in osd_ram_write_index_run), the data step osd_ram_port_write_data is defined here; GCC inlines
 * them at -O3. row *= columns is its own statement; the 16-bit address is addr = column + row.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define COMMAND_WRITE_CELLS 0x70

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
 * Write a row of 16-bit cell values into a menu layer, starting at a cell.
 *
 *   column, row  first cell; the cell address is column + row * columns of the layer
 *   count        number of values
 *   values       the values; each goes out as its low byte, then its high byte
 *   layer        menu layer 0 or 1; also the side of the memory port
 *
 * In this order: command 0x70, the 16-bit cell address, the bytes of the values. Called by osd_api_write_cells,
 * which nothing calls.
 */
void osd_ram_write_cells(unsigned int column, unsigned int row, unsigned char count, unsigned short *values, unsigned char layer)
{
    unsigned char i;
    unsigned short address;

    row *= osd_layer_columns[layer];
    address = column + row;
    osd_ram_port_write_command(layer, COMMAND_WRITE_CELLS);
    osd_ram_port_write_triple(layer, address);
    for (i = 0; i < count; i++) {
        osd_ram_port_write_data(layer, *values);
        osd_ram_port_write_data(layer, *values >> 8);
        values++;
    }
}
