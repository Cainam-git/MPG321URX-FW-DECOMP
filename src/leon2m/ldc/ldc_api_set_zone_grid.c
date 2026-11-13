/* ldc_api_set_zone_grid  (FUN_a014e050)
 *
 * Select the 64 x 32 or the 32 x 16 zone grid and send the related mode values.
 * Name basis: derived - docs/MAP.md: command 0x2A zone grid, chosen by bits 18-19 of the settings word; then
 *   commands 0x97 and 0x88
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e050, flags -mcpu=v8 -O2 -g.
 * Source form the exact build depends on: GCC loads 0x2a / 0 / 0x2040 into the argument registers before the
 * test, so ldc_send_zone_grid_32x16 (a call without arguments in the source) is entered with the same registers;
 * the last call is a tail call.
 */
extern void ldc_send_command(unsigned int, unsigned int, unsigned short);
extern void ldc_send_zone_grid_32x16(void);
extern void ldc_send_input_duty_check(unsigned short arg);
extern void ipc_set_hdr_mode_byte(unsigned char mode);

/*
 * Send the zone grid and the mode value that goes with it to the dimming processor.
 *
 *   grid_mode  1 sends the 64 x 32 grid (command 0x2A with the value 0x2040); any other value sends the
 *              32 x 16 grid. The same value then goes out with command 0x97, and the input processor is
 *              given it too (ipc_set_hdr_mode_byte, mailbox command 0x88).
 *
 * Called by sys_user_apply_startup_settings.
 */
void ldc_api_set_zone_grid(unsigned char grid_mode)
{
    if (grid_mode == 1)
        ldc_send_command(0x2a, 0, 0x2040);
    else
        ldc_send_zone_grid_32x16();
    ldc_send_input_duty_check(grid_mode);
    ipc_set_hdr_mode_byte(grid_mode);
}
