/* power_init_wake_detection  (FUN_CODE_883d)
 *
 * Set up the sync meter and wake block for detecting inputs in standby.
 * Note: DP_EnableMRX runs for a DisplayPort port only when the wake table lists it (kinds 7 or 8 for port 0,
 *   10 or 9 for port 1) and bit 0 of its AUX register 0xDCDF / 0xDCCF is clear.
 * Name basis: derived - fixed reg_write_wake_block_byte / reg_write_sync_meter_byte sequence, then
 *   DP_EnableMRX for the DisplayPort ports found in the wake table (kinds 7..10); caller
 *   power_poll_wake_sources
 *
 * Matching notes
 * --------------
 * One Keil module in this order: reg_write_wake_block_byte @ 0xD9D1 (with its common-entry block 0xD9C3),
 *   reg_write_sync_meter_byte @ 0xDCD3 (common-entry block 0xDCCF), power_init_wake_detection @ 0x883D..0x8947,
 *   power_check_sync_input @ 0xC0A1..0xC103, power_check_sync_input_alt @ 0xCF38..0xCF73.
 *   Compiler flags: OPTIMIZE(8,SPEED) LARGE.
 * Keil OPTIMIZE(8) builds the two common-entry blocks only from callers in this module:
 *   0xDCCF = 'LCALL 0xDCD3; INC R7' from the pairs reg_write_sync_meter_byte(r, v); (r + 1, v) below;
 *   0xD9C3 = 'XDATA 0xD500 = A; reg_write_sync_meter_byte(0, A); reg_write_wake_block_byte(0x54, 0x61)' from the
 *   two power_check_sync_input* routines.
 * The two register writers are defined before their callers: Keil then knows that they keep R5 and R7 (the callers
 *   pass consecutive register numbers with INC R7 and keep R5 between the calls).
 * reg_write_wake_block_byte takes its base from the array symbol (with the constant (xdata *)0x9a00 Keil knows
 *   R1 = 0 and emits MOV A,R1 / ADD A,R7); both writers store through a generic pointer (tail LJMP ?C?CSTPTR).
 * Source form: the bit-0 tests are int-typed, '(unsigned int)(x & 1) != 1', for the firmware's ANL / XRL / JZ
 *   (a char test gives JB ACC.0).
 * volatile on 0xDCB0 (read again between the set and the clear of bit 1) and on 0xD523 (written twice in a row in
 *   power_check_sync_input_alt).
 * LARGE local: wake_setting at XDATA 0xA474 (stored after each call and read back).
 */

/* Wake-up port table entry kinds (byte 0 bits 4..0 of an entry of power_wake_port_table). power_check_wake_entry
 * checks kinds 7 and 8 on DP receiver 0 and kinds 9 and 10 on DP receiver 1. */
#define WAKE_KIND_DP0_A           7
#define WAKE_KIND_DP0_B           8
#define WAKE_KIND_DP1_A           9
#define WAKE_KIND_DP1_B           10
#define WAKE_ENTRY_NONE           0xff  /* power_find_wake_entry: no entry of that kind in the table */
#define WAKE_SETTING_ADC_SHIFT    4     /* bits 7..4 of the entry's setting byte = ADC channel of the sense line */

#define DP_PORT0                  0
#define DP_PORT1                  1
#define DP_AUX_REQUEST_IRQ_BIT    0x01  /* bit 0 of 0xDCDF / 0xDCCF, cleared by dp_mrx_disable_aux_irqs */

#define CHIP_ID_20                0x20  /* reg_chip_id value with its own set-up path */
#define SYNC_METER_STATUS         0x11  /* sync meter register read by both input checks */
#define SYNC_RATIO_MIN            100   /* power_calc_sync_ratio must exceed this */
#define SYNC_MEASURE_WAIT_TICKS   50    /* ticks between the set-up and the reading */

extern unsigned char volatile xdata DAT_EXTMEM_dcb0;
extern unsigned char volatile xdata DAT_EXTMEM_d523;
extern unsigned char xdata DAT_EXTMEM_d500, DAT_EXTMEM_d502, reg_chip_id;
extern unsigned char xdata DAT_EXTMEM_f400, DAT_EXTMEM_f40d;
extern unsigned char xdata reg_dp_aux_request_ctrl_port0, reg_dp_aux_request_ctrl_port1;
extern unsigned char xdata dp_mrx_adc_channel_port0, dp_mrx_adc_channel_port1;
extern unsigned char xdata dp_mrx_adc_sample_counts[2];
extern unsigned char xdata DAT_EXTMEM_6033;
extern unsigned char xdata DAT_EXTMEM_604d[];
extern unsigned char xdata reg_wake_block_window[];
extern void reg_write_sync_meter_mode(unsigned char a, unsigned char b);
extern void reg_update_sync_meter_bits(unsigned char reg, unsigned char mask, unsigned char on);
extern unsigned char power_find_wake_entry(unsigned char key);
extern void timer_delay_ticks(unsigned int n);
extern void reg_paged_init_wake_port(unsigned char ch);
extern void DP_EnableMRX(unsigned char m);
extern void power_arm_signal_detect(void);
extern void power_disarm_signal_detect(void);
extern unsigned char reg_read_sync_meter_byte(unsigned char reg);
extern unsigned int power_calc_sync_ratio(void);
extern bit power_check_sync_timing(void);

/* Write one register of the wake detection block (window XDATA 0x9A00 + reg). */
void reg_write_wake_block_byte(unsigned char reg, unsigned char val)
{
    unsigned char *reg_ptr;
    reg_ptr = reg_wake_block_window;
    reg_ptr += reg;
    *reg_ptr = val;
}

/* Write one register of the sync measurement block (window XDATA 0x9AB0 + reg). */
void reg_write_sync_meter_byte(unsigned char reg, unsigned char val)
{
    unsigned char *reg_ptr;
    reg_ptr = (unsigned char xdata *)0x9ab0;
    reg_ptr += reg;
    *reg_ptr = val;
}

/* Prepare the standby input checks; called by power_poll_wake_sources each time it starts a new walk through the
 * wake-up port table (index 0x1F), right after power_apply_wake_block_mode.
 *
 * Phases, in order:
 *   1. Wake block registers 0x54..0x56 and the sync meter: registers 0x16, 0x17, 0x1A, the two mode fields
 *      (reg_write_sync_meter_mode), registers 0x18/0x19, 0x1C..0x1F and 0x10, mask 0x05 set in register 0x2E.
 *      The values are fixed; what each register selects is not shown.
 *   2. Wake block registers 0x5B/0x5C, then bit 1 of XDATA 0xDCB0 set for one tick and cleared again.
 *   3. XDATA 0xD502 = 0, bit 0 of 0xF400 cleared; on chip 0x20 also bits 3..0 of 0xF40D.
 *   4. DP port 0: when the wake-up table holds a kind 7 entry (else a kind 8 entry), bits 7..4 of its setting byte
 *      become the ADC channel that dp_mrx_detect_adc_rise reads for port 0, the port's paged registers get their wake
 *      set-up, and DP_EnableMRX(0) runs unless bit 0 of 0xDCDF is already set.
 *   5. DP port 1: the same with kind 10 (else kind 9), 0xDCCF and DP_EnableMRX(1).
 *   6. The ADC reading counts of both ports start again at 0.
 */
void power_init_wake_detection(void)
{
    unsigned char wake_setting;

    /* 1. Wake block and sync meter set-up. */
    reg_write_wake_block_byte(0x54, 0x24);
    reg_write_wake_block_byte(0x55, 0xc0);
    reg_write_wake_block_byte(0x56, 0x42);
    reg_write_sync_meter_byte(0x16, 0x00);
    reg_write_sync_meter_byte(0x17, 0x1f);
    reg_write_sync_meter_byte(0x1a, 0x04);
    reg_write_sync_meter_mode(1, 0x04);
    reg_write_sync_meter_byte(0x18, 0x7e);
    reg_write_sync_meter_byte(0x19, 0x7e);
    reg_write_sync_meter_byte(0x1c, 0x00);
    reg_write_sync_meter_byte(0x1d, 0x00);
    reg_write_sync_meter_byte(0x1e, 0xff);
    reg_write_sync_meter_byte(0x1f, 0xff);
    reg_write_sync_meter_byte(0x10, 0xc5);
    reg_update_sync_meter_bits(0x2e, 0x05, 1);

    /* 2. Two more wake block registers, then a one-tick pulse on bit 1 of 0xDCB0. */
    reg_write_wake_block_byte(0x5b, 0x4a);
    reg_write_wake_block_byte(0x5c, 0x02);
    DAT_EXTMEM_dcb0 |= 0x02;
    timer_delay_ticks(1);
    DAT_EXTMEM_dcb0 &= ~0x02;

    /* 3. Fixed register clears; 0xF40D only on chip 0x20. */
    DAT_EXTMEM_d502 = 0;
    DAT_EXTMEM_f400 &= 0xfe;
    if (reg_chip_id == CHIP_ID_20)
        DAT_EXTMEM_f40d &= 0xf0;

    /* 4. DP port 0, when the wake-up table names it. */
    wake_setting = power_find_wake_entry(WAKE_KIND_DP0_A);
    if (wake_setting == WAKE_ENTRY_NONE)
        wake_setting = power_find_wake_entry(WAKE_KIND_DP0_B);
    if (wake_setting != WAKE_ENTRY_NONE) {
        dp_mrx_adc_channel_port0 = wake_setting >> WAKE_SETTING_ADC_SHIFT;
        reg_paged_init_wake_port(DP_PORT0);
        if ((unsigned int)(reg_dp_aux_request_ctrl_port0 & DP_AUX_REQUEST_IRQ_BIT) != 1)
            DP_EnableMRX(DP_PORT0);
    }

    /* 5. DP port 1, the same way. */
    wake_setting = power_find_wake_entry(WAKE_KIND_DP1_B);
    if (wake_setting == WAKE_ENTRY_NONE)
        wake_setting = power_find_wake_entry(WAKE_KIND_DP1_A);
    if (wake_setting != WAKE_ENTRY_NONE) {
        dp_mrx_adc_channel_port1 = wake_setting >> WAKE_SETTING_ADC_SHIFT;
        reg_paged_init_wake_port(DP_PORT1);
        if ((unsigned int)(reg_dp_aux_request_ctrl_port1 & DP_AUX_REQUEST_IRQ_BIT) != 1)
            DP_EnableMRX(DP_PORT1);
    }

    /* 6. dp_mrx_detect_adc_rise takes its first readings again. */
    dp_mrx_adc_sample_counts[DP_PORT0] = 0;
    dp_mrx_adc_sample_counts[DP_PORT1] = 0;
}

/* First check of wake-up table kind 0 (power_check_wake_entry; power_check_sync_input_alt runs when this one
 * returns 0). Sets up the sync meter (0xD500 and meter register 0 = 0x18), writes XDATA 0x6033 and the five bytes at
 * 0x604D, waits 50 ticks and reads the meter.
 * Returns 1 when bits 7..5 of meter register 0x11 are 001, power_check_sync_timing accepts the measured timing and
 * power_calc_sync_ratio is above 100; otherwise it writes 0x6033 and 0x604D/0x604E back to other values and
 * returns 0.
 */
bit power_check_sync_input(void)
{
    DAT_EXTMEM_d523 = 0x83;
    DAT_EXTMEM_6033 = 0x40;
    DAT_EXTMEM_d500 = 0x18;
    reg_write_sync_meter_byte(0, 0x18);
    reg_write_wake_block_byte(0x54, 0x61);
    DAT_EXTMEM_604d[0] = 0xd0;
    DAT_EXTMEM_604d[1] = 0x02;
    DAT_EXTMEM_604d[2] = 0x80;
    DAT_EXTMEM_604d[3] = 0x80;
    DAT_EXTMEM_604d[4] = 0x40;
    timer_delay_ticks(SYNC_MEASURE_WAIT_TICKS);
    if ((reg_read_sync_meter_byte(SYNC_METER_STATUS) & 0xe0) == 0x20 && power_check_sync_timing() && power_calc_sync_ratio() > SYNC_RATIO_MIN) return 1;
    /* Check failed: 0x6033 and 0x604D/0x604E get other values. */
    DAT_EXTMEM_6033 = 0;
    DAT_EXTMEM_d523 = 0x83;
    DAT_EXTMEM_604d[0] = 0x50;
    DAT_EXTMEM_604d[1] = 0x22;
    return 0;
}

/* Second check of wake-up table kind 0. Sets the signal detector levels (power_arm_signal_detect), sets up the
 * sync meter (0xD500 and meter register 0 = 0x10), waits 50 ticks and reads the meter.
 * Returns 1 when meter register 0x11 masked with 0xE8 reads 0x28 and power_calc_sync_ratio is above 100; otherwise
 * it restores the detector levels (power_disarm_signal_detect) and returns 0.
 */
bit power_check_sync_input_alt(void)
{
    DAT_EXTMEM_d523 = 0x83;
    DAT_EXTMEM_d523 = 0x83;
    power_arm_signal_detect();
    DAT_EXTMEM_d500 = 0x10;
    reg_write_sync_meter_byte(0, 0x10);
    reg_write_wake_block_byte(0x54, 0x61);
    timer_delay_ticks(SYNC_MEASURE_WAIT_TICKS);
    if ((reg_read_sync_meter_byte(SYNC_METER_STATUS) & 0xe8) == 0x28 && power_calc_sync_ratio() > SYNC_RATIO_MIN) return 1;
    power_disarm_signal_detect();
    DAT_EXTMEM_d523 = 0x83;
    return 0;
}
