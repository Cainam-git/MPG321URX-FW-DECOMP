/* startup_init_system  (FUN_a00b18d0)
 *
 * Initialise the input processor's basic services and print the version banner.
 * Name basis: proven - prints 'NT68500 Leon2S system compiled under Linux' with the version text
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b18d0 @ 0xa00b18d0 (-mcpu=v8 -Os -g).
 * Source form: the helpers are declared without a prototype. The return statement is the decompiler's
 * CONCAT44(second, first) form, which truncates to the first parameter.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
#define STARTUP_FLAG_REG (*(volatile unsigned int *)0xcf0114fc)

extern int uart_init();
extern int dbg_printf();
extern int hdmi_rx21_init_register_pointers();
extern int irq_init_controller();
extern int sys_core_setup_unit_0320();
extern int sys_task_init();

/*
 * Initialise the basic services of the input processor and print the start banner.
 *
 * In order: hdmi_rx21_init_register_pointers, irq_init_controller, uart_init, sys_task_init,
 * sys_core_setup_unit_0320; then the banner "NT68500 Leon2S system compiled under Linux" and the text
 * "SWVERSION" go to the debug console, and bit 7 of the register at 0xCF0114FC is set.
 * Returns its first parameter. Neither parameter is used otherwise.
 */
int startup_init_system(unsigned int first, unsigned int second)

{
  hdmi_rx21_init_register_pointers();
  irq_init_controller();
  uart_init();
  sys_task_init();
  sys_core_setup_unit_0320();
  dbg_printf("\012\015NT68500 Leon2S system compiled under Linux\012\015%s\012\015","SWVERSION");
  STARTUP_FLAG_REG = STARTUP_FLAG_REG | 0x80;
  return CONCAT44(second,first);
}
