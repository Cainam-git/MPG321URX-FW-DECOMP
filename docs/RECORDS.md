# Record fields

The named fields of the principal records of the main processor, by offset. [Data objects](DATA.md) describes the records, [Function names](NAMES.md) how the names were given. An offset that is missing here has no name: the code that uses it does not show what it holds, or no function addresses it on its own.

## User settings record: `user_settings`

At 0xA802D290, 0x1FC bytes; 115 named offsets.

| Offset | Name | What it holds | Basis |
|---|---|---|---|
| +0x4 | `user_settings_option_bits` | Settings word +4: bits 28-30 = link option enable, port 0 option, configuration bit 25. | derived |
| +0x5 | `user_settings_output_mode` | Settings byte +5: the output mode setting. | derived |
| +0x8 | `user_settings_language` | Settings byte +8: the menu language (1 = English). | proven |
| +0x9 | `user_settings_brightness` | Settings byte +9: Brightness. | proven |
| +0xA | `user_settings_contrast` | Settings byte +0xA: Contrast. | proven |
| +0xC | `user_settings_osd_timeout` | Settings byte +0xC: OSD Time out. | proven |
| +0xD | `user_settings_menu_position_a` | Settings byte +0x0D: first value (at most 100) osd_user_apply_menu_position gives osd_api_set_position. | descriptive |
| +0xE | `user_settings_menu_position_b` | Settings byte +0x0E: second value (at most 100) osd_user_apply_menu_position gives osd_api_set_position. | descriptive |
| +0xF | `user_settings_transparency` | Settings byte +0xF: menu Transparency. | proven |
| +0x10 | `user_settings_audio_level` | Settings byte +0x10: the audio level (at most 100). | derived |
| +0x11 | `user_settings_color_temperature` | Settings byte +0x11: Color Temperature. | proven |
| +0x12 | `user_settings_red_gain` | Settings byte +0x12: the custom red gain. | proven |
| +0x13 | `user_settings_green_gain` | Settings byte +0x13: the custom green gain. | proven |
| +0x14 | `user_settings_blue_gain` | Settings byte +0x14: the custom blue gain. | proven |
| +0x15 | `user_settings_red_black_level` | Settings byte +0x15: red black level (DDC/CI VCP 0x6C). | derived |
| +0x16 | `user_settings_green_black_level` | Settings byte +0x16: green black level (DDC/CI VCP 0x6E). | derived |
| +0x17 | `user_settings_blue_black_level` | Settings byte +0x17: blue black level (DDC/CI VCP 0x70). | derived |
| +0x18 | `user_settings_byte_0x18` | Settings byte +0x18, reported to the PC tool. | descriptive |
| +0x19 | `user_settings_response_time` | Settings byte +0x19: the response time level. | proven |
| +0x1A | `user_settings_theme_mode` | Settings byte +0x1A: the theme mode (at most 4). | derived |
| +0x1E | `user_settings_input_source` | Settings byte +0x1E: the selected Input Source (DDC/CI VCP 0x60). | proven |
| +0x1F | `user_settings_pip_pbp_mode` | Settings byte +0x1F: PIP/PBP mode (0 off, 1 PIP, 2 PBP). | proven |
| +0x20 | `user_settings_second_source` | Settings byte +0x20: the source of the second picture (PIP source, PBP source 2). | proven |
| +0x21 | `user_settings_channel2_source` | Settings byte +0x21: receives the port code of channel 2 after display. | derived |
| +0x22 | `user_settings_channel3_source` | Settings byte +0x22: receives the port code of channel 3 after display. | derived |
| +0x23 | `user_settings_source_slot4` | Settings byte +0x23: the source of slot 4. | descriptive |
| +0x25 | `user_settings_source_slot5` | Settings byte +0x25: the source of slot 5. | descriptive |
| +0x26 | `user_settings_source_slot6` | Settings byte +0x26: the source of slot 6. | descriptive |
| +0x27 | `user_settings_byte_0x27` | Settings byte +0x27, chooses the record passed to the slot 5 routine. | descriptive |
| +0x28 | `user_settings_byte_0x28` | Settings byte +0x28, chooses the record passed to the slot 6 routine. | descriptive |
| +0x2B | `user_settings_byte_0x2b` | Settings byte +0x2B, applied for slot 5. | descriptive |
| +0x2C | `user_settings_byte_0x2c` | Settings byte +0x2C, applied for slot 6. | descriptive |
| +0x2D | `user_settings_byte_0x2d` | Settings byte +0x2D, applied for slot 5. | descriptive |
| +0x2E | `user_settings_byte_0x2e` | Settings byte +0x2E, applied for slot 6. | descriptive |
| +0x2F | `user_settings_pbp_layout` | Settings byte +0x2F: the PBP layout. | proven |
| +0x30 | `user_settings_pip_location` | Settings word +0x30; bits 4-7 = the PIP location. | derived |
| +0x31 | `user_settings_pip_size` | PIP window size: 0 Large, 1 Medium, 2 Small (the PIP Size list highlights row 2 minus it). | derived |
| +0x34 | `user_settings_image_enhancement` | Settings halfword +0x34; bits 0-3 = Image Enhancement level; also read for the scaling mode. | derived |
| +0x44 | `user_settings_gamma` | Settings byte +0x44: the gamma choice (DDC/CI VCP 0x72: 0x50 -> 2, 0x78 -> 1). | derived |
| +0x45 | `user_settings_channel2_enable` | Settings byte +0x45: the enable setting of channel 2. | derived |
| +0x46 | `user_settings_byte_0x46` | Settings byte +0x46, chooses the record that decides whether channel 2 restarts. | descriptive |
| +0x47 | `user_settings_channel3_enable` | Settings byte +0x47: the enable setting of channel 3. | derived |
| +0x48 | `user_settings_byte_0x48` | Settings byte +0x48, chooses the record that decides whether channel 3 restarts. | descriptive |
| +0x49 | `user_settings_sharpness` | Settings byte +0x49: Sharpness. | proven |
| +0x4A | `user_settings_optix_scope` | Settings byte +0x4A: the Optix Scope switch. | proven |
| +0x4B | `user_settings_scope_size` | Settings byte +0x4B: the Optix Scope size. | proven |
| +0x4C | `user_settings_scope_ratio` | Settings byte +0x4C: the Optix Scope ratio. | proven |
| +0x4F | `user_settings_channel0_link_option` | Settings byte +0x4F: the link option of channel 0. | derived |
| +0x50 | `user_settings_channel1_link_option` | Settings byte +0x50: the link option of channel 1. | derived |
| +0x51 | `user_settings_channel2_link_option` | Settings byte +0x51: the link option of channel 2. | derived |
| +0x52 | `user_settings_channel3_link_option` | Settings byte +0x52: the link option of channel 3. | derived |
| +0x54 | `user_settings_pip_custom_x` | Settings halfword +0x54: x position of the channel 1 window for PIP location 4 'Customize'. | derived |
| +0x56 | `user_settings_pip_custom_y` | Settings halfword +0x56: y position of the channel 1 window for PIP location 4 'Customize'. | derived |
| +0x8F | `user_settings_response_time_copy` | Settings byte +0x8F: the limited response time that pq_user_reset_response_level restores +0x19 from. | derived |
| +0xA8 | `user_settings_gaming_flags` | Settings word +0xA8 switches: bit 7 Adaptive-Sync, bit 11 Pro (1) / Game (0), bit 12 Refresh Rate display. | derived |
| +0xAC | `user_settings_settings_page_flags` | Settings word +0xAC: first byte = RGB Brightness level; bit 22 Info. On Screen, bit 17 goes to the PC tool. | derived |
| +0xB0 | `user_settings_blur_free_mode` | Settings word +0xB0: the blur reduction mode. | proven |
| +0x11C | `user_settings_professional_flags` | Settings word +0x11C switches: bit 4 Low Blue Light, bit 31 automatic level. | derived |
| +0x13E | `user_settings_refresh_rate_location` | Settings byte +0x13E: the location of the Refresh Rate overlay. | proven |
| +0x13F | `user_settings_alarm_clock_location` | Settings byte +0x13F: the location of the Alarm Clock overlay. | proven |
| +0x140 | `user_settings_byte_0x140` | Settings byte +0x140, read and set by the PC tool. | descriptive |
| +0x15B | `user_settings_night_vision` | Settings byte +0x15B: Night Vision. | proven |
| +0x174 | `user_settings_word_0x174` | Settings word +0x174; bit 15 = the AI Vision switch. | derived |
| +0x177 | `user_settings_byte_0x177` | Settings byte +0x177, read and set by the PC tool. | descriptive |
| +0x17B | `user_settings_crosshair_color` | Settings byte +0x17B: the Smart Crosshair colour (2 = automatic). | proven |
| +0x17C | `user_settings_kvm` | Settings byte +0x17C: the KVM setting. | proven |
| +0x181 | `user_settings_pro_mode` | Settings byte +0x181: the Professional mode. | proven |
| +0x182 | `user_settings_game_mode` | Settings byte +0x182: the Game Mode. | proven |
| +0x183 | `user_settings_pro_mode_copy_1` | Settings byte +0x183: copy 1 of the Pro mode (+0x181), kept with bit 10 of word +0xA8. | derived |
| +0x184 | `user_settings_game_mode_copy_1` | Settings byte +0x184: copy 1 of the Game mode (+0x182). | derived |
| +0x185 | `user_settings_pro_mode_copy_2` | Settings byte +0x185: copy 2 of the Pro mode (+0x181), kept with bit 9 of word +0xA8. | derived |
| +0x186 | `user_settings_game_mode_copy_2` | Settings byte +0x186: copy 2 of the Game mode (+0x182). | derived |
| +0x187 | `user_settings_pro_mode_copy_3` | Settings byte +0x187: copy 3 of the Pro mode (+0x181), kept with bit 8 of word +0xA8. | derived |
| +0x188 | `user_settings_game_mode_copy_3` | Settings byte +0x188: copy 3 of the Game mode (+0x182). | derived |
| +0x189 | `user_settings_key_guide_shown` | Settings byte +0x189: the two key guide text numbers last drawn (high and low nibble); 0xFF forces a redraw. | derived |
| +0x18A | `user_settings_navi_key_up` | Settings byte +0x18A: the Navi Key up function. | proven |
| +0x18B | `user_settings_navi_key_down` | Settings byte +0x18B: the Navi Key down function. | proven |
| +0x18C | `user_settings_navi_key_left` | Settings byte +0x18C: the Navi Key left function. | proven |
| +0x18D | `user_settings_navi_key_right` | Settings byte +0x18D: the Navi Key right function. | proven |
| +0x190 | `user_settings_crosshair_icon` | Settings byte +0x190: the Smart Crosshair icon, 0..6; with 0 the crosshair overlay is not shown. | proven |
| +0x1A0 | `user_settings_alarm_clock` | Settings byte +0x1A0: the Alarm Clock timer choice. | proven |
| +0x1A1 | `user_settings_alarm_minutes` | Settings byte +0x1A1: minutes left of the Alarm Clock countdown. | derived |
| +0x1A2 | `user_settings_alarm_seconds` | Settings byte +0x1A2: seconds left (59..0) of the Alarm Clock countdown. | derived |
| +0x1A3 | `user_settings_byte_0x1a3` | Settings byte +0x1A3: row byte shared by the Navi Key list, alarm editor, position editor and PBP source list. | derived |
| +0x1A4 | `user_settings_screen_size` | Settings byte +0x1A4: Screen Size. | proven |
| +0x1A5 | `user_settings_refresh_rate_custom_x` | Settings byte +0x1A5: custom x position (a grid number) of the Refresh Rate box. | descriptive |
| +0x1A6 | `user_settings_refresh_rate_custom_y` | Settings byte +0x1A6: custom y position (a grid number) of the Refresh Rate box. | descriptive |
| +0x1A7 | `user_settings_alarm_clock_custom_x` | Settings byte +0x1A7: custom x position (a grid number) of the Alarm Clock box. | descriptive |
| +0x1A8 | `user_settings_alarm_clock_custom_y` | Settings byte +0x1A8: custom y position (a grid number) of the Alarm Clock box. | descriptive |
| +0x1A9 | `user_settings_confirm_change` | Settings byte +0x1A9: 1 = a Game/Pro mode switch first asks with the 'Confirm Change !' notice. | derived |
| +0x1AA | `user_settings_notice_button` | Settings byte +0x1AA: the button highlighted in the change notice (1 = Yes, 0 = No). | derived |
| +0x1AC | `user_settings_crosshair_x` | Settings halfword +0x1AC: x origin of the crosshair layer (reset value 0x750). | derived |
| +0x1AE | `user_settings_crosshair_y` | Settings halfword +0x1AE: y origin of the crosshair layer. | derived |
| +0x1D5 | `user_settings_burn_in_flag` | Settings byte +0x1D5: burn-in mode on (1) or off (0), set by the factory tool. | proven |
| +0x1D6 | `user_settings_fast_uph` | Settings byte +0x1D6: drawn in hex after "fastUPH" in the factory menu; factory tool status 2. | proven |
| +0x1D7 | `user_settings_factory_switch_bits` | Settings byte +0x1D7: bit 7 = factory menu item "HDMI CTS", bit 6 = CEC PWM Adjust opened. | derived |
| +0x1D8 | `user_settings_cec_pwm_brightness` | Settings byte +0x1D8: the brightness loaded by the factory menu item CEC PWM Adjust. | derived |
| +0x1DA | `user_settings_brightness_knee` | Settings halfword +0x1DA: the knee of the brightness mapping line. | derived |
| +0x1DC | `user_settings_oled_care_flags` | Settings word +0x1DC: bit 31 Panel Protect run, bit 30 Panel Protect request, bit 15 Static Screen. | derived |
| +0x1DD | `user_settings_pixel_shift` | Settings byte +0x1DD: the Pixel Shift speed. | proven |
| +0x1DF | `user_settings_static_screen_level` | Settings byte +0x1DF: the Static Screen Detection reduce level. | proven |
| +0x1E0 | `user_settings_static_screen_start_time` | Settings byte +0x1E0: the Static Screen Detection start time. | proven |
| +0x1E1 | `user_settings_static_screen_time_required` | Settings byte +0x1E1: the Static Screen Detection time required. | proven |
| +0x1E2 | `user_settings_byte_0x1e2` | Settings byte +0x1E2, checked when the panel protect prompt buttons are highlighted. | descriptive |
| +0x1E8 | `user_settings_multi_logo_detection` | Settings byte +0x1E8: Multi Logo Detection on or off. | proven |
| +0x1E9 | `user_settings_multi_logo_level` | Settings byte +0x1E9: the Multi Logo Detection level. | proven |
| +0x1EA | `user_settings_taskbar_detection` | Settings byte +0x1EA: Taskbar Detection on or off. | proven |
| +0x1EB | `user_settings_taskbar_level` | Settings byte +0x1EB: the Taskbar Detection level. | proven |
| +0x1EC | `user_settings_boundary_detection` | Settings byte +0x1EC: Boundary Detection; read as a word, bit 7 = Type C PD Charge. | proven |
| +0x1ED | `user_settings_boundary_level` | Settings byte +0x1ED: the Boundary Detection level. | derived |
| +0x1EE | `user_settings_protect_notice` | Settings byte +0x1EE: Protect Notice. | proven |
| +0x1F0 | `user_settings_pbp_custom_split_x` | Settings halfword +0x1F0: split position of PBP layout 2 'Customize' (width of channel 0). | derived |
| +0x1F2 | `user_settings_pbp_custom_split_lines` | Settings halfword +0x1F2: the height of the split line, stored with the PBP custom split by its editor. | descriptive |
| +0x1F4 | `user_settings_word_0x1f4` | Settings word +0x1F4; bit 31 = the DSC switch; read for the menu tabs. | derived |
| +0x1F6 | `user_settings_factory_mode_marker` | Settings halfword +0x1F6: 0x55AA = factory mode on (shown as PRODUCT ON); 0xBB99 written when off. | derived |

## Factory record: `factory_record`

At 0xA802D274, 0x1C bytes; 8 named offsets.

| Offset | Name | What it holds | Basis |
|---|---|---|---|
| +0x2 | `factory_record_serial_length` | Factory record +0x02: number of characters of the serial number drawn after "SN:". | proven |
| +0x3 | `factory_record_serial` | Factory record +0x03: the serial number text (up to 0x12 characters; 0 ends, 0xFF shown as a space). | proven |
| +0x10 | `factory_record_key_test_bits` | Factory record +0x10: one bit per front key passed in the key test (0x3F = all). | proven |
| +0x11 | `factory_record_aux0_minutes` | Factory record +0x11: minutes 0..59 counted while auxiliary GPIO pin 0 reads high. | derived |
| +0x12 | `factory_record_aux0_hours` | Factory record +0x12: hours (up to 0xFFFF) counted while auxiliary GPIO pin 0 reads high. | derived |
| +0x14 | `factory_record_byte_0x14` | Factory record byte +0x14, read when the power state changes and by the USB port choice. | descriptive |
| +0x15 | `factory_record_oled_error_count` | Factory record +0x15: OLED error detections counted; drawn after "Panel ERR Count" in the factory menu. | proven |
| +0x16 | `factory_record_oled_error_status` | Factory record +0x16: OLED controller register 0x10 at the stored error; drawn after "Status". | proven |

## Device settings record: `device_settings`

At 0xA802E1A0, 0x50 bytes; 5 named offsets.

| Offset | Name | What it holds | Basis |
|---|---|---|---|
| +0x7 | `device_settings_pip_mode` | The current picture-in-picture / picture-by-picture mode (0 = one picture). | proven |
| +0x8 | `device_settings_on_time` | Device settings word +8: on-time; byte +8 = minutes 0..59, halfword +9 = hours; drawn as word >> 8. | proven |
| +0xB | `device_settings_brightness_preset` | Device settings byte +0xB: the brightness preset (0..2) set by the factory tool. | derived |
| +0x34 | `device_settings_fga_storage_device` | Device settings byte +0x34: storage device of the FGA block. | derived |
| +0x37 | `device_settings_byte_0x37` | Device settings byte +0x37, set from the FGA commands and checked when gamma loads. | descriptive |

## Part record: `part_record`

At 0xA802E1F0, 0x30 bytes; 16 named offsets.

| Offset | Name | What it holds | Basis |
|---|---|---|---|
| +0x1 | `part_record_byte_0x1` | Part record byte +1, answered to DDC/CI VCP 0xE2 sub-code 2. | descriptive |
| +0x2 | `part_record_byte_0x2` | Part record byte +2, answered to DDC/CI VCP 0xE2 sub-code 3. | descriptive |
| +0x3 | `part_record_byte_0x3` | Part record byte +3, answered to DDC/CI VCP 0xE2 sub-code 4. | descriptive |
| +0x4 | `part_record_byte_0x4` | Part record byte +4, answered to DDC/CI VCP 0xE2 sub-code 5. | descriptive |
| +0x5 | `part_record_byte_0x5` | Part record byte +5, answered to DDC/CI VCP 0xE2 sub-code 6. | descriptive |
| +0x6 | `part_record_warm50_red` | Part record +0x06: red value of the factory menu row Warm50. | proven |
| +0x7 | `part_record_warm50_green` | Part record +0x07: green value of the factory menu row Warm50. | proven |
| +0x8 | `part_record_warm50_blue` | Part record +0x08: blue value of the factory menu row Warm50. | proven |
| +0x9 | `part_record_normal65_red` | Part record +0x09: red value of the factory menu row Normal65. | proven |
| +0xA | `part_record_normal65_green` | Part record +0x0A: green value of the factory menu row Normal65. | proven |
| +0xB | `part_record_normal65_blue` | Part record +0x0B: blue value of the factory menu row Normal65. | proven |
| +0x12 | `part_record_cool93_red` | Part record +0x12: red value of the factory menu row Cool93. | proven |
| +0x13 | `part_record_cool93_green` | Part record +0x13: green value of the factory menu row Cool93. | proven |
| +0x14 | `part_record_cool93_blue` | Part record +0x14: blue value of the factory menu row Cool93. | proven |
| +0x24 | `part_record_hdr_peak_luminance` | Part record halfword +0x24: the HDR peak luminance sent to the input processor. | derived |
| +0x26 | `part_record_brightness_max` | Part record halfword +0x26: the panel level at 100 % brightness. | derived |

## System configuration record: `sys_config`

At 0xA802E3D0, 0x200 bytes; 28 named offsets.

| Offset | Name | What it holds | Basis |
|---|---|---|---|
| +0x3 | `sys_config_byte_3` | Byte 3 of the system configuration record; non-zero selects the second form of the output timing. | descriptive |
| +0x7 | `sys_config_auto_level_mode` | System configuration byte +7: the automatic level mode (1 = stepping on). | derived |
| +0x9 | `sys_config_color_gain` | System configuration byte +9: the colour gain of the colour matrix. | derived |
| +0xA | `sys_config_color_matrix_param` | System configuration byte +0xA: the colour parameter of the colour matrix. | derived |
| +0xB | `sys_config_picture_mode` | System configuration byte +0xB: the picture mode. | proven |
| +0xC | `sys_config_red_gain` | System configuration byte +0xC: the red gain (0..100). | proven |
| +0xD | `sys_config_green_gain` | System configuration byte +0xD: the green gain (0..100). | proven |
| +0xE | `sys_config_blue_gain` | System configuration byte +0xE: the blue gain (0..100). | proven |
| +0xF | `sys_config_red_offset` | System configuration byte +0xF: the red offset (0..100). | proven |
| +0x10 | `sys_config_green_offset` | System configuration byte +0x10: the green offset (0..100). | proven |
| +0x11 | `sys_config_blue_offset` | System configuration byte +0x11: the blue offset (0..100). | proven |
| +0x12 | `sys_config_red_offset_first` | System configuration byte +0x12: signed red offset of the first set. | derived |
| +0x13 | `sys_config_green_offset_first` | System configuration byte +0x13: signed green offset of the first set. | derived |
| +0x14 | `sys_config_blue_offset_first` | System configuration byte +0x14: signed blue offset of the first set. | derived |
| +0x15 | `sys_config_red_offset_second` | System configuration byte +0x15: signed red offset of the second set. | derived |
| +0x16 | `sys_config_green_offset_second` | System configuration byte +0x16: signed green offset of the second set. | derived |
| +0x17 | `sys_config_blue_offset_second` | System configuration byte +0x17: signed blue offset of the second set. | derived |
| +0x1A | `sys_config_color_matrix_row_bit` | System configuration halfword +0x1A: the row bit pq_fga_load_color_matrix_row gets (picture modes 15..22). | descriptive |
| +0x1D | `sys_config_preset_index` | System configuration byte +0x1D: the preset index for the preset table look-ups. | derived |
| +0x22 | `sys_config_byte_0x22` | System configuration byte +0x22: while 1 the bring-up task does nothing for a channel on port 2. | descriptive |
| +0x23 | `sys_config_byte_0x23` | System configuration byte +0x23: while 1 the bring-up task does nothing for a channel on port 3. | descriptive |
| +0x2A | `sys_config_channel2_enable` | System configuration byte +0x2A: enable value of channel 2 (1 = restart it). | derived |
| +0x2C | `sys_config_channel3_enable` | System configuration byte +0x2C: enable value of channel 3 (1 = restart it). | derived |
| +0x2E | `sys_config_panel_power_all_channels` | System configuration byte +0x2E: 0 = only channel 0 drives the panel power, 1 = every channel does. | derived |
| +0x2F | `sys_config_entry_actions_all_channels` | System configuration byte +0x2F: 0 = state entry actions for channel 0 only, 1 = for every channel. | derived |
| +0x33 | `sys_config_byte_0x33` | System configuration flag byte +0x33 (0 or 1), passed on at power-off. | descriptive |
| +0x38 | `sys_config_blurfree_mode` | System configuration word +0x38: the blur-reduction mode (off, GEN1, GEN2). | derived |
| +0x3C | `libc_errno` | The C library error number, cleared and tested by the reentrant system call wrappers. | derived |

## Channel record (the first of four): `channel_records`

At 0xA802DF30, 0x78 bytes; 4 named offsets.

| Offset | Name | What it holds | Basis |
|---|---|---|---|
| +0x6 | `channel_records_mode_row` | The mode row inside each channel record (+6), stored to the saved-mode table. | derived |
| +0x3A | `channel_records_byte_0x3a` | Byte +0x3A of channel record 0, checked by the DDC/CI set handler. | descriptive |
| +0x54 | `channel_records_half_0x54` | Halfword +0x54 of channel record 0, compared with the default panel row. | descriptive |
| +0x70 | `channel_records_flags` | Word +0x70 of channel record 0: its flags. | proven |
