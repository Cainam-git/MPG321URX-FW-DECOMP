/* uart_init  (FUN_a00dedc8)
 *
 * Set up the debug serial port from a clock value and install its receive interrupt handler.
 * Name basis: proven - divisor from the clock value (param_1 / 0x1C2000), registers 0xC00B0000..0xC00B000C,
 *   irq_set_source_handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dedc8 (0xa00dedc8-0xa00dee6c, 164 bytes, 41 words), flags -mcpu=v8 -O3 -g.
 * The division is by the constant 0x1c2000 (umul 0x91a2b3c5, rd %y, srl 20). The tail call to
 * irq_set_source_handler takes 3 arguments, as at its other call sites.
 * Source form: the receive ring is a struct with the head and tail bytes at +0x80 / +0x81; the source stores
 * the tail first, then the head (the firmware emits head, then tail).
 */

/* Receive ring of the debug serial port: 128 data bytes, then the head and the tail index (see uart_rx_isr). */
struct uart_rx_ring {
    unsigned char data[0x80];
    unsigned char head;                         /* +0x80: where the interrupt stores the next byte */
    unsigned char tail;                         /* +0x81: where the reader takes the next byte */
};
extern struct uart_rx_ring dbg_uart_rx_ring;
extern int uart_rx_isr();
extern void irq_set_source_handler();
extern void reg_write32();

/* Registers of the debug serial port. */
#define UART_REG_0         0xc00b0000           /* UART_DATA_REG; the divisor is written here first */
#define UART_REG_4         0xc00b0004
#define UART_REG_8         0xc00b0008
#define UART_REG_C         0xc00b000c
#define UART_DIVIDER       0x1c2000             /* divisor = speed / this */
#define UART_IRQ_LEVEL     4                    /* interrupt level of the receive handler */
#define UART_IRQ_SOURCE    0x20                 /* its source bit */

/*
 * Set up the debug serial port.
 *
 *   param_1  the clock handed over by startup_init_core (96000000); divided by UART_DIVIDER it gives the value
 *            written to register 0.
 *
 * The receive ring is emptied (head and tail set to 0), the registers are written in this order: C = 0x80,
 * 0 = divisor, 4 = 0, C = 0, C = 3, 8 = 6, 8 = 0, 4 = 1; and uart_rx_isr is installed as the handler of
 * interrupt level 4, source 0x20.
 */
void uart_init(unsigned int param_1)
{
    unsigned int div_result = param_1 / UART_DIVIDER;
    dbg_uart_rx_ring.tail = 0;
    dbg_uart_rx_ring.head = 0;
    reg_write32(UART_REG_C, 0x80);
    reg_write32(UART_REG_0, div_result);
    reg_write32(UART_REG_4, 0);
    reg_write32(UART_REG_C, 0);
    reg_write32(UART_REG_C, 3);
    reg_write32(UART_REG_8, 6);
    reg_write32(UART_REG_8, 0);
    reg_write32(UART_REG_4, 1);
    irq_set_source_handler(UART_IRQ_LEVEL, UART_IRQ_SOURCE, uart_rx_isr);
}
