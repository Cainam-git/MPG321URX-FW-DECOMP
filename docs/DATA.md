# Data objects

The principal records and tables that the two LEON programs keep in memory: their addresses in FW.021 and what the
code shows about them. Only objects whose role is established by the code that uses them are listed. Field offsets
are given where the code that names or prints them fixes their meaning.

An object named in `symbols/<section>.data.json` (name, description and what the name rests on) appears under that
name in the source, through the same `#define` lists as the function names (see
[Function names](NAMES.md#names-in-the-source)); the tables give that name in brackets. Every other object carries
its label in the source: `DAT_a802e3d0` is the object at 0xA802E3D0, and a label with a leading underscore is the
same address read with another type.

## Main processor

[Record fields](RECORDS.md) lists the named fields of the settings records and of the first channel record by
offset.

### Settings

| Address | Size | Object | Contents |
|---|---|---|---|
| 0xA802D290 | 0x1FC | User settings record (`user_settings`) | Every setting of the on-screen menu. Read from the settings EEPROM at start-up (`nvram_load_user_settings`), defaults in ROM at 0x198524, reset by `sys_user_factory_reset`. Byte +8 is the menu language. |
| 0xA802D274 | 0x1C | Factory record (`factory_record`) | Values of the factory menu and the factory tool: key-test bits (+0x10), panel error count (+0x11), check status (+0x12). Saved at EEPROM offset 0x2E0. |
| 0xA802E1A0 | 0x50 | Device settings record (`device_settings`) | Settings that belong to the device, not to the user: power status bit, per-port link settings, FGA fields. Saved at EEPROM offset 0x470 (`nvram_write_settings_record`), defaults in ROM at 0x20170. Read and written field by field with `nvram_get_device_setting` / `nvram_set_device_setting`. Word +8 holds the on-time. |
| 0xA802E1F0 | 0x30 | Part record (`part_record`) | Three-byte colour entries of the picture modes and related values. Saved at EEPROM offset 0x440, defaults in ROM at 0x20140. |
| 0xA802E3D0 | 0x200 | System configuration record (`sys_config`) | The working configuration of the picture path (called `stSysConfig` in the firmware's messages): frame-rate converter lock and bypass bits (bits 27 and 26 of word 0), picture mode (+0xB), gamma selection (+0x18), colour values, per-channel modes. Changed through `sys_api_config` and the `sys_api_set_…` functions. |

### Picture channels and inputs

| Address | Size | Object | Contents |
|---|---|---|---|
| 0xA802DF30 | 4 x 0x78 | Channel records (`channel_records`) | One record per picture channel (main picture and up to three further pictures). Word 0 holds the state (bits 28-31), the port (bits 12-15), the receiver index (bits 8-11) and the picture window (bits 4-7); word +0x70 holds flags; the rest is the measured and the applied timing. |
| 0xA802E224 | 0x2A each | Port records (`port_records`) | One record per input port: status bits (halfword 0), state (+2), sync mode (+9), mode (+0xA), time stamp (+0x12). |
| 0xA802E116 | 7 x 0x12 | Port entries (`port_entries`) | The inputs as the control logic sees them: class (bits 12-15 of halfword 0), flags, bus id (+0x10). Filled from the port template that the input processor sends. |
| 0xA802D8AE | 0x16 each | Port link rows (`port_link_rows`) | The link settings of each input as sent to the input processor (`input_init_port_link_row`). |
| 0x1A42A8 (ROM) | 8 x 0x16 | Port table (`port_table`) | The fixed description of each input: port code (+0), type (+1), bus id (+2), size and base of its EDID memory (+4, +6), detect pin and its active level (+0xB..+0xD), control pin and its active level (+0xE..+0x10). |
| 0xA802CBBE | 9 x 2 | Port timers | Down-counters in ticks, updated by `input_port_timers_update`. |
| 0xA802C9FE, 0xA802CA00 | 2 each | Port status words | One bit per input port in each word. |
| 0x1A5A16 (ROM) | 0x24 each | Mode table (`input_mode_table`) | The known input timings that `input_match_port_mode` compares a measured signal with. |
| 0x300 (EEPROM) | 20 x 0x10 | Saved-mode table | The timings seen last, stored by `nvram_store_mode_row`. |

### Panel and output

| Address | Size | Object | Contents |
|---|---|---|---|
| 0xA802E378 | 0x58 | Active panel timing row (`panel_active_row`) | The panel timing in use (clock, totals, sizes, refresh rate). Chosen by `SYSAPI_GetPanelParamStruct` from the rows in ROM at 0x198380 and set with `panel_api_set_active_row`; the start-up default is the ROM row at 0x1A30D0. |
| 0xA802D6A4 | 4 | Working row pointer (`panel_working_row_ptr`) | Points at the working copy of the active row (0xA802D6A8), in which the link type is remapped and the display mode is filled in (`panel_transform_row`). The output set-up reads this copy. |
| 0xA802E110 | 1 | Panel power state (`panel_power_state`) | State of `panel_power_sequencer_task` (1 = off, 6 = on). |
| 0xA802D896 | | OLED power state record | State (+0), step (+1) and working fields of `oled_power_task`. |
| 0xA802D892 | 2 | OLED refresh-rate state (`oled_frc_state`) | State and row index (+1) of `oled_frc_task`; the row index is what the panel controller is told. |

### On-screen menu

| Address | Size | Object | Contents |
|---|---|---|---|
| 0xA802AFEC | 2 | Menu state (`osd_menu_state`) | The screen the menu is on (0 = closed). |
| 0xA802422C | 6 words per state | Menu key table (`osd_menu_key_table`) | For every menu state the function that handles each key. The entries are code addresses relative to the listing base (pointer + 0xA0060000 = function address). |
| 0xA8027AA8 | per layer | Menu layer bases (`osd_layer_bases`) | Register base of each of the two menu layers. |
| 0xA802C9CA, 0xA802C9C8 | per layer | Menu layer size | Columns and rows of each layer in character cells. |
| 0xA802C9A2, 0xA802C9A0 | per layer | Glyph write position | Address and count for the next glyph data written to a layer's memory. |

### System services

| Address | Size | Object | Contents |
|---|---|---|---|
| 0xA8027B50 | 15 words | Interrupt level table | The service function of each interrupt level (index = trap type - 0x11). |
| 0xA802B170 | 15 x 16 words | Interrupt source hooks (`irq_source_hooks`) | The handler registered for each source of each level (`irq_set_source_handler`). |
| 0xA802B0C4 | | Tick record | The tick count (word at +4; its low half is what `timer_get_ticks16` returns) and the tick hooks. |
| 0xA802B0EC | 128 + 2 | Debug serial receive buffer (`dbg_uart_rx_ring`) | Ring buffer with its head and tail bytes behind it. |
| 0xA802B0B0 | 4 | Debug print mask (`dbg_print_mask`) | One bit per class of debug messages (`dbg_is_print_enabled`). |
| 0xA802AFA8 | | Application event queue | Up to ten pending events (type in bits 6-7: 0 application, 0x40 key, 0x80 menu, 0xC0 DDC/CI). |
| 0xA802AF6A | 23 x 2 | Application timers (`app_timers`) | Millisecond down-counters. |
| 0xA802CC1C | 15 words | Callback table (`sys_callback_table`) | Callbacks registered at start-up with `sys_register_callback`. |
| 0xA802DA6C | | 8051 message queue | Ring of 20-byte messages waiting for a free mailbox slot (`ipc_8051_tx_queue_flush`). |
| 0xA802D992 | 10 | I2C bus descriptor (`i2c_bus_descriptor`) | Pins, delay, device address and mode of the software I2C bus in use. |

### Picture and sound

| Address | Size | Object | Contents |
|---|---|---|---|
| 0xA802B7B4 | 1 | Selected picture window (`pq_selected_window`) | The window that picture settings currently go to (`pq_select_window`). |
| 0xA802A46C, 0xA802A468 | 6, 3 | Colour gains and offsets | The three gain values and the three offset values that the colour matrix is built from (`pq_color_matrix_rebuild`). |
| 0xA802CC90, 0xA802CD90, 0xA802CE90 | 256 each | Zone colour averages (`pq_zone_averages_blue`, `_green`, `_red`) | The blue, green and red average of each zone of a 16 x 16 grid, one byte per zone, read through the memory port by `pq_read_zone_color_averages`. |
| 0xA802CC80, 0xA802CC82 | 2 each | Audio unit assignment | Which sound source holds each of the four audio units (four 4-bit fields), and the order in which they were assigned. |
| 0xA802A480 | 9 | Audio slot owners (`audio_slot_owners`) | The source that owns each of the nine audio output slots. |

## Input processor

| Address | Size | Object | Contents |
|---|---|---|---|
| 0xA807A824 | 9 x 20 | Port records (`input_port_records`) | One record per input stream: link state (+0) and the flags published to the main processor (+0xD). Records 0-1 are the HDMI 2.0 inputs, 2-3 the HDMI 2.1 inputs, 4-5 the DisplayPort inputs and 6-8 the further streams of DisplayPort input 0. |
| 0xA807CC64 | 24 each | HDMI receiver records | Power state (+0) and equaliser state of each HDMI receiver. |
| 0xA807D7E0 | 400 each | HDMI 2.1 input records | State of each HDMI 2.1 input. |
| 0xA807DC18 | 300 each | DisplayPort input records | Settings and state of each DisplayPort input. |
| 0xA8078BB0 | 3 x 24 | Copy-protection output records (`hdcp_tx_records`) | State of the handshake on each video output (`hdcp_tx_task`). |
| 0xA807D5C8, 0xA807D5E8, 0xA807D608 | 16 each | Copy-protection input records | State of the handshake on the HDMI 2.0, HDMI 2.1 and DisplayPort inputs. |
| 0xA80793B8 | 16 x 24 | Task table (`sys_task_table`) | Timed tasks (`sys_task_start`, `sys_task_run_pending`). |
| 0xA80793A8 | 4 | Tick count (`timer_tick_count`) | What `timer_get_ticks` returns. |
| 0xA8076040 | 15 words | Interrupt vector table | The service function of each interrupt level. |
| 0xA8076088 | 4 | Crash hook | The function called after a trap has stored the registers at 0xA807FF60. |
| 0xA8077A08 | 257 x 2 | HDR tone curve (`hdr_tone_curve`) | The curve that `hdr_tmo_write_curve` loads (0x400 = neutral). |
| 0xA8078AA0 | | HDR10+ metadata record | The dynamic metadata of the incoming signal. |
| 0xA8079538 | | Compression encoder record | The timing values from which `sys_dsc_enc_compute_pps` computes the encoder settings. |
| 0xA80787F8 | | Multi-stream message state | Indexes, flags and the current port of the DisplayPort MST message service (`dp_mst_task`). |

## Mailboxes

The processors exchange messages through three mailbox portals. [Mailbox commands](MAILBOX.md) lists the commands.

| Portal | Between | Used for |
|---|---|---|
| 0 | Main processor and 8051 | Commands to the 8051 (`ipc_send_8051_command`), queued messages (EDID data, serial bytes, DDC/CI replies, storage blocks) and the messages the 8051 sends back (`ipc_8051_poll_messages`). |
| 1 | Main processor and input processor | Commands with a checksum (`ipc_send_command`, received by `ipc_dispatch_command`), the reply slot, and the state words the input processor publishes. |
| 2 | Main processor and Tensilica program | Commands in slot 0x20 (`ldc_send_command`), see [the Tensilica program](MAP.md#commands-from-the-main-processor). |
