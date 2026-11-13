/* power_watch_dp_activity  (FUN_CODE_a1fe)
 *
 * After a DP power-up request, watch the ports and fall back to the crystal clock.
 * Name basis: descriptive - flag 0xA6EE (set on DPCD 0x600 = 1); sys_test_port_event_bit every 5000 ticks;
 *   then sys_switch_to_crystal_clock
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_a1fe @ 0xa1fe..0xa2b8 (186 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE local: still_active at XDATA 0xA473 (cleared first, collected with |= from the bit results).
 * volatile on 0xDCB0: the firmware reads it again between the set and the clear of bit 1.
 */
extern unsigned char volatile xdata DAT_EXTMEM_dcb0;
extern unsigned char xdata dp_power_up_request;
extern unsigned char xdata power_dp_watch_active_flag;
extern unsigned int xdata power_dp_watch_ticks;
extern bit sys_test_port_event_bit(unsigned char n);
extern unsigned int timer_get_ticks(void);
extern void sys_switch_to_crystal_clock(void);
extern void sys_restore_crystal_timing(void);

#define DCB0_EVENT_PULSE        0x02  /* bit 1 of XDATA 0xDCB0, set and cleared again */
#define DP_WATCH_PERIOD_TICKS   5000
#define DP_PORT0                0
#define DP_PORT1                1

/*
 * power_watch_dp_activity - after a DP source has asked for power-up (dp_power_up_request), watch the event bits
 * of DP ports 0 and 1.
 * The first time either bit is set, the watch starts: bit 1 of 0xDCB0 is pulsed and the time noted. While the
 * watch runs, every 5000 ticks both bits are read again, the time noted again and bit 1 pulsed again. When that
 * reading finds both bits clear, the request and the watch end and the 8051 goes back to the crystal clock
 * (sys_switch_to_crystal_clock, sys_restore_crystal_timing).
 * Only caller: sys_main.
 */
void power_watch_dp_activity(void)
{
    unsigned char still_active;

    still_active = 0;
    if (dp_power_up_request > 0) {
        if (sys_test_port_event_bit(DP_PORT0) || sys_test_port_event_bit(DP_PORT1)) {
            if (power_dp_watch_active_flag == 0) {
                power_dp_watch_active_flag = 1;
                DAT_EXTMEM_dcb0 |= DCB0_EVENT_PULSE;
                DAT_EXTMEM_dcb0 &= ~DCB0_EVENT_PULSE;
                power_dp_watch_ticks = timer_get_ticks();
            }
        }
        if (power_dp_watch_active_flag != 0 && timer_get_ticks() - power_dp_watch_ticks > DP_WATCH_PERIOD_TICKS) {
            still_active |= sys_test_port_event_bit(DP_PORT0);
            still_active |= sys_test_port_event_bit(DP_PORT1);
            power_dp_watch_ticks = timer_get_ticks();
            DAT_EXTMEM_dcb0 |= DCB0_EVENT_PULSE;
            DAT_EXTMEM_dcb0 &= ~DCB0_EVENT_PULSE;
        } else
            still_active = 1;
        if (still_active == 0) {
            dp_power_up_request = 0;
            power_dp_watch_active_flag = 0;
            sys_switch_to_crystal_clock();
            sys_restore_crystal_timing();
        }
    }
}
