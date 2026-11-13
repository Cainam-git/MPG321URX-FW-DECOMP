/* dp_update_pending_bits  (FUN_a00ad5cc)
 *
 * Set the pending bit of each ready port while the service flag is set, then pulse the HPD block.
 * Name basis: descriptive - dp_is_port_ready_for_service per port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad5cc @ 0xa00ad5cc, flags -mcpu=v8 -Os -g.
 */
extern unsigned char dp_port_pending_bits;      /* bit 0 = port 0, bit 1 = port 1 */
extern unsigned char dp_service_flag;
extern void dp_pulse_hpd_block(void);
extern int dp_is_port_ready_for_service(int);

/*
 * Does nothing while dp_service_flag is 0. Otherwise it sets the pending bit of each of port 0 and port 1 that
 * dp_is_port_ready_for_service reports as 1, then calls dp_pulse_hpd_block.
 */
void dp_update_pending_bits(void)
{
    if (dp_service_flag == 0) {
        return;
    }
    if ((dp_is_port_ready_for_service(0) & 0xff) == 1) {
        dp_port_pending_bits = dp_port_pending_bits | 1;
    }
    if ((dp_is_port_ready_for_service(1) & 0xff) == 1) {
        dp_port_pending_bits = dp_port_pending_bits | 2;
    }
    dp_pulse_hpd_block();
}
