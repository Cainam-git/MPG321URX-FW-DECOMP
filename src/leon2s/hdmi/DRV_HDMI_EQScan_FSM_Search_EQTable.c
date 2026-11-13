/* DRV_HDMI_EQScan_FSM_Search_EQTable  (DRV_HDMI_EQScan_FSM_Search_EQTable)
 *
 * EQ scan step: step each unfinished channel through the EQ table.
 *   port: PHY
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_Search_EQTable'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_EQScan_FSM_Search_EQTable @ 0xa0078dc8-0xa0078fe8 (544 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - the parameter is an unsigned char that every use extends again, so the record offset port * 0x898 is
 *    recomputed in each block; the record fields are addressed as hdmi_eq_port_records[port] in each statement;
 *  - dbg_hdmi_message_flags is declared unsigned long here (as in DRV_HDMI_EQScan_FSM_PHY_PLL): the alias
 *    set then orders its last load after the hdmi_eq_scan_records index computation;
 *  - the function name is a separate static string.
 */
extern unsigned long dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern void hdmi_phy_load_aeq_entry(unsigned int, unsigned int, unsigned char);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);

#define HDMI_MSG_EQ_FLOW 0x02           /* bit of dbg_hdmi_message_flags: the "[EQ]" lines */

/* States of the EQ scan (index into hdmi_eq_scan_state_handlers). */
#define EQSCAN_STATE_PHY_INIT       0       /* FSM_EQSCAN_PHY_INIT */
#define EQSCAN_STATE_PRE_CHKERROR   0x0a    /* DRV_HDMI_EQScan_FSM_PHY_PreChkError */
#define EQSCAN_STATE_CHKERROR       0x0b    /* DRV_HDMI_EQScan_FSM_PHY_ChkError */
#define EQSCAN_STATE_DONE           0x10    /* DRV_HDMI_EQScan_FSM_Done */

#define EQ_TABLE_LAST_INDEX 0x17        /* the table entries are loaded while every channel's index is <= this */
#define WAIT_PASSES_BEFORE  4           /* wait_count 1..5: (wait_count - 1) <= 4 */

/* The scan state of one port (12 bytes per port, table at 0xA807CCC4). */
struct eq_scan_record {
    unsigned int state;                 /* EQSCAN_STATE_*: the step hdmi_eq_run_scan_fsm runs next */
    unsigned int word_0x4;
    unsigned char byte_0x8;
    unsigned char pad[3];
};
/* The EQ scan work record of one port (0x898 bytes). Arrays of 3 are per channel. */
struct eq_scan_channels {
    unsigned char eq_table_index[3];    /* next entry loaded for the channel ("eqtable index") */
    unsigned char bytes_0x3[0x30 - 3];
    unsigned char wait_count;           /* passes of a waiting step so far (printed as "(%u-th)") */
    unsigned char channel_ok[3];        /* 1: the error check found no errors on this channel */
    unsigned char bytes_0x34[0x896 - 0x34];
    unsigned char byte_0x896;
    unsigned char byte_0x897;
};
extern struct eq_scan_channels hdmi_eq_port_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];

static const char routine_name[] = "DRV_HDMI_EQScan_FSM_Search_EQTable";

/*
 * EQ scan state 14. Loads the next entry of the equaliser table (hdmi_phy_load_aeq_entry) into every
 * channel that is not OK, one entry per call, then sends the scan to ChkError for a new error check.
 * In order:
 *  1. wait_count in 1..5: next state PreChkError, return 0.
 *  2. All three channels OK: next state Done, byte +0x896 cleared, return 1.
 *  3. Every channel's table index at most 0x17: for each channel that is not OK print and load the entry
 *     at its index and step the index; then clear wait_count, clear the EQ error state
 *     (DRV_HDMI_PHY_Clr_EQ_Err), next state ChkError, return 0.
 *  4. Otherwise (the index of some channel is above 0x17): next state PHY_INIT ("Back to EQSCAN_PHY_INIT"), return 1.
 * The return value tells hdmi_eq_run_scan_fsm whether to run the next state at once (1) or stop for now (0).
 *   port: PHY index (the letter in the prints is 'A' + port)
 */
int DRV_HDMI_EQScan_FSM_Search_EQTable(unsigned char port)
{
    unsigned char ch;

    if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
        dbg_printf("[EQ]: \x1b[1mPort%c %s: (%u-th)\x1b[m", (char)(port + 0x41), routine_name,
                     hdmi_eq_port_records[port].wait_count);
    if ((unsigned char)(hdmi_eq_port_records[port].wait_count - 1) <= WAIT_PASSES_BEFORE) {
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_PRE_CHKERROR;
        return 0;
    }
    if (hdmi_eq_port_records[port].channel_ok[0] == 1 && hdmi_eq_port_records[port].channel_ok[1] == 1 && hdmi_eq_port_records[port].channel_ok[2] == 1) {
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_DONE;
        hdmi_eq_port_records[port].byte_0x896 = 0;
        return 1;
    }
    if (hdmi_eq_port_records[port].eq_table_index[0] <= EQ_TABLE_LAST_INDEX && hdmi_eq_port_records[port].eq_table_index[1] <= EQ_TABLE_LAST_INDEX && hdmi_eq_port_records[port].eq_table_index[2] <= EQ_TABLE_LAST_INDEX) {
        for (ch = 0; ch < 3; ch++) {
            if (hdmi_eq_port_records[port].channel_ok[ch] != 1) {
                if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
                    dbg_printf("[EQ]: # Port%c (CH%u) eqtable index = %u\n", (char)(port + 0x41), ch,
                                 hdmi_eq_port_records[port].eq_table_index[ch]);
                hdmi_phy_load_aeq_entry(port, ch, hdmi_eq_port_records[port].eq_table_index[ch]);
                hdmi_eq_port_records[port].eq_table_index[ch]++;
            }
        }
        hdmi_eq_port_records[port].wait_count = 0;
        DRV_HDMI_PHY_Clr_EQ_Err(port);
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_CHKERROR;
        return 0;
    }
    hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
    if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
        dbg_printf("[EQ]: Port%c Back to EQSCAN_PHY_INIT", (char)(port + 0x41));
    return 1;
}
