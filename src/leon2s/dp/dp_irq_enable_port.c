/* dp_irq_enable_port  (FUN_a00b0518)
 *
 * Switch the interrupt sources of DisplayPort input 0 or 1 on.
 * Name basis: descriptive - one enable routine per port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b0518 @ 0xa00b0518 (-mcpu=v8 -Os -g)
 * Source form: each arm is a call followed by 'return'; the callees are declared without a parameter list.
 */
extern int irq_enable_dp_port0();
extern int irq_enable_dp_port1();

/*
 * Run irq_enable_dp_port0 for DP receiver 0 and irq_enable_dp_port1 for any other port.
 *   port: DP receiver (0 or 1)
 * Called by dp_start_port and dp_init_port.
 */
void dp_irq_enable_port(unsigned char port)

{
  if (port == 0) {
    irq_enable_dp_port0();
    return;
  }
  irq_enable_dp_port1();
  return;
}
