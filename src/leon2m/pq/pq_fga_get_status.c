/* pq_fga_get_status  (FUN_a012e82c)
 *
 * Return the FGA status byte.
 * Returns: byte
 * Name basis: descriptive - byte at 0xA802CB10; read by the DDC/CI request handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012e82c @ 0xa012e82c (12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a plain read of the extern byte (sethi %hi, then the load with the %lo offset in the delay slot of
 * the return).
 */
extern unsigned char pq_fga_status;

/*
 * Return the FGA status byte.
 *
 * The byte is a running sum of the calibration data received over DDC/CI: pq_fga_handle_command clears it when a
 * calibration session starts (command 20) and adds every data byte of the commands 17, 18 and 23 to it, letting
 * the overflow wrap. ddc_handle_request sends it back as the first value byte of GetVCP 0xF1 with sub-code 0x15,
 * (followed by the fixed bytes 0xAA, 0xBB, 0xCC).
 */
unsigned char pq_fga_get_status(void)
{
    return pq_fga_status;
}
