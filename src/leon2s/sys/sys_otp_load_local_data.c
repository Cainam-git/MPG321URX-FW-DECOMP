/* sys_otp_load_local_data  (FUN_a008d70c)
 *
 * Load three groups of factory data records into local tables.
 * Name basis: descriptive - records 0..1, 3..11, 14 to 0xA807D27A, 0xA807D289, 0xA807D3D1; caller
 *   input_init_receivers
 *
 * Matching notes
 * --------------
 * FUN_a008d70c (leon2s, 0xa008d70c-0xa008d800, 244 bytes), flags -mcpu=v8 -Os -g.
 * Source form: u16 loop counter and sum (sll/srl 16); the last sys_otp_check_records call is a sibcall.
 */
/* One entry of the ROM table of factory data records. */
struct otp_record { unsigned short start; unsigned short length; };    /* store address, byte count */
extern struct otp_record ARR_a00b4036[];
extern unsigned char sys_otp_local_group0[];
extern unsigned char sys_otp_dp_tx_phy_options[];
extern unsigned char dp_tx_phy_edp_options[];
extern void sys_otp_read_bytes(unsigned short, unsigned short, unsigned char *);
extern void sys_otp_check_records(unsigned char *, unsigned int, unsigned int);

/* Read three groups of factory data records from the data store into local tables and check each group with
 * sys_otp_check_records: records 0..1 into sys_otp_local_group0, records 3..11 into sys_otp_dp_tx_phy_options,
 * record 14 into dp_tx_phy_edp_options. Each group is read as one block from the start address of its first
 * record, with the summed lengths. Called by input_init_receivers.
 */
void sys_otp_load_local_data(void)
{
    unsigned short total_length;
    unsigned short i;

    total_length = 0;
    for (i = 0; i < 2; i++)
        total_length += ARR_a00b4036[i].length;
    sys_otp_read_bytes(ARR_a00b4036[0].start, total_length, sys_otp_local_group0);
    total_length = 0;
    for (i = 3; i < 0xc; i++)
        total_length += ARR_a00b4036[i].length;
    sys_otp_read_bytes(ARR_a00b4036[3].start, total_length, sys_otp_dp_tx_phy_options);
    sys_otp_read_bytes(ARR_a00b4036[14].start, ARR_a00b4036[14].length, dp_tx_phy_edp_options);
    sys_otp_check_records(sys_otp_local_group0, 0, 2);
    sys_otp_check_records(sys_otp_dp_tx_phy_options, 3, 0xc);
    sys_otp_check_records(dp_tx_phy_edp_options, 0xe, 0xf);
}
