/* dp_tx_check_clock_recovery  (FUN_a00870a4)
 *
 * Return whether clock recovery is done on the active lanes.
 *   mode: lane count
 *   status
 * Returns: 4 when done, else 7
 * Name basis: derived - CR_DONE bits 0x11 of lane status bytes per lane count
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00870a4 (0xa00870a4-0xa0087110, 27 words), flags -mcpu=v8 -Os -g. Leaf.
 * Source form: unsigned char return and result (firmware 'and 7' = the nonzero-bits form of the u8 extension
 * of 4|7); one && chain for mode 4.
 */
/*
 * Check lane status bytes 4 and 5 of a link status record (see dp_tx_read_link_status) for lane count mode.
 * Returns 4 when done, else 7. Mode 4 needs both bytes to have both bits of 0x11 set; mode 2 needs byte 4
 * to have both bits of 0x11 set; any other mode only needs bit 0 of byte 4.
 *   mode:   lane count (low 4 bits used)
 *   status: 16-byte record filled by dp_tx_read_link_status
 */
unsigned char dp_tx_check_clock_recovery(unsigned int mode, unsigned char *status)
{
    unsigned char result = 7;
    if ((mode & 0xf) == 4) {
        if ((status[4] & 0x11) == 0x11 && (status[5] & 0x11) == 0x11)
            result = 4;
    } else if ((mode & 0xf) == 2) {
        if ((status[4] & 0x11) == 0x11)
            result = 4;
    } else if (status[4] & 1)
        result = 4;
    return result;
}
