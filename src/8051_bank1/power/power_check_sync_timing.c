/* power_check_sync_timing  (FUN_CODE_760c)
 *
 * Check that the measured input timing lies within the supported limits.
 * Returns: 1 when all checks pass
 * Name basis: derived - range checks on sync meter values (reg_read_sync_meter_byte/_word): totals >=
 *   0x280/0x200, rate limits 60.26/50.3/30.38
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_760c @ 0x760c..0x7765 (345 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Source form: both locals are unsigned int; the two minimum tests compare with unsigned long constants
 * (0x280UL, 0x200UL) and the last three with float constants, as in the firmware.
 */
extern unsigned char reg_read_sync_meter_byte(unsigned char reg);
extern unsigned int reg_read_sync_meter_word(unsigned char reg);

/* Registers of the sync measurement block read here; what each one measures is not shown. */
#define SYNC_REG_12        0x12
#define SYNC_REG_14        0x14
#define SYNC_REG_22        0x22
#define SYNC_REG_23        0x23
#define SYNC_REG_26        0x26
#define SYNC_WORD_MASK     0x1fff  /* 13-bit values; all ones counts as a failed reading */

/*
 * power_check_sync_timing - range checks on the values of the sync measurement block. Returns 0 at the first
 * check that fails, else 1:
 *   register 0x23 must be 1..15;
 *   register 0x22 must not exceed (register word 0x12, 13 bits) / 8 / 6;
 *   register words 0x12 and 0x14 (13 bits) must be at least 0x280 and 0x200 and not 0x1FFF;
 *   register word 0x26 plus 1 must be at least 200, and selects the limit for register 0x22:
 *   60.26 below 380, 50.3 below 730, else 30.38.
 * Only caller: power_check_sync_input, after it has set up the block and waited, when the status register
 * 0x11 reads 0x20 in bits 7..5.
 */
bit power_check_sync_timing(void)
{
    unsigned int reading;
    unsigned int word_reading;

    reading = reg_read_sync_meter_byte(SYNC_REG_23);
    if (reading > 15 || reading == 0)
        return 0;
    reading = reg_read_sync_meter_byte(SYNC_REG_22);
    word_reading = reg_read_sync_meter_word(SYNC_REG_12) & SYNC_WORD_MASK;
    if (reading > (word_reading >> 3) / 6)
        return 0;
    reading = reg_read_sync_meter_word(SYNC_REG_12) & SYNC_WORD_MASK;
    if (reading < 0x280UL || reading == SYNC_WORD_MASK)
        return 0;
    reading = reg_read_sync_meter_word(SYNC_REG_14) & SYNC_WORD_MASK;
    if (reading < 0x200UL || reading == SYNC_WORD_MASK)
        return 0;
    reading = reg_read_sync_meter_byte(SYNC_REG_22);
    word_reading = reg_read_sync_meter_word(SYNC_REG_26) + 1;
    if (word_reading < 200)
        return 0;
    /* The limit for register 0x22 falls as the value of register word 0x26 rises. */
    if (word_reading < 380) {
        if (reading > 60.26)
            return 0;
    } else if (word_reading < 730) {
        if (reading > 50.3)
            return 0;
    } else {
        if (reading > 30.38)
            return 0;
    }
    return 1;
}
