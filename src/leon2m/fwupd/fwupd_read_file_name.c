/* fwupd_read_file_name  (FUN_a01238e8)
 *
 * Read the name of the offered file from the update port and print it.
 * Name basis: derived - handshake, then six bytes per command 0x52..0x58 into the name buffer; prints it with
 *   '%s'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01238e8 @ 0xa01238e8-0xa0123c4c, flags -mcpu=v8 -O3 -g.
 * Source form: the per-command read is a static helper that is inlined seven times; the row is addressed through a
 * pointer taken inside the copy loop, which gives the firmware's [row + index] operand order.
 */
#define REG(a) (*(volatile unsigned int *)(a))
/* Port register n of the update port window (address 0xCF000000 | n << 2). */
#define PORT_REG(n) (*(volatile unsigned int *)(0xcf000000 | ((n) << 2)))

#define UPDATE_COMMAND_REG   0xcf03c660
#define PORT_STATE_REG(port)    PORT_REG((port) * 2 + 0xf190)   /* per-port state */
#define PORT_COMMAND_REG(port)  PORT_REG((port) * 2 + 0xf191)   /* per-port command */
#define NAME_DATA_FIRST      0xf19a     /* six registers 0xF19A..0xF19F carry the six bytes of one answer */
#define NAME_BYTES_PER_ROW   6
#define NAME_ROWS            7
#define PORT_STATE_NAME_OFFERED 0x96    /* state at which the name is read */
#define PORT_STATE_NO_NAME      0x9b    /* state after the command 0x47 in which no name is read */
#define PORT_CMD_NAME_REQUEST   0x47    /* docs/MAP.md: 0x47 is sent by this routine */
#define NAME_CMD_FIRST          0x52    /* commands 0x52..0x58 return rows 0..6 of the name */

extern unsigned char fwupd_active_port;
extern unsigned char fwupd_file_name[NAME_ROWS][NAME_BYTES_PER_ROW];
extern int dbg_printf(const char *, ...);

/* Send one row command and copy the six answer registers into row `row` of the name table. */
static void read_name_row(unsigned char cmd, unsigned char row)
{
    unsigned char i;

    REG(UPDATE_COMMAND_REG) = cmd;
    while (REG(UPDATE_COMMAND_REG) == cmd)
        ;
    for (i = 0; i <= 5; i++) {
        unsigned char *name_row = fwupd_file_name[row];
        name_row[i] = PORT_REG(NAME_DATA_FIRST + i);
    }
}

/*
 * Read the name of the file offered on the update port and print it.
 * Only when the state register of the active port (fwupd_active_port) reads PORT_STATE_NAME_OFFERED: the routine
 * writes command 0x47 to the port's command register and waits until the register changes. Unless the state
 * register then reads PORT_STATE_NO_NAME, it sends the commands 0x52..0x58 and collects the seven answers
 * of six bytes into fwupd_file_name, then prints the table with dbg_printf. The waits have no time limit.
 * Callers: fwupd_find_and_verify_file, fwupd_find_file.
 */
void fwupd_read_file_name(void)
{
    if (PORT_STATE_REG(fwupd_active_port) == PORT_STATE_NAME_OFFERED) {
        PORT_COMMAND_REG(fwupd_active_port) = PORT_CMD_NAME_REQUEST;
        while (PORT_COMMAND_REG(fwupd_active_port) == PORT_CMD_NAME_REQUEST)
            ;
        if (PORT_STATE_REG(fwupd_active_port) != PORT_STATE_NO_NAME) {
            read_name_row(NAME_CMD_FIRST + 0, 0);
            read_name_row(NAME_CMD_FIRST + 1, 1);
            read_name_row(NAME_CMD_FIRST + 2, 2);
            read_name_row(NAME_CMD_FIRST + 3, 3);
            read_name_row(NAME_CMD_FIRST + 4, 4);
            read_name_row(NAME_CMD_FIRST + 5, 5);
            read_name_row(NAME_CMD_FIRST + 6, 6);
            dbg_printf("%s\r\n ", fwupd_file_name);
        }
    }
}
