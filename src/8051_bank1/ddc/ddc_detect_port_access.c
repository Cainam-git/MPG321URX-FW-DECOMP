/* ddc_detect_port_access  (FUN_CODE_65e9)
 *
 * Find a port whose EDID or DDC bus was accessed and wait until it is quiet.
 * Returns: 1 when a port was accessed
 * Name basis: derived - first EDID slave register 0xF01C.. with event bit 0; waits 500 ticks without bus
 *   change; reported by MailBox_UpdateDDCFlag
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_65e9 @ 0x65E9..0x6781 (408 bytes), OPTIMIZE(8,SPEED) LARGE. Returns a bit (carry).
 * LARGE locals bus_state 0xA493, kept_bits 0xA494, edid_ctrl 0xA495..0xA497, i2c_status 0xA498..0xA49A (generic
 * pointers), quiet_since 0xA49B..0xA49C.
 * The registers are hardware registers (volatile, read through 'unsigned char volatile *' generic pointers).
 * Source form: '*edid_ctrl = (kept_bits = *edid_ctrl & 0x3C) | 0x81' (one expression) keeps kept_bits in A for the
 * store; two statements make Keil re-read it.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char volatile xdata reg_edid0_ctrl, reg_edid1_ctrl, reg_edid2_ctrl, reg_edid3_ctrl;
extern unsigned char volatile xdata reg_edid4_ctrl, reg_edid5_ctrl, reg_edid6_ctrl;
extern unsigned int timer_get_ticks(void);

#define EDID_CTRL_ACCESSED  0x01    /* reg_edid<N>_ctrl bit 0: tested here, written as 1 again on every rewrite */
#define EDID_CTRL_KEPT_BITS 0x3c    /* bits 2..5 survive the rewrite */
#define EDID_CTRL_REWRITE   0x81    /* bits 7 and 0 set by the rewrite (bits 1 and 6 cleared) */
#define I2C_STATUS_BUS_BITS 0x03    /* reg_i2c<N>_status bits 0..1, watched for changes */
#define QUIET_TICKS         500

/*
 * ddc_detect_port_access - find the first port 0..6 whose EDID slave control register has bit 0 set, and wait until
 * that port has been quiet for 500 ticks.
 * Returns 1 when a port was found (after the wait), 0 at once when no port has the bit set.
 * The port's control register is rewritten with bits 2..5 kept and bits 0 and 7 set (bits 1 and 6 cleared). Then the
 * wait restarts each time bits 0..1 of the same port's I2C / DDC/CI status register (reg_i2c<N>_status) change, and
 * each time bit 0 of the control register is set again (the register is then rewritten the same way).
 * Called by MailBox_UpdateDDCFlag, which puts the result in the low byte of mailbox portal word 0x0C.
 */
bit ddc_detect_port_access(void)
{
    unsigned char bus_state, kept_bits;
    unsigned char volatile *edid_ctrl, *i2c_status;
    unsigned int quiet_since;
    unsigned char now_state;

    if (reg_edid0_ctrl & EDID_CTRL_ACCESSED) {
        edid_ctrl = (unsigned char xdata *)0xf01c;
        i2c_status = (unsigned char xdata *)0xf03a;
    } else if (reg_edid1_ctrl & EDID_CTRL_ACCESSED) {
        edid_ctrl = (unsigned char xdata *)0xf01e;
        i2c_status = (unsigned char xdata *)0xf042;
    } else if (reg_edid2_ctrl & EDID_CTRL_ACCESSED) {
        edid_ctrl = (unsigned char xdata *)0xf085;
        i2c_status = (unsigned char xdata *)0xf08a;
    } else if (reg_edid3_ctrl & EDID_CTRL_ACCESSED) {
        edid_ctrl = (unsigned char xdata *)0xf087;
        i2c_status = (unsigned char xdata *)0xf092;
    } else if (reg_edid4_ctrl & EDID_CTRL_ACCESSED) {
        edid_ctrl = (unsigned char xdata *)0xf099;
        i2c_status = (unsigned char xdata *)0xf09c;
    } else if (reg_edid5_ctrl & EDID_CTRL_ACCESSED) {
        edid_ctrl = (unsigned char xdata *)0xf0a3;
        i2c_status = (unsigned char xdata *)0xf0b9;
    } else if (reg_edid6_ctrl & EDID_CTRL_ACCESSED) {
        edid_ctrl = (unsigned char xdata *)0xf076;
        i2c_status = (unsigned char xdata *)0xf141;
    } else {
        return 0;
    }
    /* edid_ctrl / i2c_status: the found port's reg_edid<N>_ctrl and reg_i2c<N>_status. */
    *edid_ctrl = (kept_bits = *edid_ctrl & EDID_CTRL_KEPT_BITS) | EDID_CTRL_REWRITE;
    bus_state = *i2c_status & I2C_STATUS_BUS_BITS;
    quiet_since = timer_get_ticks();
    while (timer_get_ticks() - quiet_since < QUIET_TICKS) {
        DAT_EXTMEM_f00a = 0x55;     /* the same write sys_main makes on every round of its loop */
        now_state = *i2c_status & I2C_STATUS_BUS_BITS;
        if (bus_state != now_state) {
            bus_state = now_state;
            quiet_since = timer_get_ticks();
        }
        if (*edid_ctrl & EDID_CTRL_ACCESSED) {
            *edid_ctrl = kept_bits | EDID_CTRL_REWRITE;
            quiet_since = timer_get_ticks();
        }
    }
    return 1;
}
