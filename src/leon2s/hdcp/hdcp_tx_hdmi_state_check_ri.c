/* hdcp_tx_hdmi_state_check_ri  (FUN_a00c8b18)
 *
 * State handler: compare the receiver's link-check bytes with the engine's.
 * Name basis: derived - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_hdmi_run_state; hdcp_tx_hdmi_read_ri against registers 0x22 / 0x23; prints
 *
 * Matching notes
 * --------------
 * FUN_a00c8b18 (leon2s 0xa00c8b18-0xa00c8c64), flags -mcpu=v8 -Os -g.
 * Source form: the record is declared as a 24-byte bit-field struct with its last 16 bits and 20 pad bytes
 * unnamed; the print formats are program-image addresses passed as pointer constants.
 */
/* Output record of hdcp_tx_records (24 bytes). Word 0 bit-fields, most significant bit first. */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;                  /* bit 28 */
    unsigned int tries_left : 4;                /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;               /* bits 16..17: STEP_* */
    unsigned int low_halfword : 16;             /* state (+2) and device_count (+3) */
    unsigned char pad[20];
};
/* Result of a state handler (step_result), read by hdcp_tx_select_next_state. */
enum { STEP_BACK = 0, STEP_NEXT = 1, STEP_OTHER = 2, STEP_AGAIN = 3 };
extern struct hdcp_tx_record hdcp_tx_records[];
extern int dbg_printf(const char *, ...);
extern unsigned char hdmi_tx_reg_read8(unsigned char, int, unsigned short);
extern unsigned char hdcp_tx_hdmi_read_ri(unsigned char, unsigned char *);

#define ENGINE_RI_REG 0x22                      /* registers 0x22 and 0x23 hold the engine's two bytes */

/*
 * State 19 of hdcp_tx_hdmi_run_state: compare the two Ri bytes read from the screen (hdcp_tx_hdmi_read_ri) with
 * registers 0x22 and 0x23 of HDMI output `port`.
 *   - the read fails: step result STEP_AGAIN, nothing else;
 *   - the bytes differ: a message is printed, tries_left of the record is decremented, step result STEP_AGAIN;
 *   - both bytes match: a message is printed, bit 23 of the record cleared, step result STEP_NEXT.
 * A further message is printed when bit 1 of register 0x0F is clear, before the compare.
 */
void hdcp_tx_hdmi_state_check_ri(unsigned char port)
{
    unsigned char ri[2];

    if (hdcp_tx_hdmi_read_ri(port, ri) != 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    if ((hdmi_tx_reg_read8(port, 0, 0xf) & 2) == 0)
        dbg_printf((const char *)0x9f1c2030);
    if (hdmi_tx_reg_read8(port, 0, ENGINE_RI_REG) != ri[0] || hdmi_tx_reg_read8(port, 0, ENGINE_RI_REG + 1) != ri[1]) {
        dbg_printf((const char *)0x9f1c2068);
        hdcp_tx_records[port].tries_left--;
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    dbg_printf((const char *)0x9f1c2040);
    hdcp_tx_records[port].bit23 = 0;
    hdcp_tx_records[port].step_result = STEP_NEXT;
}
