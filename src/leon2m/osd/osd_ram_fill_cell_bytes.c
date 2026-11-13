/* osd_ram_fill_cell_bytes  (FUN_a011c1ac)
 *
 * Fill a number of cells in one of the two byte planes with one value.
 * Name basis: derived - command 0x90 (mode 1) or 0x40, address x + y * columns, n data bytes
 *
 * Matching notes
 * --------------
 * leon2m, flags -mcpu=v8 -O3 -g.
 * The three port steps (command, address, data) are the firmware's own routines, defined in this file and
 * inlined by the compiler.
 * Source form: the address goes to osd_ram_port_write_triple as (unsigned short), the 16-bit narrowing ahead of the
 * register writes.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
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
/* Port commands choosing one of the two byte planes of a layer. */
#define COMMAND_PLANE_1 0x90
#define COMMAND_PLANE_0 0x40
/* plane_select value that picks plane 1; any other value picks plane 0. */
#define SELECT_PLANE_1  1

/* Number of cells in one row of layer side (see the cell address in the routines below). */
extern unsigned short osd_layer_columns[];

/* Send the 24-bit memory address (low, middle, high byte) to the port of side `side`, then wait. */
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

/* Send a command byte to the port of side `side`, then wait. */
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

/* Send one data byte to the port of side `side`, then wait. */
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
 * Write the same byte `count` times into one byte plane of the layer on `side`.
 *   plane_select : SELECT_PLANE_1 sends COMMAND_PLANE_1, any other value COMMAND_PLANE_0
 *   column, row  : first cell; its memory address is column + row * (cells per row of the side)
 *   count        : number of bytes (at most 255)
 *   value        : the byte to write
 *   side         : 0 = layer 0, otherwise the other layer
 * The command and the address are sent once; the data byte is then sent `count` times in a row.
 * Called by osd_api_fill_cell_bytes.
 */
void osd_ram_fill_cell_bytes(unsigned char plane_select, unsigned int column, unsigned int row, unsigned char count, unsigned char value,
                  unsigned char side)
{
    unsigned char i;

    row *= osd_layer_columns[side];
    column += row;
    if (plane_select == SELECT_PLANE_1)
        osd_ram_port_write_command(side, COMMAND_PLANE_1);
    else
        osd_ram_port_write_command(side, COMMAND_PLANE_0);
    osd_ram_port_write_triple(side, (unsigned short)column);
    for (i = 0; i < count; i++)
        osd_ram_port_write_data(side, value);
}
