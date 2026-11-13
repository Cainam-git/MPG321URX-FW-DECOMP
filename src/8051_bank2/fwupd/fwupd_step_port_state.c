/* fwupd_step_port_state  (FUN_CODE_6e16)
 *
 * Run one step of the update agent's state machine for one USB port.
 *   port: USB port 0/1
 * Note: Flash writing starts only on port commands 0x11..0x17.
 * Name basis: proven - prints 'CMD_LOADFILE2DRAM', 'STATUS_WAIT_FW_UPDATE', 'CMD_START_ISP_ROMCODE_MODE'; cmd
 *   0xF191/3, status 0xF190/2
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_6e16 @ 0x6e16..0x7262, compiled with OPTIMIZE(8,SPEED) LARGE. LARGE parameter port (0x08E5);
 * locals state (0x08E6), command (0x08E7), retry (0x08E8), iface (0x08E9, 2 bytes, copied with ?C?COPY from the
 * structure usb_host_enumerate_device returns), declared in that XDATA order. The switch is a ?C?CCASE table at
 * 0x6e6f.
 * Source forms the bytes depend on: 0xF101 and 0xF19A are read through XBYTE (volatile: re-read after each store and
 * in each test), the other registers are plain externs (Keil then clears A before MOV DPTR for the zero stores);
 * identical case / arm tails are written out separately (Keil cross-jumps them); the round limit is 'retry++ > 2'.
 */
#include <absacc.h>

/* Port states (fwupd_port0_state / fwupd_port1_state, also shown to the main processor in the port's status
 * register). The names say how this routine reaches and leaves each state. */
#define STATE_WAIT_REG30_A          0x81  /* waits for bit 0 of register 0x30; not set by this routine */
#define STATE_WAIT_REG30            0x82  /* set while bit 0 of register 0x30 is clear; waits for it */
#define STATE_ENUMERATE             0x83  /* enumerate the device, then pick the next state by its class */
#define STATE_STOPPED               0x8f  /* no case of its own: stays until bit 0 of register 0x30 clears */
#define STATE_91                    0x91  /* not set by this routine: command 0x41 or a search for the file */
#define STATE_FILE_FOUND            0x92  /* update file found or selected: waits for a write command */
#define STATE_SCAN_HUB              0x93  /* class 9 device: search the hub's ports */
#define STATE_DISK_MOUNTED          0x96  /* disk volume mounted: waits for the list / load / select commands */
#define STATE_WAIT_FW_UPDATE        0x97  /* file loaded into DRAM ("STATUS_WAIT_FW_UPDATE") */
#define STATE_ISP_ENDED             0x99  /* 0xF19A wait ended without a code; set just before an endless loop */
#define STATE_LIST_EMPTY            0x9a  /* command 0x45 found no *.IMG entry and no entry was listed */
#define STATE_LIST_ENDED            0x9b  /* a listing reached its end; file position set back to the start */
#define STATE_FAILED                0x9c  /* "CheckSum Fail!" or fwupd_run_isp_write returned 0 */
#define STATE_CLASS3_PROTOCOL1      0xa1  /* class 3 device, protocol byte 1 */
#define STATE_CLASS3_PROTOCOL2      0xa2  /* class 3 device, protocol byte 2 */
#define STATE_GOT_CMD_41            0xb1  /* command 0x41 came in state 0x91 */
#define STATE_GOT_CMD_42            0xb2  /* command 0x42 came in state 0xB1 */
#define STATE_F19A_CODE_1           0xc1  /* states 0xC1..0xC4: code 1..4 in bits 0..2 of mailbox byte 0xF19A */
#define STATE_F19A_CODE_2           0xc2
#define STATE_F19A_CODE_3           0xc3
#define STATE_F19A_CODE_4           0xc4

/* Port commands (reg_fwupd_port0_command / reg_fwupd_port1_command, from the main processor). */
#define CMD_ISP_MODE_1              0x11  /* fwupd_run_isp_write(1), and 2 / 4 / 8 for the next three */
#define CMD_ISP_MODE_2              0x12
#define CMD_WRITE_PASS              0x13  /* usb_disk_run_write_pass, then CMD_ENDED and an endless loop */
#define CMD_ISP_MODE_4              0x14
#define CMD_ISP_MODE_8              0x15
#define CMD_START_ISP               0x16  /* "CMD_START_ISP_ROMCODE_MODE" */
#define CMD_START_ISP_DUALFW        0x17  /* "CMD_START_ISP_ROMCODE_MODE_DUALFW" */
#define CMD_NOTHING_31              0x31  /* accepted in STATE_FILE_FOUND, nothing done */
#define CMD_41                      0x41
#define CMD_42                      0x42  /* then fwupd_find_update_file(1): name from mailbox bytes 0xF19A.. */
#define CMD_POST_0717               0x43  /* fwupd_post_value_0717 */
#define CMD_POST_0109               0x44  /* fwupd_post_value_0109 */
#define CMD_LIST_IMG                0x45  /* fwupd_list_next_img_entry */
#define CMD_LOAD_FILE               0x46  /* "CMD_LOADFILE2DRAM" */
#define CMD_LIST_DIR                0x47  /* fwupd_list_next_dir_entry */
#define CMD_SET_TARGET_FILE         0x48  /* "File_SetTargetFilePara!" */
#define CMD_ENDED                   0xee  /* written into both command registers by CMD_WRITE_PASS */

/* Update modes of fwupd_run_isp_write (as in its file). */
#define ISP_MODE_BIT0               0x01
#define ISP_MODE_BIT1               0x02
#define ISP_MODE_BIT2               0x04
#define ISP_MODE_BIT3               0x08
#define ISP_MODE_RETURNS            0x10
#define ISP_MODE_PICK_REGION        0x11

/* Interface class and protocol bytes returned by usb_host_enumerate_device. */
#define IFACE_CLASS_3               3
#define IFACE_CLASS_STORAGE         8
#define IFACE_CLASS_HUB             9
#define STORAGE_PROTOCOL_50         0x50  /* the only class 8 protocol whose volume is mounted */
#define IFACE_PROTOCOL_1            1
#define IFACE_PROTOCOL_2            2

#define REG30_BIT0_SET              1     /* value of reg_window_get_reg30_bit0 */
#define REG_F101                    0xF101
#define F101_PULSE_BITS             0x30  /* set for 10 delay units, then cleared */
#define F101_KEEP_MASK              0xcf
#define F101_BIT6                   0x40
#define REG_CD0A_PULSE              0x80  /* held in 0xCD0A and 0xCD2A for 10 delay units */
#define MAILBOX_F19A                0xF19A
#define F19A_END_MASK               0x8f  /* the wait ends when all of bits 0..3 and 7 are set */
#define F19A_CODE_MASK              7     /* bits 0..2: code 1..4 gives STATE_F19A_CODE_1..4 */

/* Printed texts (CODE addresses). */
#define FMT_READ_FAIL               0xc2c2  /* "Fail to Read USB\r\n" */
#define FMT_LOAD_FILE               0xc2d5  /* "CMD_LOADFILE2DRAM\r\n" */
#define FMT_WAIT_FW_UPDATE          0xc2e9  /* "STATUS_WAIT_FW_UPDATE\r\n" */
#define FMT_CHECKSUM_FAIL           0xc301  /* "CheckSum Fail!\r\n" */
#define FMT_SET_TARGET_FILE         0xc312  /* "File_SetTargetFilePara!\r\n" */
#define FMT_START_ISP               0xc32c  /* "CMD_START_ISP_ROMCODE_MODE\r\n" */
#define FMT_START_ISP_DUALFW        0xc349  /* "CMD_START_ISP_ROMCODE_MODE_DUALFW\r\n" */

struct usb_iface_id { unsigned char class_code; unsigned char protocol; };
extern unsigned char xdata fwupd_port0_state;
extern unsigned char xdata fwupd_port1_state;
extern unsigned char xdata fwupd_dir_entry_count;
extern unsigned char xdata reg_usb0_byte_0a, reg_usb1_byte_0a;
extern unsigned char xdata reg_fwupd_port0_status, reg_fwupd_port0_command, reg_fwupd_port1_status, reg_fwupd_port1_command;
extern void lib_printf517(void *fmt, ...) large;
void usb_select_controller(unsigned char n);
unsigned char reg_window_get_reg30_bit0(void);
unsigned char usb_get_port_error_count(void);
void usb_clear_port_error_count(void);
void usb_host_init_controller(void);
struct usb_iface_id usb_host_enumerate_device(void);
void timer_delay_units(unsigned char n);
void fwupd_mount_volume(void);
unsigned char fwupd_list_next_img_entry(void);
unsigned char fwupd_list_next_dir_entry(void);
bit fwupd_load_file_to_dram(void);
void fwupd_reset_file_position(void);
void fwupd_set_target_file(void);
bit fwupd_run_isp_write(unsigned char mode);
void fwupd_svc_set_isp_mode(unsigned char a);
void fwupd_svc_set_write_protect(unsigned char on);
void fwupd_svc_claim_link(unsigned char m);
void fwupd_tag_new_region(void);
unsigned char fwupd_find_update_file(unsigned char m);
unsigned char usb_host_scan_hub_ports(void);
void usb_disk_run_write_pass(void);
void fwupd_post_value_0717(void);
void fwupd_post_value_0109(void);
void usb_read_port_status_record(void);

/* fwupd_step_port_state: one step of the update agent's work on one USB port in host mode.
 *   port: 1 = USB port 1 (fwupd_port1_state, command 0xF193, status 0xF192); any other value = port 0
 *         (fwupd_port0_state, command 0xF191, status 0xF190)
 *
 * Caller: sys_main, while the requested USB mode is 0 (host mode): once for port 0 and once for port 1 per loop
 * round, skipping a port whose command register holds 0x21.
 *
 * Phases:
 *   1. Select the port's controller (usb_select_controller) and read its state and command byte.
 *   2. Bit 0 of controller register 0x30 clear: every state but 0x81 / 0x82 resets the host controller and becomes
 *      STATE_WAIT_REG30. Bit 0 set: one step of the state (below).
 *   3. Store the new state in the state byte and the status register; clear the command register when a command
 *      was read (the command is used once).
 *
 * Steps by state:
 *   0x81, 0x82  bit 0 of register 0x30 set: STATE_ENUMERATE.
 *   0x83        enumerate the device; while the port's error flag is set, print "Fail to Read USB", run the same
 *               reset sequence of 0xCD0A / 0xCD2A / 0xF101 that sys_main runs at start-up and enumerate again (four
 *               rounds at most). Then by the class and protocol bytes: class 8 protocol 0x50 mounts the volume
 *               (STATE_DISK_MOUNTED), class 3 protocol 1 / 2 gives 0xA1 / 0xA2, class 9 STATE_SCAN_HUB, anything
 *               else STATE_STOPPED. The bytes are used even after four failed rounds.
 *   0x96, 0x9B  the disk commands: 0x45 lists the next *.IMG entry (none left: STATE_LIST_EMPTY when nothing was
 *               listed, else STATE_LIST_ENDED); 0x46 loads the selected file into DRAM (STATE_WAIT_FW_UPDATE; the
 *               "CheckSum Fail!" arm is not reached, fwupd_load_file_to_dram returns 1 in every case); 0x47 lists
 *               the next directory entry (none left: STATE_LIST_ENDED); 0x48 selects the listed entry as the
 *               update file (STATE_FILE_FOUND).
 *   0x97        0x16 / 0x17 start fwupd_run_isp_write in mode 0x10 / 0x11. On success the routine waits for mailbox
 *               byte 0xF19A (see the loop) and calls fwupd_svc_set_isp_mode(0) (fwupd_run_isp_write called it
 *               with 1). With no code seen it then (0x17 only: tags the new DUALFW region,) sets write protect,
 *               releases the service link and stops in an endless loop; STATE_ISP_ENDED is set before that loop
 *               and so never reaches the state byte or the status register. A failed start gives STATE_FAILED; a
 *               code in 0xF19A gives 0xC1..0xC4 and the routine returns.
 *   0x91        STATE_STOPPED unless command 0x41 (STATE_GOT_CMD_41) or the update file is found (STATE_FILE_FOUND).
 *   0xB1        command 0x42: STATE_GOT_CMD_42.
 *   0xB2        search the file by the name in mailbox bytes 0xF19A..: STATE_FILE_FOUND, else STATE_STOPPED.
 *   0x93        search the hub's ports: STATE_FILE_FOUND when the file is found.
 *   0x92        the write commands 0x11 / 0x12 / 0x14 / 0x15 (fwupd_run_isp_write modes 1 / 2 / 4 / 8, which do not
 *               return), 0x13 (usb_disk_run_write_pass, both command registers = 0xEE, endless loop), 0x43 / 0x44
 *               (post a stored value into the mailbox bytes), 0x31 (nothing).
 *   0xA1, 0xA2  usb_read_port_status_record.
 * States 0x8F, 0x9A, 0x9C and 0xC1..0xC4 have no step: they stay until bit 0 of register 0x30 clears. */
void fwupd_step_port_state(unsigned char port)
{
    unsigned char state;
    unsigned char command;
    unsigned char retry;
    struct usb_iface_id iface;
    /* 1. The port's controller, state and command. */
    usb_select_controller(port);
    if (port == 1) {
        state = fwupd_port1_state;
        command = reg_fwupd_port1_command;
    } else {
        state = fwupd_port0_state;
        command = reg_fwupd_port0_command;
    }
    /* 2. Bit 0 of register 0x30 clear: back to waiting. */
    if (reg_window_get_reg30_bit0() == 0) {
        if (state != STATE_WAIT_REG30_A && state != STATE_WAIT_REG30) {
            usb_host_init_controller();
            state = STATE_WAIT_REG30;
        }
    } else switch (state) {
    case STATE_WAIT_REG30_A:
        if (reg_window_get_reg30_bit0() == REG30_BIT0_SET) state = STATE_ENUMERATE;
        break;
    case STATE_WAIT_REG30:
        if (reg_window_get_reg30_bit0() == REG30_BIT0_SET) state = STATE_ENUMERATE;
        break;
    case STATE_ENUMERATE:
        usb_clear_port_error_count();
        usb_host_init_controller();
        iface = usb_host_enumerate_device();
        retry = 0;
        /* Failed: reset sequence (as at start-up in sys_main), enumerate again; four rounds at most. */
        while (usb_get_port_error_count()) {
            lib_printf517((void code *)FMT_READ_FAIL);
            reg_usb0_byte_0a = REG_CD0A_PULSE;
            reg_usb1_byte_0a = REG_CD0A_PULSE;
            timer_delay_units(10);
            reg_usb0_byte_0a = 0;
            reg_usb1_byte_0a = 0;
            timer_delay_units(20);
            XBYTE[REG_F101] |= F101_PULSE_BITS;
            timer_delay_units(10);
            XBYTE[REG_F101] &= F101_KEEP_MASK;
            XBYTE[REG_F101] |= F101_BIT6;
            usb_clear_port_error_count();
            usb_host_init_controller();
            iface = usb_host_enumerate_device();
            if (retry++ > 2) break;
        }
        /* Next state by the device's class. */
        state = STATE_STOPPED;
        if (iface.class_code == IFACE_CLASS_STORAGE && iface.protocol == STORAGE_PROTOCOL_50) {
            fwupd_mount_volume();
            state = STATE_DISK_MOUNTED;
        } else if (iface.class_code == IFACE_CLASS_3) {
            if (iface.protocol == IFACE_PROTOCOL_1) state = STATE_CLASS3_PROTOCOL1;
            else if (iface.protocol == IFACE_PROTOCOL_2) state = STATE_CLASS3_PROTOCOL2;
        } else if (iface.class_code == IFACE_CLASS_HUB) state = STATE_SCAN_HUB;
        break;
    case STATE_DISK_MOUNTED:
    case STATE_LIST_ENDED:
        usb_clear_port_error_count();
        if (command == CMD_LIST_IMG) {
            if (fwupd_list_next_img_entry() == 0) {
                /* End of the directory. */
                if (fwupd_dir_entry_count == 0) state = STATE_LIST_EMPTY;
                else {
                    fwupd_reset_file_position();
                    state = STATE_LIST_ENDED;
                }
            } else state = STATE_DISK_MOUNTED;
        } else if (command == CMD_LOAD_FILE) {
            lib_printf517((void code *)FMT_LOAD_FILE);
            if (fwupd_load_file_to_dram()) {
                lib_printf517((void code *)FMT_WAIT_FW_UPDATE);
                state = STATE_WAIT_FW_UPDATE;
            } else {
                lib_printf517((void code *)FMT_CHECKSUM_FAIL);
                state = STATE_FAILED;
            }
        } else if (command == CMD_LIST_DIR) {
            if (fwupd_list_next_dir_entry() == 0) {
                fwupd_reset_file_position();
                state = STATE_LIST_ENDED;
            }
        } else if (command == CMD_SET_TARGET_FILE) {
            fwupd_set_target_file();
            lib_printf517((void code *)FMT_SET_TARGET_FILE);
            state = STATE_FILE_FOUND;
        }
        break;
    case STATE_WAIT_FW_UPDATE:
        /* The two arms differ only in the mode and the DUALFW tag. */
        if (command == CMD_START_ISP) {
            lib_printf517((void code *)FMT_START_ISP);
            if (fwupd_run_isp_write(ISP_MODE_RETURNS)) {
                /* Wait until 0xF19A has all bits of F19A_END_MASK set, or holds a code 1..4. */
                while ((XBYTE[MAILBOX_F19A] & F19A_END_MASK) != F19A_END_MASK && state == STATE_WAIT_FW_UPDATE) {
                    if (XBYTE[MAILBOX_F19A] & F19A_CODE_MASK) {
                        if ((XBYTE[MAILBOX_F19A] & F19A_CODE_MASK) == 1) state = STATE_F19A_CODE_1;
                        else if ((XBYTE[MAILBOX_F19A] & F19A_CODE_MASK) == 2) state = STATE_F19A_CODE_2;
                        else if ((XBYTE[MAILBOX_F19A] & F19A_CODE_MASK) == 3) state = STATE_F19A_CODE_3;
                        else if ((XBYTE[MAILBOX_F19A] & F19A_CODE_MASK) == 4) state = STATE_F19A_CODE_4;
                    }
                }
                fwupd_svc_set_isp_mode(0);
                if (state == STATE_WAIT_FW_UPDATE) {
                    state = STATE_ISP_ENDED;
                    fwupd_svc_set_write_protect(1);
                    fwupd_svc_claim_link(0);
                    for (;;) ;
                }
            } else state = STATE_FAILED;
        } else if (command == CMD_START_ISP_DUALFW) {
            lib_printf517((void code *)FMT_START_ISP_DUALFW);
            if (fwupd_run_isp_write(ISP_MODE_PICK_REGION)) {
                while ((XBYTE[MAILBOX_F19A] & F19A_END_MASK) != F19A_END_MASK && state == STATE_WAIT_FW_UPDATE) {
                    if (XBYTE[MAILBOX_F19A] & F19A_CODE_MASK) {
                        if ((XBYTE[MAILBOX_F19A] & F19A_CODE_MASK) == 1) state = STATE_F19A_CODE_1;
                        else if ((XBYTE[MAILBOX_F19A] & F19A_CODE_MASK) == 2) state = STATE_F19A_CODE_2;
                        else if ((XBYTE[MAILBOX_F19A] & F19A_CODE_MASK) == 3) state = STATE_F19A_CODE_3;
                        else if ((XBYTE[MAILBOX_F19A] & F19A_CODE_MASK) == 4) state = STATE_F19A_CODE_4;
                    }
                }
                fwupd_svc_set_isp_mode(0);
                if (state == STATE_WAIT_FW_UPDATE) {
                    fwupd_tag_new_region();
                    state = STATE_ISP_ENDED;
                    fwupd_svc_set_write_protect(1);
                    fwupd_svc_claim_link(0);
                    for (;;) ;
                }
            } else state = STATE_FAILED;
        }
        break;
    case STATE_91:
        state = STATE_STOPPED;
        usb_clear_port_error_count();
        if (command == CMD_41) state = STATE_GOT_CMD_41;
        else if (fwupd_find_update_file(0)) state = STATE_FILE_FOUND;
        break;
    case STATE_GOT_CMD_41:
        if (command == CMD_42) state = STATE_GOT_CMD_42;
        break;
    case STATE_GOT_CMD_42:
        if (fwupd_find_update_file(1)) state = STATE_FILE_FOUND;
        else state = STATE_STOPPED;
        break;
    case STATE_SCAN_HUB:
        if (usb_host_scan_hub_ports()) state = STATE_FILE_FOUND;
        else state = STATE_SCAN_HUB;
        break;
    case STATE_FILE_FOUND:
        /* The write commands. */
        if (command == CMD_ISP_MODE_1) fwupd_run_isp_write(ISP_MODE_BIT0);
        else if (command == CMD_ISP_MODE_2) fwupd_run_isp_write(ISP_MODE_BIT1);
        else if (command == CMD_NOTHING_31) ;
        else if (command == CMD_WRITE_PASS) {
            usb_disk_run_write_pass();
            reg_fwupd_port1_command = CMD_ENDED;
            reg_fwupd_port0_command = CMD_ENDED;
            for (;;) ;
        } else if (command == CMD_ISP_MODE_4) fwupd_run_isp_write(ISP_MODE_BIT2);
        else if (command == CMD_ISP_MODE_8) fwupd_run_isp_write(ISP_MODE_BIT3);
        else if (command == CMD_POST_0717) fwupd_post_value_0717();
        else if (command == CMD_POST_0109) fwupd_post_value_0109();
        break;
    case STATE_CLASS3_PROTOCOL1:
        usb_read_port_status_record();
        break;
    case STATE_CLASS3_PROTOCOL2:
        usb_read_port_status_record();
        break;
    }
    /* 3. Keep the state, show it to the main processor, use the command once. */
    if (port == 1) {
        fwupd_port1_state = state;
        reg_fwupd_port1_status = state;
        if (command) reg_fwupd_port1_command = 0;
    } else {
        fwupd_port0_state = state;
        reg_fwupd_port0_status = state;
        if (command) reg_fwupd_port0_command = 0;
    }
}
