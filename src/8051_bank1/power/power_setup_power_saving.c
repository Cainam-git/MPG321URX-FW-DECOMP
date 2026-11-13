/* power_setup_power_saving  (FUN_CODE_71f0)
 *
 * Switch the chip's blocks into the power-saving state.
 * Name basis: derived - only caller command 0x16 CMD_SYS_POWERSAVING; register blocks 0x5000/0x5100, clock
 *   unit 0xD9xx, then power cut list on
 *
 * Matching notes
 * --------------
 * Compiler flags: OPTIMIZE(8,SPEED) (not LARGE).
 * volatile on reg_chip_id: the firmware reads it again for each of its three tests.
 * Source form: the last test is '!(reg_chip_id == CHIP_ID_20)' (SETB C / CLR C / JC). The blocks at 0x5000 and
 *   0x5100 are byte arrays here (the twin power_off_sequence uses single variables and one 16-bit store).
 */

#define CHIP_ID_20             0x20  /* reg_chip_id value with its own set-up path */
#define CUT_LIST_FIRST_HALF    1     /* power_apply_cut_list: entries 0..2 of the power-cut table (0 = entries 3..5,
                                        used by power_leave_power_saving) */

extern unsigned char xdata DAT_EXTMEM_f1e0;
extern unsigned char xdata DAT_EXTMEM_5000[];
extern unsigned char xdata DAT_EXTMEM_5100[];
extern unsigned char volatile xdata reg_chip_id;
extern unsigned char xdata DAT_EXTMEM_e135;
extern unsigned char xdata DAT_EXTMEM_d929, DAT_EXTMEM_d90b, DAT_EXTMEM_d904, DAT_EXTMEM_d905, DAT_EXTMEM_d90c;
extern unsigned char xdata DAT_EXTMEM_d910, DAT_EXTMEM_d911, DAT_EXTMEM_d912, DAT_EXTMEM_d90f, DAT_EXTMEM_d92d;
extern unsigned char xdata DAT_EXTMEM_da00;
extern unsigned char xdata DAT_EXTMEM_e1bf, DAT_EXTMEM_e1cf, DAT_EXTMEM_e1d8, DAT_EXTMEM_e1e0, DAT_EXTMEM_e1e2;
extern unsigned char xdata DAT_EXTMEM_e1ec, DAT_EXTMEM_e1ee, DAT_EXTMEM_e19f, DAT_EXTMEM_e1af, DAT_EXTMEM_e12b;
extern unsigned char xdata DAT_EXTMEM_d52c, DAT_EXTMEM_d52d;
extern unsigned char xdata dp_power_up_request;
extern bit sys_on_crystal_clock_flag;
extern void flash_begin_access(void);
extern void timer_set_crystal_rates(void);
extern void power_apply_cut_list(unsigned char phase);

/* Hardware part of mailbox command 0x16 (power saving): ipc_run_command calls it after stopping both LEON
 * processors (sys_stop_leon2m, sys_stop_leon2s). The register values are fixed; what the single registers select is
 * not shown. In order:
 *   1. sys_on_crystal_clock_flag is set (sys_is_on_crystal_clock reports it), XDATA 0xF1E0 = 0xC1.
 *   2. The same twelve values go into the register blocks at XDATA 0x5000 and 0x5100.
 *   3. On chip 0x20, bits 7..6 of XDATA 0xE135 are set.
 *   4. Bits in 0xD904..0xD90C change and 0xD929 = 0x71; on chip 0x20 a further set of registers in 0xD904..0xD92D,
 *      0xDA00 and 0xE12B..0xE1EE is cleared (power_leave_power_saving writes most of them again).
 *   5. 0xD52C |= 0x0C, 0xD52D |= 0x82; the SPI flash interface is claimed for the 8051 (flash_begin_access, with no
 *      release here) and a pending DP power-up request is dropped.
 *   6. On every chip but 0x20 the timer reload and serial speed for the crystal clock are loaded.
 *   7. The pins of entries 0..2 of the power-cut table are switched (power_apply_cut_list).
 * power_off_sequence does the same with three differences: no step 3, 0xD90B is cleared once more on chip 0x20, and
 * step 6 runs on every chip.
 */
void power_setup_power_saving(void)
{
    /* 1. */
    sys_on_crystal_clock_flag = 1;
    DAT_EXTMEM_f1e0 = 0xc1;

    /* 2. Two register blocks, same values. */
    DAT_EXTMEM_5000[0x09] = 0x93;
    DAT_EXTMEM_5000[0x05] = 0x53;
    DAT_EXTMEM_5000[0x0e] = 0x00;
    DAT_EXTMEM_5000[0x08] = 0x06;
    DAT_EXTMEM_5000[0x06] = 0x1c;
    DAT_EXTMEM_5000[0x34] = 0xff;
    DAT_EXTMEM_5000[0x35] = 0x34;
    DAT_EXTMEM_5000[0x02] = 0x14;
    DAT_EXTMEM_5000[0x00] = 0x88;
    DAT_EXTMEM_5000[0x0c] = 0x35;
    DAT_EXTMEM_5000[0x0b] = 0xff;
    DAT_EXTMEM_5000[0x0a] = 0x20;
    DAT_EXTMEM_5100[0x09] = 0x93;
    DAT_EXTMEM_5100[0x05] = 0x53;
    DAT_EXTMEM_5100[0x0e] = 0x00;
    DAT_EXTMEM_5100[0x08] = 0x06;
    DAT_EXTMEM_5100[0x06] = 0x1c;
    DAT_EXTMEM_5100[0x34] = 0xff;
    DAT_EXTMEM_5100[0x35] = 0x34;
    DAT_EXTMEM_5100[0x02] = 0x14;
    DAT_EXTMEM_5100[0x00] = 0x88;
    DAT_EXTMEM_5100[0x0c] = 0x35;
    DAT_EXTMEM_5100[0x0b] = 0xff;
    DAT_EXTMEM_5100[0x0a] = 0x20;

    /* 3. */
    if (reg_chip_id == CHIP_ID_20)
        DAT_EXTMEM_e135 |= 0xc0;

    /* 4. */
    DAT_EXTMEM_d929 = 0x71;
    DAT_EXTMEM_d90b &= 0x7f;
    DAT_EXTMEM_d904 &= 0x0f;
    DAT_EXTMEM_d905 &= 0x7f;
    DAT_EXTMEM_d90c |= 0x01;
    if (reg_chip_id == CHIP_ID_20) {
        DAT_EXTMEM_d910 = 0x00;
        DAT_EXTMEM_d904 &= 0x01;
        DAT_EXTMEM_d911 = 0x00;
        DAT_EXTMEM_d912 = 0x00;
        DAT_EXTMEM_d90f &= 0x7f;
        DAT_EXTMEM_d92d &= 0x3f;
        DAT_EXTMEM_da00 &= 0xfe;
        DAT_EXTMEM_e1bf &= 0x7f;
        DAT_EXTMEM_e1cf &= 0x7f;
        DAT_EXTMEM_e1d8 = 0x00;
        DAT_EXTMEM_e1e0 &= 0x80;
        DAT_EXTMEM_e1e2 &= 0x8f;
        DAT_EXTMEM_e1ec &= 0x80;
        DAT_EXTMEM_e1ee &= 0x80;
        DAT_EXTMEM_e19f &= 0x7f;
        DAT_EXTMEM_e1af &= 0x7f;
        DAT_EXTMEM_e12b &= 0x7f;
    }

    /* 5. */
    DAT_EXTMEM_d52c |= 0x0c;
    DAT_EXTMEM_d52d |= 0x82;
    flash_begin_access();
    dp_power_up_request = 0;

    /* 6. Chip 0x20 keeps its timer and serial settings. */
    if (!(reg_chip_id == CHIP_ID_20))
        timer_set_crystal_rates();

    /* 7. */
    power_apply_cut_list(CUT_LIST_FIRST_HALF);
}
