/* sys_main  (FUN_CODE_b5b4)
 *
 * Start the agent, then serve mailbox commands and the USB ports forever.
 * Name basis: proven - entered from ?C_STARTUP; prints 'Start to loop..', 'Host Mode Init', 'Device Mode Init'
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_b5b4 @ 0xb5b4 (338 B), compiled with OPTIMIZE(8,SPEED) LARGE (no RET after the endless loop).
 * Locals round 0x08E2, command 0x08E3, unused 0x08E4.
 * volatile: 0xF198 is read twice for one value (test, then copy) and 0xF101 is read again right after a store; the
 * code shows both re-reads. Source forms the bytes depend on: 'unused' is set and never read ('command = 0;
 * unused = 0;' gives the INC DPTR store pair); the mode copy is compared first ('fwupd_mode_state[0] !=
 * fwupd_requested_usb_mode' loads 0x09C6 into R7). No aids.
 */
#include <reg51.h>

/* USB modes asked for by mailbox command 0x70 (fwupd_requested_usb_mode). */
#define USB_MODE_HOST        0
#define USB_MODE_DEVICE      1
#define USB_MODE_NONE        0xff        /* nothing is served */

#define START_ROUNDS         0x10        /* mailbox rounds before the reset sequence */
#define START_ROUND_UNITS    0x32        /* timer_delay_units wait per start round */
#define P1_START             0xe0
#define F101_BIT7            0x80        /* cleared at the start */
#define F1E0_BIT7            0x80        /* set at the start */
#define REG_CD0A_PULSE       0x80        /* held in 0xCD0A and 0xCD2A for 10 delay units */
#define F101_PULSE_BITS      0x30        /* set for 10 delay units, then cleared */
#define F101_KEEP_MASK       0xcf
#define F101_BIT6            0x40
#define PORT_COMMAND_SKIP    0x21        /* a port whose command register holds this is not stepped */

#define FMT_START_LOOP       0xc28c      /* "Start to loop..\r\n" */
#define FMT_HOST_MODE        0xc29e      /* "Host Mode Init\r\n" */
#define FMT_DEVICE_MODE      0xc2af      /* "Device Mode Init\r\n" */

extern volatile unsigned char xdata DAT_EXTMEM_f101;
extern unsigned char xdata DAT_EXTMEM_f1e0;
extern volatile unsigned char xdata reg_fwupd_mailbox_cmd;
extern unsigned char xdata reg_fwupd_port0_status;
extern unsigned char xdata reg_fwupd_port0_command;
extern unsigned char xdata reg_fwupd_port1_status;
extern unsigned char xdata reg_fwupd_port1_command;
extern unsigned char xdata reg_usb0_byte_0a;
extern unsigned char xdata reg_usb1_byte_0a;
extern unsigned char xdata fwupd_requested_usb_mode;
/* [0] = USB mode in effect; [1] / [2] = state of port 0 / port 1 (fwupd_port0_state / fwupd_port1_state). */
extern unsigned char xdata fwupd_mode_state[3];
extern void lib_printf517(void *fmt, ...) large;
void timer_delay_units(unsigned char n);
void fwupd_run_mailbox_command(unsigned char cmd);
void usb_select_controller(unsigned char n);
void usb_host_init_controller(void);
void usb_device_mode_init(void);
void usb_otg_service_irq(void);
void fwupd_step_port_state(unsigned char n);

/* sys_main: the update agent's main program; entered from the start-up code and never left.
 *
 * Start-up:
 *   1. P1 = 0xE0, bit 7 of 0xF101 cleared, interrupts off, serial port and timer 1 set up (SCON, TMOD, PCON, TH1,
 *      TR1), bit 7 of 0xF1E0 set.
 *   2. 16 rounds of a short wait, each serving the mailbox byte 0xF198. Here a command is run only when it differs
 *      from the one run before, so the same command twice in a row runs once.
 *   3. The reset sequence also used by fwupd_step_port_state: 0xCD0A / 0xCD2A = 0x80 for 10 units, then 0; bits 4
 *      and 5 of 0xF101 set for 10 units, then cleared, and bit 6 set. Print "Start to loop..".
 * Main loop, every round:
 *   1. A non-zero mailbox byte is run by fwupd_run_mailbox_command and cleared.
 *   2. When the USB mode asked for differs from the one in effect, both controllers are set up for it (host:
 *      the port states first go to the status registers 0xF190 / 0xF192, then usb_host_init_controller; device:
 *      usb_device_mode_init) and the new mode is in effect. Another value (0xFF among them) only becomes the
 *      mode in effect.
 *   3. Otherwise host mode steps the update state machine of each port whose command register does not hold
 *      0x21, and device mode serves the status of both controllers (usb_otg_service_irq).
 */
void sys_main(void)
{
    unsigned char round;
    unsigned char command;
    unsigned char unused;
    command = 0;
    unused = 0;
    P1 = P1_START;
    DAT_EXTMEM_f101 &= 0x7f;
    EA = 0;
    SCON = 0x52;
    TMOD = 0x21;
    PCON = 0x80;
    TH1 = 0xf3;
    TR1 = 1;
    DAT_EXTMEM_f1e0 |= F1E0_BIT7;
    for (round = 0; round < START_ROUNDS; round++) {
        timer_delay_units(START_ROUND_UNITS);
        if (reg_fwupd_mailbox_cmd != command) {
            command = reg_fwupd_mailbox_cmd;
            fwupd_run_mailbox_command(command);
            reg_fwupd_mailbox_cmd = 0;
        }
    }
    reg_usb0_byte_0a = REG_CD0A_PULSE;
    reg_usb1_byte_0a = REG_CD0A_PULSE;
    timer_delay_units(10);
    reg_usb0_byte_0a = 0;
    reg_usb1_byte_0a = 0;
    timer_delay_units(0x14);
    DAT_EXTMEM_f101 |= F101_PULSE_BITS;
    timer_delay_units(10);
    DAT_EXTMEM_f101 &= F101_KEEP_MASK;
    DAT_EXTMEM_f101 |= F101_BIT6;
    lib_printf517((void code *)FMT_START_LOOP);
    for (;;) {
        if (reg_fwupd_mailbox_cmd != 0) {
            command = reg_fwupd_mailbox_cmd;
            fwupd_run_mailbox_command(command);
            reg_fwupd_mailbox_cmd = 0;
        }
        if (fwupd_mode_state[0] != fwupd_requested_usb_mode) {
            /* Mode change: set up both controllers once. */
            if (fwupd_requested_usb_mode == USB_MODE_HOST) {
                reg_fwupd_port0_status = fwupd_mode_state[1];
                reg_fwupd_port1_status = fwupd_mode_state[2];
                usb_select_controller(0);
                usb_host_init_controller();
                usb_select_controller(1);
                usb_host_init_controller();
                lib_printf517((void code *)FMT_HOST_MODE);
            } else if (fwupd_requested_usb_mode == USB_MODE_DEVICE) {
                usb_select_controller(0);
                usb_device_mode_init();
                usb_select_controller(1);
                usb_device_mode_init();
                lib_printf517((void code *)FMT_DEVICE_MODE);
            }
            fwupd_mode_state[0] = fwupd_requested_usb_mode;
        } else if (fwupd_requested_usb_mode != USB_MODE_NONE) {
            if (fwupd_requested_usb_mode == USB_MODE_HOST) {
                if (reg_fwupd_port0_command != PORT_COMMAND_SKIP) fwupd_step_port_state(0);
                if (reg_fwupd_port1_command != PORT_COMMAND_SKIP) fwupd_step_port_state(1);
            } else if (fwupd_requested_usb_mode == USB_MODE_DEVICE) {
                usb_select_controller(0);
                usb_otg_service_irq();
                usb_select_controller(1);
                usb_otg_service_irq();
            }
        }
    }
}
