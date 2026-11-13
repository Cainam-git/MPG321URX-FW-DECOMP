# Data names: Input processor (leon2s)

608 entries from `symbols/leon2s.data.json`, in address order. The source uses the names through the `#define` lists (see [Function names](../NAMES.md#names-in-the-source)); [Data objects](../DATA.md) describes the principal records. The *basis* column has the same meaning as for the function names.

| Basis | Entries |
|---|---:|
| proven | 78 |
| derived | 393 |
| descriptive | 137 |

## Constant data in the program

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `dp_tx_sink_edid_buffer` | `DAT_9f1b0000` | Buffer that receives the EDID of the DisplayPort sink; MST remote I2C reads answer from it. | derived |
| `hdmi_tx_sink_edid_buffers` | `DAT_9f1b0200` | EDID of the sink on each HDMI output port (0x200 bytes per port). | derived |
| `hdr_static_curve_rows_override` | `DAT_9f1b0700` | Seven 22-byte rows that replace the static HDR curve rows when flag byte 0xA8078A5B is 1. | derived |
| `hdr_tone_curve_alternate` | `DAT_9f1b0800` | Second 257-entry tone curve, loaded instead of the received one when control bit 2 is set. | derived |
| `hdcp_rx_hdmi_recheck_ports_entry` | `DAT_9f1b1ac0` | Entry of hdcp_rx_hdmi_recheck_ports, which InitHDCP stores as a tick hook. | proven |
| `hdcp_default_keys_second` | `DAT_9f1b6ef8` | Second built-in copy-protection key block (282 bytes). | derived |
| `hdcp_default_ksv_second` | `DAT_9f1b7018` | Second built-in 5-byte key-selection value. | derived |
| `hdcp_default_keys_first` | `DAT_9f1b7020` | First built-in copy-protection key block (282 bytes). | derived |
| `hdcp_default_ksv_first` | `DAT_9f1b7140` | First built-in 5-byte key-selection value. | derived |
| `hdcp_default_table_block` | `DAT_9f1b7148` | Built-in table block: a 16-byte value at +4 and a 0x20A-byte table at +0x28. | derived |
| `hdcp_tx_engine_table_mode4` | `DAT_9f1b7438` | Built-in 128-byte table sent to the protection engine in mode 4. | derived |
| `hdcp_tx_engine_table_mode5` | `DAT_9f1b74b8` | Built-in 128-byte table sent to the protection engine in mode 5. | derived |
| `hdcp_tx_engine_table_384` | `DAT_9f1c1ca8` | Built-in 384-byte table that is loaded into the protection engine of an output. | derived |
| `hdcp_default_id_block` | `DAT_9f1c1e38` | Built-in 16-byte value, handed out in reverse byte order. | derived |
| `hdcp_tx_engine_fixed_block` | `DAT_9f1c1e48` | ROM bytes: the SHA-256 digest of no data (32 bytes) and, at +0x4F, the 16 fixed bytes sent to the engine. | derived |
| `hdcp_tx_exchange_byte_table` | `DAT_9f1c1ea8` | Byte table 0, 1, 2, ... written to the engine and combined with the bytes read back. | descriptive |
| `hdcp_tx_reg_bases` | `DAT_9f1c1ec8` | Register block base of each output protection block (0x6000, 0x6100, 0x6390). | derived |
| `hdr_tmo_setup_steps_mode1` | `DAT_9f1c3fa0` | Step table summed into the 1025 values that mode 1 of the tone-mapping set-up writes. | derived |
| `hdr_tmo_gain_steps_mode1` | `DAT_9f1c43a8` | Step table of the tone-mapping gain table for mode 1 (written as running sums). | derived |
| `hdr_tmo_gain_steps_mode6` | `DAT_9f1c4d08` | Step table of the tone-mapping gain table for mode 6 (written as running sums). | derived |
| `hdr_tmo_gain_steps_mode5` | `DAT_9f1c51a8` | Step table of the tone-mapping gain table for mode 5 (written as running sums). | derived |
| `hdr_tmo_gain_steps_mode4` | `DAT_9f1c5600` | Step table of the tone-mapping gain table for mode 4 (written as running sums). | derived |
| `hdr_tmo_gain_steps_default` | `DAT_9f1c5a38` | Step table of the tone-mapping gain table for mode 3 and all other modes. | derived |
| `dp_mst_edid_3840x1080` | `DAT_9f1cc770` | Built-in EDID "NT68580_EV" with 3840x1080 as first timing, used when DP record byte 0x117 is 2. | proven |
| `dp_mst_edid_3840x2160` | `DAT_9f1cc8f0` | Built-in EDID "NT68580_EV" with 3840x2160 as first timing, used when DP record byte 0x117 is 1. | proven |
| `dsc_enc_rc_offsets_422` | `DAT_9f1cea6f` | Rate-control range offsets (15 per row) of the compression encoder for YUV 4:2:2. | derived |
| `dsc_enc_max_qp_444` | `DAT_9f1ceaaf` | Rate-control range maximum quantiser (15 per row, row by bit depth) for RGB and YUV 4:4:4. | derived |
| `dsc_enc_max_qp_422` | `DAT_9f1ceadc` | Rate-control range maximum quantiser (15 per row, 7 rows) for YUV 4:2:2. | derived |
| `dsc_enc_max_qp_420` | `DAT_9f1ceb45` | Rate-control range maximum quantiser (15 per row, row by bit depth) for YUV 4:2:0. | derived |
| `dsc_enc_min_qp_444` | `DAT_9f1ceb72` | Rate-control range minimum quantiser (15 per row, row by bit depth) for RGB and YUV 4:4:4. | derived |
| `dsc_enc_min_qp_422` | `DAT_9f1ceb9f` | Rate-control range minimum quantiser (15 per row, 7 rows) for YUV 4:2:2. | derived |
| `dsc_enc_min_qp_420` | `DAT_9f1cec08` | Rate-control range minimum quantiser (15 per row, row by bit depth) for YUV 4:2:0. | derived |
| `hdr_bezier_weights_order10` | `DAT_a0063960` | Weights of a Bezier tone curve of order 10: 11 rows of 65 points. | proven |
| `hdr_bezier_weights_order9` | `DAT_a0063ef6` | Weights of a Bezier tone curve of order 9: 10 rows of 65 points. | proven |
| `hdr_bezier_weights_order8` | `DAT_a006440a` | Weights of a Bezier tone curve of order 8: 9 rows of 65 points. | proven |
| `hdr_bezier_weights_order7` | `DAT_a006489c` | Weights of a Bezier tone curve of order 7: 8 rows of 65 points. | proven |
| `hdr_bezier_weights_order6` | `DAT_a0064cac` | Weights of a Bezier tone curve of order 6: 7 rows of 65 points. | proven |
| `hdr_bezier_weights_order5` | `DAT_a006503a` | Weights of a Bezier tone curve of order 5: 6 rows of 65 points. | proven |
| `hdr_bezier_weights_order4` | `DAT_a0065346` | Weights of a Bezier tone curve of order 4: 5 rows of 65 points. | proven |
| `hdr_bezier_weights_order3` | `DAT_a00655d0` | Weights of a Bezier tone curve of order 3: 4 rows of 65 points. | proven |
| `hdr_bezier_weights_order2` | `DAT_a00657d8` | Weights of a Bezier tone curve of order 2: 3 rows of 65 points. | proven |
| `dp_mst_dpcd_addresses` | `DAT_a00b383c` | Table of DPCD register numbers (0x200..0x20B, 0x261, 0x301, 0x340..) that the MST answers read. | derived |
| `hdmi_eq_scan_state_handlers` | `DAT_a00b3a20` | State routines of the HDMI equaliser scan, indexed by the scan state word. | proven |
| `hdmi_eq_aeq_entries` | `DAT_a00b3a64` | Equaliser entries {RCT byte, CFT halfword} that hdmi_phy_load_aeq_entry writes to a PHY. | derived |
| `hdmi_eq_rvga_values` | `DAT_a00b3ac8` | RVGA gain value of each RVGA index (3, 9, 15). | derived |
| `hdmi_eq_initial_cft_values` | `DAT_a00b3acc` | Initial CFT values the EQ scan tries in turn when the first R/C setting fails. | derived |
| `hdmi_eq_initial_rct_values` | `DAT_a00b3ad4` | Initial RCT values the EQ scan tries in turn when the first R/C setting fails. | derived |
| `hdmi_rx21_initial_cft_values` | `DAT_a00b3adc` | Start CFT value of the HDMI 2.1 lanes. | derived |
| `hdmi_rx21_initial_rct_values` | `DAT_a00b3ae4` | Start RCT value of the HDMI 2.1 lanes. | derived |
| `hdmi_rx21_lane_regs_0x33c` | `DAT_a00b3aec` | PHY register 0x33C of each of the four HDMI 2.1 lanes, read for the lane eye-status score. | derived |
| `hdmi_rx21_lane_regs_0x31c` | `DAT_a00b3af4` | PHY register 0x31C of each of the four HDMI 2.1 lanes, read for the lane eye-status score. | derived |
| `hdmi_rx21_lane_regs_0x064` | `DAT_a00b3afc` | PHY register 0x064 of each of the four HDMI 2.1 lanes, that takes the per-lane byte setting. | derived |
| `hdmi_phy_channel_regs_0x170` | `DAT_a00b3b04` | PHY register 0x170 of each of the three HDMI channels, set by the pre-AEQ step. | derived |
| `hdmi_phy_channel_regs_0x17c` | `DAT_a00b3b0a` | PHY register 0x17C of each of the three HDMI channels, set by the pre-AEQ step. | derived |
| `hdmi_rx21_lane_regs_0x17c` | `DAT_a00b3b10` | PHY register 0x17C of each of the four HDMI 2.1 lanes, set during PHY set-up and the LMS-to-EQ switch. | derived |
| `hdmi_rx21_lane_eq_regs` | `DAT_a00b3b18` | PHY register 0x178 of each of the four HDMI 2.1 lanes, which holds the RCT and CFT values. | derived |
| `hdmi_rx21_lane_regs_0x050` | `DAT_a00b3b20` | PHY register 0x050 of each of the four HDMI 2.1 lanes, written by the bit-7 lane routine. | derived |
| `hdmi_rx21_lane_regs_0x328` | `DAT_a00b3b28` | PHY register 0x328 of each of the four HDMI 2.1 lanes, of the lane set-up and default EQ tables. | derived |
| `hdmi_rx21_lane_regs_0x308` | `DAT_a00b3b30` | PHY register 0x308 of each of the four HDMI 2.1 lanes, of the lane set-up and default EQ tables. | derived |
| `hdmi_rx21_lane_regs_0x330` | `DAT_a00b3b38` | PHY register 0x330 of each of the four HDMI 2.1 lanes, of the lane set-up and default EQ tables. | derived |
| `hdmi_rx21_lane_regs_0x310` | `DAT_a00b3b40` | PHY register 0x310 of each of the four HDMI 2.1 lanes, of the lane set-up and default EQ tables. | derived |
| `hdmi_rx21_lane_regs_0x334` | `DAT_a00b3b48` | PHY register 0x334 of each of the four HDMI 2.1 lanes, of the lane set-up and default EQ tables. | derived |
| `hdmi_rx21_lane_regs_0x314` | `DAT_a00b3b50` | PHY register 0x314 of each of the four HDMI 2.1 lanes, of the lane set-up and default EQ tables. | derived |
| `hdmi_rx21_lane_regs_0x034` | `DAT_a00b3b58` | PHY register 0x034 of each of the four HDMI 2.1 lanes, of the lane set-up tables. | derived |
| `hdmi_rx21_lane_regs_0x014` | `DAT_a00b3b60` | PHY register 0x014 of each of the four HDMI 2.1 lanes, of the lane set-up tables. | derived |
| `hdmi_rx21_lane_regs_0x060` | `ARR_a00b3b68` | PHY register 0x060 of each of the four HDMI 2.1 lanes: 0x2060, 0x2460, 0x2860, 0x3060. | descriptive |
| `hdmi_rx21_lane_regs_0x170` | `DAT_a00b3b70` | PHY register 0x170 of each of the four HDMI 2.1 lanes, that takes the lane start values. | derived |
| `hdmi_phy_channel_eq_regs` | `DAT_a00b3b78` | PHY register 0x178 of each of the three channels, which holds the RCT and CFT values. | derived |
| `hdmi_eq_rct_candidates_byte8_set` | `DAT_a00b3b80` | RCT values 6, 8, 10, 12, 15 that the best-RCT search uses with EQ record byte 8 set. | derived |
| `hdmi_eq_rct_candidates` | `DAT_a00b3b88` | RCT values 1, 3, 5, 7, 9, 12, 15 that the best-RCT search goes through. | derived |
| `hdmi_phy_channel_regs_0x128` | `DAT_a00b3b90` | PHY register 0x128 of each of the three HDMI channels, read by the RVGA steps. | derived |
| `hdmi_phy_channel_regs_0x134` | `DAT_a00b3b96` | PHY register 0x134 of each of the three HDMI channels, read by the RVGA steps. | derived |
| `hdmi_eq_pre_aeq_entries_rx21` | `DAT_a00b3b9c` | Pre-AEQ {RCT, CFT} entries for HDMI 2.1 PHYs when flag 0xA8078988 of the port is 1. | derived |
| `hdmi_eq_pre_aeq_entries` | `DAT_a00b3bd4` | Pre-AEQ {RCT, CFT} entries stepped through when EQ record byte 8 is clear. | derived |
| `hdmi_eq_pre_aeq_entries_byte8_set` | `DAT_a00b3c0c` | Pre-AEQ {RCT, CFT} entries stepped through when EQ record byte 8 is set. | derived |
| `hdmi_tx_frl_clock_table` | `DAT_a00b407c` | Link clock of each FRL rate index in 0.1 MHz (1666 = 166.6 MHz up to 6666). | derived |
| `hdmi_tx_audio_rate_table` | `DAT_a00b408a` | The 18 audio sample rates in 100 Hz: 32k, 44.1k and 48k families, six multiples each. | derived |
| `hdmi_tx_audio_n_32k_rows` | `DAT_a00b40b0` | Audio N values for the 32 kHz family (4 rows by FRL rate, 6 multiples). | derived |
| `hdmi_tx_audio_n_44k_rows` | `DAT_a00b4110` | Audio N values for the 44.1 kHz family (2 rows by FRL rate, 6 multiples). | derived |
| `hdmi_tx_audio_n_48k_rows` | `DAT_a00b4140` | Audio N values for the 48 kHz family (4 rows by FRL rate, 6 multiples). | derived |
| `hdmi_tx_audio_n_by_tmds_clock` | `DAT_a00b41a0` | Audio N value per sample rate row and TMDS clock column, for a DisplayPort audio source. | derived |
| `hdmi_tx_audio_cts_by_tmds_clock` | `DAT_a00b41e8` | Audio CTS value per sample rate row and TMDS clock column (25.2 to 297 MHz). | derived |
| `hdmi_rx21_rx_detect_state_handlers` | `DAT_a00b4230` | State routines of the HDMI 2.1 receiver link training (Init, LTS_1..4, error and stable checks). | proven |
| `hdmi_rx21_mode_detect_state_handlers` | `DAT_a00b4258` | State routines of the HDMI 2.1 receiver mode detection. | proven |
| `hdmi_rx21_frl_clocks_mhz` | `DAT_a00b427c` | FRL link clock in MHz of each FRL rate (166, 333, 333, 444, 555, 666). | derived |
| `hdmi_rx21_hdr_metadata_id_names` | `DAT_a00b4558` | Names of the HDR InfoFrame metadata id values (EN_MD_ID_TYPE1, EN_MD_ID_RESERVED). | proven |
| `hdmi_rx21_hdr_eotf_names` | `DAT_a00b4568` | Names of the HDR InfoFrame transfer function values (SDR, HDR, ST2084, HLG). | proven |
| `hdmi_rx21_audio_permit_names` | `DAT_a00b4680` | Texts Permitted / Prohibited / Unknown printed for a flag of the audio InfoFrame. | proven |
| `hdmi_rx21_audio_sample_size_names` | `DAT_a00b4698` | Names of the audio InfoFrame sample sizes (16, 20, 24 bit). | proven |
| `hdmi_rx21_audio_sample_rate_names` | `DAT_a00b46c0` | Names of the audio InfoFrame sample rates (32K, 44.1K, 48K, ...). | proven |
| `hdmi_rx21_audio_channel_names` | `DAT_a00b4708` | Names of the audio InfoFrame channel counts (2 CH, 3 CH, ...). | proven |
| `hdmi_rx21_audio_coding_names` | `DAT_a00b4750` | Names of the audio InfoFrame coding types (PCM, AC3, MPEG1, ...). | proven |
| `hdmi_rx21_avi_ycc_range_names` | `DAT_a00b47d0` | Names of the AVI InfoFrame range values where 0 = Limited Range, 1 = Full Range. | proven |
| `hdmi_rx21_avi_rgb_range_names` | `DAT_a00b47f8` | Names of the AVI InfoFrame range values Default, Limited Range, Full Range. | proven |
| `hdmi_rx21_avi_ext_colorimetry_names` | `DAT_a00b4820` | Names of the AVI InfoFrame extended colorimetry values (xvYCC601, xvYCC709, ...). | proven |
| `hdmi_rx21_avi_it_content_names` | `DAT_a00b4860` | Names of the AVI InfoFrame IT content flag (No Data, IT Content). | proven |
| `hdmi_rx21_avi_scaling_names` | `DAT_a00b4878` | Names of the AVI InfoFrame scaling values (No, H, V, HV Scaling). | proven |
| `hdmi_rx21_avi_active_format_names` | `DAT_a00b48a0` | Names of the AVI InfoFrame active format values (16_by_9_top, 14_by_9_top, ...). | proven |
| `hdmi_rx21_avi_aspect_names` | `DAT_a00b4920` | Names of the AVI InfoFrame picture aspect values (No Data, 4:3, 16:9). | proven |
| `hdmi_rx21_avi_colorimetry_names` | `DAT_a00b4948` | Names of the AVI InfoFrame colorimetry values (ITU601, ITU709, EC Valid). | proven |
| `hdmi_rx21_avi_scan_names` | `DAT_a00b4970` | Names of the AVI InfoFrame scan values (Over Scan, Under Scan). | proven |
| `hdmi_rx21_avi_bar_info_names` | `DAT_a00b4998` | Names of the AVI InfoFrame bar information values (Not Valid, V, H, HV Valid). | proven |
| `hdmi_rx21_avi_format_info_names` | `DAT_a00b49c0` | Names of the AVI InfoFrame active format information flag (No Data, Valid). | proven |
| `hdmi_rx21_avi_color_format_names` | `DAT_a00b49d8` | Names of the AVI InfoFrame colour formats (RGB, YCbCr422, YCbCr444, YCbCr420). | proven |
| `hdmi_rx21_event_table` | `DAT_a00b4a00` | One 8-byte entry per interrupt event id of the HDMI 2.1 receiver (register and bit of the event). | derived |
| `dbg_hdmi_message_group_names` | `PTR_a00b4c80` | Names of the HDMI debug message groups (dbg_set_hdmi_message_flags, EQ_FLOW, ...). | proven |
| `hdmi_tx_frl_training_state_handlers` | `DAT_a00b4cf8` | State routines of the HDMI TX FRL link training (Init, LTS_1..4, LTS_P, LTS_L). | proven |
| `hdmi_tx_lts3_byte_table` | `DAT_a00b4d14` | Eight bytes 00 00 11 11 22 22 33 33 that link training state 3 copies but never reads. | descriptive |
| `dp_unit_reg_bases` | `DAT_a00b4d20` | Register block base of each of the eight DP units. | derived |
| `hdmi_pll_reg_bases` | `DAT_a00b4d30` | Register block base of each pixel PLL unit. | derived |
| `hdmi_tx_sys_reg_bases` | `DAT_a00b4d40` | Register block base of the two HDMI transmitter system blocks (0x6000, 0x6100). | derived |
| `hdmi_tx_reg_bases` | `DAT_a00b4d44` | Register block base of each bank of the two HDMI transmitters (2 ports x 6 banks). | derived |
| `hdcp_tx_engine_reg_bases` | `DAT_a00b4d5c` | Register block base of each copy-protection engine unit (0x4100..0x4130). | derived |
| `hdmi_port_reg_bases` | `DAT_a00b4d64` | Register block base of each of the four HDMI receivers (2.0 and 2.1). | derived |
| `dp_tx_phy_reg_bases` | `DAT_a00b4d6c` | Register block base of each DP transmitter PHY unit (0x7500 DPTX, 0x7300 eDP). | derived |
| `dp_tx_ctl_reg_bases` | `DAT_a00b4d70` | Register block base of each DP / eDP transmitter control bank. | derived |
| `dp_tx_reg_bases` | `DAT_a00b4d7a` | Register block base of each of the five DP / eDP outputs. | derived |
| `dp_paged_reg_bases` | `DAT_a00b4d84` | Register block base of the two paged DP receiver register pages (0x85, 0x86). | derived |
| `audio_reg_bases` | `DAT_a00b4d88` | Register block base of each of the four audio units. | derived |
| `dp_status_reg_bases` | `DAT_a00b4d90` | Register block base of the two DP receiver status blocks. | derived |
| `dp_reg_bases` | `DAT_a00b4d94` | Register block base of the two DP receivers. | derived |
| `hdmi_rx21_reg_bases` | `DAT_a00b4d98` | Register block base of the two HDMI 2.1 receivers. | derived |
| `hdmi_reg_bases` | `DAT_a00b4d9c` | Register block base of the two HDMI 2.0 receivers. | derived |
| `reg_block_lists` | `DAT_a00b4da0` | Pointers to the register base tables that SC_MaskSetByte can address as one list. | derived |
| `reg_block_list_counts` | `DAT_a00b4dc0` | Number of register blocks in each list of reg_block_lists. | derived |
| `hdmi_packet_switch_defaults` | `DAT_a00b4dc8` | Default packet-forwarding selection bytes loaded into an HDMI 2.0 or 2.1 receiver. | derived |
| `dp_tx_drive_level_table` | `DAT_a00b4dcc` | Swing / pre-emphasis entries of the DP outputs: two rows (output 0, others) of 10 halfwords. | derived |
| `dp_stream_reg485_values` | `DAT_a00b4df8` | Values written to DP receiver register 0x485 by the stream start, one per retry count. | descriptive |
| `dp_lane_table_defaults` | `DAT_a00b4e04` | Two {u16, u16} pairs (0x2D0, 0x240, 0xFFFF, 0xFFFF) copied by the lane table compare. | descriptive |
| `dbg_command_table` | `ARR_a00b4e3c` | The 8-row command table of dbg_handle_input_line: 32-byte name and routine pointer per row. | derived |

## Hardware registers

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `reg_audio_main_control` | `_DAT_cf011008` | Main audio control register; bit 0 is the main enable. | derived |
| `reg_audio_config` | `_DAT_cf011024` | Audio configuration register (bit 6 set on request). | derived |
| `reg_audio_level_high` | `_DAT_cf0110e4` | Audio register that takes a level byte. | derived |
| `reg_audio_select_0x1254` | `_DAT_cf011254` | First audio select register, read to see whether a source number is selected. | derived |
| `reg_audio_select_0x1258` | `_DAT_cf011258` | Second audio select register, read to see whether a source number is selected. | derived |
| `reg_hdmi_tx_source_route` | `_DAT_cf0116b4` | Routing bits that link an input port to an HDMI TX port. | derived |
| `reg_dsc_enc_route` | `_DAT_cf0116dc` | Route register whose bits 6-7 select the compression encoder route. | derived |
| `reg_input_port_control` | `_DAT_cf012448` | Receiver control register with one bit per DP port, also written when the receivers power off. | derived |
| `reg_hdcp_tx_dp_control` | `_DAT_cf018d00` | DisplayPort output protection control register (bit 6 = bypass, encryption bit). | derived |
| `reg_ipc_8051_shared_f202` | `_DAT_cf03c808` | Shared 8051 byte XDATA 0xF202; written to tell the 8051 that the shared table write is finished. | derived |
| `reg_ipc_shared_hdmi_status` | `_DAT_cf03c890` | Shared status register with one bit per HDMI port (HDMI 2.1 mode-change signal). | derived |
| `reg_ipc_shared_port_events` | `_DAT_cf03c894` | Shared event register with one bit per port. | derived |

## RAM

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `dp_mst_notify_select` | `DAT_a8076098` | Selection byte of the MST notification sequence (start value 2). | derived |
| `dp_mst_notify_state` | `DAT_a8076099` | State of the three-state MST notification sequence. | derived |
| `dp_mst_msg_reg_blocks` | `DAT_a807609c` | Register block address of each DP port for the MST message bytes (0xCF004400, 0xCF005800). | derived |
| `dp_mst_ctl_reg_blocks` | `DAT_a80760a4` | Register block address of each DP port for the MST control and ready bits (0xCF004000, 0xCF005400). | derived |
| `dp_mst_option_word` | `DAT_a80760ac` | MST option value received from the main processor. | derived |
| `dp_mst_port_reply_flags` | `DAT_a80760b0` | Per-port flag byte of the MST down-reply sender, set to 1 by the port reset. | descriptive |
| `dp_mst_remote_dpcd_bytes` | `DAT_a80760b8` | Fixed bytes that the MST REMOTE_DPCD_READ answer returns for one address range. | descriptive |
| `dp_mst_path_pbn_table` | `DAT_a80760c8` | Halfword bandwidth values that the MST ENUM_PATH_RESOURCES answer reports. | derived |
| `hdmi_rx_command_reg_list` | `ARR_a80760f0` | Halfword list of HDMI receiver register numbers; a command of the main program picks one by index. | derived |
| `trap_name_table` | `DAT_a8076104` | The 17 {trap type, name} pairs with the standard LEON2 trap names. | proven |
| `hdmi_eq_detect_period` | `_DAT_a8076190` | Period of the HDMI equaliser check task (start value 10). | derived |
| `hdmi_eq_tmds_bit_ratio_guess` | `DAT_a8076198` | Per HDMI PHY: the firmware's bTMDS_BIT_RATIO_GUESS, the guessed TMDS bit ratio (0 or 1). | proven |
| `hdmi_eq_fixed_cft` | `DAT_a807619c` | Fixed CFT value written to the PHY channels by the EQ step. | derived |
| `hdmi_eq_fixed_rct` | `DAT_a807619e` | Fixed RCT value written to the PHY channels by the EQ step. | derived |
| `hdmi_eq_retry_enable` | `DAT_a807619f` | Switch (start value 1) that lets the EQ checks retry with other values. | descriptive |
| `hdmi_eq_wait_passes` | `DAT_a80761a0` | Per HDMI PHY: number of passes DRV_HDMI_EQScan_FSM_PHY_R_ChkError waits before it reads the error counts. | derived |
| `dp_tx_output_map` | `DAT_a80761a8` | Mapping of the link outputs 1..4 to status bits in 2-bit fields, set by command 0x5E. | derived |
| `dp_tx_status_byte` | `DAT_a80761b0` | DP output status byte published to the main processor. | derived |
| `dp_tx_forced_hpd_flags` | `DAT_a80761b8` | One byte per DP output: 1 makes the next HPD pass treat the output as freshly plugged. | derived |
| `dp_tx_edp_last_output` | `DAT_a80761bf` | Number of the last eDP output that the HPD and training passes handle. | derived |
| `dp_tx_edp_first_output` | `DAT_a80761c0` | Number of the first eDP output that the HPD and training passes handle. | derived |
| `dp_tx_pacing_lane_counts` | `DAT_a80761c8` | Lane count of each DP output used for the last pacing computation. | derived |
| `hdr_static_curve_rows` | `DAT_a80761d0` | Seven 22-byte rows {x, y, f[9]} from which the static HDR curve is interpolated. | derived |
| `hdr_meta_reg_byte3` | `DAT_a807626a` | Receiver register of the fourth HDR10+ packet byte (0x266 HDMI 2.0, 0x407 HDMI 2.1). | derived |
| `hdr_meta_reg_byte2` | `DAT_a807626c` | Receiver register of the third HDR10+ packet byte (0x265 HDMI 2.0, 0x406 HDMI 2.1). | derived |
| `hdr_meta_reg_byte1` | `DAT_a807626e` | Receiver register of the second HDR10+ packet byte (0x264 HDMI 2.0, 0x405 HDMI 2.1). | derived |
| `hdr_meta_reg_byte0` | `DAT_a8076270` | Receiver register of the first HDR10+ packet byte (0x263 HDMI 2.0, 0x404 HDMI 2.1). | derived |
| `hdr_meta_ready_mask` | `DAT_a8076272` | Bit mask of the new-packet test for HDR10+ metadata (0x80, 1 or 0x20 by receiver). | descriptive |
| `hdr_meta_status_reg` | `DAT_a8076274` | Receiver register tested for a new HDR10+ packet (0x7C, 0x9C8 or 5 by receiver). | descriptive |
| `hdr_tmo_lut` | `DAT_a8076278` | The 257-entry tone-mapping table TMO_LUT built from the HDR10+ metadata. | proven |
| `hdr10plus_target_luminance` | `DAT_a807667c` | The larger of the scene luminance (x10) and the panel peak; divisor of the curve scale. | derived |
| `hdr10plus_scene_luminance` | `DAT_a8076680` | Scene maximum luminance x 10 from the metadata or from the percentile value. | derived |
| `hdr10plus_scene_max` | `DAT_a8076684` | The largest of the three maxscl values of the HDR10+ metadata. | derived |
| `audio_config` | `DAT_a8076688` | The 3-byte audio configuration received from the main processor. | derived |
| `audio_config_byte_1` | `DAT_a8076689` | Second byte of the audio configuration; its top two bits pick the unit set-up. | descriptive |
| `audio_output_sources` | `DAT_a8076690` | The source id routed to each of the nine audio outputs. | proven |
| `audio_dp_status` | `DAT_a80766a0` | Audio status bit of each of the two DP receivers. | derived |
| `hdr_last_peak_luminance` | `DAT_a80766ac` | Copy of the peak luminance kept to detect a change. | derived |
| `hdr_level_ratio_table` | `DAT_a80766b0` | Word table indexed by the level index; entry 0 / entry n gives the level scale in percent. | descriptive |
| `hdr_level_scale_table` | `DAT_a8076844` | Word table (start values 5000) multiplied with hdr_level_base_table in the level update. | descriptive |
| `hdr_level_base_table` | `DAT_a80769d8` | Word table read in the level update and scaled by hdr_level_scale_table. | descriptive |
| `hdr_peak_luminance` | `DAT_a80779dc` | The panel's peak luminance, limited to 10000 (1000 when 0 is given). | derived |
| `hdr_tmo_coefficients` | `DAT_a80779e0` | Coefficient values written into the coefficient fields of the tone-mapping block. | derived |
| `hdr_tone_curve` | `DAT_a8077a08` | The HDR tone curve that is loaded into the hardware (257 entries, 0x400 = neutral). | proven |
| `hdr_tmo_gain_sums` | `DAT_a8077c0c` | Copy of 500 running sums of the gain table that was last written. | derived |
| `hdr_gain` | `DAT_a80783dc` | The HDR gain (at most 0xFFF) set by hdr_update_tone_curve; hdr_smooth_level uses it as its lower limit. | proven |
| `hdr_blend_level` | `_DAT_a80785e0` | Level value blended step by step by hdr_smooth_level (start value 0x6400). | descriptive |
| `hdr_level_scale_percent` | `_DAT_a80785e4` | Level scale in percent: ratio table entry 0 * 100 / selected entry. | derived |
| `hdmi_tx_bank4_value` | `DAT_a80785e8` | The value (11..492) from which the HDMI TX bank 4 offsets are derived. | derived |
| `hdmi_tx_stored_audio_settings` | `DAT_a80785f0` | Stored audio settings loaded into an HDMI TX port. | derived |
| `hdmi_tx_stored_audio_infoframe` | `DAT_a8078600` | Stored audio InfoFrame bytes loaded into an HDMI TX port. | derived |
| `hdcp_rx_dp_hdcp2_bytes` | `_DAT_a8078610` | Byte table (start 11 22 33 .. 88) loaded into the DisplayPort input protection block. | descriptive |
| `hdcp_rx_hdmi_hdcp2_bytes` | `DAT_a8078620` | Byte table (start 10 20 .. 80) loaded into the HDMI input protection blocks. | descriptive |
| `hdmi_rx21_rx_detect_period` | `DAT_a8078630` | Period of the HDMI 2.1 link-training timer (start value 10). | derived |
| `hdmi_rx21_mode_detect_period` | `DAT_a8078631` | Period of the HDMI 2.1 mode-detect timer (start value 50). | derived |
| `dbg_hdmi_message_flags` | `_DAT_a8078634` | HDMI debug message groups: bit 0 INIT_INFO, 1 EQ_FLOW, 2 MODEDET_FLOW, 3 INT, 4 INFOFRAME, ... | proven |
| `hdmi_rx21_lts_lane_start` | `DAT_a8078640` | Start value (4) of the per-lane bytes of the HDMI 2.1 link training record. | descriptive |
| `hdmi_rx21_stable_count_limits` | `DAT_a8078648` | Per receiver: the value the standby state's stable count must pass; capped at 10 by the complete state. | derived |
| `hdmi_rx21_event_callbacks_0` | `DAT_a8078650` | Callback table of one packet-event group of the HDMI 2.1 receivers. | descriptive |
| `hdmi_rx21_event_callbacks_1` | `DAT_a8078670` | Callback table of one packet-event group of the HDMI 2.1 receivers. | descriptive |
| `hdmi_rx21_event_callbacks_2` | `DAT_a8078690` | Callback table of one packet-event group of the HDMI 2.1 receivers. | descriptive |
| `hdmi_rx21_event_callbacks_3` | `DAT_a80786b0` | Callback table of one packet-event group of the HDMI 2.1 receivers. | descriptive |
| `hdmi_rx21_event_callbacks_4` | `DAT_a80786d0` | Callback table of one packet-event group of the HDMI 2.1 receivers. | descriptive |
| `hdmi_rx21_event_callbacks_5` | `DAT_a80786f0` | Callback table of one packet-event group of the HDMI 2.1 receivers. | descriptive |
| `hdmi_tx_lts3_phy3c_bits_off` | `ARR_a8078710` | Per HDMI output: non-zero makes LTS3 clear bits 2..3 of PHY register 0x3C, zero sets them. | descriptive |
| `hdmi_tx_lts3_phy39_bit1_on` | `ARR_a8078718` | Per HDMI output: non-zero makes LTS3 set bit 1 of PHY register 0x39, zero clears it. | descriptive |
| `hdmi_tx_lts3_phy39_bit4_on` | `ARR_a8078720` | Per HDMI output: non-zero makes LTS3 set bit 4 of PHY register 0x39, zero clears it. | descriptive |
| `hdmi_tx_lts3_timeout_enables` | `ARR_a8078728` | Per HDMI output: 1 lets the LTS3 step limit send the training to LTS_L. | derived |
| `hdmi_tx_ffe_de_emphasis_values` | `ARR_a807872a` | Two bytes per TxFFE level {registers 8/0x98 value, registers 0x0E/0x9B value} for the De-Emphasis mode. | derived |
| `hdmi_tx_ffe_normal_values` | `ARR_a8078732` | One 16-bit value per TxFFE level, written to FRL registers 0xE2 / 0xE3 in the normal TxFFE mode. | derived |
| `hdmi_tx_frl_printed_states` | `ARR_a807873c` | Per HDMI output: the FRL training state whose name was printed last. | derived |
| `hdmi_tx_frl_timer_period` | `_DAT_a8078744` | Period of the HDMI TX FRL training timer. | derived |
| `sys_dsc_dec_restart_flag` | `DAT_a8078748` | Flag set by command 0x74 and by the DSC decoder state machine. | descriptive |
| `hdmi_tx_packet_source_regs_first` | `DAT_a807874c` | Addresses of the first packet source selection registers (0xCF011410, 0xCF011464, 0xCF011470), per group. | derived |
| `hdmi_tx_packet_source_regs_second` | `DAT_a8078758` | Addresses of the second packet source selection registers (0xCF011414, 0xCF011468, 0xCF011474), per group. | derived |
| `dp_port_lane_units` | `DAT_a8078768` | Receiver unit of each port and lane pair (4-byte rows). | derived |
| `sys_clock_hz` | `DAT_a80787dc` | System clock in Hz (96,000,000) from which the tick and UART dividers are computed. | derived |
| `osd_unzip_mode` | `DAT_a80787e0` | Mode of the queued OSD unpack request: 1 = direct write to OSD memory, else through the register port. | derived |
| `osd_unzip_request` | `DAT_a80787e4` | The queued OSD unpack request {a, b, c, d}. | derived |
| `osd_unzip_busy_flag` | `DAT_a80787f4` | Set while an OSD unpack request is queued; published to the main processor. | derived |
| `dp_mst_message_state` | `_DAT_a80787f8` | Indexes, flags and current port of the DisplayPort multi-stream message service. | proven |
| `dp_mst_message_state_half_2` | `_DAT_a80787fa` | Halfword +2 of the MST message state, cleared with the payload table and on port reset. | descriptive |
| `dp_mst_message_state_up_read_index` | `DAT_a80787fc` | Read index of the ring of messages fetched from the output and sent on towards the source. | derived |
| `dp_mst_message_state_up_write_index` | `DAT_a80787fd` | Write index of the ring of messages fetched from the output. | derived |
| `dp_mst_message_state_fwd_read_index` | `DAT_a80787fe` | Read index of the ring of down requests forwarded to the output. | derived |
| `dp_mst_message_state_fwd_write_index` | `DAT_a80787ff` | Write index of the ring of down requests forwarded to the output. | derived |
| `dp_mst_message_state_reply_read_indexes` | `DAT_a8078800` | Per-port read index of the down-reply chunk ring. | derived |
| `dp_mst_message_state_reply_write_indexes` | `DAT_a8078808` | Per-port write index of the down-reply chunk ring. | derived |
| `dp_mst_message_state_reply_offsets` | `DAT_a807880a` | Per-port halfword position in the outgoing message body. | descriptive |
| `dp_mst_reply_body_write_offsets` | `ARR_a807880e` | Per port: write position (halfword, modulo the ring size) in the body ring of the down replies. | derived |
| `dp_mst_message_state_status_row` | `DAT_a8078820` | Row of the status copy table that the port 0 interrupt work fills. | descriptive |
| `dp_mst_message_state_rx_read_indexes` | `DAT_a8078828` | Per-port read index of the received chunk ring. | derived |
| `dp_mst_message_state_rx_write_indexes` | `DAT_a8078830` | Per-port write index of the received chunk ring. | derived |
| `dp_mst_message_state_port` | `DAT_a8078832` | The DP port the MST message service is currently working on. | proven |
| `dp_mst_message_state_tx_states` | `DAT_a8078838` | Per-port transmit state of the MST service. | derived |
| `dp_mst_message_state_enable` | `DAT_a807883a` | Enable byte of the MST service; 0 also clears the up and forward ring indexes. | derived |
| `dp_mst_message_state_up_sent_flag` | `DAT_a807883b` | Set when the last record of a message from the output (down reply or up request) has been sent on. | derived |
| `dp_mst_message_state_up_pending_flag` | `DAT_a807883c` | Set by dp_mst_clear_ready_bit when no message from the output was sent; holds back the records that follow. | derived |
| `dp_mst_message_state_notify_action` | `DAT_a807883d` | Action byte of the MST notification sequence. | descriptive |
| `dp_mst_message_state_pending_chunks` | `DAT_a807883e` | Sum of the fill levels of the four chunk rings. | derived |
| `dp_mst_message_state_notify_flag` | `DAT_a807883f` | Flag of the MST notification sequence, also tested by the LINK_ADDRESS answer. | descriptive |
| `dp_mst_message_state_addressed_flag` | `DAT_a8078840` | Set after the LINK_ADDRESS answer; the port reset clears the MST records only while it is 1. | derived |
| `dp_mst_message_state_option_byte` | `DAT_a8078841` | MST option byte from the main processor, also written by the downstream fetch. | descriptive |
| `dp_mst_message_state_byte_0x4b` | `DAT_a8078843` | Byte +0x4B of the MST message state, written by the LINK_ADDRESS answer and status messages. | descriptive |
| `dp_mst_message_state_byte_0x4e` | `DAT_a8078846` | Byte +0x4E of the MST message state, written by the LINK_ADDRESS answer and status messages. | descriptive |
| `dp_mst_message_state_byte_0x4f` | `DAT_a8078847` | State byte +0x4F of the MST service, set by the payload and message handlers. | descriptive |
| `dp_mst_message_state_up_wait_flags` | `DAT_a8078848` | Per-port flag set while the transmit side waits after sending a record of a message from the output. | derived |
| `dp_mst_message_state_reply_wait_flags` | `DAT_a8078850` | Per-port flag set while the transmit side waits after a down reply. | descriptive |
| `dp_mst_message_state_byte_0x5a` | `DAT_a8078852` | State byte +0x5A of the MST service. | descriptive |
| `dp_mst_message_state_byte_0x5b` | `DAT_a8078853` | State byte +0x5B of the MST service. | descriptive |
| `dp_mst_message_state_fwd_queued_flag` | `DAT_a8078854` | Set when a message is added to the forward ring. | descriptive |
| `dp_mst_message_state_reply_ticks` | `DAT_a8078858` | Per-port time stamp of the last down reply, for the reply time-out. | derived |
| `dp_mst_message_state_up_ticks` | `DAT_a8078860` | Per-port time stamp of the last record sent from the output's message ring, for its time-out. | derived |
| `dp_mst_message_state_max_body_bytes` | `DAT_a8078868` | Largest number of body bytes written per outgoing chunk. | descriptive |
| `hdmi_tmds_link_ticks` | `DAT_a8078870` | Per-port time stamp of the HDMI 2.0 link state machine (200-tick waits). | derived |
| `hdmi_tmds_link_flags` | `DAT_a8078878` | Per-port flag byte of the HDMI 2.0 link state machine, cleared once handled. | descriptive |
| `hdmi_tmds_link_retry_counts` | `DAT_a8078880` | Per-port retry count of the HDMI 2.0 link state machine. | descriptive |
| `hdmi_rx21_link_ticks` | `DAT_a8078884` | Per-port time stamp of the HDMI 2.1 link state machine. | derived |
| `hdmi_rx21_power_flags` | `DAT_a8078890` | Power flags of the two HDMI 2.1 inputs. | derived |
| `hdmi_rx21_power_init_flag` | `DAT_a8078892` | Set once the HDMI 2.1 power flags have been set. | descriptive |
| `dp_saved_slice_values` | `DAT_a8078898` | Per-port value saved by the DP timing check and compared on the next pass. | descriptive |
| `dp_link_ticks` | `DAT_a807889c` | Per-stream time stamp of the DP link state machine. | derived |
| `dp_link_counters` | `DAT_a80788b0` | Per-stream counter of the DP link state machine, cleared on the move to status 5. | descriptive |
| `dp_link_mst_flags` | `DAT_a80788b8` | Per DP port: bit 0 of register 0xC1 as last read; a change prints SST2MST or MST2SST. | proven |
| `dp_link_flags` | `DAT_a80788c0` | Per-port flag byte read by the DP link state machine. | descriptive |
| `dp_link_slice_states` | `DAT_a80788c8` | Per DP port: 0 none, 1 slice count seen while settling, 2 seen at the set-up (DSC switched on). | derived |
| `input_port_event_flags` | `DAT_a80788d2` | Event bits of the inputs (bit per port) waiting to be published to the main processor. | derived |
| `input_port_flag_bits` | `DAT_a80788d3` | Per-port flag bits received in a command byte and copied into the port records. | derived |
| `input_command_flags` | `DAT_a80788d4` | The port action flag byte sent by the main processor. | derived |
| `input_port_option_mask` | `DAT_a80788d8` | Per-port option bit mask built from three command bytes. | derived |
| `ipc_status_flag_6` | `DAT_a80788dc` | Flag set by a command and published as bit 6 of the status flags. | descriptive |
| `input_event_clear_mask` | `DAT_a80788dd` | Event bits cleared from input_port_event_flags after they are published. | derived |
| `ipc_slot0_status_word` | `DAT_a80788e0` | Word 0 of mailbox slot 0: ready bit and the port type nibbles published to the main processor. | derived |
| `ipc_ready_posted_flag` | `DAT_a80788e4` | Set once the ready bit has been posted to the main processor. | derived |
| `uart_rx_buffer` | `DAT_a80788e8` | Receive ring buffer of the debug console. | derived |
| `hdmi_only_scramble_guess_mode` | `ARR_a8078978` | Per HDMI PHY: the firmware's bHDMI_ONLYSCRAMBLE_GUESSMODE byte, behind the port mode byte routines. | proven |
| `hdmi_eq_mode_override_flags` | `DAT_a8078980` | Per-port flag: 1 makes the EQ steps use the stored clock-ratio and scrambling modes. | descriptive |
| `hdmi_eq_error_mode_flags` | `DAT_a8078988` | Per-port flag set by the best-RCT search; picks the pre-AEQ table of HDMI 2.1 PHYs. | descriptive |
| `hdmi_eq_zero_rct_flag` | `DAT_a807898c` | Set when a channel shows a zero RCT value in the EQ error check; the EQ step then forces MEQ and clears it. | derived |
| `hdmi_eq_skew_fail_counts` | `DAT_a8078990` | Per-port count of skew failures of the EQ error check; above 10 a deskew hot-plug follows. | proven |
| `hdmi_eq_keep_results_flags` | `DAT_a8078998` | Per-port flag set when the EQ error check passed; while set the next scan keeps its work records. | derived |
| `hdmi_eq_pre_aeq_fails_lower` | `DAT_a807899c` | Per PHY and channel: bad pre-AEQ error results counted in search steps 0 and 1 (lower half of the indexes). | derived |
| `hdmi_eq_pre_aeq_fails_upper` | `DAT_a80789a8` | Per PHY and channel: bad pre-AEQ error results counted in search steps 2 and 3 (upper half of the indexes). | derived |
| `hdmi_eq_monitor_ticks` | `DAT_a80789b4` | Per-port time stamp of the last EQ error monitor run (runs every 100 ticks). | derived |
| `hdmi_eq_monitor_flags` | `DAT_a80789c0` | Per-port flag set by a forced EQ error monitor run. | descriptive |
| `hdmi_eq_saved_bit_ratio` | `DAT_a80789c8` | Per-port SCDC bit-clock ratio seen at the last clock-detect check. | derived |
| `hdmi_eq_timer_frl_rates` | `DAT_a80789d0` | Per receiver: the FRL rate the EQ detect timer saw last and passed to DRV_HDMI21_Set_PHY. | proven |
| `hdmi_eq_detect_task` | `DAT_a80789d4` | Timer task record of the periodic HDMI equaliser check. | derived |
| `dp_tx_hpd_status` | `DAT_a80789e0` | Hot-plug status byte of the link outputs. | derived |
| `dp_tx_hpd_event_bits` | `DAT_a80789e4` | Hot-plug event bits recorded for the link outputs. | derived |
| `dp_tx_hpd_prev_bit0` | `DAT_a80789e8` | Previous value of hot-plug status bit 0, for edge detection. | derived |
| `dp_tx_hpd_prev_bit1` | `DAT_a80789e9` | Previous value of hot-plug status bit 1, for edge detection. | derived |
| `dp_port_swap_flag` | `DAT_a80789ec` | Set when the two DP receiver ports are swapped. | derived |
| `dp_tx_aux_data_byte` | `DAT_a80789f0` | Byte buffer of the DP output's AUX transfers: the byte that is sent, or the byte that was read. | derived |
| `dp_tx_action_flags` | `ARR_a8078a00` | One halfword of pending action flags per DP output. | derived |
| `dp_tx_hpd_flag` | `DAT_a8078a0a` | Flag of the DP output HPD handling, published to the main processor as a status flag. | descriptive |
| `dp_tx_edp_hpd_enable` | `DAT_a8078a0c` | Enable byte of the eDP output HPD handling, set by a command. | descriptive |
| `dp_tx_aux_reply_count` | `DAT_a8078a0e` | Number of AUX reply bytes collected so far. | derived |
| `dp_tx_level_low_flag` | `DAT_a8078a0f` | Set while the measured level is below 40. | derived |
| `dp_tx_pacing_clocks` | `DAT_a8078a10` | Pixel clock of each DP output used for the last pacing computation. | derived |
| `dp_tx_pacing_depths` | `DAT_a8078a28` | Bits per pixel of each DP output used for the last pacing computation. | derived |
| `dp_tx_measured_level` | `DAT_a8078a30` | Measured level that the crossing check compares with 40. | derived |
| `hdr_meta_receiver_index` | `DAT_a8078a38` | Index of the receiver within its kind (0 or 1) that HDR10+ metadata is read from. | derived |
| `hdr_meta_source_mode` | `DAT_a8078a39` | Selected HDR10+ metadata source: 0/1 HDMI 2.0, 2/3 HDMI 2.1, 4/5 other receivers. | derived |
| `hdr10plus_present_flag` | `DAT_a8078a3a` | Set while HDR10+ metadata packets keep arriving; cleared after 200 ticks without one. | derived |
| `hdr10plus_last_ticks` | `DAT_a8078a3c` | Time stamp of the last HDR10+ metadata packet. | derived |
| `hdr10plus_packet_bytes` | `DAT_a8078a40` | The 27 HDR10+ InfoFrame bytes last read from the receiver. | derived |
| `hdr_curve_rows_reload_flag` | `DAT_a8078a5b` | Set to 1 to copy the override rows into the static curve table before the next build. | derived |
| `hdr_curve_knee_slope` | `DAT_a8078a5c` | Slope of the linear part below the knee: (knee y << 10) / knee x. | derived |
| `hdr_curve_bezier_scale` | `DAT_a8078a60` | Scale of the Bezier part above the knee: 0x10000000 / (0x1000 - knee x). | derived |
| `hdr10plus_percentile_50` | `DAT_a8078a64` | The 50th percentile brightness found in the HDR10+ percentile list. | derived |
| `hdr10plus_guided_curve_flag` | `DAT_a8078a68` | When set, the tone curve parameters are computed again from the luminance values. | descriptive |
| `hdr10plus_use_scene_max_flag` | `DAT_a8078a69` | When set (with a scene maximum), the scene luminance comes from maxscl instead of the 99th percentile. | descriptive |
| `hdr10plus_percentile_99` | `DAT_a8078a6c` | The 99th percentile brightness found in the HDR10+ percentile list. | derived |
| `hdr10plus_default_record` | `DAT_a8078a70` | Default HDR10+ metadata loaded when the HDR10+ service starts. | derived |
| `hdr10plus_panel_peak_x10` | `DAT_a8078a90` | Panel peak luminance x 10, the brightness limit passed to the HDR10+ curve build. | derived |
| `hdr10plus_metadata` | `DAT_a8078aa0` | The HDR10+ dynamic metadata of the incoming signal. | proven |
| `hdr10plus_metadata_knee_y` | `DAT_a8078aa4` | Knee point y of the HDR10+ metadata (field +4). | derived |
| `audio_dp_32k_mode` | `DAT_a8078b30` | Byte kept by the DP 32 kHz switch and the audio routing. | descriptive |
| `audio_dp_resync_flag` | `DAT_a8078b31` | Set to request a fresh FIFO set-up of a DP audio source. | derived |
| `audio_dp_stable_counts` | `DAT_a8078b38` | Per-source count used to wait until DP audio is stable before unmuting. | descriptive |
| `audio_dp_last_mauds` | `ARR_a8078b3c` | One word per DP receiver: the Maud value kept when its audio was last found changed. | derived |
| `audio_dp_unmute_flags` | `DAT_a8078b48` | Per-source flag bytes of the DP audio unmute check. | descriptive |
| `audio_dp_status_ticks` | `DAT_a8078b4c` | Per-receiver time stamps of the DP audio status sampling. | descriptive |
| `audio_dp_fifo_muted_flag` | `DAT_a8078b54` | Set while the DP audio FIFO is muted. | derived |
| `dsc_enc_configured_flag` | `DAT_a8078b58` | Byte set by the encoder configuration. | descriptive |
| `hdcp_tx_timers` | `ARR_a8078b60` | 15 countdown timers (words, in ticks) of the output copy-protection state machines. | derived |
| `hdcp_tx_task_flags` | `DAT_a8078ba0` | Per-output bytes of the copy-protection service. | descriptive |
| `hdcp_tx_task_ticks` | `DAT_a8078ba4` | Per-output words of the copy-protection service. | descriptive |
| `hdcp_tx_records` | `DAT_a8078bb0` | State of the copy-protection handshake on each video output (3 x 24 bytes). | proven |
| `hdcp_tx_timer_last_ticks` | `_DAT_a8078bf8` | Tick count at the last copy-protection timer update. | derived |
| `sys_otp_shared_loaded_flag` | `DAT_a8078c00` | Set once factory data records 12..16 are in shared memory; published as a status flag. | derived |
| `sys_otp_patch_found_index` | `DAT_a8078c01` | Index of the patch entry found last. | derived |
| `sys_otp_patch_count` | `DAT_a8078c02` | Number of entries in the address patch table. | derived |
| `hdmi_port1_double_flag` | `DAT_a8078c08` | Horizontal doubling flag of HDMI receiver 1. | derived |
| `audio_hdmi_rate_check_ticks` | `DAT_a8078c0c` | Per-receiver time stamp of the 40-tick audio rate check. | derived |
| `audio_hdmi_rate_valid_flags` | `DAT_a8078c18` | Per-receiver result of the audio rate range check. | derived |
| `hdr_last_update_ticks` | `_DAT_a8078c20` | Tick count of the last HDR curve update (next one after 200 ticks). | derived |
| `hdr_task_byte` | `DAT_a8078c24` | Byte written by the HDR curve service. | descriptive |
| `hdr_tmo_enabled_flag` | `DAT_a8078c25` | Set while the tone-mapping stages are switched on. | derived |
| `hdr_tmo_second_enabled_flag` | `DAT_a8078c26` | Set while the second tone-mapping set is switched on. | derived |
| `hdr_last_meta_half` | `DAT_a8078c28` | Halfword metadata value stored for change detection. | descriptive |
| `hdr_last_meta_word` | `DAT_a8078c2c` | Word metadata value stored for change detection. | descriptive |
| `hdr_option_byte` | `DAT_a8078c30` | HDR option byte: bit 3 = load the tone curve, bit 2 = use the alternate curve. | derived |
| `hdr_enable` | `DAT_a8078c31` | On/off switch of the HDR curve service. | derived |
| `hdr_mode_byte` | `DAT_a8078c33` | HDR mode byte from the main processor. | derived |
| `hdr_settings_changed_flag` | `DAT_a8078c34` | Set when an HDR setting or the metadata changed, so the curve is rebuilt. | derived |
| `hdr_source_active_flag` | `DAT_a8078c35` | Set while the current source is HDR-active; shown in the port status flags. | derived |
| `hdr_source_disable_bits` | `DAT_a8078c36` | One bit per source; a set bit switches HDR processing off for that source. | derived |
| `hdr_source` | `DAT_a8078c37` | The source that the HDR service follows. | derived |
| `hdr_status_code` | `DAT_a8078c38` | HDR status code reported to the main processor. | derived |
| `hdr_eotf_mode` | `DAT_a8078c39` | The EOTF mode 3..7 set by hdr_update_tone_curve from the mastering luminance range. | proven |
| `hdr_level_index` | `_DAT_a8078c3c` | Index into the level tables computed in the level update. | descriptive |
| `hdr_level_target` | `_DAT_a8078c40` | Target level: smoothed level times the scale percent / 100. | derived |
| `hdr_tmo_gain_copy_start` | `DAT_a8078c44` | First gain table index copied into hdr_tmo_gain_sums (0x10E, 0x13B, 0x15B or 0x1A9 by mode). | derived |
| `hdmi_tx_sink_flags` | `DAT_a8078c48` | Per HDMI output a flag set by the hot-plug check; published as status bits 3 and 4. | derived |
| `hdmi_tx_sink_flag_port1` | `DAT_a8078c49` | Byte 1 of hdmi_tx_sink_flags: the flag of HDMI output 1, published as status bit 4. | derived |
| `hdmi_tx_last_hotplug_states` | `DAT_a8078c50` | Hot-plug state of each HDMI output seen at the last check. | derived |
| `hdcp_rx_restart_bits` | `DAT_a8078c58` | Bit per input set by an input event; the protection state machines then go back to state 9. | derived |
| `hdcp_tx_dp_bypass_flag` | `DAT_a8078c5a` | Set when the DisplayPort output protection runs in bypass (bit 6 of its control register). | derived |
| `hdcp_rx_status_mask` | `DAT_a8078c5b` | Bit per input for its protection status; shown as flag 0x20 in the port records. | derived |
| `hdcp_rx_init_flag` | `DAT_a8078c5c` | Flag set by the input protection set-up; published as status bit 1. | descriptive |
| `hdcp_repeater_counters` | `DAT_a8078c60` | Per-input counter written to the input registers by the repeater report and the event writer. | descriptive |
| `hdcp_repeater_device_sum` | `DAT_a8078c78` | Sum of the downstream device counts reported by the repeater. | derived |
| `hdcp_rx_hdmi_watch_bytes` | `DAT_a8078c80` | Per-input bytes of the rate-limited counter check of the HDMI 2.0 inputs. | descriptive |
| `hdcp_rx_hdmi21_watch_bytes` | `DAT_a8078c88` | Per-input bytes of the rate-limited counter check of the HDMI 2.1 inputs. | descriptive |
| `hdcp_rx_port_state_bytes` | `DAT_a8078c90` | Protection state byte of each input. | derived |
| `hdcp_rx_port_status_ticks` | `DAT_a8078c98` | Time stamp of the last protection status change of each input, for the time-out. | derived |
| `hdcp_rx_hdmi_task_byte` | `DAT_a8078cb0` | Byte cleared by the HDMI input protection state machines when they restart. | descriptive |
| `hdcp_rx_key_buffer` | `DAT_a8078cb8` | Buffer filled by the long table exchange and used by the key preparation steps. | descriptive |
| `hdcp_tx_engine_table_mode0` | `DAT_a8078d38` | Table prepared by the key steps and sent to the protection engine in mode 0. | derived |
| `hdcp_rx_engine_result_buffer` | `DAT_a8078eb8` | 128-byte buffer for the engine result read in the key preparation sequence (64 pairs, last pair first). | derived |
| `hdcp_rx_engine_result_tables` | `DAT_a8078eb9` | Bytes 1..127 of the engine result buffer: a 32-byte table followed by a 95-byte table. | derived |
| `hdmi_task_period` | `DAT_a8079038` | Period given to the equaliser detect task and to the two HDMI 2.1 receiver timers. | derived |
| `hdmi_rx21_frl_init_flags` | `DAT_a8079040` | Per-port bytes of the FRL start and payload states of mode detection. | descriptive |
| `hdmi_rx21_frl_lock_flags` | `DAT_a8079048` | Per-port bytes of the FRL start and lock check states of mode detection. | descriptive |
| `hdmi_rx21_modedet_stable_flags` | `DAT_a8079050` | Per-port bytes set at the end of mode detection and by the stable watch. | descriptive |
| `hdmi_rx21_ltp_force_pass` | `DAT_a8079052` | Debug switch "LTP force pass": the link training error checks are skipped while set. | derived |
| `hdmi_rx21_error_counters` | `DAT_a8079054` | Error counter of each HDMI 2.1 receiver used by the LTS_L state. | derived |
| `hdmi_rx21_lane_freqs` | `ARR_a807905a` | Measured lane frequency values, four halfwords per HDMI 2.1 receiver. | proven |
| `hdmi_rx21_ltp_end_ticks` | `DAT_a807906c` | Per receiver: tick count taken when the link training pattern phase ends (printed as 'e:'). | proven |
| `hdmi_rx21_ltp_timer_ticks` | `DAT_a8079074` | Per-port start time of the link training pattern timer. | derived |
| `hdmi_rx21_ltsp_rs_fails` | `DAT_a8079080` | Per receiver: failed RS checks in a row in link training state LTS:P; more than 5 count as a pass. | proven |
| `hdmi_rx21_ltsp_wait_passes` | `DAT_a8079082` | Per receiver: passes of LTS:P with FLT_Update still set; 300 end the wait with a message. | proven |
| `hdmi_rx21_lts3_halves` | `DAT_a8079086` | Per-port halfwords of link training state 3. | descriptive |
| `hdmi_rx21_lts_error_halves` | `DAT_a807908a` | Per-port halfwords of link training state 3 and the error check. | descriptive |
| `hdmi_rx21_frl_payload_bytes` | `DAT_a8079090` | Per-port bytes of the FRL payload check of mode detection. | descriptive |
| `hdmi_rx21_frl_payload_words` | `DAT_a8079094` | Per-port words of the FRL payload check of mode detection. | descriptive |
| `hdmi_rx21_frl_payload_ticks` | `DAT_a807909c` | Per-port words set by the FRL start and payload states and read by the lock check. | descriptive |
| `hdmi_rx21_two_port_mode_flags` | `DAT_a80790a8` | Per-receiver byte set by FRL_PLL (1 for a high target) and printed as '2PortMode'; shifts the timing values. | proven |
| `hdmi_rx21_vrr_was_on_flags` | `DAT_a80790b0` | Per HDMI 2.1 receiver: 1 when the record's VRR flags byte was non-zero at the last look. | derived |
| `hdmi_rx21_stable_watch_bytes` | `DAT_a80790b8` | Per-port bytes of the stable-input watch. | descriptive |
| `hdmi_rx21_eq_wait_bytes` | `DAT_a80790c8` | Per-port bytes of the wait for the end of EQ tuning. | descriptive |
| `hdmi_rx21_frl_rate_restart_requests` | `ARR_a80790d0` | One byte per HDMI 2.1 receiver: 1 asks the link training runner to restart at LTS_3 after a rate change. | derived |
| `hdmi_rx21_frl_rate_change_flags` | `DAT_a80790d8` | Per-port flag of an FRL rate change after link training. | derived |
| `hdmi_rx21_standby_fail_counts` | `DAT_a80790e0` | Per receiver: unstable passes of the standby state; the second one switches the PHY to only-scramble guessing. | derived |
| `hdmi_rx21_stable_watch_words` | `DAT_a80790e4` | Per-port words of the stable-input watch. | descriptive |
| `hdmi_rx21_stable_watch_ticks` | `DAT_a80790ec` | Per-port words of the stable-input watch. | descriptive |
| `hdmi_rx21_mode_detect_timer` | `DAT_a80790f4` | Timer descriptor of the HDMI 2.1 mode-detect state machine. | proven |
| `hdmi_rx21_rx_detect_timer` | `DAT_a8079100` | Timer descriptor of the HDMI 2.1 link-training state machine. | proven |
| `hdmi_rx21_port_started_flags` | `ARR_a8079110` | One byte per HDMI 2.1 receiver: 1 after hdmi_rx21_start_port, 0 after hdmi_rx21_stop_port; 0 = skipped. | derived |
| `hdmi_rx21_event_callbacks_6` | `DAT_a8079118` | Callback table of one packet-event group of the HDMI 2.1 receivers. | descriptive |
| `hdmi_rx21_event_callbacks_7` | `DAT_a8079138` | Callback table of one packet-event group of the HDMI 2.1 receivers. | descriptive |
| `hdmi_rx21_event_callbacks_8` | `DAT_a8079158` | Callback table of one packet-event group of the HDMI 2.1 receivers. | descriptive |
| `hdmi_rx21_sync_event_bytes` | `DAT_a8079178` | Per-port bytes of the sync event handler. | descriptive |
| `hdmi_rx21_sync_event_flags` | `DAT_a8079180` | Per-port bytes of the sync event handler. | descriptive |
| `hdmi_rx21_sync_event_words` | `DAT_a8079184` | Per-port event word of the HDMI 2.1 sync event handler. | derived |
| `hdmi_rx21_bit9_done_flag` | `DAT_a807918e` | Flag set after control bit 9 of an HDMI 2.1 receiver was pulsed. | descriptive |
| `hdmi_rx21_init_done_flag` | `DAT_a8079192` | Set once the HDMI 2.1 receiver driver has been initialised. | derived |
| `audio_hdmi21_rate_check_ticks` | `DAT_a8079194` | Per-receiver time stamp of the 40-tick HDMI 2.1 audio rate check. | derived |
| `audio_hdmi21_rate_valid_flags` | `DAT_a80791a0` | Per-receiver result of the HDMI 2.1 audio rate range check. | derived |
| `hdmi_tx_flt_no_timeout_flags` | `ARR_a80791a8` | Per HDMI output: the FLT_no_timeout bit (bit 5) last read from the sink's SCDC register 0x35. | proven |
| `hdmi_tx_frl_rate_byte` | `DAT_a80791aa` | FRL rate byte of the HDMI TX training: cleared at the start and for TMDS, written in LTS:2. | descriptive |
| `hdmi_tx_frl_video_flags` | `DAT_a80791b0` | Per-port flag tested by LTS:P before FRL video is started. | descriptive |
| `hdmi_tx_frl_sink_check_flag` | `DAT_a80791b2` | 0 = LTS:1 takes the FRL rate without the three sink checks (rate 5 for a sink rate of 0). Only read. | descriptive |
| `hdmi_tx_sink_dsc_flags` | `DAT_a80791b8` | DSC capability byte of the sink HF-VSDB of each HDMI output. | derived |
| `hdmi_tx_sink_dsc_max_slices` | `DAT_a80791c0` | DSC_MaxSlices field (low nibble) of the sink HF-VSDB of each HDMI output. | derived |
| `hdmi_tx_sink_dsc_max_frl` | `DAT_a80791c8` | DSC_Max_FRL_Rate field (high nibble) of the sink HF-VSDB of each HDMI output. | derived |
| `hdmi_tx_lts1_results` | `DAT_a80791d0` | Per-port result of the SCDC read in LTS:1 of the HDMI TX FRL training. | descriptive |
| `hdmi_tx_sink_max_frl` | `DAT_a80791d8` | Max_FRL_Rate field of the sink HF-VSDB of each HDMI output. | derived |
| `hdmi_tx_sink_scdc_present` | `DAT_a80791e0` | SCDC_Present bit of the sink HF-VSDB of each HDMI output. | derived |
| `hdmi_tx_txffe_mode` | `DAT_a80791e2` | The TxFFE mode chosen from the sink's SCDC register 0x35 and passed to hdmi_tx_set_txffe_mode. | derived |
| `hdmi_tx_frl_step_bytes` | `DAT_a80791e8` | Per-port bytes cleared and set by the HDMI TX FRL training states. | descriptive |
| `hdmi_tx_ffe_levels` | `DAT_a80791f0` | TxFFE level index of each HDMI output. | derived |
| `hdmi_tx_ffe_max_levels` | `ARR_a80791f4` | Per HDMI output: the highest TxFFE level index the training may step to (the texts call it FFE_Max). | derived |
| `hdmi_tx_frl_rates` | `DAT_a80791fc` | FRL rate chosen for each HDMI output (at most 6). | derived |
| `hdmi_tx_frl_done_flags` | `DAT_a8079208` | Per-port byte cleared at the training start and in LTS:P. | descriptive |
| `hdmi_tx_frl_link_flags` | `DAT_a8079210` | Per-port copy of bit 1 of HDMI TX register 9, read by the training runner. | descriptive |
| `hdmi_tx_frl_timer_init_period` | `_DAT_a8079214` | Period that hdmi_tx_frl_init_timer copies into the FRL training timer descriptor. | derived |
| `hdmi_tx_frl_timer` | `DAT_a8079218` | Timer descriptor of the HDMI TX FRL training. | proven |
| `sys_dsc_dec_command_value` | `DAT_a8079228` | Value sent with command 0x74 for the DSC decoder state machine. | derived |
| `sys_dsc_dec_init_flag` | `DAT_a8079229` | Set once the DSC decoder has been initialised. | derived |
| `sys_dsc_dec_dp_start_ticks` | `DAT_a807922c` | Tick count taken when the DSC decoder started a DisplayPort stream. | derived |
| `sys_dsc_dec_dp_check_pending` | `DAT_a8079230` | 1 from the start of a DisplayPort stream until the first check after the wait. | derived |
| `sys_dsc_dec_hdmi21_build_ticks` | `DAT_a8079234` | Per DSC decoder: tick count taken when the HDMI 2.1 set-up record was built. | derived |
| `sys_dsc_dec_hdmi21_configs` | `DAT_a8079238` | Per DSC decoder: the 0x50-byte set-up record built for an HDMI 2.1 source. | derived |
| `sys_dsc_dec_reg_ratios` | `DAT_a8079288` | Per DSC decoder: the result byte of sys_dsc_dec_calc_reg_ratio. | derived |
| `hdmi_tx_packet_state` | `DAT_a8079290` | Packet forwarding state and per-output packet selections of the HDMI outputs. | derived |
| `dp_tx_drive_level_records` | `DAT_a80792b4` | 16-byte record per DP output with the base swing and pre-emphasis of its lanes. | derived |
| `dp_tx_ctl_init_byte` | `DAT_a8079304` | Byte written by the start-up of a DP / eDP transmitter control bank. | descriptive |
| `dp_dsc_4_slices_option` | `DAT_a8079308` | The 'DSC 3440 4 slices' option byte: 1 changes two values of the DP receiver register set-up. | proven |
| `dp_block_event_handled_flags` | `ARR_a8079310` | Per DP port: 1 after dp_handle_block_event ran; cleared when the link goes stable or DSC goes on. | derived |
| `dp_port_pending_bits` | `DAT_a8079312` | Pending bit of each DP port. | derived |
| `dp_service_flag` | `DAT_a8079313` | Service flag; the pending bits are refreshed while it is set. | derived |
| `dp_port_flag_bits` | `DAT_a8079314` | DP port flag byte, one bit per port; picks the way a receiver unit restarts. | derived |
| `dp_service_block_byte` | `DAT_a8079315` | Byte updated by the service block set-up. | descriptive |
| `dp_hpd_pulse_flag` | `DAT_a8079316` | Flag cleared by the HPD block pulse and tested by the service readiness check. | descriptive |
| `dp_rate_divider` | `DAT_a807931a` | Divisor of 48000 written to DP receiver registers 0x26..0x2C. | derived |
| `dp_fec_ready_state` | `DAT_a807931c` | Last FEC-ready state of the DP receiver. | derived |
| `dp_pixel_clocks` | `DAT_a8079320` | Pixel clock value of each DP port. | derived |
| `dp_stream_clock_check_word` | `_DAT_a8079328` | Word written by the stream clock check. | descriptive |
| `dp_range_check_ticks` | `DAT_a807932c` | Per-port time stamp of the range flag update (at most once per 40 ticks). | derived |
| `dp_range_flags` | `DAT_a8079338` | Range flag of each DP port. | derived |
| `dp_stream_start_count` | `DAT_a807933a` | Counter of the stream start; selects the value written to register 0x485. | derived |
| `dp_lcnt_check_start_ticks` | `DAT_a807933c` | Per DisplayPort receiver: time the LCnt check was started; the check ends after its time limit. | derived |
| `dp_lcnt_check_hold_ticks` | `DAT_a8079344` | Per DisplayPort receiver: time of the check start or the last pending bit; LCnt steps wait 1500 ticks. | derived |
| `dp_lcnt_check_trained_ticks` | `DAT_a807934c` | Per DisplayPort receiver: time the link was last seen trained during the LCnt check (or LCnt last stepped). | derived |
| `dp_lcnt_check_reg44_clear_ticks` | `DAT_a8079354` | Per DisplayPort receiver: time the link was last seen trained with register 0x44 bits 0..1 clear. | descriptive |
| `dp_lcnt_check_running_flags` | `DAT_a8079360` | Per DisplayPort receiver: 1 while the LCnt check of dp_port_task runs. | derived |
| `dp_lcnt_check_settings` | `DAT_a8079368` | Per DisplayPort receiver: the setting byte (input record +0x125 or +0x129) dp_port_task saw last. | derived |
| `dp_last_phy_test_requests` | `DAT_a8079370` | Per DisplayPort receiver: last value read from receiver register 0x256 (bit 7 = 'DPCD 270 start phy test'). | derived |
| `dp_reset_byte` | `DAT_a8079372` | Byte written by the DP input reset. | descriptive |
| `irq_level12_handlers` | `DAT_a8079378` | Handler routines of the two sources of interrupt level 12. | derived |
| `timer_tick_isr_count` | `DAT_a807939c` | Count of tick interrupts. | derived |
| `timer_sleep_countdown` | `DAT_a80793a0` | Down-counter that the tick interrupt counts towards 0. | derived |
| `timer_tick_record` | `DAT_a80793a4` | Tick record: words, the tick count, the tick hooks and the task timers. | derived |
| `timer_tick_count` | `_DAT_a80793a8` | The tick count of the input processor. | proven |
| `sys_task_table` | `DAT_a80793b8` | The sixteen timed tasks. | proven |
| `dsc_encoder_record` | `DAT_a8079538` | The timing values from which the settings of the compression encoder are computed. | proven |
| `dsc_encoder_record_source` | `DAT_a807953d` | Source of the compression encoder: 0 DISP, 2 P2, 3 P3 (dsc_encoder_record + 5). | proven |
| `dsc_encoder_record_height` | `DAT_a807954a` | Picture height in the encoder timing record (dsc_encoder_record + 0x12). | derived |
| `dsc_enc_pps_words` | `DAT_a807955c` | The 27 packed rate-control and parameter words of the encoder; words 0..23 also fill the PPS packet. | derived |
| `dp_mst_payload_counts` | `DAT_a80795d0` | Number of time slots of each of the four streams found in the payload table. | proven |
| `dp_mst_payload_ids` | `DAT_a80795d8` | Payload id of each of the four streams found in the payload table. | proven |
| `dp_status_copy_rows` | `ARR_a80795dc` | Rows of 0x30 bytes that the port 0 interrupt copies from registers 0xE60 and following. | descriptive |
| `dp_mst_payload_removed_start` | `DAT_a807963c` | First time slot of the stream taken out by the last removal, sent to the output with it. | derived |
| `dp_mst_chunk_rings` | `ARR_a807963d` | Per DP input: ring of 16 received chunks of 0x30 bytes, filled from registers 0xE00.. by the interrupt. | derived |
| `dp_mst_last_request_numbers` | `ARR_a8079c3d` | Request number of the last request, by low header nibble * 2 + sequence bit; replies are checked against it. | derived |
| `dp_mst_reply_step_bytes` | `DAT_a8079c48` | Per-port bytes of the down-reply sender. | descriptive |
| `dp_mst_up_message_kinds` | `DAT_a8079c50` | Kind of each of the 16 messages fetched from the output: 0 = down reply (0x1400), 1 = up request (0x1600). | derived |
| `dp_mst_payload_removed_id` | `DAT_a8079c61` | Payload id of the stream taken out by the last removal, sent to the output with slot count 0. | derived |
| `dp_mst_reply_chunk_rows` | `DAT_a8079c62` | Per-port ring of 16-byte down-reply chunk entries. | derived |
| `dp_mst_forward_messages` | `DAT_a8079c88` | Assembled down requests waiting to be forwarded to the output. | derived |
| `dp_mst_up_message_rows` | `ARR_a8079c98` | 16 rows of 0x30 bytes: messages fetched from the output (down replies, up requests) for the source. | derived |
| `dp_mst_reply_bodies` | `DAT_a8079f98` | Body of the outgoing down reply of each port (0x200 bytes). | derived |
| `dp_mst_reply_header_entries` | `ARR_a807a398` | Per port 16 entries of 11 bytes: the packed headers of the down replies waiting to be sent. | derived |
| `dp_mst_reply_headers` | `DAT_a807a4f8` | Per-port 16-byte rows read when a down reply is built and sent. | descriptive |
| `dp_mst_notify_ticks` | `DAT_a807a518` | Time stamp of the MST notification sequence, for its time-out. | descriptive |
| `dp_mst_forward_rows` | `ARR_a807a520` | Forward ring: 16 rows of 0x30 bytes, packed header and body of the down requests waiting to go to the output. | derived |
| `dp_mst_payload_starts` | `DAT_a807a820` | First time slot of each of the four streams found in the payload table. | proven |
| `input_port_records` | `DAT_a807a824` | One record per input stream: link state and the flags published to the main processor (9 x 20 bytes). | proven |
| `ipc_command_0x76_low` | `DAT_a807a8f6` | Low halfword of the value of command 0x76. | descriptive |
| `ipc_command_0x76_high` | `DAT_a807a8f8` | High halfword of the value of command 0x76. | descriptive |
| `hdmi_tx_requests` | `ARR_a807a8fc` | 20-byte request record per HDMI output, filled by commands of the main program and applied to the output. | derived |
| `dp_reg3d0_value` | `DAT_a807a924` | Value of DP receiver register 0x3D0 read for command 0x7C. | derived |
| `dp_tx_path_records` | `ARR_a807a928` | 40-byte records, one per video path: mode bits in word 0, source code at +1, option word at +0x20. | descriptive |
| `hdmi_eq_port_records` | `ARR_a807a9f0` | 0x898-byte EQ work record per HDMI PHY (the firmware's port_EQ); byte +0x29 is the printed bch_en_flag. | derived |
| `hdmi_rx21_pre_aeq_r_indexes` | `DAT_a807cc50` | Per lane: index into hdmi_rx21_initial_rct_values used by the pre-AEQ PHY set-up (printed 'PreAEQ_R_Idx'). | proven |
| `hdmi_eq_rct_try_indexes` | `DAT_a807cc58` | Per-channel index into hdmi_eq_initial_rct_values. | derived |
| `hdmi_rx21_pre_aeq_c_indexes` | `DAT_a807cc60` | Per lane: index into hdmi_rx21_initial_cft_values used by the pre-AEQ PHY set-up (printed as 'AEQ_C'). | derived |
| `hdmi_phy_records` | `ARR_a807cc64` | 24-byte record per HDMI PHY: power flag, EQ done, EQ reset request, option byte (+7), PHY clock in MHz (+8). | derived |
| `hdmi_eq_scan_records` | `ARR_a807ccc4` | 12-byte EQ scan record per HDMI PHY: word 0 = scan state, byte 7 = the printed 'Check Error Round'. | derived |
| `hdmi_eq_cft_try_indexes` | `DAT_a807ccf8` | Per-channel index into hdmi_eq_initial_cft_values. | derived |
| `dp_tx_limits_others` | `DAT_a807cd00` | Limit pair shared by the DP outputs other than 0: byte 0 = highest link rate code, byte 1 = lane count. | derived |
| `dp_tx_link_option_port0` | `DAT_a807cd02` | Link option byte of DP output 0. | derived |
| `dp_tx_pacing_records` | `DAT_a807cd04` | 8-byte pacing record of each DP output (byte 0 = update enabled). | derived |
| `dp_tx_link_option_others` | `DAT_a807cd2c` | Link option byte of the DP outputs other than 0. | derived |
| `dp_tx_lane_route_byte` | `DAT_a807cd2d` | Byte from command 0x5E used for the lane selection of a DP output path. | descriptive |
| `dp_tx_sink_caps_records` | `ARR_a807cd2e` | 6-byte record per DP output read from the sink: flags, revision, top rate code, top lane count, wait value. | derived |
| `dp_tx_aux_reply_bytes` | `DAT_a807cd50` | The AUX reply bytes collected by the reply reader. | derived |
| `dp_tx_limits_port0` | `DAT_a807cd68` | Limit pair of DP output 0: byte 0 = highest link rate code, byte 1 = highest lane count. | derived |
| `hdr_bezier_weights_ptr` | `DAT_a807cd6c` | Points to the hdr_bezier_weights table of the current curve order. | derived |
| `hdr_meta_reg_write_fn` | `DAT_a807cd70` | Register write routine of the receiver selected for HDR10+ metadata. | derived |
| `hdr_meta_reg_read_fn` | `DAT_a807cd74` | Register read routine of the receiver selected for HDR10+ metadata. | derived |
| `hdr_meta_reg_modify_fn` | `DAT_a807cd78` | Register bit-update routine of the receiver selected for HDR10+ metadata. | derived |
| `hdr_meta_reg_write_fn_copy` | `DAT_a807cd7c` | Second copy of the register write routine of the HDR10+ metadata receiver. | derived |
| `audio_mute_value` | `DAT_a807cd80` | Mute value of command 0x91 (audio mute). | derived |
| `hdcp_tx_work_block` | `DAT_a807cd88` | 32-byte work block of the output protection handshake. | derived |
| `hdcp_tx_ksv_table` | `DAT_a807cda8` | Stored 5-byte key-selection value of each of the three outputs. | derived |
| `hdcp_tx_exchange_buffer` | `DAT_a807cdb8` | Buffer of the two-round table exchange with the engine. | descriptive |
| `hdcp_tx_receiver_ids` | `DAT_a807ce38` | Receiver id (5 bytes) of each output. | derived |
| `hdcp_tx_message_tail` | `DAT_a807ce48` | Three bytes copied from the end of a received message. | descriptive |
| `hdcp_tx_message_buffer` | `DAT_a807ce50` | Buffer of the message read from or sent to the receiver. | derived |
| `hdcp_tx_message_body` | `DAT_a807ce56` | Message buffer from byte 6, handed to the engine by the DP result compare. | descriptive |
| `hdcp_tx_engine_buffer` | `DAT_a807cf08` | The 0x180-byte buffer sent to the protection engine (last byte = mode). | derived |
| `hdcp_tx_result_block` | `DAT_a807d088` | The 32 result bytes read back from the protection engine. | derived |
| `hdcp_tx_retry_ticks` | `DAT_a807d0a8` | Per-output time compared with the tick count before a handshake restart. | descriptive |
| `hdcp_tx_repeater_v` | `DAT_a807d238` | The repeater's 20-byte check value read from registers 0x20..0x21D. | derived |
| `hdcp_tx_status_bytes` | `DAT_a807d250` | Status bytes of the output handshake read by the HDMI state handlers. | descriptive |
| `sys_otp_patch_table` | `DAT_a807d252` | Address patch table loaded from the one-time-programmable store (rows of 10 halfwords). | derived |
| `sys_otp_local_group0` | `DAT_a807d27a` | First group of factory data records loaded into local tables. | descriptive |
| `sys_otp_dp_tx_phy_options` | `DAT_a807d289` | Stored PHY option byte of each DP output, from the factory data. | derived |
| `hdmi_phy_trim_port0` | `DAT_a807d299` | Trim and calibration byte record of HDMI port 0. | derived |
| `hdmi_phy_trim_port1` | `DAT_a807d2a9` | Trim and calibration byte record of HDMI port 1. | derived |
| `hdmi_phy_trim_port2` | `DAT_a807d2b9` | Trim and calibration byte record of HDMI port 2. | derived |
| `hdmi_phy_trim_port3` | `DAT_a807d2e9` | Trim and calibration byte record of HDMI port 3. | derived |
| `dp_stored_settings_port0` | `DAT_a807d319` | Stored settings record applied to DP receiver 0. | descriptive |
| `dp_stored_settings_port1` | `DAT_a807d369` | Stored settings record applied to DP receiver 1. | descriptive |
| `dp_tx_phy_dptx_option` | `DAT_a807d3b9` | Stored option byte written to register 0x37 of the DPTX PHY unit. | derived |
| `hdmi_tx_reg0c_trims` | `DAT_a807d3c1` | Calibration values for HDMI TX register 0x0C (default 0x0C). | derived |
| `dp_tx_phy_edp_options` | `DAT_a807d3d1` | Stored option bytes for registers 0x3D/0x60/0x83/0xA6 of the eDP PHY unit. | derived |
| `hdmi_rx_records` | `ARR_a807d3e4` | 0xB0-byte record per HDMI 2.0 receiver: copies of the received packets, restart hint, AVI capture time. | derived |
| `hdr_mastering_luminance` | `DAT_a807d544` | Mastering luminance from which the static curve parameters were derived. | derived |
| `hdr_static_info` | `DAT_a807d548` | Static HDR information of the current source (three metadata values and status). | derived |
| `hdr_static_info_eotf_type` | `_DAT_a807d54c` | Word +4 of the static HDR information: the EOTF type 0..3 (printed as g_HDR_Info.enEOTF_Type). | proven |
| `hdr_static_status_byte` | `DAT_a807d54f` | Byte +7 of the static HDR information, returned as the HDR status code. | descriptive |
| `hdmi_tx_output_records` | `ARR_a807d580` | 28-byte record per HDMI output: flag word (bit 4 FRL mode, bit 7 hsync polarity), FRL rate at +0x15. | derived |
| `hdmi_tx_audio_reg_reader` | `_DAT_a807d5b8` | Register read routine of the HDMI input that feeds the audio of an HDMI output. | derived |
| `hdcp_rx_port_bytes` | `DAT_a807d5c0` | Per-input bytes cleared by the input protection reset. | descriptive |
| `hdcp_rx_hdmi_key_state` | `DAT_a807d5c6` | Key preparation state of the HDMI 2.0 inputs (0xFF after reset). | descriptive |
| `hdcp_rx_record_hdmi20` | `DAT_a807d5c8` | State of the copy-protection handshake on the HDMI 2.0 inputs. | proven |
| `hdcp_rx_record_hdmi21` | `DAT_a807d5e8` | State of the copy-protection handshake on the HDMI 2.1 inputs. | proven |
| `hdcp_rx_record_dp` | `DAT_a807d608` | State of the copy-protection handshake on the DisplayPort inputs. | proven |
| `hdcp_use_builtin_tables_flag` | `DAT_a807d628` | Set when the built-in 128-byte tables are sent to the engine instead of stored ones. | derived |
| `hdcp_rx_hdmi21_key_state` | `DAT_a807d629` | Key preparation state of the HDMI 2.1 inputs (0xFF after reset). | descriptive |
| `hdcp_repeater_report_flag` | `DAT_a807d62a` | Flag set by the repeater status collection and report. | descriptive |
| `hdcp_rx_dp_key_state` | `DAT_a807d62b` | Key preparation state of the DisplayPort inputs (0xFF after reset). | descriptive |
| `hdcp_use_builtin_table384_flag` | `DAT_a807d62c` | Set when the built-in 384-byte engine table is used instead of the stored one. | derived |
| `hdcp_rx_port_flags` | `DAT_a807d630` | Per-input flags cleared by the input protection reset. | descriptive |
| `hdcp_owner_byte` | `DAT_a807d636` | Owner byte of the protection engine, checked before an output handshake starts. | descriptive |
| `hdcp_stored_key_header` | `DAT_a807d638` | The 0x24 bytes read from address 0x590 of the key store at start-up. | derived |
| `hdmi_rx21_rx_detect_states` | `DAT_a807d648` | Link-training state word of each HDMI 2.1 receiver. | proven |
| `hdmi_rx21_mode_detect_states` | `DAT_a807d650` | Mode-detect state of each HDMI 2.1 receiver. | proven |
| `hdmi_rx21_lts_records` | `ARR_a807d680` | 0xB0-byte link training record per HDMI 2.1 receiver: FRL rate, TxFFE_Max_L at +0x13, last printed state. | derived |
| `hdmi_rx21_lts_record0_byte1` | `DAT_a807d681` | Byte 1 of the link training record of HDMI 2.1 receiver 0, sent in a command reply. | descriptive |
| `hdmi_rx21_lts_record1_byte1` | `DAT_a807d731` | Byte 1 of the link training record of HDMI 2.1 receiver 1, sent in a command reply. | descriptive |
| `hdmi_rx21_input_records` | `ARR_a807d7e0` | 400-byte record per HDMI 2.1 receiver: mode information and packet data (colour format at +0x50). | derived |
| `hdmi_rx21_input_record0_mode_detected` | `DAT_a807d7e1` | Mode-detected byte (+1) of the HDMI 2.1 input record of receiver 0. | derived |
| `hdmi_rx21_input_record0_dsc` | `DAT_a807d80d` | CVTEM / DSC byte (+0x2D) of the HDMI 2.1 input record of receiver 0. | derived |
| `hdmi_rx21_input_record1_mode_detected` | `DAT_a807d971` | Mode-detected byte (+1) of the HDMI 2.1 input record of receiver 1. | derived |
| `hdmi_rx21_input_record1_dsc` | `DAT_a807d99d` | CVTEM / DSC byte (+0x2D) of the HDMI 2.1 input record of receiver 1. | derived |
| `hdmi_rx21_reg_blocks` | `ARR_a807db00` | Per HDMI 2.1 receiver: the addresses of its 13 register blocks (0x34 bytes per receiver). | derived |
| `hdmi_rx21_reg_blocks_rx0_block3` | `_DAT_a807db0c` | Word 3 of row 0 of hdmi_rx21_reg_blocks: address of register block 3 (0xCE009300) of HDMI 2.1 receiver 0. | derived |
| `hdmi_rx_if_init_flag` | `DAT_a807db68` | Set once the HDMI receiver interface state has been initialised. | derived |
| `hdmi_tx_frl_states` | `ARR_a807db6c` | FRL link training state of each HDMI output (index of the DRV_HDMI21_TXDetect_FSM_* routines). | proven |
| `sys_dsc_dec_default_config` | `DAT_a807db74` | The 0x90-byte default set-up of the DSC decoder. | derived |
| `sys_dsc_dec_port_configs` | `DAT_a807dbb4` | The 0x90-byte DSC decoder set-up record of each port (checked by a checksum). | derived |
| `sys_dsc_dec_records` | `DAT_a807dc04` | Records of the DSC decoders with their register block pointers. | derived |
| `sys_dsc_dec_record0_block` | `_DAT_a807dc08` | Register block pointer in the first DSC decoder record, read by the clock set-up. | descriptive |
| `sys_dsc_dec_state_records` | `ARR_a807dc10` | 8-byte state record per DSC decoder: state word 0..4, checksum tries at +4, a byte at +5. | derived |
| `dp_input_records` | `ARR_a807dc18` | 300-byte record per DisplayPort input: status bytes, setting bytes +0x110..+0x11F, halfword +0x120. | derived |
| `dp_input_record0_setting_0x112` | `DAT_a807dd2a` | Setting byte +0x112 of the DisplayPort input record of port 0. | descriptive |
| `dp_input_record0_byte_0x11f` | `DAT_a807dd37` | Byte +0x11F of the DisplayPort input record of port 0, tested by the port interrupt work. | descriptive |
| `dp_input_record1_byte_0x11f` | `DAT_a807de63` | Byte +0x11F of the DisplayPort input record of port 1, tested by the port interrupt work. | descriptive |
| `dp_unit_route_bits` | `DAT_a807de70` | Route status bits of the DP receiver units, one per unit a port is mapped to. | derived |
| `dp_init_byte` | `DAT_a807de71` | Byte cleared by the DP input set-up sequence. | descriptive |
| `dp_status_block_bytes` | `DAT_a807de78` | The first 20 status bytes of a DP port read by the status block reader. | derived |
| `timer_div5_count` | `DAT_a807de8c` | Tick counter that raises timer_div5_flag every 5 ticks. | derived |
| `timer_div50_flag` | `DAT_a807de90` | Flag raised every 50 ticks. | derived |
| `timer_div500_flag` | `DAT_a807de91` | Flag raised every 500 ticks. | derived |
| `timer_task_pending_flag` | `DAT_a807de92` | Set by each tick; the task runner clears it. | derived |
| `timer_div500_count` | `DAT_a807de94` | Tick counter that raises timer_div500_flag every 500 ticks. | derived |
| `timer_tick_count_second` | `DAT_a807de98` | Second tick word advanced with the tick count. | descriptive |
| `timer_div5_flag` | `DAT_a807de9c` | Flag raised every 5 ticks. | derived |
| `timer_div50_count` | `DAT_a807dea0` | Tick counter that raises timer_div50_flag every 50 ticks. | derived |
| `dbg_tool_mode_flag` | `DAT_a807dea8` | Set by a "*CB00000" or "{#UTIL#}" line; while set, lines are tool commands (*RD, *WD, *RB, ...). | derived |
| `dbg_line_length` | `_DAT_a807deac` | Length of the line typed on the debug serial port. | derived |
| `dbg_word_count` | `DAT_a807deb0` | Number of words split from the typed debug command line (at most five). | derived |
| `dbg_tool_request` | `DAT_a807deb4` | The decoded tool command (*qt, *RD, *WD, *RB, *WB, *CB): command, address, value and sum. | derived |
| `dbg_hex_mode_flag` | `DAT_a807dec4` | Set by '^' as the first character: the line is then read as hex byte pairs (R, W, U commands). | derived |
| `dbg_tool_address_base` | `_DAT_a807dec8` | Base address of the tool read and write commands, set by *CB to address << 16. | derived |
| `dbg_hex_bytes` | `DAT_a807ded0` | The hex byte pairs of a hex-mode line (at most 32); the first four form the address. | derived |
| `dbg_line_buffer` | `DAT_a807def0` | The line typed on the debug serial port. | derived |
| `dbg_line_words` | `DAT_a807dff0` | The words of the typed command line, five rows of up to 31 characters. | derived |
| `dbg_tool_reply_buffer` | `DAT_a807e090` | Reply text of the tool read command ("#", the word bytes, " OK!#"). | derived |
| `dbg_tool_cb_flag` | `DAT_a807e0b0` | Set by *CB when the address is 0x1000. | descriptive |
