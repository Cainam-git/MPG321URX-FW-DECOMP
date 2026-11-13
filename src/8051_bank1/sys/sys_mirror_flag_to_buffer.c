/* sys_mirror_flag_to_buffer  (FUN_CODE_d385)
 *
 * Copy a status byte into a 63-byte buffer when its request flag is set.
 * Note: Not called anywhere.
 * Name basis: descriptive - mechanics only; no caller in the image
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d385 @ 0xD385..0xD3B9 (52 bytes).
 * No aids.
 */
#define MIRROR_BYTES 0x3f  /* size of the mirror buffer */

extern unsigned char xdata sys_mirror_request_flag, sys_mirror_done_flag, DAT_EXTMEM_9324;
extern unsigned char xdata sys_mirror_buffer[];

/*
 * When the request flag is 1: set bit 0 of the status byte at XDATA 0x9324, fill the 63-byte mirror buffer with
 * that byte and set the done flag. Otherwise clear the done flag. Nothing in the image calls this routine.
 */
void sys_mirror_flag_to_buffer(void)
{
    unsigned char i;

    if (sys_mirror_request_flag == 1) {
        DAT_EXTMEM_9324 |= 1;
        for (i = 0; i < MIRROR_BYTES; i++) sys_mirror_buffer[i] = DAT_EXTMEM_9324;
        sys_mirror_done_flag = 1;
    } else sys_mirror_done_flag = 0;
}
