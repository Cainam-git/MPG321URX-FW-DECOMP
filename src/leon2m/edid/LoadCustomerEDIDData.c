/* LoadCustomerEDIDData  (FUN_a00ce958)
 *
 * Load one of the stored EDID records into an input port.
 *   port: input port
 *   n: EDID record number
 * Note: Records of 512 bytes at flash 0x10000; numbers 0x38 and above select record 0.
 * Name basis: proven - prints 'LoadCustomerEDIDData %d %d' (original name); caller UserSwitchEDID;
 *   edid_api_write_port_edid
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ce958 @ 0xa00ce958-0xa00ce9c0 (26 words).
 * Source form: the call to ipc_signal_alive is the last statement (a tail call).
 */

/* Size of one stored EDID record. The table holds 0x38 (56) records, 0x6E00 bytes (docs/MAP.md). */
#define EDID_RECORD_SIZE   0x200
#define EDID_RECORD_COUNT  0x38

/* Number of bytes of the record that are written to the port. */
#define EDID_LOAD_LENGTH   0x180

extern int dbg_printf(const char *fmt, ...);
extern void edid_api_write_port_edid(unsigned char port, unsigned char b, unsigned int addr, unsigned short len,
                         unsigned char f);
extern void ipc_signal_alive(void);
extern const unsigned char edid_stored_records[];

/*
 * Print the port and the record number, then pass the first 0x180 bytes of record n to
 * edid_api_write_port_edid (with 0 as its second and 1 as its fifth argument), and finally call ipc_signal_alive.
 *
 *   port  input port, as given to edid_api_write_port_edid
 *   n     record number (0..0x37); a larger number is replaced by 0
 *
 * Called from UserSwitchEDID.
 */
void LoadCustomerEDIDData(unsigned char port, unsigned short n)
{
    if (n >= EDID_RECORD_COUNT)
        n = 0;
    dbg_printf("\x1b[1;35mLoadCustomerEDIDData %d %d \r\n\x1b[m", port, n);
    edid_api_write_port_edid(port, 0, (unsigned int)edid_stored_records + n * EDID_RECORD_SIZE, EDID_LOAD_LENGTH, 1);
    ipc_signal_alive();
}
