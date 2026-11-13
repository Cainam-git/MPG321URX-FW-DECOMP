/* i2c_test_no_result_ready  (FUN_CODE_de5b)
 *
 * Report whether no I2C read result waits to be reported.
 * Returns: 1 when none
 * Name basis: derived - flag 0xA35F set by the message type 2 I2C job; the report builder sends type 2 when it
 *   is 1
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de5b @ 0xde5b  OPTIMIZE(7,SPEED)
 * The 'bit' return type returns the result in the carry flag.
 */
extern unsigned char xdata i2c_result_ready_flag;

/* Return 0 when i2c_result_ready_flag is 1 (an I2C read result waits to be
 * reported), else 1. */
bit i2c_test_no_result_ready(void)
{
    if (i2c_result_ready_flag == 0x01)
    {
        return 0;  /* CLR C */
    }
    return 1;      /* SETB C */
}
