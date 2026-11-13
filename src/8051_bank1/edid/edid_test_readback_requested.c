/* edid_test_readback_requested  (FUN_CODE_de9c)
 *
 * Report whether a read-back of the EDID buffer was requested.
 * Returns: 1 when requested
 * Name basis: derived - length 0xA46C set by mailbox command 0x0D; report type 1 sends the 0xF800 EDID buffer
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de9c @ 0xde9c  OPTIMIZE(7,SPEED)
 * Each path ends in its own RET; the 'bit' return value is the carry flag.
 */
extern xdata unsigned char edid_readback_count;  /* 0xA46C, field edid_count of the report area at 0xA3E3 */

/*
 * Return 1 when an EDID RAM read-back is asked for: edid_readback_count is the byte count that mailbox command
 * 0x0D sets, 0 when none is asked for. Only caller: ipc_fill_report_record, which then sends that many bytes of
 * the EDID RAM at 0xF800 as a type 1 report and clears the count.
 */
bit edid_test_readback_requested(void) {
    if (edid_readback_count == 0) {
        return 0;
    }
    return 1;
}
