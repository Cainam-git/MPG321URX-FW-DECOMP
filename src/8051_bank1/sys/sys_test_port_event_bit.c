/* sys_test_port_event_bit  (FUN_CODE_db7d)
 *
 * Report the event bit of port 0 or 1 in the activity status register.
 *   port: port 0/1
 * Returns: 1 when set
 * Name basis: descriptive - bit 6 / 7 of reg 0xDCB0; keeps the fast clock running while set
 *   (power_watch_dp_activity)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_db7d @ 0xdb7d  OPTIMIZE(8,SPEED)
 * Source form: assigning the masked byte to the temporary before the test makes Keil emit ANL A,#mask followed by JZ,
 * as in the firmware, instead of a JNB ACC.x bit test.
 */
#define DCB0_PORT0_EVENT 0x40   /* bit 6 of XDATA 0xDCB0 */
#define DCB0_PORT1_EVENT 0x80   /* bit 7 of XDATA 0xDCB0 */

extern unsigned char xdata DAT_EXTMEM_dcb0;

/* Return 1 when the event bit of the given port is set in the byte at
 * 0xDCB0: bit 6 for port 0, bit 7 for any other port number. Used by the
 * port sequence of mailbox command 0x25 (ipc_run_cmd_0x25_sequence).
 *   port: 0 or 1 */
bit sys_test_port_event_bit(char port)
{
    unsigned char masked;
    if (port == 0) {
        masked = DAT_EXTMEM_dcb0 & DCB0_PORT0_EVENT;
        if (masked != 0) {
            return 1;
        }
    } else {
        masked = DAT_EXTMEM_dcb0 & DCB0_PORT1_EVENT;
        if (masked != 0) {
            return 1;
        }
    }
    return 0;
}
