/* ddc_get_pending_channels  (FUN_CODE_dee2)
 *
 * Return the bit mask of DDC/CI channels with a message waiting.
 * Returns: channel mask
 * Name basis: derived - byte 0xA0F3; one bit per channel row at 0xA0F4
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dee2 @ 0xdee2  OPTIMIZE(7,SPEED)
 * Source form: the byte is defined here with _at_ 0xa0f3.
 */
unsigned char xdata ddc_pending_channel_flags _at_ 0xa0f3;

/*
 * Return ddc_pending_channel_flags: one bit per DDC/CI slave port whose request has ended and is not reported yet.
 * ddc_rearm_idle_slaves sets a port's bit, ddc_clear_pending_channel clears it. Callers: ddc_test_none_pending,
 * ddc_get_first_pending_channel and power_test_ddc_wake.
 */
unsigned char ddc_get_pending_channels(void) {
    return ddc_pending_channel_flags;
}
