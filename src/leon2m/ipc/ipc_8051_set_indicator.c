/* ipc_8051_set_indicator  (FUN_a01341dc)
 *
 * Have the 8051 toggle the masked pins of one GPIO port (commands 0x19, 0x1A, 0x18); print the values.
 * Note: Reads the port's data register on the main side and sends value | mask, value & ~mask and the
 *   register's 8051 address; no routine calls it.
 * Name basis: proven - prints 'Set Indicator : ...' and 'port is not correct'; 8051 commands 0x19 and 0x1A
 *   carry the two register values with a hold time, 0x18 the register address
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01341dc @ 0xa01341dc-0xa0134394 (110 words), flags -mcpu=v8 -O3 -g. Jump table at 0xd2b2c.
 * Source forms the exact build depends on: gpio_read_port_data is declared returning int here (the value is cut
 * where it is used, not after the call) and port_value is an unsigned int; with a byte GCC puts mask first in the
 * 'or'. Case 1 is written last; address 0 is set at the start of the default case.
 */
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern int dbg_printf(const char *fmt, ...);
extern int gpio_read_port_data(unsigned char n);
extern void ipc_send_8051_command(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

/* Commands to the 8051 (docs/MAILBOX.md; names as in the 8051's ipc_run_command). */
#define IPC_8051_CMD_TOGGLE_TARGET    0x18  /* bytes 2..3 = XDATA address of the register; selects toggle mode */
#define IPC_8051_CMD_TOGGLE_LIMITS_0  0x19  /* byte 2 = first register value, byte 3 = its hold time */
#define IPC_8051_CMD_TOGGLE_LIMITS_1  0x1a  /* byte 2 = second register value, byte 3 = its hold time */
#define IPC_SEND_WAIT_TAKEN           1     /* ipc_send_8051_command: wait until the 8051 has taken it */

#define DBG_MAILBOX                   0x20  /* debug class of the 8051 mailbox prints */

/*
 * Have the 8051 blink the pins in mask of GPIO port gpio_port: it switches the port's data register between
 * (value now | mask) and (value now & ~mask), holding each for hold_time units of 100 ticks.
 *
 *   gpio_port  GPIO port 1..17; each has a data register 0xCF03C000..0xCF03CC0C (the one gpio_read_port_data
 *              reads). Any other number prints 'port is not correct' and goes on with register address 0.
 *   mask       pins to blink (low byte used)
 *   hold_time  hold time of each state in 100-tick units (low byte used)
 *
 * The register address divided by 4 gives the register's XDATA address in the 8051 (0xF000 for port 1); its low
 * byte, cut to bits 0..4, and its high byte, cut with 0xF3, go into command 0x18 (both cuts leave the 17
 * addresses unchanged). The 8051 runs the toggle (sys_run_timed_ramp) on each round of its main loop while its run
 * state is power saving; only the bits in which the two values differ are switched.
 *
 * No call to this routine and no word holding its address was found in FW.021.
 */
void ipc_8051_set_indicator(unsigned char gpio_port, unsigned int mask, unsigned int hold_time)
{
    unsigned int addr;
    unsigned int port_value;

    switch (gpio_port) {
    case 2: addr = 0xcf03c004; break;
    case 3: addr = 0xcf03c008; break;
    case 4: addr = 0xcf03c00c; break;
    case 5: addr = 0xcf03c010; break;
    case 6: addr = 0xcf03c040; break;
    case 7: addr = 0xcf03c048; break;
    case 8: addr = 0xcf03c450; break;
    case 9: addr = 0xcf03c458; break;
    case 10: addr = 0xcf03c460; break;
    case 11: addr = 0xcf03c468; break;
    case 12: addr = 0xcf03c470; break;
    case 13: addr = 0xcf03c478; break;
    case 14: addr = 0xcf03cc00; break;
    case 15: addr = 0xcf03cc04; break;
    case 16: addr = 0xcf03cc08; break;
    case 17: addr = 0xcf03cc0c; break;
    case 1: addr = 0xcf03c000; break;
    default:
        addr = 0;
        if (dbg_is_print_enabled(DBG_MAILBOX))
            dbg_printf("port is not correct\r\n");
        break;
    }
    port_value = gpio_read_port_data(gpio_port);
    /* One word per 8051 byte: the word address / 4 holds the XDATA address in its low 16 bits. */
    addr >>= 2;
    if (dbg_is_print_enabled(DBG_MAILBOX))
        dbg_printf("\nSet Indicator : %02X %02X %02X %08lx %02x\r\n", gpio_port, (unsigned char)mask, (unsigned char)hold_time, addr, (unsigned char)port_value);
    /* The two states first, then the register, which starts the toggle. */
    ipc_send_8051_command(IPC_8051_CMD_TOGGLE_LIMITS_0, 0, port_value | mask, hold_time, IPC_SEND_WAIT_TAKEN);
    ipc_send_8051_command(IPC_8051_CMD_TOGGLE_LIMITS_1, 0, port_value & ~mask, hold_time, IPC_SEND_WAIT_TAKEN);
    ipc_send_8051_command(IPC_8051_CMD_TOGGLE_TARGET, 0, addr & 0x1f, (addr >> 8) & 0xf3, IPC_SEND_WAIT_TAKEN);
}
