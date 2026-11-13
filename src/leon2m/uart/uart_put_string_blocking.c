/* uart_put_string_blocking  (FUN_a00df450)
 *
 * Send a text to the debug serial port, waiting without a limit.
 * Note: Before each character it reads 0xC00B0000 until bit 5 is set (0xC00B0014 is not read); a line feed is
 *   followed by a carriage return.
 * Name basis: derived - per character: wait loop on bit 5 of the word read at 0xC00B0000, then a write to
 *   0xC00B0000; called by sys_ddr_run_script
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df450 @ 0xa00df450 (-mcpu=v8 -O3 -g)
 * Source form: two unused parameters follow the decompiler's form (the second one is returned inside CONCAT44);
 * reg_read32 is declared without a prototype. The wait reads register 0xC00B0000 (see the comment below).
 */
typedef unsigned int undefined4, uint;
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern int reg_read32();
extern void reg_write32();

#define UART_DATA_REG        0xc00b0000
#define UART_STATUS_TX_READY 0x20

/*
 * Write a zero-terminated text to the data register, waiting without a limit before each character; after a
 * '\n' it waits again and writes a '\r'.
 *
 *   param_1  the text
 *   param_2  not used
 *
 * The wait loops read UART_DATA_REG (0xC00B0000) and test its bit 5; the status register 0xC00B0014 that
 * the other output routines poll (UART_STATUS_REG) is not read here.
 * Returns the address of the terminating zero byte. Called by sys_ddr_run_script (the memory training script).
 */
int uart_put_string_blocking(char *param_1,undefined4 param_2)

{
  char c;
  uint status;

  c = *param_1;
  while (c != '\0') {
    do {
      status = reg_read32(UART_DATA_REG);
    } while ((status & UART_STATUS_TX_READY) == 0);
    reg_write32(UART_DATA_REG,(int)*param_1);
    if (*param_1 == '\n') {
      do {
        status = reg_read32(UART_DATA_REG);
      } while ((status & UART_STATUS_TX_READY) == 0);
      reg_write32(UART_DATA_REG,0xd);
    }
    param_1 = param_1 + 1;
    c = *param_1;
  }
  return CONCAT44(param_2,param_1);
}
