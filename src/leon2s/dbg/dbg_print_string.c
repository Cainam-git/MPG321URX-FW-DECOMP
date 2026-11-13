/* dbg_print_string  (FUN_a00734c4)
 *
 * Print a plain string on the debug console.
 * Name basis: proven - forwards to uart_put_string; used for 'Reliable Check Error!!' and EQ messages
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00734c4 @ 0xa00734c4 (-mcpu=v8 -Os -g)
 * Kept in the decompiler's form: two arguments and a result built with CONCAT44 (the result is cut to the low
 * word by the return type). The result is 0.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern int uart_put_string();

/*
 * Print a fixed string on the debug console through uart_put_string.
 *   text:   the string
 *   unused: not used; the routine returns 0 whatever it is
 */
unsigned int dbg_print_string(unsigned int text, unsigned int unused)
{
  uart_put_string(text);
  return (unsigned long long)unused << 0x20;
}
