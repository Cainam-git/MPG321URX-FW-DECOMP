# Mailbox commands

The processors of the monitor talk to each other through mailboxes in shared memory (see
[Data objects](DATA.md#mailboxes)). This page lists every command and message that the code of FW.021 handles, with
the function that sends it and the function that carries it out. The descriptions state what the handling code does.
The commands to the Tensilica program are in the [firmware map](MAP.md#commands-from-the-main-processor).

## Main processor and 8051

### Commands to the 8051

The main processor sends a command word with `ipc_send_8051_command` (`FUN_a002f3f4`): the command number in bits
0-7, byte 1 in bits 8-15, byte 2 in bits 16-23, byte 3 in bits 24-31. In the 8051, `ipc_service_mailbox`
(`FUN_CODE_9243`) reads portal word +0x00 (AHB 0x9F0A0100) once per main-loop pass and calls `ipc_run_command`
(`FUN_CODE_224f`). The 8051 acknowledges by clearing word +0x00, except for 0x16 and 0x17.

- The flash jobs 0x11, 0x12, 0x13, 0x15 and 0x27 run inside a handshake on portal word +0xB8: the 8051 waits for
  low byte 1 (`ipc_wait_flash_handshake`) and answers with 2 (`ipc_finish_flash_handshake`).
- A port mask holds one bit per input port.
- The numbers 0x03, 0x04, 0x0B, 0x0C, 0x10 and 0x2C..0x2F have empty cases: acknowledged, no action.

| Command | Sender in the main program | Handler in the 8051 program | What the 8051 does |
|---|---|---|---|
| 0x01 | ipc_8051_enable_internal_edid | edid_setup_port_slaves (`FUN_CODE_abc4`), edid_enable_port_slaves (`FUN_CODE_c59a`) | Enable the internal EDID on the ports in the mask: slave address 0xA0, 256-byte mode when the EDID is longer than 128 bytes, then switch the slaves on. |
| 0x02 | ipc_8051_disable_internal_edid, UartSetI2CEnable | edid_disable_port_slaves (`FUN_CODE_c790`) | Switch the EDID slaves of the ports in the mask off. |
| 0x05 | ipc_8051_open_uart_ports | uart_open_ports (`FUN_CODE_a775`) | Open the serial ports in the mask: line format byte 2, baud rate = byte 3 x 1200. |
| 0x06 | ipc_8051_close_uart_ports | uart_close_ports (`FUN_CODE_c9b0`) | Close the serial ports in the mask. |
| 0x07 | ipc_8051_enable_ddc_slave, UartSetI2CEnable | ddc_set_slave_address (`FUN_CODE_bde9`), ddc_enable_slave (`FUN_CODE_9f04`), ddc_arm_slave (`FUN_CODE_c2d3`) | Set the DDC/CI slave address of the ports in the mask (MSI's tool: port bit 0, address 0x6E), switch the slaves on and arm them. |
| 0x08 | ipc_8051_disable_ddc_slave | ddc_disable_slave (`FUN_CODE_c278`) | Switch the DDC/CI slaves of the ports in the mask off. |
| 0x09 | ipc_8051_set_capture_irq_mask | irq_set_capture_mask (`FUN_CODE_c03f`) | Set which capture-interrupt sources are enabled (remote-control input). |
| 0x0A | ipc_8051_disable_capture_irqs | irq_set_capture_mask (`FUN_CODE_c03f`) | Disable all capture-interrupt sources (same function with 0). |
| 0x0D | ipc_8051_read_port_memory | (inline) | Ask for a read-back of the EDID RAM: offset / 16 and byte count; the 8051 answers with report type 1. |
| 0x0E | ipc_8051_enable_internal_edid | edid_set_port_entries (`FUN_CODE_bbca`) | Set the extra EDID entry (0xF180 + 2i, bit 7 on) of the ports in the mask; sent for EDIDs longer than 256 bytes. |
| 0x0F | ipc_8051_disable_internal_edid, UartSetI2CEnable | edid_clear_port_entries (`FUN_CODE_c7e0`) | Clear the extra EDID entry of the ports in the mask. |
| 0x11 | ipc_8051_flash_program_row | flash_write_from_buffer (`FUN_CODE_d3eb`) | Flash job: program the 2 KB flash data buffer to the job address (inside the 0xB8 handshake). |
| 0x12 | MailBox_LoadFE2P | flash_read_to_buffer (`FUN_CODE_d3b9`), ipc_sum_flash_data (`FUN_CODE_b781`), ipc_post_result_word (`FUN_CODE_dbdf`) | Flash job: read the job range into the buffer and post the result of ipc_sum_flash_data (always 0) to portal word 0xB0 (inside the 0xB8 handshake). |
| 0x13 | ipc_8051_flash_erase_sector | flash_erase_sector_at_addr (`FUN_CODE_da91`) | Flash job: erase the 4 KB sector at the job address (inside the 0xB8 handshake). |
| 0x14 | ipc_8051_flash_program_row, ipc_8051_flash_erase_sector, MailBox_LoadFE2P, ipc_8051_flash_write_bytes | flash_set_job_length (`FUN_CODE_de45`), flash_set_job_address (`FUN_CODE_c965`), flash_calc_window_room (`FUN_CODE_cd8c`), flash_update_fe2p_address (`FUN_CODE_d31d`) | Set the flash job length and address (window base + extension + 16-bit offset); prints 'Update FE2P Addr'. |
| 0x15 | ipc_8051_flash_write_bytes | flash_write_buffer_bytes (`FUN_CODE_9fc8`) | Flash job: program n bytes of the buffer at a buffer offset (prints 'FE2P WriteByte'; inside the 0xB8 handshake). |
| 0x16 | ipc_8051_notify_power_saving | sys_stop_leon2m (`FUN_CODE_cbac`), sys_stop_leon2s (`FUN_CODE_cbf2`), power_setup_power_saving (`FUN_CODE_71f0`), power_reset_wake_table (`FUN_CODE_ccc2`), power_clear_port_wake_flags (`FUN_CODE_d351`) | Power saving (prints CMD_SYS_POWERSAVING): stop both LEON cores, switch the chip into standby, start the wake-up checks. Not acknowledged. |
| 0x17 | ipc_8051_notify_power_off | sys_stop_leon2m (`FUN_CODE_cbac`), sys_stop_leon2s (`FUN_CODE_cbf2`), power_off_sequence (`FUN_CODE_7a0b`) | Power off (prints CMD_SYS_POWEROFF): stop both LEON cores and run the power-off sequence. Not acknowledged. |
| 0x18 | ipc_8051_set_indicator | sys_set_timed_toggle_target (`FUN_CODE_de03`) | Indicator: start the timed toggle of an XDATA register (bytes 2..3 = target). |
| 0x19 | ipc_8051_set_indicator | sys_set_timed_limits_ch0 (`FUN_CODE_dec2`) | Indicator: store the first level pair of the timed toggle (0xA73C/0xA73D). |
| 0x1A | ipc_8051_set_indicator | sys_set_timed_limits_ch1 (`FUN_CODE_decb`) | Indicator: store the second level pair of the timed toggle (0xA73E/0xA73F). |
| 0x1B | - | sys_set_adc_key_tolerance (`FUN_CODE_deee`) | Store the ADC key tolerance byte 0xA62E used by the wake-key scan. |
| 0x1C | MailBox_SetWakeUpTimer | power_set_wakeup_timer (`FUN_CODE_c830`) | Start the wake-up timer (prints 'setWakeupTimer %04x'). |
| 0x1D | ipc_8051_set_pin_p14 | (inline) | Drive pin P1.4 high or low (prints 'CMD_SET_P14'). |
| 0x1E | ipc_8051_set_pin_p15 | (inline) | Drive pin P1.5 high or low (prints 'CMD_SET_P15'). |
| 0x1F | ipc_8051_set_edid_slave_bit6 | edid_set_port_control_bit6 (`FUN_CODE_c87f`) | Set or clear bit 6 of one port's EDID slave control register. |
| 0x20 | ipc_8051_clear_ddc_access_flags | ipc_clear_portal_word (`FUN_CODE_d5a1`) | Clear portal word 0x0C (the DDC access flags of MailBox_UpdateDDCFlag). |
| 0x21 | ipc_8051_load_dp_tx_hdcp_data | hdcp_load_dptx_key_data (`FUN_CODE_d171`) | Load the DP transmitter HDCP data block (prints 'CMD_WRITE_DPTXHDCP'). |
| 0x22 | ipc_8051_switch_control_bit | (inline) | Switch bit 3 of 0xF1EB / 0xF1E0 one way or the other by byte 2. |
| 0x23 | ipc_8051_set_option_byte | (inline) | Store byte 2 in one of the six bytes 0xCBC1..0xCBC6 (byte 1 = index). |
| 0x24 | ipc_8051_set_cec_registers | hdmi_cec_set_two_regs (`FUN_CODE_de3a`) | Write two CEC controller registers (0xD820, 0xD810). |
| 0x25 | ipc_8051_start_port_sequence | (inline), then ipc_run_cmd_0x25_sequence (`FUN_CODE_4ec1`) | Store a port pair and start the timed port sequence (chip IDs 0x1A / 0x20 only). |
| 0x26 | ipc_8051_set_flash_window_extend | flash_set_fe2p_extend (`FUN_CODE_dee8`) | Set the 24-bit flash window extension (prints 'CMD_FE2P_SETEXTEND'). |
| 0x27 | ipc_8051_start_handshake | ipc_wait_flash_handshake (`FUN_CODE_c163`), ipc_finish_flash_handshake (`FUN_CODE_cb1d`) | Hold the 8051 in a handshake with the main processor (0xF00A / 0xF0E0 = 0xAA while it lasts). |
| 0x28 | ipc_8051_set_option_flag | (inline) ipc_run_command_part2 (`FUN_CODE_275e`) | Set or clear bit 0 or bit 2 of 0xCAB2 (byte 1 selects the bit). |
| 0x29 | not found as a literal in the main program | fwupd_run_flash_loop (`FUN_CODE_6c34`) | Enter the firmware-update flash loop (prints 'STBC FW updating'); never returns (see the [firmware map](MAP.md#update-path)). |
| 0x2A | ipc_8051_take_over_dp_aux | Enable_DPMRX (`FUN_CODE_dd09`) | Switch both DP receivers to 8051-handled AUX mode (DP_EnableMRX). |
| 0x2B | ipc_8051_release_dp_aux | Disable_DPMRX (`FUN_CODE_de2e`) | Hand the DP receivers back (prints 'Disable_DPMRX'). |
| 0x30 | - | sys_set_timed_ramp_fields (`FUN_CODE_d70f`) | Indicator: set the ramp mode fields of the timed ramp. |
| 0x31 | - | sys_set_timed_ramp_step (`FUN_CODE_ba6d`) | Indicator: set the high/low levels and step of one ramp channel. |

### Messages to the 8051

Four slots at portal +0x10 + 20 * i, each a header word and four data words. `ipc_find_rx_message` (`FUN_CODE_960f`)
finds a filled slot, `ipc_run_message` (`FUN_CODE_1c3c`) carries it out, then the header is cleared. Header word: type
in bits 0-3, flags in bits 4-7 (bit 4 = last piece), port or channel in bits 8-15, byte count in bits 16-23 (16 at
most), offset / 16 in bits 24-31.

| Type | Sender in the main program | Handler in the 8051 program | Content |
|---|---|---|---|
| 1 | ipc_8051_write_port_memory | (inline) | EDID bytes into the EDID RAM 0xF800 (2 KB); 'EDID address out of range!' past the end. |
| 2 | not identified | i2c_write_eeprom_pages (`FUN_CODE_50c9`), i2c_master_write_read (`FUN_CODE_83f3`) | I2C transfer on hardware channel 0..5: write in 8-byte EEPROM pages, or (flag bit 7 of the channel byte) write-then-read; the read result goes back as report type 2. 'DATA_I2C OOR'. |
| 3 | not identified | uart_putchar (`FUN_CODE_d511`), uart_queue_tx_byte_port2 (`FUN_CODE_db32`), uart_queue_tx_byte_port3 (`FUN_CODE_db4b`), uart_queue_tx_byte_port4 (`FUN_CODE_db64`), uart_flush_tx_queue_port2 (`FUN_CODE_cfad`), uart_flush_tx_queue_port3 (`FUN_CODE_cfe7`), uart_flush_tx_queue_port4 (`FUN_CODE_d021`) | Bytes to send on serial port 1..4; flag bit 4 starts the transmission. |
| 4 | not identified | (inline) | DDC/CI reply bytes into the port's out buffer 0xA002 + row * 0x3C; the last piece sets the reply length. 'DATA_DDCCI OOR'. |
| 6 | not identified | ipc_run_command (`FUN_CODE_224f`) | A list of command words, each carried out as above. |
| 7 | ipc_8051_send_storage_block | ipc_store_flash_data (`FUN_CODE_a36c`) | Flash data into the 2 KB buffer 0xA800; then the result of ipc_sum_flash_data (always 0) is posted to portal word 0xB0. |
| 8 | ipc_8051_send_wake_key_table | FillKeyDetectList (`FUN_CODE_9053`) | Standby key and wake-pin table (60 bytes at 0xA5ED). |
| 9 | ipc_8051_send_wake_port_table | ipc_store_wake_port_list (`FUN_CODE_b3cb`) | Wake-up port table (ten 3-byte entries at 0xA62F, 'SetZPArry'). |
| 10 | ipc_8051_send_power_cut_table | ipc_store_power_cut_list (`FUN_CODE_a819`) | Power-cut table (18 bytes at 0xA6AF, 'CutPwArray'). |
| 11 | ipc_8051_send_usb_c_info | FillTypeCInfo (`FUN_CODE_74af`) | Ten-byte USB-C port description (0xA69C). |
| 15 | not identified | (inline) | Test: print the five words ('DataTest'). |
| 5, 12, 13, 14 | - | - | Ignored. |

### Messages from the 8051

Four slots at portal +0x60 + 20 * i. `ipc_find_free_tx_slot` (`FUN_CODE_8512`) finds a free one,
`ipc_fill_report_record` (`FUN_CODE_38a7`) picks the next pending source and `ipc_build_report_message`
(`FUN_CODE_5c06`) cuts it into 16-byte pieces. Header word: type in bits 0-3, bit 4 = last piece, channel in bits 8-15,
byte count in bits 16-23, piece number in bits 24-31 (the number of 16-byte pieces sent before). The main processor
reads the messages with `ipc_8051_poll_messages` and sorts them in `ipc_8051_decode_message`.

| Type | Source | Content |
|---|---|---|
| 1 | EDID RAM | Read-back of 0xF800 asked for with command 0x0D. |
| 2 | I2C | Result of a message type 2 read. |
| 3 | serial ports 1..4 | Received bytes (uart_find_port_with_rx_data, uart_read_rx_ring). |
| 4 | DDC/CI | A request a computer sent to a port's DDC/CI slave (row of 0xA0F4). |
| 5 | infrared | Remote-control pulse lengths ('Reload IR'). |

### Other portal words the 8051 writes

| Word | Content |
|---|---|
| +0x0C, low byte | The ports whose EDID/DDC was accessed (`MailBox_UpdateDDCFlag`). |
| +0xB0 | The result word of `ipc_sum_flash_data`, always 0 (`ipc_post_result_word`). |
| +0xB4 | The flash window base (`flash_update_fe2p_address`). |
| +0xB8, bits 8-15 | Start-up release / boot source (`startup_release_leon2m`). |
| +0xB8, low byte | The flash job handshake. |

## Main processor and input processor

The main processor sends a command with `ipc_send_command` (`FUN_a01370dc`): the command number, the data words and
a checksum go into mailbox slot 8 of portal 1. The input processor reads the slot in `ipc_poll_command`
(`FUN_a0072900`) and carries the command out in `ipc_dispatch_command` (`FUN_a0070b7c`). Commands that answer fill a
28-byte buffer that goes back with `ipc_send_reply` (slot 10).

- Port numbers inside commands: 0 and 1 are the HDMI 2.0 inputs, 2 and 3 the HDMI 2.1 inputs, 4 and 5 the
  DisplayPort inputs; other numbers have no effect.
- A "-" in the sender column means that no function of the main program sends the number as a fixed value.

| Command | Sender in the main program | Handler in the input program | What the input processor does |
|---|---|---|---|
| 0x00 | - | (inline) | Test: reply with the bytes 0..27 (link check). |
| 0x01 | - | hdmi_phy_request_eq_reset (`FUN_a00734d8`) | Set the power/state byte of one HDMI PHY. |
| 0x02 | ipc_set_input_port_type | input_set_port_type (`FUN_a006d414`) | Set the type of one input port (byte 0 port, byte 1 type). |
| 0x03 | - | hdmi_calc_pixel_clock (`FUN_a00910ec`), hdmi_rx21_calc_tmds_clock (`FUN_a00a20c4`), dp_calc_pixel_clock (`FUN_a00acc54`), dp_set_reg9f_field (`FUN_a00d65a0`) | Reply the 16-bit clock value computed for input 0..8 (6..8 = streams 1..3 of DisplayPort input 0). |
| 0x11 | ipc_enable_hdmi_phy_input | hdmi_phy_set_input_enable (`FUN_a007ae30`) | Enable or disable the input of one HDMI PHY. |
| 0x12 | ipc_restart_hdmi_port | hdmi_tmds_restart_port (`FUN_a008ffa4`), hdmi_rx21_restart_port (`FUN_a00a22d4`), hdmi_rx21_reset_rx_detect_state (`FUN_a00a29ec`), hdmi_phy_request_eq_reset (`FUN_a00734d8`) | Restart one HDMI input port (2.0 path for ports 0/1, 2.1 path for 2/3), then set its PHY state byte. |
| 0x13 | - | hdmi_reg_write8 (`FUN_a00a65c4`), hdmi_rx21_reg_write8 (`FUN_a00a69fc`) | Write one HDMI receiver register chosen from the register list 0xA80760F0. |
| 0x14 | ipc_set_hdcp_rx_port_option | hdcp_rx_set_port_option (`FUN_a00c19b8`) | Write an option of an input's protection block; set by a command from the main processor. |
| 0x15 | ipc_set_hdmi_phy_option_byte | (inline) | Store a byte in field +7 of one HDMI PHY record (0xA807CC64). |
| 0x16 | ipc_set_hdmi21_port_mask | hdmi_rx21_set_mask_bits (`FUN_a00a2418`), hdmi_rx21_clear_mask_bits (`FUN_a00a2564`) | Apply a mask to the HDMI 2.1 port records (newer chip revisions only). |
| 0x20 | dp_set_port_dsc_support, ipc_set_dp_rx_config | dp_init_port (`FUN_a00b1028`) | Store the full DisplayPort receiver configuration of one port and set the port up. |
| 0x21 | input_set_port_link_field_first, input_set_port_link_field_second, input_set_port_link_field_third, input_set_port_link_flag_row7, ipc_set_dp_rx_mode | dp_program_port (`FUN_a00abff0`), dp_setup_port_regs (`FUN_a00ac66c`), dp_apply_port_settings (`FUN_a00af98c`), dp_mst_select_port (`FUN_a00dc264`), dp_mst_reset_port (`FUN_a00dc0a8`) | Store the DP receiver mode bytes of one port and reprogram its registers. |
| 0x22 | ipc_get_dp_rx_register | dp_reg_read8 (`FUN_a00a6bb8`) | Reply one DP receiver register (0x200..0x3FF) of one port. |
| 0x23 | - | dp_write_dpcd_reg (`FUN_a00ac4ec`) | Write one DP receiver register (0x200 and up) of one port. |
| 0x24 | input_set_port_link_byte3, ipc_set_dp_mst | dp_set_port0_setting_112 (`FUN_a00afd74`), dp_mst_select_port (`FUN_a00dc264`), dp_mst_reset_port (`FUN_a00dc0a8`) | Switch DP multi-stream (MST) on or off for one port (prints '_SetDPMST'). |
| 0x25 | ipc_set_dp_rx_capabilities | dp_write_capability_regs (`FUN_a00abe20`) | Store two DP receiver mode bytes and rewrite the port's capability registers 0x200..0x203. |
| 0x26 | ipc_set_dp_rx_option | dp_set_port_setting_115 (`FUN_a00afd04`) | Store DP receiver option byte +0x115 and reprogram the port. |
| 0x27 | - | dp_set_regs_c5_c4 (`FUN_a00aea3c`) | Write DP receiver registers 0xC5 and 0xC4 of one port. |
| 0x28 | ipc_api_set_dp_rx_reg40_bits, ipc_set_dp_rx_reg40_bits | dp_set_reg40_bits_6_7 (`FUN_a00ae344`) | Set bits 6..7 of DP receiver register 0x40 and run the follow-up set-up. |
| 0x29 | - | dp_set_reg9f_field (`FUN_a00d65a0`) | Write the 2-bit field at bits 6-7 of register 0x9F of a port. |
| 0x2A | - | dp_set_reg30_bit6 (`FUN_a00ae1c0`) | Pulse a reset bit of one DP receiver port. |
| 0x2B | ipc_load_dp_rx_clock_registers | dp_clear_reg223_bit7 (`FUN_a00ad764`), dp_clear_reg3d0_value (`FUN_a00ac5a4`) | Clear bit 7 of DP receiver register 0x223 and load registers 0x3D0..0x3D2. |
| 0x2C | ipc_api_set_dp_rx_reg44_bits, ipc_set_dp_rx_reg44_bits | dp_set_reg44_high_bits (`FUN_a00ae254`) | Write DP receiver registers 0x44 / 0x40 bits from a value. |
| 0x2D | - | dp_set_port_setting_116 (`FUN_a00afd3c`) | Store DP receiver option byte +0x116 and reprogram the port. |
| 0x2E | input_set_port_link_tail_bytes, ipc_set_dp_rx_lane_options | dp_set_lane_option_bit (`FUN_a00857d0`), sys_get_chip_revision (`FUN_a008d800`), dp_set_port_enable_bits (`FUN_a0083f04`), dp_apply_port_link_bytes (`FUN_a00ae3a0`) | Store three DP receiver option bytes, set the lane option bit and port enable bits. |
| 0x2F | ipc_set_dp_mst_logical_number, startup_init_input_ports | dp_mst_set_option_word (`FUN_a00d66b0`) | Store the MST option value received from the main processor. |
| 0x30 | ipc_set_dp_rx_port_flag | (inline) | Set flag +0x128 of DP receiver port record 0/1. |
| 0x31 | ipc_is_dp_rx_condition_pending | dp_is_port_ready_for_service (`FUN_a00ad3e0`), dp_pulse_hpd_block (`FUN_a00acff4`) | Reply 1 (and run a short register pulse) when either DP receiver port reports a pending condition. |
| 0x32 | - | (inline) | Store byte +0x129 of DP receiver port record 0/1. |
| 0x33 | - | dp_set_dsc_4_slices_option (`FUN_a00b14dc`), dp_program_port (`FUN_a00abff0`) | Store the 'DSC 3440 4 slices' option of a DP receiver and reprogram the port registers. |
| 0x40 | ipc_set_hdmi_tx_request_bytes | hdmi_tx_apply_request_regs (`FUN_a0094594`) | Store four HDMI TX request bytes (record 0xA807A8FC) and write two of them to the HDMI transmitter. |
| 0x41 | - | hdmi_tx_mark_request_pending (`FUN_a00918ec`) | Set one HDMI TX request flag and mark the request pending. |
| 0x42 | ipc_set_hdmi_tx_request | hdmi_tx_mark_request_pending (`FUN_a00918ec`) | Store a full HDMI TX request (source, clock, format bits) and mark it pending. |
| 0x43 | ipc_clear_hdmi_tx_request_bit14 | hdmi_tx_mark_request_pending (`FUN_a00918ec`) | Clear bit 14 of one HDMI TX request record and mark the request pending. |
| 0x44 | - | hdmi_tx_mark_request_pending (`FUN_a00918ec`) | Store one HDMI TX request field and mark the request pending. |
| 0x45 | ipc_get_hdmi_tx_registers | hdmi_tx_reg_read8 (`FUN_a00a7fd8`) | Reply eight registers (0x3A..0x3D, 0x60..0x63) of HDMI TX port 0/1. |
| 0x46 | - | hdmi_tx_get_status_bit31 (`FUN_a0095ef8`) | Reply an HDMI TX channel status bit (word 1 bit 31). |
| 0x47 | ipc_set_hdmi_tx_reg0d_bit2 | hdmi_tx_set_reg0d_bit2 (`FUN_a0094308`) | Set or clear HDMI TX register 0x0D bit 2. |
| 0x50 | ipc_set_dp_tx_timing | lib_memcpy (`FUN_a00b15d8`), dp_tx_set_video_timing (`FUN_a0087ec8`) | Store video timing for DP transmitter group and program it (0x50..0x53 = four variants). |
| 0x51 | - | lib_memcpy (`FUN_a00b15d8`), dp_tx_set_video_timing (`FUN_a0087ec8`) | As 0x50 (another part of the timing record). |
| 0x52 | - | lib_memcpy (`FUN_a00b15d8`), dp_tx_set_video_timing (`FUN_a0087ec8`) | As 0x50 (another part of the timing record). |
| 0x53 | - | lib_memcpy (`FUN_a00b15d8`), dp_tx_set_video_timing (`FUN_a0087ec8`) | As 0x50 (another part of the timing record). |
| 0x54 | - | (inline) | Store one flag (bit 30) of a DP transmitter record (0xA807A928). |
| 0x55 | sys_output_record_set_flag31 | dp_tx_set_reg70_bit4 (`FUN_a0089758`) | Switch a DP transmitter output function on or off (register 0x70 bit 4). |
| 0x56 | sys_output_record1_add_flags_2001, sys_output_record_add_flags | dp_tx_post_action_flags (`FUN_a0088f90`) | Set request bits for one DP transmitter. |
| 0x57 | - | dp_tx_get_reg70_bit4 (`FUN_a0088f28`) | Reply bit 4 of DP transmitter register 0x70. |
| 0x59 | ipc_set_dp_tx_drive_levels | dp_tx_set_drive_level_base (`FUN_a00ab548`) | Store the base swing and pre-emphasis values of the four lanes of one DP output. |
| 0x5A | - | dp_tx_write_reg57_latched (`FUN_a008983c`) | Write a 16-bit value to DP transmitter register 0x57 and latch it. |
| 0x5B | - | dp_tx_set_reg70_bit5 (`FUN_a0087d50`) | Set DP transmitter register 0x70 bit 5. |
| 0x5C | ipc_is_dp_tx_link_active | dp_tx_is_link_active (`FUN_a0088ea0`) | Reply whether a DP transmitter link is active. |
| 0x5D | ipc_set_hdcp_tx_dp_bypass | hdcp_tx_dp_set_bypass (`FUN_a00c68f8`) | Set or clear bit 6 of the DisplayPort protection control register and print it. |
| 0x5E | - | dp_tx_set_ctl_reg9_bit3 (`FUN_a00aa45c`), dp_tx_set_ctl_reg8_bits67 (`FUN_a00aa49c`), dp_tx_set_max_link_rate (`FUN_a0085830`), dp_tx_set_max_lane_count (`FUN_a0085888`), dp_tx_set_link_option (`FUN_a00858cc`) | Set the DP transmitter link limits (max link rate, lane count, options). |
| 0x5F | ipc_set_dp_tx_reg11_mode | dp_tx_set_reg11_mode (`FUN_a0088ee0`) | Set the DP transmitter register 0x11 mode. |
| 0x60 | MailBoxSub_SetDPTXBrilliantMode | dp_tx_request_pacing_update (`FUN_a0089e24`) | Start the pacing update of one DP output (0..4). |
| 0x63 | ipc_set_dp_tx_reg7d_bit4 | dp_tx_set_fastmute_pattern (`FUN_a0089e54`) | Set or clear DP transmitter register 0x7D bit 4. |
| 0x70 | ipc_set_status_byte_88dd | (inline) | Store a byte in 0xA80788DD. |
| 0x71 | ipc_get_input_timing | input_read_port_timing (`FUN_a0070434`) | Reply the timing of one input port. |
| 0x72 | ipc_power_down_for_saving | dp_tx_set_sink_power (`FUN_a00865b8`), irq_set_mask_preset (`FUN_a00b1fe0`), input_power_off_receivers_mode1 (`FUN_a006d204`), ipc_publish_status_flags (`FUN_a006fedc`) | Power down (receivers mode 1), report the status flags, then stop in an endless loop. |
| 0x73 | ipc_power_down | dp_tx_set_sink_power (`FUN_a00865b8`), irq_set_mask_preset (`FUN_a00b1fe0`), input_power_off_receivers_mode0 (`FUN_a006d0fc`), ipc_publish_status_flags (`FUN_a006fedc`) | Power down (receivers mode 0, prints '_SetLeonSPowerDown'), report, then stop in an endless loop. |
| 0x74 | ipc_send_dsc_dec_command | (inline) | Store a byte in 0xA8079228 and set the request flag 0xA8078748. |
| 0x75 | ipc_set_edp_hpd_enable | dp_tx_mode_requested_1 (`FUN_a006ffb4`), dp_tx_mode_requested_2 (`FUN_a006ffc4`), dp_tx_mode_requested_3 (`FUN_a006ffd4`), dp_tx_mode_requested_4 (`FUN_a006ffe4`), dp_tx_force_hpd_check (`FUN_a0088fd4`) | Store the eDP HPD enable byte; with 0, give each eDP output 1..4 whose mode update was requested a forced HPD check. |
| 0x76 | ipc_api_set_hdr_peak_luminance, ipc_set_hdr_peak_luminance | hdr_set_peak_luminance (`FUN_a00d3eb0`) | Store the panel's peak luminance, limited to 10000 (1000 when 0 is given). |
| 0x77 | ipc_select_hdr_source | hdr_select_source (`FUN_a00d25f4`), input_decode_port_code (`FUN_a006d5a8`) | Pass a decoded port code to the third program part. |
| 0x78 | ipc_set_hdr_source_enable | hdr_set_source_disable_bit (`FUN_a00d2618`), input_decode_port_code (`FUN_a006d5a8`) | As 0x77, with a second byte. |
| 0x79 | - | hdr_get_status_code (`FUN_a00d3efc`) | Return the HDR status code that is reported to the main processor. |
| 0x7A | ipc_api_set_hdr_enable, ipc_set_hdr_enable | hdr_set_enable (`FUN_a00d3f30`) | Switch the HDR curve service on or off. |
| 0x7B | ipc_request_hdr_reload | hdr_request_reload (`FUN_a00d3f54`) | Mark the HDR settings as changed and request a reload of the curve table. |
| 0x7C | ipc_get_dp_rx_clock_value | dp_read_reg3d0_value (`FUN_a00ac620`) | Reply the 24-bit value of DP receiver registers 0x3D0..0x3D2 (input 4..8). |
| 0x7D | ipc_set_command_flags | input_set_command_flags (`FUN_a006fff4`) | Set the command flags. |
| 0x7E | ipc_set_port_option_mask | input_set_port_option_mask (`FUN_a0070000`) | Set the port option mask. |
| 0x7F | ipc_apply_port_enable_mask | input_apply_port_enable_mask (`FUN_a006d46c`) | Apply the port enable mask. |
| 0x80 | input_api_power_on_dp_port, ipc_api_set_dp_rx_setting_11f, ipc_set_dp_rx_setting_11f | dp_init_port (`FUN_a00b1028`) | Store DP receiver byte +0x11F and set the port up again. |
| 0x81 | ipc_ack_port_change_bits | (inline) | Clear the given bits in byte 2 of mailbox slot 0 word 3 (acknowledge port change bits). |
| 0x82 | - | (inline) | Test: reply with the bytes 0..27. |
| 0x83 | ipc_get_hdmi_port_status | hdmi_get_reg6_bit0 (`FUN_a00910d0`), hdmi_rx21_status04_bit17 (`FUN_a00a28a4`), hdmi_rx21_is_frl_mode (`FUN_a00a29b0`) | Reply a status bit of HDMI port 0..3 (sub 0). |
| 0x84 | - | (inline) | Test: reply with the bytes 0..27. |
| 0x85 | - | (inline) | Test: reply with the bytes 0..27. |
| 0x86 | ipc_api_set_dp_rx_reg252_bits, ipc_set_dp_rx_reg252_bits | dp_reg_write8 (`FUN_a00a6c00`) | Write bits 5..7 of DP receiver register 0x252. |
| 0x87 | ipc_ping | dp_tx_option_enabled_stub_copy (`FUN_a008d8d8`) | Reply 1 (constant). |
| 0x88 | ipc_set_hdr_mode_byte | hdr_set_mode_byte (`FUN_a00d3f88`) | Store an HDR mode byte and mark the settings as changed. |
| 0x90 | audio_init_config, ipc_configure_audio | audio_configure (`FUN_a008cba8`) | Audio: store the 3-byte audio configuration and initialise the audio block. |
| 0x91 | audio_mute_outputs, audio_unmute_outputs, ipc_set_audio_mute | audio_set_mute (`FUN_a008a868`) | Audio: mute or unmute the outputs selected in the audio configuration. |
| 0x92 | audio_unit_send_owner_slots, ipc_route_audio_source | audio_route_source (`FUN_a008c9a8`) | Audio: route a source (byte 0) to an output (byte 1) through an audio unit (byte 2), enable (byte 3). |
| 0x93 | audio_unit_send_unit_value, ipc_set_audio_unit_frequency | audio_set_unit_frequency (`FUN_a008b53c`) | Audio: program the frequency word of one audio unit. |
| 0x94 | ipc_set_audio_level | audio_set_input_levels (`FUN_a008aaf8`), audio_set_output_level (`FUN_a008aa18`) | Audio: set a 16-bit level, sub 0 = main output, sub 1 = all receivers (0x8000 neutral). |
| 0x95 | ipc_api_clear_audio_level_steps, ipc_clear_audio_level_steps | audio_clear_level_step (`FUN_a008a9b0`) | Audio: clear the level step registers. |
| 0x96 | - | (inline) | Store a byte in table 0xA80788D0. |
| 0xA0 | ipc_get_input_status_byte | hdmi_rx21_get_cvtem_flag (`FUN_a00a26c4`), dp_get_msa_bit3 (`FUN_a00ad7c8`) | Reply a status byte of input 2..5. |
| 0xA1 | ipc_get_input_setting_byte | hdmi_rx21_get_cvtem_code (`FUN_a00a26a8`) | Reply a setting byte of input 2/3 (8 for DP inputs 4/5). |
| 0xA2 | ipc_reload_hdr_tone_curve | hdr_request_curve_table_reload (`FUN_a0063950`), hdr_init (`FUN_a00d27fc`) | Reload the HDR tone curve table. |
| 0xA3 | ipc_set_hdr_option_byte | hdr_set_option_byte (`FUN_a00d3f70`) | Store an HDR option byte and mark the settings as changed. |
| 0xA4 | ipc_get_hdmi21_status_byte | (inline) | Reply status byte 0xA807D681 (input 2) or 0xA807D731 (input 3). |
| 0xA5 | ipc_configure_dsc_encoder | sys_dsc_enc_configure (`FUN_a00de8ac`) | Fill the encoder's timing record, compute its parameters and program the encoder. |
| 0xA6 | dbg_send_timing_change_notice, ipc_print_timing_change_notice | (inline) | Print 'AT Prepare Timing Change' with three words (debug only). |
| 0xF0 | - | hdmi_phy_write_reg (`FUN_a00a72c0`) | Debug: write a paged register. |
| 0xF1 | - | hdmi_reg_write8 (`FUN_a00a65c4`), hdmi_rx21_reg_write8 (`FUN_a00a69fc`) | Debug: write an HDMI receiver register. |
| 0xF2 | - | hdmi_reg_read8 (`FUN_a00a657c`), hdmi_rx21_reg_read8 (`FUN_a00a69b4`) | Debug: read an HDMI receiver register. |
| 0xF3 | ipc_dbg_get_receiver_block | hdmi_read_infoframe (`FUN_a0090380`) | Debug: reply 28 bytes of a receiver block (selector 0x82/83/84/87). |
| 0xF4 | - | hdmi_tx_reg_write8 (`FUN_a00a8054`) | Debug: write an HDMI TX register. |
| 0xF5 | - | dp_write_port_reg_wrapper (`FUN_a00ac584`) | Debug: write a DP receiver register (forwarder). |
| 0xF6 | - | dp_write_low_reg (`FUN_a00ac550`) | Debug: write a DP receiver register below 0x200. |
| 0xF7 | - | dp_reg_read8 (`FUN_a00a6bb8`) | Debug: read a DP receiver register. |
| 0xF8 | - | dp_tx_reg_read8 (`FUN_a00a78b4`) | Debug: read a DP transmitter register. |
| 0xF9 | - | dp_tx_reg_write8 (`FUN_a00a78fc`) | Debug: write a DP transmitter register. |
| 0xFA | - | osd_request_unzip (`FUN_a006cfac`) | Start an OSD unzip job. |
| 0xFB | - | (inline) | Clear the selected request flags (0xA8078C48, 0xA8078C49, 0xA8078A0A). |
| 0xFD | ipc_check_hdcp_stored_keys | hdcp_tx_check_stored_keys (`FUN_a00c6968`) | Compare a stored 3-byte sum with the sum computed over the first key set or the HDCP 2 data. |
| 0xFE | ipc_set_dsc_encoder_parameters | sys_dsc_enc_set_parameters (`FUN_a00dd398`) | Unpack the compression parameters received from the main processor into the timing record. |
| 0xFF | - | dp_unit_restart (`FUN_a00afdf4`) | Run the DP receiver port set-up for a mode. |
