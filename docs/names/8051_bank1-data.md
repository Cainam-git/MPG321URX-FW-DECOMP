# Data names: 8051 main application (bank 1)

505 entries from `symbols/8051_bank1.data.json`, in address order. The source uses the names through the `#define` lists (see [Function names](../NAMES.md#names-in-the-source)); [Data objects](../DATA.md) describes the principal records. The *basis* column has the same meaning as for the function names.

| Basis | Entries |
|---|---:|
| proven | 24 |
| derived | 418 |
| descriptive | 63 |

## Bit variables

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `sys_shared_bit_param` | `BITS_20_0` | Bit shared by several routines: watch restart request, 4-byte flash addressing at start-up. | descriptive |
| `power_wake_entry_option_flag` | `BITS_20_1` | Bit 5 of the current wake-up table entry for the port signal check; also the ADC rise result bit. | descriptive |
| `flash_extended_addr_flag` | `BITS_20_2` | When set, a flash DMA read first writes address bits 31..24 to the extended address register. | derived |
| `dp_aux_no_request_flag` | `BITS_21_3` | Set when the DP receiver holds no AUX request bytes to answer. | derived |
| `dp_aux_empty_reply_flag` | `BITS_21_4` | Set when an AUX request has no case: the reply is then that many zero bytes. | derived |
| `sys_on_crystal_clock_flag` | `BITS_21_6` | Set when the chip has been switched into power saving or off and the 8051 runs on its crystal. | derived |
| `ddc_rearm_pending_flag` | `BITS_22_0` | Set on DDC/CI slave activity; once all ports have been idle for 1000 ticks the slaves are re-armed. | derived |
| `power_cec_wake_request_flag` | `BITS_22_1` | Set when a CEC power-up request has been received; taken and cleared by the wake check. | derived |
| `dp_aux_answer_mode_flag` | `BITS_22_5` | Set: the 8051 answers DP AUX requests itself; clear: it only watches them for link training. | derived |
| `usb_cc_ch0_mode_on_flag` | `BITS_22_6` | When set, the stored mode of USB-C CC channel 0 is applied; when clear its mode bits are cleared. | derived |
| `usb_cc_ch1_mode_on_flag` | `BITS_22_7` | When set, the stored mode of USB-C CC channel 1 is applied; when clear its mode bits are cleared. | derived |
| `usb_cc_both_lines_low_flag` | `BITS_23_2` | Result bit: both CC line readings are low. | derived |
| `usb_cc_both_lines_high_flag` | `BITS_23_4` | Result bit: both CC line readings are high. | derived |
| `usb_cc_active_line_high_flag` | `BITS_23_5` | Result bit: the CC line of the current plug orientation reads high. | derived |
| `usb_cc_lines_split_flag` | `BITS_23_6` | Result bit: one CC line reads high and the other low. | derived |

## Constant tables in code memory

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `dp_aux_edid` | `DAT_CODE_6af7` | The 256-byte EDID that the 8051 serves on the DP receivers over I2C-over-AUX. | proven |
| `dp_mrx_setup_bytes_default` | `DAT_CODE_6bf7` | Seven bytes copied to XDATA 0xE140 for chip IDs 0x16, 0x17, 0x1E and 0x1F. | descriptive |
| `dp_mrx_setup_bytes_chip1a` | `DAT_CODE_6bfe` | Seven bytes copied to XDATA 0xE140 for chip ID 0x1A. | descriptive |
| `dp_mrx_setup_bytes_chip20` | `DAT_CODE_6c05` | Seven bytes copied to XDATA 0xE140 for chip ID 0x20. | descriptive |
| `dp_aux_dpcd_link_status` | `DAT_CODE_6c0c` | DPCD link status bytes (0x200..0x207) that the 8051 answers for an emulated DP receiver. | derived |
| `dp_aux_dpcd_rx_caps` | `DAT_CODE_6c14` | DPCD receiver capability bytes (0x000..0x00B) answered by the emulated DP receiver. | derived |
| `dp_aux_dpcd_ext_rx_caps` | `DAT_CODE_6c20` | DPCD extended receiver capability bytes (0x2200..0x220F) answered by the emulated DP receiver. | derived |
| `dp_aux_dpcd_0400_bytes` | `DAT_CODE_6c30` | Four bytes returned for native AUX reads of DPCD addresses 0x400..0x403. | derived |
| `edid_slave_ctrl_reg_ptrs` | `DAT_CODE_b114` | Per EDID port (7): pointer to the EDID slave control register (0xF01C, 0xF01E ...). | derived |
| `edid_slave_addr_reg_ptrs` | `DAT_CODE_b129` | Per EDID port (7): pointer to the EDID slave address register (0xF01D, 0xF01F ...). | derived |
| `edid_port_reg_ptr_table` | `DAT_CODE_b13e` | 28 pointers to EDID slave port registers, picked by index to test bits or write 7. | descriptive |
| `edid_init_zero_reg_ptrs` | `DAT_CODE_b153` | Per port (7): pointer to the EDID slave register that the set-up clears. | descriptive |
| `edid_init_value_reg_ptrs` | `DAT_CODE_b168` | Per port (7): pointer to the EDID slave register that gets the value parameter. | descriptive |
| `edid_init_extra_reg_ptrs` | `DAT_CODE_b17d` | Per port (7): pointer to the EDID slave register that gets XDATA 0xA6DE. | descriptive |
| `sys_pll_clock_list` | `DAT_CODE_dc7d` | Six clock values (12..96) searched for 0x60 to pick the PLL setting. | descriptive |
| `sys_pll_clock_list_chip20` | `DAT_CODE_dc83` | Six clock values (12..68) searched for 0x30 to pick the PLL setting on chip ID 0x20. | descriptive |
| `sys_clock_factor_table` | `DAT_CODE_dc89` | Factor per clock select value (1, 1, 2, 2, 4, 5, 8, ...) used to scale timings. | descriptive |
| `i2c_sw_bit_masks` | `DAT_CODE_ded4` | Bit masks 0x80, 0x40 .. 0x01 for sending a byte on the software I2C bus, first bit highest. | derived |

## Hardware registers and chip memory

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `startup_share_block` | `DAT_EXTMEM_3000` | Share block that the boot loader fills for the application (0x6A bytes). | proven |
| `startup_share_flash_chip_index` | `DAT_EXTMEM_3066` | Flash chip index from the boot loader (share block kind 5); the high nibble is the chip group. | derived |
| `hdcp_dptx_key_block` | `DAT_EXTMEM_3e00` | The 282-byte HDCP data block copied into the DP transmitter key port. | derived |
| `sys_mirror_request_flag` | `DAT_EXTMEM_3f20` | When 1, a status byte is copied into the 63-byte mirror buffer. | descriptive |
| `sys_mirror_done_flag` | `DAT_EXTMEM_3f21` | Set to 1 when the mirror buffer was filled, 0 when no request was set. | descriptive |
| `sys_mirror_buffer` | `DAT_EXTMEM_3f22` | 63 bytes filled with one status byte on request. | descriptive |
| `reg_dp_mrx0_window` | `DAT_EXTMEM_4d00` | Register window of DisplayPort receiver 0. | derived |
| `reg_dp_mrx1_window` | `DAT_EXTMEM_4e00` | Register window of DisplayPort receiver 1. | derived |
| `reg_port_page_window` | `DAT_EXTMEM_6100` | Paged register window of the input ports, 256 bytes per page. | derived |
| `reg_paged_block0_window` | `DAT_EXTMEM_6500` | Register window of paged block 0. | derived |
| `reg_paged_block1_window` | `DAT_EXTMEM_6600` | Register window of paged block 1. | derived |
| `reg_wake_block_window` | `DAT_EXTMEM_9a00` | Register window of the wake detection block used in standby. | derived |
| `reg_dp_mrx_aux_irq_enable` | `DAT_EXTMEM_cc87` | Interrupt enable bits (3..4) of the AUX requests of both DP receivers. | derived |
| `reg_ahb_bridge_addr` | `DAT_EXTMEM_cd80` | AHB bridge address register, byte 0 (address written low byte first). | proven |
| `reg_ahb_bridge_addr_byte1` | `DAT_EXTMEM_cd81` | AHB bridge address register, byte 1. | proven |
| `reg_ahb_bridge_addr_byte2` | `DAT_EXTMEM_cd82` | AHB bridge address register, byte 2. | proven |
| `reg_ahb_bridge_addr_byte3` | `DAT_EXTMEM_cd83` | AHB bridge address register, byte 3. | proven |
| `reg_ahb_bridge_wdata` | `DAT_EXTMEM_cd84` | AHB bridge write data register, byte 0 (low byte first). | proven |
| `reg_ahb_bridge_wdata_byte1` | `DAT_EXTMEM_cd85` | AHB bridge write data register, byte 1. | proven |
| `reg_ahb_bridge_wdata_byte2` | `DAT_EXTMEM_cd86` | AHB bridge write data register, byte 2. | proven |
| `reg_ahb_bridge_wdata_byte3` | `DAT_EXTMEM_cd87` | AHB bridge write data register, byte 3. | proven |
| `reg_ahb_bridge_rdata` | `DAT_EXTMEM_cd88` | AHB bridge read data register, byte 0 (low byte first). | proven |
| `reg_ahb_bridge_rdata_byte1` | `DAT_EXTMEM_cd89` | AHB bridge read data register, byte 1. | proven |
| `reg_ahb_bridge_rdata_byte2` | `DAT_EXTMEM_cd8a` | AHB bridge read data register, byte 2. | proven |
| `reg_ahb_bridge_rdata_byte3` | `DAT_EXTMEM_cd8b` | AHB bridge read data register, byte 3. | proven |
| `reg_ahb_bridge_control` | `DAT_EXTMEM_cd8c` | AHB bridge control: bit 0 = ready, 0x40 starts a read. | proven |
| `reg_paged_select` | `DAT_EXTMEM_d50b` | Page block select of the paged register access (0x85 block 0, 0x86 block 1). | derived |
| `reg_paged_index` | `DAT_EXTMEM_d50c` | Register number of the paged register access. | derived |
| `reg_paged_data` | `DAT_EXTMEM_d50d` | Data byte of the paged register access. | derived |
| `reg_chip_id` | `DAT_EXTMEM_d511` | Chip variant ID (0x16, 0x17, 0x1A, 0x1E, 0x1F, 0x20) that selects the set-up paths. | derived |
| `reg_hdmi_cec_port_select` | `DAT_EXTMEM_d533` | Two-bit field per port (0..3) set to 01 when CEC is set up for that port. | descriptive |
| `reg_hdcp_dptx_key_ctrl` | `DAT_EXTMEM_d5e0` | Control of the DP transmitter HDCP key port; 0x22 while the key block is written. | derived |
| `reg_hdcp_dptx_key_data` | `DAT_EXTMEM_d5e3` | Data port of the DP transmitter HDCP key port; takes the 282 key bytes in turn. | derived |
| `reg_hdmi_cec_clock_divider` | `DAT_EXTMEM_d801` | CEC controller clock divider (0x78 shifted by the clock select). | derived |
| `reg_hdmi_cec_status` | `DAT_EXTMEM_d80d` | CEC controller status and command register; status bits are cleared by writing them back. | derived |
| `reg_hdmi_cec_rx_count` | `DAT_EXTMEM_d80f` | CEC receive register; zero means no message was received. | descriptive |
| `reg_hdmi_cec_tx_length` | `DAT_EXTMEM_d810` | Byte count of the CEC message to send. | derived |
| `reg_hdmi_cec_tx_dest` | `DAT_EXTMEM_d820` | Destination logical address of the CEC message to send. | derived |
| `reg_hdmi_cec_tx_data` | `DAT_EXTMEM_d821` | Bytes of the CEC message to send (opcode first). | derived |
| `reg_hdmi_cec_rx_header` | `DAT_EXTMEM_d831` | Header byte of the received CEC message: initiator bits 7..4, destination bits 3..0. | derived |
| `reg_hdmi_cec_rx_data` | `DAT_EXTMEM_d832` | The 16 data bytes of the received CEC message (opcode first). | derived |
| `reg_dp_aux_window` | `DAT_EXTMEM_dc00` | Register window of the DP AUX units; the reply bytes go to 0xDCDD / 0xDCCD through it. | descriptive |
| `reg_clock_timing_factors` | `DAT_EXTMEM_dcb1` | Two registers 0xDCB1 / 0xDCB2: clock factor * 9 and * 15 on the PLL clock, 9 and 15 on the crystal. | descriptive |
| `reg_dp_aux_rx_fifo_port1` | `DAT_EXTMEM_dcc8` | AUX request FIFO of DP receiver 1: byte 0 bit 0 = data waiting, byte 1 = next request byte. | derived |
| `reg_dp_aux_ctrl_port1` | `DAT_EXTMEM_dcca` | AUX control register of DP receiver 1, pulsed 0 then 1 after a request. | descriptive |
| `reg_dp_aux_reply_len_port1` | `DAT_EXTMEM_dccb` | Reply byte count of DP receiver 1 (request length + 1, or 0). | derived |
| `reg_dp_aux_rx_ack_port1` | `DAT_EXTMEM_dccc` | Bit 0 is set after a request of DP receiver 1 was read and clears when done. | descriptive |
| `reg_dp_aux_mode_port1` | `DAT_EXTMEM_dcce` | AUX mode register of DP receiver 1; bit 3 marks a waiting request. | descriptive |
| `reg_dp_aux_request_ctrl_port1` | `DAT_EXTMEM_dccf` | AUX control register of DisplayPort port 1: bit 0 enables the AUX request service; bits 4..5 are set by USB-C. | derived |
| `reg_dp_aux_rx_fifo_port0` | `DAT_EXTMEM_dcd8` | AUX request FIFO of DP receiver 0: byte 0 bit 0 = data waiting, byte 1 = next request byte. | derived |
| `reg_dp_aux_ctrl_port0` | `DAT_EXTMEM_dcda` | AUX control register of DP receiver 0, pulsed 0 then 1 after a request. | descriptive |
| `reg_dp_aux_reply_len_port0` | `DAT_EXTMEM_dcdb` | Reply byte count of DP receiver 0 (request length + 1, or 0). | derived |
| `reg_dp_aux_rx_ack_port0` | `DAT_EXTMEM_dcdc` | Bit 0 is set after a request of DP receiver 0 was read and clears when done. | descriptive |
| `reg_dp_aux_mode_port0` | `DAT_EXTMEM_dcde` | AUX mode register of DP receiver 0; bit 3 marks a waiting request. | descriptive |
| `reg_dp_aux_request_ctrl_port0` | `DAT_EXTMEM_dcdf` | AUX control register of DisplayPort port 0: bit 0 enables the AUX request service; bits 4..5 are set by USB-C. | derived |
| `reg_gpio_port1` | `DAT_EXTMEM_f000` | Output register of GPIO port 1. | derived |
| `reg_gpio_port2` | `DAT_EXTMEM_f001` | Output register of GPIO port 2. | derived |
| `reg_gpio_port3` | `DAT_EXTMEM_f002` | Output register of GPIO port 3. | derived |
| `reg_gpio_port4` | `DAT_EXTMEM_f003` | Output register of GPIO port 4. | derived |
| `reg_gpio_port5` | `DAT_EXTMEM_f004` | Output register of GPIO port 5. | derived |
| `reg_gpio_port1_partner` | `DAT_EXTMEM_f005` | Partner register of GPIO port 1, ORed into each output update. | derived |
| `reg_gpio_port2_partner` | `DAT_EXTMEM_f006` | Partner register of GPIO port 2, ORed into each output update. | derived |
| `reg_gpio_port3_partner` | `DAT_EXTMEM_f007` | Partner register of GPIO port 3, ORed into each output update. | derived |
| `reg_gpio_port4_partner` | `DAT_EXTMEM_f008` | Partner register of GPIO port 4, ORed into each output update. | derived |
| `reg_gpio_port5_partner` | `DAT_EXTMEM_f009` | Partner register of GPIO port 5, ORed into each output update. | derived |
| `reg_gpio_port6` | `DAT_EXTMEM_f010` | Output register of GPIO port 6. | derived |
| `reg_gpio_port6_partner` | `DAT_EXTMEM_f011` | Partner register of GPIO port 6, ORed into each output update. | derived |
| `reg_gpio_port7` | `DAT_EXTMEM_f012` | Output register of GPIO port 7. | derived |
| `reg_gpio_port7_partner` | `DAT_EXTMEM_f013` | Partner register of GPIO port 7, ORed into each output update. | derived |
| `reg_i2c7_ctrl` | `DAT_EXTMEM_f014` | Control register of I2C unit 7; bit 6 arms the DDC/CI slave. | derived |
| `reg_i2c7_status` | `DAT_EXTMEM_f015` | Status of I2C unit 7: bit 7 = read transfer, bit 0 = transfer finished. | derived |
| `reg_i2c7_mode` | `DAT_EXTMEM_f016` | Mode register of I2C unit 7 (0xF8 on slave enable, 0xA0 / 0xC0 per transfer). | derived |
| `reg_i2c7_events` | `DAT_EXTMEM_f017` | Event bits of I2C unit 7: 7 addressed, 6 byte to send, 5 byte received, 4 and 3 others. | derived |
| `reg_i2c7_event_ack` | `DAT_EXTMEM_f018` | Event acknowledge register of I2C unit 7 (write the event bit back). | derived |
| `reg_i2c7_tx_data` | `DAT_EXTMEM_f019` | Transmit data register of I2C unit 7. | derived |
| `reg_i2c7_rx_data` | `DAT_EXTMEM_f01a` | Receive data register of I2C unit 7. | derived |
| `reg_i2c7_address` | `DAT_EXTMEM_f01b` | DDC/CI slave address of I2C unit 7 (bits 7..1) and its slave enable bit 0. | derived |
| `reg_edid0_ctrl` | `DAT_EXTMEM_f01c` | EDID slave control of port 0: bit 7 on, bit 6 control bit, size mode bits; bit 0 = accessed. | derived |
| `reg_edid0_address` | `DAT_EXTMEM_f01d` | EDID slave address register of port 0 (0xA0 with bits 3..1 from command 0x01). | derived |
| `reg_edid1_ctrl` | `DAT_EXTMEM_f01e` | EDID slave control of port 1: bit 7 on, bit 6 control bit, size mode bits; bit 0 = accessed. | derived |
| `reg_edid1_address` | `DAT_EXTMEM_f01f` | EDID slave address register of port 1 (0xA0 with bits 3..1 from command 0x01). | derived |
| `reg_irq_source_status` | `DAT_EXTMEM_f020` | Pending sources of the external interrupts: bit N = I2C unit N (0..6), bit 7 = capture (IR). | derived |
| `reg_capture_irq_flags` | `DAT_EXTMEM_f021` | Capture interrupt flags (remote-control input); cleared by writing the enabled bits back. | derived |
| `reg_capture_irq_enable` | `DAT_EXTMEM_f022` | Capture interrupt enable register written with the source mask (commands 0x09 / 0x0A). | descriptive |
| `reg_ir_capture_low` | `DAT_EXTMEM_f027` | Low byte of the captured infrared pulse length. | derived |
| `reg_ir_capture_high` | `DAT_EXTMEM_f028` | High byte of the captured infrared pulse length. | derived |
| `reg_uart_irq_enable` | `DAT_EXTMEM_f02c` | Serial interrupt enable bits: bit 6 port 2, bit 7 port 3. | derived |
| `reg_uart_rx_irq_status` | `DAT_EXTMEM_f02e` | Receive interrupt status: bit 6 serial port 2, bit 7 serial port 3. | derived |
| `reg_uart4_rx_irq_status` | `DAT_EXTMEM_f031` | Receive interrupt status; bit 6 = serial port 4. | derived |
| `reg_uart3_line_ctrl` | `DAT_EXTMEM_f032` | Line control of serial port 3: bit 7 set on open, line format bits from command 0x05. | derived |
| `reg_uart3_divisor_high` | `DAT_EXTMEM_f033` | High byte of the serial port 3 baud divisor (12 MHz / baud - 1). | derived |
| `reg_uart3_divisor_low` | `DAT_EXTMEM_f034` | Low byte of the serial port 3 baud divisor. | derived |
| `reg_uart3_config` | `DAT_EXTMEM_f035` | Configuration register of serial port 3, set to 0xEA on open. | descriptive |
| `reg_uart3_status` | `DAT_EXTMEM_f036` | Status of serial port 3: bit 0 = receive empty, bit 4 = acknowledged by writing it back. | derived |
| `reg_uart3_tx_data` | `DAT_EXTMEM_f037` | Transmit data register of serial port 3. | derived |
| `reg_uart3_rx_data` | `DAT_EXTMEM_f038` | Receive data register of serial port 3. | derived |
| `reg_i2c0_ctrl` | `DAT_EXTMEM_f039` | Control register of I2C unit 0; bit 6 arms the DDC/CI slave. | derived |
| `reg_i2c0_status` | `DAT_EXTMEM_f03a` | Status of I2C unit 0: bit 7 = read transfer, bit 0 = transfer finished. | derived |
| `reg_i2c0_mode` | `DAT_EXTMEM_f03b` | Mode register of I2C unit 0 (0xF8 on slave enable, 0xA0 / 0xC0 per transfer). | derived |
| `reg_i2c0_events` | `DAT_EXTMEM_f03c` | Event bits of I2C unit 0: 7 addressed, 6 byte to send, 5 byte received, 4 and 3 others. | derived |
| `reg_i2c0_event_ack` | `DAT_EXTMEM_f03d` | Event acknowledge register of I2C unit 0 (write the event bit back). | derived |
| `reg_i2c0_tx_data` | `DAT_EXTMEM_f03e` | Transmit data register of I2C unit 0. | derived |
| `reg_i2c0_rx_data` | `DAT_EXTMEM_f03f` | Receive data register of I2C unit 0. | derived |
| `reg_i2c0_address` | `DAT_EXTMEM_f040` | DDC/CI slave address of I2C unit 0 (bits 7..1) and its slave enable bit 0. | derived |
| `reg_i2c1_ctrl` | `DAT_EXTMEM_f041` | Control register of I2C unit 1; bit 6 arms the DDC/CI slave. | derived |
| `reg_i2c1_status` | `DAT_EXTMEM_f042` | Status of I2C unit 1: bit 7 = read transfer, bit 0 = transfer finished. | derived |
| `reg_i2c1_mode` | `DAT_EXTMEM_f043` | Mode register of I2C unit 1 (0xF8 on slave enable, 0xA0 / 0xC0 per transfer). | derived |
| `reg_i2c1_events` | `DAT_EXTMEM_f044` | Event bits of I2C unit 1: 7 addressed, 6 byte to send, 5 byte received, 4 and 3 others. | derived |
| `reg_i2c1_event_ack` | `DAT_EXTMEM_f045` | Event acknowledge register of I2C unit 1 (write the event bit back). | derived |
| `reg_i2c1_tx_data` | `DAT_EXTMEM_f046` | Transmit data register of I2C unit 1. | derived |
| `reg_i2c1_rx_data` | `DAT_EXTMEM_f047` | Receive data register of I2C unit 1. | derived |
| `reg_i2c1_address` | `DAT_EXTMEM_f048` | DDC/CI slave address of I2C unit 1 (bits 7..1) and its slave enable bit 0. | derived |
| `reg_flash_read_mode` | `DAT_EXTMEM_f050` | Flash mode bits: bit 2 selects quad read (0x6B), bit 5 dual read (0x3B) at start-up. | derived |
| `reg_uart1_line_ctrl` | `DAT_EXTMEM_f054` | Line control of serial port 1: line format in bits 3..0; uart_open_ports sets bit 7 when it opens port 2. | derived |
| `reg_uart4_line_ctrl` | `DAT_EXTMEM_f06e` | Line control of serial port 4: bit 7 set on open, line format bits from command 0x05. | derived |
| `reg_uart4_divisor_high` | `DAT_EXTMEM_f06f` | High byte of the serial port 4 baud divisor (12 MHz / baud - 1). | derived |
| `reg_uart4_divisor_low` | `DAT_EXTMEM_f070` | Low byte of the serial port 4 baud divisor. | derived |
| `reg_uart4_config` | `DAT_EXTMEM_f071` | Configuration register of serial port 4, set to 0xEA on open. | descriptive |
| `reg_uart4_status` | `DAT_EXTMEM_f072` | Status of serial port 4: bit 0 = receive empty, bit 4 = acknowledged by writing it back. | derived |
| `reg_uart4_tx_data` | `DAT_EXTMEM_f073` | Transmit data register of serial port 4. | derived |
| `reg_uart4_rx_data` | `DAT_EXTMEM_f074` | Receive data register of serial port 4. | derived |
| `reg_edid6_ctrl` | `DAT_EXTMEM_f076` | EDID slave control of port 6: bit 7 on, bit 6 control bit, size mode bits; bit 0 = accessed. | derived |
| `reg_edid6_address` | `DAT_EXTMEM_f077` | EDID slave address register of port 6 (0xA0 with bits 3..1 from command 0x01). | derived |
| `reg_edid2_ctrl` | `DAT_EXTMEM_f085` | EDID slave control of port 2: bit 7 on, bit 6 control bit, size mode bits; bit 0 = accessed. | derived |
| `reg_edid2_address` | `DAT_EXTMEM_f086` | EDID slave address register of port 2 (0xA0 with bits 3..1 from command 0x01). | derived |
| `reg_edid3_ctrl` | `DAT_EXTMEM_f087` | EDID slave control of port 3: bit 7 on, bit 6 control bit, size mode bits; bit 0 = accessed. | derived |
| `reg_edid3_address` | `DAT_EXTMEM_f088` | EDID slave address register of port 3 (0xA0 with bits 3..1 from command 0x01). | derived |
| `reg_i2c2_ctrl` | `DAT_EXTMEM_f089` | Control register of I2C unit 2; bit 6 arms the DDC/CI slave. | derived |
| `reg_i2c2_status` | `DAT_EXTMEM_f08a` | Status of I2C unit 2: bit 7 = read transfer, bit 0 = transfer finished. | derived |
| `reg_i2c2_mode` | `DAT_EXTMEM_f08b` | Mode register of I2C unit 2 (0xF8 on slave enable, 0xA0 / 0xC0 per transfer). | derived |
| `reg_i2c2_events` | `DAT_EXTMEM_f08c` | Event bits of I2C unit 2: 7 addressed, 6 byte to send, 5 byte received, 4 and 3 others. | derived |
| `reg_i2c2_event_ack` | `DAT_EXTMEM_f08d` | Event acknowledge register of I2C unit 2 (write the event bit back). | derived |
| `reg_i2c2_tx_data` | `DAT_EXTMEM_f08e` | Transmit data register of I2C unit 2. | derived |
| `reg_i2c2_rx_data` | `DAT_EXTMEM_f08f` | Receive data register of I2C unit 2. | derived |
| `reg_i2c2_address` | `DAT_EXTMEM_f090` | DDC/CI slave address of I2C unit 2 (bits 7..1) and its slave enable bit 0. | derived |
| `reg_i2c3_ctrl` | `DAT_EXTMEM_f091` | Control register of I2C unit 3; bit 6 arms the DDC/CI slave. | derived |
| `reg_i2c3_status` | `DAT_EXTMEM_f092` | Status of I2C unit 3: bit 7 = read transfer, bit 0 = transfer finished. | derived |
| `reg_i2c3_mode` | `DAT_EXTMEM_f093` | Mode register of I2C unit 3 (0xF8 on slave enable, 0xA0 / 0xC0 per transfer). | derived |
| `reg_i2c3_events` | `DAT_EXTMEM_f094` | Event bits of I2C unit 3: 7 addressed, 6 byte to send, 5 byte received, 4 and 3 others. | derived |
| `reg_i2c3_event_ack` | `DAT_EXTMEM_f095` | Event acknowledge register of I2C unit 3 (write the event bit back). | derived |
| `reg_i2c3_tx_data` | `DAT_EXTMEM_f096` | Transmit data register of I2C unit 3. | derived |
| `reg_i2c3_rx_data` | `DAT_EXTMEM_f097` | Receive data register of I2C unit 3. | derived |
| `reg_i2c3_address` | `DAT_EXTMEM_f098` | DDC/CI slave address of I2C unit 3 (bits 7..1) and its slave enable bit 0. | derived |
| `reg_edid4_ctrl` | `DAT_EXTMEM_f099` | EDID slave control of port 4: bit 7 on, bit 6 control bit, size mode bits; bit 0 = accessed. | derived |
| `reg_edid4_address` | `DAT_EXTMEM_f09a` | EDID slave address register of port 4 (0xA0 with bits 3..1 from command 0x01). | derived |
| `reg_i2c4_ctrl` | `DAT_EXTMEM_f09b` | Control register of I2C unit 4; bit 6 arms the DDC/CI slave. | derived |
| `reg_i2c4_status` | `DAT_EXTMEM_f09c` | Status of I2C unit 4: bit 7 = read transfer, bit 0 = transfer finished. | derived |
| `reg_i2c4_mode` | `DAT_EXTMEM_f09d` | Mode register of I2C unit 4 (0xF8 on slave enable, 0xA0 / 0xC0 per transfer). | derived |
| `reg_i2c4_events` | `DAT_EXTMEM_f09e` | Event bits of I2C unit 4: 7 addressed, 6 byte to send, 5 byte received, 4 and 3 others. | derived |
| `reg_i2c4_event_ack` | `DAT_EXTMEM_f09f` | Event acknowledge register of I2C unit 4 (write the event bit back). | derived |
| `reg_i2c4_tx_data` | `DAT_EXTMEM_f0a0` | Transmit data register of I2C unit 4. | derived |
| `reg_i2c4_rx_data` | `DAT_EXTMEM_f0a1` | Receive data register of I2C unit 4. | derived |
| `reg_i2c4_address` | `DAT_EXTMEM_f0a2` | DDC/CI slave address of I2C unit 4 (bits 7..1) and its slave enable bit 0. | derived |
| `reg_edid5_ctrl` | `DAT_EXTMEM_f0a3` | EDID slave control of port 5: bit 7 on, bit 6 control bit, size mode bits; bit 0 = accessed. | derived |
| `reg_edid5_address` | `DAT_EXTMEM_f0a4` | EDID slave address register of port 5 (0xA0 with bits 3..1 from command 0x01). | derived |
| `reg_i2c7_irq_status` | `DAT_EXTMEM_f0a7` | Bit 7 marks a pending event of I2C unit 7. | descriptive |
| `reg_i2c5_ctrl` | `DAT_EXTMEM_f0b8` | Control register of I2C unit 5; bit 6 arms the DDC/CI slave. | derived |
| `reg_i2c5_status` | `DAT_EXTMEM_f0b9` | Status of I2C unit 5: bit 7 = read transfer, bit 0 = transfer finished. | derived |
| `reg_i2c5_mode` | `DAT_EXTMEM_f0ba` | Mode register of I2C unit 5 (0xF8 on slave enable, 0xA0 / 0xC0 per transfer). | derived |
| `reg_i2c5_events` | `DAT_EXTMEM_f0bb` | Event bits of I2C unit 5: 7 addressed, 6 byte to send, 5 byte received, 4 and 3 others. | derived |
| `reg_i2c5_event_ack` | `DAT_EXTMEM_f0bc` | Event acknowledge register of I2C unit 5 (write the event bit back). | derived |
| `reg_i2c5_tx_data` | `DAT_EXTMEM_f0bd` | Transmit data register of I2C unit 5. | derived |
| `reg_i2c5_rx_data` | `DAT_EXTMEM_f0be` | Receive data register of I2C unit 5. | derived |
| `reg_i2c5_address` | `DAT_EXTMEM_f0bf` | DDC/CI slave address of I2C unit 5 (bits 7..1) and its slave enable bit 0. | derived |
| `reg_startup_wake_status` | `DAT_EXTMEM_f0dd` | Register read once at start-up into power_wake_source; bit 2 leads to a second release of the main processor. | descriptive |
| `reg_flash_spi_start` | `DAT_EXTMEM_f0e5` | SPI flash transfer start and busy bits: bit 0 command or write, bit 1 read transfer, bit 6 FIFO reset. | derived |
| `reg_flash_spi_mode` | `DAT_EXTMEM_f0e6` | SPI flash transfer mode (bits 2..3 kept; 0x41 command transfer, 0x01 read or program). | derived |
| `reg_flash_spi_read_opcode` | `DAT_EXTMEM_f0ea` | Command byte of an SPI flash data transfer: reads (0x0B / 0x3B / 0x6B, status) and Page Program (0x02). | derived |
| `reg_flash_spi_count_high` | `DAT_EXTMEM_f0eb` | Bits 23..16 of the SPI flash transfer byte count. | derived |
| `reg_flash_spi_count_mid` | `DAT_EXTMEM_f0ec` | Bits 15..8 of the SPI flash transfer byte count. | derived |
| `reg_flash_spi_count_low` | `DAT_EXTMEM_f0ed` | Bits 7..0 of the SPI flash transfer byte count. | derived |
| `reg_flash_spi_write_opcode` | `DAT_EXTMEM_f0ee` | Command byte of an SPI flash command or write transfer (erase, program, status write). | derived |
| `reg_flash_spi_read_byte` | `DAT_EXTMEM_f0ef` | Byte answered by the flash to a one-byte read transfer. | derived |
| `reg_flash_spi_addr_high` | `DAT_EXTMEM_f0f0` | Bits 23..16 of the SPI flash transfer address. | derived |
| `reg_flash_spi_addr_mid` | `DAT_EXTMEM_f0f1` | Bits 15..8 of the SPI flash transfer address. | derived |
| `reg_flash_spi_addr_low` | `DAT_EXTMEM_f0f2` | Bits 7..0 of the SPI flash transfer address. | derived |
| `reg_flash_spi_format` | `DAT_EXTMEM_f0f4` | SPI flash transfer format (3 with address, 7 one-byte read, 0x13 \| count << 5 for commands). | derived |
| `reg_uart2_line_ctrl` | `DAT_EXTMEM_f0f6` | Line control of serial port 2: bit 7 set on open, line format bits from command 0x05. | derived |
| `reg_uart2_divisor_high` | `DAT_EXTMEM_f0f7` | High byte of the serial port 2 baud divisor (12 MHz / baud - 1). | derived |
| `reg_uart2_divisor_low` | `DAT_EXTMEM_f0f8` | Low byte of the serial port 2 baud divisor. | derived |
| `reg_uart2_config` | `DAT_EXTMEM_f0f9` | Configuration register of serial port 2, set to 0xEA on open. | descriptive |
| `reg_uart2_status` | `DAT_EXTMEM_f0fa` | Status of serial port 2: bit 0 = receive empty, bit 4 = acknowledged by writing it back. | derived |
| `reg_uart2_tx_data` | `DAT_EXTMEM_f0fb` | Transmit data register of serial port 2. | derived |
| `reg_uart2_rx_data` | `DAT_EXTMEM_f0fc` | Receive data register of serial port 2. | derived |
| `reg_gpio_port8` | `DAT_EXTMEM_f114` | Output register of GPIO port 8. | derived |
| `reg_gpio_port8_partner` | `DAT_EXTMEM_f115` | Partner register of GPIO port 8, ORed into each output update. | derived |
| `reg_gpio_port9` | `DAT_EXTMEM_f116` | Output register of GPIO port 9. | derived |
| `reg_gpio_port9_partner` | `DAT_EXTMEM_f117` | Partner register of GPIO port 9, ORed into each output update. | derived |
| `reg_gpio_port10` | `DAT_EXTMEM_f118` | Output register of GPIO port 10. | derived |
| `reg_gpio_port10_partner` | `DAT_EXTMEM_f119` | Partner register of GPIO port 10, ORed into each output update. | derived |
| `reg_gpio_port11` | `DAT_EXTMEM_f11a` | Output register of GPIO port 11. | derived |
| `reg_gpio_port11_partner` | `DAT_EXTMEM_f11b` | Partner register of GPIO port 11, ORed into each output update. | derived |
| `reg_gpio_port12` | `DAT_EXTMEM_f11c` | Output register of GPIO port 12. | derived |
| `reg_gpio_port12_partner` | `DAT_EXTMEM_f11d` | Partner register of GPIO port 12, ORed into each output update. | derived |
| `reg_gpio_port13` | `DAT_EXTMEM_f11e` | Output register of GPIO port 13. | derived |
| `reg_gpio_port13_partner` | `DAT_EXTMEM_f11f` | Partner register of GPIO port 13, ORed into each output update. | derived |
| `reg_i2c6_ctrl` | `DAT_EXTMEM_f140` | Control register of I2C unit 6; bit 6 arms the DDC/CI slave. | derived |
| `reg_i2c6_status` | `DAT_EXTMEM_f141` | Status of I2C unit 6: bit 7 = read transfer, bit 0 = transfer finished. | derived |
| `reg_i2c6_mode` | `DAT_EXTMEM_f142` | Mode register of I2C unit 6 (0xF8 on slave enable, 0xA0 / 0xC0 per transfer). | derived |
| `reg_i2c6_events` | `DAT_EXTMEM_f143` | Event bits of I2C unit 6: 7 addressed, 6 byte to send, 5 byte received, 4 and 3 others. | derived |
| `reg_i2c6_event_ack` | `DAT_EXTMEM_f144` | Event acknowledge register of I2C unit 6 (write the event bit back). | derived |
| `reg_i2c6_tx_data` | `DAT_EXTMEM_f145` | Transmit data register of I2C unit 6. | derived |
| `reg_i2c6_rx_data` | `DAT_EXTMEM_f146` | Receive data register of I2C unit 6. | derived |
| `reg_i2c6_address` | `DAT_EXTMEM_f147` | DDC/CI slave address of I2C unit 6 (bits 7..1) and its slave enable bit 0. | derived |
| `reg_usb_load_start` | `DAT_EXTMEM_f167` | Start of the copy of the update agent into the USB controller (0x87); reads 0 when done. | derived |
| `reg_usb_load_addr_low` | `DAT_EXTMEM_f16a` | Bits 7..0 of the flash address of the USB controller image. | derived |
| `reg_usb_load_addr_mid` | `DAT_EXTMEM_f16b` | Bits 15..8 of the flash address of the USB controller image. | derived |
| `reg_usb_load_addr_high` | `DAT_EXTMEM_f16c` | Bits 23..16 of the flash address of the USB controller image. | derived |
| `reg_usb_load_len_low` | `DAT_EXTMEM_f16d` | Bits 7..0 of the length of the USB controller image. | derived |
| `reg_usb_load_len_mid` | `DAT_EXTMEM_f16e` | Bits 15..8 of the length of the USB controller image. | derived |
| `reg_usb_load_len_high` | `DAT_EXTMEM_f16f` | Bits 23..16 of the length of the USB controller image. | derived |
| `reg_edid0_entry` | `DAT_EXTMEM_f180` | Extra EDID entry value of port 0 (used for EDIDs longer than 256 bytes). | derived |
| `reg_edid0_entry_ctrl` | `DAT_EXTMEM_f181` | Bit 7 switches the extra EDID entry of port 0 on. | derived |
| `reg_edid1_entry` | `DAT_EXTMEM_f182` | Extra EDID entry value of port 1 (used for EDIDs longer than 256 bytes). | derived |
| `reg_edid1_entry_ctrl` | `DAT_EXTMEM_f183` | Bit 7 switches the extra EDID entry of port 1 on. | derived |
| `reg_edid2_entry` | `DAT_EXTMEM_f184` | Extra EDID entry value of port 2 (used for EDIDs longer than 256 bytes). | derived |
| `reg_edid2_entry_ctrl` | `DAT_EXTMEM_f185` | Bit 7 switches the extra EDID entry of port 2 on. | derived |
| `reg_edid3_entry` | `DAT_EXTMEM_f186` | Extra EDID entry value of port 3 (used for EDIDs longer than 256 bytes). | derived |
| `reg_edid3_entry_ctrl` | `DAT_EXTMEM_f187` | Bit 7 switches the extra EDID entry of port 3 on. | derived |
| `reg_edid4_entry` | `DAT_EXTMEM_f188` | Extra EDID entry value of port 4 (used for EDIDs longer than 256 bytes). | derived |
| `reg_edid4_entry_ctrl` | `DAT_EXTMEM_f189` | Bit 7 switches the extra EDID entry of port 4 on. | derived |
| `reg_edid5_entry` | `DAT_EXTMEM_f18a` | Extra EDID entry value of port 5 (used for EDIDs longer than 256 bytes). | derived |
| `reg_edid5_entry_ctrl` | `DAT_EXTMEM_f18b` | Bit 7 switches the extra EDID entry of port 5 on. | derived |
| `reg_edid6_entry` | `DAT_EXTMEM_f18c` | Extra EDID entry value of port 6 (used for EDIDs longer than 256 bytes). | derived |
| `reg_edid6_entry_ctrl` | `DAT_EXTMEM_f18d` | Bit 7 switches the extra EDID entry of port 6 on. | derived |
| `reg_flash_fifo_port` | `DAT_EXTMEM_f1c0` | SPI flash FIFO port: control codes 0x80 / 0x82 / 0x84 are written to it, read data comes from it. | descriptive |
| `reg_flash_fifo_wdata` | `DAT_EXTMEM_f1c3` | SPI flash FIFO write port: command, address and page bytes to send. | derived |
| `reg_flash_fifo_rdata` | `DAT_EXTMEM_f1c8` | SPI flash FIFO answer port: control codes 0x80..0x82 written, answer bytes read. | descriptive |
| `reg_flash_leon2_base_7_0` | `DAT_EXTMEM_f1db` | Bits 7..0 of the LEON flash window base register; written at the end of start-up. | derived |
| `reg_flash_leon2_base_15_8` | `DAT_EXTMEM_f1dc` | Bits 15..8 of the LEON flash window base register; written at the end of start-up. | derived |
| `reg_flash_leon2_base_23_16` | `DAT_EXTMEM_f1dd` | Bits 23..16 of the LEON flash window base register; written at the end of start-up. | derived |
| `reg_flash_leon2_base_31_24` | `DAT_EXTMEM_f1de` | Bits 31..24 of the LEON flash window base register; written at the end of start-up. | derived |
| `reg_flash_access_ctrl` | `DAT_EXTMEM_f1df` | Bit 7 gives the SPI flash interface to the 8051 during a flash job. | derived |
| `reg_ipc_alive_stbc_cnt` | `DAT_EXTMEM_f204` | Alive ring 1, the 8051 byte: the token the 8051 sends round (stbc cnt). | derived |
| `reg_ipc_alive_main_cnt` | `DAT_EXTMEM_f208` | Alive ring 1, the main processor byte (main cnt): its copy of the token. | derived |
| `reg_ipc_alive_main_service` | `DAT_EXTMEM_f209` | Two bytes next to the main count; 0x87 0x78 here stops the crash check (service mark). | descriptive |
| `reg_ipc_alive_sub_cnt` | `DAT_EXTMEM_f20c` | Alive ring 1, the input processor byte (sub_cnt); equal to the 8051 byte = round complete. | derived |
| `reg_ipc_alive_sub_service` | `DAT_EXTMEM_f20d` | Two bytes next to the sub count; 0x87 0x78 here stops the crash check (service mark). | descriptive |
| `reg_ipc_shared_bytes` | `DAT_EXTMEM_f230` | Shared bytes 0xF230..0xF23F; the wake key scan writes its hit (flag, key, value) here. | derived |
| `reg_ipc_reliable_stbc_cnt` | `DAT_EXTMEM_f240` | Alive ring 2, the 8051 byte: the token the 8051 sends round. | derived |
| `reg_ipc_reliable_main_cnt` | `DAT_EXTMEM_f244` | Alive ring 2, the main processor byte. | derived |
| `reg_ipc_reliable_sub_cnt` | `DAT_EXTMEM_f248` | Alive ring 2, the input processor byte; equal to the 8051 byte = round complete. | derived |
| `reg_fwupd_mailbox` | `DAT_EXTMEM_f250` | Update mailbox read by the flash loop: command byte, address bytes, checksum. | derived |
| `reg_adc_ch1_value` | `DAT_EXTMEM_f3c5` | Reading of ADC channel 1. | derived |
| `reg_adc_ch2_value` | `DAT_EXTMEM_f3c6` | Reading of ADC channel 2. | derived |
| `reg_adc_ch3_value` | `DAT_EXTMEM_f3c7` | Reading of ADC channel 3. | derived |
| `reg_adc_ch4_value` | `DAT_EXTMEM_f3c8` | Reading of ADC channel 4. | derived |
| `reg_adc_ch5_value` | `DAT_EXTMEM_f3c9` | Reading of ADC channel 5. | derived |
| `reg_adc_ch6_value` | `DAT_EXTMEM_f3ca` | Reading of ADC channel 6. | derived |
| `reg_adc_ch7_value` | `DAT_EXTMEM_f3cb` | Reading of ADC channel 7. | derived |
| `reg_adc_ch8_value` | `DAT_EXTMEM_f3cc` | Reading of ADC channel 8. | derived |
| `reg_adc_ch9_value` | `DAT_EXTMEM_f3d5` | Reading of ADC channel 9. | derived |
| `reg_adc_ch10_value` | `DAT_EXTMEM_f3d6` | Reading of ADC channel 10. | derived |
| `reg_port_page_select` | `DAT_EXTMEM_f401` | Page select bytes of the port register window 0x6100 (one per 256-byte page). | derived |
| `reg_paged_block0_page_low` | `DAT_EXTMEM_f405` | Low byte of the page select of paged block 0 (window 0x6500). | derived |
| `reg_paged_block0_page_high` | `DAT_EXTMEM_f406` | High byte of the page select of paged block 0. | derived |
| `reg_paged_block1_page_low` | `DAT_EXTMEM_f407` | Low byte of the page select of paged block 1 (window 0x6600). | derived |
| `reg_paged_block1_page_high` | `DAT_EXTMEM_f408` | High byte of the page select of paged block 1. | derived |
| `reg_port_wake_select` | `DAT_EXTMEM_f40e` | Selects the input port whose wake flag is read (chip ID 0x20). | descriptive |
| `reg_adc_ch11_value` | `DAT_EXTMEM_f5d5` | Reading of ADC channel 11. | derived |
| `reg_adc_ch12_value` | `DAT_EXTMEM_f5d6` | Reading of ADC channel 12. | derived |
| `reg_dma_ctrl` | `DAT_EXTMEM_f600` | DMA start register: 0x04 fill, 0x02 second mode, 0x40 flash read; 0 when done. | derived |
| `reg_dma_status` | `DAT_EXTMEM_f601` | DMA done bits (7 fill, 6 other jobs), acknowledged by writing them back. | derived |
| `reg_dma_dst_7_0` | `DAT_EXTMEM_f602` | Bits 7..0 of the DMA destination address. | derived |
| `reg_dma_dst_15_8` | `DAT_EXTMEM_f603` | Bits 15..8 of the DMA destination address. | derived |
| `reg_dma_dst_23_16` | `DAT_EXTMEM_f604` | Bits 23..16 of the DMA destination address. | derived |
| `reg_dma_dst_31_24` | `DAT_EXTMEM_f605` | Bits 31..24 of the DMA destination address. | derived |
| `reg_dma_count_7_0` | `DAT_EXTMEM_f606` | Bits 7..0 of the DMA word count (length / 4). | derived |
| `reg_dma_count_15_8` | `DAT_EXTMEM_f607` | Bits 15..8 of the DMA word count. | derived |
| `reg_dma_count_23_16` | `DAT_EXTMEM_f608` | Bits 23..16 of the DMA word count. | derived |
| `reg_dma_count_31_24` | `DAT_EXTMEM_f609` | Bits 31..24 of the DMA word count. | derived |
| `reg_dma_flash_count_low` | `DAT_EXTMEM_f60c` | Low byte of the word count of a flash DMA read. | derived |
| `reg_dma_flash_count_high` | `DAT_EXTMEM_f60d` | High byte of the word count of a flash DMA read. | derived |
| `edid_ram` | `DAT_EXTMEM_f800` | EDID RAM (2 KB) served by the EDID slaves; filled by message type 1, read back for command 0x0D. | proven |

## Internal RAM

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `ddc_port_activity_flags` | `DAT_INTMEM_29` | One bit per DDC/CI slave port (0..7), set when a computer addresses the port, cleared when it is done. | derived |
| `ddc_request_index_port0` | `DAT_INTMEM_2a` | Write position in the request buffer row of DDC/CI slave port 0. | derived |
| `ddc_request_index_port1` | `DAT_INTMEM_2b` | Write position in the request buffer row of DDC/CI slave port 1. | derived |
| `ddc_request_index_port2` | `DAT_INTMEM_2c` | Write position in the request buffer row of DDC/CI slave port 2. | derived |
| `ddc_request_index_port3` | `DAT_INTMEM_2d` | Write position in the request buffer row of DDC/CI slave port 3. | derived |
| `ddc_request_index_port4` | `DAT_INTMEM_2e` | Write position in the request buffer row of DDC/CI slave port 4. | derived |
| `ddc_request_index_port5` | `DAT_INTMEM_2f` | Write position in the request buffer row of DDC/CI slave port 5. | derived |
| `ddc_request_index_port6` | `DAT_INTMEM_30` | Write position in the request buffer row of DDC/CI slave port 6. | derived |
| `ddc_request_index_port7` | `DAT_INTMEM_31` | Write position in the request buffer row of DDC/CI slave port 7. | derived |
| `ddc_reply_end_indexes` | `DAT_INTMEM_32` | End position of the reply in the buffer row, one byte per DDC/CI slave port, from port 0. | derived |
| `ddc_reply_end_index_port1` | `DAT_INTMEM_33` | End position of the reply in the buffer row of DDC/CI slave port 1. | derived |
| `ddc_reply_end_index_port2` | `DAT_INTMEM_34` | End position of the reply in the buffer row of DDC/CI slave port 2. | derived |
| `ddc_reply_end_index_port3` | `DAT_INTMEM_35` | End position of the reply in the buffer row of DDC/CI slave port 3. | derived |
| `ddc_reply_end_index_port4` | `DAT_INTMEM_36` | End position of the reply in the buffer row of DDC/CI slave port 4. | derived |
| `ddc_reply_end_index_port5` | `DAT_INTMEM_37` | End position of the reply in the buffer row of DDC/CI slave port 5. | derived |
| `ddc_reply_end_index_port6` | `DAT_INTMEM_38` | End position of the reply in the buffer row of DDC/CI slave port 6. | derived |
| `ddc_reply_end_index_port7` | `DAT_INTMEM_39` | End position of the reply in the buffer row of DDC/CI slave port 7. | derived |
| `ddc_reply_index_port0` | `DAT_INTMEM_3a` | Read position of the next reply byte sent by DDC/CI slave port 0. | derived |
| `ddc_reply_index_port1` | `DAT_INTMEM_3b` | Read position of the next reply byte sent by DDC/CI slave port 1. | derived |
| `ddc_reply_index_port2` | `DAT_INTMEM_3c` | Read position of the next reply byte sent by DDC/CI slave port 2. | derived |
| `ddc_reply_index_port3` | `DAT_INTMEM_3d` | Read position of the next reply byte sent by DDC/CI slave port 3. | derived |
| `ddc_reply_index_port4` | `DAT_INTMEM_3e` | Read position of the next reply byte sent by DDC/CI slave port 4. | derived |
| `ddc_reply_index_port5` | `DAT_INTMEM_3f` | Read position of the next reply byte sent by DDC/CI slave port 5. | derived |
| `ddc_reply_index_port6` | `DAT_INTMEM_40` | Read position of the next reply byte sent by DDC/CI slave port 6. | derived |
| `ddc_reply_index_port7` | `DAT_INTMEM_41` | Read position of the next reply byte sent by DDC/CI slave port 7. | derived |
| `uart_rx_write_index_port1` | `DAT_INTMEM_42` | Write position in the 16-byte receive ring of serial port 1. | derived |
| `uart_tx_write_index_port1` | `DAT_INTMEM_43` | Write position in the 16-byte transmit ring of serial port 1. | derived |
| `uart_rx_read_index_port1` | `DAT_INTMEM_44` | Read position in the receive ring of serial port 1. | derived |
| `uart_tx_read_index_port1` | `DAT_INTMEM_45` | Read position in the transmit ring of serial port 1. | derived |
| `uart_tx_idle_flag_port1` | `DAT_INTMEM_46` | Set when serial port 1 has sent all queued bytes; the next put restarts sending. | derived |
| `uart_rx_write_index_port2` | `DAT_INTMEM_47` | Write position in the receive ring of serial port 2 (0x38 bytes). | derived |
| `uart_rx_write_index_port3` | `DAT_INTMEM_48` | 16-bit write position in the receive ring of serial port 3 (0x38 bytes). | derived |
| `uart_rx_write_index_port3_low` | `DAT_INTMEM_49` | Low byte of the write position in the receive ring of serial port 3. | derived |
| `uart_rx_write_index_port4` | `DAT_INTMEM_4a` | 16-bit write position in the receive ring of serial port 4 (0x38 bytes). | derived |
| `uart_rx_write_index_port4_low` | `DAT_INTMEM_4b` | Low byte of the write position in the receive ring of serial port 4. | descriptive |
| `uart_rx_read_index_port2` | `DAT_INTMEM_4c` | Read position in the receive ring of serial port 2. | derived |
| `uart_tx_queue_count_port2` | `DAT_INTMEM_4d` | Number of bytes queued for serial port 2; the queue is sent at 0x37 bytes. | derived |
| `uart_rx_read_index_port3` | `DAT_INTMEM_4e` | 16-bit read position in the receive ring of serial port 3. | derived |
| `uart_tx_queue_count_port3` | `DAT_INTMEM_50` | Number of bytes queued for serial port 3. | derived |
| `uart_rx_read_index_port4` | `DAT_INTMEM_51` | 16-bit read position in the receive ring of serial port 4. | derived |
| `uart_tx_queue_count_port4` | `DAT_INTMEM_53` | Number of bytes queued for serial port 4. | derived |
| `timer_tick_count` | `DAT_INTMEM_57` | 16-bit system tick counter, counted by the timer 0 interrupt. | derived |
| `timer_tick_copy` | `DAT_INTMEM_59` | Copy of the tick counter, re-read until two reads agree. | derived |
| `irq_ext1_loop_counters` | `DAT_INTMEM_5b` | Work bytes of external interrupt 1: AUX loop index and count; the first also holds the IR pulse value. | descriptive |
| `uart_rx_last_byte_port1` | `DAT_INTMEM_5d` | Last byte received on serial port 1. | derived |
| `irq_ir_pulse_length` | `DAT_INTMEM_5e` | Length of the last infrared pulse, read from the capture registers. | derived |
| `i2c_sw_clock_wait_count` | `DAT_INTMEM_60` | Down-counter while waiting for the software I2C clock line to go high. | derived |
| `dp_aux_edid_offset_port0` | `DAT_INTMEM_64` | Read offset into the EDID that DP receiver 0 serves over I2C-over-AUX. | derived |
| `dp_aux_edid_offset_port1` | `DAT_INTMEM_65` | Read offset into the EDID that DP receiver 1 serves over I2C-over-AUX. | derived |

## RAM

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `ddc_last_access_ticks` | `DAT_EXTMEM_a000` | Tick stamp of the last DDC/CI slave activity, for the one-second idle re-arm. | derived |
| `ddc_reply_rows_from_end` | `DAT_EXTMEM_a001` | The DDC/CI reply rows addressed one byte lower, for the odd ports that fill a row from its end. | derived |
| `ddc_reply_buffers` | `DAT_EXTMEM_a002` | DDC/CI reply buffers: four rows of 0x3C bytes, row = port / 2 (even port from the front, odd from the end). | proven |
| `ddc_reply_buffer_row1` | `DAT_EXTMEM_a03e` | DDC/CI reply buffer row 1 (slave ports 2 and 3). | derived |
| `ddc_reply_buffer_row2` | `DAT_EXTMEM_a07a` | DDC/CI reply buffer row 2 (slave ports 4 and 5). | derived |
| `ddc_reply_buffer_row3` | `DAT_EXTMEM_a0b6` | DDC/CI reply buffer row 3 (slave ports 6 and 7). | derived |
| `ddc_pending_channel_flags` | `DAT_EXTMEM_a0f3` | One bit per DDC/CI slave port with a finished request waiting to be reported. | derived |
| `ddc_request_buffers` | `DAT_EXTMEM_a0f4` | DDC/CI request buffers: four rows of 0x3C bytes, row = port / 2, filled by the slave interrupts. | proven |
| `ddc_request_buffer_row1` | `DAT_EXTMEM_a130` | DDC/CI request buffer row 1 (slave ports 2 and 3). | derived |
| `ddc_request_buffer_row2` | `DAT_EXTMEM_a16c` | DDC/CI request buffer row 2 (slave ports 4 and 5). | derived |
| `ddc_request_buffer_row3` | `DAT_EXTMEM_a1a8` | DDC/CI request buffer row 3 (slave ports 6 and 7). | derived |
| `timer_div10_count` | `DAT_EXTMEM_a1e4` | Counter 0..9 stepped on every timer 0 tick. | derived |
| `dbg_uart_dump_read_index` | `DAT_EXTMEM_a1e5` | Read position of the debug dump of the serial port 2 receive ring. | derived |
| `uart_test_byte_value` | `DAT_EXTMEM_a1e6` | Counting test byte sent on serial port 4. | derived |
| `irq_capture_enable_mask` | `DAT_EXTMEM_a1e7` | Enabled sources of the capture interrupt (remote-control input), set by command 0x09 / 0x0A. | derived |
| `uart_rx_ring_port1` | `DAT_EXTMEM_a1e8` | 16-byte receive ring of serial port 1. | derived |
| `uart_tx_ring_port1` | `DAT_EXTMEM_a1f8` | 16-byte transmit ring of serial port 1 (printf output). | derived |
| `uart_rx_ring_port2` | `DAT_EXTMEM_a208` | Receive ring of serial port 2 (0x38 bytes). | derived |
| `uart_rx_ring_port3` | `DAT_EXTMEM_a240` | Receive ring of serial port 3 (0x38 bytes). | derived |
| `uart_rx_ring_port4` | `DAT_EXTMEM_a278` | Receive ring of serial port 4 (0x38 bytes). | derived |
| `uart_tx_queue_port2` | `DAT_EXTMEM_a2b0` | Bytes queued for sending on serial port 2. | derived |
| `uart_tx_queue_port3` | `DAT_EXTMEM_a2e8` | Bytes queued for sending on serial port 3. | derived |
| `uart_tx_queue_port4` | `DAT_EXTMEM_a320` | Bytes queued for sending on serial port 4. | derived |
| `ipc_rx_slot_index` | `DAT_EXTMEM_a358` | Mailbox slot (0..3) where the search for the next message from the main processor starts. | derived |
| `sys_watch_token` | `DAT_EXTMEM_a359` | Token the 8051 sends round the alive rings (plus 7 for ring 1, plus 13 for ring 2). | derived |
| `sys_watch_ring1_ticks` | `DAT_EXTMEM_a35a` | Tick stamp of the last round of alive ring 1; more than 15000 ticks old means a crash. | derived |
| `sys_watch_ring2_ticks` | `DAT_EXTMEM_a35c` | Tick stamp of the last round of alive ring 2; more than 10000 ticks old means a crash. | derived |
| `ipc_cmd25_sequence_state` | `DAT_EXTMEM_a35e` | State (0..2) of the timed port sequence started by command 0x25. | derived |
| `i2c_result_ready_flag` | `DAT_EXTMEM_a35f` | Set to 1 when an I2C read result waits to be reported to the main processor. | derived |
| `i2c_transfer_buffer` | `DAT_EXTMEM_a360` | Message type 2 data: device and register bytes, then the bytes to write or the bytes read. | derived |
| `i2c_transfer_data` | `DAT_EXTMEM_a362` | Data part of the I2C transfer buffer; holds the read result that is reported. | derived |
| `ipc_cmd25_first_port` | `DAT_EXTMEM_a3e0` | First port of the pair stored by command 0x25 (byte 2). | derived |
| `ipc_cmd25_second_port` | `DAT_EXTMEM_a3e1` | Second port of the pair stored by command 0x25 (byte 3). | derived |
| `ipc_tx_slot_index` | `DAT_EXTMEM_a3e2` | Mailbox slot (0..3) where the search for a free slot towards the main processor starts. | derived |
| `uart_rx_reported_mask` | `DAT_EXTMEM_a3e3` | One bit per serial port whose received data still sits in a mailbox slot. | derived |
| `i2c_result_channel` | `DAT_EXTMEM_a3e4` | Hardware I2C channel of the read result waiting to be reported. | derived |
| `ipc_report_record` | `DAT_EXTMEM_a3e5` | Outgoing report for the main processor: word count, position, type, channel, flags, length, data. | derived |
| `ipc_report_record_length` | `DAT_EXTMEM_a3ea` | Bytes of the report still to send; zero means the record is free. | derived |
| `edid_readback_count` | `DAT_EXTMEM_a46c` | Byte count of the EDID RAM read-back asked for with command 0x0D; zero = none. | derived |
| `edid_readback_offset` | `DAT_EXTMEM_a46d` | Start of the EDID RAM read-back asked for with command 0x0D, in 16-byte units. | derived |
| `i2c_result_length` | `DAT_EXTMEM_a46e` | Byte count of the I2C read result waiting to be reported. | derived |
| `power_wake_source` | `DAT_EXTMEM_a46f` | Wake word: code of the source that ended standby, passed to the main processor on release. | derived |
| `sys_main_work_word` | `DAT_EXTMEM_a470` | Work word of the main loop: counter of its 100-pass delay and holder of the wake check results. | descriptive |
| `power_wake_retry_count` | `DAT_EXTMEM_a472` | Round counter (up to 10) of the wake-up wait while 0xDCB0 bits 7..6 stay set ('cnt %d %d'). | descriptive |
| `startup_share_copy` | `DAT_EXTMEM_a47f` | Copy of the share block (from 0x3002) with the image records used at start-up. | derived |
| `startup_share_copy_0x0c` | `DAT_EXTMEM_a48b` | Flash source of the first image record; the record is handed to startup_setup_leon2m. | descriptive |
| `startup_share_copy_0x10` | `DAT_EXTMEM_a48f` | Length of the first image record. | descriptive |
| `startup_share_copy_0x14` | `DAT_EXTMEM_a493` | Flash source of the second image record. | descriptive |
| `startup_share_copy_0x18` | `DAT_EXTMEM_a497` | Destination of the second image record. | descriptive |
| `startup_share_copy_0x1c` | `DAT_EXTMEM_a49b` | Length of the second image record. | descriptive |
| `startup_share_copy_0x20` | `DAT_EXTMEM_a49f` | Long written to registers 0xF1DB..0xF1DE and to XDATA 0xA729 at the end of start-up. | descriptive |
| `startup_share_copy_0x30` | `DAT_EXTMEM_a4af` | Flash source of the third image record; the record is handed to startup_setup_leon2s. | descriptive |
| `startup_share_copy_0x3c` | `DAT_EXTMEM_a4bb` | Destination of the fifth image record. | descriptive |
| `startup_share_copy_0x44` | `DAT_EXTMEM_a4c3` | Flash source of the fourth image record (chip IDs 0x16/0x17/0x1E/0x1F only). | descriptive |
| `startup_share_copy_0x48` | `DAT_EXTMEM_a4c7` | Length of the fourth image record. | descriptive |
| `reg_ahb_read_addr` | `DAT_EXTMEM_a4e7` | AHB address parameter of the PBus-to-AHB bridge read. | derived |
| `reg_ahb_write_addr` | `DAT_EXTMEM_a4ec` | AHB address parameter of the PBus-to-AHB bridge write. | derived |
| `reg_ahb_write_value` | `DAT_EXTMEM_a4f0` | Word parameter of the PBus-to-AHB bridge write. | derived |
| `sys_ir_ring_write_index` | `DAT_EXTMEM_a564` | Write position in the 128-byte infrared pulse ring. | derived |
| `sys_ir_ring_read_index` | `DAT_EXTMEM_a565` | Read position in the 128-byte infrared pulse ring. | derived |
| `sys_ir_ring_buffer` | `DAT_EXTMEM_a566` | 128-byte ring of infrared pulse lengths (report type 5). | derived |
| `power_ir_match_state` | `DAT_EXTMEM_a5e6` | State of the infrared wake-code matcher: step, collected bits and bit count. | derived |
| `power_wakeup_timer_ticks` | `DAT_EXTMEM_a5e9` | Tick stamp of the last count-down step of the wake-up timer. | derived |
| `power_key_hit_ticks` | `DAT_EXTMEM_a5eb` | Tick stamp of the wake key scan; a hit less than 50 ticks after it is ignored. | derived |
| `power_key_table` | `DAT_EXTMEM_a5ed` | Standby key and wake-pin table (60 bytes) from the main processor; starts with six 2-byte key entries. | proven |
| `power_key_table_ir_code` | `DAT_EXTMEM_a5f9` | Six-byte infrared wake-up code of the standby table. | derived |
| `power_key_table_i2c_0x12` | `DAT_EXTMEM_a5ff` | Standby table word passed as pin pointer to the software I2C ID check; zero disables it. | descriptive |
| `power_key_table_i2c_0x14` | `DAT_EXTMEM_a601` | Standby table word passed as pin pointer to the software I2C ID check. | descriptive |
| `power_key_table_i2c_0x16` | `DAT_EXTMEM_a603` | Standby table byte passed to the software I2C pin selection. | descriptive |
| `power_key_table_i2c_0x17` | `DAT_EXTMEM_a604` | Standby table word passed as pin pointer to the software I2C ID check; zero disables it. | descriptive |
| `power_key_table_i2c_0x19` | `DAT_EXTMEM_a606` | Standby table word passed as pin pointer to the software I2C ID check. | descriptive |
| `power_key_table_i2c_0x1b` | `DAT_EXTMEM_a608` | Standby table byte passed to the software I2C pin selection. | descriptive |
| `power_key_table_i2c_id_record` | `DAT_EXTMEM_a609` | Device address, register and six expected ID bytes for the software I2C ID check. | derived |
| `power_key_table_wake_pins` | `DAT_EXTMEM_a611` | Six 2-byte wake-up pin entries of the standby table. | derived |
| `power_key_table_standby_pins` | `DAT_EXTMEM_a61d` | Six 2-byte pin entries of the standby table that are set on entering standby. | derived |
| `power_key_release_seen_flag` | `DAT_EXTMEM_a629` | Set after a scan with no key or IR hit; a held key counts again only after that. | derived |
| `power_wakeup_timer_remaining` | `DAT_EXTMEM_a62a` | Ticks left on the wake-up timer (seconds x 1000); 0x03E7FC18 = stopped. | derived |
| `power_adc_key_tolerance` | `DAT_EXTMEM_a62e` | Tolerance of the ADC key comparison in the wake key scan (command 0x1B). | proven |
| `power_wake_port_table` | `DAT_EXTMEM_a62f` | Wake-up port table from the main processor: ten 3-byte entries (input kind and option bits, time slot, ...). | proven |
| `power_wake_table_index` | `DAT_EXTMEM_a64d` | Current entry of the wake-up port table being checked. | derived |
| `power_wake_slot_ticks` | `DAT_EXTMEM_a64e` | Tick stamp at which the current wake table entry got its time slot. | derived |
| `usb_cc_adc_reading` | `DAT_EXTMEM_a671` | ADC reading taken on the channel named in the USB-C port description. | descriptive |
| `usb_cc_line_readings` | `DAT_EXTMEM_a672` | The two CC line level readings of the USB-C port. | derived |
| `usb_cc_line_reading_second` | `DAT_EXTMEM_a673` | Second of the two CC line level readings. | derived |
| `usb_c_port_info` | `DAT_EXTMEM_a69c` | Ten-byte USB-C port description from the main processor (message type 11). | proven |
| `usb_c_port_info_port_select` | `DAT_EXTMEM_a6a5` | Last byte of the USB-C description; bits 1..0 select the Type-C port register block. | derived |
| `usb_cc_channel_select` | `DAT_EXTMEM_a6a6` | 1 starts CC channel 0 in mode 2; any other value starts channel 1. | descriptive |
| `power_dp_watch_ticks` | `DAT_EXTMEM_a6a7` | Tick stamp for the 5000-tick DP activity watch after a DP power-up request. | derived |
| `power_dp_watch_active_flag` | `DAT_EXTMEM_a6a9` | Set while the DP activity watch after a power-up request is running. | derived |
| `ipc_cmd25_start_ticks` | `DAT_EXTMEM_a6aa` | Tick stamp at the start of the command 0x25 port sequence (600 / 1200 tick steps). | derived |
| `ipc_cmd25_step_ticks` | `DAT_EXTMEM_a6ad` | Tick stamp of the last 500-tick step of the command 0x25 port sequence. | derived |
| `power_cut_table` | `DAT_EXTMEM_a6af` | Power-cut table from the main processor: six 3-byte pin entries (18 bytes). | proven |
| `ipc_cmd25_port_entry_ptr` | `DAT_EXTMEM_a6c1` | Pointer to the 0xF180 port entry that the command 0x25 sequence watches. | derived |
| `dp_power_up_request` | `DAT_EXTMEM_a6ee` | 1 when a DP source writes 1 to DPCD 0x600; sys_step_clock_switch counts it on to 4; 0 in power saving. | derived |
| `dp_aux_link_config_port0` | `DAT_EXTMEM_a6ef` | Seven DPCD link configuration bytes (0x100..) written by the source on DP receiver 0. | derived |
| `dp_aux_link_config_port0_0x03` | `DAT_EXTMEM_a6f2` | Byte 3 of the DP receiver 0 link configuration, cleared when AUX handling starts. | descriptive |
| `dp_aux_link_config_port1` | `DAT_EXTMEM_a6f6` | Seven DPCD link configuration bytes (0x100..) written by the source on DP receiver 1. | derived |
| `dp_aux_link_config_port1_0x03` | `DAT_EXTMEM_a6f9` | Byte 3 of the DP receiver 1 link configuration, cleared when AUX handling starts. | descriptive |
| `dp_aux_port_state_flags` | `DAT_EXTMEM_a6fd` | Four bits per DP receiver: bit 1 = powered on by DPCD 0x600, bit 0 = lanes reported trained. | derived |
| `i2c_sw_sda_port_ptr` | `DAT_EXTMEM_a6fe` | Pointer to the port register of the software I2C data line. | derived |
| `i2c_sw_scl_port_ptr` | `DAT_EXTMEM_a701` | Pointer to the port register of the software I2C clock line. | derived |
| `i2c_sw_sda_mask` | `DAT_EXTMEM_a704` | Bit mask of the software I2C data line in its port register. | derived |
| `i2c_sw_scl_mask` | `DAT_EXTMEM_a705` | Bit mask of the software I2C clock line in its port register. | derived |
| `i2c_sw_sda_ctrl_ptr` | `DAT_EXTMEM_a706` | Pointer to the second register of the data line, ORed in on each update and set while reading. | descriptive |
| `i2c_sw_scl_ctrl_ptr` | `DAT_EXTMEM_a709` | Pointer to the second register of the clock line, ORed in on each update. | descriptive |
| `i2c_sw_id_match_flag` | `DAT_EXTMEM_a70c` | Whether the last software I2C device ID check matched. | derived |
| `flash_window_base` | `DAT_EXTMEM_a70d` | Flash window base address for the main processor; the next long is the job address. | derived |
| `flash_job_address` | `DAT_EXTMEM_a711` | Flash address of the current flash job (window base + extension + offset). | derived |
| `flash_job_length` | `DAT_EXTMEM_a715` | Byte length of the current flash read or program job. | derived |
| `flash_window_extension` | `DAT_EXTMEM_a717` | Extension added to the window base for flash job addresses (command 0x26). | derived |
| `flash_leon2_base_address` | `DAT_EXTMEM_a729` | LEON flash window base saved at the end of start-up. | derived |
| `startup_core_reg_addr` | `DAT_EXTMEM_a72d` | AHB address of the LEON core register that is written next. | derived |
| `startup_core_reg_value` | `DAT_EXTMEM_a731` | Value for the LEON core register that is written next. | derived |
| `sys_timed_record` | `DAT_EXTMEM_a735` | Timed indicator effect: last tick stamp, steps, mode, target, two limit pairs. | derived |
| `sys_timed_steps` | `DAT_EXTMEM_a737` | Ramp step of each of the two channels, from their level span. | derived |
| `sys_timed_mode` | `DAT_EXTMEM_a739` | Mode of the timed effect: 0 off, 1 toggle, 2 ramp. | derived |
| `sys_timed_target` | `DAT_EXTMEM_a73a` | Toggle target address (mode 1) or the two ramp field bytes (mode 2). | derived |
| `sys_timed_limits` | `DAT_EXTMEM_a73c` | High and low limit pairs of the two timed effect channels (0xA73C/D, 0xA73E/F). | derived |
| `flash_block_byte_ptr` | `DAT_EXTMEM_a74a` | Moving byte pointer of the 512-byte flash block copies. | derived |
| `flash_block_sum` | `DAT_EXTMEM_a74c` | Sum of the 512 bytes of the last flash block read. | derived |
| `flash_block_addr_high` | `DAT_EXTMEM_a74e` | Bits 23..16 of the flash address of a 512-byte block read. | derived |
| `flash_block_addr_bits_7_0` | `DAT_EXTMEM_a74f` | Bits 7..0 of the flash address of a 512-byte block read (written to register 0xF0F2). | derived |
| `flash_block_addr_bits_15_8` | `DAT_EXTMEM_a750` | Bits 15..8 of the flash address of a 512-byte block read (written to register 0xF0F1). | derived |
| `dp_mrx_adc_min_levels` | `DAT_EXTMEM_a751` | Lowest analog sense reading of each DP port since detection started. | derived |
| `dp_mrx_adc_sample_counts` | `DAT_EXTMEM_a753` | Number of first readings taken per DP port (up to 2). | derived |
| `dp_mrx_adc_channel_port0` | `DAT_EXTMEM_a755` | ADC channel of the analog sense line of DP port 0. | derived |
| `dp_mrx_adc_channel_port1` | `DAT_EXTMEM_a756` | ADC channel of the analog sense line of DP port 1. | derived |
| `hdmi_cec_active_source` | `DAT_EXTMEM_a757` | Logical address of the device that last sent CEC 'Active Source' (0x0F = none). | derived |
| `hdmi_cec_request_flags` | `DAT_EXTMEM_a758` | CEC requests seen: bit 1 Standby, 2 Active Source, 3 Inactive Source, 4 User Control Pressed. | derived |
| `hdmi_cec_operand` | `DAT_EXTMEM_a759` | Operand byte of the last CEC request (0xFF = none). | derived |
| `hdmi_cec_initiator` | `DAT_EXTMEM_a75a` | Logical address of the sender of the last received CEC message. | derived |
| `flash_edid_write_addr` | `DAT_EXTMEM_a75f` | Flash address of the next 256-byte page when the EDID RAM is written to flash. | derived |
| `uart_line_format_port1` | `DAT_EXTMEM_a763` | Line-format code of serial port 1. | derived |
| `uart_line_format_port2` | `DAT_EXTMEM_a764` | Line-format code of serial port 2. | derived |
| `uart_line_format_port3` | `DAT_EXTMEM_a765` | Line-format code of serial port 3. | derived |
| `uart_line_format_port4` | `DAT_EXTMEM_a766` | Line-format code of serial port 4. | derived |
| `usb_cc_block_ptr` | `DAT_EXTMEM_a76d` | Pointer to the register block of the selected Type-C port (0xB250 or 0x1A50). | derived |
| `usb_cc_block_ptr_high` | `DAT_EXTMEM_a76e` | High address byte of the Type-C register block pointer. | derived |
| `usb_cc_block_ptr_low` | `DAT_EXTMEM_a76f` | Low address byte of the Type-C register block pointer. | derived |
| `sys_run_state` | `DAT_EXTMEM_a770` | Run state of the 8051 main loop: 0 power saving, 1 power off, 2 running. | derived |
| `flash_read_opcode` | `DAT_EXTMEM_a771` | SPI flash read command used for DMA reads: 0x6B quad, 0x3B dual or 0x0B fast read. | derived |
| `timer_reload_high` | `DAT_EXTMEM_a772` | High byte of the timer 0 reload for the current clock. | derived |
| `timer_reload_low` | `DAT_EXTMEM_a773` | Low byte of the timer 0 reload for the current clock. | derived |
| `i2c_master_ctrl_bits` | `DAT_EXTMEM_a77a` | Bits ORed into the hardware I2C control register with each start, read and stop command. | descriptive |
| `i2c_sw_bus_clear_count` | `DAT_EXTMEM_a77b` | Clock pulses given (up to 9) while the software I2C data line is held low at start. | derived |
| `dp_mrx_adc_level` | `DAT_EXTMEM_a77e` | Last analog sense reading of a DP port (above 0xA0 = level high). | derived |
| `usb_cc_mode_ch0` | `DAT_EXTMEM_a780` | Stored mode (0, 1 or 2) of USB-C CC channel 0. | derived |
| `usb_cc_mode_ch1` | `DAT_EXTMEM_a781` | Stored mode (0, 1 or 2) of USB-C CC channel 1. | derived |
| `flash_data_buffer` | `DAT_EXTMEM_a800` | 2 KB flash data buffer shared by the flash jobs of the main processor (message type 7). | proven |
