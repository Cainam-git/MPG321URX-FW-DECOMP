/* ipc_run_command  (FUN_CODE_224f)
 *
 * Carry out one numbered command word written by the main processor.
 *   word: command word: number in bits 0-7, arguments above
 * Note: Acknowledges by clearing portal word 0 except for commands 0, 0x16 and 0x17.
 * Name basis: proven - prints CMD_SYS_POWERSAVING, CMD_SYS_POWEROFF, CMD_WRITE_DPTXHDCP, CMD_FE2P_SETEXTEND;
 *   docs/MAP.md update path; the commands are listed in docs/MAILBOX.md
 *
 * Matching notes
 * --------------
 * Byte-exact with OPTIMIZE(8,SPEED) LARGE: ipc_run_command over 0x224F..0x27B5 (1382 bytes) and, in the same file,
 * ipc_clear_portal_word over 0xD59B..0xD5C8 (45 bytes).
 * Source forms the exact build depends on:
 * - ipc_clear_portal_word must be in this module: 0xD59B..0xD5A0 ('MOV R6,#0 / MOV R5,#0 / MOV R4,#0') is Keil's
 *   common-entry block for its unsigned long parameter, built from the two calls here (0x0C and 0). Without it
 *   Keil emits 'CLR A / MOV R7,A' at 0x27AF.
 * - 'command = word & 0xFF' (not '(uchar)word') gives the full R4..R7 load at 0x2255.
 * - The case bodies stay in this order: Keil places them in source order, which is the firmware's code order.
 * - The empty cases (3, 4, 11, 12, 16, 44..47) are needed for the 49-entry jump table at 0x22DB; without them
 *   Keil builds a ?C?CCASE search instead.
 * - ipc_sum_flash_data and ipc_post_result_word are declared without their unsigned long result / parameter: the
 *   checksum passes from one to the other in R4..R7.
 * - volatile only on chip registers (0xF0xx / 0xF1xx and reg_chip_id, which is read again for each test).
 * - Texts are CODE addresses passed to lib_printf517.
 */
#pragma LARGE
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
sfr SFR_A5 = 0xA5;
sbit P1_4 = 0x94;
sbit P1_5 = 0x95;
extern void lib_printf517(void *fmt, ...) large;   /* printf */
extern unsigned char volatile xdata DAT_EXTMEM_f00a, DAT_EXTMEM_f0e0, DAT_EXTMEM_f0cc, DAT_EXTMEM_f1f0;
extern unsigned char volatile xdata DAT_EXTMEM_f150, DAT_EXTMEM_f152, DAT_EXTMEM_f1eb, DAT_EXTMEM_f1e0;
extern unsigned char volatile xdata DAT_EXTMEM_f17c, DAT_EXTMEM_f17d, DAT_EXTMEM_f17e, DAT_EXTMEM_f17f;
extern unsigned char volatile xdata reg_chip_id;
extern unsigned char xdata sys_run_state, edid_readback_count, edid_readback_offset, ipc_cmd25_sequence_state;
extern unsigned char xdata ipc_cmd25_first_port, ipc_cmd25_second_port, DAT_EXTMEM_cab2;
extern unsigned char xdata DAT_EXTMEM_cbc1, DAT_EXTMEM_cbc2, DAT_EXTMEM_cbc3, DAT_EXTMEM_cbc4, DAT_EXTMEM_cbc5, DAT_EXTMEM_cbc6;
extern void edid_setup_port_slaves(uchar, uchar, uchar);
extern void edid_enable_port_slaves(uchar);
extern void edid_disable_port_slaves(uchar);
extern void uart_open_ports(uchar, uchar, uchar);
extern void uart_close_ports(uchar);
extern void ddc_set_slave_address(uchar, uchar);
extern void ddc_enable_slave(uchar);
extern void ddc_arm_slave(uchar);
extern void ddc_disable_slave(uchar);
extern void irq_set_capture_mask(uchar);
extern void edid_set_port_entries(uchar, uchar);
extern void edid_clear_port_entries(uchar);
extern void flash_set_job_length(uchar);
extern void flash_set_job_address(uint);
extern void flash_calc_window_room(void);
extern void flash_update_fe2p_address(void);
extern uchar ipc_wait_flash_handshake(void);
extern void flash_write_from_buffer(void);
extern void flash_read_to_buffer(void);
extern void ipc_sum_flash_data(void);
extern void ipc_post_result_word(void);
extern void flash_erase_sector_at_addr(void);
extern void ipc_finish_flash_handshake(void);
extern void flash_write_buffer_bytes(uint, uchar);
extern void flash_set_fe2p_extend(ulong);
extern void sys_stop_leon2m(void);
extern void sys_stop_leon2s(void);
extern void power_setup_power_saving(void);
extern void sys_restart_key_scan_timer(void);
extern void power_reset_wake_table(uchar);
extern void power_clear_port_wake_flags(void);
extern void power_off_sequence(void);
extern void hdcp_load_dptx_key_data(void);
extern void sys_set_timed_toggle_target(uint);
extern void sys_set_timed_limits_ch0(uchar, uchar);
extern void sys_set_timed_limits_ch1(uchar, uchar);
extern void sys_set_timed_ramp_fields(uchar, uchar, uchar);
extern void sys_set_timed_ramp_step(uchar, uchar, uchar);
extern void sys_set_adc_key_tolerance(uchar);
extern void power_set_wakeup_timer(uint);
extern void edid_set_port_control_bit6(uchar, uchar);
extern void ipc_portal_write(uchar off, ulong *src, uchar n);
void ipc_clear_portal_word(ulong off);
extern void hdmi_cec_set_two_regs(uchar, uchar);
extern void sys_empty_function(void);
extern void fwupd_run_flash_loop(void);
extern void Enable_DPMRX(void);
extern void Disable_DPMRX(void);


/* Command numbers (docs/MAILBOX.md, "Commands to the 8051"). */
#define IPC_8051_CMD_ENABLE_EDID         0x01
#define IPC_8051_CMD_DISABLE_EDID        0x02
#define IPC_8051_CMD_OPEN_UART           0x05
#define IPC_8051_CMD_CLOSE_UART          0x06
#define IPC_8051_CMD_ENABLE_DDC_SLAVE    0x07
#define IPC_8051_CMD_DISABLE_DDC_SLAVE   0x08
#define IPC_8051_CMD_SET_CAPTURE_IRQS    0x09
#define IPC_8051_CMD_STOP_CAPTURE_IRQS   0x0A
#define IPC_8051_CMD_READ_EDID_RAM       0x0D
#define IPC_8051_CMD_SET_EDID_ENTRIES    0x0E
#define IPC_8051_CMD_CLEAR_EDID_ENTRIES  0x0F
#define IPC_8051_CMD_FLASH_PROGRAM       0x11
#define IPC_8051_CMD_FLASH_READ          0x12
#define IPC_8051_CMD_FLASH_ERASE         0x13
#define IPC_8051_CMD_FLASH_SET_JOB       0x14
#define IPC_8051_CMD_FLASH_WRITE_BYTES   0x15
#define IPC_8051_CMD_POWER_SAVING        0x16
#define IPC_8051_CMD_POWER_OFF           0x17
#define IPC_8051_CMD_TOGGLE_TARGET       0x18
#define IPC_8051_CMD_TOGGLE_LIMITS_0     0x19
#define IPC_8051_CMD_TOGGLE_LIMITS_1     0x1A
#define IPC_8051_CMD_ADC_KEY_TOLERANCE   0x1B
#define IPC_8051_CMD_WAKEUP_TIMER        0x1C
#define IPC_8051_CMD_SET_P14             0x1D
#define IPC_8051_CMD_SET_P15             0x1E
#define IPC_8051_CMD_EDID_SLAVE_BIT6     0x1F
#define IPC_8051_CMD_CLEAR_DDC_FLAGS     0x20
#define IPC_8051_CMD_LOAD_DPTX_HDCP      0x21
#define IPC_8051_CMD_SWITCH_BIT3         0x22
#define IPC_8051_CMD_SET_OPTION_BYTE     0x23
#define IPC_8051_CMD_SET_CEC_REGS        0x24
#define IPC_8051_CMD_PORT_SEQUENCE       0x25
#define IPC_8051_CMD_FLASH_EXTEND        0x26
#define IPC_8051_CMD_HANDSHAKE           0x27
#define IPC_8051_CMD_SET_OPTION_FLAG     0x28
#define IPC_8051_CMD_FW_UPDATE_LOOP      0x29
#define IPC_8051_CMD_TAKE_OVER_DP_AUX    0x2A
#define IPC_8051_CMD_RELEASE_DP_AUX      0x2B
#define IPC_8051_CMD_RAMP_FIELDS         0x30
#define IPC_8051_CMD_RAMP_STEP           0x31

#define IPC_8051_CMD_NONE      0        /* command word empty: nothing to do, no acknowledge */
#define PORTAL_COMMAND_WORD    0        /* portal word +0x00: the command word */
#define PORTAL_DDC_ACCESS_WORD 0x0C     /* portal word +0x0C: ports whose EDID / DDC was accessed */

/*
 * ipc_run_command - carry out one command word from the main processor.
 *   word  bits 0..7 command number, bits 8..15 arg1, bits 16..23 arg2, bits 24..31 arg3 (arg23 = bits 16..31)
 * Callers: ipc_service_mailbox with portal word +0x00, and ipc_run_message for each word of a command-list
 * message.
 *
 * Phases:
 *   1. Split the word into the command number and its argument bytes.
 *   2. Carry the command out (see the IPC_8051_CMD_* list; what each handler does is in docs/MAILBOX.md):
 *      - port set-up: EDID slaves, serial ports, DDC/CI slaves, capture interrupts, EDID read-back, CEC registers;
 *      - flash jobs FLASH_PROGRAM / FLASH_READ / FLASH_ERASE / FLASH_WRITE_BYTES: each waits for the main
 *        processor's handshake on portal word +0xB8 (ipc_wait_flash_handshake), runs only when that wait returns
 *        non-zero, and always answers it (ipc_finish_flash_handshake). FLASH_READ posts the buffer checksum even
 *        when the wait failed;
 *      - POWER_SAVING / POWER_OFF: stop both LEON processors, write 9 to 0xF150 and set bit 6 of 0xF152, then
 *        the power-saving set-up or the power-off sequence; sys_run_state = 0 / 1;
 *      - HANDSHAKE: while the handshake is held, 0xF00A and 0xF0E0 read 0xAA, afterwards 0x55;
 *      - FW_UPDATE_LOOP: enters fwupd_run_flash_loop, which never returns.
 *      Numbers without a case, and the empty cases, do nothing.
 *   3. Acknowledge: clear the command word in the portal, for every number except NONE, POWER_SAVING and
 *      POWER_OFF.
 */
void ipc_run_command(ulong word)
{
    uchar command, arg1, arg2, arg3;
    uint arg23;

    /* Phase 1: split the command word. */
    command = word & 0xFF;
    arg1 = word >> 8;
    arg2 = word >> 16;
    arg3 = word >> 24;
    arg23 = word >> 16;

    /* Phase 2: carry it out. */
    switch (command) {
    case IPC_8051_CMD_ENABLE_EDID: edid_setup_port_slaves(arg1, arg2, arg3); edid_enable_port_slaves(arg1); break;
    case IPC_8051_CMD_DISABLE_EDID: edid_disable_port_slaves(arg1); break;
    case IPC_8051_CMD_OPEN_UART: uart_open_ports(arg1, arg2, arg3); break;
    case IPC_8051_CMD_CLOSE_UART: uart_close_ports(arg1); break;
    case IPC_8051_CMD_ENABLE_DDC_SLAVE: ddc_set_slave_address(arg1, arg2); ddc_enable_slave(arg1); ddc_arm_slave(arg1); break;
    case IPC_8051_CMD_DISABLE_DDC_SLAVE: ddc_disable_slave(arg1); break;
    case IPC_8051_CMD_SET_CAPTURE_IRQS: irq_set_capture_mask(arg1); break;
    case IPC_8051_CMD_STOP_CAPTURE_IRQS: irq_set_capture_mask(0); break;
    /* Offset / 16 and count of the EDID RAM read-back; the report itself goes out with the messages. */
    case IPC_8051_CMD_READ_EDID_RAM: edid_readback_offset = arg2; edid_readback_count = arg3; break;
    case IPC_8051_CMD_SET_EDID_ENTRIES: edid_set_port_entries(arg1, arg2); break;
    case IPC_8051_CMD_CLEAR_EDID_ENTRIES: edid_clear_port_entries(arg1); break;
    /* Job length, then the 16-bit job address (arg2 high, arg3 low). */
    case IPC_8051_CMD_FLASH_SET_JOB: flash_set_job_length(arg1); flash_set_job_address(((uint)arg2 << 8) + arg3); flash_calc_window_room(); flash_update_fe2p_address(); break;
    case IPC_8051_CMD_FLASH_PROGRAM: if (ipc_wait_flash_handshake()) flash_write_from_buffer(); ipc_finish_flash_handshake(); break;
    case IPC_8051_CMD_FLASH_READ: if (ipc_wait_flash_handshake()) flash_read_to_buffer(); ipc_sum_flash_data(); ipc_post_result_word(); ipc_finish_flash_handshake(); break;
    case IPC_8051_CMD_FLASH_ERASE: if (ipc_wait_flash_handshake()) flash_erase_sector_at_addr(); ipc_finish_flash_handshake(); break;
    /* Buffer offset (arg2 high, arg3 low) and byte count arg1. */
    case IPC_8051_CMD_FLASH_WRITE_BYTES: if (ipc_wait_flash_handshake()) flash_write_buffer_bytes(((uint)arg2 << 8) + arg3, arg1); ipc_finish_flash_handshake(); break;
    case IPC_8051_CMD_FLASH_EXTEND:
        lib_printf517((void code *)0x54e4 /* "CMD_FE2P_SETEXTEND : %02X%02X%02X" */, (uint)arg1, (uint)arg2, (uint)arg3);
        flash_set_fe2p_extend(((ulong)arg1 << 16) | ((ulong)arg2 << 8) | arg3);
        break;
    case IPC_8051_CMD_POWER_SAVING:
        lib_printf517((void code *)0x5508 /* "CMD_SYS_POWERSAVING" */);
        sys_stop_leon2m(); sys_stop_leon2s();
        DAT_EXTMEM_f150 = 9; DAT_EXTMEM_f152 |= 0x40;
        power_setup_power_saving();
        sys_run_state = 0;
        sys_restart_key_scan_timer();
        power_reset_wake_table(0);
        if (reg_chip_id == 0x20) power_clear_port_wake_flags();
        break;
    case IPC_8051_CMD_POWER_OFF:
        lib_printf517((void code *)0x551e /* "CMD_SYS_POWEROFF" */);
        sys_stop_leon2m(); sys_stop_leon2s();
        DAT_EXTMEM_f150 = 9; DAT_EXTMEM_f152 |= 0x40;
        power_off_sequence();
        sys_run_state = 1;
        sys_restart_key_scan_timer();
        break;
    case IPC_8051_CMD_LOAD_DPTX_HDCP: lib_printf517((void code *)0x5531 /* "CMD_WRITE_DPTXHDCP" */); hdcp_load_dptx_key_data(); break;
    case IPC_8051_CMD_TOGGLE_TARGET: sys_set_timed_toggle_target(arg23); break;
    case IPC_8051_CMD_TOGGLE_LIMITS_0: sys_set_timed_limits_ch0(arg2, arg3); break;
    case IPC_8051_CMD_TOGGLE_LIMITS_1: sys_set_timed_limits_ch1(arg2, arg3); break;
    case IPC_8051_CMD_RAMP_FIELDS: sys_set_timed_ramp_fields(arg1, arg2, arg3); break;
    case IPC_8051_CMD_RAMP_STEP: sys_set_timed_ramp_step(arg1, arg2, arg3); break;
    case IPC_8051_CMD_ADC_KEY_TOLERANCE: sys_set_adc_key_tolerance(arg2); break;
    case IPC_8051_CMD_WAKEUP_TIMER: power_set_wakeup_timer(arg23); lib_printf517((void code *)0x5546 /* "setWakeupTimer %04x" */, arg23); break;
    case IPC_8051_CMD_SET_P14:
        /* 0xF0CC, 0xF1F0 and SFR 0xA5 first (purpose not shown), then pin P1.4 = (arg23 != 0). */
        DAT_EXTMEM_f0cc = 0x30; DAT_EXTMEM_f1f0 = 0xFF; SFR_A5 = 0xFF;
        if (arg23 == 0) P1_4 = 0; else P1_4 = 1;
        lib_printf517((void code *)0x555c /* "CMD_SET_P14 %04x" */, arg23);
        break;
    case IPC_8051_CMD_SET_P15:
        DAT_EXTMEM_f0cc = 0x30; DAT_EXTMEM_f1f0 = 0xFF; SFR_A5 = 0xFF;
        if (arg23 == 0) P1_5 = 0; else P1_5 = 1;
        lib_printf517((void code *)0x556f /* "CMD_SET_P15 %04x" */, arg23);
        break;
    case IPC_8051_CMD_EDID_SLAVE_BIT6: edid_set_port_control_bit6(arg1, arg2); break;
    case IPC_8051_CMD_CLEAR_DDC_FLAGS: ipc_clear_portal_word(PORTAL_DDC_ACCESS_WORD); break;
    case IPC_8051_CMD_SWITCH_BIT3:
        /* Bit 3 is cleared in one of 0xF1EB / 0xF1E0 and set in the other. */
        if (arg2) { DAT_EXTMEM_f1eb &= 0xF7; DAT_EXTMEM_f1e0 |= 0x08; }
        else    { DAT_EXTMEM_f1eb |= 0x08; DAT_EXTMEM_f1e0 &= 0xF7; }
        break;
    case IPC_8051_CMD_SET_CEC_REGS: hdmi_cec_set_two_regs(arg2, arg3); break;
    case IPC_8051_CMD_SET_OPTION_BYTE:
        /* arg1 = index 0..5 of the bytes 0xCBC1..0xCBC6; other indexes write nothing. */
        switch (arg1) {
        case 0: DAT_EXTMEM_cbc1 = arg2; break;
        case 1: DAT_EXTMEM_cbc2 = arg2; break;
        case 2: DAT_EXTMEM_cbc3 = arg2; break;
        case 3: DAT_EXTMEM_cbc4 = arg2; break;
        case 4: DAT_EXTMEM_cbc5 = arg2; break;
        case 5: DAT_EXTMEM_cbc6 = arg2; break;
        }
        break;
    case IPC_8051_CMD_PORT_SEQUENCE:
        /* Only chip IDs 0x1A and 0x20 store the port pair and restart the sequence state; the sequence itself runs
           in ipc_run_cmd_0x25_sequence. */
        DAT_EXTMEM_f17c = arg1;
        if (reg_chip_id == 0x1A || reg_chip_id == 0x20) {
            ipc_cmd25_first_port = arg2; ipc_cmd25_second_port = arg3;
            DAT_EXTMEM_f17d = 1;
            if (reg_chip_id == 0x1A) { DAT_EXTMEM_f17e = 0xFF; DAT_EXTMEM_f17f = 0xFF; }
            else { DAT_EXTMEM_f17e = 0xAA; DAT_EXTMEM_f17f = 0; }
            ipc_cmd25_sequence_state = 0;
        }
        break;
    case IPC_8051_CMD_HANDSHAKE:
        if (ipc_wait_flash_handshake()) {
            DAT_EXTMEM_f00a = 0xAA; DAT_EXTMEM_f0e0 = 0xAA;
            if (reg_chip_id == 0x20) sys_empty_function();
        }
        ipc_finish_flash_handshake();
        DAT_EXTMEM_f00a = 0x55; DAT_EXTMEM_f0e0 = 0x55;
        break;
    case IPC_8051_CMD_SET_OPTION_FLAG:
        /* arg1 0 / 1 selects bit 0 / bit 2 of 0xCAB2; arg2 non-zero sets it. */
        switch (arg1) {
        case 0: if (arg2) DAT_EXTMEM_cab2 |= 0x01; else DAT_EXTMEM_cab2 &= 0xFE; break;
        case 1: if (arg2) DAT_EXTMEM_cab2 |= 0x04; else DAT_EXTMEM_cab2 &= 0xFB; break;
        }
        break;
    case IPC_8051_CMD_FW_UPDATE_LOOP: fwupd_run_flash_loop(); break;
    case IPC_8051_CMD_TAKE_OVER_DP_AUX: Enable_DPMRX(); break;
    case IPC_8051_CMD_RELEASE_DP_AUX: Disable_DPMRX(); break;
    case 3: case 4: case 11: case 12: case 16: case 44: case 45: case 46: case 47: break;
    }

    /* Phase 3: acknowledge. The two power commands are not acknowledged. */
    if (command != IPC_8051_CMD_NONE && command != IPC_8051_CMD_POWER_SAVING && command != IPC_8051_CMD_POWER_OFF) ipc_clear_portal_word(PORTAL_COMMAND_WORD);
}

/*
 * ipc_clear_portal_word - write the 32-bit value 0 to the mailbox portal word at byte offset offset.
 * Callers: ipc_run_command (the command word and the DDC access word) and ipc_service_mailbox (the header word of
 * a message slot after the message has been carried out).
 */
void ipc_clear_portal_word(ulong offset)
{
    ulong zero;
    zero = 0;
    ipc_portal_write(offset, &zero, 1);
}
