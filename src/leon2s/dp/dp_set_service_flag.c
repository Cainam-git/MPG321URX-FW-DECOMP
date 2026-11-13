/* dp_set_service_flag  (FUN_a00ad054)
 *
 * Store the service flag byte at 0xA8079313.
 * Name basis: descriptive - plain store
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad054 @ 0xa00ad054, flags -mcpu=v8 -Os -g. Leaf.
 */
extern unsigned char dp_service_flag;

/* Store the byte dp_service_flag. dp_setup_service_block sets it to 1; dp_update_pending_bits does nothing while it is 0. */
void dp_set_service_flag(unsigned char flag)

{
  dp_service_flag = flag;
  return;
}
