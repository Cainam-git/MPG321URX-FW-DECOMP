/* SYSAPI_ConfigSystemPIPMode  (FUN_a0149bf0)
 *
 * Set the picture-in-picture / picture-by-picture mode and reconfigure the channels.
 * Name basis: proven - prints 'SYSAPI_ConfigSystemPIPMode %d' (original name); called from UserSetPIPMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0149bf0 @ 0xa0149bf0-0xa0149e8c (668 bytes), flags -mcpu=v8 -O3 -g.
 *
 * RANGE: the assembly header (and symbols/leon2m.splits.json "a0149bf0": "a0149db8") cut this function at its tail
 * call; the 8-entry jump table (0xe34b4 + 0xA0060000 run-time offset) targets 0xa0149e5c (modes 0, 2),
 * 0xa0149e14 (1, 5), 0xa0149cf4 (3, 6) and 0xa0149db8 (4, 7). "FUN_a0149db8" is one case body of this function and
 * 0xa0149e14-0xa0149e8c are two more. A comparison against the firmware must use the real range, the jump table
 * included.
 *
 * Source form: `(state == 0) & (mode != 0)` with bitwise & (setcc + btst); the final call is written as if/else
 * with two calls (a ?: or a variable gives the addx / clr shapes); the switch cases are in natural order
 * 0,2 / 1,5 / 3,6 / 4,7 with four explicit calls each (gcc cross-jumps the shared tails); mode is an unsigned int
 * parameter.
 */
/* Channel record: word 0 holds the port in bits 12..15; word +0x40 holds flags (bit 30 is cleared here). */
struct PipWin { unsigned int cfg; unsigned char pad0[0x3c]; unsigned int ctl; unsigned char pad1[0x34]; };
/* Device settings: byte +7 is the current PIP/PBP mode. */
struct PipState { unsigned char pad[7]; unsigned char mode; };
extern struct PipWin channel_records[4];
extern struct PipState device_settings;
extern unsigned char sys_config_byte_3;
extern unsigned short panel_output_rate;
extern int dbg_printf();
extern void FRCConfigPostFRC(int, unsigned short, int);
extern void sys_frc_set_channel_bit_triple(unsigned char, int);
extern void sys_frc_set_active(unsigned char);
extern void sys_set_reg1360_bit(unsigned int, unsigned char);
extern void pq_set_color_fill_enable(int);
extern void sys_restart_channel(int, int);
extern void sys_apply_pip_layout_and_windows(void);
extern void pq_block8_set_mode(int);
extern void nvram_write_settings_record(struct PipState *, unsigned char);

#define CHANNEL_CTL_BIT30 0x40000000    /* bit 30 of the channel record's flag word +0x40 */
#define RESTART_STATE     2             /* second argument of sys_restart_channel */

/*
 * Change the picture-in-picture / picture-by-picture mode of the monitor and bring all four channels in line.
 *
 *   mode  the new mode, 0..7 (0 = one picture). The number of pictures shown is 1 for modes 0 and 2, 2 for
 *         modes 1 and 5, 3 for modes 3 and 6 and 4 for modes 4 and 7. Another value switches nothing on or off.
 *
 * In this order:
 * 1. When the old mode is 0 and the new one is not, or the old mode is 2 and the new one is neither 2 nor 0,
 *    FRCConfigPostFRC is called to configure the output clock and timing again.
 * 2. For the new modes 5, 6 and 7: sys_frc_set_channel_bit_triple(0, 1) (channel 0's bit set in three
 *    registers of the frame-rate converter) and sys_frc_set_active(1).
 * 3. If the mode changes, bit 30 of channel 0's flag word (+0x40) is cleared.
 * 4. The mode is stored in the device settings and printed.
 * 5. Bit n of register 0xCF011360 is set for the port of each channel that is shown and cleared for the others
 *    (see the counts above).
 * 6. The colour fill is switched on, all four channels are restarted with sys_restart_channel(n, 2), and
 *    sys_apply_pip_layout_and_windows applies the layout and window set-up.
 * 7. pq_block8_set_mode gets 2 for mode 0 and 3 for any other mode; the settings record is written to
 *    non-volatile memory (nvram_write_settings_record) as the last call.
 * Called by UserSetPIPMode, osd_apply_screen_size and uart_cmd_set_screen_size.
 */
void SYSAPI_ConfigSystemPIPMode(unsigned int mode)
{
    /* Leaving mode 0 for any other, or mode 2 for a mode other than 0 and 2: configure the output again. */
    if (((device_settings.mode == 0) & (mode != 0)) || (device_settings.mode == 2 && ((mode != 2) & (mode != 0))))
        FRCConfigPostFRC(sys_config_byte_3 != 0, panel_output_rate, 1);
    if (mode - 5 <= 2) {        /* modes 5, 6, 7 */
        sys_frc_set_channel_bit_triple(0, 1);
        sys_frc_set_active(1);
    }
    if (device_settings.mode != mode)
        channel_records[0].ctl &= ~CHANNEL_CTL_BIT30;
    device_settings.mode = mode;
    dbg_printf("SYSAPI_ConfigSystemPIPMode %d\r\n", mode);
    /* Shown channels get their port's bit set in register 0xCF011360, the others get it cleared. */
    switch (device_settings.mode) {
    case 0: case 2:
        sys_set_reg1360_bit(channel_records[0].cfg >> 12 & 0xf, 1);
        sys_set_reg1360_bit(channel_records[1].cfg >> 12 & 0xf, 0);
        sys_set_reg1360_bit(channel_records[2].cfg >> 12 & 0xf, 0);
        sys_set_reg1360_bit(channel_records[3].cfg >> 12 & 0xf, 0);
        break;
    case 1: case 5:
        sys_set_reg1360_bit(channel_records[0].cfg >> 12 & 0xf, 1);
        sys_set_reg1360_bit(channel_records[1].cfg >> 12 & 0xf, 1);
        sys_set_reg1360_bit(channel_records[2].cfg >> 12 & 0xf, 0);
        sys_set_reg1360_bit(channel_records[3].cfg >> 12 & 0xf, 0);
        break;
    case 3: case 6:
        sys_set_reg1360_bit(channel_records[0].cfg >> 12 & 0xf, 1);
        sys_set_reg1360_bit(channel_records[1].cfg >> 12 & 0xf, 1);
        sys_set_reg1360_bit(channel_records[2].cfg >> 12 & 0xf, 1);
        sys_set_reg1360_bit(channel_records[3].cfg >> 12 & 0xf, 0);
        break;
    case 4: case 7:
        sys_set_reg1360_bit(channel_records[0].cfg >> 12 & 0xf, 1);
        sys_set_reg1360_bit(channel_records[1].cfg >> 12 & 0xf, 1);
        sys_set_reg1360_bit(channel_records[2].cfg >> 12 & 0xf, 1);
        sys_set_reg1360_bit(channel_records[3].cfg >> 12 & 0xf, 1);
        break;
    }
    pq_set_color_fill_enable(1);
    sys_restart_channel(0, RESTART_STATE);
    sys_restart_channel(1, RESTART_STATE);
    sys_restart_channel(2, RESTART_STATE);
    sys_restart_channel(3, RESTART_STATE);
    sys_apply_pip_layout_and_windows();
    if (device_settings.mode == 0)
        pq_block8_set_mode(2);
    else
        pq_block8_set_mode(3);
    nvram_write_settings_record(&device_settings, 0);
}
