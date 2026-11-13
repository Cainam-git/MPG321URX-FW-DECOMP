/* power_test_adc_key_level  (FUN_CODE_d7ac)
 *
 * Pulse register 0xF0A8, wait, and report whether register 0xF0AD reads between 1 and 9.
 * Returns: 1 when 0 < value < 10
 * Name basis: descriptive - ADC control 0xF0A8, result 0xF0AD; standby wake check case 0
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d7ac @ 0xd7ac  Byte-exact with OPTIMIZE(7,SPEED) and OPTIMIZE(8,SPEED).
 * volatile is real: the firmware writes 0xF0A8 twice in a row and reads 0xF0AD twice (MOVX after each compare).
 */
#define ADC_SETTLE_TICKS_MINUS_ONE 20  /* argument of timer_delay_ticks: a wait of 21 ticks */
#define ADC_LEVEL_LIMIT            10  /* the reading must be below this */

extern unsigned char volatile xdata DAT_EXTMEM_f0a8;
extern unsigned char volatile xdata DAT_EXTMEM_f0ad;
void timer_delay_ticks(unsigned int ticks_minus_one);

/*
 * Run one sample on the ADC (XDATA 0xF0A8: write 0x7F, then 0x0F, wait, then write 0) and return 1 when the
 * result byte at 0xF0AD is between 1 and 9. Part of the standby wake check (case 0); its only caller is at 0x5337.
 */
bit power_test_adc_key_level(void)
{
    DAT_EXTMEM_f0a8 = 0x7f;
    DAT_EXTMEM_f0a8 = 0x0f;
    timer_delay_ticks(ADC_SETTLE_TICKS_MINUS_ONE);
    DAT_EXTMEM_f0a8 = 0;
    if (DAT_EXTMEM_f0ad > 0 && DAT_EXTMEM_f0ad < ADC_LEVEL_LIMIT)
        return 1;
    return 0;
}
