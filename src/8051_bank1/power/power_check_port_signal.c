/* power_check_port_signal  (FUN_CODE_b2b0)
 *
 * Run the standby wake-up test of one input port's receiver.
 *   port_page: the port's register page (0..3)
 * Returns: 1 when the test passes, 0 otherwise
 * Note: The test: bit 0 of sync meter register 0x20 set and the low 10 bits of port register 0x1F1C above
 *   0x16; run twice unless the wake entry's option flag is set.
 * Name basis: descriptive - chip 0x20: power_test_port_wake_status; else sync meter register 0x20 bit 0 and
 *   paged port register 0x1F1C (reg_port_page_read16), prints 'Check Again!!!!' before the second pass; caller
 *   power_check_wake_entry
 *
 * Matching notes
 * --------------
 * 8051_bank1 module FUN_CODE_b2b0: reg_port_page_write @ 0xce18..0xce4b and FUN_CODE_b2b0 @ 0xb2b0..0xb33e.
 * Options: OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC).
 * One Keil module: the firmware has a common-entry block 0xCE0D..0xCE18 in front of reg_port_page_write (0xCE0D: R3 =
 *   0x28; 0xCE0F: R7 = XDATA 0xA476, R4:R5 = 0x1C02), entered only by the three calls in FUN_CODE_b2b0 (0xB30D,
 *   0xB332, 0xB337). Keil builds such a block only from calls inside the same module. It matches once the learned
 *   XDATA block base ?reg_port_page_write?XD in symbols/8051_bank1.libs.json is 0xA477.
 * LARGE slots: port_page 0xA476; page 0xA477 and value 0xA478 (reg_port_page_write).
 * Source form, reg_port_page_write: the first address is the array's address cast to a generic pointer plus page
 *   ('(unsigned char *)&reg_port_page_select + page'), which sets R3 = 1 before the address add as in the firmware;
 *   'reg_port_page_select + page' sets R3 after it. Both stores go through ?C?CSTPTR.
 * Source form, power_check_port_signal: returns a bit (carry); the first reg_port_page_read16 call reuses R4 = 0x1F
 *   from the write before it. Its parameter must not share a name with a local of reg_port_page_write: the checking
 *   tool resolves a name in the common-entry block as the callee's local when both functions have one.
 */
extern unsigned char xdata reg_chip_id;
extern unsigned char xdata DAT_EXTMEM_d523;
extern unsigned char xdata reg_port_page_select[];
extern unsigned char xdata reg_port_page_window[][256];
extern bit power_wake_entry_option_flag;
extern bit power_test_port_wake_status(unsigned char page);
extern unsigned char reg_read_sync_meter_byte(unsigned char reg);
extern unsigned int reg_port_page_read16(unsigned char page, unsigned int v);
extern void lib_printf517(void *fmt, ...) large;

#define CHIP_VARIANT_20       0x20   /* reg_chip_id value that uses power_test_port_wake_status instead */
#define SYNC_METER_REG_20     0x20   /* sync measurement register; bit 0 must be set for the port test */
#define PORT_MEASURE_MASK     0x3ff  /* low 10 bits of port register 0x1F1C are compared */
#define PORT_MEASURE_LIMIT    0x16   /* the port test passes when the value is above this */

/*
 * reg_port_page_write - write one byte of a port's paged register window.
 *   page        port page (0..3 from power_check_port_signal)
 *   reg_number  register number: bits 8..15 go to the page select byte reg_port_page_select[page], bits 0..7 are
 *               the offset in the 256-byte window reg_port_page_window[page]
 *   value       the byte to write
 * The read counterpart is reg_port_page_read16.
 */
void reg_port_page_write(unsigned char page, unsigned int reg_number, unsigned char value)
{
    unsigned char *target;
    target = (unsigned char *)&reg_port_page_select + page;
    *target = reg_number >> 8;
    target = reg_port_page_window[page];
    target += (unsigned char)reg_number;
    *target = value;
}

/*
 * power_check_port_signal - wake-up test of one input port while the monitor is in standby.
 *   port_page  the port's register page (0..3)
 * Returns 1 when the test passes, 0 otherwise.
 * Only caller: power_check_wake_entry for wake-table entry kinds 1..6, which ORs the result with
 * power_test_port_wake_flag of the same port and sets power_wake_entry_option_flag to bit 5 of the entry first.
 * Chip variant 0x20 only asks power_test_port_wake_status. The other variants:
 *   1. 0xD523 = 0x83 and port register 0x1F02 = 4.
 *   2. The test: bit 0 of sync measurement register 0x20 set and the low 10 bits of port register 0x1F1C above
 *      0x16. Fails -> 0.
 *   3. With power_wake_entry_option_flag set the first pass is enough -> 1.
 *   4. Otherwise print "Check Again!!!!", write 0x24 to port register 0x1C02, run the test once more, write 0x28 to
 *      0x1C02 whatever the outcome, and return the second result.
 */
bit power_check_port_signal(unsigned char port_page)
{
    if (reg_chip_id == CHIP_VARIANT_20) {
        if (power_test_port_wake_status(port_page)) return 1;
        return 0;
    }
    DAT_EXTMEM_d523 = 0x83;
    reg_port_page_write(port_page, 0x1f02, 4);
    if (reg_read_sync_meter_byte(SYNC_METER_REG_20) & 1) {
        if ((reg_port_page_read16(port_page, 0x1f1c) & PORT_MEASURE_MASK) > PORT_MEASURE_LIMIT) {
            if (power_wake_entry_option_flag) return 1;
            lib_printf517((void code *)0xb102 /* "Check Again!!!!\r\n" */);
            reg_port_page_write(port_page, 0x1c02, 0x24);
            if (reg_read_sync_meter_byte(SYNC_METER_REG_20) & 1) {
                if ((reg_port_page_read16(port_page, 0x1f1c) & PORT_MEASURE_MASK) > PORT_MEASURE_LIMIT) {
                    reg_port_page_write(port_page, 0x1c02, 0x28);
                    return 1;
                }
            }
            reg_port_page_write(port_page, 0x1c02, 0x28);
            return 0;
        }
    }
    return 0;
}
