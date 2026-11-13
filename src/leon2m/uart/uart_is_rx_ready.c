/* uart_is_rx_ready  (FUN_a00df368)
 *
 * Return whether the debug serial port has received a character.
 * Returns: 0 or 1
 * Name basis: proven - bit 0 of 0xC00B0014; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df368 @ 0xa00df368 (-mcpu=v8 -O2 -g)
 * Source form: two unused parameters; reg_read32 is declared without a prototype; the result is the low word of
 * a 64-bit AND with 1, written with CONCAT44.
 */
typedef unsigned int undefined4;
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern int reg_read32();

#define UART_STATUS_REG      0xc00b0014
#define UART_STATUS_RX_READY 0x01               /* status bit 0: a character has arrived */

/*
 * Return bit 0 of the status register: 1 when a character has arrived, else 0. The two parameters are not used.
 * Nothing calls it.
 */
int uart_is_rx_ready(undefined4 param_1,undefined4 param_2)

{
  undefined4 status;

  status = reg_read32(UART_STATUS_REG);
  return CONCAT44(param_2,status) & (0xffffffff00000000ULL | UART_STATUS_RX_READY);
}
