/* fwupd_svc_set_isp_mode  (FUN_CODE_e21d)
 *
 * Write main chip registers 0xF1EB / 0xF1E0: 0x8A / 0x02 for a non-zero mode, 0x82 / 0x0A for mode 0.
 *   mode: 0: values 0x82 / 0x0A; any other: 0x8A / 0x02
 * Note: Waits 50 delay units first. fwupd_run_isp_write calls it with 1 before the flash write;
 *   fwupd_step_port_state with 0 after its wait on mailbox byte 0xF19A.
 * Name basis: derived - service writes to registers 0xF1EB and 0xF1E0, values by mode; mode 1 comes from
 *   fwupd_run_isp_write before service command 0xA3
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e21d @ 0xe21d, OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char i2c_read_packet(unsigned char addr, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply_entry(void);
void fwupd_svc_read_reply(unsigned char *buf);
void timer_delay_units(unsigned char t);
unsigned char fwupd_svc_write_register(unsigned int reg, unsigned char val);

#define SVC_REG_F1EB    0xf1eb
#define SVC_REG_F1E0    0xf1e0

/* Wait 50 delay units, then write registers 0xF1EB and 0xF1E0 of the main chip over the service link:
 *   mode 0:     0xF1EB = 0x82, 0xF1E0 = 0x0A;
 *   any other:  0xF1EB = 0x8A, 0xF1E0 = 0x02.
 * Callers: fwupd_run_isp_write with 1 (modes 0x10 / 0x11, after write protect and register 0xD7E0, before service
 * command 0xA3), and fwupd_step_port_state with 0 once its wait on mailbox byte 0xF19A has ended. */
void fwupd_svc_set_isp_mode(unsigned char mode)
{
    timer_delay_units(50);
    if (mode == 0) {
        fwupd_svc_write_register(SVC_REG_F1EB, 0x82);
        fwupd_svc_write_register(SVC_REG_F1E0, 0x0a);
    } else {
        fwupd_svc_write_register(SVC_REG_F1EB, 0x8a);
        fwupd_svc_write_register(SVC_REG_F1E0, 0x02);
    }
}
