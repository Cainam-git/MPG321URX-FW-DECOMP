/* power_off_sequence  (FUN_CODE_7a0b)
 *
 * Switch the chip's blocks off for power-off.
 * Name basis: proven - docs/MAP.md; callers command 0x17 CMD_SYS_POWEROFF and the SYSTEM CRASH path of
 *   sys_watch_main_core
 *
 * Matching notes
 * --------------
 * Compiler flags: OPTIMIZE(8,SPEED) (also exact with LARGE).
 * Source forms: 0x5034/0x5035 and 0x5134/0x5135 are one 16-bit variable each (the firmware stores 0xFF, INC DPTR,
 *   0x34: one 16-bit store of 0xFF34); the last call is a tail call (LJMP power_apply_cut_list).
 * volatile: the 0x50xx / 0x51xx / 0xD5xx / 0xD9xx / 0xDAxx / 0xE1xx / 0xF1xx registers (0xD90B is cleared twice in
 *   a row on chip 0x20); dp_power_up_request is RAM and not volatile.
 */

#define CHIP_ID_20             0x20  /* reg_chip_id value with its own set-up path */
#define CUT_LIST_FIRST_HALF    1     /* power_apply_cut_list: entries 0..2 of the power-cut table */

extern bit sys_on_crystal_clock_flag;
extern unsigned char volatile xdata DAT_EXTMEM_f1e0;
extern unsigned char volatile xdata DAT_EXTMEM_5009, DAT_EXTMEM_5005, DAT_EXTMEM_500e, DAT_EXTMEM_5008, DAT_EXTMEM_5006;
extern unsigned int volatile xdata DAT_EXTMEM_5034;
extern unsigned char volatile xdata DAT_EXTMEM_5002, DAT_EXTMEM_5000, DAT_EXTMEM_500c, DAT_EXTMEM_500b, DAT_EXTMEM_500a;
extern unsigned char volatile xdata DAT_EXTMEM_5109, DAT_EXTMEM_5105, DAT_EXTMEM_510e, DAT_EXTMEM_5108, DAT_EXTMEM_5106;
extern unsigned int volatile xdata DAT_EXTMEM_5134;
extern unsigned char volatile xdata DAT_EXTMEM_5102, DAT_EXTMEM_5100, DAT_EXTMEM_510c, DAT_EXTMEM_510b, DAT_EXTMEM_510a;
extern unsigned char volatile xdata DAT_EXTMEM_d929, DAT_EXTMEM_d90b, DAT_EXTMEM_d904, DAT_EXTMEM_d905, DAT_EXTMEM_d90c;
extern unsigned char volatile xdata reg_chip_id, DAT_EXTMEM_d910, DAT_EXTMEM_d911, DAT_EXTMEM_d912, DAT_EXTMEM_d90f;
extern unsigned char volatile xdata DAT_EXTMEM_d92d, DAT_EXTMEM_da00, DAT_EXTMEM_e1bf, DAT_EXTMEM_e1cf, DAT_EXTMEM_e1d8;
extern unsigned char volatile xdata DAT_EXTMEM_e1e0, DAT_EXTMEM_e1e2, DAT_EXTMEM_e1ec, DAT_EXTMEM_e1ee, DAT_EXTMEM_e19f;
extern unsigned char volatile xdata DAT_EXTMEM_e1af, DAT_EXTMEM_e12b, DAT_EXTMEM_d52c, DAT_EXTMEM_d52d;
extern unsigned char xdata dp_power_up_request;
extern void flash_begin_access(void);
extern void timer_set_crystal_rates(void);
extern void power_apply_cut_list(unsigned char phase);

/* Hardware part of power-off. Two callers, both right after stopping both LEON processors (sys_stop_leon2m,
 * sys_stop_leon2s) and writing 0xF150 = 9, 0xF152 |= 0x40:
 *   - mailbox command 0x17 (prints "CMD_SYS_POWEROFF"; ipc_run_command then sets the run state to 1);
 *   - the crash path of sys_watch_main_core, which afterwards loops forever.
 * The register values are fixed; what the single registers select is not shown. In order:
 *   1. sys_on_crystal_clock_flag is set, XDATA 0xF1E0 = 0xC1.
 *   2. The same values go into the register blocks at XDATA 0x5000 and 0x5100.
 *   3. Bits in 0xD904..0xD90C change and 0xD929 = 0x71; on chip 0x20 a further set of registers in 0xD904..0xD92D,
 *      0xDA00 and 0xE12B..0xE1EE is cleared.
 *   4. 0xD52C |= 0x0C, 0xD52D |= 0x82; the SPI flash interface is claimed for the 8051 (flash_begin_access, with no
 *      release here) and a pending DP power-up request is dropped.
 *   5. The timer reload and serial speed for the crystal clock are loaded (timer_set_crystal_rates).
 *   6. The pins of entries 0..2 of the power-cut table are switched (power_apply_cut_list).
 * power_setup_power_saving does the same with three differences: it also sets bits 7..6 of 0xE135 on chip 0x20,
 * clears 0xD90B only once, and skips step 5 on chip 0x20.
 */
void power_off_sequence(void)
{
    /* 1. */
    sys_on_crystal_clock_flag = 1;
    DAT_EXTMEM_f1e0 = 0xc1;

    /* 2. Two register blocks, same values. */
    DAT_EXTMEM_5009 = 0x93;
    DAT_EXTMEM_5005 = 0x53;
    DAT_EXTMEM_500e = 0;
    DAT_EXTMEM_5008 = 0x06;
    DAT_EXTMEM_5006 = 0x1c;
    DAT_EXTMEM_5034 = 0xff34;
    DAT_EXTMEM_5002 = 0x14;
    DAT_EXTMEM_5000 = 0x88;
    DAT_EXTMEM_500c = 0x35;
    DAT_EXTMEM_500b = 0xff;
    DAT_EXTMEM_500a = 0x20;
    DAT_EXTMEM_5109 = 0x93;
    DAT_EXTMEM_5105 = 0x53;
    DAT_EXTMEM_510e = 0;
    DAT_EXTMEM_5108 = 0x06;
    DAT_EXTMEM_5106 = 0x1c;
    DAT_EXTMEM_5134 = 0xff34;
    DAT_EXTMEM_5102 = 0x14;
    DAT_EXTMEM_5100 = 0x88;
    DAT_EXTMEM_510c = 0x35;
    DAT_EXTMEM_510b = 0xff;
    DAT_EXTMEM_510a = 0x20;

    /* 3. */
    DAT_EXTMEM_d929 = 0x71;
    DAT_EXTMEM_d90b &= 0x7f;
    DAT_EXTMEM_d904 &= 0x0f;
    DAT_EXTMEM_d905 &= 0x7f;
    DAT_EXTMEM_d90c |= 0x01;
    if (reg_chip_id == CHIP_ID_20) {
        DAT_EXTMEM_d90b &= 0x7f;
        DAT_EXTMEM_d910 = 0;
        DAT_EXTMEM_d904 &= 0x01;
        DAT_EXTMEM_d911 = 0;
        DAT_EXTMEM_d912 = 0;
        DAT_EXTMEM_d90f &= 0x7f;
        DAT_EXTMEM_d92d &= 0x3f;
        DAT_EXTMEM_da00 &= 0xfe;
        DAT_EXTMEM_e1bf &= 0x7f;
        DAT_EXTMEM_e1cf &= 0x7f;
        DAT_EXTMEM_e1d8 = 0;
        DAT_EXTMEM_e1e0 &= 0x80;
        DAT_EXTMEM_e1e2 &= 0x8f;
        DAT_EXTMEM_e1ec &= 0x80;
        DAT_EXTMEM_e1ee &= 0x80;
        DAT_EXTMEM_e19f &= 0x7f;
        DAT_EXTMEM_e1af &= 0x7f;
        DAT_EXTMEM_e12b &= 0x7f;
    }

    /* 4. */
    DAT_EXTMEM_d52c |= 0x0c;
    DAT_EXTMEM_d52d |= 0x82;
    flash_begin_access();
    dp_power_up_request = 0;

    /* 5., 6. */
    timer_set_crystal_rates();
    power_apply_cut_list(CUT_LIST_FIRST_HALF);
}
