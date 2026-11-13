/* ddc_rearm_idle_slaves  (FUN_CODE_568f)
 *
 * Mark finished DDC/CI requests as pending and re-arm the slave ports that are not active.
 * Note: A port that is not active gets bit 6 of its control register set on every pass; 0x10 goes to the event
 *   acknowledge registers once, after more than 1000 ticks without activity.
 * Name basis: derived - per-port activity bits from irq_ext0_ddc_slave; status bit -> pending channel flag;
 *   after 1000 ticks 0x10 to reg_i2c<N>_event_ack; bit 6 of reg_i2c<N>_ctrl
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_568f @ 0x568f (469 B). Options: OPTIMIZE(8,SPEED) LARGE.
 * LARGE local i at XDATA 0xA473, bit local request_done (BIT 0x00).
 * Source form: the mask 1 << i is built in the local port_bit; the per-port register tests are written out port by
 * port (a switch for the status bits, eight ifs for each of the two register groups).
 */

extern unsigned char idata ddc_port_activity_flags;
extern unsigned int xdata ddc_last_access_ticks;
extern unsigned char xdata ddc_pending_channel_flags;
extern bit ddc_rearm_pending_flag;
extern unsigned char xdata reg_i2c0_status, reg_i2c1_status, reg_i2c2_status, reg_i2c3_status;
extern unsigned char xdata reg_i2c4_status, reg_i2c5_status, reg_i2c6_status, reg_i2c7_status;
extern unsigned char xdata reg_i2c0_address, reg_i2c1_address, reg_i2c2_address, reg_i2c3_address;
extern unsigned char xdata reg_i2c4_address, reg_i2c5_address, reg_i2c6_address, reg_i2c7_address;
extern unsigned char xdata reg_i2c0_event_ack, reg_i2c1_event_ack, reg_i2c2_event_ack, reg_i2c3_event_ack;
extern unsigned char xdata reg_i2c4_event_ack, reg_i2c5_event_ack, reg_i2c6_event_ack, reg_i2c7_event_ack;
extern unsigned char xdata reg_i2c0_ctrl, reg_i2c1_ctrl, reg_i2c2_ctrl, reg_i2c3_ctrl;
extern unsigned char xdata reg_i2c4_ctrl, reg_i2c5_ctrl, reg_i2c6_ctrl, reg_i2c7_ctrl;
extern unsigned int timer_get_ticks(void);

#define DDC_PORTS          8
#define I2C_STATUS_DONE    0x01   /* reg_i2c<N>_status bit 0: ends the port's activity */
#define I2C_ADDRESS_ON     0x01   /* reg_i2c<N>_address bit 0: the port is served */
#define DDC_IDLE_TICKS     1000
#define DDC_EVT_BIT4       0x10   /* written to reg_i2c<N>_event_ack (as in irq_ext0_ddc_slave) */
#define I2C_CTRL_BIT6      0x40   /* also set by irq_ext0_ddc_slave when a request starts */

/*
 * ddc_rearm_idle_slaves - follow the activity of the eight DDC/CI slave ports and set their control registers up
 * again when they have gone quiet. The interrupt routines set a port's bit in ddc_port_activity_flags when a
 * request starts or a request byte arrives. Called by sys_service_ddc_and_cec.
 *
 * For each port 0..7:
 *   active (bit set)  note the time in ddc_last_access_ticks and set ddc_rearm_pending_flag. When the port's
 *                     status bit 0 is set, the activity ends: the bit moves from ddc_port_activity_flags to
 *                     ddc_pending_channel_flags (power_test_ddc_wake reads it there).
 *   not active        once more than 1000 ticks have passed since the last activity of any port and the pending
 *                     flag is set: write 0x10 to the event acknowledge register of every served port (address
 *                     bit 0 set) and clear the flag. Then, on every such pass, set bit 6 of the control register
 *                     of every served port.
 */
void ddc_rearm_idle_slaves(void)
{
    unsigned char i, port_bit;
    bit request_done;

    for (i = 0; i < DDC_PORTS; i++) {
        request_done = 0;
        if ((ddc_port_activity_flags >> i) & 1) {
            ddc_last_access_ticks = timer_get_ticks();
            ddc_rearm_pending_flag = 1;
            switch (i) {
            case 0: if (reg_i2c0_status & I2C_STATUS_DONE) request_done = 1; break;
            case 1: if (reg_i2c1_status & I2C_STATUS_DONE) request_done = 1; break;
            case 2: if (reg_i2c2_status & I2C_STATUS_DONE) request_done = 1; break;
            case 3: if (reg_i2c3_status & I2C_STATUS_DONE) request_done = 1; break;
            case 4: if (reg_i2c4_status & I2C_STATUS_DONE) request_done = 1; break;
            case 5: if (reg_i2c5_status & I2C_STATUS_DONE) request_done = 1; break;
            case 6: if (reg_i2c6_status & I2C_STATUS_DONE) request_done = 1; break;
            case 7: if (reg_i2c7_status & I2C_STATUS_DONE) request_done = 1; break;
            }
            if (request_done) {
                port_bit = 1 << i;
                ddc_port_activity_flags &= ~port_bit;
                ddc_pending_channel_flags |= port_bit;
            }
        } else {
            if (timer_get_ticks() - ddc_last_access_ticks > DDC_IDLE_TICKS && ddc_rearm_pending_flag) {
                if (reg_i2c0_address & I2C_ADDRESS_ON) reg_i2c0_event_ack = DDC_EVT_BIT4;
                if (reg_i2c1_address & I2C_ADDRESS_ON) reg_i2c1_event_ack = DDC_EVT_BIT4;
                if (reg_i2c2_address & I2C_ADDRESS_ON) reg_i2c2_event_ack = DDC_EVT_BIT4;
                if (reg_i2c3_address & I2C_ADDRESS_ON) reg_i2c3_event_ack = DDC_EVT_BIT4;
                if (reg_i2c4_address & I2C_ADDRESS_ON) reg_i2c4_event_ack = DDC_EVT_BIT4;
                if (reg_i2c5_address & I2C_ADDRESS_ON) reg_i2c5_event_ack = DDC_EVT_BIT4;
                if (reg_i2c6_address & I2C_ADDRESS_ON) reg_i2c6_event_ack = DDC_EVT_BIT4;
                if (reg_i2c7_address & I2C_ADDRESS_ON) reg_i2c7_event_ack = DDC_EVT_BIT4;
                ddc_rearm_pending_flag = 0;
            }
            if (reg_i2c0_address & I2C_ADDRESS_ON) reg_i2c0_ctrl |= I2C_CTRL_BIT6;
            if (reg_i2c1_address & I2C_ADDRESS_ON) reg_i2c1_ctrl |= I2C_CTRL_BIT6;
            if (reg_i2c2_address & I2C_ADDRESS_ON) reg_i2c2_ctrl |= I2C_CTRL_BIT6;
            if (reg_i2c3_address & I2C_ADDRESS_ON) reg_i2c3_ctrl |= I2C_CTRL_BIT6;
            if (reg_i2c4_address & I2C_ADDRESS_ON) reg_i2c4_ctrl |= I2C_CTRL_BIT6;
            if (reg_i2c5_address & I2C_ADDRESS_ON) reg_i2c5_ctrl |= I2C_CTRL_BIT6;
            if (reg_i2c6_address & I2C_ADDRESS_ON) reg_i2c6_ctrl |= I2C_CTRL_BIT6;
            if (reg_i2c7_address & I2C_ADDRESS_ON) reg_i2c7_ctrl |= I2C_CTRL_BIT6;
        }
    }
}
