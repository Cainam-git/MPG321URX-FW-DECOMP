# Data names: Main processor (leon2m)

1,177 entries from `symbols/leon2m.data.json`, in address order. The source uses the names through the `#define` lists (see [Function names](../NAMES.md#names-in-the-source)); [Data objects](../DATA.md) describes the principal records. The *basis* column has the same meaning as for the function names.

| Basis | Entries |
|---|---:|
| proven | 343 |
| derived | 603 |
| descriptive | 231 |

## Constant data in the program

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `flash_window` | `DAT_00000000` | The flash memory as the processor sees it from address 0; stored blocks are read from it. | derived |
| `edid_stored_records` | `DAT_00010000` | The stored EDID records in flash, 0x200 bytes each, loaded into the input ports. | derived |
| `nvram_default_records` | `DAT_00020000` | The ROM defaults: the part record at +0x140 and the device settings record at +0x170. | proven |
| `sys_ddr_unit1_n_values_entry` | `DAT_00082588` | Entry of sys_ddr_set_n_adj_det_first, the step hook of the first calibration unit. | proven |
| `sys_ddr_unit2_n_values_entry` | `DAT_0008260c` | Entry of sys_ddr_set_n_adj_det_second, the step hook of the second calibration unit. | proven |
| `sys_ddr_unit3_n_values_entry` | `DAT_00082690` | Entry of sys_ddr_set_n_adj_det_third, the step hook of the third calibration unit. | proven |
| `sys_ddr_unit1_adj_fields_entry` | `DAT_00082714` | Entry of sys_ddr_set_adj_table_fields_first, the setting hook of the first calibration unit. | proven |
| `sys_ddr_unit2_adj_fields_entry` | `DAT_0008285c` | Entry of sys_ddr_set_adj_table_fields_second, the setting hook of the second calibration unit. | proven |
| `sys_ddr_unit3_adj_fields_entry` | `DAT_000829a4` | Entry of sys_ddr_set_adj_table_fields_third, the setting hook of the third calibration unit. | proven |
| `sys_ddr_unit1_idle_wait_entry` | `DAT_00082aec` | Entry of sys_ddr_wait_cal_idle_first, the second measuring hook of the first calibration unit. | proven |
| `sys_ddr_unit2_idle_wait_entry` | `DAT_00082b5c` | Entry of sys_ddr_wait_cal_idle_second, the second measuring hook of the second calibration unit. | proven |
| `sys_ddr_unit3_idle_wait_entry` | `DAT_00082bcc` | Entry of sys_ddr_wait_cal_idle_third, the second measuring hook of the third calibration unit. | proven |
| `sys_ddr_unit1_measure_entry` | `DAT_00082c3c` | Entry of sys_ddr_run_cal_first, the first measuring hook of the first calibration unit. | proven |
| `sys_ddr_unit2_measure_entry` | `DAT_00082cac` | Entry of sys_ddr_run_cal_second, the first measuring hook of the second calibration unit. | proven |
| `sys_ddr_unit3_measure_entry` | `DAT_00082d1c` | Entry of sys_ddr_run_cal_third, the first measuring hook of the third calibration unit. | proven |
| `ldc_hw_mode3_pass_entry` | `DAT_0009a814` | Entry of ldc_hw_run_mode3_pass, registered as the grid block interrupt handler (level 12). | proven |
| `ipc_8051_option_byte_entry` | `DAT_000d3da0` | Entry of ipc_8051_set_option_byte, installed as the picture window item hook. | proven |
| `ipc_8051_cec_registers_entry` | `DAT_000d3ea4` | Entry of ipc_8051_set_cec_registers, installed as the CEC send hook. | proven |
| `libc_cleanup_r_entry` | `DAT_000fb5c4` | Entry of _cleanup_r, stored by __sinit as the clean-up routine of a reentrancy structure. | proven |
| `libc_fp_unlock_entry` | `DAT_000fb75c` | Entry of __fp_unlock, applied to every stream by __fp_unlock_all. | proven |
| `libc_fclose_entry` | `DAT_000fe3ec` | Entry of fclose, applied to every stream by _cleanup_r. | proven |
| `pq_ch1_timing_table` | `DAT_000feb30_mode_table` | 12 rows of 18 bytes that pq_match_ch1_timing_table matches the measured size against. | derived |
| `app_event_actions` | `DAT_000fec08` | The action number of each application event row. | proven |
| `app_event_indexes` | `DAT_000fec40` | For each application event code the row of its action in app_event_actions. | proven |
| `app_ddcci_event_actions` | `DAT_000fec80` | The action number of each DDC/CI event row. | proven |
| `app_ddcci_event_indexes` | `DAT_000fec88` | For each DDC/CI event code the row of its action in app_ddcci_event_actions. | proven |
| `app_osd_event_actions` | `DAT_000fec90` | The action number of each menu event row. | proven |
| `app_osd_event_indexes` | `DAT_000feca8` | For each menu event code the row of its action in app_osd_event_actions. | proven |
| `app_key_event_actions` | `DAT_000fecb0` | The action number of each key event row. | proven |
| `app_key_event_indexes` | `DAT_000fece0` | For each key event code the row of its action in app_key_event_actions. | proven |
| `pq_ace_tables` | `DAT_000ff600` | Four 0x44-byte ACE tables in ROM; one is loaded into channels 1 and 0. | derived |
| `pq_theme_mode_presets` | `DAT_000ff710` | The picture theme presets, 0x20 bytes each: item values and table pointers. | proven |
| `ddc_color_preset_codes` | `DAT_000ffd80` | The VCP 0x14 colour preset value reported for each value of settings byte +0x11. | derived |
| `ddc_capability_string` | `DAT_000ffde0` | The DDC/CI capability string '(prot(monitor)type(lcd)model(FALCON)...' in its first form. | proven |
| `ddc_capability_string_alt` | `DAT_000fff18` | The second form of the DDC/CI capability string, used when the channel port is of type 5. | proven |
| `osd_event_action_numbers` | `DAT_00100060` | The action number of each menu event row; 3 or lower flags the event. | derived |
| `osd_event_action_rows` | `DAT_00100068` | For each menu event code the row in osd_event_action_numbers (4 = none). | derived |
| `osd_factory_menu_layout` | `DAT_00100242` | Column, row and length of each factory menu item (3 bytes per item). | proven |
| `osd_factory_layout_sensing_test` | `DAT_00100287` | The layout entry of factory menu item 23 'Sensing Test'. | proven |
| `osd_factory_layout_phy_cts_auto` | `DAT_0010028a` | The layout entry of factory menu item 24 'PHY CTS AUTO'. | proven |
| `sys_key_code_table` | `DAT_0010051f` | The 16 front-key pairs {scan code, key event 0x40..0x4E}. | proven |
| `sys_key_bit_table` | `DAT_0010053f` | Six pairs {key input bit, key bit} used to turn the key inputs into key bits. | derived |
| `osd_logo_cell_map` | `DAT_00100554` | The cell values of the 63 x 10 power-on logo grid. | derived |
| `osd_logo_glyph_words` | `DAT_00101e52` | The glyph data words of the power-on logo (0xBE8 entries). | derived |
| `osd_logo_glyph_high_bytes` | `DAT_00104d00` | The high byte that goes with each glyph data word of the power-on logo. | derived |
| `osd_app_event_handler_rows` | `DAT_001080b8` | For each application event code the row of its handler in the table at 0xA80241B0. | derived |
| `osd_key_roles` | `DAT_001080f8` | The role of each key event in the menu: 0 OK, 1 back, 2 down, 3 up, 4 right, 7 hook. | proven |
| `font_glyph_columns_fa` | `DAT_001081f0` | Glyph bitmap columns of menu font 0xFA. | proven |
| `font_glyph_widths_fa` | `DAT_0010dfe0` | Glyph widths of menu font 0xFA. | proven |
| `font_glyph_columns_f9` | `DAT_0010e088` | Glyph bitmap columns of menu font 0xF9. | proven |
| `font_glyph_widths_f9` | `DAT_00115588` | Glyph widths of menu font 0xF9. | proven |
| `font_glyph_columns_f0` | `DAT_00125928` | Glyph bitmap columns of menu font 0xF0. | proven |
| `font_glyph_widths_f0` | `DAT_0012e2f8` | Glyph widths of menu font 0xF0. | proven |
| `font_glyph_columns_f8` | `DAT_0012e3f0` | Glyph bitmap columns of menu font 0xF8. | proven |
| `font_glyph_widths_f8` | `DAT_0012fb90` | Glyph widths of menu font 0xF8. | proven |
| `font_glyph_columns_fd` | `DAT_0012fbc0` | Glyph bitmap columns of menu font 0xFD. | proven |
| `font_glyph_widths_fd` | `DAT_00130dc0` | Glyph widths of menu font 0xFD. | proven |
| `font_glyph_columns_f6` | `DAT_00130de0` | Glyph bitmap columns of menu font 0xF6. | proven |
| `font_glyph_widths_f6` | `DAT_001394e0` | Glyph widths of menu font 0xF6. | proven |
| `font_glyph_widths_fe` | `DAT_001395d0` | Glyph widths of menu font 0xFE. | proven |
| `font_glyph_columns_fe` | `DAT_001395ec` | Glyph bitmap columns of menu font 0xFE. | proven |
| `font_glyph_columns_f1` | `DAT_0013a3fc` | Glyph bitmap columns of menu font 0xF1. | proven |
| `font_glyph_widths_f1` | `DAT_00142b00` | Glyph widths of menu font 0xF1. | proven |
| `font_glyph_columns_f2` | `DAT_00142bf0` | Glyph bitmap columns of menu font 0xF2. | proven |
| `font_glyph_widths_f2` | `DAT_0014b2f0` | Glyph widths of menu font 0xF2. | proven |
| `font_glyph_columns_fc` | `DAT_0014b3e8` | Glyph bitmap columns of menu font 0xFC. | proven |
| `font_glyph_widths_fc` | `DAT_0014d1b8` | Glyph widths of menu font 0xFC. | proven |
| `font_glyph_columns_f3` | `DAT_0014d1f0` | Glyph bitmap columns of menu font 0xF3. | proven |
| `font_glyph_widths_f3` | `DAT_00155860` | Glyph widths of menu font 0xF3. | proven |
| `font_glyph_columns_fb` | `DAT_00155950` | Glyph bitmap columns of menu font 0xFB. | proven |
| `font_glyph_widths_fb` | `DAT_00157840` | Glyph widths of menu font 0xFB. | proven |
| `font_glyph_columns_f4` | `DAT_00157878` | Glyph bitmap columns of menu font 0xF4. | proven |
| `font_glyph_widths_f4` | `DAT_0015ff78` | Glyph widths of menu font 0xF4. | proven |
| `font_glyph_columns_f5` | `DAT_00160068` | Glyph bitmap columns of menu font 0xF5. | proven |
| `font_glyph_widths_f5` | `DAT_00166f38` | Glyph widths of menu font 0xF5. | proven |
| `font_glyph_columns_f7` | `DAT_00167000` | Glyph bitmap columns of menu font 0xF7. | proven |
| `font_glyph_widths_f7` | `DAT_0016dd20` | Glyph widths of menu font 0xF7. | proven |
| `osd_panel_protect_prompt_texts` | `DAT_0016dde8` | Texts of the panel protect prompt, starting 'After 10 mins, panel protect Process will active'. | proven |
| `osd_oled_care_choice_texts` | `DAT_0016df60` | The OLED Care choice texts per language, starting 'OFF', 'ON', 'Reducing Level'. | proven |
| `osd_protect_long_execute_texts` | `DAT_0016e0d0` | Panel protect page: press 'Execute' to do panel protect (long time). | proven |
| `osd_protect_long_auto_texts` | `DAT_0016f25c` | Panel protect page: panel protect (long time) will automatically activate. | proven |
| `osd_protect_long_title_texts` | `DAT_0016f670` | Page 'MSI OLED Care - Panel Protect (Long Time)': activates after 1,500 hours of use. | proven |
| `osd_protect_long_incomplete_texts` | `DAT_00172590` | Panel protect page: the long-time process did not complete; select the item later. | proven |
| `osd_protect_incomplete_texts` | `DAT_00173998` | Panel protect page: the process did not complete; select the item later. | proven |
| `osd_protect_execute_texts` | `DAT_00174bd0` | Panel protect page: press 'Execute' to do panel protect. | proven |
| `osd_protect_long_retry_texts` | `DAT_00175de4` | Panel protect page: the long-time process did not complete; press 'execute'. | proven |
| `osd_protect_retry_texts` | `DAT_00177270` | Panel protect page: the process did not complete; press 'execute'. | proven |
| `osd_protect_auto_texts` | `DAT_001785c0` | Panel protect page: panel protect will automatically activate. | proven |
| `osd_protect_title_texts` | `DAT_00179a14` | Page 'MSI OLED Care - Panel Protect': activates after 4 hours of use. | proven |
| `osd_change_notice_line3_texts` | `DAT_00180b60` | Change notice line 'Please select one of the following options:' | proven |
| `osd_change_notice_line2_texts` | `DAT_00181058` | Change notice line 'the power consumption of this monitor.' | proven |
| `osd_change_notice_line1_texts` | `DAT_001814d8` | Change notice line 'Changing the selected function may increase'. | proven |
| `osd_change_notice_title_texts` | `DAT_001819cc` | The title 'Confirm Change !' of the change notice, per language. | proven |
| `osd_pbp_source_texts` | `DAT_00182534` | PBP texts 'Source 1', 'Source 2', ... | proven |
| `osd_pip_item_texts` | `DAT_001828c0` | PIP item names: 'Source', 'PIP Size', 'Location', 'Display Switch', 'Audio Switch'. | proven |
| `osd_choice_note_function_texts` | `DAT_001832e4` | Function names in the notes: 'Adaptive-Sync', 'Brightness', 'HDCR', 'PIP/PBP'. | proven |
| `osd_choice_note_texts` | `DAT_00183a70` | Notes under a choice list: 'Notice :', 'Approx. 15 mins to complete', ... | proven |
| `osd_choice_note_reducing_texts` | `DAT_00183cb4` | Note 'Reducing effect depends on "Brightness" or "DisplayHDR" setting.' | proven |
| `osd_choice_note_enabling_texts` | `DAT_00185af0` | Note starting 'Enabling it will affect'. | proven |
| `osd_oled_care_function_texts` | `DAT_00185bc0` | OLED Care function names: 'Panel Protect', 'Pixel Shift', 'Static Screen Detection', ... | proven |
| `osd_oled_care_item_texts` | `DAT_00185e78` | Item names of the MSI OLED Care tab (Pixel Shift .. OLED Panel Info.). | proven |
| `osd_settings_item_texts` | `DAT_001874f8` | Item names of the Settings tab (Language .. Reset). | proven |
| `osd_professional_item_texts` | `DAT_00188634` | Item names of the Professional tab: Pro Mode, Low Blue Light, Image Enhancement. | proven |
| `osd_gaming_item_texts` | `DAT_00188da0` | Item names of the Gaming tab (Game Mode .. DSC). | proven |
| `osd_night_vision_texts` | `DAT_001890d4` | Night Vision choices: 'OFF', 'Normal', 'Strong', 'Strongest', 'A. I.'. | proven |
| `osd_gi_item_texts` | `DAT_0018a360` | Item names of the G.I. tab: KVM, Smart Crosshair, Optix Scope. | proven |
| `osd_status_header_texts` | `DAT_0018a6ac` | Texts of the top status lines, starting 'HDR'. | derived |
| `osd_rgb_brightness_level_texts` | `DAT_0018a758` | The five RGB Brightness level texts '100%', '80%', ... | proven |
| `osd_oled_care_level_texts` | `DAT_0018a794` | OLED Care choice texts '65%', '50 c', '100 c', '120 c'. | proven |
| `osd_oled_care_seconds_texts` | `DAT_0018a7ec` | OLED Care choice texts '50 Sec', '100 Sec', '120 Sec', '240 Sec'. | proven |
| `osd_oled_care_usage_texts` | `DAT_0018b29c` | OLED Care choice texts 'Auto', 'Usage 24 hrs', ... | proven |
| `osd_oled_care_speed_texts` | `DAT_0018b5e0` | OLED Care choice texts 'Slow', 'Normal', 'Fast'. | proven |
| `osd_oled_care_status_texts` | `DAT_0018b94c` | OLED Care texts 'Starting in', 'Time required', 'Reducing Level'. | proven |
| `osd_image_item_texts` | `DAT_0018ca88` | Item names of the Image tab: Brightness, Contrast, Sharpness, Color Temperature, ... | proven |
| `osd_language_texts` | `DAT_0018d3d4` | The names of the menu languages, starting 'English'. | proven |
| `osd_optix_scope_item_texts` | `DAT_0018d578` | Optix Scope texts 'Scope Size', 'Scope Ratio', 'OFF'. | proven |
| `osd_color_temp_texts` | `DAT_0018db28` | Color Temperature choices 'Cool', 'Normal', 'Warm', 'Customization'. | proven |
| `osd_response_time_texts` | `DAT_0018e08c` | Choices 'Normal', 'Fast', 'Fastest'. | proven |
| `osd_crosshair_color_texts` | `DAT_0018e54c` | Smart Crosshair colours 'White', 'Red', 'Auto'. | proven |
| `osd_pbp_mode_texts` | `DAT_0018e89c` | PBP mode texts 'Mode 1', 'Mode 2', 'Customize'. | proven |
| `osd_location_texts` | `DAT_0018e9f8` | Location choices 'Left Top', 'Right Top', 'Left Bottom', 'Right Bottom', 'Customize'. | proven |
| `osd_size_texts` | `DAT_0018f550` | Size choices 'Small', 'Medium', 'Large'. | proven |
| `osd_crosshair_item_texts` | `DAT_0018f984` | Smart Crosshair texts 'None', 'Icon', 'Color', 'Position', 'Reset'. | proven |
| `osd_protect_button_texts` | `DAT_00190184` | Panel protect buttons 'Execute', 'Cancel', 'Later', 'More Info'. | proven |
| `osd_yes_no_texts` | `DAT_00190748` | The choices 'Yes', 'No'. | proven |
| `osd_kvm_texts` | `DAT_001909ec` | KVM choices 'Auto', 'Upstream', 'Type C'. | proven |
| `osd_screen_size_texts` | `DAT_001910b0` | Screen Size choices 'Auto', '4:3', '16:9', '16:10', '1:1'. | proven |
| `osd_navi_key_item_texts` | `DAT_0019158c` | Item names of the Navi Key tab: 'Up', 'Down', 'Left', 'Right'. | proven |
| `osd_info_box_texts` | `DAT_00191b30` | Info. On Screen labels 'Input Source', 'Native Resolution', 'Refresh Rate', ... | proven |
| `osd_cec_console_texts` | `DAT_00192860` | Console names shown under the input name, by CEC source type: PlayStation, Nintendo Switch, Xbox. | derived |
| `osd_key_guide_texts` | `DAT_001928b0` | Key guide texts 'Move', 'Enter', 'Switch', 'Adjust', 'Select', 'Save'. | proven |
| `osd_out_of_range_texts` | `DAT_00192d8c` | Signal message text 'Out Of Range!', per language. | proven |
| `osd_no_signal_texts` | `DAT_00193008` | Signal message text 'No Signal', per language. | proven |
| `osd_off_on_texts` | `DAT_00193248` | The choices 'OFF', 'ON'. | proven |
| `osd_rgb_led_texts` | `DAT_00193330` | RGB LED choices, starting 'RGB Brightness'. | proven |
| `osd_power_button_texts` | `DAT_0019336c` | Power Button choices 'OFF', 'Standby'. | proven |
| `osd_navi_function_texts` | `DAT_001935bc` | Navi key functions 'OFF', 'Brightness', 'Game Mode', 'Smart Crosshair', ... | proven |
| `osd_image_enhancement_texts` | `DAT_00194b34` | Image Enhancement levels 'OFF', 'Weak', 'Medium', 'Strong', 'Strongest'. | proven |
| `osd_pro_mode_texts` | `DAT_001951dc` | Pro modes 'Eco', 'User', 'Anti-Blue', 'Movie', 'Office', 'sRGB'. | proven |
| `osd_game_mode_texts` | `DAT_00195f24` | Game modes 'Premium Color', 'User', 'FPS', 'Racing', 'RTS', 'RPG'. | proven |
| `osd_pip_pbp_texts` | `DAT_00196678` | PIP/PBP choices 'OFF', 'PIP', 'PBP'. | proven |
| `osd_input_name_texts` | `DAT_00196b24` | The input names of the input lists and the signal messages. | derived |
| `osd_tab_name_texts` | `DAT_00196dc0` | The nine tab names: G.I., Gaming, Professional, Image, Input Source, ..., MSI OLED Care. | proven |
| `osd_color_gain_label_texts` | `DAT_00197d08` | The custom colour gain labels 'R', 'G', 'B'. | proven |
| `osd_symbol_texts` | `DAT_00197ee4` | Short texts '0', '1', '5', '20', '30', '100', ':', '%', 'F'. | proven |
| `osd_protect_icon_cells` | `DAT_00197f50` | Glyph numbers (less 0x3F) of the picture drawn in the panel protect prompt, row by row. | derived |
| `osd_firmware_version_text` | `DAT_001981f0` | Length-prefixed text 'FW.021' drawn in the signal information header. | proven |
| `osd_model_name_text` | `DAT_001981f8` | Length-prefixed text 'MPG 321U QD-OLED' drawn in the signal information header. | proven |
| `osd_crosshair_color_table` | `DAT_0019820a` | The 24 halfwords from which the automatic crosshair colour is picked. | descriptive |
| `ddc_model_name_text` | `DAT_00198328` | Length byte 14 and the text "MSI MPG 321URX", sent for GetVCP 0xFE sub-code 0xE9. | proven |
| `ddc_firmware_version_text` | `DAT_00198338` | Length byte 6 and the text "FW.021", sent for GetVCP 0xFE sub-code 0xE1 with key E6 06 00. | proven |
| `ddc_key_a7_text` | `DAT_00198340` | Length byte 18 and the text "SDC QMC315AA01_D01", sent for GetVCP 0xFE sub-code 0xE1 with key A7 07 00. | derived |
| `panel_mode_rows` | `DAT_00198380` | The three panel timing rows in ROM: the 240 Hz, 120 Hz and 60 Hz mode of the panel (0x58 bytes each). | proven |
| `sys_user_slot_records` | `DAT_00198488` | 16-byte records chosen by settings bytes +0x27 / +0x28 and handed to the slot 5 and 6 routines. | descriptive |
| `sys_user_channel_records` | `DAT_001984c8` | 16-byte records chosen by settings bytes +0x46 / +0x48 that decide channel 2 and 3 restarts. | descriptive |
| `factory_record_defaults` | `DAT_00198508` | The default factory record in ROM (0x1C bytes). | proven |
| `user_settings_defaults` | `DAT_00198524` | The default user settings record in ROM. | proven |
| `user_settings_defaults_contrast` | `DAT_0019852e` | Default of settings byte +0xA, the Contrast. | derived |
| `dbg_command_table` | `DAT_00198c90` | The twelve commands of the debug command line: name ('mem', ...) and routine. | proven |
| `uart_hex_digits` | `DAT_00198fa0` | The hexadecimal digit characters '0'..'F'. | proven |
| `irq_level_source_counts` | `DAT_00199278` | Number of interrupt sources of each interrupt level. | proven |
| `sys_ddr_script_unit_ranges` | `DAT_0019962c` | First and last unit numbers that each memory training script command works on. | derived |
| `input_bring_up_lane_regs` | `DAT_00199ffc` | Register numbers of the four lanes during port bring-up (0xCF000000 \| n << 2). | derived |
| `input_clock_powers_of_two` | `DAT_0019a004` | Seventeen powers of two (2^10 .. 2^26) used by the pixel clock computation. | proven |
| `reg_blockset7_bases` | `DAT_0019a2d8` | Register bases of the blocks of the seventh block set. | derived |
| `input_unit_reg_bases` | `DAT_0019a2e0` | Register bases of the receiver units. | derived |
| `pq_port_reg_bases` | `DAT_0019a2e4` | Register bases of the four port blocks. | derived |
| `pq_block_reg_bases` | `DAT_0019a2ec` | Register bases of the eight picture blocks. | derived |
| `input_measure_reg_bases` | `DAT_0019a2fc` | Register bases of the eight input measurement blocks. | derived |
| `input_format_reg_bases` | `DAT_0019a30c` | Register bases of the eight input format blocks. | derived |
| `input_capture_reg_bases` | `DAT_0019a31c` | Register bases of the eight input capture blocks. | derived |
| `pq_ace_default_table` | `DAT_0019a334` | The default 16-bit table streamed to the ACE block: count and values. | derived |
| `pq_ace_default_curve` | `DAT_0019a378` | The default curve of 16-bit points for the ACE block: count and points. | derived |
| `input_block_source_reg_table` | `DAT_0019a4fb` | The ROM register table loaded into the block registers for each input class (0xC0 bytes). | derived |
| `input_csc_mode_reg_values` | `DAT_0019a5bc` | 15 halfwords written, for format code 41 only, to capture registers 0x1B..0x23 in three groups of five. | derived |
| `input_csc_table_first` | `DAT_0019a5da` | The first of three 0x1E-byte colour conversion tables. | descriptive |
| `input_csc_table_second` | `DAT_0019a5f8` | The second of three 0x1E-byte colour conversion tables. | descriptive |
| `input_csc_table_third` | `DAT_0019a616` | The third of three 0x1E-byte colour conversion tables. | descriptive |
| `input_supported_timing_table` | `DAT_0019a640` | The supported timings: width, height and rate, with the settings of picture block 5. | derived |
| `pq_gamma_first_curve_preset2` | `DAT_0019acdc` | Preset 2 of the first preset-curve stage (0x40 bytes). | derived |
| `pq_gamma_first_curve_preset0` | `DAT_0019ad1c` | Preset 0 of the first preset-curve stage (0x40 bytes). | derived |
| `pq_gamma_first_curve_preset1` | `DAT_0019ad5c` | Preset 1 of the first preset-curve stage (0x40 bytes). | derived |
| `pq_gamma_first_curve_preset3` | `DAT_0019ad9c` | Preset 3 of the first preset-curve stage (0x40 bytes). | derived |
| `pq_gamma_first_curve_preset4` | `DAT_0019addc` | Preset 4 of the first preset-curve stage (0x40 bytes). | derived |
| `pq_gamma_second_curve_preset2` | `DAT_0019ae1c` | Preset 2 of the second preset-curve stage (0x20 bytes). | derived |
| `pq_gamma_second_curve_preset0` | `DAT_0019ae3c` | Preset 0 of the second preset-curve stage (0x20 bytes). | derived |
| `pq_gamma_second_curve_preset1` | `DAT_0019ae5c` | Preset 1 of the second preset-curve stage (0x20 bytes). | derived |
| `pq_gamma_second_curve_preset3` | `DAT_0019ae7c` | Preset 3 of the second preset-curve stage (0x20 bytes). | derived |
| `pq_gamma_second_curve_preset4` | `DAT_0019ae9c` | Preset 4 of the second preset-curve stage (0x20 bytes). | derived |
| `panel_layer4_blocks_second_half` | `DAT_0019aebc` | Pointers to the two fourth-layer register blocks at 0xD003A028 / 0xD003A098. | derived |
| `panel_layer4_blocks_first_half` | `DAT_0019aec4` | Pointers to the two fourth-layer register blocks at 0xD0032028 / 0xD0032098. | derived |
| `panel_channel_blocks_second_half` | `DAT_0019aecc` | Pointers to the three channel layer register blocks at 0xD0038100..0xD0038300. | derived |
| `panel_channel_blocks_first_half` | `DAT_0019aed8` | Pointers to the three channel layer register blocks at 0xD0030100..0xD0030300. | derived |
| `panel_layer_alt_blocks_second_half` | `DAT_0019aee4` | Pointers to the three second-set layer register blocks at 0xD0038030..0xD0038070. | derived |
| `panel_layer_alt_blocks_first_half` | `DAT_0019aef0` | Pointers to the three second-set layer register blocks at 0xD0030030..0xD0030070. | derived |
| `pq_profile_table` | `DAT_0019af00` | The built-in 1024-entry profile table, 0x20 bytes per entry. | derived |
| `sys_path_block_bases` | `DAT_001a2fb0` | Register bases of the two signal path blocks. | derived |
| `sys_path_block_start_regs48` | `DAT_001a2fb8` | Start values of registers 0x48.. of the signal path blocks (8 bytes). | derived |
| `sys_path_block_start_regs38` | `DAT_001a2fc0` | Start values of registers 0x38.. of the signal path blocks (8 bytes). | derived |
| `sys_path_block_start_regs12` | `DAT_001a2fc8` | Start values of registers 0x12.. of the signal path blocks (12 bytes). | derived |
| `input_unit_mode_regs40` | `DAT_001a3060` | Values written to registers 0x40..0x4F of a receiver unit for a mode. | derived |
| `input_block_reg_bases` | `DAT_001a3070` | Register bases of the input blocks read by the register-pair readers. | derived |
| `panel_default_row` | `DAT_001a30d0` | The start-up default panel timing row in ROM. | proven |
| `panel_default_row_active_lines` | `DAT_001a30da` | Halfword +0xA of the default panel timing row: the number of active lines. | derived |
| `panel_level_gen_levels` | `DAT_001a3128` | The rising level steps of the level generator. | derived |
| `pq_fga_gamma_block_codes` | `DAT_001a31a8` | The 32-byte table used to decode the stored gamma blocks into full tables. | descriptive |
| `pq_block8_value_tables` | `DAT_001a3648` | Picture block 8 value pairs per preset, loaded with pq_block8_load_tables. | derived |
| `pq_block8_config_tables` | `DAT_001a3668` | Picture block 8 configuration tables, loaded together with the value tables. | derived |
| `edid_bus_table` | `DAT_001a4288` | Four-byte entries of the EDID buses: port and bit pairs of their pins. | derived |
| `port_table` | `DAT_001a42a8` | The fixed description of each input in ROM: port code, type, bus, EDID memory, pins (0x16 bytes each). | proven |
| `port_table_type` | `DAT_001a42a9` | The type field (+1) of the first port table entry. | proven |
| `port_table_byte_0x12` | `DAT_001a42ba` | Byte +0x12 of the first port table entry. | descriptive |
| `input_control_key_table` | `DAT_001a4371` | The control keys: 8051 port, bit and active level of each key. | derived |
| `pq_auto_level_weights` | `DAT_001a4ea8` | The 16 weights handed to the automatic brightness level measurement. | derived |
| `pq_fga_default_row_bit4` | `DAT_001a4f40` | Default 18-byte FGA row written by FGA_Init for bit 0x04. | derived |
| `pq_fga_default_row_bit2` | `DAT_001a4f58` | Default 18-byte FGA row written by FGA_Init for bit 0x02. | derived |
| `pq_fga_default_row_bit1` | `DAT_001a4f70` | Default 18-byte FGA row written by FGA_Init for bit 0x01 and every other bit. | derived |
| `pq_fga_default_block_second` | `DAT_001a4f88` | Second 0x60-byte FGA default block, written when the FGA selector is above 1. | derived |
| `pq_fga_default_block_first` | `DAT_001a4fe8` | First 0x60-byte FGA default block, written when the FGA selector is above 1. | derived |
| `pq_fga_default_block_key400` | `DAT_001a5048` | 0x60-byte FGA default block written for key bit 0x400. | derived |
| `pq_fga_default_block_key100` | `DAT_001a50a8` | 0x60-byte FGA default block written for key bit 0x100. | derived |
| `pq_fga_default_block_key8` | `DAT_001a5108` | 0x60-byte FGA default block written for key bit 0x008. | derived |
| `pq_fga_key_table_second` | `DAT_001a5168` | The 12 {key, value} pairs (keys 0x2D..0xCC) of the second FGA key table (bit set 0x92). | descriptive |
| `pq_fga_key_table_first` | `DAT_001a5198` | The 11 {key, value} pairs (keys 0x10..0x24) of the first FGA key table (bit set 0x508). | descriptive |
| `input_source_code_table` | `DAT_001a5238` | The four source codes 0x61, 0x51, 0x81, 0x71; the top six bits give the group. | derived |
| `ldc_start_words_e0` | `DAT_001a5320` | Eight words sent to the dimming processor at mailbox offset 0xE0 before the start command. | derived |
| `ldc_start_words_c0` | `DAT_001a5340` | Eight words sent to the dimming processor at mailbox offset 0xC0 before the start command. | derived |
| `ipc_8051_wake_keys_mode1` | `DAT_001a5360` | The 36-byte standby key and wake-up pin list sent to the 8051 in mode 1. | derived |
| `ipc_8051_wake_keys_mode0` | `DAT_001a5388` | The 36-byte standby key and wake-up pin list sent to the 8051 in mode 0. | derived |
| `ipc_8051_wake_port_table` | `DAT_001a53ac` | The 0x30-byte table of wake-up ports sent to the 8051. | derived |
| `pq_color_matrix_post` | `DAT_001a566c` | The 3 x 3 Q12 matrix that multiplies the hue and saturation product last. | derived |
| `pq_color_matrix_pre` | `DAT_001a5690` | The 3 x 3 Q12 matrix that the hue and saturation matrix is applied to first. | derived |
| `startup_channel_ports` | `DAT_001a57c0` | The port given to each of the four channel records at reset. | derived |
| `input_short_mode_list` | `DAT_001a59e2` | Short list of {id, value} mode entries checked before the mode table. | descriptive |
| `input_mode_table` | `DAT_001a5a16` | The known input timings in ROM that a measured signal is compared with (0x24 bytes each). | proven |
| `nvram_write_pins` | `DAT_001a69d6` | Port, mask and level of the pin of each storage bus that nvram_write changes around a write. | derived |
| `nvram_bus_table` | `DAT_001a69e0` | The software I2C bus descriptors of the storage devices (pins, delay, address, mode). | proven |
| `nvram_device_table` | `DAT_001a69fe` | One entry per storage device: flash area (negative = EEPROM), row, size, row shift. | derived |
| `nvram_flash_area_table` | `DAT_001a6a24` | One entry per flash-backed storage area: size, kind and bank. | derived |
| `edid_variant_lengths` | `DAT_001a6ad8` | The EDID length of each EDID variant (indexed by device settings byte 0x1B + port). | derived |
| `sys_frc_bit_group_table` | `DAT_001a6adc` | Bit groups for the frame-rate converter by the two stored mode indexes, 22 bytes each. | derived |
| `sys_frc_rom_settings` | `DAT_001a6b34` | The frame-rate converter settings selected by the two stored indexes. | derived |
| `sys_channel_path_modes` | `DAT_001a6cb4` | The records of path modes 0..4: mode record, two coefficient records, register values. | derived |
| `input_source_value_map` | `DAT_001a6da3` | Five 3-byte entries {source id, setting value, key} that translate source settings. | descriptive |
| `input_menu_source_pairs` | `DAT_001a6db2` | Four {source id, menu index} pairs of the input menu. | derived |
| `sys_port_service_table` | `DAT_001a74a6` | Four {port mask, timer id} entries served on every pass of sys_main_loop_periodic_task. | derived |
| `nvram_blank_pattern` | `DAT_001a75e6` | The 16-byte blank pattern that clears the saved-mode table and records. | proven |
| `uart_cmd_get_rows` | `DAT_001a7656` | The PC tool 'get' command rows, 8 characters each. | proven |
| `uart_cmd_set_rows11` | `DAT_001a7a6e` | The PC tool 'set' command rows of 11 bytes. | proven |
| `uart_cmd_set_rows26` | `DAT_001a807d` | The PC tool 'set' command rows of 26 bytes. | proven |
| `uart_cmd_set_rows42` | `DAT_001a81cf` | The PC tool 'set' command rows of 42 bytes. | proven |
| `_global_impure_ptr` | `DAT_001a83d8` | Pointer to the global reentrancy structure of the C library. | proven |
| `lconv` | `DAT_001a84f4` | The static locale conventions record of the C library. | proven |

## Hardware registers

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `reg_pq_color_matrix_option` | `_DAT_cf00e984` | Colour matrix register; bit 7 = the second option of the colour matrix. | derived |
| `reg_pq_gamma_lut_control` | `_DAT_cf00eac8` | Gamma register: bit 7 = primary LUT on, bit 3 = secondary LUT on, bit 6 = option. | derived |
| `reg_panel_vx1_reset` | `_DAT_cf00eb44` | V-by-One reset register (1 = reset, 0 = run). | derived |
| `reg_panel_vx1_lock_status` | `_DAT_cf00eb48` | V-by-One lock status register (4 = locked). | derived |
| `reg_panel_output_source_select` | `_DAT_cf00ed80` | Output register whose low bits select the output source. | derived |
| `reg_input_block_pre_pattern` | `_DAT_cf011400` | Input block register; bit 4 switches the pre-pattern on. | derived |
| `reg_sys_path_selector` | `_DAT_cf01166c` | Signal path register; bits 0-1 select the path. | derived |
| `reg_sys_selected_path_enable` | `_DAT_cf011670` | Enable register of the selected signal path. | derived |
| `reg_sys_frc_control` | `_DAT_cf011800` | Frame-rate converter register: bit 0 = running, bit 4 = channel 4 enable. | derived |
| `reg_sys_frc_active_control` | `_DAT_cf011aa0` | Frame-rate converter register: bit 7 = active; bits 0-3 read as idle check of unit 0. | derived |
| `reg_pq_block8_variant` | `_DAT_cf012fdc` | Picture block 8 register; bits 0-3 give the block variant. | derived |
| `reg_panel_level_gen_ctrl` | `_DAT_cf0160c0` | Control register of the level generator (bits 0 and 1). | derived |
| `reg_panel_level_gen_min_level` | `_DAT_cf0160c8` | Level generator register (low byte): receives the minimum level byte 0x7E; the level goes to 0xCF0160DC. | descriptive |
| `reg_panel_level_gen_enable` | `_DAT_cf016118` | Level generator register: bit 7 = enable, bit 6 = option. | derived |
| `reg_panel_pwm_group_sync` | `_DAT_cf016404` | PWM register whose top two bits set the group sync mode. | derived |
| `reg_input_adc_level0` | `_DAT_cf020000` | Input ADC level register 0 (low byte). | derived |
| `reg_input_adc_level1` | `_DAT_cf020004` | Input ADC level register 1 (low byte). | derived |
| `reg_input_adc_level2` | `_DAT_cf020008` | Input ADC level register 2 (low byte). | derived |
| `reg_input_adc_offset0` | `_DAT_cf02000c` | Input ADC offset register 0. | derived |
| `reg_input_adc_offset1` | `_DAT_cf020010` | Input ADC offset register 1. | derived |
| `reg_input_adc_offset2` | `_DAT_cf020014` | Input ADC offset register 2. | derived |
| `reg_ipc_8051_shared_f211` | `_DAT_cf03c844` | Shared 8051 byte XDATA 0xF211, first word of the handshake pair (1 = taken). | derived |
| `reg_ipc_8051_shared_f212` | `_DAT_cf03c848` | Shared 8051 byte XDATA 0xF212, second word of the handshake pair (1 = taken). | derived |
| `reg_ipc_8051_shared_f220` | `_DAT_cf03c880` | Shared 8051 byte XDATA 0xF220, the status register the main processor writes. | derived |
| `reg_ipc_shared_hdmi_status` | `_DAT_cf03c890` | Shared status register with one bit per HDMI port, read as the 8051 port flags. | derived |

## RAM

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `sys_fake_sleep_led_flag` | `DAT_a8024000` | Fake sleep: 0xFF until the 10-minute LED and off step has run, then 0 (first data byte). | derived |
| `sys_fake_sleep_minutes` | `DAT_a8024001` | Minutes counted in fake sleep (0..10, 0xFF = not counting). | proven |
| `pq_ch1_measured_height` | `DAT_a8024004_vactive` | Measured height of channel 1 (valid from 200). | derived |
| `pq_ch1_measured_width` | `DAT_a8024006` | Measured width of channel 1 (valid from 300). | derived |
| `pq_ch1_measured_fourth_value` | `DAT_a8024008` | Fourth measured size value of channel 1 (registers 0x38/0x39). | descriptive |
| `pq_ch1_measured_third_value` | `DAT_a802400a` | Third measured size value of channel 1 (registers 0x3E/0x3F times 8). | descriptive |
| `hdmi_cec_vendor_id_bytes` | `DAT_a8024010` | The received CEC message word as bytes; bytes 1..3 are the vendor ID compared with the consoles. | derived |
| `hdmi_cec_source_name` | `DAT_a8024018` | The received CEC source name; bytes 1..4 are compared with 'Play', 'Nint', 'XBOX'. | derived |
| `usb_mode_select` | `DAT_a802401d` | The chosen USB upstream port (0xFF = none). | proven |
| `usb_hub_pbp_flag` | `DAT_a802401e` | Last state of PIP/PBP set to PBP (settings +0x1F = 2), which keeps the OT2211 hub powered. | derived |
| `usb_hub_factory_flag` | `DAT_a802401f` | Last state of the factory condition that keeps the OT2211 hub powered. | derived |
| `pq_ch1_change_flag` | `DAT_a8024020` | Last result of the channel 1 input change test (0xFF = none yet). | derived |
| `ddc_new_control_value` | `DAT_a8024028` | The VCP 0x02 'New Control Value' reported to the host: 1, 2 or 0xFF. | derived |
| `osd_factory_crc_auto_value` | `DAT_a8024040` | On/off value of factory menu item 26 "CRC AUTO", also set as option bit 20 of ports 0xC and 0xD. | proven |
| `sys_key_long_press_time` | `DAT_a8024044` | Hold time that counts as a long key press. | proven |
| `sys_key_repeat_interval` | `DAT_a8024046` | Time between repeats of a held key. | proven |
| `sys_key_repeat_delay` | `DAT_a8024048` | Hold time before a held key repeats for the first time. | proven |
| `osd_logo_layer1_block` | `DAT_a802404c` | Register block written to menu layer 1 when the power-on logo is set up. | descriptive |
| `osd_logo_layer1_packed` | `DAT_a802406c` | Packed register block written to menu layer 1 for the power-on logo. | descriptive |
| `osd_logo_layer0_block` | `DAT_a8024078` | Register block written to menu layer 0 when the power-on logo is set up. | descriptive |
| `osd_logo_layer0_packed_second` | `DAT_a802408c` | Second packed register block written for the power-on logo. | descriptive |
| `osd_logo_layer0_packed_first` | `DAT_a8024098` | First packed register block written for the power-on logo. | descriptive |
| `font_glyph_block_0` | `DAT_a80240a4` | Glyph block record 0 (count, region, destination, ROM source) of menu layouts 2, 3, 5. | derived |
| `font_glyph_block_1` | `DAT_a80240b0` | Glyph block record 1 (count, region, destination, ROM source) of menu layouts 5. | derived |
| `font_glyph_block_2` | `DAT_a80240bc` | Glyph block record 2 (count, region, destination, ROM source) of menu layouts 2, 3, 5. | derived |
| `font_glyph_block_3` | `DAT_a80240c8` | Glyph block record 3 (count, region, destination, ROM source) of menu layouts 2. | derived |
| `font_glyph_block_5` | `DAT_a80240e0` | Glyph block record 5 (count, region, destination, ROM source) of menu layouts 0. | derived |
| `font_glyph_block_6` | `DAT_a80240ec` | Glyph block record 6 (count, region, destination, ROM source) of menu layouts 0. | derived |
| `font_glyph_block_8` | `DAT_a8024104` | Glyph block record 8 (count, region, destination, ROM source) of menu layouts 0. | derived |
| `font_glyph_block_9` | `DAT_a8024110` | Glyph block record 9 (count, region, destination, ROM source) of menu layouts 2. | derived |
| `font_glyph_block_16` | `DAT_a8024164` | Glyph block record 16 (count, region, destination, ROM source) of menu layouts 3, 5. | derived |
| `font_glyph_block_17` | `DAT_a8024170` | Glyph block record 17 (count, region, destination, ROM source) of menu layouts 0, 2, 3, 5. | derived |
| `font_glyph_block_18` | `DAT_a802417c` | Glyph block record 18 (count, region, destination, ROM source) of menu layouts 3, 5. | derived |
| `font_glyph_block_19` | `DAT_a8024188` | Glyph block record 19 (count, region, destination, ROM source) of menu layouts 2, 3, 5. | derived |
| `font_glyph_block_20` | `DAT_a8024194` | Glyph block record 20 (count, region, destination, ROM source) of menu layouts 0. | derived |
| `osd_layer1_lookup_block` | `DAT_a80241a0` | The start-up lookup table block of menu layer 1. | derived |
| `osd_layer0_lookup_block` | `DAT_a80241a8` | The start-up lookup table block of menu layer 0. | derived |
| `osd_app_event_handlers` | `DAT_a80241b0` | The menu routine run for each application event row (osd_app_event_handler_rows). | derived |
| `osd_menu_key_table` | `DAT_a802422c` | For every menu state the routine that handles each key (six entries per state). | proven |
| `osd_menu_key_table_state1_ok` | `_DAT_a8024244` | Entry 0 of menu state 1 in the menu key table; also called directly for key role 7. | derived |
| `osd_saved_choice_value` | `DAT_a8025c54` | The setting value saved when a choice list is entered, restored when it is left. | derived |
| `osd_edit_value` | `DAT_a8025c55` | Working value of the item being changed: prompt button, slider level or input row. | descriptive |
| `osd_choice_row` | `DAT_a8025c56` | The highlighted row of the open choice list. | derived |
| `app_main_link_state` | `DAT_a8025c57` | Link state of channel 0 read before display; shown as the bit depth in the info box. | descriptive |
| `ddc_status_entries` | `DAT_a8025c58` | The three DDC/CI status entries {value, key, flags}. | derived |
| `edid_user_variant` | `DAT_a8025c64` | The EDID variant last chosen from the user settings. | proven |
| `dbg_help_lines` | `DAT_a8025c68` | The lines of the debug command list, ending with 0. | proven |
| `sys_clock_hz` | `DAT_a8025c74` | The processor clock in Hz (96000000) the timers are set up from. | derived |
| `sys_ddr_param0` | `DAT_a8025d08` | The first memory training parameter. | proven |
| `sys_ddr_phy_pages` | `DAT_a8025d10` | The register page currently selected in each memory interface. | derived |
| `sys_ddr_unit3_value2_masks` | `DAT_a8025e58` | Mask of value field 2 of calibration unit 3, per N_adj 0..9. | derived |
| `sys_ddr_unit3_value2_regs` | `DAT_a8025e80` | Register of value field 2 of calibration unit 3, per N_adj 0..9. | derived |
| `sys_ddr_unit3_value1_shifts` | `DAT_a8025ea8` | Shift of value field 1 of calibration unit 3, per N_adj 0..9. | derived |
| `sys_ddr_unit3_value1_masks` | `DAT_a8025ed0` | Mask of value field 1 of calibration unit 3, per N_adj 0..9. | derived |
| `sys_ddr_unit3_value1_regs` | `DAT_a8025ef8` | Register of value field 1 of calibration unit 3, per N_adj 0..9. | derived |
| `sys_ddr_unit3_value3_shifts` | `DAT_a8025f20` | Shift of value field 3 of calibration unit 3, per N_adj 0..9. | derived |
| `sys_ddr_unit3_value3_masks` | `DAT_a8025f48` | Mask of value field 3 of calibration unit 3, per N_adj 0..9. | derived |
| `sys_ddr_unit3_value3_regs` | `DAT_a8025f70` | Register of value field 3 of calibration unit 3, per N_adj 0..9. | derived |
| `sys_ddr_unit2_value2_masks` | `DAT_a8025f98` | Mask of value field 2 of calibration unit 2, per N_adj 0..9. | derived |
| `sys_ddr_unit2_value2_regs` | `DAT_a8025fc0` | Register of value field 2 of calibration unit 2, per N_adj 0..9. | derived |
| `sys_ddr_unit2_value1_shifts` | `DAT_a8025fe8` | Shift of value field 1 of calibration unit 2, per N_adj 0..9. | derived |
| `sys_ddr_unit2_value1_masks` | `DAT_a8026010` | Mask of value field 1 of calibration unit 2, per N_adj 0..9. | derived |
| `sys_ddr_unit2_value1_regs` | `DAT_a8026038` | Register of value field 1 of calibration unit 2, per N_adj 0..9. | derived |
| `sys_ddr_unit2_value3_shifts` | `DAT_a8026060` | Shift of value field 3 of calibration unit 2, per N_adj 0..9. | derived |
| `sys_ddr_unit2_value3_masks` | `DAT_a8026088` | Mask of value field 3 of calibration unit 2, per N_adj 0..9. | derived |
| `sys_ddr_unit2_value3_regs` | `DAT_a80260b0` | Register of value field 3 of calibration unit 2, per N_adj 0..9. | derived |
| `sys_ddr_unit1_value2_masks` | `DAT_a80260d8` | Mask of value field 2 of calibration unit 1, per N_adj 0..9. | derived |
| `sys_ddr_unit1_value2_regs` | `DAT_a8026100` | Register of value field 2 of calibration unit 1, per N_adj 0..9. | derived |
| `sys_ddr_unit1_value1_shifts` | `DAT_a8026128` | Shift of value field 1 of calibration unit 1, per N_adj 0..9. | derived |
| `sys_ddr_unit1_value1_masks` | `DAT_a8026150` | Mask of value field 1 of calibration unit 1, per N_adj 0..9. | derived |
| `sys_ddr_unit1_value1_regs` | `DAT_a8026178` | Register of value field 1 of calibration unit 1, per N_adj 0..9. | derived |
| `sys_ddr_unit1_value3_shifts` | `DAT_a80261a0` | Shift of value field 3 of calibration unit 1, per N_adj 0..9. | derived |
| `sys_ddr_unit1_value3_masks` | `DAT_a80261c8` | Mask of value field 3 of calibration unit 1, per N_adj 0..9. | derived |
| `sys_ddr_unit1_value3_regs` | `DAT_a80261f0` | Register of value field 3 of calibration unit 1, per N_adj 0..9. | derived |
| `sys_ddr_wr_deskew_dq_masks` | `DAT_a8026238` | Bit mask of the per-line write deskew registers of each data byte. | derived |
| `sys_ddr_wr_deskew_dq_regs` | `DAT_a8026248` | First register of the eight per-line write deskew registers of each data byte. | derived |
| `sys_ddr_dq_fail_masks` | `DAT_a8026258` | Bit masks of the data line fail bits (one bit per line, set when the last self-test failed on it). | descriptive |
| `sys_ddr_dq_fail_regs` | `DAT_a8026268` | Register numbers of the data line fail bits (one bit per line, set when the last self-test failed on it). | descriptive |
| `sys_ddr_rd_deskew_dq_masks` | `DAT_a8026278` | Bit mask of the per-line read deskew registers of each data byte. | derived |
| `sys_ddr_rd_deskew_dq_regs` | `DAT_a8026288` | First register of the eight per-line read deskew registers of each data byte. | derived |
| `sys_ddr_dly_per_cnt_masks` | `DAT_a80262f8` | Bit masks, one per data byte, of the field that gives the delay units in one whole write step. | descriptive |
| `sys_ddr_dly_per_cnt_regs` | `DAT_a8026308` | Register numbers, one per data byte, of the field that gives the delay units in one whole write step. | descriptive |
| `sys_ddr_read_eye_field1_masks` | `DAT_a8026318` | Bit mask of the memory interface field read_eye_field1 for each data byte. | descriptive |
| `sys_ddr_read_eye_field2_masks` | `DAT_a8026328` | Bit mask of the memory interface field read_eye_field2 for each data byte. | descriptive |
| `sys_ddr_read_eye_field1_regs` | `DAT_a8026338` | Register of the memory interface field read_eye_field1 for each data byte. | descriptive |
| `sys_ddr_read_eye_field2_regs` | `DAT_a8026348` | Register of the memory interface field read_eye_field2 for each data byte. | descriptive |
| `sys_ddr_read_eye_field3_masks` | `DAT_a8026358` | Bit mask of the memory interface field read_eye_field3 for each data byte. | descriptive |
| `sys_ddr_read_eye_field3_regs` | `DAT_a8026368` | Register of the memory interface field read_eye_field3 for each data byte. | descriptive |
| `sys_ddr_gate_check_field1_masks` | `DAT_a8026398` | Bit mask of the memory interface field gate_check_field1 for each data byte. | descriptive |
| `sys_ddr_gate_check_field1_regs` | `DAT_a80263a8` | Register of the memory interface field gate_check_field1 for each data byte. | descriptive |
| `sys_ddr_gate_check_field2_masks` | `DAT_a80263b8` | Bit mask of the memory interface field gate_check_field2 for each data byte. | descriptive |
| `sys_ddr_gate_check_field2_regs` | `DAT_a80263c8` | Register of the memory interface field gate_check_field2 for each data byte. | descriptive |
| `sys_ddr_gate_check_field3_masks` | `DAT_a80263d8` | Bit mask of the memory interface field gate_check_field3 for each data byte. | descriptive |
| `sys_ddr_gate_check_field3_regs` | `DAT_a80263e8` | Register of the memory interface field gate_check_field3 for each data byte. | descriptive |
| `sys_ddr_gate_check_field4_masks` | `DAT_a80263f8` | Bit mask of the memory interface field gate_check_field4 for each data byte. | descriptive |
| `sys_ddr_gate_check_field4_regs` | `DAT_a8026408` | Register of the memory interface field gate_check_field4 for each data byte. | descriptive |
| `sys_ddr_rd_deskew_result_masks` | `DAT_a8026418` | Bit mask of the read deskew result registers of each data byte. | descriptive |
| `sys_ddr_rd_deskew_result_regs` | `DAT_a8026428` | First result register read per line during read deskew, for each data byte. | descriptive |
| `sys_ddr_gate_check_field5_shifts` | `DAT_a8026438` | Bit position of the memory interface field gate_check_field5 for each data byte. | descriptive |
| `sys_ddr_gate_check_field5_masks` | `DAT_a8026448` | Bit mask of the memory interface field gate_check_field5 for each data byte. | descriptive |
| `sys_ddr_gate_check_field5_regs` | `DAT_a8026458` | Register of the memory interface field gate_check_field5 for each data byte. | descriptive |
| `sys_ddr_qs_gate_field1_shifts` | `ARR_a8026468` | Bit positions used with sys_ddr_qs_gate_field1_regs / _masks, one per data byte. | derived |
| `sys_ddr_qs_gate_field1_masks` | `DAT_a8026478` | Bit mask of the memory interface field qs_gate_field1 for each data byte. | descriptive |
| `sys_ddr_qs_gate_field1_regs` | `DAT_a8026488` | Register of the memory interface field qs_gate_field1 for each data byte. | descriptive |
| `sys_ddr_qsen_dly_c_sel_shifts` | `DAT_a8026498` | Bit position of the memory interface field qsen_dly_c_sel for each data byte. | proven |
| `sys_ddr_qsen_dly_c_sel_masks` | `DAT_a80264a8` | Bit mask of the memory interface field qsen_dly_c_sel for each data byte. | proven |
| `sys_ddr_qsen_dly_c_sel_regs` | `DAT_a80264b8` | Register of the memory interface field qsen_dly_c_sel for each data byte. | proven |
| `sys_ddr_qsen_dly_b_sel_shifts` | `DAT_a80264c8` | Bit position of the memory interface field qsen_dly_b_sel for each data byte. | proven |
| `sys_ddr_qsen_dly_b_sel_masks` | `DAT_a80264d8` | Bit mask of the memory interface field qsen_dly_b_sel for each data byte. | proven |
| `sys_ddr_qsen_dly_b_sel_regs` | `DAT_a80264e8` | Register of the memory interface field qsen_dly_b_sel for each data byte. | proven |
| `sys_ddr_qsen_dly_a_sel_shifts` | `DAT_a80264f8` | Bit position of the memory interface field qsen_dly_a_sel for each data byte. | proven |
| `sys_ddr_qsen_dly_a_sel_masks` | `DAT_a8026508` | Bit mask of the memory interface field qsen_dly_a_sel for each data byte. | proven |
| `sys_ddr_qsen_dly_a_sel_regs` | `DAT_a8026518` | Register of the memory interface field qsen_dly_a_sel for each data byte. | proven |
| `sys_ddr_qs_gate_field2_shifts` | `DAT_a8026528` | Bit position of the memory interface field qs_gate_field2 for each data byte. | descriptive |
| `sys_ddr_qs_gate_field2_masks` | `DAT_a8026538` | Bit mask of the memory interface field qs_gate_field2 for each data byte. | descriptive |
| `sys_ddr_qs_gate_field2_regs` | `DAT_a8026548` | Register of the memory interface field qs_gate_field2 for each data byte. | descriptive |
| `sys_ddr_qs_gate_field3_shifts` | `DAT_a8026558` | Bit position of the memory interface field qs_gate_field3 for each data byte. | descriptive |
| `sys_ddr_qs_gate_field3_masks` | `DAT_a8026568` | Bit mask of the memory interface field qs_gate_field3 for each data byte. | descriptive |
| `sys_ddr_qs_gate_field3_regs` | `DAT_a8026578` | Register of the memory interface field qs_gate_field3 for each data byte. | descriptive |
| `sys_ddr_qs_gate_field4_shifts` | `DAT_a8026588` | Bit position of the memory interface field qs_gate_field4 for each data byte. | descriptive |
| `sys_ddr_qs_gate_field4_masks` | `DAT_a8026598` | Bit mask of the memory interface field qs_gate_field4 for each data byte. | descriptive |
| `sys_ddr_qs_gate_field4_regs` | `DAT_a80265a8` | Register of the memory interface field qs_gate_field4 for each data byte. | descriptive |
| `sys_ddr_qs_gate_field6_shifts` | `DAT_a80265e8` | Bit position of the memory interface field qs_gate_field6 for each data byte. | descriptive |
| `sys_ddr_qs_gate_field6_masks` | `DAT_a80265f8` | Bit mask of the memory interface field qs_gate_field6 for each data byte. | descriptive |
| `sys_ddr_qs_gate_field6_regs` | `DAT_a8026608` | Register of the memory interface field qs_gate_field6 for each data byte. | descriptive |
| `sys_ddr_qs_late_shifts` | `DAT_a8026648` | Bit positions of the strobe 'late' field, one per data byte. | derived |
| `sys_ddr_qs_late_masks` | `DAT_a8026658` | Bit masks of the strobe 'late' field, one per data byte. | derived |
| `sys_ddr_qs_late_regs` | `DAT_a8026668` | Register numbers of the strobe 'late' field, one per data byte. | derived |
| `sys_ddr_qs_gate_sel_shifts` | `DAT_a80266a8` | Bit position of the memory interface field qs_gate_sel for each data byte. | proven |
| `sys_ddr_qs_gate_sel_masks` | `DAT_a80266b8` | Bit mask of the memory interface field qs_gate_sel for each data byte. | proven |
| `sys_ddr_qs_gate_sel_regs` | `DAT_a80266c8` | Register of the memory interface field qs_gate_sel for each data byte. | proven |
| `sys_ddr_qsen_wrap_dly_shifts` | `DAT_a80266d8` | Bit position of the memory interface field qsen_wrap_dly for each data byte. | proven |
| `sys_ddr_qsen_wrap_dly_masks` | `DAT_a80266e8` | Bit mask of the memory interface field qsen_wrap_dly for each data byte. | proven |
| `sys_ddr_qsen_wrap_dly_regs` | `DAT_a80266f8` | Register of the memory interface field qsen_wrap_dly for each data byte. | proven |
| `sys_ddr_write_delay_field1_masks` | `DAT_a8026708` | Bit mask of the memory interface field write_delay_field1 for each data byte. | descriptive |
| `sys_ddr_write_delay_field1_regs` | `ARR_a8026718` | Register numbers, one per data byte, of write delay field 1 (pairs with the field1 masks and shifts). | descriptive |
| `sys_ddr_wr_eye_lcdly_shifts` | `DAT_a8026728` | Bit positions, one per data byte, of the write delay field that is stepped together with clk_cdly. | descriptive |
| `sys_ddr_wr_eye_lcdly_masks` | `DAT_a8026738` | Bit masks, one per data byte, of the write delay field that is stepped together with clk_cdly. | descriptive |
| `sys_ddr_wr_eye_lcdly_regs` | `DAT_a8026748` | Register numbers, one per data byte, of the write delay field that is stepped together with clk_cdly. | descriptive |
| `sys_ddr_write_delay_field2_masks` | `DAT_a8026758` | Bit mask of the memory interface field write_delay_field2 for each data byte. | descriptive |
| `sys_ddr_write_delay_field2_regs` | `DAT_a8026768` | Register of the memory interface field write_delay_field2 for each data byte. | descriptive |
| `sys_ddr_write_clk_cdly_shifts` | `DAT_a8026778` | Bit positions, one per data byte, of the write delay field that the text "DQ clk cdly is full" names. | descriptive |
| `sys_ddr_write_clk_cdly_masks` | `DAT_a8026788` | Bit masks, one per data byte, of the write delay field that the text "DQ clk cdly is full" names. | descriptive |
| `sys_ddr_write_clk_cdly_regs` | `DAT_a8026798` | Register numbers, one per data byte, of the write delay field that the text "DQ clk cdly is full" names. | descriptive |
| `sys_ddr_write_level_field1_shifts` | `DAT_a80267a8` | Bit position of the memory interface field write_level_field1 for each data byte. | descriptive |
| `sys_ddr_write_level_field1_masks` | `DAT_a80267b8` | Bit mask of the memory interface field write_level_field1 for each data byte. | descriptive |
| `sys_ddr_write_level_field1_regs` | `DAT_a80267c8` | Register of the memory interface field write_level_field1 for each data byte. | descriptive |
| `sys_ddr_read_deskew_field1_masks` | `DAT_a80267d8` | Bit mask of the memory interface field read_deskew_field1 for each data byte. | descriptive |
| `sys_ddr_read_deskew_field1_regs` | `DAT_a80267e8` | Register of the memory interface field read_deskew_field1 for each data byte. | descriptive |
| `sys_ddr_read_deskew_field2_shifts` | `DAT_a80267f8` | Bit position of the memory interface field read_deskew_field2 for each data byte. | descriptive |
| `sys_ddr_read_deskew_field2_masks` | `DAT_a8026808` | Bit mask of the memory interface field read_deskew_field2 for each data byte. | descriptive |
| `sys_ddr_read_deskew_field2_regs` | `DAT_a8026818` | Register of the memory interface field read_deskew_field2 for each data byte. | descriptive |
| `sys_ddr_read_deskew_field3_masks` | `DAT_a8026828` | Bit mask of the memory interface field read_deskew_field3 for each data byte. | descriptive |
| `sys_ddr_read_deskew_field3_regs` | `DAT_a8026838` | Register of the memory interface field read_deskew_field3 for each data byte. | descriptive |
| `sys_ddr_write_level_field2_shifts` | `DAT_a8026848` | Bit position of the memory interface field write_level_field2 for each data byte. | descriptive |
| `sys_ddr_write_level_field2_masks` | `DAT_a8026858` | Bit mask of the memory interface field write_level_field2 for each data byte. | descriptive |
| `sys_ddr_write_level_field2_regs` | `DAT_a8026868` | Register of the memory interface field write_level_field2 for each data byte. | descriptive |
| `sys_ddr_write_leveling_field1_masks` | `DAT_a8026878` | Bit mask of the memory interface field write_leveling_field1 for each data byte. | descriptive |
| `sys_ddr_write_leveling_field1_regs` | `DAT_a8026888` | Register of the memory interface field write_leveling_field1 for each data byte. | descriptive |
| `sys_ddr_write_delay_field3_shifts` | `DAT_a8026898` | Bit position of the memory interface field write_delay_field3 for each data byte. | descriptive |
| `sys_ddr_write_delay_field3_masks` | `DAT_a80268a8` | Bit mask of the memory interface field write_delay_field3 for each data byte. | descriptive |
| `sys_ddr_write_delay_field3_regs` | `DAT_a80268b8` | Register of the memory interface field write_delay_field3 for each data byte. | descriptive |
| `sys_ddr_write_delay_field4_shifts` | `DAT_a80268c8` | Bit position of the memory interface field write_delay_field4 for each data byte. | descriptive |
| `sys_ddr_write_delay_field4_masks` | `DAT_a80268d8` | Bit mask of the memory interface field write_delay_field4 for each data byte. | descriptive |
| `sys_ddr_write_delay_field4_regs` | `DAT_a80268e8` | Register of the memory interface field write_delay_field4 for each data byte. | descriptive |
| `sys_ddr_write_delay_field5_shifts` | `DAT_a80268f8` | Bit position of the memory interface field write_delay_field5 for each data byte. | descriptive |
| `sys_ddr_write_delay_field5_masks` | `DAT_a8026908` | Bit mask of the memory interface field write_delay_field5 for each data byte. | descriptive |
| `sys_ddr_write_delay_field5_regs` | `DAT_a8026918` | Register of the memory interface field write_delay_field5 for each data byte. | descriptive |
| `sys_ddr_write_delay_field6_shifts` | `DAT_a8026928` | Bit position of the memory interface field write_delay_field6 for each data byte. | descriptive |
| `sys_ddr_write_delay_field6_masks` | `DAT_a8026938` | Bit mask of the memory interface field write_delay_field6 for each data byte. | descriptive |
| `sys_ddr_write_delay_field6_regs` | `DAT_a8026948` | Register of the memory interface field write_delay_field6 for each data byte. | descriptive |
| `sys_ddr_write_leveling_field2_shifts` | `DAT_a8026958` | Bit position of the memory interface field write_leveling_field2 for each data byte. | descriptive |
| `sys_ddr_write_leveling_field2_masks` | `DAT_a8026968` | Bit mask of the memory interface field write_leveling_field2 for each data byte. | descriptive |
| `sys_ddr_write_leveling_field2_regs` | `DAT_a8026978` | Register of the memory interface field write_leveling_field2 for each data byte. | descriptive |
| `sys_ddr_gate_pattern` | `DAT_a8026988` | Pattern byte sent with mode register 0xB and inverted at each gate test. | derived |
| `sys_ddr_gate_pattern_low_byte` | `DAT_a802698b` | The low byte of sys_ddr_gate_pattern, sent with mode register 0xB at the start. | derived |
| `sys_ddr_vref_high_indexes` | `DAT_a802698c` | Upper end of the passing reference voltage window (table index), per memory interface. | derived |
| `sys_ddr_vref_table` | `DAT_a8026998` | The reference voltage steps, three bytes each (mode register 6 value and range). | derived |
| `input_bring_up_lane` | `DAT_a8026a78` | The lane in use during port bring-up (0..3, 8 = all four). | derived |
| `input_bring_up_port` | `DAT_a8026a79` | The port that is being brought up. | proven |
| `reg_blockset6_bases` | `DAT_a8026a7a` | Register bases of the blocks of the sixth block set. | derived |
| `reg_blockset5_bases` | `DAT_a8026a7e` | Register bases of the blocks of the fifth block set. | derived |
| `ldc_reg8_value` | `DAT_a8026a88` | Value written to grid register 8: 1000 less the scaled timing value. | descriptive |
| `ldc_timing_scale` | `DAT_a8026a8a` | Scale of the timing value: 0x100 in modes 0 and 1, else 0x80. | derived |
| `ldc_mode3_sum_second` | `DAT_a8026a8c` | Second sum of the last mode 3 pass, written to register 0xD00400FC. | descriptive |
| `ldc_mode3_sum_first` | `DAT_a8026a8e` | First sum of the last mode 3 pass, written to register 0xD00400FC. | descriptive |
| `ldc_mode3_max_value` | `DAT_a8026a90` | Largest value found in the last mode 3 pass. | descriptive |
| `ldc_grid_table_select` | `DAT_a8026a92` | The grid table selector (bits 15..12 of 0xD0040098) last loaded. | derived |
| `ldc_cleared_on_array_refill` | `DAT_a8026a94` | Halfword set to 0 each time the three cell arrays are refilled; no routine reads it. | descriptive |
| `ldc_grid_table_5` | `DAT_a8026a96` | The 16 x 17 grid table loaded for selector 5. | derived |
| `ldc_grid_table_4` | `DAT_a8026cb6` | The 16 x 17 grid table loaded for selector 4. | derived |
| `ldc_grid_table_3` | `DAT_a8026ed6` | The 16 x 17 grid table loaded for selector 3. | derived |
| `ldc_grid_table_2` | `DAT_a80270f6` | The 16 x 17 grid table loaded for selector 2. | derived |
| `ldc_grid_table_1` | `DAT_a8027316` | The 16 x 17 grid table loaded for selector 1. | derived |
| `ldc_grid_table_0` | `DAT_a8027536` | The 16 x 17 grid table loaded for selector 0 and any other value. | derived |
| `ldc_cell_top_value` | `DAT_a8027756` | The largest 3 x 3 sum of the last mode 3 pass. | descriptive |
| `ldc_cell_smoothed_values` | `DAT_a8027758` | Running averages of the measured grid cells (14 x 26). | derived |
| `ldc_second_curve` | `DAT_a8027a30` | The second 17-point curve, copied into 12-bit register fields. | derived |
| `ldc_first_curve` | `DAT_a8027a52` | The first 17-point curve, copied into 12-bit register fields. | derived |
| `input_csc_option_byte` | `DAT_a8027a74` | Option byte of the colour format handling, taken over as the format code. | derived |
| `input_csc_format_code` | `DAT_a8027a75` | The current colour format code of the conversion set-up. | derived |
| `input_csc_selector` | `DAT_a8027a78` | The selector the colour format set-up runs with (0..2). | derived |
| `input_csc_last_format_code` | `DAT_a8027a7c` | The format code last written by input_csc_write_mode_regs. | derived |
| `panel_output_flag` | `DAT_a8027a80` | The output driver's flag value. | descriptive |
| `input_pin_config_bytes` | `DAT_a8027a82` | The five pin configuration bytes of the inputs. | derived |
| `input_pin_config_byte2` | `DAT_a8027a84` | Pin configuration byte 2. | derived |
| `gpio_pin_register_copy` | `DAT_a8027a87` | Copy of the pin register 0xCF03C1A8, changed bit by bit and written back. | derived |
| `panel_layer_update_strobe_enabled` | `DAT_a8027a88` | 1 = layer routines request the layer update after a change and wait until it is taken; else they do neither. | derived |
| `dbg_ddr_test_state` | `DAT_a8027a90` | The state record of the memory stress test (four bytes). | derived |
| `sys_frc_mode` | `DAT_a8027a94` | The current mode of the frame-rate converter. | derived |
| `pq_block8_config` | `DAT_a8027a98` | The 16-byte configuration record of picture block 8. | derived |
| `osd_layer_bases` | `DAT_a8027aa8` | Register base of each of the two menu layers. | proven |
| `input_block_configs` | `DAT_a8027aac` | The 12-byte configuration of each input block. | derived |
| `panel_vx1_second_param` | `DAT_a8027b0c` | The second V-by-One parameter, used when the lanes are set up. | descriptive |
| `pq_gamma_set_table` | `DAT_a8027ba8` | For each gamma set number: pointer to its secondary tables and pointer to its curves. | derived |
| `pq_gamma_set_table_curve` | `DAT_a8027bac` | The curve pointer of the first gamma set entry. | derived |
| `pq_response_level_tables` | `DAT_a8027bb0` | The table set pointer for each response level. | derived |
| `sys_ddr_script_new` | `DAT_a8027bc0` | The memory training script used when the board strap says 'New DDR'. | proven |
| `sys_ddr_script_old` | `DAT_a8028ff0` | The memory training script used when the board strap says 'Old DDR'. | proven |
| `input_last_gpio2_bit0_pin` | `DAT_a802a420` | GPIO port 2 bit 0 at the last pin check: 2 = high, 0 = low, 0xFF = none seen yet. | derived |
| `input_last_gpio2_bit3_pin` | `DAT_a802a421` | GPIO port 2 bit 3 at the last pin check (0xFF = none seen yet). | derived |
| `ddc_port_slave_addresses` | `ARR_a802a428` | DDC/CI slave address of each port 0..7 (0x6E at power-on for ports 0..6), sent to the 8051 with command 0x07. | derived |
| `i2c_bus0_descriptors` | `DAT_a802a430` | Descriptors of the devices on software I2C bus 0. | descriptive |
| `oled_care_table` | `DAT_a802a440` | The four-entry OLED care table. | descriptive |
| `oled_care_table_last` | `DAT_a802a443` | The last entry of the OLED care table, returned for index 0xFF. | derived |
| `panel_level_gen_level` | `DAT_a802a448` | The current level of the level generator. | derived |
| `panel_level_gen_target` | `DAT_a802a449` | The target level of the level generator, computed from the configuration. | derived |
| `panel_level_gen_index` | `DAT_a802a44a` | The selected entry of the level step table (0x18..0x3F). | derived |
| `panel_level_gen_last_value` | `DAT_a802a44b` | The value the table entry was last chosen for. | derived |
| `sys_source_b1_block` | `DAT_a802a44c` | The input block given source code 0xB1 by the mode handler (0xFF = none). | descriptive |
| `sys_mode_handler_port` | `DAT_a802a44d` | The port entry last taken by the mode handler. | descriptive |
| `ipc_input_cpu_port_nibbles` | `DAT_a802a450` | Eight 4-bit port values packed into one word for the input processor. | derived |
| `ipc_input_cpu_word_byte2` | `DAT_a802a457` | The byte placed in bits 16..23 of the words written to the input processor. | descriptive |
| `ldc_cmd35_last_value` | `DAT_a802a458` | The value last sent with dimming command 0x35. | derived |
| `ldc_cmd82_last_mode` | `DAT_a802a45a` | The mode byte last sent with dimming command 0x82. | derived |
| `ldc_cmd30_last_level` | `DAT_a802a45c` | The level last sent with dimming command 0x30. | derived |
| `pq_color_matrix_scale` | `DAT_a802a460` | The scale the colour matrix is built with. | proven |
| `pq_color_matrix_param_first` | `DAT_a802a461` | The first (signed) colour matrix parameter. | derived |
| `pq_color_matrix_param_second` | `DAT_a802a462` | The second colour matrix parameter. | derived |
| `pq_color_offsets` | `DAT_a802a468` | The three offset values the colour matrix is built from. | proven |
| `pq_color_gains` | `DAT_a802a46c` | The three gain values the colour matrix is built from. | proven |
| `pq_color_gains_green` | `_DAT_a802a46e` | The second gain value of the colour matrix. | proven |
| `pq_color_gains_blue` | `_DAT_a802a470` | The third gain value of the colour matrix. | proven |
| `nvram_new_row_marker` | `DAT_a802a478` | Byte copied into the last byte of the 8051 flash buffer before the new row is programmed (0x55 in FW.021). | descriptive |
| `nvram_pending_flash_row` | `DAT_a802a47a` | The flash row whose data waits to be written. | derived |
| `pq_response_level_last` | `DAT_a802a47c` | The response level last applied. | derived |
| `sys_event_code` | `DAT_a802a47d` | The stored event code. | derived |
| `dbg_ddr_stress_stopped` | `DAT_a802a47e` | 1 = no memory stress run in progress (start value); cleared when a run starts, set again at its end. | derived |
| `audio_slot_owners` | `DAT_a802a480` | The source that owns each of the nine audio output slots. | proven |
| `panel_blurfree_second_port` | `DAT_a802a49a` | The port of the second blur-reduction PWM signal. | derived |
| `panel_blurfree_first_pwm_freq` | `_DAT_a802a49c` | The frequency of the first blur-reduction PWM signal. | derived |
| `panel_blurfree_duty_offset` | `_DAT_a802a49e` | The duty offset of the blur-reduction PWM. | derived |
| `panel_blurfree_second_pwm_freq` | `_DAT_a802a4a0` | The frequency of the second blur-reduction PWM signal: the usSecondPWMFreq parameter times 100. | derived |
| `panel_blurfree_task_threshold` | `DAT_a802a4a2` | The threshold the periodic blur-reduction task compares against. | derived |
| `panel_blurfree_channel_delays` | `DAT_a802a4a8` | The stored delay of each of the eight PWM channels. | derived |
| `panel_blurfree_channel_delay_1` | `DAT_a802a4a9` | The stored delay of PWM channel 1. | derived |
| `panel_blurfree_channel_delay_2` | `DAT_a802a4aa` | The stored delay of PWM channel 2. | derived |
| `panel_blurfree_channel_delay_3` | `DAT_a802a4ab` | The stored delay of PWM channel 3. | derived |
| `panel_blurfree_channel_delay_4` | `DAT_a802a4ac` | The stored delay of PWM channel 4. | derived |
| `panel_blurfree_channel_delay_5` | `DAT_a802a4ad` | The stored delay of PWM channel 5. | derived |
| `panel_blurfree_channel_delay_6` | `DAT_a802a4ae` | The stored delay of PWM channel 6. | derived |
| `panel_blurfree_channel_delay_7` | `DAT_a802a4af` | The stored delay of PWM channel 7. | derived |
| `panel_blurfree_cycle_length` | `DAT_a802a4b0` | The cycle length of the first blur-reduction PWM signal. | derived |
| `panel_blurfree_on_time` | `_DAT_a802a4b2` | The on-time of the first blur-reduction PWM signal. | derived |
| `sys_picture_init_record` | `DAT_a802a4b8` | Record whose two mode bits sys_init_picture_blocks sets. | descriptive |
| `ldc_menu_layer_status_last` | `DAT_a802a4bc` | The value last sent with ldc_write_status_word: -1 when menu layer 0 or 1 is on, else 0. | derived |
| `sys_status_refresh_request` | `DAT_a802a4c0` | Set to 1 to have the input status codes refreshed. | derived |
| `_impure_ptr` | `_DAT_a802aa18` | Pointer to the current reentrancy structure of the C library. | proven |
| `libc_locale_charset` | `DAT_a802aaa8` | The character-set name pointer returned by __locale_charset. | derived |
| `app_settings_1b4_copy` | `DAT_a802af40` | Copy of settings byte +0x1B4, kept to see its change before display. | derived |
| `app_flags` | `DAT_a802af41` | Application flag bits: bit 0 logo hold, bit 3 read with sys_get_app_flag_bit3. | derived |
| `app_port_flags` | `DAT_a802af42` | Application flag bits: three per port (bits n, 5+n, 10+n) and three for all ports (bits 4, 9, 14). | derived |
| `app_flags_second` | `DAT_a802af44` | A second byte of application flag bits. | descriptive |
| `app_port_rearm_bits` | `DAT_a802af45` | One bit per port that forces its pending event again. | derived |
| `sys_aux0_time_step_count` | `DAT_a802af47` | Counts the 20 s steps (1..3) of a minute while gpio_is_aux_bit0_high answers 1, which it never does. | derived |
| `sys_oled_error_stored` | `DAT_a802af48` | Set to 1 once the first OLED error detection after start-up has been counted in the factory record. | derived |
| `app_event_pending_last` | `DAT_a802af49` | The pending-event state seen at the last event pass. | derived |
| `app_port_events_ready` | `DAT_a802af4a` | 0 until sys_app_generate_events has filled its per-port tables the first time, then 1. | derived |
| `app_port_pending_events` | `DAT_a802af50` | The event waiting for each port (0x3F = none). | derived |
| `panel_burnin_colour_index` | `DAT_a802af54` | Which of the nine burn-in test colours is shown next. | proven |
| `pq_ch1_last_ratio` | `DAT_a802af56` | The last width-to-height ratio of channel 1, in tenths. | derived |
| `pq_ch1_last_third_value` | `DAT_a802af58` | The kept third measured value of channel 1. | derived |
| `pq_ch1_last_width` | `DAT_a802af5a` | The kept measured width of channel 1. | derived |
| `pq_ch1_change_count` | `DAT_a802af5c` | How many checks in a row channel 1 showed a size change. | derived |
| `app_port_last_states` | `DAT_a802af60` | The last state byte of each port (0xFF after a re-arm). | derived |
| `app_port_active_bits` | `DAT_a802af64` | One bit per port: the activity seen at the last event pass. | derived |
| `app_timers_snapshot` | `DAT_a802af68` | The tick count at which the application timers were last aged. | derived |
| `app_timers` | `DAT_a802af6a` | The 23 application timers: millisecond down-counters. | proven |
| `ddc_pending_events` | `DAT_a802af99` | Pending DDC/CI event flags, bits 0..6. | proven |
| `ddc_request_record` | `DAT_a802af9a` | Working record of the SetVCP 0xFA block write: address, read-back sum, block end. | derived |
| `ddc_reply_checksum` | `DAT_a802af9e` | The DDC/CI reply XOR checksum (seed 0x50). | proven |
| `app_event_read_index` | `DAT_a802afa0` | Read position in the application event queue while events are dispatched. | derived |
| `app_event_count` | `DAT_a802afa1` | Number of events in the application event queue. | derived |
| `app_event_queue` | `DAT_a802afa8` | The application event queue: up to ten pending events. | proven |
| `osd_factory_ssc_freq` | `DAT_a802afb8` | The spread-spectrum frequency choice of the factory menu. | proven |
| `osd_factory_ssc_ratio` | `DAT_a802afb9` | The spread-spectrum ratio value of the factory menu. | proven |
| `osd_factory_dummy_value` | `DAT_a802afba` | Value of factory menu item 22 "Dummy": 0 = inspection mode off, 1..7 = inspection pattern. | proven |
| `osd_factory_drawn_flag` | `DAT_a802afbb` | Set when the factory menu or info page is drawn, cleared when an item runs. | descriptive |
| `osd_factory_panel_npc_value` | `DAT_a802afbc` | The value shown for factory menu item 21 "Panel NPC" (the OLED luminance mode). | proven |
| `osd_factory_item` | `DAT_a802afbd` | The highlighted item of the factory menu. | proven |
| `osd_factory_item20_switch` | `DAT_a802afbe` | The switch of factory item 0x14 (settings +0x1D4 bit 6) while it is edited. | derived |
| `sys_key_blocked_mask` | `DAT_a802afc0` | One bit per front key that is blocked. | proven |
| `sys_key_long_codes` | `DAT_a802afc8` | The second event code each key sends when held long. | proven |
| `sys_key_long_alt_mask` | `DAT_a802afd8` | One bit per key that sends its second event code when held long. | proven |
| `sys_key_long_only_mask` | `DAT_a802afda` | One bit per key that acts only after the long-press time. | proven |
| `sys_key_repeat_mask` | `DAT_a802afdc` | One bit per key that repeats while held. | proven |
| `sys_key_hold_ticks` | `DAT_a802afde` | Time stamp of the start of the current key hold or repeat step. | derived |
| `sys_key_wait_time` | `DAT_a802afe0` | The hold time now waited for: repeat delay, repeat interval or long-press time. | derived |
| `sys_key_last_entry` | `DAT_a802afe2` | Entry number 0..15 in sys_key_code_table of the key seen at the last key scan (not the scan code). | derived |
| `sys_key_mode` | `DAT_a802afe4` | Mode of the held key: 0 none, 1 repeat, 2 long-press only, 3 long or short, 4 blocked. | derived |
| `osd_last_key_ticks` | `DAT_a802afe8` | Time stamp of the last key handled by the menu. | derived |
| `osd_alarm_clock_choice` | `DAT_a802afea` | The Alarm Clock choice while its list is open (settings +0x1A0). | derived |
| `osd_menu_state` | `_DAT_a802afec` | The screen the menu is on (0 = closed). | proven |
| `osd_menu_state_low16` | `_DAT_a802afee` | The low half of the menu state word. | proven |
| `osd_led_bar_query_sent` | `DAT_a802aff0` | Set to 1 when sys_led_bar_send_query was sent 29 s into the panel protect wait; cleared with the wait. | derived |
| `osd_protect_prompt_step` | `DAT_a802aff1` | The panel protect step code whose prompt is shown. | derived |
| `osd_seconds_countdown` | `DAT_a802aff2` | The menu's one-second countdown. | proven |
| `osd_text_field_width` | `DAT_a802aff4` | The text field width used by the text drawer. | proven |
| `osd_text_column_buffer` | `DAT_a802aff8` | The glyph columns of the text being drawn. | derived |
| `osd_last_text_width` | `DAT_a802b088` | The pixel width of the text drawn last. | proven |
| `osd_shown_refresh_rate` | `DAT_a802b08c` | The refresh rate last shown by the refresh rate overlay. | derived |
| `osd_gaming_page_drawn` | `DAT_a802b08d` | The Gaming item page drawn last. | derived |
| `osd_request_bits` | `DAT_a802b08e` | Menu request bits for the main loop; bit 1 = settings changed. | derived |
| `osd_list_id` | `DAT_a802b08f` | Which item or choice list the menu has open (0 = main menu). | descriptive |
| `osd_crosshair_color_step` | `DAT_a802b090` | The step of the automatic crosshair colour last applied. | descriptive |
| `osd_crosshair_icon_last` | `DAT_a802b091` | The crosshair icon (settings +0x190) the colour was last set for. | derived |
| `uart_cmd_wait_flag` | `DAT_a802b096` | Set while a tool command port waits for the rest of a frame. | descriptive |
| `uart_cmd_rx_state_port3` | `DAT_a802b098` | Receive index byte of tool command port 3 (pairs with uart_cmd_rx_record_port3). | derived |
| `uart_cmd_wait_flag_port2` | `DAT_a802b099` | Set while command port 2 waits for the rest of a frame. | descriptive |
| `uart_cmd_rx_state_port2` | `DAT_a802b09a` | Receive state of command port 2. | descriptive |
| `uart_cmd_power_request` | `DAT_a802b09b` | Set by a PC tool power command. | derived |
| `uart_cmd_rx_count` | `DAT_a802b09c` | Number of bytes received into the tool command record. | derived |
| `ddc_tool_inverted_flag` | `DAT_a802b09d` | Flag byte set from the inverse of a factory tool on/off value. | descriptive |
| `ddc_tool_read_address_high` | `DAT_a802b09e` | First address byte for the next factory tool table read. | derived |
| `ddc_tool_read_address_low` | `DAT_a802b09f` | Second address byte for the next factory tool table read. | derived |
| `ddc_color_entry_byte2` | `DAT_a802b0a0` | Third byte of the colour entry set over DDC/CI (part record +8 and +0x23). | descriptive |
| `ddc_color_entry_byte1` | `DAT_a802b0a1` | Second byte of the colour entry set over DDC/CI (part record +7 and +0x22). | descriptive |
| `ddc_color_entry_byte0` | `DAT_a802b0a2` | First byte of the colour entry set over DDC/CI (part record +6 and +0x21). | descriptive |
| `dbg_ddr_stress_param` | `DAT_a802b0a8` | The parameter of the memory stress test. | proven |
| `dbg_ddr_stress_enabled` | `DAT_a802b0ac` | Whether the memory stress test is switched on. | proven |
| `dbg_dithering_off_flag` | `DAT_a802b0ad` | Set while dbg_switch_dithering has switched dithering off (modes 1 and 2). | derived |
| `dbg_dithering_off_mode2_flag` | `DAT_a802b0ae` | Set when dbg_switch_dithering switched dithering off with mode 2. | derived |
| `dbg_print_mask` | `DAT_a802b0b0` | One bit per class of debug messages that is printed. | proven |
| `timer_isr_count` | `DAT_a802b0b4` | Counts every timer tick interrupt. | derived |
| `timer_128_tick_counter` | `DAT_a802b0b8` | Counts ticks up to 128 for the 128-tick flag. | derived |
| `timer_128_tick_enable` | `DAT_a802b0bc` | When nonzero the tick interrupt raises the timer flag every 128 ticks. | derived |
| `timer_flag` | `DAT_a802b0bd` | The timer flag byte, raised every 128 ticks when enabled. | proven |
| `timer_sleep_countdown` | `_DAT_a802b0c0` | Down-counter of timer_sleep_ticks. | proven |
| `timer_tick_record` | `DAT_a802b0c4` | The tick record: the tick count and the tick hooks. | proven |
| `timer_tick_record_count` | `DAT_a802b0c8` | The 32-bit tick counter of the tick record. | proven |
| `timer_tick_record_count_low16` | `_DAT_a802b0ca` | The low 16 bits of the tick counter. | proven |
| `timer_hook1` | `_DAT_a802b0d4` | Timer hook 1, called with 1 when set. | proven |
| `timer_hook3` | `_DAT_a802b0dc` | Timer hook 3, called with 3 when set. | proven |
| `timer_hook4` | `_DAT_a802b0e0` | Timer hook 4, called with 4 when set. | proven |
| `dbg_uart_rx_ring` | `DAT_a802b0ec` | Receive ring buffer of the debug serial port: 128 bytes, then head and tail. | proven |
| `irq_source_hooks` | `DAT_a802b170` | The handler registered for each source of each interrupt level (15 x 16 entries). | proven |
| `sys_ddr_step_record` | `DAT_a802b530` | The current training step, memory interface and data byte, for error messages. | proven |
| `sys_ddr_param2_set_flag` | `DAT_a802b53c` | Set when the third training parameter was set explicitly. | derived |
| `sys_ddr_param1_set_flag` | `DAT_a802b548` | Set when the second training parameter was set explicitly. | derived |
| `sys_ddr_param0_set_flag` | `DAT_a802b54c` | Set when the first training parameter was set explicitly. | derived |
| `sys_ddr_register_trace_enabled` | `DAT_a802b550` | Third memory training parameter: non-zero makes the register routines print each value read back. | derived |
| `sys_ddr_param1` | `DAT_a802b554` | The second memory training parameter. | proven |
| `sys_ddr_unit3_value2_shifts` | `DAT_a802b580` | Shift of value field 2 of calibration unit 3, per N_adj 0..9. | derived |
| `sys_ddr_unit2_value2_shifts` | `DAT_a802b5a8` | Shift of value field 2 of calibration unit 2, per N_adj 0..9. | derived |
| `sys_ddr_unit1_value2_shifts` | `DAT_a802b5d0` | Shift of value field 2 of calibration unit 1, per N_adj 0..9. | derived |
| `sys_ddr_dq_fail_shifts` | `DAT_a802b618` | Bit positions of the data line fail bits (one bit per line, set when the last self-test failed on it). | descriptive |
| `sys_ddr_dly_per_cnt_shifts` | `DAT_a802b638` | Bit positions, one per data byte, of the field that gives the delay units in one whole write step. | descriptive |
| `sys_ddr_read_eye_field1_shifts` | `DAT_a802b648` | Bit position of the memory interface field read_eye_field1 for each data byte. | descriptive |
| `sys_ddr_read_eye_field2_shifts` | `DAT_a802b658` | Bit position of the memory interface field read_eye_field2 for each data byte. | descriptive |
| `sys_ddr_read_eye_field3_shifts` | `DAT_a802b668` | Bit position of the memory interface field read_eye_field3 for each data byte. | descriptive |
| `sys_ddr_gate_check_field1_shifts` | `DAT_a802b688` | Bit position of the memory interface field gate_check_field1 for each data byte. | descriptive |
| `sys_ddr_gate_check_field2_shifts` | `DAT_a802b698` | Bit position of the memory interface field gate_check_field2 for each data byte. | descriptive |
| `sys_ddr_gate_check_field3_shifts` | `DAT_a802b6a8` | Bit position of the memory interface field gate_check_field3 for each data byte. | descriptive |
| `sys_ddr_gate_check_field4_shifts` | `DAT_a802b6b8` | Bit position of the memory interface field gate_check_field4 for each data byte. | descriptive |
| `sys_ddr_write_delay_field1_shifts` | `DAT_a802b6d8` | Bit position of the memory interface field write_delay_field1 for each data byte. | descriptive |
| `sys_ddr_write_delay_field2_shifts` | `DAT_a802b6e8` | Bit position of the memory interface field write_delay_field2 for each data byte. | descriptive |
| `sys_ddr_read_deskew_field1_shifts` | `DAT_a802b6f8` | Bit position of the memory interface field read_deskew_field1 for each data byte. | descriptive |
| `sys_ddr_read_deskew_field3_shifts` | `DAT_a802b708` | Bit position of the memory interface field read_deskew_field3 for each data byte. | descriptive |
| `sys_ddr_write_leveling_field1_shifts` | `DAT_a802b718` | Bit position of the memory interface field write_leveling_field1 for each data byte. | descriptive |
| `sys_ddr_cal_compare_mode` | `_DAT_a802b728` | Which of the two measured sums must be larger in the calibration search (0 or 1). | derived |
| `sys_ddr_bist_write_toggle` | `DAT_a802b72c` | Word flipped (xor 1) once per attempt of sys_ddr_run_bist_write; no routine reads it. | descriptive |
| `sys_ddr_vref_low_indexes` | `DAT_a802b730` | Lower end of the passing reference voltage window (table index), per memory interface. | derived |
| `input_bring_up_retry_count_ports_3_7` | `DAT_a802b740` | Retry count of the port lock during bring-up, shared by ports 3 and 7. | derived |
| `input_bring_up_done_ports_3_7` | `DAT_a802b742` | Done flag of the port lock during bring-up, shared by ports 3 and 7. | derived |
| `input_bring_up_retry_count_ports_2_6` | `DAT_a802b744` | Retry count of the port lock during bring-up, shared by ports 2 and 6. | derived |
| `input_bring_up_done_ports_2_6` | `DAT_a802b746` | Done flag of the port lock during bring-up, shared by ports 2 and 6. | derived |
| `input_bring_up_clock_flag` | `DAT_a802b747` | Cleared when the pixel clock is programmed; tested by the port lock. | descriptive |
| `input_bring_up_start_tick_ports_3_7` | `DAT_a802b748` | Tick stamp of the start of the port lock during bring-up, shared by ports 3 and 7. | derived |
| `input_bring_up_start_tick_ports_2_6` | `DAT_a802b74a` | Tick stamp of the start of the port lock during bring-up, shared by ports 2 and 6. | derived |
| `input_bring_up_vactive` | `DAT_a802b74c` | Active height used to scale the vertical total in the pixel clock computation. | derived |
| `input_bring_up_hactive` | `DAT_a802b74e` | Active width used to scale the horizontal total in the pixel clock computation. | derived |
| `input_bring_up_reg51_flags` | `DAT_a802b750` | Step direction flags of register 0x51 during bring-up. | derived |
| `input_bring_up_reg51_value` | `DAT_a802b751` | The value last written to register 0x51 of the picture block. | derived |
| `input_free_run_fail_counts` | `DAT_a802b758` | Failed free-run checks in a row, per port of the pair. | derived |
| `input_free_run_on_counts` | `DAT_a802b760` | Count printed with the ON state of the free-run check, per port of the pair. | descriptive |
| `input_free_run_start_ticks` | `DAT_a802b762` | Time stamp of the start of the free-run check, per port of the pair. | derived |
| `input_free_run_pass_ticks` | `DAT_a802b766` | Time stamp of the passing free-run reading, per port of the pair. | descriptive |
| `input_free_run_wait_ticks` | `DAT_a802b76a` | Ticks the free-run check waits (0x32, then 2), per port of the pair. | descriptive |
| `input_adc_record` | `DAT_a802b770` | The record of the analogue input stage: on state, hooks and settings. | derived |
| `input_adc_clock_target` | `DAT_a802b794` | The clock value the stage waits for after a width change (-1 = none). | descriptive |
| `input_adc_levels_done` | `DAT_a802b798` | Set when the level calibration has stored its averages. | descriptive |
| `input_adc_cal_hooks` | `DAT_a802b79c` | The calibration's four-entry hook record. | proven |
| `input_adc_cal_hook1` | `DAT_a802b7a0` | Entry 1 of the calibration hook record. | proven |
| `input_adc_cal_hook2` | `DAT_a802b7a4` | Entry 2 of the calibration hook record. | proven |
| `input_adc_cal_hook3` | `DAT_a802b7a8` | Entry 3 of the calibration hook record. | proven |
| `input_adc_adjust_aborted` | `DAT_a802b7ac` | 1 when a wait of a measurement or adjustment step was given up; cleared when an area measurement starts. | derived |
| `input_adc_adjust_failed` | `DAT_a802b7ad` | 1 when a stage of the automatic adjustment failed; cleared before the last stage and tested for success. | derived |
| `input_adc_phase_scan_count` | `DAT_a802b7ae` | The number of phase steps the automatic adjustment scans: 0x10 or 0x20. | derived |
| `input_adc_phase_first` | `DAT_a802b7af` | First sampling position found by the phase search. | derived |
| `input_adc_phase_second` | `DAT_a802b7b0` | Second sampling position found by the phase search. | derived |
| `input_adc_progress` | `DAT_a802b7b1` | Progress value handed to calibration hook 0 (up to 99). | derived |
| `pq_selected_window` | `DAT_a802b7b4` | The picture window that picture settings currently go to. | proven |
| `pq_window_item_hook` | `_DAT_a802b7b8` | Routine the pq_window_set_item routines call (ipc_8051_set_option_byte). | derived |
| `input_block_sample_average1` | `DAT_a802b7bc` | First of the three sample averages of an input block. | derived |
| `input_block_sample_average2` | `DAT_a802b7c0` | Second of the three sample averages of an input block. | derived |
| `input_block_sample_average3` | `DAT_a802b7c4` | Third of the three sample averages of an input block. | derived |
| `input_block_sample_phase` | `DAT_a802b7c8` | Which average input_block_accumulate_samples is working on. | descriptive |
| `input_block_sample_sum` | `DAT_a802b7cc` | Running weighted sum of the samples (divided by 5000). | derived |
| `input_block_sample_sum2` | `DAT_a802b7d0` | Second running weighted sum of the samples. | derived |
| `input_block_sample_sum3` | `DAT_a802b7d4` | Third running weighted sum of the samples. | derived |
| `input_block_offsets` | `DAT_a802b7d8` | The stored offset of each input block, added to its capture width. | derived |
| `ldc_saved_enable_bit` | `DAT_a802b7e8` | The grid block's enable bit saved at suspend, restored at resume. | derived |
| `ldc_started_flag` | `DAT_a802b7ea` | Set once the grid block has been started. | derived |
| `ldc_cmd_strength_arg` | `DAT_a802b7eb` | Argument of the strength command of the grid block. | derived |
| `ldc_cmd_timing_arg` | `DAT_a802b7ec` | Argument of the timing command of the grid block. | derived |
| `ldc_cmd_suspend_arg` | `DAT_a802b7ef` | Argument of the suspend command of the grid block. | derived |
| `ldc_mode3_setup_state` | `DAT_a802b7f0` | Zero until the mode 3 registers and arrays have been set up. | descriptive |
| `ldc_mode3_pass_count` | `DAT_a802b7f4` | Counts the mode 3 passes. | derived |
| `ldc_mode` | `DAT_a802b7f8` | The grid block mode last read from register 0xD00400D8 bits 3..0. | derived |
| `ldc_timing_value` | `DAT_a802b7fa` | The timing value that ldc_hw_set_timing scales. | descriptive |
| `ldc_timing_mode` | `DAT_a802b7fc` | The mode stored by ldc_hw_set_timing and written to register 0xD00400D8. | derived |
| `ldc_last_register_offset` | `DAT_a802b7fd` | Offset of the grid block register last accessed. | descriptive |
| `ldc_level_changed_flag` | `DAT_a802b7fe` | Set when the top two bits of the level field changed. | derived |
| `ldc_array_first` | `DAT_a802b800` | The first of the three 0x120-entry arrays written to the grid block. | descriptive |
| `ldc_array_second` | `DAT_a802ba40` | The second of the three 0x120-entry arrays written to the grid block. | descriptive |
| `ldc_array_third` | `DAT_a802bc80` | The third of the three 0x120-entry arrays written to the grid block. | descriptive |
| `ldc_level_field` | `DAT_a802bec0` | The 10-bit level field copied from the grid block register. | derived |
| `ldc_level_field_applied` | `DAT_a802bec2` | The level field value the arrays were last filled from. | derived |
| `ldc_mode3_busy_flag` | `DAT_a802bec4` | Set while a mode 3 pass runs. | derived |
| `ldc_mode3_array` | `DAT_a802bec6` | A 0x120-entry array filled from the smoothed cells in mode 3. | descriptive |
| `ldc_cell_values` | `DAT_a802c106` | The 14 x 26 cell values computed in mode 3. | descriptive |
| `ldc_cell_reads_first` | `DAT_a802c3de` | High fields (bits 10..23, shifted, at most 0x3FF) of the cells read from 0xD00400CC and 0xD00402CC. | descriptive |
| `ldc_cell_reads_second` | `DAT_a802c61e` | Low fields (bits 0..9, shifted, at most 0x3FF) of the cells read from 0xD00400CC and 0xD00402CC. | descriptive |
| `ldc_level_top_bits` | `DAT_a802c85e` | The top two bits of the level field seen last. | derived |
| `ldc_last_array_word` | `DAT_a802c860` | The last control word written after the arrays. | descriptive |
| `ldc_work_table` | `DAT_a802c864` | Working grid table of the current mode, rows of 8 halfwords. | derived |
| `hdmi_cec_rx_message` | `DAT_a802c968` | The five stored bytes of the last CEC message received. | derived |
| `hdmi_cec_send_hook` | `_DAT_a802c970` | The routine the CEC code sends its messages with. | proven |
| `hdmi_cec_rx_word` | `DAT_a802c978` | Four stored CEC message bytes, returned as one word. | derived |
| `hdmi_cec_rx_flags` | `DAT_a802c97c` | Bits for the kinds of CEC message kept for the caller; all cleared when the command is taken. | derived |
| `hdmi_cec_peer_address` | `DAT_a802c97d` | CEC address of the device that sent the last message; replies and requests go to it (0xF: none yet). | derived |
| `hdmi_cec_sender` | `DAT_a802c97e` | The byte that accompanies the last CEC command. | derived |
| `hdmi_cec_operand` | `DAT_a802c97f` | The operand of the last CEC command. | proven |
| `input_pending_source` | `DAT_a802c980` | The source code stored as pending. | proven |
| `panel_level_gen_ramp_value` | `DAT_a802c981` | The level generator's ramp value. | derived |
| `panel_clock_saved_reg50` | `DAT_a802c982` | Register 0x50 of the picture block saved by the output clock correction. | derived |
| `panel_clock_saved_reg88` | `DAT_a802c983` | Register 0x88 of the picture block saved by the output clock correction. | derived |
| `panel_clock_saved_reg86` | `DAT_a802c984` | Register 0x86 of the picture block saved by the output clock correction. | derived |
| `sys_frc_post_last_rate` | `DAT_a802c986` | The rate the output behind the frame-rate converter was last set up for. | derived |
| `sys_request_byte` | `DAT_a802c988` | A byte stored from the caller, read by the V-by-One start sequence. | descriptive |
| `dbg_ddr_result_first` | `DAT_a802c98c` | The first stored result byte of the memory stress test. | proven |
| `dbg_ddr_result_second` | `DAT_a802c98d` | The second stored result byte of the memory stress test. | proven |
| `sys_frc_config_index` | `DAT_a802c98e` | The first index that selects the frame-rate converter's ROM settings. | proven |
| `sys_frc_config_index2` | `DAT_a802c98f` | The second index that selects the frame-rate converter's ROM settings. | derived |
| `sys_region_base_first` | `DAT_a802c990` | First memory region base set from the ROM settings. | descriptive |
| `sys_region_base_second` | `DAT_a802c994` | Second memory region base set from the ROM settings. | descriptive |
| `sys_region_base_third` | `DAT_a802c998` | Third memory region base set from the ROM settings. | descriptive |
| `pq_block8_reg50_count` | `DAT_a802c99c` | Count kept by pq_block8_count_reg50_step: calls that found bit 0 of block register 0x50 set (0..50). | descriptive |
| `osd_glyph_write_count` | `DAT_a802c9a0` | Count for the next glyph data written to a menu layer's memory. | derived |
| `osd_glyph_write_address` | `DAT_a802c9a2` | Address for the next glyph data written to a menu layer's memory. | derived |
| `osd_layer_text_modes` | `ARR_a802c9a8` | One word per menu layer; its low byte is the text alignment mode set by osd_set_text_mode. | derived |
| `osd_option_byte` | `DAT_a802c9b0` | Option byte with two 2-bit fields (orientation of the menu windows). | derived |
| `osd_cell_heights` | `DAT_a802c9b8` | The character cell height of each menu layer in lines (16, 18 or 36). | derived |
| `osd_cell_widths` | `DAT_a802c9c0` | The character cell width of each menu layer in pixels (10, 12 or 24). | derived |
| `osd_layer_rows` | `ARR_a802c9c8` | The number of character rows of each menu layer (byte per layer). | derived |
| `osd_layer_columns` | `ARR_a802c9ca` | The number of character columns of each menu layer (halfword per layer). | derived |
| `osd_layer_x_scales` | `DAT_a802c9d0` | Horizontal scale of each menu layer for window rectangles. | derived |
| `osd_layer_y_scales` | `DAT_a802c9d8` | Vertical scale of each menu layer for window rectangles. | derived |
| `sys_unit0_hook` | `DAT_a802c9e0` | The hook called when unit 0 has latched its event. | derived |
| `sys_unit_event_bits` | `DAT_a802c9e4` | Event bits of the units and input blocks (bit n = unit n). | derived |
| `input_measured_hfreq` | `DAT_a802c9e8` | Horizontal frequency last measured: 120000 / (count + 1), 0xFFFF = none. | derived |
| `panel_vx1_first_param` | `DAT_a802c9ec` | The first V-by-One parameter, used when the lanes are set up. | descriptive |
| `fwupd_progress_percent` | `DAT_a802c9f0` | The transfer progress of the firmware update in percent. | proven |
| `fwupd_progress_hook` | `DAT_a802c9f4` | Routine that the update progress loop calls each time the progress percent changes, if set. | derived |
| `sys_pin_mode_byte` | `DAT_a802c9f8` | Mode byte that lets pins 4 and 7 of GPIO port 4 be driven. | derived |
| `sys_cable_mode_byte` | `DAT_a802c9f9` | Mode byte read by the cable detection of the inputs. | descriptive |
| `edid_port_flags` | `DAT_a802c9fa` | The per-port flag bits that accompany the internal EDID. | derived |
| `edid_internal_enabled_bits` | `DAT_a802c9fb` | One bit per port whose internal EDID is switched on. | derived |
| `input_last_key_code` | `DAT_a802c9fc` | The key code seen last by the debounced key reader. | derived |
| `oled_write_retry_count` | `DAT_a802c9fd` | Counts repeated writes to the OLED panel controller; retries stop once it passes 9. It is never cleared. | derived |
| `port_present_mask` | `DAT_a802c9fe` | One bit per input port: the ports found present. | derived |
| `port_present_mask_alt` | `DAT_a802ca00` | One bit per input port: the ports found present by the second test. | derived |
| `panel_level_gen_flags` | `DAT_a802ca02` | Flag bits of the level generator: 0x81 after a target is set; bit 0 = step to the full target. | descriptive |
| `panel_level_gen_min_level` | `DAT_a802ca03` | Always 0x7E: the lowest level the stepping may reach; also the byte written to register 0xCF0160C8. | derived |
| `panel_level_gen_ramp_running` | `DAT_a802ca04` | 1 while a ramp of the level generator runs; 0 when panel_level_gen_ramp_next reports the end. | derived |
| `pq_auto_level_jump_flag` | `DAT_a802ca08` | When nonzero the applied curve takes the new curve at once instead of in steps of 4. | derived |
| `pq_auto_level_sum` | `DAT_a802ca0c` | The sum of the 16 measured values. | derived |
| `pq_auto_level_curve_moving` | `DAT_a802ca10` | Set while the applied curve still moves towards the target curve. | derived |
| `pq_auto_level_weight_sum` | `DAT_a802ca12` | The sum of the 16 weights. | derived |
| `pq_auto_level_active` | `DAT_a802ca14` | Set when automatic level control has been switched on after the wait. | descriptive |
| `pq_auto_level_ticks` | `DAT_a802ca16` | Time stamp for the 10-second wait of the automatic level control. | derived |
| `pq_auto_level_condition` | `DAT_a802ca18` | Set while the measured picture allows automatic level control. | descriptive |
| `pq_auto_level_stepping` | `DAT_a802ca19` | Set while the level is being stepped towards its target. | derived |
| `pq_auto_level_target_curve` | `DAT_a802ca1a` | The 16-point curve computed from the measured values. | derived |
| `pq_auto_level_applied_curve` | `DAT_a802ca3a` | The 16-point curve applied, stepped towards the target curve. | derived |
| `pq_auto_level_bins` | `DAT_a802ca5c` | The 16 measured values of the picture. | derived |
| `pq_auto_level_reference_bins` | `DAT_a802ca9c` | The 16 measured values stored as the reference. | derived |
| `pq_auto_level_weight_values` | `DAT_a802cae0` | The 16 weights (default 0x3A each). | derived |
| `pq_auto_level_target` | `DAT_a802caf0` | The level computed from the measured values (0..0x3FF). | derived |
| `pq_auto_level_current` | `DAT_a802caf2` | The level applied, stepped by 4 towards the target. | derived |
| `input_port_pending_bits` | `DAT_a802caf8` | One pending bit per port. | derived |
| `input_port_changed_flags` | `DAT_a802cb00` | The changed flag of each port. | derived |
| `edid_port_size_codes` | `DAT_a802cb08` | The EDID size code of each port. | derived |
| `pq_fga_status` | `DAT_a802cb10` | The FGA status byte. | proven |
| `pq_fga_lum_gain` | `DAT_a802cb12` | The OLED luminance gain read and written by the calibration commands. | derived |
| `pq_fga_lum_mode` | `DAT_a802cb14` | The OLED luminance mode read by the calibration commands. | derived |
| `pq_fga_lum_mode_low_byte` | `DAT_a802cb15` | Low byte of pq_fga_lum_mode (saved by FGA command 0x14); command 0x24 writes it back. | descriptive |
| `pq_fga_color_offset` | `DAT_a802cb16` | Byte offset in the colour block: first key index * 9 + second key index * 3. | derived |
| `pq_fga_key_index_second` | `DAT_a802cb18` | The index of the command key in the second FGA key table. | derived |
| `pq_fga_key_index_first` | `DAT_a802cb1a` | The index of the command key in the first FGA key table. | derived |
| `pq_fga_saved_flag_registers` | `DAT_a802cb1c` | The value of flag registers 0xCF009BB4 / B8 saved by the FGA begin command and written back later. | descriptive |
| `pq_fga_color_block` | `DAT_a802cb20` | The 27-byte colour block saved at FGA offset 0x10. | derived |
| `pq_fga_color_rows` | `DAT_a802cb40` | The three 18-byte colour rows of the FGA block. | derived |
| `pq_fga_write_offset` | `DAT_a802cb78` | Offset in the FGA block for the next 32-byte write. | derived |
| `pq_fga_row_offset` | `DAT_a802cb7a` | Offset in the colour rows for the next 18 bytes. | derived |
| `sys_frc_last_pip_mode` | `DAT_a802cb80` | Device settings byte 7 (PIP mode) seen when the converter channels were last set. | derived |
| `sys_frc_last_bypass_bit` | `DAT_a802cb81` | Bit 26 of the system configuration seen when the converter channels were last set. | derived |
| `sys_wait2show_start_ticks` | `DAT_a802cb82` | Per channel: tick stamp taken when the channel entered MODE_WAIT2SHOW with a show delay. | derived |
| `ipc_8051_rx_slot` | `DAT_a802cb8c` | The incoming slot of the 8051 mailbox found filled. | derived |
| `ipc_8051_tx_slot` | `DAT_a802cb8d` | The outgoing slot index of the 8051 mailbox (wraps after 3). | derived |
| `ipc_8051_rx_block_length` | `DAT_a802cb8e` | Length of the received block waiting to be taken. | derived |
| `ipc_8051_rx_block_ready_flag` | `DAT_a802cb8f` | Set when a received block from the 8051 waits to be taken; cleared when taken. | derived |
| `ipc_8051_rx_block2_length` | `DAT_a802cb92` | Length of the second received block waiting to be taken. | derived |
| `ipc_8051_rx_block2_ready_flag` | `DAT_a802cb93` | Set when the second received block waits to be taken; cleared when taken. | derived |
| `ipc_ir_rx_buffer_count` | `DAT_a802cb94` | Number of bytes in the infrared message buffer (at most 0x40). | proven |
| `ipc_8051_tx_queue_read_index` | `DAT_a802cb96` | Read index of the 36-entry 8051 message queue. | derived |
| `ipc_8051_tx_queue_write_index` | `DAT_a802cb97` | Write index of the 36-entry 8051 message queue. | derived |
| `ipc_port_descriptor_dumped_flag` | `DAT_a802cb98` | Set to 1 when ipc_ack_port_change_bits has printed a port descriptor ("ulMailBoxData[%d]") once. | derived |
| `ldc_cmd20_last_mode` | `DAT_a802cb99` | The mode value last sent with dimming command 0x20. | derived |
| `ipc_reply_words` | `DAT_a802cb9c` | The words of the input processor's reply to the last command. | derived |
| `ipc_reply_word1` | `DAT_a802cba0` | Word 1 of the reply of the input processor. | derived |
| `ipc_reply_result_byte` | `DAT_a802cba3` | Low byte of reply word 1, returned as the result of the one-byte queries. | derived |
| `pq_color_matrix_flags` | `DAT_a802cbbc` | Bit 0 = colour matrix on, bit 1 = second option of the colour matrix. | derived |
| `pq_color_matrix_param_third` | `_DAT_a802cbbd` | The third matrix parameter the colour matrix is built from. | derived |
| `input_port_timers_ticks` | `DAT_a802cbd0` | Time stamp of the last update of the nine port timers. | derived |
| `input_bring_up_channel` | `DAT_a802cbd2` | The channel the bring-up state machine works on (0xFF = none). | derived |
| `input_port_status_bit7_mask` | `DAT_a802cbd3` | One bit per port: copy of status bit 7 of its port record, read by input_get_port_mask_bit_alt. | descriptive |
| `input_port_status_bit10_mask` | `DAT_a802cbd4` | One bit per port: copy of status bit 10 of its port record, read by input_get_port_mask_bit. | descriptive |
| `nvram_old_row_marker` | `DAT_a802cbd8` | Byte copied into the last byte of the 8051 flash buffer before the old row is programmed again. | descriptive |
| `nvram_pending_write_flag` | `DAT_a802cbd9` | Set while flash-backed data waits to be written. | derived |
| `nvram_area_layouts` | `DAT_a802cbdc` | Layout of each flash-backed storage area built at start-up: base offset and row. | derived |
| `nvram_device_layouts` | `DAT_a802cc00` | Base offset and row step of each storage device, built at start-up. | derived |
| `nvram_last_write_ticks` | `DAT_a802cc04` | Time stamp of the last storage write; pending data is flushed 1000 ticks later. | derived |
| `panel_power_on_done_flag` | `DAT_a802cc08` | Set when the panel power sequencer has finished switching on. | derived |
| `panel_power_reverse_flag` | `DAT_a802cc09` | Set when a power request arrives while the opposite sequence is running. | derived |
| `hdmi_hdcp22_mute_started_bits` | `DAT_a802cc0b` | One bit per port whose HDCP 2.2 mute wait has started. | derived |
| `hdmi_hdcp22_mute_ticks` | `DAT_a802cc0c` | Time stamp per port of the start of the HDCP 2.2 mute wait (one second). | derived |
| `edid_default_ptrs` | `DAT_a802cc10` | Pointers to the built-in EDIDs, picked by the port's variant in device settings +0x1B. | derived |
| `sys_port_holdoff_counts` | `DAT_a802cc18` | The hold-off counter of each port: 2 while port status bit 5 is set, then counted down to 0. | derived |
| `sys_callback_table` | `DAT_a802cc1c` | The fifteen callbacks registered at start-up. | proven |
| `sys_callback_table_slot1` | `_DAT_a802cc20` | Slot 1 of the callback table, read as the start value of a firmware update. | derived |
| `sys_callback_table_slot7` | `DAT_a802cc38` | Slot 7 of the callback table, called by the channel idle task. | derived |
| `sys_callback_table_slot8` | `DAT_a802cc3c` | Slot 8 of the callback table, called in the second start-up step. | derived |
| `sys_callback_table_slot11` | `DAT_a802cc48` | Slot 11 of the callback table, called after the port EDIDs are loaded. | derived |
| `sys_callback_table_slot12` | `DAT_a802cc4c` | Slot 12 of the callback table, called by the settings check at start-up. | derived |
| `sys_callback_table_slot13` | `_DAT_a802cc50` | Slot 13 of the callback table: hook that adjusts the automatic brightness level. | derived |
| `dbg_ddr_stress_count` | `DAT_a802cc58` | Count of memory stress test runs (printed as pre_DDRStressCnt). | proven |
| `dbg_ddr_zero_step_count` | `DAT_a802cc5c` | Number of stress-test steps in a row whose dbg_ddr_run_test_step result was 0. | descriptive |
| `dbg_ddr_row_index` | `DAT_a802cc5d` | Row index (data byte 0..7) of the stress test result table. | derived |
| `dbg_ddr_column_index` | `DAT_a802cc5e` | Column index (0..3) of the stress test result table. | derived |
| `dbg_ddr_result_table` | `DAT_a802cc5f` | The 8 x 4 result table of the memory stress test (printed under WDQ / RDQ). | derived |
| `audio_unit_owners` | `DAT_a802cc80` | Which sound source holds each of the four audio units (four 4-bit fields). | proven |
| `audio_unit_order` | `DAT_a802cc82` | The order in which the four audio units were assigned (four 4-bit fields). | proven |
| `panel_blurfree_reversed_mode` | `DAT_a802cc84` | 1 when panel_blurfree_configure took its reversed case, else 0; SetPSMMixMode uses it as the channel enable. | derived |
| `panel_blurfree_reference_delay` | `DAT_a802cc85` | The reference delay of the blur-reduction PWM. | derived |
| `panel_blurfree_channel_mask` | `DAT_a802cc86` | The mask of PWM channels used for blur reduction. | derived |
| `panel_blurfree_second_channel_mask` | `DAT_a802cc87` | The second mask of PWM channels; these get the duty value. | derived |
| `panel_blurfree_timer` | `DAT_a802cc88` | Down-counter of the blur-reduction task, restarted at 1000. | derived |
| `pq_zone_averages_blue` | `DAT_a802cc90` | 256 bytes: the blue average of each zone of the 16 x 16 grid (first value of each triple read). | derived |
| `pq_zone_averages_green` | `DAT_a802cd90` | 256 bytes: the green average of each zone of the 16 x 16 grid (second value of each triple read). | derived |
| `pq_zone_averages_red` | `DAT_a802ce90` | 256 bytes: the red average of each zone of the 16 x 16 grid (third value of each triple read). | derived |
| `sys_boot_source` | `DAT_a802cf90` | The boot source reported by the 8051 (printed as Boot from). | proven |
| `sys_oled_time_pass_count` | `DAT_a802cf91` | Counts passes to 3 before the OLED usage-time counters of the device settings advance. | descriptive |
| `sys_on_time_pass_count` | `DAT_a802cf92` | Counts passes to 3 before the on-time counter of the device settings advances. | descriptive |
| `sys_housekeeping_ticks` | `DAT_a802cf94` | Time stamp of the last 200 ms housekeeping step. | derived |
| `sys_input_cpu_state_last` | `DAT_a802cf96` | The state byte of the input processor seen last. | derived |
| `sys_lut_upload_pass_count` | `DAT_a802cf97` | Pass counter; the colour look-up tables are uploaded every 20th pass. | descriptive |
| `sys_link_status_code` | `DAT_a802cf98` | The link status code last published (0 or 3). | derived |
| `sys_chip_revision` | `DAT_a802cf9c` | The chip revision read at start-up. | derived |
| `sys_chip_model_code` | `DAT_a802cf9d` | The chip model code read at start-up. | derived |
| `libc_mutexattr_settype_hook` | `_DAT_a802cfd4` | Optional mutex-attribute-settype hook (0 = none). | derived |
| `libc_mutexattr_destroy_hook` | `_DAT_a802cfd8` | Optional mutex-attribute-destroy hook (0 = none). | derived |
| `libc_mutexattr_init_hook` | `_DAT_a802cfdc` | Optional mutex-attribute-init hook (0 = none). | derived |
| `libc_mutex_unlock_hook` | `_DAT_a802cfe0` | Optional mutex-unlock hook (0 = none). | derived |
| `libc_mutex_lock_hook` | `_DAT_a802cfe4` | Optional mutex-lock hook (0 = none). | derived |
| `libc_mutex_trylock_hook` | `_DAT_a802cfe8` | Optional mutex-trylock hook (0 = none). | derived |
| `libc_mutex_destroy_hook` | `_DAT_a802cfec` | Optional mutex-destroy hook (0 = none). | derived |
| `libc_mutex_init_hook` | `DAT_a802cff0` | Optional mutex-init hook (0 = none). | derived |
| `app_state_record` | `DAT_a802cff4` | The application state record: power and fake-sleep state, step counts, panel prompt fields. | descriptive |
| `app_state_record_sleep_word` | `DAT_a802cff8` | Word +4 of the application state; bits 13-14 hold the fake-sleep state (2 = fake sleep). | derived |
| `app_state_record_pressed_key_bit` | `DAT_a802cffa` | Application state +0x06: key bit of the last key read, used by the factory key test. | derived |
| `uart_cmd_alarm_slot_index` | `DAT_a802cffd` | The alarm clock timer slot selected by the PC tool (0..4). | derived |
| `app_state_record_half_0xa` | `DAT_a802cffe` | Application state +0xA: high byte = who opened the change notice; bits 7 and 6 = CEC source flags. | derived |
| `app_state_record_led_bar_status_code` | `DAT_a802d00d` | Application state +0x19: the last result 1..10 of sys_led_bar_get_status_code. | derived |
| `app_state_record_power_on_ticks` | `DAT_a802d00e` | Application state +0x1A: tick stamp of App_Initialize type 1; key 0x40 is dropped for 1000 ticks after it. | derived |
| `app_state_record_channel_flag_bits` | `DAT_a802d010` | Application state +0x1C: bit n set by sys_app_generate_events for a state change of channel n. | derived |
| `app_state_record_split_editor` | `DAT_a802d028` | Application state +0x34: 2 while the PBP custom split editor is open. | descriptive |
| `app_state_record_split_x` | `DAT_a802d02a` | Application state +0x36: x position of the split line in the PBP custom split editor. | descriptive |
| `app_state_record_split_lines` | `DAT_a802d02c` | Application state +0x38: height of the split line in the PBP custom split editor. | descriptive |
| `osd_dialog_button_index` | `DAT_a802d033` | The selected button of a dialog or prompt (0..2). | derived |
| `osd_move_key_ticks` | `DAT_a802d034` | Time stamp of the last move key in the window and position editors. | derived |
| `osd_alarm_second_ticks` | `DAT_a802d036` | Time stamp of the last one-second step of the alarm clock countdown. | derived |
| `osd_protect_wait_ticks` | `DAT_a802d038` | Time stamp from which the 30 s wait before the OLED panel protect check counts. | derived |
| `osd_move_hold_ticks` | `DAT_a802d03a` | Time stamp from which a held move key counts; steps grow after 2 and 5 seconds. | derived |
| `osd_message_ticks` | `_DAT_a802d03c` | Time stamp from which the menu message time-outs are counted. | derived |
| `uart_cmd_rx_record_port2` | `DAT_a802d040` | Receive record (0x32 bytes) of PC tool command port 2. | proven |
| `uart_cmd_rx_units_digit_port2` | `DAT_a802d049` | Byte +9 of the port 2 receive record: the units digit of a set command's value. | derived |
| `uart_cmd_tx_frame` | `DAT_a802d078` | Reply frame (0x19 bytes) of the PC tool command port. | proven |
| `uart_cmd_rx_record_port3` | `DAT_a802d098` | Receive record (0x32 bytes) of PC tool command port 3. | proven |
| `uart_cmd_rx_units_digit_port3` | `DAT_a802d0a1` | Byte +9 of the port 3 receive record: the units digit of a set command's value. | derived |
| `uart_cmd_rx_record` | `DAT_a802d0d0` | Receive record (0x32 bytes) of the PC tool command port. | proven |
| `uart_cmd_rx_units_digit` | `DAT_a802d0d9` | Byte +9 of the tool port's receive record: the units digit of a set command's value. | derived |
| `uart_cmd_tx_frame_port3` | `DAT_a802d108` | Reply frame (0x19 bytes) of PC tool command port 3. | proven |
| `uart_cmd_tx_frame_port2` | `DAT_a802d128` | Reply frame (0x19 bytes) of PC tool command port 2. | proven |
| `ddc_tool_edid_buffer` | `DAT_a802d148` | EDID buffer read and written by the maker commands over DDC/CI, stored to the port EDID. | derived |
| `sys_led_bar_tx_frame` | `DAT_a802d268` | Command frame sent to the LED light bar controller. | derived |
| `factory_record` | `DAT_a802d274` | The factory record: values of the factory menu and the factory tool (0x1C bytes). | proven |
| `factory_record_serial_length` | `DAT_a802d276` | Factory record +0x02: number of characters of the serial number drawn after "SN:". | proven |
| `factory_record_serial` | `DAT_a802d277` | Factory record +0x03: the serial number text (up to 0x12 characters; 0 ends, 0xFF shown as a space). | proven |
| `factory_record_key_test_bits` | `DAT_a802d284` | Factory record +0x10: one bit per front key passed in the key test (0x3F = all). | proven |
| `factory_record_aux0_minutes` | `DAT_a802d285` | Factory record +0x11: minutes 0..59 counted while auxiliary GPIO pin 0 reads high. | derived |
| `factory_record_aux0_hours` | `DAT_a802d286` | Factory record +0x12: hours (up to 0xFFFF) counted while auxiliary GPIO pin 0 reads high. | derived |
| `factory_record_byte_0x14` | `DAT_a802d288` | Factory record byte +0x14, read when the power state changes and by the USB port choice. | descriptive |
| `factory_record_oled_error_count` | `DAT_a802d289` | Factory record +0x15: OLED error detections counted; drawn after "Panel ERR Count" in the factory menu. | proven |
| `factory_record_oled_error_status` | `DAT_a802d28a` | Factory record +0x16: OLED controller register 0x10 at the stored error; drawn after "Status". | proven |
| `factory_record_check_word` | `DAT_a802d28c` | Factory record halfword +0x18: its bit 15 is drawn after "Check" in the factory menu. | descriptive |
| `user_settings` | `DAT_a802d290` | The user settings record: every setting of the on-screen menu (0x1FC bytes). | proven |
| `user_settings_option_bits` | `DAT_a802d294` | Settings word +4: bits 28-30 = link option enable, port 0 option, configuration bit 25. | derived |
| `user_settings_output_mode` | `DAT_a802d295` | Settings byte +5: the output mode setting. | derived |
| `user_settings_language` | `DAT_a802d298` | Settings byte +8: the menu language (1 = English). | proven |
| `user_settings_brightness` | `DAT_a802d299` | Settings byte +9: Brightness. | proven |
| `user_settings_contrast` | `DAT_a802d29a` | Settings byte +0xA: Contrast. | proven |
| `user_settings_osd_timeout` | `DAT_a802d29c` | Settings byte +0xC: OSD Time out. | proven |
| `user_settings_menu_position_a` | `DAT_a802d29d` | Settings byte +0x0D: first value (at most 100) osd_user_apply_menu_position gives osd_api_set_position. | descriptive |
| `user_settings_menu_position_b` | `DAT_a802d29e` | Settings byte +0x0E: second value (at most 100) osd_user_apply_menu_position gives osd_api_set_position. | descriptive |
| `user_settings_transparency` | `DAT_a802d29f` | Settings byte +0xF: menu Transparency. | proven |
| `user_settings_audio_level` | `DAT_a802d2a0` | Settings byte +0x10: the audio level (at most 100). | derived |
| `user_settings_color_temperature` | `DAT_a802d2a1` | Settings byte +0x11: Color Temperature. | proven |
| `user_settings_red_gain` | `DAT_a802d2a2` | Settings byte +0x12: the custom red gain. | proven |
| `user_settings_green_gain` | `DAT_a802d2a3` | Settings byte +0x13: the custom green gain. | proven |
| `user_settings_blue_gain` | `DAT_a802d2a4` | Settings byte +0x14: the custom blue gain. | proven |
| `user_settings_red_black_level` | `DAT_a802d2a5` | Settings byte +0x15: red black level (DDC/CI VCP 0x6C). | derived |
| `user_settings_green_black_level` | `DAT_a802d2a6` | Settings byte +0x16: green black level (DDC/CI VCP 0x6E). | derived |
| `user_settings_blue_black_level` | `DAT_a802d2a7` | Settings byte +0x17: blue black level (DDC/CI VCP 0x70). | derived |
| `user_settings_byte_0x18` | `DAT_a802d2a8` | Settings byte +0x18, reported to the PC tool. | descriptive |
| `user_settings_response_time` | `DAT_a802d2a9` | Settings byte +0x19: the response time level. | proven |
| `user_settings_theme_mode` | `DAT_a802d2aa` | Settings byte +0x1A: the theme mode (at most 4). | derived |
| `user_settings_input_source` | `DAT_a802d2ae` | Settings byte +0x1E: the selected Input Source (DDC/CI VCP 0x60). | proven |
| `user_settings_pip_pbp_mode` | `DAT_a802d2af` | Settings byte +0x1F: PIP/PBP mode (0 off, 1 PIP, 2 PBP). | proven |
| `user_settings_second_source` | `DAT_a802d2b0` | Settings byte +0x20: the source of the second picture (PIP source, PBP source 2). | proven |
| `user_settings_channel2_source` | `DAT_a802d2b1` | Settings byte +0x21: receives the port code of channel 2 after display. | derived |
| `user_settings_channel3_source` | `DAT_a802d2b2` | Settings byte +0x22: receives the port code of channel 3 after display. | derived |
| `user_settings_source_slot4` | `DAT_a802d2b3` | Settings byte +0x23: the source of slot 4. | descriptive |
| `user_settings_source_slot5` | `DAT_a802d2b5` | Settings byte +0x25: the source of slot 5. | descriptive |
| `user_settings_source_slot6` | `DAT_a802d2b6` | Settings byte +0x26: the source of slot 6. | descriptive |
| `user_settings_byte_0x27` | `DAT_a802d2b7` | Settings byte +0x27, chooses the record passed to the slot 5 routine. | descriptive |
| `user_settings_byte_0x28` | `DAT_a802d2b8` | Settings byte +0x28, chooses the record passed to the slot 6 routine. | descriptive |
| `user_settings_byte_0x2b` | `DAT_a802d2bb` | Settings byte +0x2B, applied for slot 5. | descriptive |
| `user_settings_byte_0x2c` | `DAT_a802d2bc` | Settings byte +0x2C, applied for slot 6. | descriptive |
| `user_settings_byte_0x2d` | `DAT_a802d2bd` | Settings byte +0x2D, applied for slot 5. | descriptive |
| `user_settings_byte_0x2e` | `DAT_a802d2be` | Settings byte +0x2E, applied for slot 6. | descriptive |
| `user_settings_pbp_layout` | `DAT_a802d2bf` | Settings byte +0x2F: the PBP layout. | proven |
| `user_settings_pip_location` | `_DAT_a802d2c0` | Settings word +0x30; bits 4-7 = the PIP location. | derived |
| `user_settings_pip_size` | `DAT_a802d2c1` | PIP window size: 0 Large, 1 Medium, 2 Small (the PIP Size list highlights row 2 minus it). | derived |
| `user_settings_image_enhancement` | `DAT_a802d2c4` | Settings halfword +0x34; bits 0-3 = Image Enhancement level; also read for the scaling mode. | derived |
| `user_settings_gamma` | `DAT_a802d2d4` | Settings byte +0x44: the gamma choice (DDC/CI VCP 0x72: 0x50 -> 2, 0x78 -> 1). | derived |
| `user_settings_channel2_enable` | `DAT_a802d2d5` | Settings byte +0x45: the enable setting of channel 2. | derived |
| `user_settings_byte_0x46` | `DAT_a802d2d6` | Settings byte +0x46, chooses the record that decides whether channel 2 restarts. | descriptive |
| `user_settings_channel3_enable` | `DAT_a802d2d7` | Settings byte +0x47: the enable setting of channel 3. | derived |
| `user_settings_byte_0x48` | `DAT_a802d2d8` | Settings byte +0x48, chooses the record that decides whether channel 3 restarts. | descriptive |
| `user_settings_sharpness` | `DAT_a802d2d9` | Settings byte +0x49: Sharpness. | proven |
| `user_settings_optix_scope` | `DAT_a802d2da` | Settings byte +0x4A: the Optix Scope switch. | proven |
| `user_settings_scope_size` | `DAT_a802d2db` | Settings byte +0x4B: the Optix Scope size. | proven |
| `user_settings_scope_ratio` | `DAT_a802d2dc` | Settings byte +0x4C: the Optix Scope ratio. | proven |
| `user_settings_channel0_link_option` | `DAT_a802d2df` | Settings byte +0x4F: the link option of channel 0. | derived |
| `user_settings_channel1_link_option` | `DAT_a802d2e0` | Settings byte +0x50: the link option of channel 1. | derived |
| `user_settings_channel2_link_option` | `DAT_a802d2e1` | Settings byte +0x51: the link option of channel 2. | derived |
| `user_settings_channel3_link_option` | `DAT_a802d2e2` | Settings byte +0x52: the link option of channel 3. | derived |
| `user_settings_pip_custom_x` | `DAT_a802d2e4` | Settings halfword +0x54: x position of the channel 1 window for PIP location 4 'Customize'. | derived |
| `user_settings_pip_custom_y` | `DAT_a802d2e6` | Settings halfword +0x56: y position of the channel 1 window for PIP location 4 'Customize'. | derived |
| `user_settings_response_time_copy` | `DAT_a802d31f` | Settings byte +0x8F: the limited response time that pq_user_reset_response_level restores +0x19 from. | derived |
| `user_settings_gaming_flags` | `_DAT_a802d338` | Settings word +0xA8 switches: bit 7 Adaptive-Sync, bit 11 Pro (1) / Game (0), bit 12 Refresh Rate display. | derived |
| `user_settings_settings_page_flags` | `_DAT_a802d33c` | Settings word +0xAC: first byte = RGB Brightness level; bit 22 Info. On Screen, bit 17 goes to the PC tool. | derived |
| `user_settings_blur_free_mode` | `DAT_a802d340` | Settings word +0xB0: the blur reduction mode. | proven |
| `user_settings_professional_flags` | `_DAT_a802d3ac` | Settings word +0x11C switches: bit 4 Low Blue Light, bit 31 automatic level. | derived |
| `user_settings_refresh_rate_location` | `DAT_a802d3ce` | Settings byte +0x13E: the location of the Refresh Rate overlay. | proven |
| `user_settings_alarm_clock_location` | `DAT_a802d3cf` | Settings byte +0x13F: the location of the Alarm Clock overlay. | proven |
| `user_settings_byte_0x140` | `DAT_a802d3d0` | Settings byte +0x140, read and set by the PC tool. | descriptive |
| `user_settings_night_vision` | `DAT_a802d3eb` | Settings byte +0x15B: Night Vision. | proven |
| `user_settings_word_0x174` | `_DAT_a802d404` | Settings word +0x174; bit 15 = the AI Vision switch. | derived |
| `user_settings_byte_0x177` | `DAT_a802d407` | Settings byte +0x177, read and set by the PC tool. | descriptive |
| `user_settings_crosshair_color` | `DAT_a802d40b` | Settings byte +0x17B: the Smart Crosshair colour (2 = automatic). | proven |
| `user_settings_kvm` | `DAT_a802d40c` | Settings byte +0x17C: the KVM setting. | proven |
| `user_settings_pro_mode` | `DAT_a802d411` | Settings byte +0x181: the Professional mode. | proven |
| `user_settings_game_mode` | `DAT_a802d412` | Settings byte +0x182: the Game Mode. | proven |
| `user_settings_pro_mode_copy_1` | `DAT_a802d413` | Settings byte +0x183: copy 1 of the Pro mode (+0x181), kept with bit 10 of word +0xA8. | derived |
| `user_settings_game_mode_copy_1` | `DAT_a802d414` | Settings byte +0x184: copy 1 of the Game mode (+0x182). | derived |
| `user_settings_pro_mode_copy_2` | `DAT_a802d415` | Settings byte +0x185: copy 2 of the Pro mode (+0x181), kept with bit 9 of word +0xA8. | derived |
| `user_settings_game_mode_copy_2` | `DAT_a802d416` | Settings byte +0x186: copy 2 of the Game mode (+0x182). | derived |
| `user_settings_pro_mode_copy_3` | `DAT_a802d417` | Settings byte +0x187: copy 3 of the Pro mode (+0x181), kept with bit 8 of word +0xA8. | derived |
| `user_settings_game_mode_copy_3` | `DAT_a802d418` | Settings byte +0x188: copy 3 of the Game mode (+0x182). | derived |
| `user_settings_key_guide_shown` | `DAT_a802d419` | Settings byte +0x189: the two key guide text numbers last drawn (high and low nibble); 0xFF forces a redraw. | derived |
| `user_settings_navi_key_up` | `DAT_a802d41a` | Settings byte +0x18A: the Navi Key up function. | proven |
| `user_settings_navi_key_down` | `DAT_a802d41b` | Settings byte +0x18B: the Navi Key down function. | proven |
| `user_settings_navi_key_left` | `DAT_a802d41c` | Settings byte +0x18C: the Navi Key left function. | proven |
| `user_settings_navi_key_right` | `DAT_a802d41d` | Settings byte +0x18D: the Navi Key right function. | proven |
| `user_settings_crosshair_icon` | `DAT_a802d420` | Settings byte +0x190: the Smart Crosshair icon, 0..6; with 0 the crosshair overlay is not shown. | proven |
| `user_settings_alarm_clock` | `DAT_a802d430` | Settings byte +0x1A0: the Alarm Clock timer choice. | proven |
| `user_settings_alarm_minutes` | `DAT_a802d431` | Settings byte +0x1A1: minutes left of the Alarm Clock countdown. | derived |
| `user_settings_alarm_seconds` | `DAT_a802d432` | Settings byte +0x1A2: seconds left (59..0) of the Alarm Clock countdown. | derived |
| `user_settings_byte_0x1a3` | `DAT_a802d433` | Settings byte +0x1A3: row byte shared by the Navi Key list, alarm editor, position editor and PBP source list. | derived |
| `user_settings_screen_size` | `DAT_a802d434` | Settings byte +0x1A4: Screen Size. | proven |
| `user_settings_refresh_rate_custom_x` | `DAT_a802d435` | Settings byte +0x1A5: custom x position (a grid number) of the Refresh Rate box. | descriptive |
| `user_settings_refresh_rate_custom_y` | `DAT_a802d436` | Settings byte +0x1A6: custom y position (a grid number) of the Refresh Rate box. | descriptive |
| `user_settings_alarm_clock_custom_x` | `DAT_a802d437` | Settings byte +0x1A7: custom x position (a grid number) of the Alarm Clock box. | descriptive |
| `user_settings_alarm_clock_custom_y` | `DAT_a802d438` | Settings byte +0x1A8: custom y position (a grid number) of the Alarm Clock box. | descriptive |
| `user_settings_confirm_change` | `DAT_a802d439` | Settings byte +0x1A9: 1 = a Game/Pro mode switch first asks with the 'Confirm Change !' notice. | derived |
| `user_settings_notice_button` | `DAT_a802d43a` | Settings byte +0x1AA: the button highlighted in the change notice (1 = Yes, 0 = No). | derived |
| `user_settings_crosshair_x` | `DAT_a802d43c` | Settings halfword +0x1AC: x origin of the crosshair layer (reset value 0x750). | derived |
| `user_settings_crosshair_y` | `DAT_a802d43e` | Settings halfword +0x1AE: y origin of the crosshair layer. | derived |
| `user_settings_burn_in_flag` | `DAT_a802d465` | Settings byte +0x1D5: burn-in mode on (1) or off (0), set by the factory tool. | proven |
| `user_settings_fast_uph` | `DAT_a802d466` | Settings byte +0x1D6: drawn in hex after "fastUPH" in the factory menu; factory tool status 2. | proven |
| `user_settings_factory_switch_bits` | `DAT_a802d467` | Settings byte +0x1D7: bit 7 = factory menu item "HDMI CTS", bit 6 = CEC PWM Adjust opened. | derived |
| `user_settings_cec_pwm_brightness` | `DAT_a802d468` | Settings byte +0x1D8: the brightness loaded by the factory menu item CEC PWM Adjust. | derived |
| `user_settings_brightness_knee` | `DAT_a802d46a` | Settings halfword +0x1DA: the knee of the brightness mapping line. | derived |
| `user_settings_oled_care_flags` | `_DAT_a802d46c` | Settings word +0x1DC: bit 31 Panel Protect run, bit 30 Panel Protect request, bit 15 Static Screen. | derived |
| `user_settings_pixel_shift` | `DAT_a802d46d` | Settings byte +0x1DD: the Pixel Shift speed. | proven |
| `user_settings_static_screen_level` | `DAT_a802d46f` | Settings byte +0x1DF: the Static Screen Detection reduce level. | proven |
| `user_settings_static_screen_start_time` | `DAT_a802d470` | Settings byte +0x1E0: the Static Screen Detection start time. | proven |
| `user_settings_static_screen_time_required` | `DAT_a802d471` | Settings byte +0x1E1: the Static Screen Detection time required. | proven |
| `user_settings_byte_0x1e2` | `DAT_a802d472` | Settings byte +0x1E2, checked when the panel protect prompt buttons are highlighted. | descriptive |
| `user_settings_multi_logo_detection` | `DAT_a802d478` | Settings byte +0x1E8: Multi Logo Detection on or off. | proven |
| `user_settings_multi_logo_level` | `DAT_a802d479` | Settings byte +0x1E9: the Multi Logo Detection level. | proven |
| `user_settings_taskbar_detection` | `DAT_a802d47a` | Settings byte +0x1EA: Taskbar Detection on or off. | proven |
| `user_settings_taskbar_level` | `DAT_a802d47b` | Settings byte +0x1EB: the Taskbar Detection level. | proven |
| `user_settings_boundary_detection` | `DAT_a802d47c` | Settings byte +0x1EC: Boundary Detection; read as a word, bit 7 = Type C PD Charge. | proven |
| `user_settings_boundary_level` | `DAT_a802d47d` | Settings byte +0x1ED: the Boundary Detection level. | derived |
| `user_settings_protect_notice` | `DAT_a802d47e` | Settings byte +0x1EE: Protect Notice. | proven |
| `user_settings_pbp_custom_split_x` | `DAT_a802d480` | Settings halfword +0x1F0: split position of PBP layout 2 'Customize' (width of channel 0). | derived |
| `user_settings_pbp_custom_split_lines` | `DAT_a802d482` | Settings halfword +0x1F2: the height of the split line, stored with the PBP custom split by its editor. | descriptive |
| `user_settings_word_0x1f4` | `_DAT_a802d484` | Settings word +0x1F4; bit 31 = the DSC switch; read for the menu tabs. | derived |
| `user_settings_factory_mode_marker` | `DAT_a802d486` | Settings halfword +0x1F6: 0x55AA = factory mode on (shown as PRODUCT ON); 0xBB99 written when off. | derived |
| `dbg_shell_line_length` | `DAT_a802d490` | Number of characters typed into the debug command line. | derived |
| `dbg_shell_arg_count` | `DAT_a802d494` | Number of words the debug command line was split into. | derived |
| `dbg_shell_caret_flag` | `DAT_a802d495` | Set to 1 by dbg_command_shell when '^' is the first character typed; nothing reads it. | descriptive |
| `dbg_shell_line_buffer` | `DAT_a802d498` | The 0x100-byte buffer of the debug command line. | derived |
| `dbg_shell_args` | `DAT_a802d598` | The words of the debug command line, five of 0x20 bytes. | derived |
| `timer_sleep_watch_count` | `_DAT_a802d638` | Loop count (clock / 100) after which a stuck sleep prints a warning. | derived |
| `timer_div5_count` | `DAT_a802d63c` | Tick counter that sets the divide-by-5 flag every fifth tick. | derived |
| `timer_div50_flag` | `DAT_a802d640` | Set every 50th tick. | derived |
| `timer_div500_flag` | `DAT_a802d641` | Set every 500th tick. | derived |
| `timer_tick_flag` | `DAT_a802d642` | Set on every tick. | derived |
| `timer_div500_count` | `DAT_a802d644` | Tick counter that sets the divide-by-500 flag. | derived |
| `timer_isr_count_since_init` | `DAT_a802d648` | Count of tick interrupts since timer_init cleared it. | derived |
| `timer_div5_flag` | `DAT_a802d64c` | Set every fifth tick. | derived |
| `timer_div50_count` | `DAT_a802d650` | Tick counter that sets the divide-by-50 flag. | derived |
| `sys_ddr_script` | `DAT_a802d654` | Pointer to the training script that sys_ddr_run_script carries out. | derived |
| `sys_ddr_script_length` | `DAT_a802d658` | Length in bytes of the training script (0x1429 for both scripts). | derived |
| `sys_ddr_run_cal_hook` | `_DAT_a802d65c` | The run-measurement routine of the calibration unit being searched. | derived |
| `sys_ddr_set_n_adj_det_hook` | `_DAT_a802d660` | The N_adj / N_det write routine of the calibration unit being searched. | derived |
| `sys_ddr_wait_cal_idle_hook` | `_DAT_a802d664` | The start-and-wait routine of the calibration unit being searched. | derived |
| `sys_ddr_set_adj_fields_hook` | `_DAT_a802d668` | The table-field write routine of the calibration unit being searched. | derived |
| `sys_ddr_write_delay_field5_value` | `DAT_a802d66c` | The value of write delay field 5 read before the write window training. | descriptive |
| `sys_ddr_write_delay_field4_value` | `DAT_a802d670` | Value of write delay field 4 stored by sys_ddr_train_write_eye; no routine reads it. | descriptive |
| `sys_ddr_write_delay_field3_value` | `DAT_a802d674` | Value of write delay field 3 stored by sys_ddr_train_write_eye; no routine reads it. | descriptive |
| `ldc_kept_height` | `DAT_a802d678` | Height kept by ldc_hw_access_register (ids 3..6), written to bits 0..12 of 0xD0040000. | derived |
| `ldc_kept_width` | `DAT_a802d67a` | Width kept by ldc_hw_access_register (ids 3..6), written to bits 16..28 of 0xD0040000. | derived |
| `panel_output_config_record` | `DAT_a802d680` | Copy of the output path's configuration with the measured level and rate per channel. | derived |
| `panel_working_row_ptr` | `DAT_a802d6a4` | Pointer to the working copy of the active panel timing row. | proven |
| `panel_working_row` | `DAT_a802d6a8` | The working copy of the active panel timing row. | proven |
| `panel_layer_position_offset` | `DAT_a802d700` | Offset added to layer window positions: 0 up to chip revision 0x81, else 0x10. | derived |
| `sys_frc_post_frame_remainder` | `DAT_a802d702` | Frame remainder (12 bits, at least 1) that FRCConfigPostFRC writes scaled into register 0xCF011AE8. | descriptive |
| `panel_layer4_context_ch0` | `DAT_a802d704` | Stored settings of the fourth layer for channel 0. | derived |
| `panel_layer_context_ch0` | `DAT_a802d744` | Stored settings of the channel layer for channel 0. | derived |
| `panel_layer_context_ch2` | `DAT_a802d784` | Stored settings of the channel layer for channel 2. | derived |
| `panel_layer_context_ch1` | `DAT_a802d7c4` | Stored settings of the channel layer for channel 1. | derived |
| `panel_layer4_context_ch1` | `DAT_a802d804` | Stored settings of the fourth layer for channel 1. | derived |
| `sys_path_block_readouts` | `DAT_a802d844` | The two read-out halfwords of each signal path block. | derived |
| `fwupd_file_name` | `DAT_a802d850` | The name of the file offered on the update port. | derived |
| `fwupd_active_port` | `DAT_a802d87e` | The update port (0 or 1) that answered. | proven |
| `port_table_index_by_bus_id` | `ARR_a802d880` | For each bus id 0..6: the index of its entry in the port table, 0xFF when there is none. | derived |
| `oled_read_buffer` | `DAT_a802d888` | Two bytes read back from the OLED panel controller over I2C. | derived |
| `oled_write_buffer` | `DAT_a802d890` | Two bytes written to the OLED panel controller over I2C. | derived |
| `oled_frc_state` | `DAT_a802d892` | State and row index of the OLED refresh-rate task. | proven |
| `oled_frc_state_row_index` | `DAT_a802d893` | The row index of the OLED refresh-rate state; what the panel controller is told. | proven |
| `oled_power_state` | `DAT_a802d896` | State record of the OLED power state machine: state, step and working fields. | proven |
| `oled_power_state_step` | `DAT_a802d897` | The step of the OLED power state (+1). | proven |
| `oled_power_state_ticks` | `_DAT_a802d89a` | Time stamp of the OLED power state (+4) from which the elapsed time is counted. | derived |
| `oled_power_state_sensing_requested` | `DAT_a802d89f` | OLED power state +0x9: 1 = an off sensing run is wanted. | derived |
| `oled_power_state_forced_sensing` | `DAT_a802d8a0` | OLED power state +0xA: 1 = start off sensing without checking the use time. | derived |
| `oled_power_state_byte_0xb` | `DAT_a802d8a1` | OLED power state record byte +0xB, kept through oled_power_set_field_0b. | descriptive |
| `oled_power_state_power_down_done` | `DAT_a802d8a2` | OLED power state +0xC: 1 = the power-down after a sensing run has been done. | derived |
| `oled_power_state_power_down_request` | `DAT_a802d8a3` | OLED power state +0xD: 1 = power down after the sensing run. | derived |
| `oled_power_state_byte_0xe` | `DAT_a802d8a4` | OLED power state record byte +0xE, kept through oled_power_set_field_0e. | descriptive |
| `oled_power_state_after_sensing` | `DAT_a802d8a5` | OLED power state +0xF: what follows a sensing run (0 picture, 1 power saving, 2 power off). | derived |
| `oled_power_state_qsm_done` | `DAT_a802d8a6` | OLED power state +0x10: 1 after the QSM steps; state 0 then starts no off sensing. | derived |
| `oled_power_state_byte_0x11` | `DAT_a802d8a7` | OLED power state record byte +0x11, kept through oled_power_set_field_11. | descriptive |
| `oled_power_state_byte_0x12` | `DAT_a802d8a8` | OLED power state record byte +0x12, kept through oled_power_set_field_12. | descriptive |
| `oled_power_state_sensing_active` | `DAT_a802d8a9` | OLED power state +0x13: 1 during an off sensing run. | derived |
| `port_link_rows` | `DAT_a802d8ae` | The link settings of each input as sent to the input processor (0x16 bytes each). | proven |
| `sys_output_records` | `DAT_a802d8dc` | Records of the outputs with their flag halfword (+0x1C) sent in output messages. | descriptive |
| `sys_event_code_byte` | `DAT_a802d990` | The event code byte; bit 7 cleared when a new code is set. | descriptive |
| `sys_event_pending_byte` | `DAT_a802d991` | Bit 7 = an event is pending. | derived |
| `i2c_bus_descriptor` | `DAT_a802d992` | Pins, delay, device address and mode of the software I2C bus in use. | proven |
| `ipc_8051_power_cut_table` | `DAT_a802d9a0` | The 18-byte power-cut table built for the 8051 (message type 10). | derived |
| `ipc_8051_wake_table` | `DAT_a802d9b8` | The 12-byte wake table built for the 8051 key table message (type 8). | derived |
| `ddc_rx_request` | `DAT_a802d9c6` | The DDC/CI request received from the 8051: port, length and data bytes. | derived |
| `ddc_rx_request_state` | `DAT_a802da4a` | State byte (+0x84) of the received DDC/CI request; cleared when the request is taken. | derived |
| `ipc_8051_fixed_wake_table` | `DAT_a802da60` | The fixed 12-byte wake table for the 8051 key table message. | derived |
| `ipc_8051_tx_queue` | `DAT_a802da6c` | Ring of 20-byte messages waiting for a free slot of the 8051 mailbox. | proven |
| `ipc_ir_rx_buffer` | `DAT_a802dd50` | Bytes of the 8051's infrared messages (type 5) waiting to be taken (0x40 bytes). | proven |
| `uart_rx_rings` | `DAT_a802dd90` | One 32-byte receive ring per serial port with write and read index and overflow flag. | derived |
| `ipc_8051_rx_block_buffer` | `DAT_a802de40` | Buffer of the block received from the 8051 (port memory, answers). | derived |
| `input_port_templates` | `DAT_a802dec0` | The port templates sent by the input processor (type per port). | derived |
| `channel_records` | `DAT_a802df30` | The four channel records: state, port, picture window and timing of each picture channel. | proven |
| `channel_records_mode_row` | `DAT_a802df36` | The mode row inside each channel record (+6), stored to the saved-mode table. | derived |
| `channel_records_byte_0x3a` | `DAT_a802df6a` | Byte +0x3A of channel record 0, checked by the DDC/CI set handler. | descriptive |
| `channel_records_half_0x54` | `_DAT_a802df84` | Halfword +0x54 of channel record 0, compared with the default panel row. | descriptive |
| `channel_records_flags` | `_DAT_a802dfa0` | Word +0x70 of channel record 0: its flags. | proven |
| `panel_power_state` | `DAT_a802e110` | State of the panel power sequencer (1 = off, 6 = on). | proven |
| `port_entries` | `DAT_a802e116` | The seven port entries: the inputs as the control logic sees them (0x12 bytes each). | proven |
| `port_entry0_bus_id` | `DAT_a802e126` | Bus id (+0x10) of port entry 0. | proven |
| `port_entry1` | `DAT_a802e128` | Port entry 1 (halfword 0: class and flags). | derived |
| `port_entry1_bus_id` | `DAT_a802e138` | Bus id (+0x10) of port entry 1. | proven |
| `port_entry2` | `DAT_a802e13a` | Port entry 2 (halfword 0: class and flags). | derived |
| `port_entry2_bus_id` | `DAT_a802e14a` | Bus id (+0x10) of port entry 2. | proven |
| `port_entry3` | `DAT_a802e14c` | Port entry 3 (halfword 0: class and flags). | derived |
| `port_entry3_bus_id` | `DAT_a802e15c` | Bus id (+0x10) of port entry 3. | proven |
| `device_settings` | `DAT_a802e1a0` | The device settings record: settings that belong to the device, not to the user (0x50 bytes). | proven |
| `device_settings_pip_mode` | `DAT_a802e1a7` | The current picture-in-picture / picture-by-picture mode (0 = one picture). | proven |
| `device_settings_on_time` | `DAT_a802e1a8` | Device settings word +8: on-time; byte +8 = minutes 0..59, halfword +9 = hours; drawn as word >> 8. | proven |
| `device_settings_brightness_preset` | `DAT_a802e1ab` | Device settings byte +0xB: the brightness preset (0..2) set by the factory tool. | derived |
| `device_settings_fga_storage_device` | `DAT_a802e1d4` | Device settings byte +0x34: storage device of the FGA block. | derived |
| `device_settings_byte_0x37` | `DAT_a802e1d7` | Device settings byte +0x37, set from the FGA commands and checked when gamma loads. | descriptive |
| `part_record` | `DAT_a802e1f0` | The part record: three-byte colour entries of the picture modes and related values (0x30 bytes). | derived |
| `part_record_byte_0x1` | `DAT_a802e1f1` | Part record byte +1, answered to DDC/CI VCP 0xE2 sub-code 2. | descriptive |
| `part_record_byte_0x2` | `DAT_a802e1f2` | Part record byte +2, answered to DDC/CI VCP 0xE2 sub-code 3. | descriptive |
| `part_record_byte_0x3` | `DAT_a802e1f3` | Part record byte +3, answered to DDC/CI VCP 0xE2 sub-code 4. | descriptive |
| `part_record_byte_0x4` | `DAT_a802e1f4` | Part record byte +4, answered to DDC/CI VCP 0xE2 sub-code 5. | descriptive |
| `part_record_byte_0x5` | `DAT_a802e1f5` | Part record byte +5, answered to DDC/CI VCP 0xE2 sub-code 6. | descriptive |
| `part_record_warm50_red` | `DAT_a802e1f6` | Part record +0x06: red value of the factory menu row Warm50. | proven |
| `part_record_warm50_green` | `DAT_a802e1f7` | Part record +0x07: green value of the factory menu row Warm50. | proven |
| `part_record_warm50_blue` | `DAT_a802e1f8` | Part record +0x08: blue value of the factory menu row Warm50. | proven |
| `part_record_normal65_red` | `DAT_a802e1f9` | Part record +0x09: red value of the factory menu row Normal65. | proven |
| `part_record_normal65_green` | `DAT_a802e1fa` | Part record +0x0A: green value of the factory menu row Normal65. | proven |
| `part_record_normal65_blue` | `DAT_a802e1fb` | Part record +0x0B: blue value of the factory menu row Normal65. | proven |
| `part_record_cool93_red` | `DAT_a802e202` | Part record +0x12: red value of the factory menu row Cool93. | proven |
| `part_record_cool93_green` | `DAT_a802e203` | Part record +0x13: green value of the factory menu row Cool93. | proven |
| `part_record_cool93_blue` | `DAT_a802e204` | Part record +0x14: blue value of the factory menu row Cool93. | proven |
| `part_record_hdr_peak_luminance` | `DAT_a802e214` | Part record halfword +0x24: the HDR peak luminance sent to the input processor. | derived |
| `part_record_brightness_max` | `DAT_a802e216` | Part record halfword +0x26: the panel level at 100 % brightness. | derived |
| `pq_fga_state_bits` | `DAT_a802e220` | Bits 5 and 6 changed by the FGA commands; bit 5 is checked by the DDC/CI handler. | descriptive |
| `port_records` | `DAT_a802e224` | One record per input port: status bits, state, type, mode and time stamp (0x2A bytes each). | proven |
| `port_records_half_0x10` | `_DAT_a802e234` | Halfword +0x10 of port record 0. | descriptive |
| `panel_active_row` | `DAT_a802e378` | The panel timing row in use: clock, totals, sizes, refresh rate (0x58 bytes). | proven |
| `panel_active_row_bpc` | `DAT_a802e37f` | Byte +7 of the active panel timing row: bits per colour. | derived |
| `panel_active_row_active_width` | `DAT_a802e380` | Halfword +8 of the active panel timing row: the active width in pixels. | derived |
| `panel_active_row_active_lines` | `DAT_a802e382` | Halfword +0xA of the active panel timing row: the number of active lines. | derived |
| `panel_active_row_htotal` | `DAT_a802e39a` | Halfword +0x22 of the active panel timing row: the horizontal total, between its minimum and maximum. | proven |
| `panel_output_rate` | `DAT_a802e3ca` | The refresh rate the output timing is programmed for, in tenths of a hertz. | derived |
| `sys_config` | `DAT_a802e3d0` | The system configuration record (stSysConfig in the firmware's messages): the working picture-path set-up. | proven |
| `sys_config_byte_3` | `DAT_a802e3d3` | Byte 3 of the system configuration record; non-zero selects the second form of the output timing. | descriptive |
| `sys_config_auto_level_mode` | `DAT_a802e3d7` | System configuration byte +7: the automatic level mode (1 = stepping on). | derived |
| `sys_config_color_gain` | `DAT_a802e3d9` | System configuration byte +9: the colour gain of the colour matrix. | derived |
| `sys_config_color_matrix_param` | `DAT_a802e3da` | System configuration byte +0xA: the colour parameter of the colour matrix. | derived |
| `sys_config_picture_mode` | `DAT_a802e3db` | System configuration byte +0xB: the picture mode. | proven |
| `sys_config_red_gain` | `DAT_a802e3dc` | System configuration byte +0xC: the red gain (0..100). | proven |
| `sys_config_green_gain` | `DAT_a802e3dd` | System configuration byte +0xD: the green gain (0..100). | proven |
| `sys_config_blue_gain` | `DAT_a802e3de` | System configuration byte +0xE: the blue gain (0..100). | proven |
| `sys_config_red_offset` | `DAT_a802e3df` | System configuration byte +0xF: the red offset (0..100). | proven |
| `sys_config_green_offset` | `DAT_a802e3e0` | System configuration byte +0x10: the green offset (0..100). | proven |
| `sys_config_blue_offset` | `DAT_a802e3e1` | System configuration byte +0x11: the blue offset (0..100). | proven |
| `sys_config_red_offset_first` | `DAT_a802e3e2` | System configuration byte +0x12: signed red offset of the first set. | derived |
| `sys_config_green_offset_first` | `DAT_a802e3e3` | System configuration byte +0x13: signed green offset of the first set. | derived |
| `sys_config_blue_offset_first` | `DAT_a802e3e4` | System configuration byte +0x14: signed blue offset of the first set. | derived |
| `sys_config_red_offset_second` | `DAT_a802e3e5` | System configuration byte +0x15: signed red offset of the second set. | derived |
| `sys_config_green_offset_second` | `DAT_a802e3e6` | System configuration byte +0x16: signed green offset of the second set. | derived |
| `sys_config_blue_offset_second` | `DAT_a802e3e7` | System configuration byte +0x17: signed blue offset of the second set. | derived |
| `sys_config_color_matrix_row_bit` | `DAT_a802e3ea` | System configuration halfword +0x1A: the row bit pq_fga_load_color_matrix_row gets (picture modes 15..22). | descriptive |
| `sys_config_preset_index` | `DAT_a802e3ed` | System configuration byte +0x1D: the preset index for the preset table look-ups. | derived |
| `sys_config_byte_0x22` | `DAT_a802e3f2` | System configuration byte +0x22: while 1 the bring-up task does nothing for a channel on port 2. | descriptive |
| `sys_config_byte_0x23` | `DAT_a802e3f3` | System configuration byte +0x23: while 1 the bring-up task does nothing for a channel on port 3. | descriptive |
| `sys_config_channel2_enable` | `DAT_a802e3fa` | System configuration byte +0x2A: enable value of channel 2 (1 = restart it). | derived |
| `sys_config_channel3_enable` | `DAT_a802e3fc` | System configuration byte +0x2C: enable value of channel 3 (1 = restart it). | derived |
| `sys_config_panel_power_all_channels` | `DAT_a802e3fe` | System configuration byte +0x2E: 0 = only channel 0 drives the panel power, 1 = every channel does. | derived |
| `sys_config_entry_actions_all_channels` | `DAT_a802e3ff` | System configuration byte +0x2F: 0 = state entry actions for channel 0 only, 1 = for every channel. | derived |
| `sys_config_byte_0x33` | `DAT_a802e403` | System configuration flag byte +0x33 (0 or 1), passed on at power-off. | descriptive |
| `sys_config_blurfree_mode` | `_DAT_a802e408` | System configuration word +0x38: the blur-reduction mode (off, GEN1, GEN2). | derived |
| `libc_errno` | `_DAT_a802e40c` | The C library error number, cleared and tested by the reentrant system call wrappers. | derived |
